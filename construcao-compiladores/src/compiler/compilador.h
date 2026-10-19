#ifndef COMPILADOR_H
#define COMPILADOR_H

#include "lexer.h"
#include "parser.h"
#include "token.h"

// ResultadoAnalise: struct retornado pela função principal do compilador.
// sucesso: 1 se o programa for válido ou 0 se houver erro.
// mensagem: descrição do resultado (sucesso ou erro).
// linha_erro: a linha em que o erro ocorreu. Se houver sucesso o valor será 0.

typedef struct {
    int sucesso;
    char mensagem [512];
    int linha_erro;

} ResultadoAnalise;

// compilador_ler_arquivo: lê o conteúdo de um arquivo texto e retorna
// uma string alocada dinamicamente com o código-fonte.
// O chamador é responsável por chamar free() na string retornada.
// Retorna NULL em caso de erro ao abrir ou ler o arquivo.

// caminho: endereço do arquivo no sistema de arquivos.

char *compilador_ler_arquivo(const char *caminho);

// compilador_analisar: executa o pipeline completa:
// 1. Inicializa o parser (que inicializa internamente o lexer);
// 2. Executa a análise sintática (que consome tokens do léxico);
// 3. Retorna o resultado indicando sucesso ou a mensagem de erro.

// codigo: string com o código-fonte completo (já lido do arquivo).

ResultadoAnalise compilador_analisar(const char *codigo);

#endif
