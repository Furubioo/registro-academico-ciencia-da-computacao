package SistemaHospitalar;

public abstract class ProfissionalSaude {
    private String nome;
    private String crm;
    private String especialidade;
    private double valorConsulta;

    public ProfissionalSaude(String nome, String crm, String especialidade, double valorConsulta) {
        this.nome = nome;
        this.crm = crm;
        this.especialidade = especialidade;
        this.valorConsulta = valorConsulta;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getCrm() {
        return crm;
    }
    public void setCrm(String crm) {
        this.crm = crm;
    }
    public String getEspecialidade() {
        return especialidade;
    }
    public void setEspecialidade(String especialidade) {
        this.especialidade = especialidade;
    }
    public double getValorConsulta() {
        return valorConsulta;
    }
    public void setValorConsulta(double valorConsulta) {
        this.valorConsulta = valorConsulta;
    }

    abstract void calcularHonorarios();
}
