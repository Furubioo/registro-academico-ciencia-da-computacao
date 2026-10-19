package Exercicio8;

public class Professor {
    
    private String nome;
    private int idade;
    private int matricula;
    private Sala sala;

    public Professor(String nome, int idade, int matricula, Sala sala) {

        this.nome = nome;
        this.idade = idade;
        this.matricula = matricula;
        this.sala = sala;

    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public Sala getSala() {
        return sala;
    }

    public void setSala(Sala sala){
        this.sala = sala;
    }

    public void IniciarAula() {

        if (sala.Alternar() == false) {
            System.out.println("**Aula em andamento**");
            System.out.println("Nome do professor: "+ getNome());
            System.out.println("Matrícula do professor: "+getMatricula());
        }
    }

    public void Chamada(boolean[] vet) {
    
        for (int i = 0; i < vet.length; i++) {
            if (vet[i] == true) {
                sala.setDiadeaula(i);
            }
        }
    }

    public void TerminarAula() {

        if (sala.Alternar() == true) {
            System.out.println("**Aula terminada**");
            System.out.println("Nome do professor " +getNome());
            System.out.println("Matrícula do professor: " +getMatricula());
            int a = sala.getDiadeaula();
            a++;
            sala.setDiadeaula(a);
        }


    }



}
