package SimuladoPOO;

public class Aluno extends Usuario implements Treinar{
    private int horasTotaisDeTreino;
    private int[] horasDiariasDeTreino;
    private double[] caloriasDiarias;

    public Aluno(String login, String senha, String plano, int horasTotaisDeTreino, int[] horasDiariasDeTreino,
            double[] caloriasDiarias) {
        super(login, senha, plano);
        this.horasTotaisDeTreino = horasTotaisDeTreino;
        this.horasDiariasDeTreino = horasDiariasDeTreino;
        this.caloriasDiarias = caloriasDiarias;
    }

    public int getHorasTotaisDeTreino() {
        return horasTotaisDeTreino;
    }
    public void setHorasTotaisDeTreino(int horasTotaisDeTreino) {
        this.horasTotaisDeTreino = horasTotaisDeTreino;
    }
    public int[] getHorasDiariasDeTreino() {
        return horasDiariasDeTreino;
    }
    public void setHorasDiariasDeTreino(int[] horasDiariasDeTreino) {
        this.horasDiariasDeTreino = horasDiariasDeTreino;
    }
    public double[] getCaloriasDiarias() {
        return caloriasDiarias;
    }
    public void setCaloriasDiarias(double[] caloriasDiarias) {
        this.caloriasDiarias = caloriasDiarias;
    }

    public double calculoDeMensalidade() {
        double mensalidade = 0;
        if (getPlano().equalsIgnoreCase("Mensal")) {
            mensalidade = 100;
        }
        else if (getPlano().equalsIgnoreCase("Anual")) {
            mensalidade = 80;
        }
        else if (getPlano().equalsIgnoreCase("Especial")) {
            mensalidade = 55;
        }
        return mensalidade;
    }

    public int tempoDeTreino(int inicio, int fim) throws HorarioInvalidoException{
        int tempo = 0;
        if (inicio < 5 || fim > 22) {
            throw new HorarioInvalidoException();
        }
        tempo = fim - inicio;
        for (int i = 0; i < getHorasDiariasDeTreino().length; i++) {
            if (getHorasDiariasDeTreino()[i] == 0) {
                getHorasDiariasDeTreino()[i] = tempo;
                setHorasTotaisDeTreino(getHorasTotaisDeTreino() + 1);
            }
        }
        return tempo;
    }

    public double calculoCalorias() {
        double calorias = 0;

        calorias = getHorasTotaisDeTreino() * 500;

        // setCaloriasTotais(getCaloriasTotais() + calorias);

        // return calorias;
        
        for (int i = 0; i < getCaloriasDiarias().length; i++) {
            if (getCaloriasDiarias()[i] == 0.0) {
                getCaloriasDiarias()[i] = calorias;
            }
        }

        return calorias;
    }


}
