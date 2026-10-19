package Exercicio4;

public class Velocidade {
    
    Viagem v1;

    public Velocidade(Viagem v1) {
        this.v1 = v1;
    }

    public int velMedia() {
        return v1.distancia / v1.tempo;
    }


}
