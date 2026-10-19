package ExercicioRevisao;

import java.util.Scanner;

public class funcao4 {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite um número inteiro: ");
        int num = scanner.nextInt();

        // Solução Iterativa
        System.out.println("Solução Iterativa:");
        int valor = fatorial(num);
        System.out.println("Valor do fatorial: " +valor);

        // Solução recursiva
        System.out.println("Solução recursiva: ");
        int valor1 = fatorial1(num);
        System.out.println("Valor do fatorial: " +valor1);

        scanner.close();


    }


    public static int fatorial(int n) {

        int mult = 1;

        for (int i = 1; i <= n; i++) {
            mult = mult * i;
        }
        return mult;

    }

    public static int fatorial1(int n) {


        if (n == 1) {
            return 1;
        }

        return n * fatorial1(n - 1);


    }

}














