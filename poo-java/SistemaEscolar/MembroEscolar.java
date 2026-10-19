package SistemaEscolar;

public abstract class MembroEscolar {
    private String nome;
    private String matricula;
    private String serie;
    private String turno;

    public MembroEscolar(String nome, String matricula, String serie, String turno) {
        this.nome = nome;
        this.matricula = matricula;
        this.serie = serie;
        this.turno = turno;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getMatricula() {
        return matricula;
    }
    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }
    public String getSerie() {
        return serie;
    }
    public void setSerie(String serie) {
        this.serie = serie;
    }
    public String getTurno() {
        return turno;
    }
    public void setTurno(String turno) {
        this.turno = turno;
    }

    abstract String calcularSituacao(double media);


}
