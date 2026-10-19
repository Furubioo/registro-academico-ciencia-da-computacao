# Estruturas de Dados Lineares em C

Implementações de listas encadeadas, filas, pilhas, deques e tabela hash. Há versões sucessivas da mesma estrutura porque elas registram práticas diferentes da disciplina; o sufixo `-2` marca a segunda versão do mesmo exercício.

| Arquivo | Estrutura |
| --- | --- |
| `deque-com-lista-ligada.c` / `deque-com-lista-ligada-2.c` | deque básico (push/pop/inject/eject) |
| `deque-com-busca-e-remocao.c` | deque com busca e remoção por valor |
| `fila-com-vetor.c` | fila com vetor de tamanho fixo |
| `fila-com-lista-ligada.c` | fila com lista ligada |
| `fila-senha-atendimento.c` | fila aplicada a um sistema de senhas de atendimento |
| `pilha-com-lista-ligada.c` | pilha com lista ligada |
| `lista-simples-tad.c` / `lista-simples-tad-2.c` | lista simplesmente encadeada (TAD completo) |
| `lista-circular-completa.c` | lista circular com inserção, remoção e busca |
| `lista-circular-busca.c` | lista circular, apenas busca |
| `lista-circular-com-insercao-e-remocao.c` | lista circular com menu completo de inserção/remoção |
| `lista-duplamente-encadeada-com-contagem.c` | lista dupla com contagem de ocorrências e listagem invertida |
| `lista-copia-identica-e-invertida.c` | lista dupla com cópia idêntica e cópia invertida |
| `lista-classificacao-de-alunos.c` | lista dupla circular aplicada à classificação de alunos |
| `lista-cadastro-alunos-media-faltas.c` | lista aplicada a um cadastro de alunos com média e faltas |
| `lista-insercao-e-remocao-por-valor.c` | lista com inserção e remoção por valor (inteiros) |
| `lista-de-nomes-remocao-por-valor.c` | mesma ideia, para uma lista de nomes |
| `lista-uniao-intersecao-diferenca.c` | lista aplicada a operações de conjunto (união, interseção, diferença) |
| `lista-multiplicacao-de-listas.c` | lista aplicada à multiplicação de dois números representados como listas |
| `lista-simples-busca-e-somatorio.c` | lista simples com busca e somatório |
| `cadastro-carros-tabela-hash.c` / `cadastro-carros-tabela-hash-com-lista.c` | cadastro de carros com tabela hash (duas implementações) |

## Executar

```bash
gcc -Wall -Wextra -std=c11 lista-simples-tad.c -o lista_tad
./lista_tad
```

`cadastro-carros-tabela-hash.c` combina persistência em arquivo e tabela hash; ele cria o arquivo de dados localmente durante a execução, que é ignorado pelo Git.
