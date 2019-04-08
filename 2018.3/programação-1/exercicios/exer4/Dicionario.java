class Dicionario {

    private Variavel[] variaveis;
//    private int size = 128;

    public Dicionario() {
       // variaveis = new Variavel[this.size];
    }

    public Variavel busca(String n) {
        for (Variavel v : this.variaveis) {
            if (v.getNome().equals(n)) {
                return v;
            }
        }

        return null;
    }
    
   /* public void setVariavel(Variavel v) {
        for(int i = 0; i < this.size; i++) {
            if (variaveis[i] == null) {
                variaveis[i] = new Variavel();
                variaveis[i] = v;
                return ;
            }
        }
    }*/

    public void setVariaveis(Variavel[] vs) {
        this.variaveis = vs;
    }

    public Variavel[] getVariaveis() {
        return this.variaveis;
    }

} 
