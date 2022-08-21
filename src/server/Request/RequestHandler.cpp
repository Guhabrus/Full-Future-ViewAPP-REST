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
#include "include/Method.h"

//**************************POCO**************************
#include "Poco/Net/HTMLForm.h"
#include "Poco/JSON/Stringifier.h"




void RequestHendler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    Poco::Net::HTMLForm form(request, request.stream());
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");
    std::ostream& out = response.send();
    print_debug("request = %s\n", request.getURI().c_str());

    printf("%d\n", (int)string_to_enum(METHOD, "POST"));
    switch (string_to_enum(METHOD, request.getMethod().c_str()))
    {
    case METHOD::GET:
        /* code */
    break;
    
    case METHOD::POST:

    break;
    
    default:
        break;
    }


    
    out<<"Helloe "<< form.get("name")<<"\n";
    out.flush();

}