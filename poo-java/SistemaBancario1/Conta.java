package SistemaBancario1;

public abstract class Conta {
    private String titular;
    private String numeroConta;
    private String agencia;
    private double saldo;

    public Conta(String titular, String numeroConta, String agencia, double saldo) {
        this.titular = titular;
        this.numeroConta = numeroConta;
        this.agencia = agencia;
        this.saldo = saldo;
    }

    public String getTitular() {
        return titular;
    }
    public void setTitular(String titular) {
        this.titular = titular;
    }
    public String getNumeroConta() {
        return numeroConta;
    }
    public void setNumeroConta(String numeroConta) {
        this.numeroConta = numeroConta;
    }
    public String getAgencia() {
        return agencia;
    }
    public void setAgencia(String agencia) {
        this.agencia = agencia;
    }
    public double getSaldo() {
        return saldo;
    }
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    abstract double calcularRendimento();

    
}
