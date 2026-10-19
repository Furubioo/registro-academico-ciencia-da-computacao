package PlataformaDeEntregas;

public class EntregadorApp extends Entregador implements Roteirizavel {
    private int[][] entregasPorRegiao;
    private double distanciaTotal;
    private int tempoTotal;
    private double bonus;

    public EntregadorApp(String id, String nome, String modalidade, double avaliacaoMedia, int[][] entregasPorRegiao,
            double distanciaTotal, int tempoTotal, double bonus) {
        super(id, nome, modalidade, avaliacaoMedia);
        this.entregasPorRegiao = entregasPorRegiao;
        this.distanciaTotal = distanciaTotal;
        this.tempoTotal = tempoTotal;
        this.bonus = bonus;
    }

    public int[][] getEntregasPorRegiao() {
        return entregasPorRegiao;
    }
    public void setEntregasPorRegiao(int[][] entregasPorRegiao) {
        this.entregasPorRegiao = entregasPorRegiao;
    }
    public double getDistanciaTotal() {
        return distanciaTotal;
    }
    public void setDistanciaTotal(double distanciaTotal) {
        this.distanciaTotal = distanciaTotal;
    }
    public int getTempoTotal() {
        return tempoTotal;
    }
    public void setTempoTotal(int tempoTotal) {
        this.tempoTotal = tempoTotal;
    }
    public double getBonus() {
        return bonus;
    }
    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

    public double calcularPagamentoBase() {
        double valor = 0;
        if (getModalidade().equalsIgnoreCase("Bike")) {
            valor = getDistanciaTotal() * 1.50;
        }
        else if (getModalidade().equalsIgnoreCase("Moto")) {
            valor = getDistanciaTotal() * 2.30;
        }
        else if (getModalidade().equalsIgnoreCase("Carro")) {
            valor = getDistanciaTotal() * 3;
        }
        return valor;
    }

    public void registrarEntrega(int linha, int coluna, int tempo, int distancia, int avaliacao) throws EntregaInvalidaException {
 
        if (getEntregasPorRegiao()[linha][coluna] == 0) {
            getEntregasPorRegiao()[linha][coluna] = 1;
            setTempoTotal(getTempoTotal() + tempo);
            setDistanciaTotal(getDistanciaTotal() + distancia);
            setAvaliacaoMedia(getAvaliacaoMedia() + avaliacao);
        }

        if (getDistanciaTotal() < 0) {
            throw new EntregaInvalidaException("A distância é inválida!");
        }
        else if (getAvaliacaoMedia() < 0 || getAvaliacaoMedia() > 5) {
            throw new EntregaInvalidaException("A avaliação está fora da faixa permitida!");
        }
        else if (getDistanciaTotal() > 60) {
            throw new EntregaInvalidaException("Tempo limite de entrega excedido!");
        }
        else if (linha > getEntregasPorRegiao().length || 
        coluna > getEntregasPorRegiao()[linha].length) {
            throw new EntregaInvalidaException("A região informada não existe!");
        }


    }

    public double calcularDesempenho(double avaliacao, int tempo) {
        double soma = 0, media = 0;
        for (int i = 0; i < getEntregasPorRegiao().length; i++) {
            for (int j = 0; j < getEntregasPorRegiao()[i].length; j++) {
                soma += getEntregasPorRegiao()[i][j];
            }
        }
        media = getAvaliacaoMedia() / soma;

        if (avaliacao >= media && tempo < getTempoTotal()) {
            setBonus(calcularPagamentoBase() * 0.2);
        }
        return getBonus();
    }
    
}
