package Exercicio5;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Informe o seu peso: ");
        double peso = sc.nextDouble();
        System.out.println("Informe a sua altura: ");
        double altura = sc.nextDouble();

        Pessoa p = new Pessoa(peso, altura);
        Imc p1 = new Imc(p);

        if (p1.calcImc() < 18.5) {
            System.out.println("Abaixo do peso.");
        }
        else if(p1.calcImc() >= 18.5 && p1.calcImc() <= 24.99) {
            System.out.println("Peso normal(Eutrófico)");
        }
        else if(p1.calcImc() >= 25 && p1.calcImc() <= 29.99) {
            System.out.println("Sobrepeso.");
        }
        else if(p1.calcImc() >= 30 && p1.calcImc() <= 34.99) {
            System.out.println("Obesidade grau 1");
        }
        else if(p1.calcImc() >= 35 && p1.calcImc() <= 39.99) {
            System.out.println("Obesidade grau 2");
        }
        else if(p1.calcImc() >= 40) {
            System.out.println("Obesidade grau 3(mórbida)");
        }

        sc.close();

    }
}

