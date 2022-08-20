/**
 * @file RequestHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//************************LOCAL****************************
#include "RequestHandler.h"
#include "../../debug/debug.h"


//**************************POCO**************************
#include "Poco/Net/HTMLForm.h"


void RequestHendler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    Poco::Net::HTMLForm form(request, request.stream());
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");
    std::ostream& out = response.send();
    print_debug("request = %s\n", request.getURI().c_str());
    out<<"Got\n";
    out.flush();

}