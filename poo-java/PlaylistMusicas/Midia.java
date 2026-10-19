package PlaylistMusicas;

public abstract class Midia {
    private String titulo;
    private String artista;
    private int duracaoSegundos;

    public Midia(String titulo, String artista, int duracaoSegundos) {
        this.titulo = titulo;
        this.artista = artista;
        this.duracaoSegundos = duracaoSegundos;
    }

    public String getTitulo() {
        return titulo;
    }
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    public String getArtista() {
        return artista;
    }
    public void setArtista(String artista) {
        this.artista = artista;
    }
    public int getDuracaoSegundos() {
        return duracaoSegundos;
    }
    public void setDuracaoSegundos(int duracaoSegundos) {
        this.duracaoSegundos = duracaoSegundos;
    }        

    public String duracaoFormatada() {
        int mm = 0, ss = 0;
        for(int i = 0; i < getDuracaoSegundos(); i++) {
            if (i % 60 == 0) {
                mm++;
            }
        }
        ss = getDuracaoSegundos() % 60;

        String minsec = "" +mm+ ":" + ""+ss;

        return minsec;
    }

    public abstract void info();

}
