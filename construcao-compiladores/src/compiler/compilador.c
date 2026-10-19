#include "compilador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// COMPILADOR (compilador.c)

//Este módulo é a "fachada" (facade) do sistema: esconde a complexidade
// do léxico e do parser atrás de duas funções simples.
// O main.c só precisa chamar compilador_ler_arquivo() e compilador_analisar().

// compilador_ler_arquivo: abre o arquivo, descobre seu tamanho,
// aloca memória suficiente e lê tudo de uma vez.
// Por que alocar dinamicamente? Porque não sabemos o tamanho do arquivo
// em tempo de compilação. Usamos fseek/ftell para descobrir o tamanho.

char *compilador_ler_arquivo(const char *caminho) {
    FILE *f = fopen(caminho, "r");
    if (!f) {
        fprintf(stderr, "Erro: nao foi possivel abrir o arquivo '%s'\n", caminho);
        return NULL;
    }

    // Vai até o fim do arquivo para descobrir o tamanho.
    fseek(f, 0, SEEK_END);
    long tamanho = ftell(f);
    fseek(f, 0, SEEK_SET); // Volta ao início.

    // Aloca tamanho + 1 byte para o '\0' terminador.
    char *buffer = (char *)malloc(tamanho + 1);
    if (!buffer) {
        fprintf(stderr, "Erro: sem memoria para ler o arquivo\n");
        fclose(f);
        return NULL;
    }

    // Lê o arquivo inteiro de uma vez.
    long lidos = (long)fread(buffer, 1, tamanho, f);
    buffer[lidos] = '\0'; // Garante terminação da string.
    fclose(f);

    return buffer;
}

// compilador_analisar: orquestra léxico + parser e devolve um resultado
// estruturado. Não imprime nada — quem imprime é o main.c.

ResultadoAnalise compilador_analisar(const char *codigo) {
    ResultadoAnalise resultado;
    resultado.sucesso    = 0;
    resultado.linha_erro = 0;
    resultado.mensagem[0] = '\0';

    // Inicializa e executa o parser (o parser inicializa o lexer internamente).
    Parser parser;
    parser_inicializar(&parser, codigo);
    int ok = parser_analisar(&parser);

    if (ok) {
        resultado.sucesso = 1;
        strncpy(resultado.mensagem, "Programa sintaticamente correto.",
                sizeof(resultado.mensagem) - 1);
    } else {
        resultado.sucesso    = 0;
        resultado.linha_erro = parser.linha_erro;
        strncpy(resultado.mensagem, parser.msg_erro,
                sizeof(resultado.mensagem) - 1);
    }

    return resultado;
}