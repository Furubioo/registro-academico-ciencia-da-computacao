package BoletimEscolar;

public class TurmaFundamental extends Turma{

    public TurmaFundamental(String nomeTurma, String[] nomeAlunos, double[][] notas) {
        super(nomeTurma, nomeAlunos, notas);
    }

    @Override
    public void avaliarTurma() {
        for (int i = 0; i < getNotas().length; i++) {
            if (mediaAluno(i) >= 5) {
                System.out.print("Aprovado(a): "+getNomeAlunos()[i]+"\n");
            }
            else {
                System.out.print("Reprovado(a): "+getNomeAlunos()[i]+"\n");
            }
        }
    }
}
