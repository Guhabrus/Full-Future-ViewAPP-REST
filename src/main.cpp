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


char buf_[2024];


int main()
{
    std::ifstream in;
    std::string line;

    in.open("/home/maksim/Myfolder/Magistr/VKR/Project/Server/src/JsonFile/Info.json", std::ifstream::in);

    

    if(!in.is_open()){
        printf("ccc\n");
    }
    else{
        printf("sdc\n");
    }
    while (std::getline(in, line))
    {
        printf("line = %s\n", line.c_str());
    }

    in.close();
    

    

    printf("%s\n", line.c_str());
    // in.close();

    // std::ofstream out("image2.bin", std::ios::binary|std::ios::out);


    // out.write(buf_, sizeof(buf_));

    // out.close();

    // FILE* in;
    // in = fopen("../image.bin","rb");

    // if(in == 0)
    //     printf("cdlocndnc");

    
    return 0;
    
}

#endif