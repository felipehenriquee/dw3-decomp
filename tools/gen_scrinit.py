import re, subprocess, sys, os
R=os.path.expanduser('~/dw3-decomp')
out=subprocess.run([sys.executable,'-I','tools/pending.py','--skip','build/w/skip.txt'],capture_output=True,text=True,cwd=R).stdout
tmpl=open(f'{R}/build/w/n22.c').read()
for ln in out.splitlines():
    n,t,f=ln.split()
    if t=='main': continue
    p=f'{R}/asm/ovl/{t}/nonmatchings/{t}/{f}.s'
    if not os.path.exists(p): continue
    s=open(p).read()
    if '0x16C(' not in s or '0x174(' not in s or 'D_8004DE10' not in s: continue
    try:
      m154=re.search(r'0x154\(\$s0\).*?jalr.*?\n.*?(?:addiu\s+\$a0, \$zero, (0x[0-9A-F]+)|ori\s+\$a0, \$a0, \((0x[0-9A-F]+) & 0xFFFF\))',s,re.S)
      k154=m154.group(1) or m154.group(2)
      m16c=re.search(r'addiu\s+\$a1, \$zero, (0x[0-9A-F]+)\n.*?addiu\s+\$a2, \$zero, 0x1000',s)
      callee=re.search(r'jal\s+(func_[0-9A-F]+)',s.split('0x12C(')[1]).group(1)
      c=tmpl.replace('func_80082CD0',f).replace('(0x5000)','(%s)'%k154).replace('(r, 2, 0x1000)','(r, %s, 0x1000)'%m16c.group(1)).replace('func_80087B08',callee)
    except Exception as e:
      print(t,f,"falhou extracao"); continue
    fn=f'{R}/build/w/scr_{t}_{f}.c'; open(fn,'w').write(c)
    r=subprocess.run([sys.executable,'-I','tools/fn.py',t,f,'test',fn],capture_output=True,text=True,cwd=R).stdout.strip().splitlines()
    print(t,f,r[-1] if r else '?')
