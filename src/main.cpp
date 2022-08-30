#include <iostream>
#include <stdio.h>
#include "config/config.h"
#include "server/Server.h"


// #define TRAIN


#ifndef TRAIN
int main(int argc, char** argv)
{
    Config::getInstance().parse_line(argc, argv);
    
    Server serv;

  
    return serv.run(1, argv);
  
    
}

#else
int main()
{
    
    return 0;
    
}

#endif