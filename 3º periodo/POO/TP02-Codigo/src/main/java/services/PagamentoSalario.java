/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package services;

import java.util.ArrayList;
import tools.Salario;

public class PagamentoSalario {
    private ArrayList<Salario> pagamentos;

    public PagamentoSalario() {
        pagamentos = new ArrayList<>();
    }
    
    public void addPagamento(Salario s) {
        pagamentos.add(s);
    }
    
    public ArrayList<Salario> getPagamentos() {
        return pagamentos;
    }
}
