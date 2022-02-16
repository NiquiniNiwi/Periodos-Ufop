import React from "react";
import '../Css/Contato.css'
function Contato() {
  return (
    <div id = "Contato">
            <text H3>----------------------</text>
            <form id = "infoContato">
                <label id="tituloContato">Contato</label><br/>
                <label for="fname">Nome:</label><br/>
                <input type="text" id="Nome" name="fname"/><br/>
                <label for="lname">Email:</label><br/>
                <input type="text" id="Email" name="lname"/><br/>
                <label for="lname">Mensagem:</label><br/>
                <input type="text" class = "wideInput" id="Mensagem" name="lname"/><br/>
                <input type="submit" value="Enviar"/>
              </form>
      <text id = "Agradecimento">
          Mensagem de agradecimento por enviar uma mensagem de contato
      </text>        
    </div>
  );
}

export default Contato;