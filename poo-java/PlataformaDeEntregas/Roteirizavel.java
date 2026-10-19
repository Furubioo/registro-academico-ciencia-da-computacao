package PlataformaDeEntregas;

public interface Roteirizavel {
    void registrarEntrega(int linha, int coluna, int tempo, int distancia, int avaliacao) throws EntregaInvalidaException;
    double calcularDesempenho(double avaliacao, int tempo);
}
