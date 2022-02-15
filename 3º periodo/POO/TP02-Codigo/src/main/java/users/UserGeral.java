/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package users;

public class UserGeral extends User {
    private int geral = 0;
    public UserGeral(String login, String senha) {
        super(login, senha);
    }
    public int getGeral(){
        return this.geral;
    }
}