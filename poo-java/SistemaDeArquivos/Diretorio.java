package SistemaDeArquivos;

public class Diretorio extends EntradaSistema {
    private final EntradaSistema[] conteudo = new EntradaSistema[10];
    private int quantidade;

    public Diretorio(String nome, String caminho, long tamanho) {
        super(nome, caminho, tamanho);
    }

    public boolean adicionar(EntradaSistema entrada) {
        if (quantidade == conteudo.length) {
            return false;
        }
        conteudo[quantidade] = entrada;
        quantidade++;
        return true;
    }

    @Override
    public void descrever() {
        System.out.println("Diretorio com " + quantidade + " entrada(s).");
    }

    @Override
    public long calcularEspacoOcupado() {
        long total = getTamanho();
        for (int indice = 0; indice < quantidade; indice++) {
            total += conteudo[indice].getTamanho();
        }
        return total;
    }
}
