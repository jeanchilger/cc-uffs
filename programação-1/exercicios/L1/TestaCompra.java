import java.util.Scanner;

class TestaCompra {

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        String n = scan.nextLine();
        float p = scan.nextFloat();
        int q = scan.nextInt();

        Compra c = new Compra(n, p, q);
        c.imprimeResumo();

    }

}
