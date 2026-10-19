package SistemaRPG;

public class NoDamageException extends Exception{
    public NoDamageException(double ataque, double defesa) {
        super("Não houve dano suficiente! \nAtaque: "+ataque+"\nDefesa: "+defesa);
    }
}
