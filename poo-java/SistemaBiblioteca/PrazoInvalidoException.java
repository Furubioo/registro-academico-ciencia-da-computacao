package SistemaBiblioteca;

public class PrazoInvalidoException extends Exception{
    private int diasInvalidos;
    
    public PrazoInvalidoException(int diasInvalidos) {
        super("O prazo foi excedido!");
        this.diasInvalidos = diasInvalidos;
    }

    public int getDiasInvalidos() {
        return diasInvalidos;
    }

}
