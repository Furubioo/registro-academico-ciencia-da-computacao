package Exercicio7;

public class Triangulo {
    Ponto p1, p2, p3;

    public Triangulo(Ponto p1, Ponto p2, Ponto p3) {
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    public double Lado1() {
        return Math.sqrt((Math.pow((p2.x - p1.x), 2) + Math.pow((p2.y - p1.y), 2)));
    }

    public double Lado2() {
        return Math.sqrt((Math.pow((p3.x - p1.x), 2) + Math.pow((p3.y - p1.y), 2)));
    }

    public double Lado3() {
        return Math.sqrt((Math.pow((p2.x - p3.x), 2) + Math.pow((p2.y - p3.y), 2)));
    }

    public double CalcPerim() {
        return Lado1() + Lado2() + Lado3();
    }




}
