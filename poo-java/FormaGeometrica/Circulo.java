package FormaGeometrica;
import java.lang.Math;

public class Circulo extends Forma{
    private double raio;

    public Circulo(String cor, double raio) {
        super(cor);
        this.raio = raio;
    }

    public double getRaio() {
        return raio;
    }

    public void setRaio(double raio) {
        this.raio = raio;
    }

    @Override
    public double calcularArea() {
        double area;
        area = 3.1415 * Math.pow(getRaio(), 2);
        return area;
    }

    @Override
    public double calcularPerimetro() {
        double perimetro;
        perimetro = 2 * 3.1415 * getRaio();
        return perimetro;
    }
}
