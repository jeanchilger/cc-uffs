import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        int d, m;
        Scanner s = new Scanner(System.in);
        System.out.print("Dia: ");
        d = s.nextInt();
        System.out.print("Mes: ");
        m = s.nextInt();

        Data a = new Data(d, m);

        a.imprime();
        System.out.println(a.media());


    }
}
