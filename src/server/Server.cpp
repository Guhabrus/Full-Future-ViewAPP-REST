/**
 * @file Server.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Server.h"
#include "../config/config.h"
#include "../debug/debug.h"

//**------------------POCO----------------------**


#include "Poco/DateTimeFormat.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Net/HTTPRequestHandler.h"


//***********************LOCAL**********************
#include "Request/RequestFactory/RequestFactory.h"




Server::Server():Observer(), _private_request(false)
{

}


Server::Server(bool on_private): Observer(), _private_request(on_private)
{

}


void Server::update(){

}


int Server::main([[maybe_unused]] const std::vector<std::string> &argv)
{
    if(!this->_private_request)
    {
        Poco::Net::ServerSocket soket(Poco::Net::SocketAddress(Config::getInstance().get_IP(), Config::getInstance().get_port()));

        std::string format_url = config().getString("HHTPBestServer.format",Poco::DateTimeFormat::SORTABLE_FORMAT);
        
        Poco::Net::HTTPServer server_start(new RequestFactory(format_url), soket, new Poco::Net::HTTPServerParams);
        
        try
        {
            server_start.start();
        }
        catch(const std::exception& e)
        {
            print_error("error start server %s\n",e.what());
            return Application::EXIT_SOFTWARE;
        }
        std::cout<<"Server start"<<std::endl;   
        waitForTerminationRequest();

        server_start.stop();

    }
    return Application::EXIT_OK;
}