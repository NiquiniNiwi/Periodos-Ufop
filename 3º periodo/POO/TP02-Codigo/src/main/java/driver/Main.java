/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package driver;
import GUI.Login;
import java.util.*;
//Import all
import pessoa.*;

import services.*;

import tools.*;

import users.*;

public class Main {
    public static void main(String[] args) {
        // TODO code application logic here
        Vector<UserGeral> geral = new Vector<>();
        Vector<AssistenteAdm> ass = new Vector<>();
        Administrador adm = new Administrador();
        Vector<Dentista> dent = new Vector<>();
        Dentista dent1 = new Dentista("One", 2, 2);
        dent.add(dent1);
        Dentista dent2 = new Dentista("Two", 2, 2);
        dent.add(dent2);
        Dentista dent3 = new Dentista("Three", 2, 2);
        dent.add(dent3);
        ReceberConsultas con = new ReceberConsultas();
        PagamentoContas pgc = new PagamentoContas();
        Vector<Funcionario> fun = new Vector<>();
        Funcionario fun1 = new Funcionario("Four", 2);
        fun.add(fun1);
        Funcionario fun2 = new Funcionario("Five", 2);
        fun.add(fun2);
        Funcionario fun3 = new Funcionario("Six", 2);
        fun.add(fun3);
        Funcionario fun4 = new Funcionario("Seven", 2);
        fun.add(fun4);
        Vector<Pessoa> pacientes = new Vector<>();
        System.out.print(("Sistema funcionando."));
        new Login(adm, dent, con, pgc, fun, pacientes, ass, geral).setVisible(true);
    }
}
