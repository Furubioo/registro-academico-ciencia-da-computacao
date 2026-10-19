package EstacionamentoInteligente;

public interface Tarifavel {
    abstract void registrarUso(int linha, int coluna) throws PermanenciaInvalidaException;
    abstract void calcularTarifa();
}
