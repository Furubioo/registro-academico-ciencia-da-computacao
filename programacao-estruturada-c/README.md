# Programação Estruturada em C

Esta disciplina concentra a maior coleção da trilha: **124 exercícios independentes**. Cada programa possui seu próprio `main` e foi colocado na área correspondente ao conceito predominante.

| Pasta | Conteúdo |
| --- | --- |
| `fundamentos` | entrada e saída, condicionais, laços, funções numéricas |
| `vetores` e `matrizes` | estruturas sequenciais e bidimensionais |
| `strings` | manipulação e validação de texto |
| `funcoes-e-ponteiros` | decomposição e passagem por referência |
| `structs-e-cadastros` | tipos compostos e operações de cadastro |
| `arquivos` | leitura, gravação e consulta binária |
| `revisao` | listas de revisão e simulados |

Os nomes de arquivos descrevem a tarefa. O sufixo numérico que aparece em parte dos nomes indica apenas a posição de origem na lista, sem substituir a descrição semântica.

## Compilação

```bash
gcc -std=c11 -Wall exercicios/fundamentos/fundamentos-001-soma-de-5-2.c -o soma
```

Arquivos que criam `produtos.dat` devem ser executados em uma pasta gravável. Não há executáveis versionados no repositório.
