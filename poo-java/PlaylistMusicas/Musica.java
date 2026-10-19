package PlaylistMusicas;

public class Musica extends Midia implements Tocavel{
    private String genero;

    public Musica(String titulo, String artista, int duracaoSegundos, String genero) {
        super(titulo, artista, duracaoSegundos);
        this.genero = genero;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public void play() {
        System.out.println("A música está tocando.");
    }

    public void pause() {
        System.out.println("A música está pausada");
    }

    public void stop() {
        System.out.println("Nenhuma musica está tocando.");
    }

    public void info() {
        System.out.println("Título: "+getTitulo());
        System.out.println("Artista: "+getArtista());
        System.out.println("Duração: "+duracaoFormatada());
        System.out.println("Gênero: "+getGenero());
    }
}
