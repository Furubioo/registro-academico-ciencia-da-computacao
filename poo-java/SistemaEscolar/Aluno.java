package SistemaEscolar;

public class Aluno extends MembroEscolar implements Avaliavel{
    private double[] notas = new double[4];
    private int presencas;
    private int totalAulas;

    public Aluno(String nome, String matricula, String serie, String turno, int presencas,
            int totalAulas) {
        super(nome, matricula, serie, turno);
        this.presencas = presencas;
        this.totalAulas = totalAulas;
    }

    public double[] getNotas() {
        return notas;
    }
    public void setNotas(double[] notas) {
        this.notas = notas;
    }
    public int getPresencas() {
        return presencas;
    }
    public void setPresencas(int presencas) {
        this.presencas = presencas;
    }
    public int getTotalAulas() {
        return totalAulas;
    }
    public void setTotalAulas(int totalAulas) {
        this.totalAulas = totalAulas;
    }

    public String calcularSituacao(double media) {
        String situacao = null;
        if (getPresencas() < 0.75 * getTotalAulas()) {
            System.out.println("Reprovado por frequência");
            situacao = "Reprovado por frequência";

        }
        else if (media >= 7 && getPresencas() >= getTotalAulas() * 0.75) {
            System.out.println("Aprovado");
            situacao = "Aprovado";

        }
        else if (media >= 5) {
            System.out.println("Recuperação");
            situacao = "Recuperação";
        }
        else {
            System.out.println("Reprovado");
            situacao = "Reprovado";
        }

        return situacao;
    }

    public void registrarNota(double nota) throws NotaInvalidaException{
        if (nota < 0 || nota > 10) {
            throw new NotaInvalidaException();
        }
        else {
            for (int i = 0; i < 4; i++) {
                if (getNotas()[i] == 0.0) {
                    getNotas()[i] = nota;
                    break;
                }
            }
        }
    }

    public double calcularMedia() {
        double soma = 0, media = 0;
        for (int i = 0; i < 4; i++) {
            soma += getNotas()[i];
        }
        media = soma / 4;

        return media;
    }

    public void registrarPresenca() {
        setPresencas(getPresencas() + 1);
        System.out.println("Presenças: "+getPresencas());
    }   

    public double calcularFrequencia() {
        return getPresencas()/(getTotalAulas() * 100);
    }

}
