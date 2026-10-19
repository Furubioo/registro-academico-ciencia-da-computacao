package ContasBancarias;

public class ContaCorrente extends Conta{
    private double limite;

    public ContaCorrente(String numeroConta, String titular, double saldo, double limite) {
        super(numeroConta, titular, saldo);
        this.limite = limite;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }

    public void sacar(double valor) {
        if ((getSaldo() + getLimite()) >= valor) {
            setSaldo(getSaldo() - valor);
        }
        else {
            System.out.println("Não foi possível sacar.");
        }
    }


}
