import React from "react";
import { Link, withRouter } from "react-router-dom";
import LOGO from '../Images/Side2.png'
import '../Css/Cabeçalho.css'
function Navigation(props) {
  return (
    <div id="Cabeçalho">
      <nav>
        <div id="cabeçalho">
            <img src={LOGO} width ={50} height={50} alt=""/>
            <ul class="navbar-nav ml-auto">
            <li
                class={`nav-item  ${
                  props.location.pathname === "/" ? "active" : ""
                }`}
              >
                <Link class="nav-link" to="/">
                  Home
                </Link>
            </li>
            <li
                class={`nav-item  ${
                  props.location.pathname === "/Sobre" ? "active" : ""
                }`}
              >
                <Link to="/Sobre">
                  Sobre
                </Link>
            </li>
            <li
                class={`nav-item  ${
                  props.location.pathname === "/Contato" ? "active" : ""
                }`}
              >
                <Link class="nav-link" to="/Contato">
                  Contato
                </Link>
            </li>
            <li
                class={`nav-item  ${
                  props.location.pathname === "/Cadastro" ? "active" : ""
                }`}
              >
                <Link class="nav-link" to="/Cadastro">
                  Cadastro
                </Link>
            </li>
            <li
                class={`nav-item  ${
                  props.location.pathname === "/Login" ? "active" : ""
                }`}
              >
                <Link class="nav-link" to="/Login">
                  Login
                </Link>
            </li>
            </ul>
          </div>
      </nav>
    </div>
  );
}

export default withRouter(Navigation);