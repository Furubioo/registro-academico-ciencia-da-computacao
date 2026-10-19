package AcademiaPorMetas;

public abstract class UsuarioFitness {
    private String login;
    private String senha;
    private String plano;
    private int metaSemanal;


    public UsuarioFitness(String login, String senha, String plano, int metaSemanal) {
        this.login = login;
        this.senha = senha;
        this.plano = plano;
        this.metaSemanal = metaSemanal;
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public String getPlano() {
        return plano;
    }

    public void setPlano(String plano) {
        this.plano = plano;
    }

    public int getMetaSemanal() {
        return metaSemanal;
    }

    public void setMetaSemanal(int metaSemanal) {
        this.metaSemanal = metaSemanal;
    }

    abstract double calcularCobranca();
}
