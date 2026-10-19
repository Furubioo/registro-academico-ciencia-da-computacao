package InterfaceAutenticavel;

public class UsuarioSistema implements Autenticavel{
    private String login;
    private String senha;
    private String email;
    private int tentativas = 0;
    private boolean bloqueado = false;

    public UsuarioSistema(String login, String senha, String email) {
        this.login = login;
        this.senha = senha;
        this.email = email;
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
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        this.email = email;
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
