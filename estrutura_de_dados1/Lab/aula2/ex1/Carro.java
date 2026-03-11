package aula2.ex1;


public class Carro{
    private  String marca;
    private int ano;
    private String modelo;
    public String categoria;

    public  String getMarca(){
        return marca;

    }
    public void setMarca(String marca){
        this.marca = marca;
    } 

    public  String getModelo(){
        return modelo;

    }
    public void  setModelo(String modelo){
        this.modelo = modelo;
    } 

    public  String getCategoria(){
        return categoria;

    }
    public void setCategoria( String categoria){
        this.categoria = categoria;
    } 
    public  int getAno(){
        return ano;

    }
    public void setAno(int ano){
        this.ano = ano;
    } 

    public void show(){
        System.out.println("----------------------------------------");
        System.out.println ("marca: "+getMarca()+"\n");
        System.out.println ("modelo: "+getModelo()+"\n");
        System.out.println ("Categoria: "+ getCategoria()+"\n");
        System.out.println ("ano: "+getAno()+"\n");
        System.out.println("----------------------------------------");


    }
}