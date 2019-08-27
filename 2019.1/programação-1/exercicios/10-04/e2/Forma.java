class Forma {

    private int x;
    private int y;

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }

    public void imprime() {
        System.out.println("(" + this.x + ", " + this.y + ")");
    }
}
