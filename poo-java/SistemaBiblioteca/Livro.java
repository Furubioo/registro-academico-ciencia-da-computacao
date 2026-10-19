package SistemaBiblioteca;

public class Livro extends Material implements Emprestavel{
    private String autor;

    public Livro(String titulo, String codigo, String autor) {
        super(titulo, codigo);
        this.autor = autor;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public void realizarEmprestimo(int diasEmprestimo) throws PrazoInvalidoException {
        if (diasEmprestimo > 30 || diasEmprestimo < 1) {
            throw new PrazoInvalidoException(diasEmprestimo);
        }
        else {
            System.out.println("O livro será emprestado por "+diasEmprestimo+" dias.");
            setDiasEmprestado(diasEmprestimo);
        }   
    }

    public double calcularMulta() {
        if (30 - getDiasEmprestado() >= 1 && 30 - getDiasEmprestado() <= 5) {
            return 1.0;
        }
        else if (30 - getDiasEmprestado() >= 6 && 30 - getDiasEmprestado() <= 15) {
            return 2;
        }
        else if (30 - getDiasEmprestado() >= 15) {
            return 3.50;
        }
        return 0;
    }
}
