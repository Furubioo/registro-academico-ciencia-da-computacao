package TorneioEsportivo;

public interface Competidor {
    void registrarResultado(int placar1, int placar2) throws ResultadoInvalidoException;
    int calcularClassificacao();
}
