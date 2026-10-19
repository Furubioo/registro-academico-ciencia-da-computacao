#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "token.h"

// Parser: Estrutura que mantém o estado do analisador sintático.
// lexer: O analisador léxico de onde os tokens são obtidos
// token_atual: O token que está sendo analisado no momento
// erro: 1 Se houver um erro sintático, 0 caso contrário
// msg_erro: Mensagem descrevendo o erro encontrado
// linha_erro: Linha onde o erro ocorreu

// O parser usa a técnica de "descida recursiva" (recursive descent):
// cada regra da gramática BNF vira uma função. As funções se chamam
// mutuamente conforme a gramática expande os não-terminais.

typedef struct {
    Lexer lexer;
    Token token_atual;
    int erro;
    char msg_erro[512];
    int linha_erro;
} Parser;

// parser_inicializar: Configura o parser com o código-fonte a analisar.
// Já lê o primeiro token para que o token_atual esteja pronto.
// parser: Estrutura a inicializar
// código: String com o código-fonte completo

void parser_inicializar(Parser *parser,const char *codigo);

// parser_analisar: Ponto de entrada da análise sintática.
// Tenta reconhecer o programa inteiro a partir da regra raiz <programa>
// Retorna 1 se o programa é sintaticamente correto e 0 se há erro.

// parser - estado do parser(já inicializado).

int parser_analisar(Parser *parser);

#endif
