package Exercicio8;

public class Main {
    public static void main(String[] args) {

        Aluno a1 = new Aluno("João", 23, 190411);
        
        Aluno[] vet1 = new Aluno[10];

        vet1[0] = a1;

        Sala s1 = new Sala("REDES A", true, vet1, 1);

        Professor p1 = new Professor("Júlio", 57, 12, s1);

        p1.IniciarAula();

        

        p1.TerminarAula();






    }
}
