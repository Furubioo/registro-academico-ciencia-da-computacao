package SistemaHospitalar;

public class Medico extends ProfissionalSaude implements Agendavel{
    private String[] pacientes;
    private int[] horariosOcupados;
    private int totalConsultas;

    public Medico(String nome, String crm, String especialidade, double valorConsulta, String[] pacientes,
            int[] horariosOcupados, int totalConsultas) {
        super(nome, crm, especialidade, valorConsulta);
        this.pacientes = pacientes;
        this.horariosOcupados = horariosOcupados;
        this.totalConsultas = totalConsultas;
    }

    public String[] getPacientes() {
        return pacientes;
    }
    public void setPacientes(String[] pacientes) {
        this.pacientes = pacientes;
    }
    public int[] getHorariosOcupados() {
        return horariosOcupados;
    }
    public void setHorariosOcupados(int[] horariosOcupados) {
        this.horariosOcupados = horariosOcupados;
    }
    public int getTotalConsultas() {
        return totalConsultas;
    }
    public void setTotalConsultas(int totalConsultas) {
        this.totalConsultas = totalConsultas;
    }

    public void calcularHonorarios() {
        double honorarios;
        honorarios = (getValorConsulta() * getTotalConsultas() * 0.7);
        System.out.println("Honorários do médico: "+honorarios);
    }

    public void agendarConsulta(int horario, String paciente) throws AgendamentoInvalidoException{
        if (horario < 7 || horario > 20) {
            throw new AgendamentoInvalidoException("Este horário está fora do expediente!");
        }
        for (int i = 0; i < getHorariosOcupados().length; i++) {
            if (getHorariosOcupados()[i] == horario) {
                throw new AgendamentoInvalidoException("Este horário já está ocupado!");
            }
        }
        for (int i = 0; i < getHorariosOcupados().length; i++) {
            if (getHorariosOcupados()[i] == 0 && getPacientes()[i] == null) {
                getHorariosOcupados()[i] = horario;
                getPacientes()[i] = paciente;
                break;
            }
        }
    }

    public void cancelarConsulta(int horario, String paciente) {
        for (int i = 0; i < getHorariosOcupados().length; i++) {
            if (getHorariosOcupados()[i] == horario && getPacientes()[i] == paciente) {
                getHorariosOcupados()[i] = 0;
                getPacientes()[i] = null;
            }
        }
    }

    public boolean verificarDisponibilidade(int horario) {
        boolean ocupado = true;
        if (horario < 7 || horario > 20) {
            ocupado = false;
        }
        for (int i = 0; i < getHorariosOcupados().length; i++) {
            if (getHorariosOcupados()[i] == horario) {
                ocupado = false;
                break;
            }
        }
        return ocupado;
    }

    public void listarPacientes() {
        for (int i = 0; i < getHorariosOcupados().length; i++) {
            System.out.printf("Paciente %d: %s\n", i, getPacientes()[i]);
            System.out.printf("Horário: %d\n\n", getHorariosOcupados()[i]);
        }
    }
}
