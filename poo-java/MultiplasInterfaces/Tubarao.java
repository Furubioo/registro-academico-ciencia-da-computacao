package MultiplasInterfaces;

public class Tubarao implements Nadavel{
    private String nome;
    private double peso;
    private double comprimento;

    public Tubarao(String nome, double peso, double comprimento) {
        this.nome = nome;
        this.peso = peso;
        this.comprimento = comprimento;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public double getPeso() {
        return peso;
    }
    public void setPeso(double peso) {
        this.peso = peso;
    }
    public double getComprimento() {
        return comprimento;
    }
    public void setComprimento(double comprimento) {
        this.comprimento = comprimento;
    }

    public void nadar() {
        System.out.println("O tubarão está nadando");
    }

}
