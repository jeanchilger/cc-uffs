class Retangulo {

    private double altura;
    private double largura;
    private int idade;

    public Retangulo() {

    }

    public Retangulo(double altura, double largura) {
        this.setAltura(altura);
        this.setLargura(largura);
        this.setIdade(0);
    }

    public Retangulo(double altura, double largura, int idade) {
        this.setAltura(altura);
        this.setLargura(largura);
        this.setIdade(idade);
    }

    public double getAltura() {
        return this.altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double getLargura() {
        return this.largura;
    }

    public void setLargura(double largura) {
        this.largura = largura;
    }

    public int getIdade() {
        return this.idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String toString() {
        return "Altura: " + this.altura + "\nLargura: " + this.largura + "\nIdade: " + this.idade;
    }
}
