#include "conta.h"

int saldo = 0; // Variável global que as duas threads vão alterar

void depositar(int valor) {
    // Esta linha é a "Seção Crítica". 
    // O Peterson garante que apenas uma thread mexa aqui por vez[cite: 2].
    saldo += valor;
}
