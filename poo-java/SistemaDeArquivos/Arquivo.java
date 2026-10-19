package SistemaDeArquivos;

public class Arquivo extends EntradaSistema{
    private String extensao;
    private boolean comprimido;
    
    public Arquivo(String nome, String caminho, long tamanho, String extensao, boolean comprimido) {
        super(nome, caminho, tamanho);
        this.extensao = extensao;
        this.comprimido = comprimido;
    }

    public String getExtensao() {
        return extensao;
    }

    public void setExtensao(String extensao) {
        this.extensao = extensao;
    }

    public boolean getComprimido() {
        return comprimido;
    }

    public void setComprimido(boolean comprimido) {
        this.comprimido = comprimido;
    }

    @Override
    public long calcularEspacoOcupado() {
        long reducao = 0;
        if (getComprimido() == true) {
            reducao = (long)(getTamanho() - getTamanho() * 0.6);
            setTamanho(getTamanho() - reducao);
        }
        return reducao;
    }

    @Override
    public void descrever() {
        if (getComprimido() == true) {
            System.out.println("O arquivo está comprimido");
        }
        else {
            System.out.println("O arquivo não está comprimido");
        }
        System.out.println("Extensão: "+getExtensao());
    }


    


}
