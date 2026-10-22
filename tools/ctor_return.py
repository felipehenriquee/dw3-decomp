"""Converte construtores void (so criam o objeto e preenchem campos) para
devolver o objeto (Obj *). O codigo gerado e o mesmo; os chamadores que
usam o retorno passam a compilar. Rode e confira com o make.
"""
import glob,re,json,sys
pat=re.compile(r'^void (func_[0-9A-F]+)\(([^)]*)\) \{\n    void \*temp_v0;\n\n    temp_v0 = (func_800143DC|func_80014504)\(([^;]*)\);\n((?:    M2C_FIELD\(temp_v0, [^;]*;\n)+)\}', re.M)
changed={}
for f in glob.glob('src/ovl/*.c')+['src/main.c']:
    s=open(f).read()
    def sub(m):
        return 'Obj *%s(%s) {\n    void *temp_v0;\n\n    temp_v0 = %s(%s);\n%s    return temp_v0;\n}'%(m.group(1),m.group(2),m.group(3),m.group(4),m.group(5))
    s2,n=pat.subn(sub,s)
    if n:
        changed[f]=s; open(f,'w').write(s2); print(f,n)
json.dump(changed,open('build/w/ctor_backup.json','w'))
