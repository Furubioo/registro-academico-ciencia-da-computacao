package BoletimEscolar;

public class TurmaUniversitaria extends Turma{
    
    public TurmaUniversitaria(String nomeTurma, String[] nomeAlunos, double[][] notas) {
        super(nomeTurma, nomeAlunos, notas);
    }

    @Override
    public void avaliarTurma() {
        double soma = 0, media = 0;
        int qtd = 0;
        for (int i = 0; i < getNotas().length; i++) {
            if (mediaAluno(i) >= 6) {
                System.out.print("Aprovado(a): "+getNomeAlunos()[i]+"\n");
            }
            else {
                System.out.print("Reprovado(a): "+getNomeAlunos()[i]+"\n");
            }
            for (int j = 0; j < getNotas()[i].length; j++) {
                soma += getNotas()[i][j];
                qtd++;
            }
        }
        media = soma / qtd;
        System.out.println("\nCoeficiente da turma: "+media);
    }
}
