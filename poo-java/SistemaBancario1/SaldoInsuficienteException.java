package SistemaBancario1;

public class SaldoInsuficienteException extends Exception{
    public SaldoInsuficienteException() {
        super("O saldo atual é insuficiente!");
    }
}
