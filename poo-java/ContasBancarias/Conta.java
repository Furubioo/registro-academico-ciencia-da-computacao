package ContasBancarias;

public abstract class Conta {
    private String numeroConta;
    private String titular;
    private double saldo;

    public Conta(String numeroConta, String titular, double saldo) {
        this.numeroConta = numeroConta;
        this.titular = titular;
        this.saldo = saldo;
    }

    public String getNumeroConta() {
        return numeroConta;
    }
    public void setNumeroConta(String numeroConta) {
        this.numeroConta = numeroConta;
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

    public void depositar(double valor) {
        if (valor > 0) {
            setSaldo(getSaldo() + valor);
        }
    } 

    public abstract void sacar(double valor);

    public void exibirExtrato() {
        System.out.println("Numero da conta: "+getNumeroConta());
        System.out.println("Titular: "+getTitular());
        System.out.println("Saldo: "+getSaldo()+ "\n");
    }


}
