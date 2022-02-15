/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pessoa;
import services.Agend;

import java.util.*;

public class Dentista extends Funcionario {
    private int pacientes;
    private Agend agenda;

    public Dentista(String nome, int salario, int pacientes) {
        // Chama construtor da classe Base Funcionario
        super(nome, salario);
        this.pacientes = pacientes < 0 ? 0 : pacientes;
        agenda = new Agend();
    }

    public int getpacientes() {
        return pacientes;
    }

    public void setPacientes(int p) {
        // Se valor fornecido for negativo, pacientes toma valor 0
        pacientes = p < 0 ? 0 : p;
    }
    
    public Vector<String> getAgendNomes(Dentista dent){
        return dent.agenda.GetAgendaNome(agenda);
    }
    public Vector<String> getAgendData(Dentista dent){
        return dent.agenda.getAgendaData(agenda);
    }
    
    public String getAgendaAsString(Dentista dent){
        String ag = "";
        for(int index = 0; index < dent.getAgendNomes(dent).size(); index++){
            ag = ag + dent.getAgendData(dent).get(index) + " " + dent.getAgendNomes(dent).get(index) +"\n";
        }
        return ag;
    }
}
