#include <stdio.h>
#include "thread.h"
#include "../conta/conta.h"
#include "../peterson/peterson.h"

void thread_P0(void *arg) {
    (void)arg;
    enter(0);       // Pede para entrar
    depositar(50);  // Faz o depósito fixo de 50
    leave(0);       // Sai da seção crítica
}

void thread_P1(void *arg) {
    (void)arg;
    enter(1);       // Pede para entrar
    depositar(1000);// Faz o depósito fixo de 1000
    leave(1);       // Sai da seção crítica
}
