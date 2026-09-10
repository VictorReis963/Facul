

class jarvas{
    public static void main(String[] args){
        Carro veic = new Carro("Toyota","delicia 8000");

        veic.getVelocidadeAtual();
        veic.acelerar(5);
        veic.getMarca();
        veic.getModelo();
        veic.setMarca("tesla");
        veic.setModelo("calma calabreso");
        veic.acelerar(100);
        veic.getVelocidadeAtual();
        
    }
}