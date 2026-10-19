package SistemaDeBatalha;

public abstract class Personagem {
    private String nome;
    private int vidaMaxima;
    private int vidaAtual;
    private int nivel;

    public Personagem(String nome, int vidaMaxima, int vidaAtual, int nivel) {
        this.nome = nome;
        this.vidaMaxima = vidaMaxima;
        this.vidaAtual = vidaAtual;
        this.nivel = nivel;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public int getVidaMaxima() {
        return vidaMaxima;
    }
    public void setVidaMaxima(int vidaMaxima) {
        this.vidaMaxima = vidaMaxima;
    }
    public int getVidaAtual() {
        return vidaAtual;
    }
    public void setVidaAtual(int vidaAtual) {
        this.vidaAtual = vidaAtual;
    }
    public int getNivel() {
        return nivel;
    }
    public void setNivel(int nivel) {
        this.nivel = nivel;
    }

    abstract void calcularPoderDeAtaque();


}
