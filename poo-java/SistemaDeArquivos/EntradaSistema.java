package SistemaDeArquivos;

public abstract class EntradaSistema {
    private String nome;
    private String caminho;
    private long tamanho;

    public EntradaSistema(String nome, String caminho, long tamanho) {
        this.nome = nome;
        this.caminho = caminho;
        this.tamanho = tamanho;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getCaminho() {
        return caminho;
    }
    public void setCaminho(String caminho) {
        this.caminho = caminho;
    }
    public long getTamanho() {
        return tamanho;
    }
    public void setTamanho(long tamanho) {
        this.tamanho = tamanho;
    }

    public void exibirInfo() {
        System.out.println("Nome: "+getNome());
        System.out.println("Caminho: "+getCaminho());
        System.out.println("Tamanho formatado: "+getTamanho());
    }

    public abstract void descrever();

    public abstract long calcularEspacoOcupado();
}
