package VeiculosETiposDeMotor;

public class Caminhao extends Veiculo{
    private double consumoKmporL;

    public Caminhao(String marca, String modelo, int velocidadeMaxima, double consumoKmporL) {
        super(marca, modelo, velocidadeMaxima);
        this.consumoKmporL = consumoKmporL;
    }

    public double getConsumoKmporL() {
        return consumoKmporL;
    }

    public void setConsumoKmporL(double consumoKmporL) {
        this.consumoKmporL = consumoKmporL;
    }

    public void mover() {
        System.out.println("O caminhão está se locomovendo.");
    }

    public double calcularAutonomia(double litros) {
        return getConsumoKmporL() * litros;
    }

    
}
