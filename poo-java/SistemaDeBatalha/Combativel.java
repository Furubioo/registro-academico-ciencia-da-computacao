package SistemaDeBatalha;

public interface Combativel {
    void atacar(int dano) throws AtaqueInvalidoException;
    int esquivar(int dano);
}
