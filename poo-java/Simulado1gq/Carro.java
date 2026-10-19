package Simulado1gq;

public class Carro extends Veiculo{

    private String placa;

    public Carro(String marca, boolean estado, double tanque, double consumo, double velocidadeAtual, double litragemDoTanque, double velocidadeMaxima, String placa) {
        super(marca, estado, tanque, consumo, velocidadeAtual, litragemDoTanque, velocidadeMaxima);
        this.placa = placa;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public void Acelerar() {
        if (getVelocidadeAtual() < getVelocidadeMaxima()) {
            setVelocidadeAtual(getVelocidadeAtual() + 10);
        }
    }

    public void Frear() {
        if (getVelocidadeAtual() > 0) {
            setVelocidadeAtual(getVelocidadeAtual() - 5);
        }
    }

    public void Chavear() {
        while (getVelocidadeAtual() > 0) {
            Frear();
            if (getVelocidadeAtual() < 0) {
                setVelocidadeAtual(0);
            }
        }
        
        if (getEstado() == false) {
            setEstado(true);
        }
        else {
            setEstado(false);
        }
    }

    public void Corrida(double distancia, double gasolinaEspecial) {
        double distanciaConsumo;
        distanciaConsumo = (getConsumo() + 0.5 * getConsumo()) * gasolinaEspecial;

        if (distanciaConsumo > distancia) {
            System.out.println("Distância percorrida!");
        }
        else if (distanciaConsumo < distancia) {
            int cont = 0;
            while (distanciaConsumo < distancia && getTanque() > 0) {
                setTanque(getTanque() - 1);
                cont++;
                distanciaConsumo = getConsumo() * cont;
            }
            if (distanciaConsumo >= distancia) {
                setTanque(getTanque() - cont);
                System.out.println("Distância percorrida!");
            }
        }
        else if (distanciaConsumo < distancia){
            setVelocidadeAtual(0);
            setTanque(0);
            distancia -= distanciaConsumo;
            System.out.println("Distância restante: " +distancia+ "km.");
        }
    }

}
