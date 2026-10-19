package SistemaRPG;

public interface Acoes {
    double atacar();
    void defender(double dano) throws NoDamageException;
}
