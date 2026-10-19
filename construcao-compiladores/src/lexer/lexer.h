#ifndef LEXER_H
#define LEXER_H

#include "token.h"

//Lexer: Guarda todo o estado necessário para percorrer o código-fonte
//caractere por caractere sem precisar de variáveis globais.
//codigo: Ponteiro para a string completa do código-fonte.
//pos: Índice do próximo caractere a ser lido.
//linha: Contador de linhas (começa em 1), atualizando a cada '\n'.

typedef struct {
    const char *codigo;
    int pos;
    int linha;
} Lexer;

//lexer_inicializar: Prepara o Lexer para ler o 'codigo' a partir do início.
//Deve ser chamada antes de qualquer lexer_proximo_token.

void lexer_inicializar(Lexer *l, const char *codigo);

//lexer_proximo_token: Avança no código-fonte e devolve o próximo Token encontrado.
//Ignora espaços, tabs e quebras de linha automaticamente.
//Devolve TOKEN_EOF quando o código acaba.
//Devolve TOKEN_ERRO para caracteres não reconhecidos.

Token lexer_proximo_token(Lexer *l);

#endif
