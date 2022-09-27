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
#include <Poco/Net/HTMLForm.h>
#include <Poco/JSON/Array.h>
//**************************STL***************************************
#include <fstream>
#include <iostream>

RequestHandlerInfo::RequestHandlerInfo(const std::string &html_requestt):Observer(), _html_requestt(html_requestt)
{
    this->update();
}


void RequestHandlerInfo::update(){
    this->json_info = this->readJson("/home/maksim/Myfolder/Magistr/VKR/Project/Server/src/JsonFile/Info.json");
}

std::string RequestHandlerInfo::readJson(const char* path){
   
    std::ifstream in;
    std::string line, json_info;
    
    in.open(path, std::ifstream::in);


    if(!in.is_open()){
        print_error("Don t open the Info.json file\n");
        return "{\"status\" :\"500\"}";
    }
    
    while (std::getline(in, line))
    {
        json_info.append(line + "\n");
    }

    try
    {
        in.close();
    }
    catch(const std::exception& e)
    {
        print_error("%s\n", e.what());
    }
    
    return json_info;
    
}



void RequestHandlerInfo::handleRequest([[maybe_unused]] Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &respons)
{
    Poco::Net::HTMLForm html_request(request, request.stream());

    respons.setStatus(Poco::Net::HTTPResponse::HTTP_OK);

    respons.setChunkedTransferEncoding(true);

    respons.setContentType("application/json");

    std::ostream& out = respons.send();
    
    out<<this->json_info;  

    out.flush();  
}


