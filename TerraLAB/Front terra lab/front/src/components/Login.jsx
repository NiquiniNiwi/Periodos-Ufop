import React, { useState, useEffect} from 'react'
import '../Css/Login.css'

function Login({onSubmit}) {
  const [usuario, setUsuario] = useState('');
  const [senha, setSenha] = useState('');

  async function handleSubmit(e){
    e.preventDefault();

    await onSubmit({
      usuario,
      senha,
    });

    
    setUsuario('');
    setSenha('');      
      
}
  return (
    <body>
      <div id = "Login">
            <text h1>
                <strong id = "mdTituloCadastro">
                    Login
                </strong>
            </text>
        <form onSubmit={handleSubmit}>

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
            <label id="labels" htmlFor="senha">Nome-------------|</label>
            <input 
            name="senha" 
            id="senha" 
            required
            value = {senha}
            onChange = {e => setSenha(e.target.value)}></input>
          </div>
          <button id = "salvar" type="submit">
            Entrar
          </button>
          </form>
        </div>
    </body>
  );
}

export default Login;