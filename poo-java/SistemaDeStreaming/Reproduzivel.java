package SistemaDeStreaming;

public interface Reproduzivel {
    void reproduzir(int indice) throws FaixaInvalidaException;
    void avancarFaixa() throws FaixaInvalidaException;
    
}
