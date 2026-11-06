#!/usr/bin/env bash
# Usage: ./run.sh file.cpp [program args...]
set -e

if [ $# -lt 1 ]; then
  echo "Usage: $0 file.cpp [program args...]" >&2
  exit 1
fi

src="$1"
shift

if [ ! -f "$src" ]; then
  echo "Error: file not found: $src" >&2
  exit 1
fi

out="${src%.*}"
if [ "$out" = "$src" ]; then
  out="$src.out"
fi

g++ -std=c++17 -Wall -Wextra -o "$out" "$src"

case "$out" in
  /*) exec "$out" "$@" ;;
  *) exec "./$out" "$@" ;;
esac
