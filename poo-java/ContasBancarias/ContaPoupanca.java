package ContasBancarias;

public class ContaPoupanca extends Conta{
    private double taxaRendimento;

    public ContaPoupanca(String numeroConta, String titular, double saldo, double taxaRendimento) {
        super(numeroConta, titular, saldo);
        this.taxaRendimento = taxaRendimento;
    }

    public double getTaxaRendimento() {
        return taxaRendimento;
    }

    public void setTaxaRendimento(double taxaRendimento) {
        this.taxaRendimento = taxaRendimento;
    }

    public void sacar(double valor) {
        if (valor <= getSaldo()) {
            setSaldo(getSaldo() - valor);
        }
        else {
            System.out.println("Não foi possível realizar o saque.");
        }
    }

    public void renderJuros() {
        if (getSaldo() > 0) {
            setSaldo(getSaldo() + (getSaldo() * getTaxaRendimento()));
        }
        else {
            System.out.println("Não há saldo!");
        }

    }

}
