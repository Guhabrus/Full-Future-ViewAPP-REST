/**
 * @file RequestHandkerFront.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */



//**************************LOCAL*************************************
#include "RequestHandlerFront.h"
#include "../../../debug/debug.h"

//**************************POCO**************************************

//**************************STL***************************************
#include <fstream>

RequestHandlerFront::RequestHandlerFront(const std::string &html_requestt): _html_requestt(html_requestt)
{

}

#include <iostream>
void RequestHandlerFront::handleRequest([[maybe_unused]] Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &respons)
{
    std::ifstream file;
    
    print_debug("URL = %s", request.getURI().c_str());
    try{
        file.open("/home/maksim/Myfolder/Magistr/VKR/prototip/mogo_1/index.html", std::ifstream::in);
    }
    catch(...){

    }

    if(!file.is_open()){
        respons.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
        respons.send();
        return;
    }

    std::string http_s = "";
    while(!file.eof()){
        std::string tmp;
        std::getline(file, tmp);
        http_s += (tmp + "\n");
    }

    file.close();

    std::cout<<http_s<<std::endl;
    respons.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
    respons.setContentType("application/html");
    respons.setChunkedTransferEncoding(false);
    respons.setContentLength(http_s.length());
    std::ostream& out = respons.send();
    out<< http_s <<std::flush;
    
}


