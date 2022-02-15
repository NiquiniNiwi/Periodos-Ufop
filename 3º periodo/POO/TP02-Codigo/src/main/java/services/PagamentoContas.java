/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package services;

import java.util.*;
import tools.Conta;

public class PagamentoContas {
    private final Vector<Conta> contasClinica;

    public PagamentoContas() {
        contasClinica = new Vector<Conta>();
    }
    
    public void addConta(Conta c) {
        contasClinica.add(c);
    }
    
    public Vector<Conta> getContasClinica() {
        return contasClinica;
    }
    
    public Vector<String> getValoresConta(PagamentoContas pc){
        Vector<String> aux = new Vector<String>();
        for(int index = 0; index < pc.contasClinica.size();index++){
            aux.add(Double.toString(pc.contasClinica.get(index).getValor()) + pc.contasClinica.get(index).getDescricao());
        }
        return aux;
    }
}
