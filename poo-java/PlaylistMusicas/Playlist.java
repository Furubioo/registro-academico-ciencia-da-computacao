package PlaylistMusicas;

public class Playlist {
    private String nome;
    private Midia[] faixas;

    public Playlist(String nome, Midia[] faixas) {
        this.nome = nome;
        this.faixas = faixas;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public Midia[] getFaixas() {
        return faixas;
    }
    public void setFaixas(Midia[] faixas) {
        this.faixas = faixas;
    }

    public void adicionar(Midia m) {
        for (int i = 0; i < faixas.length; i++) {
            if (faixas[i] == null) {
                faixas[i] = m;
                break;
            }
        }
    }

    public void duracaoTotal() {
        int soma = 0;
        for (int i = 0; i < faixas.length; i++) {
            soma += faixas[i].getDuracaoSegundos();
        }
        System.out.println("Duração total(s): "+soma);
    }

    public void exibir() {
        System.out.println("=====" +getNome() + "=====");
        for (int i = 0; i < faixas.length; i++) {
            System.out.println("Título: "+faixas[i].getTitulo());
            System.out.println("Artista: "+faixas[i].getArtista());
            System.out.println("Duração: "+faixas[i].getDuracaoSegundos());
        }
    }
}
