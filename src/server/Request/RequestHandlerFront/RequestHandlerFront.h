/**
 * @file RequestHandkerFront.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef REQUESTHANDLERFRONT_H
#define REQUESTHANDLERFRONT_H

//**********************POCO******************************
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

//************************Local****************************
#include "../../../config/Observer/Observer.h"


class RequestHandlerInfo : public Poco::Net::HTTPRequestHandler, public Observer
{
    public:
    
    /**
     * @brief Construct a new Request Handker Front object
     * 
     * @param html_requestt 
     */
        RequestHandlerInfo(const std::string &html_requestt);

        /**
         * @brief 
         * 
         * @param req 
         * @param resp 
         */
        void handleRequest([[maybe_unused]] Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);

        /**
         * @brief 
         * 
         * @param path 
         * @return std::string 
         */
        std::string readJson(const char *path);
        
        /**
         * @brief 
         * 
         */
        void update();

        /**
         * @brief Destroy the Request Handker Front object
         * 
         */
        ~RequestHandlerInfo() = default;

        private:
        std::string _html_requestt;
        std::string json_info;
};

#endif