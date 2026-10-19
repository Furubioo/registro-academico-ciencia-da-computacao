package SistemaHospitalar;

public interface Agendavel {
    void agendarConsulta(int horario, String paciente) throws AgendamentoInvalidoException;
    void cancelarConsulta(int horario, String paciente);
}
