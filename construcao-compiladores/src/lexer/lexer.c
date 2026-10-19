#include "lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------------------
// ANALISADOR LÉXICO (lexer.c)
//
// Responsabilidade: transformar o código-fonte (texto bruto) em uma
// sequência de tokens. Não verifica se a sequência faz sentido
// gramaticalmente — isso é trabalho do parser.
//
// Funcionamento geral:
//   1. Pula espaços em branco e comentários.
//   2. Olha o primeiro caractere relevante.
//   3. Decide qual categoria de token pode começar por ali.
//   4. Consome os caracteres necessários e preenche o Token.
// -----------------------------------------------------------------------

// ------------------------------------------------------------------
// Funções auxiliares internas (static = visíveis só neste arquivo)
// ------------------------------------------------------------------

// Retorna o caractere na posição atual sem avançar.
static char atual(Lexer *l) {
    return l->codigo[l->pos];
}

// Avança uma posição e retorna o caractere que estava lá.
static char avancar(Lexer *l) {
    char c = l->codigo[l->pos];
    if (c == '\n') l->linha++;   // Rastreia a linha para mensagens de erro.
    l->pos++;
    return c;
}

// Olha o próximo caractere (pos+1) sem avançar — "lookahead de 1".
static char proximo(Lexer *l) {
    if (l->codigo[l->pos] == '\0') return '\0';
    return l->codigo[l->pos + 1];
}

// Pula espaços, tabulações e quebras de linha.
static void pular_espacos(Lexer *l) {
    while (atual(l) != '\0' && isspace((unsigned char)atual(l))) {
        avancar(l);
    }
}

// ------------------------------------------------------------------
// Tabela de palavras-chave
// Quando o léxico lê um identificador, confere aqui se é palavra-chave.
// ------------------------------------------------------------------
typedef struct {
    const char *palavra;
    TipoToken   tipo;
} PalavraChave;

static PalavraChave palavras_chave[] = {
    {"int",   TOKEN_INT},
    {"float", TOKEN_FLOAT},
    {"char",  TOKEN_CHAR},
    {"if",    TOKEN_IF},
    {"else",  TOKEN_ELSE},
    {"while", TOKEN_WHILE},
    {"do",    TOKEN_DO},
    {"main",  TOKEN_MAIN},
    {NULL,    TOKEN_ERRO}   // Sentinela: fim da tabela.
};

// Verifica se 'texto' é uma palavra-chave; retorna o tipo ou TOKEN_ID.
static TipoToken verificar_palavra_chave(const char *texto) {
    for (int i = 0; palavras_chave[i].palavra != NULL; i++) {
        if (strcmp(texto, palavras_chave[i].palavra) == 0) {
            return palavras_chave[i].tipo;
        }
    }
    return TOKEN_ID;
}

// ------------------------------------------------------------------
// lexer_inicializar
// ------------------------------------------------------------------
void lexer_inicializar(Lexer *lexer, const char *codigo) {
    lexer->codigo = codigo;
    lexer->pos    = 0;
    lexer->linha  = 1;  // Linhas começam em 1 (convenção humana).
}

// ------------------------------------------------------------------
// lexer_proximo_token
// Função principal do léxico: retorna o próximo Token do código.
// ------------------------------------------------------------------
Token lexer_proximo_token(Lexer *lexer) {
    Token tok;
    tok.lexema[0] = '\0';
    tok.linha     = lexer->linha;

    pular_espacos(lexer);

    // Atualiza a linha do token após pular espaços.
    tok.linha = lexer->linha;

    char c = atual(lexer);

    // ---- Fim do arquivo ------------------------------------------
    if (c == '\0') {
        tok.tipo = TOKEN_EOF;
        strcpy(tok.lexema, "EOF");
        return tok;
    }

    // ---- Identificadores e palavras-chave -------------------------
    // Começam com letra ou '_'.
    if (isalpha((unsigned char)c) || c == '_') {
        int i = 0;
        while (isalnum((unsigned char)atual(lexer)) || atual(lexer) == '_') {
            if (i < MAX_LEXEMA - 1) {
                tok.lexema[i++] = avancar(lexer);
            } else {
                avancar(lexer); // Descarta excesso mas não para.
            }
        }
        tok.lexema[i] = '\0';
        tok.tipo = verificar_palavra_chave(tok.lexema);
        return tok;
    }

    // ---- Constantes numéricas -------------------------------------
    // Podem ser inteiras (ex.: 42) ou de ponto flutuante (ex.: 2.0).
    if (isdigit((unsigned char)c)) {
        int i = 0;
        tok.tipo = TOKEN_INT_CONST;

        while (isdigit((unsigned char)atual(lexer))) {
            if (i < MAX_LEXEMA - 1) tok.lexema[i++] = avancar(lexer);
            else avancar(lexer);
        }

        // Se há ponto seguido de dígito, é float.
        if (atual(lexer) == '.' && isdigit((unsigned char)proximo(lexer))) {
            tok.tipo = TOKEN_FLOAT_CONST;
            if (i < MAX_LEXEMA - 1) tok.lexema[i++] = avancar(lexer); // '.'
            while (isdigit((unsigned char)atual(lexer))) {
                if (i < MAX_LEXEMA - 1) tok.lexema[i++] = avancar(lexer);
                else avancar(lexer);
            }
        }

        tok.lexema[i] = '\0';
        return tok;
    }

    // ---- Constante de caractere: 'a', '\n', etc. ------------------
    if (c == '\'') {
        int i = 0;
        tok.tipo = TOKEN_CHAR_CONST;
        tok.lexema[i++] = avancar(lexer); // ' de abertura

        if (atual(lexer) == '\\') {       // Sequência de escape (ex.: '\n')
            if (i < MAX_LEXEMA - 1) tok.lexema[i++] = avancar(lexer);
        }
        if (atual(lexer) != '\0' && atual(lexer) != '\'') {
            if (i < MAX_LEXEMA - 1) tok.lexema[i++] = avancar(lexer);
        }
        if (atual(lexer) == '\'') {       // ' de fechamento
            if (i < MAX_LEXEMA - 1) tok.lexema[i++] = avancar(lexer);
        }
        tok.lexema[i] = '\0';
        return tok;
    }

    // ---- Operadores e delimitadores -------------------------------
    // Avança o caractere e preenche o lexema de um único símbolo.
    avancar(lexer);
    tok.lexema[0] = c;
    tok.lexema[1] = '\0';

    switch (c) {
        case '+': tok.tipo = TOKEN_PLUS;      return tok;
        case '-': tok.tipo = TOKEN_MINUS;     return tok;
        case '*': tok.tipo = TOKEN_STAR;      return tok;
        case '/': tok.tipo = TOKEN_SLASH;     return tok;
        case '(': tok.tipo = TOKEN_LPAREN;    return tok;
        case ')': tok.tipo = TOKEN_RPAREN;    return tok;
        case '{': tok.tipo = TOKEN_LBRACE;    return tok;
        case '}': tok.tipo = TOKEN_RBRACE;    return tok;
        case ';': tok.tipo = TOKEN_SEMICOLON; return tok;
        case ',': tok.tipo = TOKEN_COMMA;     return tok;

        // Operadores que podem ter dois caracteres: =, ==, <, <=, >, >=, !=
        case '=':
            if (atual(lexer) == '=') {
                tok.lexema[1] = avancar(lexer);
                tok.lexema[2] = '\0';
                tok.tipo = TOKEN_EQ;
            } else {
                tok.tipo = TOKEN_ASSIGN;
            }
            return tok;

        case '<':
            if (atual(lexer) == '=') {
                tok.lexema[1] = avancar(lexer);
                tok.lexema[2] = '\0';
                tok.tipo = TOKEN_LE;
            } else {
                tok.tipo = TOKEN_LT;
            }
            return tok;

        case '>':
            if (atual(lexer) == '=') {
                tok.lexema[1] = avancar(lexer);
                tok.lexema[2] = '\0';
                tok.tipo = TOKEN_GE;
            } else {
                tok.tipo = TOKEN_GT;
            }
            return tok;

        case '!':
            if (atual(lexer) == '=') {
                tok.lexema[1] = avancar(lexer);
                tok.lexema[2] = '\0';
                tok.tipo = TOKEN_NE;
            } else {
                tok.tipo = TOKEN_ERRO;
            }
            return tok;

        default:
            // Qualquer caractere não reconhecido vira TOKEN_ERRO.
            tok.tipo = TOKEN_ERRO;
            return tok;
    }
}
