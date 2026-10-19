package ExercicioRevisao;

import java.util.Scanner;

public class funcao3 {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite o primeiro número(limite inferior): ");
        int num1 = scanner.nextInt();
        System.out.println("Digite o segundo número(limite superior): ");
        int num2 = scanner.nextInt();

        intervalo(num1,num2);

        scanner.close();

    }

    public static void intervalo(int num1, int num2) {

        System.out.println("Números primos entre o intervalo: ");

        int cont = 0;
        

        for (int i = num1+1; i < num2; i++) {
            for (int j = 1; j <= i; j++) {
                if (i % j == 0) {
                    cont++;
                }
            }
            if (cont == 2) {
                System.out.println(i);
            }
            cont = 0;

        }   

    }
}
