package SimuladoPOO;

public abstract class Usuario {
    private String login;
    private String senha;
    private String plano;

    public Usuario(String login, String senha, String plano) {
        this.login = login;
        this.senha = senha;
        this.plano = plano;
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
    
    abstract double calculoDeMensalidade();


}
