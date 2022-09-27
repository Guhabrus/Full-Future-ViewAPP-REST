import React, {useState, useEffect} from 'react';
import logo from './logo.svg';
import './App.css';
import Info from './Info';

function App() {
  const [data, setData] = useState(null)

  useEffect(() => {
    fetch('/api')
    .then(response => response.json())
    .then(response => setData(response.author))
    .then(response => setData(response.number))
    .then(response => setData(response.mail))
    .then(response => setData(response.city))
    .then(response => setData(response.contrey))
    .then(response => setData(response.status))
  }, [])

  return (
    <div className="App">
      <header className="App-header">
        <Info/>
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          {
            !data ? "Loading1 ...":data
          }
        </p>
        
      </header>
    </div>
  );
}

export default App;
