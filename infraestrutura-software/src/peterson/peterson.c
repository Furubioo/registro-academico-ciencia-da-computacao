#include "peterson.h"
#include <stdbool.h>
#include <sched.h> 

int turn = 0;           
bool wants[2] = {false, false}; 

void enter(int task) {
    int other = 1 - task; 

    // 1. Avisa que quer entrar e dá a vez para o outro
    __atomic_store_n(&wants[task], true, __ATOMIC_SEQ_CST);
    __atomic_store_n(&turn, other, __ATOMIC_SEQ_CST);

    // 2. Espera se o outro quiser entrar E for a vez do outro
    while (__atomic_load_n(&wants[other], __ATOMIC_SEQ_CST) &&
           __atomic_load_n(&turn, __ATOMIC_SEQ_CST) == other) {
        
        // Cede o processador imediatamente para a outra thread trabalhar
        sched_yield(); 
    }
}

void leave(int task) {
    // 3. Avisa que terminou e saiu da seção crítica
    __atomic_store_n(&wants[task], false, __ATOMIC_SEQ_CST);
}
