package SistemaBancario;

public class ValorInvalidoException extends Exception {
    public ValorInvalidoException() {
        super("O valor fornecido é inválido!");
    }
}
