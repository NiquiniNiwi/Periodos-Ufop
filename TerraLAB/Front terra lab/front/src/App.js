import React from "react";
import { BrowserRouter as Router, Route, Switch } from "react-router-dom";
import { Navigation, Footer, Home, Sobre, Contato, Cadastro, Login } from "./components";
import api from './services/api';

function App() {
  async function handleAddUser(data){

    const reponse = await api.post('/register' ,data);
  }
  async function handdleAutetificacao(token){
    
    const respose = await api.get('/me', token);
  }
  return (
    <div className="App">
      <Router>
        <Navigation />
        <Switch>
          <Route path="/" exact component={() => <Home />} />
          <Route path="/Sobre" exact component={() => <Sobre />} />
          <Route path="/Contato" exact component={() => <Contato />} />
          <Route path="/Cadastro" exact component={() => <Cadastro onSubmit={handleAddUser}/>} />
          <Route path="/Login" exact component={() => <Login onSubmit={handdleAutetificacao}/>} />
        </Switch>
        <Footer />
      </Router>
    </div>
  );
}

export default App;