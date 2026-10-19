package SistemaDeStreaming;

public abstract class ContaUsuario {
    private String nomeUsuario;
    private String email;
    private String plano;
    private int limiteSkipsPorHora;

    public ContaUsuario(String nomeUsuario, String email, String plano, int limiteSkipsPorHora) {
        this.nomeUsuario = nomeUsuario;
        this.email = email;
        this.plano = plano;
        this.limiteSkipsPorHora = limiteSkipsPorHora;
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
    public String getPlano() {
        return plano;
    }
    public void setPlano(String plano) {
        this.plano = plano;
    }
    public int getLimiteSkipsPorHora() {
        return limiteSkipsPorHora;
    }
    public void setLimiteSkipsPorHora(int limiteSkipsPorHora) {
        this.limiteSkipsPorHora = limiteSkipsPorHora;
    }

    public void validarPlano() {
        if (getPlano().equalsIgnoreCase("Básico")
        || getPlano().equalsIgnoreCase("Premium") 
        || getPlano().equalsIgnoreCase("Família")) {
            System.out.println("O plano é válido.");
        }
        else {
            System.out.println("O plano informado é inválido.");
        }
    }

    abstract double calcularCustoMensal();
}
