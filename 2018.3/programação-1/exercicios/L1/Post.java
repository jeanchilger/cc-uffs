class Post{

    private Autor autor;
    private String texto;

    public void setAutor(Autor autor) {
        this.autor = autor;
    }

    public Autor getAutor() {
        return this.autor;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    public String getTexto() {
        return this.texto;
    }

    // Imprime todas as propriedades da classe no formato:
    public void imprimeResumo() {
        System.out.println("Autor: " + this.autor.toString());
        System.out.println("Texto: " + this.texto);
    }
}
