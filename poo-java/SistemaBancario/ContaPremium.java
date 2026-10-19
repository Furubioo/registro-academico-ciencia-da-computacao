package SistemaBancario;

public class ContaPremium extends Conta implements Operavel{
    private double cashbackAcumulado;
    private boolean ativa;

    public ContaPremium(String numero, String titular, double saldo, double limiteDiarioSaque) {
        super(numero, titular, saldo, limiteDiarioSaque);
        this.cashbackAcumulado = 0;
        this.ativa = true;
    }

    public double getCashbackAcumulado() {
        return cashbackAcumulado;
    }
    public void setCashbackAcumulado(double cashbackAcumulado) {
        this.cashbackAcumulado = cashbackAcumulado;
    }
    public boolean getAtiva() {
        return ativa;
    }
    public void setAtiva(boolean ativa) {
        this.ativa = ativa;
    }

    public void depositar(double valor) throws ValorInvalidoException{
        if (valor <= 0) {
            throw new ValorInvalidoException();
        }
        else {
            setSaldo(getSaldo() + valor);
        }
    }

    public void sacar(double valor) throws ValorInvalidoException, SaldoInsuficienteException,
    LimiteDiarioException {
        if (valor <= 0) {
            throw new ValorInvalidoException();
        }
        else if (valor > getSaldo()) {
            throw new SaldoInsuficienteException();
        }
        else if (valor > getLimiteDiarioSaque()) {
            throw new LimiteDiarioException();
        }
        else {
            setSaldo(getSaldo() - valor);
            setLimiteDiarioSaque(getLimiteDiarioSaque() + valor);
            setCashbackAcumulado(getCashbackAcumulado() * (0.01 * valor));
        }
    }

    public double calcularTarifaMensal() {
        double situacao = 0;
        if (getSaldo() < 1000.00) {
            situacao = 12.00;
        }
        else {
            situacao = 0.0;
        }
        if (getSaldo() < 0) {
            setAtiva(false);
        }
        return situacao;
    }

}
