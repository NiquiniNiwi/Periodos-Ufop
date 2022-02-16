import React from "react";
import '../Css/Sobre.css'
import IMAGEMSOBRE from '../Images/Imagem_Sobre.jpg'

function Sobre() {
  return (
    <body>
        <div id = "Sobre">
            <text h1>
                <strong id = "mdTituloSobre">
                    Sobre o GeoCave
                </strong>
            </text>
            <img src={IMAGEMSOBRE} id = "imagemSobre"alt=""/>
            <p id = "mdTextSobre">
                Lorem ipsum dolor sit amet, consectetur adipiscing elit.
                Maecenas viverra, dui nec sodales scelerisque, odio odio sodales nisi, in semper lorem tortor vitae dui. 
                Vivamus in cursus leo.
            </p>
        </div>
    </body>
  );
}

export default Sobre;