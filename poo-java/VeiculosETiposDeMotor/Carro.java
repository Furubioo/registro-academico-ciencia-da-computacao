package VeiculosETiposDeMotor;

public class Carro extends Veiculo{
    private double consumoKmporL;

    public Carro(String marca, String modelo, int velocidadeMaxima, double consumoKmporL) {
        super(marca, modelo, velocidadeMaxima);
        this.consumoKmporL = consumoKmporL;
    }

    public double getConsumoKmL() {
        return consumoKmporL;
    }

    public void setConsumoKmL(double consumoKmL) {
        this.consumoKmporL = consumoKmL;
    }

    @Override
    public void mover() {
        System.out.println("O carro está se locomovendo.");
    }

    @Override
    public double calcularAutonomia(double litros) {
        
        return getConsumoKmL() * litros;
    }

}
