package Exercicio5;

public class Imc {
    Pessoa p;

    public Imc(Pessoa p) {
        this.p = p;
    }

    public double calcImc() {
        return (p.peso / (p.altura * p.altura));
    }
}
