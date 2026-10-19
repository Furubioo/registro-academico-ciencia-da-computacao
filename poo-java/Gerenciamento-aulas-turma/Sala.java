package Exercicio8;

public class Sala {
    private String nome;
    private boolean ocupada;
    private Aluno[] turma = new Aluno[10];
    private int diadeaula;

    public Sala(String nome, boolean ocupada, Aluno[] turma, int diadeaula) {

        this.nome = nome;
        this.ocupada = ocupada;
        this.turma = turma;
        this.diadeaula = diadeaula;

    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public boolean getOcupada() {
        return ocupada;
    }

    public void setOcupada(boolean ocupada) {
        this.ocupada = ocupada;
    }

    public Aluno[] getTurma() {
        return turma;
    }

    public void setTurma(Aluno[] turma) {
        this.turma = turma;
    }

    public int getDiadeaula() {
        return diadeaula;
    }

    public void setDiadeaula(int diadeaula) {
        this.diadeaula = diadeaula;
    }

    public boolean Alternar() {

        if (getOcupada() == false) {
            setOcupada(true);
            return getOcupada();
            
        }
        else {
            setOcupada(false);
            return getOcupada();
        }

    }

}
