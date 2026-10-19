package SistemaBancario;

public abstract class Conta {
    private String numero;
    private String titular;
    private double saldo;
    private double limiteDiarioSaque;

    public Conta(String numero, String titular, double saldo, double limiteDiarioSaque) {
        this.numero = numero;
        this.titular = titular;
        this.saldo = saldo;
        this.limiteDiarioSaque = limiteDiarioSaque;
    }

    public String getNumero() {
        return numero;
    }
    public void setNumero(String numero) {
        this.numero = numero;
    }
    public String getTitular() {
        return titular;
    }
    public void setTitular(String titular) {
        this.titular = titular;
    }
    public double getSaldo() {
        return saldo;
    }
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }
    public double getLimiteDiarioSaque() {
        return limiteDiarioSaque;
    }
    public void setLimiteDiarioSaque(double limiteDiarioSaque) {
        this.limiteDiarioSaque = limiteDiarioSaque;
    }

    abstract void depositar(double valor) throws ValorInvalidoException;
    
    abstract void sacar(double valor) throws ValorInvalidoException, SaldoInsuficienteException,
    LimiteDiarioException;

    abstract double calcularTarifaMensal();

}
