/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUI;
import java.util.*;
import javax.swing.JOptionPane;
//Import all
import pessoa.*;

import services.*;

import tools.*;

import users.*;
/**
 *
 * @author Niquini
 */
public class ListFolhaPonto extends javax.swing.JFrame {
    private JanelaAdmin janelaAdmin;
    private JanelaAssistenteAdmin jaa;
    private Vector<Dentista> dent;
    private Vector<Funcionario> fun;
    public ListFolhaPonto() {
        initComponents();
    }
    public ListFolhaPonto(JanelaAdmin janelaAdmin, Vector<Dentista> dent, Vector<Funcionario> fun){
        this();
        this.janelaAdmin = janelaAdmin;
        this.dent = dent;
        this.fun = fun;
    }
    public ListFolhaPonto(JanelaAssistenteAdmin jaa, Vector<Dentista> dent, Vector<Funcionario> fun){
        this();
        this.jaa = jaa;
        this.dent = dent;
        this.fun = fun;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        Dent1 = new javax.swing.JButton();
        Dent2 = new javax.swing.JButton();
        Dent3 = new javax.swing.JButton();
        Cancelar = new javax.swing.JButton();
        Fun1 = new javax.swing.JButton();
        Fun2 = new javax.swing.JButton();
        Fun3 = new javax.swing.JButton();
        Fun4 = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        jButton6 = new javax.swing.JButton();
        jButton7 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosed(java.awt.event.WindowEvent evt) {
                formWindowClosed(evt);
            }
        });

        Dent1.setText("One");
        Dent1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Dent1ActionPerformed(evt);
            }
        });

        Dent2.setText("Two");
        Dent2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Dent2ActionPerformed(evt);
            }
        });

        Dent3.setText("Three");
        Dent3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Dent3ActionPerformed(evt);
            }
        });

        Cancelar.setText("Cancelar");
        Cancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CancelarActionPerformed(evt);
            }
        });

        Fun1.setText("Four");
        Fun1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Fun1ActionPerformed(evt);
            }
        });

        Fun2.setText("Five");
        Fun2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Fun2ActionPerformed(evt);
            }
        });

        Fun3.setText("Six");
        Fun3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Fun3ActionPerformed(evt);
            }
        });

        Fun4.setText("Seven");
        Fun4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Fun4ActionPerformed(evt);
            }
        });

        jButton1.setText("Novo ponto One");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("Novo ponto Two");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("Novo ponto Three");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton4.setText("Novo ponto Four");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jButton5.setText("Novo ponto FIve");
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });

        jButton6.setText("Novo ponto Six");
        jButton6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton6ActionPerformed(evt);
            }
        });

        jButton7.setText("Novo ponto Seven");
        jButton7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton7ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Cancelar, javax.swing.GroupLayout.DEFAULT_SIZE, 380, Short.MAX_VALUE)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(Fun4, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 199, Short.MAX_VALUE)
                            .addComponent(Fun3, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(Fun2, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(Fun1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(Dent3, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(Dent2, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(Dent1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jButton1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jButton2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jButton3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jButton4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jButton5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jButton7, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jButton6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Dent1)
                    .addComponent(jButton1))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Dent2)
                    .addComponent(jButton2))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Dent3)
                    .addComponent(jButton3))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Fun1)
                    .addComponent(jButton4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Fun2)
                    .addComponent(jButton5))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Fun3)
                    .addComponent(jButton6))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Fun4)
                    .addComponent(jButton7))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(Cancelar)
                .addContainerGap(69, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void Dent1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Dent1ActionPerformed
        // Mostra folha de ponto de dentista selecionado.
        JOptionPane.showMessageDialog(null, dent.get(0).getFolhaPontoAsString(dent.get(0)));//pagamentos anteriores na tela        
    }//GEN-LAST:event_Dent1ActionPerformed

    private void Dent2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Dent2ActionPerformed
        // Mostra folha de ponto de dentista selecionado.
        JOptionPane.showMessageDialog(null, dent.get(1).getFolhaPontoAsString(dent.get(1)));
    }//GEN-LAST:event_Dent2ActionPerformed

    private void Dent3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Dent3ActionPerformed
        // Mostra folha de ponto de dentista selecionado.
        JOptionPane.showMessageDialog(null, dent.get(1).getFolhaPontoAsString(dent.get(1)));
    }//GEN-LAST:event_Dent3ActionPerformed

    private void CancelarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CancelarActionPerformed
        //Gerenciamento de janelas
        if(janelaAdmin != null){
            janelaAdmin.setVisible(true);
            janelaAdmin.setEnabled(true);
        }
        else if(jaa != null){
            jaa.setVisible(true);
            jaa.setEnabled(true);
        }
        this.setEnabled(false);
        this.setVisible(false);
    }//GEN-LAST:event_CancelarActionPerformed

    private void Fun1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Fun1ActionPerformed
        // Mostra folha de ponto de funcionario selecionado.
        JOptionPane.showMessageDialog(null, fun.get(0).getFolhaPontoAsString(fun.get(0)));
    }//GEN-LAST:event_Fun1ActionPerformed

    private void Fun2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Fun2ActionPerformed
        // Mostra folha de ponto de funcionario selecionado.
        JOptionPane.showMessageDialog(null, fun.get(1).getFolhaPontoAsString(fun.get(1)));
    }//GEN-LAST:event_Fun2ActionPerformed

    private void Fun3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Fun3ActionPerformed
        // Mostra folha de ponto de funcionario selecionado.
        JOptionPane.showMessageDialog(null, fun.get(2).getFolhaPontoAsString(fun.get(2)));
    }//GEN-LAST:event_Fun3ActionPerformed

    private void Fun4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Fun4ActionPerformed
        // Mostra folha de ponto de funcionario selecionado.
        JOptionPane.showMessageDialog(null, fun.get(3).getFolhaPontoAsString(fun.get(3)));;
    }//GEN-LAST:event_Fun4ActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // Adiciona ponto na folha de ponto de funcionario selecionado.
        String data = JOptionPane.showInputDialog("Data: ");
        String desc = JOptionPane.showInputDialog("Descrição: ");
        dent.get(0).addFp(data, desc);
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        // Adiciona ponto na folha de ponto de funcionario selecionado.
        String data = JOptionPane.showInputDialog("Data: ");
        String desc = JOptionPane.showInputDialog("Descrição: ");
        dent.get(1).addFp(data, desc);
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        // Adiciona ponto na folha de ponto de funcionario selecionado.
        String data = JOptionPane.showInputDialog("Data: ");
        String desc = JOptionPane.showInputDialog("Descrição: ");
        dent.get(2).addFp(data, desc);
    }//GEN-LAST:event_jButton3ActionPerformed

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
        // Adiciona ponto na folha de ponto de funcionario selecionado.
        String data = JOptionPane.showInputDialog("Data: ");
        String desc = JOptionPane.showInputDialog("Descrição: ");
        fun.get(0).addFp(data, desc);
    }//GEN-LAST:event_jButton4ActionPerformed

    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton5ActionPerformed
        // Adiciona ponto na folha de ponto de funcionario selecionado.
        String data = JOptionPane.showInputDialog("Data: ");
        String desc = JOptionPane.showInputDialog("Descrição: ");
        fun.get(1).addFp(data, desc);
    }//GEN-LAST:event_jButton5ActionPerformed

    private void jButton6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton6ActionPerformed
        // Adiciona ponto na folha de ponto de funcionario selecionado.
        String data = JOptionPane.showInputDialog("Data: ");
        String desc = JOptionPane.showInputDialog("Descrição: ");
        fun.get(2).addFp(data, desc);
    }//GEN-LAST:event_jButton6ActionPerformed

    private void jButton7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton7ActionPerformed
        // Adiciona ponto na folha de ponto de funcionario selecionado.
        String data = JOptionPane.showInputDialog("Data: ");
        String desc = JOptionPane.showInputDialog("Descrição: ");
        fun.get(3).addFp(data, desc);
    }//GEN-LAST:event_jButton7ActionPerformed

    private void formWindowClosed(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosed
        // Gerenciamento de janelas.
        this.setEnabled(false);
        this.setVisible(false);
    }//GEN-LAST:event_formWindowClosed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ListFolhaPonto.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ListFolhaPonto.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ListFolhaPonto.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ListFolhaPonto.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ListFolhaPonto().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Cancelar;
    private javax.swing.JButton Dent1;
    private javax.swing.JButton Dent2;
    private javax.swing.JButton Dent3;
    private javax.swing.JButton Fun1;
    private javax.swing.JButton Fun2;
    private javax.swing.JButton Fun3;
    private javax.swing.JButton Fun4;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton5;
    private javax.swing.JButton jButton6;
    private javax.swing.JButton jButton7;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}
