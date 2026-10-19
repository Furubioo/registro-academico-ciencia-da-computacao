package SistemaBancario1;

public interface Transacionavel {
    void realizarTransferencia(double valor) throws SaldoInsuficienteException;
    void consultarExtrato();
}
