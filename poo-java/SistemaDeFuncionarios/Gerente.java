package SistemaDeFuncionarios;

public class Gerente extends Funcionario{
    double bonusPercentual;

    public Gerente(String nome, String cpf, double salarioBase, double bonusPercentual) {
        super(nome, cpf, salarioBase);  
        this.bonusPercentual = bonusPercentual;
    }

    public double getBonusPercentual() {
        return bonusPercentual;
    }

    public void setBonusPercentual(double bonusPercentual) {
        this.bonusPercentual = bonusPercentual;
    }

    @Override
    public void calcularSalario() {
        setSalarioBase(getSalarioBase() + (getSalarioBase() * getBonusPercentual()));
    }


}
