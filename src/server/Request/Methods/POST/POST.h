/**
 * @file POST.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#ifndef POST_H
#define POST_H


//******************8*STL****************************
#include <string>
#include <fstream>
//********************POCO**************************
#include <Poco/Net/PartHandler.h>
#include <Poco/Net/MessageHeader.h>
#include <Poco/Net/HTTPServerResponse.h>


//********************LOCAL*************************
#include "../../include/Error.h"


class ObjectBase;

class Post :public Poco::Net::PartHandler
{
    public:

        /**
         * @brief Construct a new Post object
         * 
         */
        Post();

        /**
         * @brief Get the length object
         * 
         * @return int 
         */
        int get_length();

        /**
         * @brief Get the type object
         * 
         * @return std::string 
         */
        std::string get_type();

        /**
         * @brief Get the name object
         * 
         * @return std::string 
         */
        std::string get_name();

        /**
         * @brief Get the filename object
         * 
         * @return std::string 
         */
        std::string get_filename();

        /**
         * @brief 
         * 
         * @param header 
         * @param stream 
         */
        void handlePart(const Poco::Net::MessageHeader& header,  std::istream& stream);


        /**
         * @brief 
         * 
         * @param obj_p 
         * @return ERROR_HANDLER 
         */
        ERROR_HANDLER send_to(ObjectBase* obj_p);


        /**
         * @brief Set the lenth object
         * 
         * @param size_data 
         */
        void set_lenth(std::streamsize size_data);


        /**
         * @brief Destroy the Post object
         * 
         */
        ~Post();

    private:
        
        std::streamsize _length = 73545;
        std::string     _type;
        std::string     _name;
        std::string     _fileName;
        #define _METHOD "POST"

        char *buff; //TODO убрать костыль
};

#endif