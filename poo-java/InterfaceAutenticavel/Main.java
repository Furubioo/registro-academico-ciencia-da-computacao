package InterfaceAutenticavel;

public class Main {
    public static void main(String[] args) {
        boolean r1;
        UsuarioSistema u1 = new UsuarioSistema("Junior", "12345678", "JuniorAlmeida@gmail.com");
        Administrador a1 = new Administrador("Alessandro", "9102", "Prata");

        r1 = u1.autenticar("1234567");
        if (r1 == true) {
            System.out.println("Login realizado com sucesso!");
        }
        else {
            System.out.println("Login inválido!");
        }
        r1 = a1.autenticar("9101");
        if (r1 == true) {
            System.out.println("Login realizado com sucesso!");
        }
        else {
            System.out.println("Login inválido!");
        }
    }
}
