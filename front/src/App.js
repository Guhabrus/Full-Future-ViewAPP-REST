import React from "react";
import './App.css';
import Header from "./Components/Header";
import Nav from "./Components/Nav";



const App=()=>{
  return (
    <div className='app-wrapper'>
      <Header/>

      <Nav/>

      <div className='content'>
        <img src = 'https://www.m24.ru/b/d/nBkSUhL2hFYgmseyLr6BvMKnxdDs95C-yyqYy7jLs2KQeXqLBmmcmzZh59JUtRPBsdaJqSfJd54qEr7t1mNwKSGK7WY=PAz50uypFcpFtB6F6spJUw.jpg'/>
      </div>
    </div>);
}


export default App;