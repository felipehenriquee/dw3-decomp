"""Gera o C das funcoes pendentes com duas chamadas D_80048ABC.fn(K, n)
(forma comum nos WSTAG: liga/desliga flags do mapa). Grava como ok no
results.json; integre com tools/autodecomp.py <alvo> --apply.

Uso: python3 -I tools/twocall.py
"""
import sys,os,glob,re,json
sys.path.insert(0,'tools')
import autodecomp as ad
from proj import Target
tpl=None
out={}
for p in sorted(glob.glob('src/ovl/*.c')):
    t=os.path.basename(p)[:-2]; T=Target(t)
    for fn in ad.pending(t):
        f=T.p(T.asm+'/'+fn+'.s')
        if not os.path.exists(f): continue
        ins=[re.sub(r'\s+',' ',m.group(1)).strip() for m in re.finditer(r'/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/\s*(.*)',open(f).read())]
        if len(ins)!=19: continue
        norm=[re.sub(r'0x[0-9A-F]+','K',i) for i in ins]
        want=['addiu $sp, $sp, -K','addiu $a0, $zero, K','sw $s0, K($sp)','lui $s0, %hi(D_80048ABC)','addiu $s0, $s0, %lo(D_80048ABC)','sw $ra, K($sp)','lw $v0, K($s0)','nop','jalr $v0','addiu $a1, $zero, K','addiu $a0, $zero, K','lw $v0, K($s0)','nop','jalr $v0','addiu $a1, $zero, K','lw $ra, K($sp)','lw $s0, K($sp)','jr $ra','addiu $sp, $sp, K']
        norm2=[n.replace('ori $a0, $zero, K','addiu $a0, $zero, K') for n in norm]
        if norm2!=want: continue
        k=[int(re.search(r'(0x[0-9A-F]+)$',ins[i]).group(1),16) for i in (1,9,10,14)]
        if ins[6]!=ins[11]: continue
        off=int(re.search(r'(0x[0-9A-F]+)\(',ins[6]).group(1),16)
        code=('extern struct opaque D_80048ABC;\nvoid %s(void) {\n    u8 *f = (u8 *)&D_80048ABC;\n\n'
              '    (*(void (**)(s32, s32))(f + 0x%X))(0x%X, %d);\n    (*(void (**)(s32, s32))(f + 0x%X))(0x%X, %d);\n}\n')%(fn,off,k[0],k[1],off,k[2],k[3])
        out.setdefault(t,{})[fn]=code
n=0
for t,fs in out.items():
    p=os.path.join('build/autodecomp',t,'results.json')
    os.makedirs(os.path.dirname(p),exist_ok=True)
    res=json.load(open(p)) if os.path.exists(p) else {}
    for fn,code in fs.items():
        res[fn]={'status':'ok','code':code,'types':{},'variant':0}; n+=1
    json.dump(res,open(p,'w'),indent=1)
print(n,'geradas em',len(out),'alvos')
