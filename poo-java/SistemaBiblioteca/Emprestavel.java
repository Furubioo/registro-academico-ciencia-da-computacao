package SistemaBiblioteca;

public interface Emprestavel {
   void realizarEmprestimo(int diasEmprestimo) throws PrazoInvalidoException;
}
