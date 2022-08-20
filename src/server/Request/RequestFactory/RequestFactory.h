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


//***************************Poco***********************

#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"


//**************************My**************************
#include "../RequestHandler.h"


class RequestFactory: public Poco::Net::HTTPRequestHandlerFactory
{
    public:
        /**
         * @brief Construct a new Request Factory object
         * 
         * @param html_requestt 
         */
        RequestFactory(const std::string &html_requestt): prvt_html_requestt(html_requestt){}

    /**
     * @brief Create a Request Handler object
     * 
     * @param request 
     * @return Poco::Net::HTTPRequestHandler* 
     */
    Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);
    

    private:

        std::string prvt_html_requestt;                     ///< 
};
