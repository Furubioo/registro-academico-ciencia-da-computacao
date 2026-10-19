package ModuloDePublicacoes;

public class PerfilUsuario extends Perfil implements Publicavel{
    private String[] publicacoes;
    private int totalSeguidores;
    private int totalPublicacoes;

    public PerfilUsuario(String nomeUsuario, String email, String dataCriacao, String tipoPlano, String[] publicacoes,
            int totalSeguidores, int totalPublicacoes) {
        super(nomeUsuario, email, dataCriacao, tipoPlano);
        this.publicacoes = publicacoes;
        this.totalSeguidores = totalSeguidores;
        this.totalPublicacoes = totalPublicacoes;
    }

    public String[] getPublicacoes() {
        return publicacoes;
    }
    public void setPublicacoes(String[] publicacoes) {
        this.publicacoes = publicacoes;
    }
    public int getTotalSeguidores() {
        return totalSeguidores;
    }
    public void setTotalSeguidores(int totalSeguidores) {
        this.totalSeguidores = totalSeguidores;
    }
    public int getTotalPublicacoes() {
        return totalPublicacoes;
    }
    public void setTotalPublicacoes(int totalPublicacoes) {
        this.totalPublicacoes = totalPublicacoes;
    }

    public void calcularEngajamento() {
        double indiceEngajamento = 0;
        indiceEngajamento = (getTotalPublicacoes() * 100) / (getTotalSeguidores() + 1);
        System.out.println("O índice de engajamento é: "+indiceEngajamento);
    }

    public void publicarConteudo(String publicacao) throws ConteudoInvalidoException{
        if (publicacao == null || publicacao.isEmpty()) {
            throw new ConteudoInvalidoException("O conteúdo é nulo ou vazio!");
        }
        else if (publicacao.length() > 280) {
            throw new ConteudoInvalidoException("O limite de 280 caracteres foi excedido!");
        }
        else if (getPublicacoes()[getPublicacoes().length - 1] != null) {
            throw new ConteudoInvalidoException("O limite máximo de publicações foi atingido!");
        }
        getPublicacoes()[getTotalPublicacoes()] = publicacao;
        setTotalPublicacoes(getTotalSeguidores() + 1);
    }

    public void removerPublicacao(int indice) {
        if (indice >= 0 && indice < getPublicacoes().length) {
            for (int i = 0; i < getPublicacoes().length; i++) {
                if (i == indice) {
                    getPublicacoes()[i] = null;
                    for (int j = i; j < getPublicacoes().length; j++) {
                        getPublicacoes()[i] = getPublicacoes()[i + 1];
                    }
                }
            }
            getPublicacoes()[getPublicacoes().length - 1] = null;
        }
    }

    public void seguir() {
        setTotalSeguidores(getTotalSeguidores() + 1);
        System.out.println("Nova quantidade de seguidores: "+getTotalSeguidores());
    }

    public void listarPublicacoes() {
        for (int i = 0; i < getPublicacoes().length; i++) {
            System.out.printf("Publicação %d: %s\n\n", i, getPublicacoes()[i]);
        }
    }

}
