package InterfaceImprimivel;

public class NotaFiscal implements Imprimivel{
    private int numero;
    private double valor;
    private String cliente;

    public NotaFiscal(int numero, double valor, String cliente) {
        this.numero = numero;
        this.valor = valor;
        this.cliente = cliente;
    }

    public int getNumero() {
        return numero;
    }
    public void setNumero(int numero) {
        this.numero = numero;
    }
    public double getValor() {
        return valor;
    }
    public void setValor(double valor) {
        this.valor = valor;
    }
    public String getCliente() {
        return cliente;
    }
    public void setCliente(String cliente) {
        this.cliente = cliente;
    }

    public void imprimir() {
        System.out.println("Número: "+getNumero()+"\nValor da nota fiscal: "+getValor()+"\nNome do cliente: "+getCliente()+ "\n");
    }
    
}
