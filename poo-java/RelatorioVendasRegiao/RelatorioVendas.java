package RelatorioVendasRegiao;

public class RelatorioVendas implements Analisavel{
    private String[] regioes;
    private String[] meses;
    private double[][] vendas;

    public RelatorioVendas(String[] regioes, String[] meses, double[][] vendas) {
        this.regioes = regioes;
        this.meses = meses;
        this.vendas = vendas;
    }

    public String[] getRegioes() {
        return regioes;
    }
    public void setRegioes(String[] regioes) {
        this.regioes = regioes;
    }
    public String[] getMeses() {
        return meses;
    }
    public void setMeses(String[] meses) {
        this.meses = meses;
    }
    public double[][] getVendas() {
        return vendas;
    }
    public void setVendas(double[][] vendas) {
        this.vendas = vendas;
    }

    public int melhorMes() {
        int melhorMes = 0;
        double maiorVenda = getVendas()[0][0];
        for (int i = 0; i < getVendas().length; i++) {
            for (int j = 0; j < getVendas()[i].length; j++) {
                if (maiorVenda < getVendas()[i][j]) {
                    maiorVenda = getVendas()[i][j];
                    melhorMes = j;
                }
            }
        }
        return melhorMes;
    }

    public int melhorRegiao() {
        int melhorRegiao = 0;
        double maiorVenda = getVendas()[0][0];
        for (int i = 0; i < getVendas().length; i++) {
            for (int j = 0; j < getVendas()[i].length; j++) {
                if (maiorVenda < getVendas()[i][j]) {
                    maiorVenda = getVendas()[i][j];
                    melhorRegiao = i;
                }
            }
        }
        return melhorRegiao;
    }

    public double totalGeral() {
        double soma = 0;
        for (int i = 0; i < getVendas().length; i++) {
            for (int j = 0; j < getVendas()[i].length; j++) {
                soma += getVendas()[i][j];
            }
        }
        return soma;
    }

    public void exibirRelatorio() {
        System.out.println("Melhor mês: "+getMeses()[melhorMes() + 1]);
        System.out.println("Melhor região: "+getRegioes()[melhorRegiao()]);
        System.out.println("Total geral de vendas: "+totalGeral());
    }


}
