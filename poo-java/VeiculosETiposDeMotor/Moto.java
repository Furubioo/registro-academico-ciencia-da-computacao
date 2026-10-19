package VeiculosETiposDeMotor;

public class Moto extends Veiculo{
    private double consumoKmporL;

    public Moto(String marca, String modelo, int velocidadeMaxima, double consumoKmporL) {
        super(marca, modelo, velocidadeMaxima);
        this.consumoKmporL = consumoKmporL;
    }
    
    public double getConsumoKmporL() {
        return consumoKmporL;
    }

    public void setConsumoKmporL(double consumoKmporL) {
        this.consumoKmporL = consumoKmporL;
    }
    
    @Override
    public void mover() {
        System.out.println("A moto está se locomovendo.");
    }

    public double calcularAutonomia(double litros) {
        return getConsumoKmporL() * litros;
    }
}
