package Exercicio9;

public class Cliente {
    private String nome;
    private int idade;
    private Conta conta;

    public Cliente(String nome, int idade, Conta conta) {
        this.nome = nome;
        this.idade = idade;
        this.conta = conta;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public Conta getConta() {
        return conta;
    }

    public void setConta(Conta conta) {
        this.conta = conta;
    }


}
