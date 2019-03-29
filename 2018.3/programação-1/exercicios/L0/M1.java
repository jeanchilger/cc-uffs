import java.util.Scanner;

class M1 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Autor a = new Autor();
        a.nome = s.nextLine();
        a.id = s.nextInt();
    }
}
