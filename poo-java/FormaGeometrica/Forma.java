package FormaGeometrica;

public abstract class Forma {
    private String cor;

    public Forma(String cor) {
        this.cor = cor;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public abstract double calcularArea();
    public abstract double calcularPerimetro();

    public void exibirInfo() {
        System.out.println("Cor da forma: "+ getCor());
        System.out.println("Area: "+calcularArea());
        System.out.println("Perímetro: "+calcularPerimetro());
    } 
}
