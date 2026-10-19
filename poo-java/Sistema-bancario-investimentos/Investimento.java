package Exercicio9;

public class Investimento extends Conta{
    private String risco;


    public Investimento(String agencia, String numconta, double saldo, String risco) {
        super(agencia, numconta, saldo);
        this.risco = risco;
    }


    public String getRisco() {
        return risco;
    }

    public void setRisco(String risco) {
        this.risco = risco;
    }


    public void Investir(int numero) {

        if (risco.equals("baixo") && numero <= 85) {
            setSaldo(getSaldo() + getSaldo() * 0.025);
        }
        else if (risco.equals("baixo") && numero > 85){
            setSaldo(getSaldo() - getSaldo() * 0.025);
        }

        if (risco.equals("medio") && numero <= 45) {
            setSaldo(getSaldo() + getSaldo() * 0.30);
        }
        else if(risco.equals("medio") && numero > 45) {
            setSaldo(getSaldo() - getSaldo() * 0.30);
        }

        if (risco.equals("alto") && numero <= 2) {
            setSaldo(getSaldo() + getSaldo() * 1);
        }
        else if(risco.equals("alto") && numero > 2) {
            setSaldo(getSaldo() - getSaldo() * 1);
        }
    }

    public void Investir(int numero, double lucro) {
        
        if (risco.equals("baixo") && numero <= 85) {
            lucro = getSaldo() * 0.025;
            System.out.println("Lucro do investimento: "+lucro);
        }
        else if (risco.equals("baixo") && numero > 85){
            System.out.println("Não houve lucro.");
        }

        if (risco.equals("medio") && numero <= 45) {
            lucro = getSaldo() * 0.30;
            System.out.println("Lucro do investimento: "+lucro);
        }
        else if(risco.equals("medio") && numero > 45) {
            System.out.println("Não houve lucro.");
        }

        if (risco.equals("alto") && numero <= 2) {
            lucro = getSaldo() * 1;
            System.out.println("Lucro do investimento: "+lucro);
        }
        else if(risco.equals("alto") && numero > 2) {
            System.out.println("Não houve lucro.");
        }

    }
}
