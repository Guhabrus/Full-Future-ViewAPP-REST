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

#ifndef REQUESTHANDKER_H
#define REQUESTHANDKER_H
//*******************Poco*********************
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPServerResponse.h"


class Get;
class Post;
class Put;
class Delete;


class RequestHendler:public Poco::Net::HTTPRequestHandler
{
    public:
    /**
     * @brief Construct a new Request Hendler object
     * 
     * @param html_requestt 
     */
        RequestHendler(const std::string &html_requestt);
    

        /**
         * @brief Переопределенная фунция обработки запросов
         * 
         * @param req --> запрос сервера
         * @param resp --> ответ сервера
         */
        void handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);

        /**
         * @brief Destroy the Request Hendler object
         * 
         */
        ~RequestHendler();

    private:
        std::string prvt_html_requestt;                                                                 ///< 
        Get*        get_method_p;
        Post*       post_method_p;
        Put*        put_method_p;
        Delete*     delete_method_p;

};






#endif