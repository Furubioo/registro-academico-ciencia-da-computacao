package SistemaBancario;

public interface Operavel {
    void depositar(double valor) throws ValorInvalidoException;
    void sacar(double valor) throws ValorInvalidoException, SaldoInsuficienteException,
    LimiteDiarioException;
    double calcularTarifaMensal();
}
