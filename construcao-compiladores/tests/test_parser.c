#include "../src/compiler/compilador.h"
#include "minunit.h"
#include <string.h>
 
// -----------------------------------------------------------------------
// TESTES DO PARSER (test_parser.c)
//
// Testamos o parser por meio da função compilador_analisar(),
// que é a interface pública do sistema. Cada teste fornece um trecho
// de código e verifica se o resultado é sucesso ou falha.
// -----------------------------------------------------------------------
 
// Macro auxiliar: analisa o código e extrai o campo sucesso.
#define ANALISAR(codigo) compilador_analisar(codigo).sucesso
 
// ------------------------------------------------------------------
// Programas válidos — devem retornar sucesso (1)
// ------------------------------------------------------------------
 
MU_TEST(test_parser_programa_minimo) {
    // Programa mínimo válido: só a estrutura principal vazia.
    const char *codigo = "int main() { }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_declaracao_int) {
    const char *codigo = "int main() { int x; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_declaracao_multiplas_variaveis) {
    // int x, y; — lista de identificadores separados por vírgula.
    const char *codigo = "int main() { int x, y; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_declaracao_float) {
    const char *codigo = "int main() { float media; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_declaracao_char) {
    const char *codigo = "int main() { char letra; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_atribuicao_simples) {
    const char *codigo = "int main() { int x; x = 10; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_atribuicao_expressao) {
    const char *codigo = "int main() { int x; int y; x = y + 5; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_atribuicao_float_const) {
    const char *codigo = "int main() { float m; m = 2.0; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_if_sem_else) {
    const char *codigo =
        "int main() { int x; int y; if (x > y) x = 1; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_if_com_else) {
    const char *codigo =
        "int main() { int x; int y; if (x > y) x = 1; else y = 2; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_if_com_bloco) {
    const char *codigo =
        "int main() { int x; int y;"
        "if (x > y) { x = x - 1; } else { y = y + 1; } }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_while) {
    const char *codigo =
        "int main() { int x; while (x < 20) x = x + 1; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_do_while) {
    const char *codigo =
        "int main() { int y; do y = y - 1; while (y > 0); }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_programa_completo) {
    // O input.txt de exemplo completo deve ser aceito.
    const char *codigo =
        "int main() {\n"
        "    int x, y;\n"
        "    float media;\n"
        "    char letra;\n"
        "    x = 10;\n"
        "    y = x + 5;\n"
        "    media = y / 2.0;\n"
        "    if (x > y) {\n"
        "        x = x - 1;\n"
        "    } else {\n"
        "        y = y + 1;\n"
        "    }\n"
        "    while (x < 20) {\n"
        "        x = x + 1;\n"
        "    }\n"
        "    do {\n"
        "        y = y - 1;\n"
        "    } while (y > 0);\n"
        "}\n";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_expressao_parenteses) {
    // Parênteses em expressão aritmética.
    const char *codigo = "int main() { int x; x = (1 + 2); }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_operador_le) {
    const char *codigo = "int main() { int x; while (x <= 10) x = x + 1; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_operador_eq) {
    const char *codigo = "int main() { int x; int y; if (x == y) x = 0; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
MU_TEST(test_parser_operador_ne) {
    const char *codigo = "int main() { int x; int y; if (x != y) x = 0; }";
    mu_assert_int_eq(1, ANALISAR(codigo));
}
 
// ------------------------------------------------------------------
// Programas inválidos — devem retornar falha (0)
// ------------------------------------------------------------------
 
MU_TEST(test_parser_erro_sem_main) {
    // Faltou a palavra 'main'.
    const char *codigo = "int () { }";
    mu_assert_int_eq(0, ANALISAR(codigo));
}
 
MU_TEST(test_parser_erro_sem_chave_abre) {
    // Faltou '{' para abrir o bloco.
    const char *codigo = "int main() int x; }";
    mu_assert_int_eq(0, ANALISAR(codigo));
}
 
MU_TEST(test_parser_erro_sem_chave_fecha) {
    // Faltou '}' para fechar o bloco.
    const char *codigo = "int main() { int x;";
    mu_assert_int_eq(0, ANALISAR(codigo));
}
 
MU_TEST(test_parser_erro_sem_ponto_virgula) {
    // Faltou ';' após a declaração.
    const char *codigo = "int main() { int x }";
    mu_assert_int_eq(0, ANALISAR(codigo));
}
 
MU_TEST(test_parser_erro_atribuicao_sem_igual) {
    // Faltou '=' na atribuição.
    const char *codigo = "int main() { int x; x 10; }";
    mu_assert_int_eq(0, ANALISAR(codigo));
}
 
MU_TEST(test_parser_erro_if_sem_parenteses) {
    // Faltou '(' após if.
    const char *codigo = "int main() { int x; int y; if x > y x = 1; }";
    mu_assert_int_eq(0, ANALISAR(codigo));
}
 
MU_TEST(test_parser_erro_do_while_sem_ponto_virgula) {
    // Faltou ';' após do-while.
    const char *codigo = "int main() { int y; do y = 1; while (y > 0) }";
    mu_assert_int_eq(0, ANALISAR(codigo));
}
 
MU_TEST(test_parser_erro_tokens_apos_programa) {
    // Sobra código depois do programa.
    const char *codigo = "int main() { } int x;";
    mu_assert_int_eq(0, ANALISAR(codigo));
}
 
// ------------------------------------------------------------------
// Suite de testes
// ------------------------------------------------------------------
 
MU_TEST_SUITE(suite_parser) {
    // Válidos
    MU_RUN_TEST(test_parser_programa_minimo);
    MU_RUN_TEST(test_parser_declaracao_int);
    MU_RUN_TEST(test_parser_declaracao_multiplas_variaveis);
    MU_RUN_TEST(test_parser_declaracao_float);
    MU_RUN_TEST(test_parser_declaracao_char);
    MU_RUN_TEST(test_parser_atribuicao_simples);
    MU_RUN_TEST(test_parser_atribuicao_expressao);
    MU_RUN_TEST(test_parser_atribuicao_float_const);
    MU_RUN_TEST(test_parser_if_sem_else);
    MU_RUN_TEST(test_parser_if_com_else);
    MU_RUN_TEST(test_parser_if_com_bloco);
    MU_RUN_TEST(test_parser_while);
    MU_RUN_TEST(test_parser_do_while);
    MU_RUN_TEST(test_parser_programa_completo);
    MU_RUN_TEST(test_parser_expressao_parenteses);
    MU_RUN_TEST(test_parser_operador_le);
    MU_RUN_TEST(test_parser_operador_eq);
    MU_RUN_TEST(test_parser_operador_ne);

    // Inválidos
    MU_RUN_TEST(test_parser_erro_sem_main);
    MU_RUN_TEST(test_parser_erro_sem_chave_abre);
    MU_RUN_TEST(test_parser_erro_sem_chave_fecha);
    MU_RUN_TEST(test_parser_erro_sem_ponto_virgula);
    MU_RUN_TEST(test_parser_erro_atribuicao_sem_igual);
    MU_RUN_TEST(test_parser_erro_if_sem_parenteses);
    MU_RUN_TEST(test_parser_erro_do_while_sem_ponto_virgula);
    MU_RUN_TEST(test_parser_erro_tokens_apos_programa);
}
 
int main(void) {
    MU_RUN_SUITE(suite_parser);
    MU_REPORT();
    return MU_EXIT_CODE;
}