package Exercicio3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Informe o valor em Celsius: ");
        double c = sc.nextDouble();

        Temperatura c1 = new Temperatura(c);

        Conversao cvs = new Conversao(c1);

        System.out.println("Celsius para Fahrenheit: "+cvs.paraFahrenheit());
        System.out.println("Celsius para Kelvin: "+cvs.paraKelvin());
    
        sc.close();
    }
}
