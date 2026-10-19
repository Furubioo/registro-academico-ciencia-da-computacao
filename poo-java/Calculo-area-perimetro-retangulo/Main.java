package ExercicioPrimeiro;


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Informe o valor do lado 1: ");
        double l1 = sc.nextDouble();
        System.out.println("Informe o valor do lado 2: ");
        double l2 = sc.nextDouble();
        System.out.println("Informe o valor do lado 3(Largura): ");
        double l3 = sc.nextDouble();
        System.out.println("Informe o valor do lado 4(Altura): ");
        double l4 = sc.nextDouble();

        Retangulo r = new Retangulo(l4,l3);

        Calculos c = new Calculos(l1, l2, l3, l4, r);

        System.out.println("Valor da area: "+c.Area());
        System.out.println("Valor do perímetro: "+c.Perimetro());

        sc.close();
        
    }
}
