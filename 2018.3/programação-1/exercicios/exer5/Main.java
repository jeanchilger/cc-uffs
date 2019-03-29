import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        String s;
        System.out.print("Bota uma string: ");
        Scanner scan = new Scanner(System.in);

        s = scan.nextLine();

        for (int i = s.length() - 1; i >= 0; i--) {
            System.out.print(s.charAt(i));
        }

        System.out.println();

    }
}
