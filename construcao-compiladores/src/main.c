#include "compilador.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  char *caminho = "examples/input.txt";
  if (argc > 1) {
    caminho = argv[1];
  }

  printf("Arquivo: %s\n\n", caminho);

  char *codigo = compilador_ler_arquivo(caminho);
  if (!codigo) {
    return 1;
  }

  ResultadoAnalise resultado = compilador_analisar(codigo);

  if (resultado.sucesso) {
    printf("[SUCESSO] %s\n", resultado.mensagem);
  } else {
    printf("[ERRO] %s\n", resultado.mensagem);
    if (resultado.linha_erro > 0) {
      printf("         Linha: %d\n", resultado.linha_erro);
    }
  }

  free(codigo);

  return resultado.sucesso ? 0 : 1;
}
