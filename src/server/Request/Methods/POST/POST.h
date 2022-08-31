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

//********************POCO**************************
#include <Poco/Net/PartHandler.h>
#include <Poco/Net/MessageHeader.h>
#include <Poco/Net/HTTPServerResponse.h>



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
         * @param response 
         */
        void send_response(Poco::Net::HTTPServerResponse &response);


    private:
        
        int _length;
        std::string _type;
        std::string _name;
        std::string _fileName;
        #define _METHOD "POST"
};

#endif