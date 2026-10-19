package FormaGeometrica;

public class Main {
    public static void main(String[] args) {
        Forma[] vet = new Forma[3];
        
        Circulo c1 = new Circulo("Azul", 3.22);
        Retangulo r1 = new Retangulo("Verde", 2, 5);
        Triangulo t1 = new Triangulo("Vermelho", 5.60, 3.20, 2.80, 2.60, 5.60);

        vet[0] = c1;
        vet[1] = r1;
        vet[2] = t1;

        for (int i = 0; i < 3; i++) {
            vet[i].exibirInfo();
            System.out.println();
        }

    }
}
