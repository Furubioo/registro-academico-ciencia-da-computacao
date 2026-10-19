# Repositório Acadêmico em Ciência da Computação

Este repositório reúne atividades desenvolvidas em disciplinas de Ciência da Computação, preservando o contexto de estudo, a evolução acadêmica e a documentação original dos exercícios e projetos. O objetivo principal não é simular um portfólio profissional, mas registrar de forma clara aquilo que foi aprendido, praticado e revisado ao longo do curso.

## Propósito e contexto

- O material representa exercícios, revisões, notebooks e projetos didáticos realizados em diferentes períodos.
- A organização foi feita por disciplina e por tema, mantendo nomes e descrições dos arquivos o mais próximos possível do contexto original.
- Há variação de complexidade e acabamento entre os itens; isso reflete o processo real de aprendizagem.
- O repositório serve como referência técnica para consulta, revisão de conceitos e avaliação de progresso acadêmico.

## Estrutura principal

| Disciplina / área | Conteúdo principal | Link |
| --- | --- | --- |
| `fundamentos-python` | exercícios de lógica, condicionais, laços, strings, funções e recursão | [fundamentos-python/README.md](fundamentos-python/README.md) |
| `programacao-estruturada-c` | exercícios em C organizados por conceito | [programacao-estruturada-c/README.md](programacao-estruturada-c/README.md) |
| `estruturas-dados-c` | estruturas lineares, cadastros e algoritmos de dados | [estruturas-dados-c/README.md](estruturas-dados-c/README.md) |
| `poo-java` | projetos independentes em Java com orientação a objetos | [poo-java/README.md](poo-java/README.md) |
| `algebra-linear-computacional` | notebooks e materiais de álgebra linear | [algebra-linear-computacional/README.md](algebra-linear-computacional/README.md) |
| `calculo-computacional` | notebooks e revisões de cálculo | [calculo-computacional/README.md](calculo-computacional/README.md) |
| `metodos-numericos` | notebooks de métodos numéricos | [metodos-numericos/README.md](metodos-numericos/README.md) |
| `fundamentos-hardware` | atividades com Raspberry Pi e lógica de hardware | [fundamentos-hardware/README.md](fundamentos-hardware/README.md) |
| `infraestrutura-software` | concorrência, cabeçalhos e ambiente de teste | [infraestrutura-software/README.md](infraestrutura-software/README.md) |
| `construcao-compiladores` | implementação e testes de compilador | [construcao-compiladores/README.md](construcao-compiladores/README.md) |
| `projetos-exploratorios` | atividades exploratórias e notebooks | [projetos-exploratorios/README.md](projetos-exploratorios/README.md) |

## Linguagens e ferramentas presentes

- Python 3 para exercícios e notebooks
- C (gcc, padrões C11) para algoritmos e estruturas de dados
- Java para projetos orientados a objetos
- Jupyter notebooks para modelagem e matemática computacional
- GitHub Actions e scripts de validação de atividades acadêmicas
- Raspberry Pi / GPIO em atividades de hardware

## Tipos de atividade

- Exercícios independentes e revisões
- Implementações de algoritmos e estruturas de dados
- Soluções de listas e simulados
- Notebooks de cálculo, álgebra linear e métodos numéricos
- Projetos didáticos em Java e em C
- Atividades de infraestrutura e compiladores

## Como executar

### C

```bash
gcc -std=c11 -Wall arquivo.c -o programa
./programa
```

### Java

```bash
cd poo-java/NomeDoProjeto
javac -d out *.java
java -cp out NomeDaClassePrincipal
```

### Python

```bash
python3 nome_do_script.py
```

### Notebooks

Os notebooks utilizam bibliotecas listadas em `requirements-notebooks.txt`:

```bash
python3 -m pip install -r requirements-notebooks.txt
```

## Observações importantes

- Este é um material acadêmico autêntico, não uma coleção artificialmente "polida" para fins de marketing.
- Nomes de arquivos, comentários didáticos e soluções alternativas foram preservados quando relevantes ao contexto.
- Alguns projetos possuem dependências específicas de aula, testes automatizados ou materiais de apoio; por isso, a execução pode variar conforme a disciplina.
- Dados pessoais, informações sensíveis e segredos foram verificados antes da preparação para publicação pública.

## Navegação rápida

- [README de fundamentos em Python](fundamentos-python/README.md)
- [README de programação estruturada em C](programacao-estruturada-c/README.md)
- [README de estruturas de dados em C](estruturas-dados-c/README.md)
- [README de POO em Java](poo-java/README.md)
- [README de infraestrutura de software](infraestrutura-software/README.md)

Consulte os READMEs específicos de cada área para detalhes de compilação, conceitos e organização dos arquivos.
