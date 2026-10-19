package BibliotecaUniversitaria;

public abstract class PessoaBiblioteca {
    private String matricula;
    private String nome;
    private String categoria;
    private int limiteEmprestimos;

    public PessoaBiblioteca(String matricula, String nome, String categoria, int limiteEmprestimos) {
        this.matricula = matricula;
        this.nome = nome;
        this.categoria = categoria;
        this.limiteEmprestimos = limiteEmprestimos;
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public int getLimiteEmprestimos() {
        return limiteEmprestimos;
    }

    public void setLimiteEmprestimos(int limiteEmprestimos) {
        this.limiteEmprestimos = limiteEmprestimos;
    }

    abstract int calcularPrazoPadrao();
}
