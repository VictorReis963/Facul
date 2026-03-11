package aula2.ex1;

public class Teste {
    public static void main(String [] args){

        
        Carro x = new Carro();

        x.setCategoria("sedan");
        x.setAno(2001);
        x.setModelo("civic");
        x.setMarca("Honda");

        Carro y = new Carro();
        y.setMarca("toyota");
        y.setModelo("RAV4");
        y.setCategoria("SUV");
        y.setAno(2015);

        x.show();
        y.show();



    }

}