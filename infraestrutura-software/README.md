# Infraestrutura de Software e Concorrência

Este diretório reúne uma atividade de sistemas concorrentes baseada no algoritmo de Peterson para exclusão mútua. O foco está em sincronização entre threads, acesso compartilhado a recursos críticos e validação dos comportamentos esperados da disciplina.

## Conteúdo

- `src/peterson/`: implementação do algoritmo de Peterson
- `src/conta/`: estrutura de dados e lógica do saldo compartilhado
- `src/threads/`: coordenação e uso de threads com pthread
- `test/`: artefatos de teste fornecidos pela disciplina

## Validação

A atividade original inclui um binário `test/test_suite.o` e uma configuração de GitHub Actions que o usa em um ambiente Unix-like. Em um ambiente Windows, o arquivo binário não pode ser executado diretamente, mas a estrutura do projeto permanece preservada para documentação e reprodução em Linux/macOS.

Para compilar os arquivos em um ambiente compatível com `pthread`, use:

```bash
gcc src/peterson/peterson.c src/conta/conta.c src/threads/thread.c test/test_suite.o -o test_suite -lpthread
./test_suite
```

Se o binário de teste for incompatível com a plataforma local, a opção segura é manter o artefato original e documentar a limitação, em vez de reconstruir ou substituir conteúdo acadêmico da disciplina.
