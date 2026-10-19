package ExercicioRevisao;

import java.util.Scanner;

public class funcao2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Informe um valor: ");
        int valor = scanner.nextInt();

        boolean resultado = verificacao(valor);

        if (resultado == true) {
            System.out.println("O número é primo.");
        }
        else {
            System.out.println("O número não é primo.");
        }

        scanner.close();
    }

    public static boolean verificacao(int num) {
        int cont = 0;

        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                cont++;
            }
        }
        if (cont == 2) {
            return true;
        }
        else {
            return false;
        }
        
    }



}
