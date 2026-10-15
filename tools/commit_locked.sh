#!/bin/sh
# Commit + push segurando a trava de integracao (ver proj.apply_lock), para
# nao capturar um lote que o autodecomp ainda esta conferindo com o make.
# Uso: tools/commit_locked.sh "mensagem"
cd "$(dirname "$0")/.." || exit 1
mkdir -p build
exec flock build/.apply.lock sh -c 'git add -A && git commit -q -m "$1" && git push -q' sh "$1"
