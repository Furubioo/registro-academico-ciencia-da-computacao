#include "../src/lexer/lexer.h"
#include "../src/token/token.h"
#include "minunit.h"
#include <string.h>
 
// -----------------------------------------------------------------------
// TESTES DO LÉXICO (test_lexer.c)
//
// Cada MU_TEST testa um comportamento específico do lexer.
// O padrão é:
//   1. Criar um Lexer com um trecho de código.
//   2. Chamar lexer_proximo_token() uma ou mais vezes.
//   3. Usar mu_assert_int_eq / mu_assert_string_eq para verificar.
// -----------------------------------------------------------------------
 
// ------------------------------------------------------------------
// Testes de palavras-chave
// ------------------------------------------------------------------
 
MU_TEST(test_lexer_palavra_chave_int) {
    Lexer l;
    lexer_inicializar(&l, "int");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_INT, t.tipo);
    mu_assert_string_eq("int", t.lexema);
}
 
MU_TEST(test_lexer_palavra_chave_float) {
    Lexer l;
    lexer_inicializar(&l, "float");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_FLOAT, t.tipo);
}
 
MU_TEST(test_lexer_palavra_chave_char) {
    Lexer l;
    lexer_inicializar(&l, "char");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_CHAR, t.tipo);
}
 
MU_TEST(test_lexer_palavra_chave_if) {
    Lexer l;
    lexer_inicializar(&l, "if");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_IF, t.tipo);
}
 
MU_TEST(test_lexer_palavra_chave_else) {
    Lexer l;
    lexer_inicializar(&l, "else");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_ELSE, t.tipo);
}
 
MU_TEST(test_lexer_palavra_chave_while) {
    Lexer l;
    lexer_inicializar(&l, "while");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_WHILE, t.tipo);
}
 
MU_TEST(test_lexer_palavra_chave_do) {
    Lexer l;
    lexer_inicializar(&l, "do");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_DO, t.tipo);
}
 
MU_TEST(test_lexer_palavra_chave_main) {
    Lexer l;
    lexer_inicializar(&l, "main");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_MAIN, t.tipo);
}
 
// ------------------------------------------------------------------
// Testes de identificadores
// ------------------------------------------------------------------
 
MU_TEST(test_lexer_identificador_simples) {
    Lexer l;
    lexer_inicializar(&l, "variavel");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_ID, t.tipo);
    mu_assert_string_eq("variavel", t.lexema);
}
 
MU_TEST(test_lexer_identificador_com_numero) {
    Lexer l;
    lexer_inicializar(&l, "x1");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_ID, t.tipo);
    mu_assert_string_eq("x1", t.lexema);
}
 
// ------------------------------------------------------------------
// Testes de constantes numéricas
// ------------------------------------------------------------------
 
MU_TEST(test_lexer_constante_inteira) {
    Lexer l;
    lexer_inicializar(&l, "42");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_INT_CONST, t.tipo);
    mu_assert_string_eq("42", t.lexema);
}
 
MU_TEST(test_lexer_constante_float) {
    Lexer l;
    lexer_inicializar(&l, "3.14");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_FLOAT_CONST, t.tipo);
    mu_assert_string_eq("3.14", t.lexema);
}
 
// ------------------------------------------------------------------
// Testes de operadores
// ------------------------------------------------------------------
 
MU_TEST(test_lexer_operador_assign) {
    Lexer l;
    lexer_inicializar(&l, "=");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_ASSIGN, t.tipo);
}
 
MU_TEST(test_lexer_operador_eq) {
    Lexer l;
    lexer_inicializar(&l, "==");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_EQ, t.tipo);
    mu_assert_string_eq("==", t.lexema);
}
 
MU_TEST(test_lexer_operador_ne) {
    Lexer l;
    lexer_inicializar(&l, "!=");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_NE, t.tipo);
}
 
MU_TEST(test_lexer_operador_le) {
    Lexer l;
    lexer_inicializar(&l, "<=");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_LE, t.tipo);
}
 
MU_TEST(test_lexer_operador_ge) {
    Lexer l;
    lexer_inicializar(&l, ">=");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_GE, t.tipo);
}
 
MU_TEST(test_lexer_operador_plus) {
    Lexer l;
    lexer_inicializar(&l, "+");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_PLUS, t.tipo);
}
 
MU_TEST(test_lexer_operador_minus) {
    Lexer l;
    lexer_inicializar(&l, "-");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_MINUS, t.tipo);
}
 
// ------------------------------------------------------------------
// Testes de delimitadores
// ------------------------------------------------------------------
 
MU_TEST(test_lexer_semicolon) {
    Lexer l;
    lexer_inicializar(&l, ";");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_SEMICOLON, t.tipo);
}
 
MU_TEST(test_lexer_comma) {
    Lexer l;
    lexer_inicializar(&l, ",");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_COMMA, t.tipo);
}
 
MU_TEST(test_lexer_lbrace) {
    Lexer l;
    lexer_inicializar(&l, "{");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_LBRACE, t.tipo);
}
 
MU_TEST(test_lexer_rbrace) {
    Lexer l;
    lexer_inicializar(&l, "}");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_RBRACE, t.tipo);
}
 
// ------------------------------------------------------------------
// Testes de controle
// ------------------------------------------------------------------
 
MU_TEST(test_lexer_eof) {
    Lexer l;
    lexer_inicializar(&l, "");
    Token t = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_EOF, t.tipo);
}
 
MU_TEST(test_lexer_pula_espacos) {
    Lexer l;
    lexer_inicializar(&l, "   int");
    Token t = lexer_proximo_token(&l);

    // Deve pular os espaços e reconhecer 'int'.
    mu_assert_int_eq(TOKEN_INT, t.tipo);
}
 
MU_TEST(test_lexer_rastreia_linha) {
    Lexer l;
    lexer_inicializar(&l, "int\nx");

    lexer_proximo_token(&l); // int - linha 1
    Token t = lexer_proximo_token(&l); // x - linha 2

    mu_assert_int_eq(2, t.linha);
}
 
MU_TEST(test_lexer_sequencia_declaracao) {

    // Testa a sequência completa: "int x ;"
    Lexer l;
    lexer_inicializar(&l, "int x;");
 
    Token t1 = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_INT, t1.tipo);
 
    Token t2 = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_ID, t2.tipo);
    mu_assert_string_eq("x", t2.lexema);
 
    Token t3 = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_SEMICOLON, t3.tipo);
 
    Token t4 = lexer_proximo_token(&l);
    mu_assert_int_eq(TOKEN_EOF, t4.tipo);
}
 
// ------------------------------------------------------------------
// Suite de testes
// ------------------------------------------------------------------
 
MU_TEST_SUITE(suite_lexer) {
    MU_RUN_TEST(test_lexer_palavra_chave_int);
    MU_RUN_TEST(test_lexer_palavra_chave_float);
    MU_RUN_TEST(test_lexer_palavra_chave_char);
    MU_RUN_TEST(test_lexer_palavra_chave_if);
    MU_RUN_TEST(test_lexer_palavra_chave_else);
    MU_RUN_TEST(test_lexer_palavra_chave_while);
    MU_RUN_TEST(test_lexer_palavra_chave_do);
    MU_RUN_TEST(test_lexer_palavra_chave_main);
    MU_RUN_TEST(test_lexer_identificador_simples);
    MU_RUN_TEST(test_lexer_identificador_com_numero);
    MU_RUN_TEST(test_lexer_constante_inteira);
    MU_RUN_TEST(test_lexer_constante_float);
    MU_RUN_TEST(test_lexer_operador_assign);
    MU_RUN_TEST(test_lexer_operador_eq);
    MU_RUN_TEST(test_lexer_operador_ne);
    MU_RUN_TEST(test_lexer_operador_le);
    MU_RUN_TEST(test_lexer_operador_ge);
    MU_RUN_TEST(test_lexer_operador_plus);
    MU_RUN_TEST(test_lexer_operador_minus);
    MU_RUN_TEST(test_lexer_semicolon);
    MU_RUN_TEST(test_lexer_comma);
    MU_RUN_TEST(test_lexer_lbrace);
    MU_RUN_TEST(test_lexer_rbrace);
    MU_RUN_TEST(test_lexer_eof);
    MU_RUN_TEST(test_lexer_pula_espacos);
    MU_RUN_TEST(test_lexer_rastreia_linha);
    MU_RUN_TEST(test_lexer_sequencia_declaracao);
}
 
int main(void) {
    MU_RUN_SUITE(suite_lexer);
    MU_REPORT();
    return MU_EXIT_CODE;
}