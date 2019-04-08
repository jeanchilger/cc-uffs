class Main {

    public static void main(String[] args) {
        Evento e = new Evento();
        Data a = new Data();
        a.dia = 12;
        e.setEncontro(a);
        Data b = new Data();
        b.mes = 12;

        e.setEncontro(b);
        e.getEncontros();
    }
}
