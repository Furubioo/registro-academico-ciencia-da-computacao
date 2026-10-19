package Exercicio9;

public class Conta {
    private String agencia;
    private String numconta;
    private double saldo;

    public Conta(String agencia, String numconta, double saldo) {
        this.agencia = agencia;
        this.numconta = numconta;
        this.saldo = saldo;
    }
    public String getAgencia() {
        return agencia;
    }
    public void setAgencia(String agencia) {
        this.agencia = agencia;
    }
    public String getNumconta() {
        return numconta;
    }
    public void setNumconta(String numconta) {
        this.numconta = numconta;
    }
    public double getSaldo() {
        return saldo;
    }
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public void Saque(double valor) {
        if (getSaldo() < valor) {
            System.out.println("Valor maior que o saldo!");
        }
        else {
            setSaldo(getSaldo() - valor);
            System.out.println("Saque realizado!");
            System.out.println("Saldo atual: "+getSaldo());
        }
    }

    public void Deposito(double adicionar) {
        setSaldo(getSaldo() + adicionar);
        System.out.println("Valor depositado!");
        System.out.println("Saldo atual: "+getSaldo());
    }

    public void Deposito(double adicionar, double imposto) {
        setSaldo(getSaldo() + adicionar);
        setSaldo(getSaldo() - getSaldo() * imposto);   
    }

}
