package SistemaDeFuncionarios;

public class Main {
    public static void main(String[] args) {
        Estagiario e1 = new Estagiario("Juscelino", "192.884.992-30", 900);
        Gerente f1 = new Gerente("Gabriel", "222.331.451-90", 4000, 0.2);
        Vendedor v1 = new Vendedor("Marcelo", "002.341.321-11", 1700, 200, 0.05);

        System.out.println("===== Antes de calcular o salário =====\n");
        e1.exibirFicha();
        f1.exibirFicha();
        v1.exibirFicha();

        e1.calcularSalario();
        f1.calcularSalario();
        v1.calcularSalario();

        System.out.println("===== Após calcular o salário ===== \n");
        e1.exibirFicha();
        f1.exibirFicha();
        v1.exibirFicha();

    }
}
