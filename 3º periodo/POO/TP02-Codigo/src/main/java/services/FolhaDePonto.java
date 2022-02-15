/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package services;

import java.util.*;

import tools.DiaTrabalho;

public class FolhaDePonto {
    private Vector<DiaTrabalho> fp;

    public FolhaDePonto() {
        fp = new Vector<>();
    }
    
    public void adicionarFolhaDePonto(DiaTrabalho d) {
        fp.add(d);
    }

    public Vector<DiaTrabalho> mostrarFolha(String nome) {
        return fp;
    }
    public Vector<String> getFObs(){
        Vector<String> aux = new Vector<String>();
        for(int index = 0; index < this.fp.size(); index++){
            aux.add(this.fp.get(index).getObservacao());
        }
        return aux;
    }
    public Vector<String> getFData(){
        Vector<String> aux = new Vector<String>();
        for(int index = 0; index < this.fp.size(); index++){
            aux.add(this.fp.get(index).getData());
        }
        return aux;
    }
    
}

