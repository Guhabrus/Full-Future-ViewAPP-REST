#include "config.h"
#include <iostream>

/**************************************/
#include <boost/program_options.hpp>



/**-------------------------------------**/
#include "../debug/debug.h"


void Config::print_settings()
{
    
    std::cout.setf(std::ios::left);
    std::cout<<"ip host = "             <<this->_host_name  <<std::endl;
    std::cout<<"port = "                <<this->_port       <<std::endl;
    std::cout<<"database name = "       <<this->_bd_name    <<std::endl;
    std::cout<<"login database = "      <<this->_login_bd   <<std::endl;
    std::cout<<"database password = "   <<this->_password_bd<<std::endl;
    // std::cout<<" json = "               <<this->_json_conf  <<std::endl;

}


namespace po = boost::program_options;



ERROR_CONFIG Config::parse_line( int argc,  char** argv)
{
    po::options_description descript("General options");

    descript.add_options() ("help, h", "Help screen")
    // ("json, J",         po::value<bool>()->required(),          "Setting file" )
    ("host, N",    po::value<std::string>()->required(),   "IP host" )
    ("port, p ",        po::value<std::string>()->required(),   "server port " )
    ("login, l",     po::value<std::string>()->required(),   "login to database " )
    ("password, P",  po::value<std::string>()->required(),   "password to database " )
    ("database, M ",     po::value<std::string>()->required(),   "name of database " );


    po::variables_map pars_line;
    po::store(po::parse_command_line(argc,argv, descript), pars_line);

    this->_host_name    = pars_line["host"].as<std::string>();
    this->_port         = pars_line["port"].as<std::string>();
    this->_bd_name      = pars_line["database"].as<std::string>();
    this->_password_bd  = pars_line["password"].as<std::string>();
    this->_login_bd     = pars_line["login"].as<std::string>();
    // this->_json_conf    = pars_line["json"].as<bool>();
    
    #ifdef PRINT_DEBUG
        this->getInstance().print_settings();
    #endif

    return ERROR_CONFIG::SUCCES;


}



inline Config& Config::getInstance(){
    static Config instance;
    return instance;
}



void Config::connect(Observer* obsrv){
    getInstance()._list_view.push_back(obsrv);
}

void Config::notify(){
    for(std::vector<Observer*>::iterator it = getInstance()._list_view.begin(); it!= getInstance()._list_view.end(); ++it)
        (*it)->update();
}



unsigned short Config::get_port(){
    return (unsigned short)std::stoi(Config::getInstance()._port);
}


std::string Config::get_IP(){
    return Config::getInstance()._host_name;
}