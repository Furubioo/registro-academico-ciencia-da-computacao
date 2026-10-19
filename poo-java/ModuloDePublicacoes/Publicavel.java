package ModuloDePublicacoes;

public interface Publicavel {
    void publicarConteudo(String publicacao) throws ConteudoInvalidoException;
    void removerPublicacao(int indice);
}
