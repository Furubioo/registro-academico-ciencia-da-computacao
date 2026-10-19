package SistemaRPG;

public abstract class Personagem {
    private double pontosDeVida;
    private double ataque;
    private double defesa;

    public Personagem(double pontosDeVida, double ataque, double defesa) {
        this.pontosDeVida = pontosDeVida;
        this.ataque = ataque;
        this.defesa = defesa;
    }

    public double getPontosDeVida() {
        return pontosDeVida;
    }
    public void setPontosDeVida(double pontosDeVida) {
        this.pontosDeVida = pontosDeVida;
    }
    public double getAtaque() {
        return ataque;
    }
    public void setAtaque(double ataque) {
        this.ataque = ataque;
    }
    public double getDefesa() {
        return defesa;
    }
    public void setDefesa(double defesa) {
        this.defesa = defesa;
    }

    abstract double atacar();
    abstract void defender(double dano) throws NoDamageException;

}
