package BibliotecaUniversitaria;

public interface Emprestavel {
    abstract void registrarEmprestimo(int linha, int coluna, int dias) throws EmprestimoInvalidoException;
    abstract double calcularMulta();
}
