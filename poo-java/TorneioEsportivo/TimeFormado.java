package TorneioEsportivo;

public class TimeFormado extends Equipe implements Competidor{
    private String[] jogadores;
    private int[][] resultados;
    private int totalPartidas;

    public TimeFormado(String nome, String sigla, String cidade, String tecnico, String[] jogadores, int[][] resultados,
            int totalPartidas) {
        super(nome, sigla, cidade, tecnico);
        this.jogadores = jogadores;
        this.resultados = resultados;
        this.totalPartidas = totalPartidas;
    }

    public String[] getJogadores() {
        return jogadores;
    }
    public void setJogadores(String[] jogadores) {
        this.jogadores = jogadores;
    }
    public int[][] getResultados() {
        return resultados;
    }
    public void setResultados(int[][] resultados) {
        this.resultados = resultados;
    }
    public int getTotalPartidas() {
        return totalPartidas;
    }
    public void setTotalPartidas(int totalPartidas) {
        this.totalPartidas = totalPartidas;
    }

    public void calcularDesempenho() {
        double result = 0;

        result = (calcularClassificacao() / getTotalPartidas() * 3) * 100;

        System.out.println("Aproveitamento percentual: "+result);
    }

    public void registrarResultado(int time1, int time2) throws ResultadoInvalidoException{
        int cont = 0;
        if (time1 < 0 || time2 < 0) {
            throw new ResultadoInvalidoException("Um dos placares está negativo!");
        }
        for (int i = 0; i < getResultados().length; i++) {
            for (int j = 0; j < getResultados()[i].length; j++) {
                if (getResultados()[i][j] != 0) {
                    cont++;
                }
                else if (cont == (getResultados().length) * (getResultados()[i].length)) {
                    throw new ResultadoInvalidoException("O registro de placares está esgotado");
                }      
            }
        }

        for (int i = 0; i < getResultados().length; i++) {
            for (int j = 0; j < getResultados()[i].length; j++) {
                if (getResultados()[i][j] == 0 && getResultados()[i][j+1] == 0) {
                    getResultados()[i][j] = time1;
                    getResultados()[i][j+1] = time2;
                }
            }
        }

        if (time1 > time2) {
            System.out.println("O time 1 venceu.");
        }
        else if (time2 > time1) {
            System.out.println("O time 2 venceu.");
        }
        else if (time1 == time2) {
            System.out.println("Houve um empate.");
        }
    }

    public int calcularClassificacao() {
        int pontos = 0;
        for (int i = 0; i < getResultados().length; i++) {
            for (int j = 0; j < getResultados()[i].length; j++) {
                if (getResultados()[i][j] > getResultados()[i][j + 1]) {
                    pontos += 3;
                }
                else if (getResultados()[i][j] == getResultados()[i][j+1]) {
                    pontos++;
                }
            }
        }
        return pontos;
    }

    public void adicionarJogador(String nome) {
        for (int i = 0; i < getJogadores().length; i++) {
            if (getJogadores()[i] == null) {
                getJogadores()[i] = nome;
                break;
            }
        }
        if (getJogadores()[getJogadores().length - 1] != null) {
            System.out.println("Não é mais possível adicionar jogadores.");
        }
    }

    public void listarResultados() {
        String resultado = null;
        for (int i = 0; i < getResultados().length; i++) {
            for (int j = 0; j < getResultados()[i].length; j++) {
                if (getResultados()[i][j] > getResultados()[i][j+1]) {
                    resultado = "V";
                }   
                else {
                    resultado = "D";
                }
                if (getResultados()[i][j] > getResultados()[i][j+1]) {
                    resultado = "E";
                }
                System.out.printf("Partida %d: [%d]:[%d] - %s\n\n", i, getResultados()[i][j],
                getResultados()[i][j+1], resultado);
            }
        }
    }

}
