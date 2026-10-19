package Exercicio3;

public class Conversao {
    
    Temperatura c1;

    public Conversao(Temperatura c1) {
        this.c1 = c1;
    }

    public double paraFahrenheit() {
        return c1.celsius * 1.8 + 32;
    }

    public double paraKelvin() {
        return c1.celsius + 273.15;
    }

}
