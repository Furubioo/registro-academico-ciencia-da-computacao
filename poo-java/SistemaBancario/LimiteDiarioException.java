package SistemaBancario;

public class LimiteDiarioException extends Exception{
    public LimiteDiarioException() {
        super("O limite diário foi excedido!");
    }
}
