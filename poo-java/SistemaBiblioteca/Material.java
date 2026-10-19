package SistemaBiblioteca;

public abstract class Material {
    private String titulo;
    private String codigo;
    private int diasEmprestado = 0;
    
    public Material(String titulo, String codigo) {
        this.titulo = titulo;
        this.codigo = codigo;
    }

    public String getTitulo() {
        return titulo;
    }
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    public String getCodigo() {
        return codigo;
    }
    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }
    public int getDiasEmprestado() {
        return diasEmprestado;
    }
    public void setDiasEmprestado(int diasEmprestado) {
        this.diasEmprestado = diasEmprestado;
    }

    abstract double calcularMulta();
}
