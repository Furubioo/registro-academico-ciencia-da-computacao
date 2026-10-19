package EstacionamentoInteligente;

public abstract class ClienteEstacionamento {
    private String placa;
    private String nome;
    private String tipoCliente;
    private double saldo;

    public ClienteEstacionamento(String placa, String nome, String tipoCliente, double saldo) {
        this.placa = placa;
        this.nome = nome;
        this.tipoCliente = tipoCliente;
        this.saldo = saldo;
    }

    public String getPlaca() {
        return placa;
    }
    public void setPlaca(String placa) {
        this.placa = placa;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getTipoCliente() {
        return tipoCliente;
    }
    public void setTipoCliente(String tipoCliente) {
        this.tipoCliente = tipoCliente;
    }
    public double getSaldo() {
        return saldo;
    }
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    abstract boolean validarCadastro();

}
