package SistemaRestaurante;

public interface Atendivel {
    void registrarPedido(int numeroMesa, String pedido) throws PedidoInvalidoException;
    void cancelarPedido(String pedido);
}
