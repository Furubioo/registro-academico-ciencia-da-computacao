package TorneioEsportivo;

public abstract class Equipe {
    private String nome;
    private String sigla;
    private String cidade;
    private String tecnico;

    public Equipe(String nome, String sigla, String cidade, String tecnico) {
        this.nome = nome;
        this.sigla = sigla;
        this.cidade = cidade;
        this.tecnico = tecnico;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getSigla() {
        return sigla;
    }
    public void setSigla(String sigla) {
        this.sigla = sigla;
    }
    public String getCidade() {
        return cidade;
    }
    public void setCidade(String cidade) {
        this.cidade = cidade;
    }
    public String getTecnico() {
        return tecnico;
    }
    public void setTecnico(String tecnico) {
        this.tecnico = tecnico;
    }

    abstract void calcularDesempenho();
}
