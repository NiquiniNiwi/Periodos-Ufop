/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pessoa;

public class Pessoa {
    private String nome;
    private static final String EMPTY_STRING = "";
    private double pagamento;
    
    public Pessoa() {
        this.nome = EMPTY_STRING;
    }

    public Pessoa(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String n) {
        nome = n;
    }
    public double getPagamento(){
        return pagamento;
    }
    public void setPagamento(double pg){
        pagamento = pg;
    }
}