class Compra {
    
    private String nomeProduto;
    private float preco;
    private int quantidade;
    
    public Compra(String produto, float preco, int quantidade) {
        this.nomeProduto = produto;
        this.preco = preco;
        this.quantidade = quantidade;
    }

    public void setNomeProduto(String novo) {
        this.nomeProduto = novo;
    }

    public String getNomeProduto() {
        return this.nomeProduto;
    }

    public void setPreço(float preco) {
        this.preco = preco;
    }

    public float getPreco() {
        return this.preco;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public int getQuantidade() {
        return this.quantidade;
    }

    // Imprime todas as propriedades da classe
    public void imprimeResumo() {
        System.out.println("Nome do Produto: " + this.nomeProduto);
        System.out.println("Preço: " + this.preco);
        System.out.println("Quantidade: " + this.quantidade);
    }

}
