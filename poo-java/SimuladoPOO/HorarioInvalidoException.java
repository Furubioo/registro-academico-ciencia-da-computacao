package SimuladoPOO;

public class HorarioInvalidoException extends Exception{
    public HorarioInvalidoException() {
        super("O horário fornecido está inválido!");
    }
}
