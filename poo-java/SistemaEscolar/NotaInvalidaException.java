package SistemaEscolar;

public class NotaInvalidaException extends Exception{
    public NotaInvalidaException() {
        super("A nota fornecida está fora do intervalo");
    }
    
}
