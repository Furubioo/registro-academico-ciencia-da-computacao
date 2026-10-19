package SistemaDeStreaming;

public interface Gerenciavel {
    void adicionarFaixa(String faixa) throws FaixaInvalidaException;
    void exportarEstatisticas();
}
