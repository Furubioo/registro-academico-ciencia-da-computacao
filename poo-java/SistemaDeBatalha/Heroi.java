package SistemaDeBatalha;

public class Heroi extends Personagem implements Combativel{
    private int experiencia;
    private String[] habilidades;
    private String[] inventario;

    public Heroi(String nome, int vidaMaxima, int vidaAtual, int nivel, int experiencia, String[] habilidades,
            String[] inventario) {
        super(nome, vidaMaxima, vidaAtual, nivel);
        this.experiencia = experiencia;
        this.habilidades = habilidades;
        this.inventario = inventario;
    }

    public int getExperiencia() {
        return experiencia;
    }
    public void setExperiencia(int experiencia) {
        this.experiencia = experiencia;
    }
    public String[] getHabilidades() {
        return habilidades;
    }
    public void setHabilidades(String[] habilidades) {
        this.habilidades = habilidades;
    }
    public String[] getInventario() {
        return inventario;
    }
    public void setInventario(String[] inventario) {
        this.inventario = inventario;
    }

    public void calcularPoderDeAtaque() {
        double poder = 0;
        poder = ((getNivel() * 10) + getExperiencia()) / 100;
        System.out.println("O poder de ataque é "+poder+"!!!");
    }

    public void atacar(int dano) throws AtaqueInvalidoException{
        if (getVidaMaxima() <= 0 || dano < 0) {
            throw new AtaqueInvalidoException("O ataque não é mais possível");
        }
        else {
            dano = dano - esquivar(dano);
            if (dano >= 0) {
                setVidaAtual(getVidaAtual() - dano);
            }
        }
    }

    public int esquivar(int dano) {
        return 10 / 100 * dano;
    }

    public void ganharExperiencia(int experiencia) {
        setExperiencia(getExperiencia() + experiencia);
        if (getExperiencia() == 1000) {
            setNivel(getNivel() + 1);
            System.out.println("Você subiu de nível!!");
            setExperiencia(0);
        }
    }

    public void adicionarHabilidade(String novaHabilidade) {
        for (int i = 0; i < getHabilidades().length; i++) {
            if (getHabilidades()[i] == null) {
                getHabilidades()[i] = novaHabilidade;
                break;
            }
        }
        if (getHabilidades()[getHabilidades().length - 1] != null) {
            System.out.println("O limite de habilidades foi excedido!");
        }
    }


}
