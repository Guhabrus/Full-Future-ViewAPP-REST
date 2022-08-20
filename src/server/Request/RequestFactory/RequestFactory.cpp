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



#include "RequestFactory.h"
#include "../../../debug/debug.h"

Poco::Net::HTTPRequestHandler* RequestFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request)
{
    print_debug(" req URL = %s\n", request.getURI().c_str());
    if("/person"==request.getURI() || 1)        //TODO сделать проверку
    {
        return new RequestHendler(prvt_html_requestt);
    }
    else 
        return NULL;
}