package PlaylistMusicas;

public class Podcast extends Midia implements Tocavel{
    private int episodio;
    private String canal;

    public Podcast(String titulo, String artista, int duracaoSegundos, int episodio, String canal) {
        super(titulo, artista, duracaoSegundos);
        this.episodio = episodio;
        this.canal = canal;
    }

    public int getEpisodio() {
        return episodio;
    }

    public void setEpisodio(int episodio) {
        this.episodio = episodio;
    }

    public String getCanal() {
        return canal;
    }

    public void setCanal(String canal) {
        this.canal = canal;
    }

    public void info() {
        System.out.println("Título: "+getTitulo());
        System.out.println("Artista: "+getArtista());
        System.out.println("Duração: "+duracaoFormatada());
        System.out.println("Episódio: "+getEpisodio());
        System.out.println("Canal: "+getCanal());
    }

    public void play() {
        System.out.println("O podcast está em andamento");
    }

    public void pause() {
        System.out.println("O podcast foi pausado");
    }

    public void stop() {
        System.out.println("Não há nenhum podcast em andamento");
    }
}