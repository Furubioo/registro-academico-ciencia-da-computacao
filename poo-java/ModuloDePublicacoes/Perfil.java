package ModuloDePublicacoes;

public abstract class Perfil {
    private String nomeUsuario;
    private String email;
    private String dataCriacao;
    private String tipoPlano;
    
    public Perfil(String nomeUsuario, String email, String dataCriacao, String tipoPlano) {
        this.nomeUsuario = nomeUsuario;
        this.email = email;
        this.dataCriacao = dataCriacao;
        this.tipoPlano = tipoPlano;
    }

    public String getNomeUsuario() {
        return nomeUsuario;
    }
    public void setNomeUsuario(String nomeUsuario) {
        this.nomeUsuario = nomeUsuario;
    }
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public String getDataCriacao() {
        return dataCriacao;
    }
    public void setDataCriacao(String dataCriacao) {
        this.dataCriacao = dataCriacao;
    }
    public String getTipoPlano() {
        return tipoPlano;
    }
    public void setTipoPlano(String tipoPlano) {
        this.tipoPlano = tipoPlano;
    }

    abstract void calcularEngajamento();

}
