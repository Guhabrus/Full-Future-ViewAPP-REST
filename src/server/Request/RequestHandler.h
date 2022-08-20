/**
 * @file RequestHandler.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */


//*******************Poco*********************
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/JSON/Stringifier.h"

enum Metod
{
    GET,
    POST
};
class RequestHendler:public Poco::Net::HTTPRequestHandler
{
    public:
        RequestHendler(const std::string &html_requestt): prvt_html_requestt(html_requestt){}
    

        /**
         * @brief Переопределенная фунция обработки запросов
         * 
         * @param req --> запрос сервера
         * @param resp --> ответ сервера
         */
        void handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);

    private:
        
        std::string prvt_html_requestt;


       
};