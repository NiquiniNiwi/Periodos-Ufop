/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package services;

import tools.PagamentoConsulta;
import java.util.*;
/**
 *
 * @author Niquini
 */
public class ReceberConsultas {
    private Vector<PagamentoConsulta> consultas;
    
    public ReceberConsultas() {
        consultas = new Vector<>();
    }
    
    public void addConsulta(PagamentoConsulta c) {
        consultas.add(c);
    }
    
    public Vector<PagamentoConsulta> getConsultas() {
        return consultas;
    }
    public Vector<String> getValores(ReceberConsultas rc){
        Vector<String> aux = new Vector<String>();
        for(int index = 0; index < rc.consultas.size();index++){
            aux.add(Double.toString(rc.consultas.get(index).getValor()));
        }
        return aux;
    }
    
    public String getConsultasAsString(ReceberConsultas rc){
        String rr = "";
        for(int index = 0; index < rc.getValores(rc).size(); index++){
            rr = rr + rc.getValores(rc).get(index) + "\n";
        }
        return rr;
    }
}
