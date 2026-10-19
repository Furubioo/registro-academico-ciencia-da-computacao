package InterfaceImprimivel;

public class Contrato implements Imprimivel{
    private String partes;
    private String vigencia;

    public Contrato(String partes, String vigencia) {
        this.partes = partes;
        this.vigencia = vigencia;
    }

    public String getPartes() {
        return partes;
    }
    public void setPartes(String partes) {
        this.partes = partes;
    }
    public String getVigencia() {
        return vigencia;
    }
    public void setVigencia(String vigencia) {
        this.vigencia = vigencia;
    }

    public void imprimir() {
        System.out.println("Partes: "+getPartes()+"\nVigência: "+getVigencia()+"\n");
    }


    
}
