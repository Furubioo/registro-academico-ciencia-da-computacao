package AcademiaPorMetas;

public class AlunoPremium extends UsuarioFitness implements Monitoravel{
    private int[] minutosPorDia;
    private int totalMinutos;
    private double caloriasEstimadas;
    private int limitePremium;

    public AlunoPremium(String login, String senha, String plano, int metaSemanal, int[] minutosPorDia,
            int totalMinutos, double caloriasEstimadas, int limitePremium) {
        super(login, senha, plano, metaSemanal);
        this.minutosPorDia = minutosPorDia;
        this.totalMinutos = totalMinutos;
        this.caloriasEstimadas = caloriasEstimadas;
        this.limitePremium = limitePremium;
    }

    public int getLimitePremium() {
        return limitePremium;
    }

    public int[] getMinutosPorDia() {
        return minutosPorDia;
    }
    public void setMinutosPorDia(int[] minutosPorDia) {
        this.minutosPorDia = minutosPorDia;
    }
    public int getTotalMinutos() {
        return totalMinutos;
    }
    public void setTotalMinutos(int totalMinutos) {
        this.totalMinutos = totalMinutos;
    }
    public double getCaloriasEstimadas() {
        return caloriasEstimadas;
    }
    public void setCaloriasEstimadas(double caloriasEstimadas) {
        this.caloriasEstimadas = caloriasEstimadas;
    }

    public double calcularCobranca() {
        double valorASerPago = 0;
        if (getPlano().equalsIgnoreCase("Básico")) {
            valorASerPago = 120;
        }
        else if (getPlano().equalsIgnoreCase("Plus")) {
            valorASerPago = 170;
        }
        else if (getPlano().equalsIgnoreCase("Premium")) {
            valorASerPago = 230;
        }
        else if (getTotalMinutos() >= getMetaSemanal()) {
            valorASerPago = valorASerPago - valorASerPago * 0.15;
        }
        return valorASerPago;
        
    }

    public void registrarSessao(int minutos) throws MetaInvalidaException {
        
        if (minutos <= 0) {
            throw new MetaInvalidaException("O valor informado é negativo ou zero!\n");
        }
        else if (minutos > getLimitePremium()) {
            throw new MetaInvalidaException("Minutos informados acima do limite diário!\n");
        }
        else if (getTotalMinutos() < getMetaSemanal()) {
            throw new MetaInvalidaException("A meta semanal excedeu o plano. \n");
        }

        
        for (int i = 0; i < getMinutosPorDia().length; i++) {
            if (getMinutosPorDia()[i] == 0) {
                getMinutosPorDia()[i] = minutos;
                setTotalMinutos(getTotalMinutos() + minutos);
            }
        }
    
    }

    public void calcularIndicador() {
        setCaloriasEstimadas(getTotalMinutos() * 8);
    }


}
