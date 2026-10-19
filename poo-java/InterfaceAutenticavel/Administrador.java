package InterfaceAutenticavel;

public class Administrador implements Autenticavel{
    private String login;
    private String senha;
    private String nivelAcesso;
    private int tentativas = 0;
    private boolean bloqueado = false;

    public Administrador(String login, String senha, String nivelAcesso) {
        this.login = login;
        this.senha = senha;
        this.nivelAcesso = nivelAcesso;
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
    public String getNivelAcesso() {
        return nivelAcesso;
    }
    public void setNivelAcesso(String nivelAcesso) {
        this.nivelAcesso = nivelAcesso;
    }
    public int getTentativas() {
        return tentativas;
    }
    public void setTentativas(int tentativas) {
        this.tentativas = tentativas;
    }
    public boolean isBloqueado() {
        return bloqueado;
    }
    public void setBloqueado(boolean bloqueado) {
        this.bloqueado = bloqueado;
    }

    @Override
    public boolean autenticar(String senha) {
        if (senha == getSenha()) {
            return true;
        }
        else if (getTentativas() > 3) {
            bloquear();
            return false;
        }
        else {
            setTentativas(getTentativas() + 1);
            return false;
        }
    }

    @Override
    public void bloquear() {
        System.out.println("Limite de tentativas atingido!");
        setBloqueado(true);
    }
    
}
