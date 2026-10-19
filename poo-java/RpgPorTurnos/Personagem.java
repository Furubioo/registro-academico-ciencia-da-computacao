package RpgPorTurnos;

public abstract class Personagem {
    private String nome;
    private String classe;
    private int vidaAtual;
    private int vidaMaxima;

    public Personagem(String nome, String classe, int vidaAtual, int vidaMaxima) {
        this.nome = nome;
        this.classe = classe;
        this.vidaAtual = vidaAtual;
        this.vidaMaxima = vidaMaxima;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getClasse() {
        return classe;
    }
    public void setClasse(String classe) {
        this.classe = classe;
    }
    public int getVidaAtual() {
        return vidaAtual;
    }
    public void setVidaAtual(int vidaAtual) {
        this.vidaAtual = vidaAtual;
    }
    public int getVidaMaxima() {
        return vidaMaxima;
    }
    public void setVidaMaxima(int vidaMaxima) {
        this.vidaMaxima = vidaMaxima;
    }

    abstract void calcularPoder(String personagem);

}
