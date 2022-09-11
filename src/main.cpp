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

#include <fstream>


char buf_[1024];


int main()
{
    std::ifstream in;

    in.open("image.bin", std::ios::binary|std::ios::in);
   
    in.read(buf_, sizeof(buf_));

    


    in.close();

    std::ofstream out("image2.bin", std::ios::binary|std::ios::out);


    out.write(buf_, sizeof(buf_));

    out.close();

    // FILE* in;
    // in = fopen("../image.bin","rb");

    // if(in == 0)
    //     printf("cdlocndnc");

    
    return 0;
    
}

#endif