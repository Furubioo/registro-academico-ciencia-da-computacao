package BoletimEscolar;

public class Main {
    public static void main(String[] args) {
        String alunosFundamental[] = {"Júlio", "Gabriel", "Vitória"};
        double[][] notasFundamental = {{4.0, 3.0, 8.0}, {2.0, 10.0, 9.7}, {9.9, 10.0, 8.9}};
        
        TurmaFundamental tf = new TurmaFundamental("Jegues tiktokers", alunosFundamental, notasFundamental);

        String alunosUnivers[] = {"Gustavo", "Junior", "Cleiton"};
        double[][] notasUnivers = {{6.6, 3.4, 2,3}, {9.9, 1.2, 6.4}, {8.4, 6.6, 5.5}};

        TurmaUniversitaria tu = new TurmaUniversitaria("Dinosarios", alunosUnivers, notasUnivers);
        
        System.out.println("===== Turma fundamental =====\n");
        tf.avaliarTurma();
        System.out.println("===== Turma universitária =====\n");
        tu.avaliarTurma();

    }
}
