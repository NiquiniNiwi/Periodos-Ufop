# -*- utf-8 -*-
from tkinter import *
primeiro = 1
operador = "0"
root = Tk()
root.title("Calc")
e = Entry(root, width=35, borderwidth=5)
e.grid(row = 0, column=0, columnspan=3, padx=10, pady=10)
#funções
def button_click(valor):
    atual = e.get()
    e.delete(0, END)
    e.insert(0, str(atual) + str(valor))
def button_soma():
    global primeiro
    primeiro = str(e.get())
    global operador
    operador = "+"
    e.delete(0, END)
def button_sub():
    global primeiro
    primeiro = str(e.get())
    global operador
    operador = "-"
    e.delete(0, END)
def button_mult():
    global primeiro
    primeiro = str(e.get())
    global operador
    operador = "*"
    e.delete(0, END)
def button_div():
    global primeiro
    primeiro = str(e.get())
    global operador
    operador = "/"
    e.delete(0, END)
def button_igual():
    segundo = e.get()
    e.delete(0, END)
    if operador == "+":
        e.insert(0, int(primeiro) + int(segundo))
    elif operador == "-":
        e.insert(0, int(primeiro) - int(segundo))
    elif operador == "*":
        e.insert(0, int(primeiro) * int(segundo))
    elif operador == "/":
        e.insert(0, float(primeiro) / float(segundo))
    else:
        e.insert(0, "ERROR")
def button_limpa():
    e.delete(0,END)
#botões
button_1 = Button(root, text = "1", padx=40, pady = 20, command=lambda: button_click(1))
button_2 = Button(root, text = "2", padx=40, pady = 20, command=lambda: button_click(2))
button_3 = Button(root, text = "3", padx=40, pady = 20, command=lambda: button_click(3))
button_4 = Button(root, text = "4", padx=40, pady = 20, command=lambda: button_click(4))
button_5 = Button(root, text = "5", padx=40, pady = 20, command=lambda: button_click(5))
button_6 = Button(root, text = "6", padx=40, pady = 20, command=lambda: button_click(6))
button_7 = Button(root, text = "7", padx=40, pady = 20, command=lambda: button_click(7))
button_8 = Button(root, text = "8", padx=40, pady = 20, command=lambda: button_click(8))
button_9 = Button(root, text = "9", padx=40, pady = 20, command=lambda: button_click(9))
button_0 = Button(root, text = "0", padx=40, pady = 20, command=lambda: button_click(0))
button_add = Button(root, text = "+", padx=39, pady = 20, command= button_soma)
button_menos = Button(root, text = "-", padx=39, pady = 20, command= button_sub)
button_multi = Button(root, text = "x", padx=39, pady = 20, command= button_mult)
button_divi = Button(root, text = "/", padx=39, pady = 20, command= button_div)
button_equal = Button(root, text = "=", padx=91, pady = 20, command=button_igual)
button_clear = Button(root, text = "Clear", padx=79, pady = 20, command=button_limpa)
#botões na ordem 
button_1.grid(row =3, column= 0)
button_2.grid(row =3, column= 1)
button_3.grid(row =3, column= 2)

button_4.grid(row =2, column= 0)
button_5.grid(row =2, column= 1)
button_6.grid(row =2, column= 2)

button_7.grid(row =1, column= 0)
button_8.grid(row =1, column= 1)
button_9.grid(row =1, column= 2)

button_0.grid(row =4, column= 0)
button_clear.grid(row =4, column = 1, columnspan = 2)

button_multi.grid(row =5, column= 0)
button_divi.grid(row =5, column= 1)
button_menos.grid(row =5, column= 2)

button_add.grid(row =6, column=0)
button_equal.grid(row =6, column=1, columnspan = 2)
#-----------------------------------------------------------------------------------
root.mainloop()