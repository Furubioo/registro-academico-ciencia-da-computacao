package Simulado1gq;

public class Aviao extends Veiculo{

    private boolean voando;

    public Aviao(String marca, boolean estado, double tanque, double consumo, double velocidadeAtual, double litragemDoTanque, double velocidadeMaxima, boolean voando) {
        super(marca, estado, tanque, consumo, velocidadeAtual, litragemDoTanque, velocidadeMaxima);
        this.voando = voando;
    }

    public boolean getVoando() {
        return voando;
    }

    public void setVoando(boolean voando) {
        this.voando = voando;
    }
    
    public void Voar() {
        if (getVelocidadeAtual() >= 200) {
            System.out.println("Avião apto para voar e pronto para exceder velocidade máxima");
        }
        setVoando(true);
    }

    public void Acelerar() {
        if (getVoando() == true) {
            if (getVelocidadeAtual() < getVelocidadeMaxima()) {
                setVelocidadeAtual(getVelocidadeAtual() + 20);
            }
        }
    }   

    public void Frear() {
        if (getVoando() == true) {
            if (getVelocidadeAtual() > 0) {
                setVelocidadeAtual(getVelocidadeAtual() - 10);
            }
        }
        if (getVelocidadeAtual() < 200) {
            System.out.println("O avião está pousando.");
            setVoando(false);
        }
    }

    public void Chavear() {
        if (getEstado() == false) {
            setEstado(true);
        }
        else if (getVelocidadeAtual() == 0) {
            setEstado(false);
        }
    }

    public void Corrida(double distancia) {
        double distanciaConsumo;
        int cont = 0;
        distanciaConsumo = getConsumo() * cont;

        while (distanciaConsumo < distancia && getTanque() > 0) {
            setTanque(getTanque() - 1);
            cont++;
            distanciaConsumo = getConsumo() * cont;
        }
        if (distanciaConsumo >= distancia) {
            System.out.println("Distância percorrida!");
            setTanque(getTanque() - cont);
        }
        else if (distanciaConsumo < distancia){
            System.out.println("Distância maior que a litragem do avião. Haverá pouso de emergência.");
        }
    }
}    
