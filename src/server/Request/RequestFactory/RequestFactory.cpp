/**
 * @file RequestFactory.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <Poco/Net/HTMLForm.h>


//*****************LOCAL******************
#include "RequestFactory.h"
#include "../RequestHandler.h"
#include "../RequestHandlerFront/RequestHandlerFront.h"
#include "../../../debug/debug.h"

Poco::Net::HTTPRequestHandler* RequestFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request)
{
    print_debug(" req URL = %s\n", request.getURI().c_str());
    if("/api"==request.getURI())         //TODO сделать проверку
    {
        
        print_debug("HTML\n");
        return new RequestHandlerInfo(prvt_html_requestt);
    }
    else
    {
        return new RequestHendler(prvt_html_requestt);
    }
     
    
}