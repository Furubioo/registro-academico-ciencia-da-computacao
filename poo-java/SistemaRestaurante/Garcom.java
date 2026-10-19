package SistemaRestaurante;

public class Garcom extends ColaboradorRestaurante implements Atendivel{
    private int[] mesasAtendidas;
    private String[] pedidosAtivos;
    private int totalPedidosRealizados;

    public Garcom(String nome, String cpf, String cargo, double salarioBase, int[] mesasAtendidas,
            String[] pedidosAtivos, int totalPedidosRealizados) {
        super(nome, cpf, cargo, salarioBase);
        this.mesasAtendidas = mesasAtendidas;
        this.pedidosAtivos = pedidosAtivos;
        this.totalPedidosRealizados = totalPedidosRealizados;
    }

    public int[] getMesasAtendidas() {
        return mesasAtendidas;
    }
    public void setMesasAtendidas(int[] mesasAtendidas) {
        this.mesasAtendidas = mesasAtendidas;
    }
    public String[] getPedidosAtivos() {
        return pedidosAtivos;
    }
    public void setPedidosAtivos(String[] pedidosAtivos) {
        this.pedidosAtivos = pedidosAtivos;
    }
    public int getTotalPedidosRealizados() {
        return totalPedidosRealizados;
    }
    public void setTotalPedidosRealizados(int totalPedidosRealizados) {
        this.totalPedidosRealizados = totalPedidosRealizados;
    }

    public void calcularSalario() {
        double salario = 0.0;
        salario = getSalarioBase() + (getTotalPedidosRealizados() * 2.50);
        System.out.println("Salário: "+salario);
    }

    public void registrarPedido(int numeroMesa, String pedido) throws PedidoInvalidoException{
        int cont = 0;
        if (numeroMesa < 1 || numeroMesa > 20) {
            throw new PedidoInvalidoException("Número de mesa inválido!");
        }
        for (int i = 0; i < getMesasAtendidas().length; i++) {
            if (getMesasAtendidas()[i] == numeroMesa) {
                cont++;
                break;
            }
        }
        if (cont == 1) {
            throw new PedidoInvalidoException("Essa mesa já foi reservada!");
        }
        for (int i = 0; i < getPedidosAtivos().length; i++) {
            if (getPedidosAtivos()[i] == null) {
                getPedidosAtivos()[i] = pedido;
                break;
            }
        }
    }

    public void cancelarPedido(String pedido) {
        for (int i = 0; i < getPedidosAtivos().length; i++) {
            if (getPedidosAtivos()[i] == pedido) {
                getPedidosAtivos()[i] = null;
                for (int j = i; j < getPedidosAtivos().length; j++) {
                    getPedidosAtivos()[j] = getPedidosAtivos()[j+1];
                }
                getPedidosAtivos()[getPedidosAtivos().length - 1] = null;
            }
        }
    }

    public void atribuirMesa(int mesa) {
        if (getMesasAtendidas()[getMesasAtendidas().length - 1] != 0) {
            System.out.println("Todas as mesas estão ocupadas!");
            return;
        }
        for (int i = 0; i < getMesasAtendidas().length; i++) {
            if (getMesasAtendidas()[i] == 0) {
                getMesasAtendidas()[i] = mesa;
                break;
            }
        }
    }

    public void finalizarAtendimento(int mesa) {
        for (int i = 0; i < getMesasAtendidas().length; i++) {
            if (getMesasAtendidas()[i] == mesa) {
                getMesasAtendidas()[i] = 0;
                break;
            }
        }
        setTotalPedidosRealizados(getTotalPedidosRealizados() + 1);
        System.out.println("Atendimento finalizado!\n");
    }

}
