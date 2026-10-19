package AnimaisESons;

public class Cachorro extends Animal{
    private String raca;

    public Cachorro(String nome, String especie, int idade, String raca) {
        super(nome, especie, idade);
        this.raca = raca;
    }

    public String getRaca() {
        return raca;
    }

    public void setRaca(String raca) {
        this.raca = raca;
    }

    @Override
    public void emitirSom() {
        System.out.println("Au au!");
    }

    @Override
    public void mover() {
        System.out.println("O cachorro está se movendo.");
    }

    
}
