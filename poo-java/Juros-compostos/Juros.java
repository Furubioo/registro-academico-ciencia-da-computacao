package Exercicio6;

public class Juros {
    
    Investimento i;

    public Juros(Investimento i) {
        this.i = i;
    }

    public double calcMont() {
        return i.capital * Math.pow(1 + (i.juros/100), i.tempo);
    }

}
