package AcademiaPorMetas;

public interface Monitoravel {
    abstract void registrarSessao(int minutos) throws MetaInvalidaException;
    abstract void calcularIndicador();
}
