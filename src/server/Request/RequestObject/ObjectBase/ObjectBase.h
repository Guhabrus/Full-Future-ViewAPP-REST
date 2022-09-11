/**
 * @file ObjectBase.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include <string>

class ObjectBase
{
    private:

    public:
        
        /**
         * @brief 
         * 
         * @param data 
         * @param size_data 
         * @return true 
         * @return false 
         */
        virtual bool send_request(const char* data,const size_t size_data) = 0;

        /**
         * @brief 
         * 
         * @param request_db 
         * @return true 
        //  * @return false 
        //  */
        // virtual bool send_request(std::string request_db) = 0;
};

#endif