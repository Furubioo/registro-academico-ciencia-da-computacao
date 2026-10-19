package AnimaisESons;

public class Peixe extends Animal{
    private String habitat;

    public Peixe(String nome, String especie, int idade, String habitat) {
        super(nome, especie, idade);
        this.habitat = habitat;

    }

    public String getHabitat() {
        return habitat;
    }

    public void setHabitat(String habitat) {
        this.habitat = habitat;
    } 

    @Override
    public void emitirSom() {
        System.out.println("Peixes não reproduzem som.");
    }

    @Override
    public void mover() {
        System.out.println("O peixe está se movendo.");
    }
    
    
}
