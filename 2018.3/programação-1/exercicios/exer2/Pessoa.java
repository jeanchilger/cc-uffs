class Pessoa {

    public int id;
        public String nome;
    public Data nascimento;

    public Pessoa() {

    }

    public Pessoa(int id, String nome) {
        this.id = id;
        this.nome = nome;
    }

    public void setId(int i) {
        this.id = i;
    }

    public void setNome(String n) {
        this.nome = n;
    }

    public int getId() {
        return this.id;
    }

    public String getNome() {
        return this.nome;
    }
}
