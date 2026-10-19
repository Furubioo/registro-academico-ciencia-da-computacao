package Exercicio9;

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        
        Investimento i1 = new Investimento("Caixa", "12345678", 100, "baixo");

        Funcionario f1 = new Funcionario("Gabriel", 26, i1, "Programador");

        Random gerador = new Random();
        int numero = gerador.nextInt(0, 100);

        System.out.println("Nome: "+f1.getNome());
        System.out.println("Idade: "+f1.getIdade());
        System.out.println("Agência: "+f1.getConta().getAgencia());
        System.out.println("Número da conta: "+f1.getConta().getNumconta());
        System.out.println("Saldo atual: "+f1.getConta().getSaldo());
        System.out.println("Cargo: "+f1.getCargo());

        i1.Investir(numero);
        i1.Investir(numero, 0);

        f1.InvEspecial(i1, numero);

        System.out.println("Saldo após possíveis investimentos: "+f1.getConta().getSaldo());

    }
}
