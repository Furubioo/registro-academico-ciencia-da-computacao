package PlataformaDeEntregas;

public abstract class Entregador {
    private String id;
    private String nome;
    private String modalidade;
    private double avaliacaoMedia;

    public Entregador(String id, String nome, String modalidade, double avaliacaoMedia) {
        this.id = id;
        this.nome = nome;
        this.modalidade = modalidade;
        this.avaliacaoMedia = avaliacaoMedia;
    }

    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getModalidade() {
        return modalidade;
    }
    public void setModalidade(String modalidade) {
        this.modalidade = modalidade;
    }
    public double getAvaliacaoMedia() {
        return avaliacaoMedia;
    }
    public void setAvaliacaoMedia(double avaliacaoMedia) {
        this.avaliacaoMedia = avaliacaoMedia;
    }

    abstract double calcularPagamentoBase();



}
