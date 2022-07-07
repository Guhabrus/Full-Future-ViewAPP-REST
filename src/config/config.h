#ifndef CONFIG_H
#define CONFIG_H

#include <string>

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
    std::string _json_conf;                 ///< использование настроечного файла вместо настроек командной строки


    public:

    // Config(): _host_name(), _port(), _login_bd(), _password_bd(){}
    Config(int argc, const char* argv[]);
    virtual ~Config(){};

    /**
     * @brief фнукция парсинга входого потока символов (настройки)
     * 
     * @param argc кол-во аргументов
     * @param argv настроечные параметры //TODO БОП
     * @return ERROR_CONFIG 
     */
    ERROR_CONFIG parse_line(int argc, const char* argv[]);

    /**
     * @brief Get the settings object
     * выводит ip хоста, порт подключения, логин к базе данных, пароль к базе данных
     */
    void print_settings();    

};


#endif