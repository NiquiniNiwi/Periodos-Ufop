import React, { useState, useEffect} from 'react'
import '../Css/Cadastro.css'
import IMAGEM from '../Images/ImagemCadastro.jpg'
import Popup from './Popup';

function Cadastro({onSubmit}) {
  const [isOpen, setIsOpen] = useState(false);
  const [nome, setNome] = useState('');
  const [usuario, setUsuario] = useState('');
  const [email, setEmail] = useState('');
  const [empresa, setEmpresa] = useState('');
  const [senha, setSenha] = useState('');
  const [confirmacao_senha, setConfimacao] = useState('');
  
  const togglePopup = () => {
    setIsOpen(!isOpen);
  }

  async function handleSubmit(e){
      e.preventDefault();
    
      await onSubmit({
        nome,
        //usuario,
        email,
        empresa,
        //senha,
      });

      if(senha !== confirmacao_senha){
        setNome('');
        setUsuario('');
        setEmail('');
        setEmpresa('');
        setSenha('');
        setConfimacao('');
      }
       
  }
  return (
    <body>
      <div id = "Cadastro">
            <text h1>
                <strong id = "mdTituloCadastro">
                    Cadastro
                </strong>
            </text>
        <form onSubmit={handleSubmit}>
        <div className="input-block"> 
            <label id="labels" htmlFor="nome">Nome-------------|</label>
            <input 
            name="nome" 
            id="nome" 
            required
            value = {nome}
            onChange = {e => setNome(e.target.value)}></input>
          </div>
          <div className="input-block">
            <label id="labels" htmlFor="usuario">User---------------|</label>
            <input 
            name="usuario" 
            id="usuario" 
            required
            value = {usuario}
            onChange = {e => setUsuario(e.target.value)}></input>
          </div>
          <div className="input-block">
            <label id="labels" htmlFor="email">E-mail-------------|</label>
            <input 
            name="email" 
            id="email" 
            required
            value = {email}
            onChange = {e => setEmail(e.target.value)}></input>
          </div>
          <div className="input-block">
            <label id="labels" htmlFor="empresa">Empresa----------|</label>
            <input 
            name="empresa" 
            id="empresa" 
            required
            value = {empresa}
            onChange = {e => setEmpresa(e.target.value)}></input>
          </div>
          <div className="input-block">
            <label id="labels" htmlFor="senha">Senha-------------|</label>
            <input 
            name="senha" 
            id="senha" 
            required
            value = {senha}
            onChange = {e => setSenha(e.target.value)}></input>
          </div>
          <div className="input-block">
            <label id="labels" htmlFor="confirmacao_senha">Confirmar Senha-|</label>
            <input 
            name="confirmacao_senha" 
            id="confirmacao_senha" 
            required
            value = {confirmacao_senha}
            onChange = {e => setConfimacao(e.target.value)}></input>
          </div>
          <button id = "salvar" type="submit">
            Salvar
          </button>
        </form>
        
        <img type="button" src={IMAGEM} id ="image" alt="" />
    </div>
    </body>
  );
}

export default Cadastro;