# -*- utf-8 -*-
#imports
from tkinter import *
import numpy as np
import pandas as pd
import plotly as py
from plotly.offline import download_plotlyjs, init_notebook_mode, plot, iplot
import plotly.graph_objs as go
root = Tk()
#plota graficos
#----------------------------------------------------------------------------------
def category():
   categoria = pd.read_csv('categorias.csv')
   df_categoria = categoria.apply(pd.to_numeric, errors='ignore')
   df_new_categoria = df_categoria.head(56)
      #traces
   trace_league = go.Bar(
      x = df_new_categoria['DATAS'],
      y = df_new_categoria['League of legends'],
      name ='League of Legens')
   trace_fortinite = go.Bar(
      x = df_new_categoria['DATAS'],
      y = df_new_categoria['Fortine'],
      name ='Fortinite')
   trace_chating = go.Bar(
      x = df_new_categoria['DATAS'],
      y = df_new_categoria['Just chating'],
      name ='Just chating')
   trace_cs = go.Bar(
      x = df_new_categoria['DATAS'],
      y = df_new_categoria['CS:GO'],
      name ='CS:GO')
   trace_gta = go.Bar(
      x = df_new_categoria['DATAS'],
      y = df_new_categoria['GTA V'],
      name ='GTA V')
   trace_dota = go.Bar(
      x = df_new_categoria['DATAS'],
      y = df_new_categoria['Dota 2'],
      name ='Dota 2')
   trace_cod = go.Bar(
      x = df_new_categoria['DATAS'],
      y = df_new_categoria['COD MW'],
      name ='COD MW')
   trace_mine = go.Bar(
      x = df_new_categoria['DATAS'],
      y = df_new_categoria['Minecraft'],
      name ='Minecraft')
   trace_valora =go.Bar(
      x = df_new_categoria['DATAS'],
      y = df_new_categoria['Valorant'],
      name ='Valorant')
   #-----------------------------------------------------------------------------
   data = [trace_chating, trace_cod, trace_cs,
   trace_dota, trace_fortinite, trace_gta, trace_league, trace_mine,
   trace_valora]
   layout = go.Layout(barmode='group')
   fig1 = go.Figure(data=data, layout=layout)
   iplot(fig1, filename='Categorias')#cria host local pra mostra grafico em barras
def canbar():
   tempo = pd.read_csv('Tempo de visualização.csv')
   df_tempo = tempo.apply(pd.to_numeric, errors='ignore')
   df_new_tempo = df_tempo.head(96)
   trace_canis_barra =go.Bar(
      x = df_new_tempo['Meses | Ano'],
      y = df_new_tempo['Canais ativos'],
      name ='Quantidade de Canais Ativo')
   data1 = [trace_canis_barra]
   fig3 = go.Figure(data=data1)
   iplot(fig3, filename='Canais')#cria host local pra mostra grafico em barras
def tempbar():
   tempo = pd.read_csv('Tempo de visualização.csv')
   df_tempo = tempo.apply(pd.to_numeric, errors='ignore')
   df_new_tempo = df_tempo.head(96)
   trace_tempo_barra =go.Bar(
      x = df_new_tempo['Meses | Ano'],
      y = df_new_tempo['Tempo assistido horas'],
      name ='Tempo assistido horas')
   data2 = [trace_tempo_barra]
   fig2 = go.Figure(data=data2)
   iplot(fig2, filename='Tempo em horas')
def temppieinicio():
   #style
   colors = ['#d32c58', '#f9b1ee', '#b7f9b1', '#b1f5f9']
   #-----------------------------------------------------------------------------------
   tempo = pd.read_csv('Tempo de visualização.csv')
   df_tempo = tempo.apply(pd.to_numeric, errors='ignore')
   df_new_t10 = df_tempo.head(12)
   trace_tempo_tempo1 = go.Pie(labels=df_new_t10['Meses | Ano'], values=df_new_t10['Tempo assistido horas'],
   title='Tempo assistido em Horas',
                  hoverinfo='label+percent', textinfo='value', 
                  textfont=dict(size=25),
                  marker=dict(colors=colors, 
                              line=dict(color='#000000', width=2)))
   iplot([trace_tempo_tempo1])#cria host local pra mostra grafico em pizza
def temppieatual():
   #style
   colors = ['#d32c58', '#f9b1ee', '#b7f9b1', '#b1f5f9']
   #-----------------------------------------------------------------------------------
   tempo = pd.read_csv('2020.csv')
   df_tempo = tempo.apply(pd.to_numeric, errors='ignore')
   df_new_t10 = df_tempo.head(8)
   trace_tempo_tempo = go.Pie(labels=df_new_t10['Meses | Ano'], values=df_new_t10['Tempo assistido horas'],
   title='Tempo assistido em Horas',
                  hoverinfo='label+percent', textinfo='value', 
                  textfont=dict(size=25),
                  marker=dict(colors=colors, 
                              line=dict(color='#000000', width=2)))
   iplot([trace_tempo_tempo])#cria host local pra mostra grafico em pizza
def canpieatual():
      #style
   colors = ['#d32c58', '#f9b1ee', '#b7f9b1', '#b1f5f9']
   #-----------------------------------------------------------------------------------
   tempo = pd.read_csv('2020.csv')
   df_tempo = tempo.apply(pd.to_numeric, errors='ignore')
   df_new_t10 = df_tempo.head(8)
   trace_tempo_canais = go.Pie(labels=df_new_t10['Meses | Ano'], values=df_new_t10['Canais ativos'],
   title='Quantidade de Canais Ativo',
                  hoverinfo='label+percent', textinfo='value', 
                  textfont=dict(size=25),
                  marker=dict(colors=colors, 
                              line=dict(color='#000000', width=2)))
   iplot([trace_tempo_canais])#cria host local pra mostra grafico em pizza
def todos():
   category()
   canbar()
   tempbar()
   temppieinicio()
   temppieatual()
   canpieatual()
#-----------------------------------------------------------------------------------
butall = Button(root, text="|----------------All----------------|",padx=10,pady=30, command=todos)
butall.pack()
butcat = Button(root, text="|-------------Categoria-------------|",padx=10,pady=30, command=category)
butcat.pack()
butcb  = Button(root, text="|-------Canais Ativos Barra---------|",padx=10,pady=30, command=canbar)
butcb.pack()
buttb  = Button(root, text="|----Tempo de Visuzalização Barra---|",padx=10,pady=30, command=tempbar)
buttb.pack()
butcp  = Button(root, text="|----Canais Ativos Pizza Atuais-----|",padx=10,pady=30, command=canpieatual)
butcp.pack()
buttp  = Button(root, text="|Tempo de Visuzalização Pizza Atual-|",padx=10,pady=30, command=temppieatual)
buttp.pack()
buttp  = Button(root, text="|Tempo de Visuzalização Pizza Inicio|",padx=10,pady=30, command=temppieinicio)
buttp.pack()
#-----------------------------------------------------------------------------------
root.mainloop()