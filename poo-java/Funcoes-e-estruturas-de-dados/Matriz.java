package ExercicioRevisao;

import java.util.Scanner;

public class Matriz {
    public static void main(String[] args) {
        int[][] mat = new int[3][3];

        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.println("Digite o elemento ["+ i +"]["+ j +"]");
                mat[i][j] = scanner.nextInt();

            }
        }

        System.out.println("Matriz transposta: ");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(mat[j][i]);
            }
            System.out.print("\n");
        }

        scanner.close();

    }
}
