package Exercicio4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Informe a distância da viagem(km): ");
        int dist = sc.nextInt();
        System.out.println("Informe o tempo da viagem(h): ");
        int tempo = sc.nextInt();

        Viagem v1 = new Viagem(dist, tempo);

        Velocidade v = new Velocidade(v1);

        System.out.println("Velocidade média da viagem: "+v.velMedia()+"km/h");

        sc.close();
    }
}
