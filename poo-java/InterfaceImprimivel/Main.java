package InterfaceImprimivel;

public class Main {
    public static void main(String[] args) {
        Imprimivel vet[] = new Imprimivel[3];

        vet[0] = new Relatorio("Mais um dia", "O dia está de fato muito belo.","24/09/1999");
        vet[1] = new NotaFiscal(292813, 29.99, "Pedro Gabriel");
        vet[2] = new Contrato("João e Maria", "Válido de 01/01/2026 até 01/01/2027");

        for(int i = 0 ; i < 3; i++) {
            vet[i].imprimir();
        }
    }
}
