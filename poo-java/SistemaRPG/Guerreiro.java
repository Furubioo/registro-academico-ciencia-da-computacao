package SistemaRPG;

public class Guerreiro extends Personagem implements Acoes{
    private boolean estarVivo;
    
    public Guerreiro(double pontosDeVida, double ataque, double defesa, boolean estarVivo) {
        super(pontosDeVida, ataque, defesa);
        this.estarVivo = estarVivo;
    }

    public boolean getEstarVivo() {
        return estarVivo;
    }

    public void setEstarVivo(boolean estarVivo) {
        this.estarVivo = estarVivo;
    }

    public double atacar() {
        return getAtaque() * 1.5;
    }

    public void defender(double dano) throws NoDamageException{
        if (getAtaque() > getDefesa()) {
            setPontosDeVida(getPontosDeVida() - dano);
        }
        else {
            throw new NoDamageException(getAtaque(), getDefesa());
        }
        if (getPontosDeVida() <= 0) {
            setEstarVivo(false);
        }
    }

    
}
