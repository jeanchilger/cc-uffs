import java.util.Random;

class Main {

    public static void main(String[] args) {
        Dicionario dict = new Dicionario();
        Variavel[] vars = new Variavel[12];
        Random gen = new Random();

        for (int i = 0; i < 12; i++) {
            vars[i] = new Variavel();
            (vars[i]).setValor(gen.nextDouble());
            (vars[i]).setNome(String.valueOf(gen.nextInt(150)));
        }

        dict.setVariaveis(vars);
        Variavel[] a = dict.getVariaveis();

        for (Variavel v : a) {
            System.out.println("NOME: " + v.getNome());
            System.out.println("VALOR: " + v.getValor());
            System.out.println();
        }

        System.out.println("SEARCH FOR 75: " + dict.busca("75"));
        
    }
}
