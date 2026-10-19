package ExercicioRevisao;

import java.util.Scanner;

public class funcao1 {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int[] vet = new int[9];
        
        for (int i = 0; i < 9; i++) {
            System.out.print("Digite o valor ["+i+"]: ");
            vet[i] = scanner.nextInt(); 
        }

        menornumero(vet);

        scanner.close();
    }

    public static void menornumero(int vet[]) {
        int aux = vet[0];
        for (int i = 0; i < 9; i++) {
            if (vet[i] < aux) {
                aux = vet[i];
            }
        }
        System.out.println("O menor número digitado foi: "+aux+"");
    } 
}
