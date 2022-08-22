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

class ObjectBase
{
    private:

    public:
        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        virtual bool send_request() = 0;
};

#endif