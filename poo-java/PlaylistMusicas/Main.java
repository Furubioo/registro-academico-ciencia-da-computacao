package PlaylistMusicas;

public class Main {
    public static void main(String[] args) {
        Musica m1 = new Musica("O amigo", "Sérgio Lopes", 300, "Gospel");
        Musica m2 = new Musica("Rock my world", "Michael Jackson", 350, "Pop");
        Musica m3 = new Musica("Cartoon on & on", "NCS", 270, "Eletronic");
        Podcast p1 = new Podcast("Rubens Barrichello", "Igor", 30000, 8,  "Flow Podcast");
        Podcast p2 = new Podcast("Ricardinho", "Igor", 50000, 20, "Flow Podcast");

        Midia[] faixas = new Midia[5];
        faixas[0] = m1;
        faixas[1] = m2;
        faixas[2] = m3;
        faixas[3] = p1;
        faixas[4] = p2;

        Playlist P = new Playlist("Tchow", faixas);
        P.exibir();
        m1.play();
        m2.play();
        m3.play();
        p1.play();
        p2.play();

    }
}
