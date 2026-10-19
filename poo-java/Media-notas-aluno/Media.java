package Exercicio2;

public class Media {
    Aluno a;

    public Media(Aluno a) {
        this.a = a;
    }

    public double calcMedia() {
        return (a.n1 + a.n2 + a.n3) / 3;
    }
}
