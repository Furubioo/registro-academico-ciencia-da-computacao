package VeiculosETiposDeMotor;

public class Main {
    public static void main(String[] args) {
        Carro c1 = new Carro("Mercedes", "C300", 280, 8);
        Caminhao c2 = new Caminhao("Caio", "Jk", 120, 10);
        Moto m1 = new Moto("Honda", "NB800", 200, 6);

        System.out.println("Dados dos veículos: ");
        System.out.println("Carro: ");
        c1.exibirDados();
        System.out.println("Caminhão: ");
        c2.exibirDados();
        System.out.println("Moto: ");
        m1.exibirDados();

        System.out.println("Autonomia de cada veículo com 50L: ");
        System.out.println("Carro: "+c1.calcularAutonomia(50)+ "km");
        System.out.println("Caminhão: "+c2.calcularAutonomia(50)+ "km");
        System.out.println("Moto: "+m1.calcularAutonomia(50)+ "km");
    }
}
