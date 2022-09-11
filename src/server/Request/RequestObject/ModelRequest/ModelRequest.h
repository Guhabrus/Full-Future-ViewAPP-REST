/**
 * @file ModelRequest.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MODELREQUEST_H
#define MODELREQUEST_H

//*****************LOCAL*************************
#include "../ObjectBase/ObjectBase.h"


//******************STL***************************
#include <string>

class ModelRequest:public ObjectBase
{
    private:
    const char* _request;
    public:
        

        /**
         * @brief 
         * 
         * @param data 
         * @return true 
         * @return false 
         */
        bool send_request(const char* data,const size_t size_data);

        /**
         * @brief Construct a new Model Request object
         */
        ModelRequest();
};


#endif