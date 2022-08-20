#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <iostream>
#include <vector>

#include "Observer/Observer.h"

enum ERROR_CONFIG
{
    SUCCES,                             ///* функция заверщилась успешно
    ERROR_ARGS,                         ///* ошибка входных данных
    SIZE_ERROR,                         ///* слишком много входных аргументов
    UNKNOWN_ERROR
};


class Config
{
    private:

    std::string _host_name;          ///< ip хоста
    std::string _port;               ///< порт подключения
    std::string _login_bd;           ///< логин к базе данных
    std::string _password_bd;        ///< пароль к базе данных
    std::string _bd_name;            ///< имя базы данных
    // bool _json_conf;                 ///< использование настроечного файла вместо настроек командной строки

    std::vector<Observer*>  _list_view;


    public:

    /**
     * @brief Construct a new Config object
     * 
     */
    Config() = default;

    /**
     * @brief 
     * 
     * @param observ 
     */
    void connect(Observer* observ);

    /**
     * @brief 
     * 
     */
    void notify();

    /**
     * @brief Get the Instanse object
     * 
     * @return Config 
     */
    static Config& getInstance();


    /**
     * @brief фнукция парсинга входого потока символов (настройки)
     * 
     * @param argc кол-во аргументов
     * @param argv настроечные параметры //TODO БОП
     * @return ERROR_CONFIG 
     */
    ERROR_CONFIG parse_line(int argc,  char** argv);

    /**
     * @brief 
     * 
     * @param path 
     * @return ERROR_CONFIG 
     */
    ERROR_CONFIG parse_json(std::string path);

    /**
     * @brief Get the settings object
     * выводит ip хоста, порт подключения, логин к базе данных, пароль к базе данных
     */
    void print_settings();    


    /**
     * @brief Get the port object
     * 
     * @return unsigned short 
     */
    unsigned short get_port();//{return (unsigned short)std::stoi(Config::getInstance()._port);}

    /**
     * @brief 
     * 
     * @return std::string 
     */
    std::string get_IP();

    virtual ~Config(){};

};


#endif