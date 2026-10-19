package Exercicio2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Informe a nota 1: ");
        double n1 = sc.nextDouble();
        System.out.print("Informe a nota 2: ");
        double n2 = sc.nextDouble();
        System.out.print("Informe a nota 3: ");
        double n3 = sc.nextDouble();

        Aluno a = new Aluno(n1,n2,n3);

        Media m = new Media(a);

        if (m.calcMedia() >= 6) {
            System.out.println("Aprovado!");
        }
        else {
            System.out.println("Reprovado!");
        }

        sc.close();

    }
}
