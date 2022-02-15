/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pessoa;
import tools.*;
import services.*;
import java.util.*;

public class Funcionario extends Pessoa {
    private double salario;
    private Agend agenda;
    private FolhaDePonto folhaDePonto;
    private Vector<String> dataPg;
    private Vector<Double> valorPg;
    private Vector<String> descriPg;
    
    public Vector<String> getDatasPg(){
        return dataPg;
    }
    public Vector<Double> getValorPg(){
        return valorPg;
    }
    public Vector<String> getDescriPg(){
        return descriPg;
    }
    public void setDatasPg(String dt){
        dataPg.add(dt);
    }
    public void setValorPg(double value){
        valorPg.add(value);
    }
    public void setDesriPG(String descri){
        descriPg.add(descri);
    }
    public Funcionario() {
        super();
        this.salario = 0;
        this.agenda = new Agend();
        DiaTrabalho d = new DiaTrabalho("","");
        this.folhaDePonto = new FolhaDePonto();
        this.folhaDePonto.adicionarFolhaDePonto(d);
        this.valorPg = new Vector<>();
        this.valorPg.add(0.0);
        this.dataPg = new Vector<>();
        this.dataPg.add("");
        this.descriPg = new Vector<>();
        this.descriPg.add("");
    }

    public Funcionario(double salario) {
        super();
        this.salario = salario;
        this.agenda = new Agend();
        DiaTrabalho d = new DiaTrabalho("","");
        this.folhaDePonto = new FolhaDePonto();
        this.folhaDePonto.adicionarFolhaDePonto(d);
        this.valorPg = new Vector<>();
        this.valorPg.add(0.0);
        this.dataPg = new Vector<>();
        this.dataPg.add("");
        this.descriPg = new Vector<>();
        this.descriPg.add("");
    }

    public Funcionario(String nome, double salario) {
        super(nome);
        this.salario = salario;
        this.agenda = new Agend();
        DiaTrabalho d = new DiaTrabalho("","");
        this.folhaDePonto = new FolhaDePonto();
        this.folhaDePonto.adicionarFolhaDePonto(d);
        this.valorPg = new Vector<>();
        this.valorPg.add(0.0);
        this.dataPg = new Vector<>();
        this.dataPg.add("");
        this.descriPg = new Vector<>();
        this.descriPg.add("");
    }

    public double getsalario() {
        return salario;
    }

    public void setSalario(double s) {
        // Se valor fornecido for negativo, salario toma valor 0
        salario = s < 0 ? 0 : s;
    }

    public Vector<String> getFolhaObs(Funcionario fun){
        return folhaDePonto.getFObs();
    }
    public Vector<String> getFolhaData(Funcionario fun){
        return folhaDePonto.getFData();
    }
    
    public Vector<String> getPgAsString(Vector<Funcionario> fun){
        Vector<String> aux = new Vector<String>();
        for(int index1 = 0; index1 < fun.size(); index1++){
            for(int index = 0; index < fun.get(index1).getValorPg().size(); index++){
                aux.add(Double.toString(fun.get(index1).getValorPg().get(index)));
            }
        }
        return aux;
    }
    public String getFolhaPontoAsString(Funcionario fun){
        String rr = "";
        for(int index = 0; index < fun.getFolhaData(fun).size(); index++){
            rr = rr + fun.getFolhaData(fun).get(index) + " " + fun.getFolhaObs(fun).get(index) + "\n";
        }
        return rr;
    }
    public void addFp(String data, String desc){
        DiaTrabalho d = new DiaTrabalho(data, desc);
        folhaDePonto.adicionarFolhaDePonto((d));
    }
}
