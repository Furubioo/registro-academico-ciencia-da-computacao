package AnimaisESons;

public abstract class Animal {
    private String nome;
    private String especie;
    private int idade;

    public Animal(String nome, String especie, int idade) {
        this.nome = nome;
        this.especie = especie;
        this.idade = idade;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getEspecie() {
        return especie;
    }
    public void setEspecie(String especie) {
        this.especie = especie;
    }
    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }

    public abstract void emitirSom();

    public abstract void mover();

    public void dormir() {
        System.out.println("O animal está dormindo");
    }

    public void exibirInfo() {
        System.out.println("Animal: "+getNome());
        System.out.println("Espécie: "+getEspecie());
        System.out.println("Idade: "+getIdade()+ "\n");
    }

    
}
