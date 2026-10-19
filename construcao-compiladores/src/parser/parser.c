#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Protótipos das funções auxiliares e regras da gramática BNF
static void parser_avancar(Parser *p);
static int  parser_consumir(Parser *p, TipoToken esperado, const char *regra, const char *detalhe);
static void parser_erro(Parser *p, const char *regra, const char *detalhe);

static void parser_programa(Parser *p);
static void parser_bloco(Parser *p);
static void parser_lista_declaracoes(Parser *p);
static void parser_declaracao(Parser *p);
static void parser_lista_comandos(Parser *p);
static void parser_comando(Parser *p);
static void parser_atribuicao(Parser *p);
static void parser_condicional(Parser *p);
static void parser_iteracao(Parser *p);
static void parser_expr_relacional(Parser *p);
static void parser_expr_aritmetica(Parser *p);
static void parser_termo(Parser *p);
static void parser_fator(Parser *p);

// -----------------------------------------------------------------------

// Pede o próximo token para o Lexer se o parser não estiver travado em erro
static void parser_avancar(Parser *p) {
    if (p->erro) return;
    p->token_atual = lexer_proximo_token(&p->lexer);
}

//
// parser_erro: monta a mensagem citando a regra BNF violada, o que era
// esperado, e o que foi encontrado no código-fonte.
//
//   regra   - a regra BNF no formato "<nome_regra>"
//   detalhe - o que especificamente era esperado neste ponto
//
static void parser_erro(Parser *p, const char *regra, const char *detalhe) {
    if (p->erro) return;
    p->erro       = 1;
    p->linha_erro = p->token_atual.linha;
    snprintf(p->msg_erro, sizeof(p->msg_erro),
             "Linha %d — Regra violada: %s\n"
             "         Esperado : %s\n"
             "         Encontrado: '%s'",
             p->token_atual.linha,
             regra,
             detalhe,
             p->token_atual.lexema[0] != '\0'
                 ? p->token_atual.lexema
                 : token_tipo_para_string(p->token_atual.tipo));
}

//
// parser_consumir: verifica se o token atual é o esperado pela regra.
// Se não for, chama parser_erro com a regra e o detalhe fornecidos.
//
static int parser_consumir(Parser *p, TipoToken esperado,
                            const char *regra, const char *detalhe) {
    if (p->erro) return 0;
    if (p->token_atual.tipo == esperado) {
        parser_avancar(p);
        return 1;
    }
    parser_erro(p, regra, detalhe);
    return 0;
}

// -----------------------------------------------------------------------

// Configura o parser apontando para o início do texto do código fonte
void parser_inicializar(Parser *parser, const char *codigo) {
    lexer_inicializar(&parser->lexer, codigo);
    parser->erro        = 0;
    parser->msg_erro[0] = '\0';
    parser->linha_erro  = 0;
    parser->token_atual = lexer_proximo_token(&parser->lexer);
}

// Executa o ponto de entrada da análise sintática
int parser_analisar(Parser *parser) {
    parser_programa(parser);
    // Garante que após o programa não existem caracteres perdidos no arquivo
    if (!parser->erro && parser->token_atual.tipo != TOKEN_EOF) {
        parser_erro(parser,
                    "<programa>",
                    "fim do arquivo após o bloco principal — tokens inesperados após '}'");
    }
    return !parser->erro;
}

// -----------------------------------------------------------------------

//
// <programa> ::= int main ( ) <bloco>
//
static void parser_programa(Parser *p) {
    if (p->erro) return;
    parser_consumir(p, TOKEN_INT,
                    "<programa> ::= int main ( ) <bloco>",
                    "'int' para iniciar o programa");
    parser_consumir(p, TOKEN_MAIN,
                    "<programa> ::= int main ( ) <bloco>",
                    "'main' após 'int'");
    parser_consumir(p, TOKEN_LPAREN,
                    "<programa> ::= int main ( ) <bloco>",
                    "'(' após 'main'");
    parser_consumir(p, TOKEN_RPAREN,
                    "<programa> ::= int main ( ) <bloco>",
                    "')' para fechar a lista de parâmetros de 'main'");
    parser_bloco(p);
}

//
// <bloco> ::= { <lista_declaracoes> <lista_comandos> }
//
static void parser_bloco(Parser *p) {
    if (p->erro) return;
    parser_consumir(p, TOKEN_LBRACE,
                    "<bloco> ::= { <lista_declaracoes> <lista_comandos> }",
                    "'{' para abrir o bloco");
    parser_lista_declaracoes(p);
    parser_lista_comandos(p);
    parser_consumir(p, TOKEN_RBRACE,
                    "<bloco> ::= { <lista_declaracoes> <lista_comandos> }",
                    "'}' para fechar o bloco");
}

//
// <lista_declaracoes> ::= <declaracao> <lista_declaracoes> | ε
//
static void parser_lista_declaracoes(Parser *p) {
    if (p->erro) return;
    while (!p->erro &&
           (p->token_atual.tipo == TOKEN_INT   ||
            p->token_atual.tipo == TOKEN_FLOAT ||
            p->token_atual.tipo == TOKEN_CHAR)) {
        parser_declaracao(p);
    }
}

//
// <declaracao> ::= <tipo> id { , id } ;
// <tipo>       ::= int | float | char
//
static void parser_declaracao(Parser *p) {
    if (p->erro) return;

    if (p->token_atual.tipo == TOKEN_INT   ||
        p->token_atual.tipo == TOKEN_FLOAT ||
        p->token_atual.tipo == TOKEN_CHAR) {
        parser_avancar(p);
    } else {
        parser_erro(p,
                    "<declaracao> ::= <tipo> id { , id } ;",
                    "tipo válido: 'int', 'float' ou 'char'");
        return;
    }

    parser_consumir(p,
                    TOKEN_ID,
                    "<declaracao> ::= <tipo> id { , id } ;",
                    "identificador (nome de variável) após o tipo");

    while (!p->erro && p->token_atual.tipo == TOKEN_COMMA) {
        parser_avancar(p);
        parser_consumir(p,
                        TOKEN_ID,
                        "<declaracao> ::= <tipo> id { , id } ;",
                        "identificador (nome de variável) após ','");
    }

    parser_consumir(p,
                    TOKEN_SEMICOLON,
                    "<declaracao> ::= <tipo> id { , id } ;",
                    "';' para encerrar a declaração");
}

//
// <lista_comandos> ::= <comando> <lista_comandos> | ε
//
static void parser_lista_comandos(Parser *p) {
    if (p->erro) return;
    while (!p->erro &&
           (p->token_atual.tipo == TOKEN_ID     ||
            p->token_atual.tipo == TOKEN_LBRACE ||
            p->token_atual.tipo == TOKEN_IF     ||
            p->token_atual.tipo == TOKEN_WHILE  ||
            p->token_atual.tipo == TOKEN_DO)) {
        parser_comando(p);
    }
}

//
// <comando> ::= <atribuicao> | <bloco> | <iteracao> | <condicional>
//
static void parser_comando(Parser *p) {
    if (p->erro) return;

    switch (p->token_atual.tipo) {
        case TOKEN_ID:     parser_atribuicao(p);  break;
        case TOKEN_LBRACE: parser_bloco(p);        break;
        case TOKEN_IF:     parser_condicional(p);  break;
        case TOKEN_WHILE:
        case TOKEN_DO:     parser_iteracao(p);     break;
        default:
            parser_erro(p,
                        "<comando> ::= <atribuicao> | <bloco> | <iteracao> | <condicional>",
                        "início de comando válido: identificador, '{', 'if', 'while' ou 'do'");
            break;
    }
}

//
// <atribuicao> ::= id = <expr_aritmetica> ;
//
static void parser_atribuicao(Parser *p) {
    if (p->erro) return;
    parser_consumir(p,
                    TOKEN_ID,
                    "<atribuicao> ::= id = <expr_aritmetica> ;",
                    "identificador (variável) no lado esquerdo da atribuição");
    parser_consumir(p,
                    TOKEN_ASSIGN,
                    "<atribuicao> ::= id = <expr_aritmetica> ;",
                    "'=' após o identificador");
    parser_expr_aritmetica(p);
    parser_consumir(p,
                    TOKEN_SEMICOLON,
                    "<atribuicao> ::= id = <expr_aritmetica> ;",
                    "';' para encerrar a atribuição");
}

//
// <condicional> ::= if ( <expr_relacional> ) <comando> [ else <comando> ]
//
static void parser_condicional(Parser *p) {
    if (p->erro) return;
    parser_consumir(p,
                    TOKEN_IF,
                    "<condicional> ::= if ( <expr_relacional> ) <comando> [ else <comando> ]",
                    "'if'");
    parser_consumir(p,
                    TOKEN_LPAREN,
                    "<condicional> ::= if ( <expr_relacional> ) <comando> [ else <comando> ]",
                    "'(' após 'if'");
    parser_expr_relacional(p);
    parser_consumir(p,
                    TOKEN_RPAREN,
                    "<condicional> ::= if ( <expr_relacional> ) <comando> [ else <comando> ]",
                    "')' para fechar a condição do 'if'");
    parser_comando(p);

    // Trata o else opcional indicado pelos colchetes [ ] na BNF
    if (!p->erro && p->token_atual.tipo == TOKEN_ELSE) {
        parser_avancar(p);
        parser_comando(p);
    }
}

//
// <iteracao> ::= while ( <expr_relacional> ) <comando>
//              | do <comando> while ( <expr_relacional> ) ;
//
static void parser_iteracao(Parser *p) {
    if (p->erro) return;

    if (p->token_atual.tipo == TOKEN_WHILE) {
        parser_avancar(p);
        parser_consumir(p,
                        TOKEN_LPAREN,
                        "<iteracao> ::= while ( <expr_relacional> ) <comando>",
                        "'(' após 'while'");
        parser_expr_relacional(p);
        parser_consumir(p,
                        TOKEN_RPAREN,
                        "<iteracao> ::= while ( <expr_relacional> ) <comando>",
                        "')' para fechar a condição do 'while'");
        parser_comando(p);

    } else if (p->token_atual.tipo == TOKEN_DO) {
        parser_avancar(p);
        parser_comando(p);
        parser_consumir(p,
                        TOKEN_WHILE,
                        "<iteracao> ::= do <comando> while ( <expr_relacional> ) ;",
                        "'while' após o corpo do 'do'");
        parser_consumir(p,
                        TOKEN_LPAREN,
                        "<iteracao> ::= do <comando> while ( <expr_relacional> ) ;",
                        "'(' após 'while'");
        parser_expr_relacional(p);
        parser_consumir(p,
                        TOKEN_RPAREN,
                        "<iteracao> ::= do <comando> while ( <expr_relacional> ) ;",
                        "')' para fechar a condição do 'do-while'");
        parser_consumir(p,
                        TOKEN_SEMICOLON,
                        "<iteracao> ::= do <comando> while ( <expr_relacional> ) ;",
                        "';' para encerrar o 'do-while'");
    } else {
        parser_erro(p,
                    "<iteracao> ::= while ( <expr_relacional> ) <comando> | do <comando> while ( <expr_relacional> ) ;",
                    "'while' ou 'do'");
    }
}

//
// <expr_relacional> ::= <expr_aritmetica> <op_relacional> <expr_aritmetica>
// <op_relacional>   ::= < | > | <= | >= | == | !=
//
static void parser_expr_relacional(Parser *p) {
    if (p->erro) return;
    parser_expr_aritmetica(p);

    TipoToken t = p->token_atual.tipo;
    // Valida se há um operador relacional válido no meio das subexpressões
    if (t == TOKEN_LT || t == TOKEN_GT || t == TOKEN_LE ||
        t == TOKEN_GE || t == TOKEN_EQ || t == TOKEN_NE) {
        parser_avancar(p);
    } else {
        parser_erro(p,
                    "<expr_relacional> ::= <expr_aritmetica> <op_relacional> <expr_aritmetica>",
                    "operador relacional: '<', '>', '<=', '>=', '==' ou '!='");
        return;
    }

    parser_expr_aritmetica(p);
}

//
// <expr_aritmetica> ::= <termo> { ( + | - ) <termo> }
//
static void parser_expr_aritmetica(Parser *p) {
    if (p->erro) return;
    parser_termo(p);

    // Garante a associatividade à esquerda para somas e subtrações recorrentes
    while (!p->erro &&
           (p->token_atual.tipo == TOKEN_PLUS ||
            p->token_atual.tipo == TOKEN_MINUS)) {
        parser_avancar(p);
        parser_termo(p);
    }
}

//
// <termo> ::= <fator> { ( * | / ) <fator> }
//
static void parser_termo(Parser *p) {
    if (p->erro) return;
    parser_fator(p);

    // Garante a precedência matemática correta tratando multiplicações e divisões primeiro
    while (!p->erro &&
           (p->token_atual.tipo == TOKEN_STAR ||
            p->token_atual.tipo == TOKEN_SLASH)) {
        parser_avancar(p);
        parser_fator(p);
    }
}

//
// <fator> ::= ( <expr_aritmetica> ) | id | <literal>
// <literal> ::= int_const | float_const | char_const
//
static void parser_fator(Parser *p) {
    if (p->erro) return;

    switch (p->token_atual.tipo) {
        case TOKEN_LPAREN:
            parser_avancar(p);
            parser_expr_aritmetica(p);
            parser_consumir(p,
                            TOKEN_RPAREN,
                            "<fator> ::= ( <expr_aritmetica> )",
                            "')' para fechar a expressão entre parênteses");
            break;

        case TOKEN_ID:
        case TOKEN_INT_CONST:
        case TOKEN_FLOAT_CONST:
        case TOKEN_CHAR_CONST:
            parser_avancar(p);
            break;

        default:
            parser_erro(p,
                        "<fator> ::= ( <expr_aritmetica> ) | id | int_const | float_const | char_const",
                        "identificador, constante numérica, constante de caractere ou '('");
            break;
    }
}