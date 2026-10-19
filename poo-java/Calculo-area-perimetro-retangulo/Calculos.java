package ExercicioPrimeiro;

public class Calculos {
    double l1;
    double l2;
    double l3;
    double l4;

    Retangulo r;

    public Calculos(double l1, double l2, double l3, double l4, Retangulo r) {
        this.l1 = l1;
        this.l2 = l2;
        this.l3 = l3;
        this.l4 = l4;
        this.r = r;

    }

    public double Area() {
     
        double area;

        area = r.altura * r.largura;
        
        return area;
    }

    public double Perimetro() {

        double perimetro;

        perimetro = l1 + l2 + l3 + l4;

        return perimetro;
    }



}
