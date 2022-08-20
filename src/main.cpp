#include <iostream>
#include <stdio.h>
#include "config/config.h"
#include "server/Server.h"

int main(int argc, char** argv)
{
    Config::getInstance().parse_line(argc, argv);
    
    Server serv;

    // printf(" argc = %d , argv  = %s\n",argc, *argv );
    return serv.run(1, argv);
    // return 0;
    
}