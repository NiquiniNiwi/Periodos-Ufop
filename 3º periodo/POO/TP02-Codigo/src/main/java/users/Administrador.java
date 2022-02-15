/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package users;

public class Administrador extends User {

    public Administrador(String login, String senha) {
        super(login, senha);
    }
    
    public Administrador() {
        super("admin", "admin");
    }
}