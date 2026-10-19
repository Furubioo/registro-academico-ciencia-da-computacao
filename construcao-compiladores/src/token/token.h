#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_CHAR,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_DO,
    TOKEN_MAIN,
    TOKEN_ID,
    TOKEN_INT_CONST,
    TOKEN_FLOAT_CONST,
    TOKEN_CHAR_CONST,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_ASSIGN,
    TOKEN_LT,
    TOKEN_GT,
    TOKEN_LE,
    TOKEN_GE,
    TOKEN_EQ,
    TOKEN_NE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_SEMICOLON,
    TOKEN_COMMA,
    TOKEN_EOF,
    TOKEN_ERRO
} TipoToken;

#define MAX_LEXEMA 256

typedef struct {
    TipoToken tipo;
    char      lexema[MAX_LEXEMA];
    int       linha;
} Token;

char* token_tipo_para_string(TipoToken tipo);

#endif
