package Exercicio6;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Informe o capital inicial(R$): ");
        double capital = sc.nextDouble();
        System.out.println("Informe a taxa de juros compostos(em %): ");
        double juros = sc.nextDouble();
        System.out.println("Informe o tempo(em anos)");
        double tempo = sc.nextDouble();

        Investimento i = new Investimento(capital, juros, tempo);
        Juros j = new Juros(i);

        System.out.println("Valor do montante após os juros: R$"+j.calcMont());

        sc.close();

    }
}
