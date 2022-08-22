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

#include "Methods/GET/GET.h"
#include "Methods/DELETE/DELETE.h"
#include "Methods/POST/POST.h"
#include "Methods/PUT/PUT.h"
//**************************POCO**************************
#include "Poco/Net/HTMLForm.h"
#include "Poco/JSON/Stringifier.h"

//TODO  удалить //*****************TEMP******************
#include "RequestObject/ModelRequest/ModelRequest.h"

RequestHendler::RequestHendler(const std::string &html_requestt):prvt_html_requestt(html_requestt)
{
    this->get_method_p      = new Get();
    this->delete_method_p   = new Delete();
    this->post_method_p     = new Post();
    this->put_method_p      = new Put();
}

void RequestHendler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    Poco::Net::HTMLForm form(request, request.stream());
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");
    std::ostream& out = response.send();

    print_debug("request = %s\n", request.getURI().c_str());




    switch (string_to_enum(REST_METHOD, request.getMethod().c_str()))
    {
    case REST_METHOD::GET:
    {
        this->get_method_p->send_request();
        ModelRequest m;
        m.send_request();
    }break;
    
    case REST_METHOD::POST:

    break;

    case REST_METHOD::PUT:

    break;

    case REST_METHOD::DELETE:

    break;

    default:
        //TODO кинуть ошибку клиенту
        break;
    }


    
    out<<"Helloe "<< form.get("name")<<"\n";
    out.flush();

}



RequestHendler::~RequestHendler(){
    if(this->get_method_p)
        delete this->get_method_p;

    if(this->delete_method_p)
        delete this->delete_method_p;

    if(this->post_method_p)
        delete this->post_method_p;

    if(this->put_method_p)
        delete this->put_method_p;
}