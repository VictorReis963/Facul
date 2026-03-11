package aula2.ex2;

public class Circulo {
    private float raio;

    public float getRaio(){
        return raio;
    }

    public void setRaio(float raio){
        this.raio=raio;
    }

    public class Metodos{

        public void Circulo(float novo_raio){
            if (novo_raio >=1){
                setRaio(novo_raio); 
                System.out.println("Novo raio: "+ getRaio()+"\n");
            }
            else{
                System.out.println("Valor inserido inválido\n");
            }

        }


        public double calculaArea(){
            double r=getRaio();

            return Math.PI*Math.pow(r,2);
        }

        public float calculaDiametro(){
            float r = getRaio();
            return r*2;

        }

        public void mostrarDados(){
                       
            System.out.println("-------------------------------------");
            System.out.println("DADOS DO CIRCULO");
            
            System.out.println("Raio: "+getRaio()+"\n");
            System.out.println("Area: "+calculaArea()+"\n");
            System.out.println("Diametro: "+calculaDiametro()+"\n");
            System.out.println("------------------------------------");
        }




    }


}