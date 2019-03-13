class Main {
    public static void main(String args[]) {
        Pessoa p = new Pessoa();
        p.idade = 46;
        p.anoNascimento = 2019 - 46;
        p.altura = 1.98;

        System.out.println("I: " + p.idade + "\nN: " + p.anoNascimento + "\nA: " + p.altura);
    }
}
