"""Caminhos e parametros de cada alvo do projeto (EXE ou overlay)."""
import contextlib
import fcntl
import os

R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class Target:
    def __init__(self, name):
        self.name = name
        if name == 'main':
            self.src = 'src/main.c'
            self.hdr = 'include/main.h'
            self.auto = 'include/main_auto.h'
            self.data = 'include/main_data.h'
            self.asm = 'asm/nonmatchings/main'
            self.bin = 'disc/SLES_049.36'
            self.vram, self.off, self.G = 0x80010000, 0x800, 8
        else:
            self.src = 'src/ovl/%s.c' % name
            self.hdr = 'include/ovl/%s.h' % name
            self.auto = 'include/ovl/%s_auto.h' % name
            self.data = 'include/ovl/%s_data.h' % name
            self.asm = 'asm/ovl/%s/nonmatchings/%s' % (name, name)
            self.bin = 'disc/PRO/%s.PRO' % name
            self.vram = 0x800A5DE0 if name.startswith('W') else 0x80082CB0
            self.off, self.G = 0, 0

    def p(self, rel):
        return os.path.join(R, rel)

    def include_line(self, fn):
        return 'INCLUDE_ASM("%s", %s);' % (self.asm, fn)

    def ensure_files(self):
        """Cria o header, o _data.h e os #include do .c se faltarem."""
        n = os.path.basename(self.hdr)[:-2]
        guard = n.upper()
        if not os.path.exists(self.p(self.hdr)):
            open(self.p(self.hdr), 'w').write(
                '#ifndef %s_H\n#define %s_H\n\n#include "common.h"\n\n'
                '#endif /* %s_H */\n' % (guard, guard, guard))
        if not os.path.exists(self.p(self.data)):
            open(self.p(self.data), 'w').write(
                '/* Dados usados pelo codigo C de %s (ver include/main_data.h)'
                ' */\n#ifndef %s_DATA_H\n#define %s_DATA_H\n\n'
                '/* tipo ainda desconhecido (so o endereco e usado) */\n'
                'struct opaque;\n\n#endif /* %s_DATA_H */\n'
                % (self.name, guard, guard, guard))
        if not os.path.exists(self.p(self.auto)):
            open(self.p(self.auto), 'w').write('')
        src = open(self.p(self.src)).read()
        want = '#include "%s.h"\n#include "m2c.h"\n#include "%s_auto.h"\n' \
               '#include "%s_data.h"\n' % (n, n, n)
        if '#include "%s_auto.h"' % n not in src:
            src = src.replace('#include "common.h"\n', want, 1)
            open(self.p(self.src), 'w').write(src)


@contextlib.contextmanager
def apply_lock():
    """Trava para integrar codigo (inserir + make + desfazer) sem que dois
    processos (ex.: autodecomp_all em segundo plano e fn.py) se misturem."""
    os.makedirs(os.path.join(R, 'build'), exist_ok=True)
    with open(os.path.join(R, 'build/.apply.lock'), 'w') as f:
        fcntl.flock(f, fcntl.LOCK_EX)
        try:
            yield
        finally:
            fcntl.flock(f, fcntl.LOCK_UN)
