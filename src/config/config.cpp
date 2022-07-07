#include "config.h"
#include <iostream>

/**************************************/
#include <boost/program_options.hpp>

void Config::print_settings()
{
    
    std::cout.setf(std::ios::left);
    std::cout<<"ip host = "             <<this->_host_name  <<std::endl;
    std::cout<<"port = "                <<this->_port       <<std::endl;
    std::cout<<"database name = "       <<this->_bd_name    <<std::endl;
    std::cout<<"login database = "      <<this->_login_bd   <<std::endl;
    std::cout<<"database password = "   <<this->_password_bd<<std::endl;

}


namespace po = boost::program_options;

Config::Config(int _argc, const char* _argv[])
{
    po::options_description descript("General options");

    descript.add_options() ("help, h", "Help screen")
    ("json, j", po::value<std::string>()->required(), "Using json config file")
    ("host_name, N",po::value<std::string>()->required(), "IP host" )
    ("port, p ",    po::value<std::string>()->required(), "server port " )
    ("login_bd, l", po::value<std::string>()->required(), "login to database " )
    ("password_bd, P", po::value<std::string>()->required(), "password to database " )
    ("bd_name, M ",    po::value<std::string>()->required(), "name of database " );


    po::variables_map pars_line;
    po::store(po::parse_command_line(_argc,_argv, descript), pars_line);


    std::cout<<"1\n";

    this->_host_name = pars_line["host_name"].as<std::string>();
    std::cout<<"2\n";
    this->_port = pars_line["port"].as<std::string>();
    std::cout<<"3\n";
    this->_bd_name = pars_line["bd_name"].as<std::string>();
    std::cout<<"4\n";
    this->_password_bd = pars_line["password_bd"].as<std::string>();
    std::cout<<"5\n";
    this->_login_bd = pars_line["login_bd"].as<std::string>();
    std::cout<<"6\n";
    this->_json_conf = parse_line["json"].as<std::string>();
    std::cout<<" json = "<<this->_json_conf<<std::endl;

    
    print_settings();


}