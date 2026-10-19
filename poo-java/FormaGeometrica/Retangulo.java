package FormaGeometrica;

public class Retangulo extends Forma{
    private double largura;
    private double altura;

    public Retangulo(String cor, double largura, double altura) {
        super(cor);
        this.altura = altura;
        this.largura = largura;
    }

    public double getLargura() {
        return largura;
    }

    public void setLargura(double largura) {
        this.largura = largura;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }
    
    @Override
    public double calcularArea() {
        return getLargura() * getAltura();
    }

    @Override
    public double calcularPerimetro() {
        return (2 * getAltura()) + (2 * getLargura());
    }
}
