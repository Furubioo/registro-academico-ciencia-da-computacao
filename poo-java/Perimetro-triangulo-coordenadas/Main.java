package Exercicio7;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Informe o valor de x1: ");
        double x1 = sc.nextDouble();
        System.out.println("Informe o valor de y1: ");
        double y1 = sc.nextDouble();
        System.out.println("Informe o valor de x2: ");
        double x2 = sc.nextDouble();
        System.out.println("Informe o valor de y2: ");
        double y2 = sc.nextDouble();
        System.out.println("Informe o valor de x3: ");
        double x3 = sc.nextDouble();
        System.out.println("Informe o valor de y3: ");
        double y3 = sc.nextDouble();


        Ponto pp1 = new Ponto(x1,y1);
        Ponto pp2 = new Ponto(x2,y2);
        Ponto pp3 = new Ponto(x3,y3);

        Triangulo t = new Triangulo(pp1,pp2,pp3);

        System.out.println("Distância do lado 1: "+t.Lado1());
        System.out.println("Distância do lado 2: "+t.Lado2());
        System.out.println("Distância do lado 3: "+t.Lado3());
        System.out.println("Perímetro do triângulo: "+t.CalcPerim());

        sc.close();

    }
}
