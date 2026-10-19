package SistemaEscolar;

public interface Avaliavel {
    void registrarNota(double nota) throws NotaInvalidaException;
    double calcularMedia();
}
