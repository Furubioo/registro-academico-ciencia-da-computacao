#include "token.h"

char *token_tipo_para_string(TipoToken tipo) {
  switch (tipo) {
  case TOKEN_INT:
    return "TOKEN_INT";
  case TOKEN_FLOAT:
    return "TOKEN_FLOAT";
  case TOKEN_CHAR:
    return "TOKEN_CHAR";
  case TOKEN_IF:
    return "TOKEN_IF";
  case TOKEN_ELSE:
    return "TOKEN_ELSE";
  case TOKEN_WHILE:
    return "TOKEN_WHILE";
  case TOKEN_DO:
    return "TOKEN_DO";
  case TOKEN_MAIN:
    return "TOKEN_MAIN";

  case TOKEN_ID:
    return "TOKEN_ID";
  case TOKEN_INT_CONST:
    return "TOKEN_INT_CONST";
  case TOKEN_FLOAT_CONST:
    return "TOKEN_FLOAT_CONST";
  case TOKEN_CHAR_CONST:
    return "TOKEN_CHAR_CONST";
  case TOKEN_PLUS:
    return "TOKEN_PLUS";
  case TOKEN_MINUS:
    return "TOKEN_MINUS";
  case TOKEN_STAR:
    return "TOKEN_STAR";
  case TOKEN_SLASH:
    return "TOKEN_SLASH";
  case TOKEN_ASSIGN:
    return "TOKEN_ASSIGN";
  case TOKEN_LT:
    return "TOKEN_LT";
  case TOKEN_GT:
    return "TOKEN_GT";
  case TOKEN_LE:
    return "TOKEN_LE";
  case TOKEN_GE:
    return "TOKEN_GE";
  case TOKEN_EQ:
    return "TOKEN_EQ";
  case TOKEN_NE:
    return "TOKEN_NE";
  case TOKEN_LPAREN:
    return "TOKEN_LPAREN";
  case TOKEN_RPAREN:
    return "TOKEN_RPAREN";
  case TOKEN_LBRACE:
    return "TOKEN_LBRACE";
  case TOKEN_RBRACE:
    return "TOKEN_RBRACE";
  case TOKEN_SEMICOLON:
    return "TOKEN_SEMICOLON";
  case TOKEN_COMMA:
    return "TOKEN_COMMA";
  case TOKEN_EOF:
    return "TOKEN_EOF";
  case TOKEN_ERRO:
    return "TOKEN_ERRO";

  default:
    return "TOKEN_DESCONHECIDO";
  }
}
