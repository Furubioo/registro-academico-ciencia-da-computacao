package ContasBancarias;

public class Main {
    public static void main(String[] args) {
        ContaCorrente c1 = new ContaCorrente("21313232", "Juscelino Irineu", 2000, 2500);
        ContaPoupanca c2 = new ContaPoupanca("345691912", "Alexandre Silva", 500, 0.5);

        System.out.println("===== Conta corrente =====");
        c1.exibirExtrato();

        System.out.println("=== Extrato(s) bancário após depósitos ===");
        c1.depositar(100);
        c1.exibirExtrato();

        System.out.println("=== Extrato(s) bancário após saques ===");
        c1.sacar(50);
        c1.exibirExtrato();

        System.out.println("===== Conta poupança =====");
        c2.exibirExtrato();

        System.out.println("=== Extrato(s) bancário após depósitos ===");
        c2.depositar(100);
        c2.exibirExtrato();

        System.out.println("=== Extrato(s) bancário após saques ===");
        c2.sacar(50);
        c2.exibirExtrato();


    }
}
