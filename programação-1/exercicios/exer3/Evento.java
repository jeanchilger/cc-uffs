class Evento {

    private int id;
    private Data[] encontros;
    
    public Evento() {
        this.encontros = new Data[256];
    }

    public void setId(int i) {
        this.id = i;
    }

    public void setEncontro(Data d) {
        for(int i = 0; i < 256; i++) {
            if (encontros[i] == null) {
                encontros[i] = new Data();
                encontros[i] = d;
                return ;
            }
        }    
    }

    public int getId() {
        return this.id;
    }

    public Data[] getEncontros() {
        for (Data d: this.encontros) {
            System.out.println(d);
        }
        return this.encontros;
    }

}
