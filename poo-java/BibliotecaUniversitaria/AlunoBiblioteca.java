package BibliotecaUniversitaria;

public class AlunoBiblioteca extends PessoaBiblioteca implements Emprestavel {
    private boolean acervoDisponivel[][];
    private int emprestimosAtivos;
    private int[] diasDeAtraso;
    private double multaAtual;
    private int diasEmprestados;

    public AlunoBiblioteca(String matricula, String nome, String categoria, int limiteEmprestimos,
            boolean[][] acervoDisponivel, int emprestimosAtivos, int[] diasDeAtraso, double multaAtual, int diasEmprestados) {
        super(matricula, nome, categoria, limiteEmprestimos);
        this.acervoDisponivel = acervoDisponivel;
        this.emprestimosAtivos = emprestimosAtivos;
        this.diasDeAtraso = diasDeAtraso;
        this.multaAtual = multaAtual;
        this.diasEmprestados = diasEmprestados;
    }

    public int getDiasEmprestados() {
        return diasEmprestados;
    }

    public void setDiasEmprestados(int diasEmprestados) {
        this.diasEmprestados = diasEmprestados;
    }

    public boolean[][] getAcervoDisponivel() {
        return acervoDisponivel;
    }
    public void setAcervoDisponivel(boolean[][] acervoDisponivel) {
        this.acervoDisponivel = acervoDisponivel;
    }
    public int getEmprestimosAtivos() {
        return emprestimosAtivos;
    }
    public void setEmprestimosAtivos(int emprestimosAtivos) {
        this.emprestimosAtivos = emprestimosAtivos;
    }
    public int[] getDiasDeAtraso() {
        return diasDeAtraso;
    }
    public void setDiasDeAtraso(int[] diasDeAtraso) {
        this.diasDeAtraso = diasDeAtraso;
    }
    public double getMultaAtual() {
        return multaAtual;
    }
    public void setMultaAtual(double multaAtual) {
        this.multaAtual = multaAtual;
    }

    public int calcularPrazoPadrao() {
        int prazoPadrao = 0;
        if (getCategoria().equalsIgnoreCase("Graduação")) {
            prazoPadrao = 7;
        }
        else if (getCategoria().equalsIgnoreCase("Pós")) {
            prazoPadrao = 14;
        }
        else if (getCategoria().equalsIgnoreCase("Monitoria")) {
            prazoPadrao = 21;
        }
        return prazoPadrao;
    }

    public void registrarEmprestimo(int linha, int coluna, int dias) throws EmprestimoInvalidoException{
        if (getAcervoDisponivel()[linha][coluna] == false) {
            getAcervoDisponivel()[linha][coluna] = true;
            setEmprestimosAtivos(getEmprestimosAtivos() + 1);
            setDiasEmprestados(dias);
        }
        else if (getEmprestimosAtivos() > getLimiteEmprestimos()) {
            throw new EmprestimoInvalidoException("O limite de empréstimos foi ultrapassado!");
        }
        else if (dias < 0) {
            throw new EmprestimoInvalidoException("Os dias informados são inválidos!");
        }
        else if (linha > getAcervoDisponivel().length || coluna > getAcervoDisponivel()[linha].length) {
            throw new EmprestimoInvalidoException("Esta posição do acervo não existe.");
        }
        
    }

    public double calcularMulta() {
        double multa = 0;
        int dias = 0;
        for (int i = 0; i < getDiasDeAtraso().length; i++) {
            dias += getDiasDeAtraso()[i];
        }
        multa = dias * 2.50;
        if (getCategoria().equalsIgnoreCase("Monitoria")) {
            multa = multa - (0.3 * multa);
        }

        return multa;
    }
}
