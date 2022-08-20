/**
 * @file Server.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef SERVER_H
#define SERVER_H

#include "../config/Observer/Observer.h"

#include "Poco/Util/ServerApplication.h"


#include <vector>
#include <string>

/**
 * @brief 
 * 
 */
class Server : public Poco::Util::ServerApplication,  public Observer
{
    private:
        unsigned short _port;                           ///< 
        bool _private_request;                           ///<


        void initialize(Application &self)
        {
            loadConfiguration();
            ServerApplication::initialize(self);
        }


        void uninitialize()
        {
            ServerApplication::uninitialize();
        }

        void defineOptions(Poco::Util::OptionSet &options)
        {
            ServerApplication::defineOptions(options);
        }

    public:
        /**
         * @brief Construct a new Server object
         * 
         */
        Server();

        /**
         * @brief Construct a new Server object
         * 
         * @param on_private 
         */
        Server(bool on_private);

        /**
         * @brief 
         * virtual
         */
        void update();

        /**
         * @brief 
         * 
         * @param argv 
         * @return int 
         */
        int main([[maybe_unused]] const std::vector<std::string> &argv);

    
};


#endif