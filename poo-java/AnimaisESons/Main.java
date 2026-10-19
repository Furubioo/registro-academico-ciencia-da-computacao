package AnimaisESons;

public class Main {
    public static void main(String[] args) {
        Cachorro c1 = new Cachorro("Pepsi", "Canis lupus", 10, "Carne corso");
        Passaro p1 = new Passaro("Cleitinho", "Amazona amazonica", 24, 35);
        Peixe p2 = new Peixe("Beto", "Betta splendens", 2, "Água doce");

        Animal[] vet = new Animal[3];
        vet[0] = c1;
        vet[1] = p1;
        vet[2] = p2;

        for (int i = 0; i < 3; i++) {
            vet[i].emitirSom();
            vet[i].mover();
            System.out.println();
        }

        c1.exibirInfo();
        p1.exibirInfo();
        p2.exibirInfo();
    }
}
