# Compilador C Simplificado

Projeto de Construção de Compiladores: análise léxica e sintática para uma versão simplificada de C. A arquitetura separa tokens, lexer, parser e orquestração do compilador, mantendo a organização original da disciplina.

## Estrutura

- `src/token/`: definição de tokens
- `src/lexer/`: análise léxica
- `src/parser/`: análise sintática
- `src/compiler/`: orquestração e compilação
- `tests/`: testes do lexer e do parser
- `examples/`: entradas de exemplo

## Compilar e executar

```bash
mkdir -p build
gcc -Wall -Wextra -std=c11 -Isrc/token -Isrc/lexer -Isrc/parser -Isrc/compiler src/main.c src/token/token.c src/lexer/lexer.c src/parser/parser.c src/compiler/compilador.c -o build/compilador
./build/compilador examples/input.txt
```

O comando acima foi validado no ambiente local com sucesso. Os testes da disciplina e a arquitetura do compilador foram preservados sem reescrever a lógica original.
