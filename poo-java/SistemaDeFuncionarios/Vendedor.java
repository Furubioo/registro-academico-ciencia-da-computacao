package SistemaDeFuncionarios;

public class Vendedor extends Funcionario{
    double totalVendas;
    double comissaoPercentual;

    public Vendedor(String nome, String cpf, double salarioBase, double totalVendas, double comissaoPercentual) {
        super(nome, cpf, salarioBase);
        this.totalVendas = totalVendas;
        this.comissaoPercentual = comissaoPercentual;
    }

    public double getComissaoPercentual() {
        return comissaoPercentual;
    }

    public void setComissaoPercentual(double comissaoPercentual) {
        this.comissaoPercentual = comissaoPercentual;
    }

    public double getTotalVendas() {
        return totalVendas;
    }

    public void setTotalVendas(int  totalVendas) {
        this.totalVendas = totalVendas;
    }

    @Override
    public void calcularSalario() {
        setSalarioBase(getSalarioBase() + (getTotalVendas() * getComissaoPercentual()));
    }


}
