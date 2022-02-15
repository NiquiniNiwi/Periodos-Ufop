/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package services;

import java.util.*;
import tools.Consulta;

/**
 *
 * @author Niquini
 */
public class Agend {
    private Vector<Consulta> agenda;
    
    public Agend() {
        agenda = new Vector<>(); 
        Consulta c = new Consulta("","");
        agenda.add(c);
    }
    
    public void addToAgenda(Consulta c) {
        agenda.add(c);
    }
    
    public void removeFromAgenda(Consulta c) {
        agenda.remove(c);
    }
    
    public void editNomeAgenda(Consulta c, String novoNome) {
        // Se o novo nome for igual ao antigo, nenhuma atualização é necessária
        if(c.getNome().equals(novoNome)) return;
        // Se for diferente, atualizo o nome
        c.setNome(novoNome);
        if(!agenda.contains(c)) {
            agenda.add(c);
        }
    }
    
    public void editDataAgenda(Consulta c, String novaData) {
        // Se a nova data for igual a antiga, nenhuma atualização é necessária
        if(c.getData().equals(novaData)) return;
        // Se for diferente, atualizo a data
        c.setNome(novaData);
        if(!agenda.contains(c)) {
            agenda.add(c);
        }
    }
    
    public Vector<Consulta> getAgenda(){
        return agenda;
    }
    
    public Vector<String> getAgendaData(Agend ag){
        Vector<String> aux = new Vector<String>();
        for(int index = 0; index < ag.agenda.size(); index++){
            aux.add(ag.agenda.get(index).getData());
        }
        return aux;
    }
    
    public Vector<String> GetAgendaNome(Agend ag){
        Vector<String> aux = new Vector<String>();
        for(int index = 0; index < ag.agenda.size(); index++){
            aux.add(ag.agenda.get(index).getNome());
        }
        return aux;
    }
}
