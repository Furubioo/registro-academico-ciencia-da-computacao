package RpgPorTurnos;

public interface Combatente {
    void receberDano(int dano);
    void executarAcao(int dano, String habilidade, int linha, int coluna) throws AcaoInvalidaException;
}
