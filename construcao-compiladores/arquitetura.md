# Arquitetura do Compilador

## Visão Geral do Fluxo

<p align="center">
  <img src="../assets/fluxo_compilacao.png" alt="Fluxo de Compilação" width="800">
</p>

```
input.txt ──▶ Analisador Léxico ──▶ Analisador Sintático ──▶ Resultado
              (lexer)               (parser)                 Sucesso / Erro
```

## Estrutura de Diretórios

```
src/
├── main.c
├── token/
│   ├── token.h
│   └── token.c
├── lexer/
│   ├── lexer.h
│   └── lexer.c
├── parser/
│   ├── parser.h
│   └── parser.c
└── compiler/
    ├── compilador.h
    └── compilador.c
```

## Módulos

### Token (`src/token/`)

Define a estrutura de dados central: o **Token**. Consulte o header para ver os tipos disponíveis.

### Lexer (`src/lexer/`)

Responsável por transformar o código-fonte em uma sequência de tokens. A implementação deve ser feita pelo aluno com base na gramática fornecida.

### Parser (`src/parser/`)

Consome os tokens produzidos pelo lexer e valida a estrutura do programa contra a gramática BNF. A técnica sugerida é o **parser descendente recursivo**.

### Compiler (`src/compiler/`)

Fachada que orquestra o fluxo completo: leitura do arquivo → análise léxica → análise sintática.
