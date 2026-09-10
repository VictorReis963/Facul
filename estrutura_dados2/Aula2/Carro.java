public class Carro {
// Atributos (Estado)
String marca;
String modelo;
int velocidadeAtual;
// Construtor
public Carro(String marca , String modelo) {
this.marca = marca;
this.modelo = modelo;
this.velocidadeAtual = 0;
}
// Metodos (Comportamento)
public void acelerar(int incremento) {
this.velocidadeAtual += incremento;
System.out.println("Velocidade: " + this.velocidadeAtual);
}

public void setMarca(String novo){
    this.marca=novo;
}
public String getMarca(){
    return this.marca;
}

public void setModelo(String novo){
    this.modelo=novo;
}
public String getModelo(){
    return this.modelo;
}

public void setVelocidadeAtual(int acc){
    this.velocidadeAtual+=acc;
}
public int getVelocidadeAtual(){
    return this.velocidadeAtual;
}
}