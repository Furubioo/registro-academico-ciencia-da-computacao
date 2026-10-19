package RpgPorTurnos;

public class Heroi extends Personagem implements Combatente{
    private int[] danoPorTurno;
    private String[][] campoDeBatalha;
    private boolean escudoAtivo;
    private int pontosDeEnergia;
    
    public Heroi(String nome, String classe, int vidaAtual, int vidaMaxima, int[] danoPorTurno,
            String[][] campoDeBatalha, boolean escudoAtivo, int pontosDeEnergia) {
        super(nome, classe, vidaAtual, vidaMaxima);
        this.danoPorTurno = danoPorTurno;
        this.campoDeBatalha = campoDeBatalha;
        this.escudoAtivo = escudoAtivo;
        this.pontosDeEnergia = pontosDeEnergia;
    }

    public int[] getDanoPorTurno() {
        return danoPorTurno;
    }
    public void setDanoPorTurno(int[] danoPorTurno) {
        this.danoPorTurno = danoPorTurno;
    }
    public String[][] getCampoDeBatalha() {
        return campoDeBatalha;
    }
    public void setCampoDeBatalha(String[][] campoDeBatalha) {
        this.campoDeBatalha = campoDeBatalha;
    }
    public boolean getEscudoAtivo() {
        return escudoAtivo;
    }
    public void setEscudoAtivo(boolean escudoAtivo) {
        this.escudoAtivo = escudoAtivo;
    }
    public int getPontosDeEnergia() {
        return pontosDeEnergia;
    }
    public void setPontosDeEnergia(int pontosDeEnergia) {
        this.pontosDeEnergia = pontosDeEnergia;
    }

    public void calcularPoder(String personagem) {
        if (personagem.equalsIgnoreCase("Guerreiro")) {
            setVidaMaxima(getVidaMaxima() + getPontosDeEnergia());
        }
        else if (personagem.equalsIgnoreCase("Mago")) {
            setPontosDeEnergia(getPontosDeEnergia() * 2);
        }
        else if (personagem.equalsIgnoreCase("Arqueiro")) {
            setVidaMaxima((getVidaMaxima() / 2) + getPontosDeEnergia());
        }
    }

    public void receberDano(int dano) {
        if (getEscudoAtivo() == true) {
            setVidaAtual(getVidaAtual() - dano * 30 / 100);
            for (int i = 0; i < getDanoPorTurno().length; i++) {
                if (getDanoPorTurno()[i] == 0) {
                    getDanoPorTurno()[i] = dano * 30 / 100;
                    break;
                }
            }
        }
        else {
            setVidaAtual(getVidaAtual() - dano);
            for (int i = 0; i < getDanoPorTurno().length; i++) {
                if (getDanoPorTurno()[i] == 0) {
                    getDanoPorTurno()[i] = getVidaAtual() - dano;
                    break;
                }
            }
        }
    }

    public void executarAcao(int dano, String habilidade, int linha, int coluna) 
    throws AcaoInvalidaException{
        if (getVidaAtual() == 0) {
            throw new AcaoInvalidaException("A vida está zerada.");
        }
        else if (getVidaAtual() < 0) {
            throw new AcaoInvalidaException("A vida está negativa!");
        }
        else if (habilidade.equalsIgnoreCase(null)) {
            throw new AcaoInvalidaException("Habilidade indisponível!");
        }
        else if (linha > getCampoDeBatalha().length || coluna > getCampoDeBatalha()[linha].length ||
        linha < 0 || coluna < 0) {
            throw new AcaoInvalidaException("Posição do campo de batalha inválida!");
        }

        System.out.printf("Você efetuou %d dano com a habilidade %s na posição [%d][%d]\n", 
        dano, habilidade, linha, coluna);

    }


}
