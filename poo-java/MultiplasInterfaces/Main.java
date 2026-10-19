package MultiplasInterfaces;

public class Main {
    public static void main(String[] args) {
        Pato p = new Pato("Donald", 4, 40);
        Sapo s = new Sapo("Clovis", 0.2, 12);
        Tubarao t = new Tubarao("Bruce", 100, 160);

        Andavel a, a1;
        Nadavel n, n1, n2;
        Voavel v;

        //Sapo
        a = s;
        n = s;
        
        //Pato
        a1 = p;
        n1 = p;
        v = p;

        //Tubarão
        n2 = t;

        a.andar();
        n.nadar();

        a1.andar();
        n1.nadar();
        v.voar();

        n2.nadar();


    }
}
