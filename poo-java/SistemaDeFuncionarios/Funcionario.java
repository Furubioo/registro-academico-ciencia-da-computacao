package SistemaDeFuncionarios;

public abstract class Funcionario {
    private String nome;
    private String cpf;
    private double salarioBase;

    public Funcionario(String nome, String cpf, double salarioBase) {
        this.nome = nome;
        this.cpf = cpf;
        this.salarioBase = salarioBase;
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public double getSalarioBase() {
        return salarioBase;
    }

    public void setSalarioBase(double salarioBase) {
        this.salarioBase = salarioBase;
    }

    public abstract void calcularSalario();

    public void exibirFicha() {
        System.out.println("Nome: "+getNome());
        System.out.println("Cpf: "+getCpf());
        System.out.println("Salario base: R$ "+getSalarioBase()+ "\n");
    }

}
