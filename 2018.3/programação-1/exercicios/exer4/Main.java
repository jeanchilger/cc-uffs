import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        String a;
        Scanner scan = new Scanner(System.in);
        a = scan.nextLine();

        if (a.length() < 5) {
            System.out.println("Erro troxão");

        } else {
            System.out.println("4°: " + a.substring(3, 4) + " 5°: " + a.substring(4, 5));
        }

    }
}
