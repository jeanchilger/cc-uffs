class Data {
    public int dia;
    public int mes;

    public Data(int dia, int mes) {
        this.dia = dia;
        this.mes = mes;

    }

    public void imprime() {

        System.out.println(this.dia + "/" + this.mes);
    }

    public double media() {
        return (double)(this.dia + this.mes) / 2;
    }

}
