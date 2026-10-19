package SistemaDeStreaming;

public class ContaPremium extends ContaUsuario implements Reproduzivel, Gerenciavel{
    private String[] fila;
    private int[][] estatisticas;
    private int totalFaixas;
    private int indiceAtual;
    private int skipsUsadosNaHora;

    public ContaPremium(String nomeUsuario, String email, String plano, int limiteSkipsPorHora, String[] fila,
            int[][] estatisticas, int totalFaixas, int indiceAtual, int skipsUsadosNaHora) {
        super(nomeUsuario, email, plano, limiteSkipsPorHora);
        this.fila = fila;
        this.estatisticas = estatisticas;
        this.totalFaixas = totalFaixas;
        this.indiceAtual = indiceAtual;
        this.skipsUsadosNaHora = skipsUsadosNaHora;
    }

    public String[] getFila() {
        return fila;
    }
    public void setFila(String[] fila) {
        this.fila = fila;
    }
    public int[][] getEstatisticas() {
        return estatisticas;
    }
    public void setEstatisticas(int[][] estatisticas) {
        this.estatisticas = estatisticas;
    }
    public int getTotalFaixas() {
        return totalFaixas;
    }
    public void setTotalFaixas(int totalFaixas) {
        this.totalFaixas = totalFaixas;
    }
    public int getIndiceAtual() {
        return indiceAtual;
    }
    public void setIndiceAtual(int indiceAtual) {
        this.indiceAtual = indiceAtual;
    }
    public int getSkipsUsadosNaHora() {
        return skipsUsadosNaHora;
    }
    public void setSkipsUsadosNaHora(int skipsUsadosNaHora) {
        this.skipsUsadosNaHora = skipsUsadosNaHora;
    }

    public double calcularCustoMensal() {
        double resultado = 0.0;
        if (getPlano().equalsIgnoreCase("Básico")) {
            resultado = 15;
        }
        else if (getPlano().equalsIgnoreCase("Premium")) {
            resultado = 25;
        }
        else if (getPlano().equalsIgnoreCase("Família")) {
            resultado = 35;
        }
        return resultado;
    }

    public void reproduzir(int indice) throws FaixaInvalidaException{
        int v = 0;
        for (int i = 0; i < getFila().length; i++) {
            if (getFila()[i] != null) {
                v = 1;
                break;
            }
        }
        if (v == 0) {
            throw new FaixaInvalidaException("A fila está vazia!!");
        }
        else if (indice < 0 || indice >= getFila().length) {
            throw new FaixaInvalidaException("Numeração inválida para a música!");
        }
        setIndiceAtual(indice);
        System.out.printf("Faixa sendo tocada: %s \n", getFila()[indice]);

        getEstatisticas()[indice][0] += 1;
    }   

    public void avancarFaixa() throws FaixaInvalidaException{
        int circular = 0;
        if (getSkipsUsadosNaHora() > getLimiteSkipsPorHora()) {
            throw new FaixaInvalidaException("O limite de skips foi excedido!");
        }
        circular = getIndiceAtual() % getTotalFaixas() + 1;
        if (circular == 1) {
            circular = 0;
        }
        reproduzir(circular);
    }

    public void adicionarFaixa(String faixa) throws FaixaInvalidaException{
        for (int i = 0; i < getFila().length; i++) {
            if (faixa == getFila()[i]) {
                throw new FaixaInvalidaException("A faixa já está presente na fila!");
            }
        }
        if (getFila()[getFila().length - 1] != null) {
            throw new FaixaInvalidaException("A fila está cheia!!");
        }
        for (int i = 0; i < getFila().length; i++) {
            if (getFila()[i] == null) {
                getFila()[i] = faixa;
                break;
            }
        }
    }

    public void exportarEstatisticas() {
        System.out.println("Faixa | Reproduções | Skips");
        for (int i = 0; i < getTotalFaixas(); i++) {
            System.out.printf("%s | %d | %d \n", fila[i], estatisticas[i][0], estatisticas[i][1]);
        }
    }

    public void resetarSkips() {
        setSkipsUsadosNaHora(0);
    }
}
