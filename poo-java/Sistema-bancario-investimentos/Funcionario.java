package Exercicio9;


public class Funcionario extends Cliente{
    private String cargo;

    public Funcionario(String nome, int idade, Conta conta, String cargo) {
        super(nome, idade, conta);
        this.cargo = cargo;
    }

    public String getCargo() {
        return cargo;
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    public void InvEspecial(Conta conta, int numero) {
        if (numero == 60) {
            double saldoAtual = conta.getSaldo();
            conta.setSaldo(saldoAtual += conta.getSaldo() * 0.5);
            System.out.println("O saldo teve investimento especial!");
        }    
    } 
}
