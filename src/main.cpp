// #include <iostream>
// #include <stdio.h>
// #include "config/config.h"
// #include "server/Server.h"

// int main(int argc, char** argv)
// {
//     Config::getInstance().parse_line(argc, argv);
    
//     Server serv;

//     // printf(" argc = %d , argv  = %s\n",argc, *argv );
//     return serv.run(1, argv);
//     // return 0;
    
// }

// // #include <Poco/Net/HTMLForm.h>
// // int main()
// // {
// //     // Config::getInstance().parse_line(argc, argv);
    
// //     // Server serv;

// //     // printf(" argc = %d , argv  = %s\n",argc, *argv );
// //     Poco::Net::HTMLForm f;
// //     f.get()
// //     return 0;
    
// // }




//***************soket********************
#include <sys/socket.h>
#include <netinet/in.h> //struct sockaddr_in
#include <sys/types.h>
#include <unistd.h>

//*************C****************************
#include <cstring>

#define TYPE_DOMEN AF_UNIX                                     //тип домена: AF_INET через интернет или через процесс AF_UNIX - только между процессами
#define TYPE_SOKET SOCK_STREAM                                  //тип сокета: SOCK_STREAM - с предварительной установкой соединения,
// SOCK_DGRAM - обмен ввиде отдельных сообщений, SOCK_RAW - низкоуровневый обмен (это гавно не использовать)
#define TYPE_PROTOCOL 0                                         // тип протокола: 0-поумолчанию, другие не знаю
#define COUNT_QUEUE   1                                         //Размер очереди
#define SIZE_AKS      64
#define PORT_MODEL    8083


uint16_t message[32] = {1,2,3,4,5,6,7,8,9,10};
uint16_t buf[sizeof(message)];

#include "debug/debug.h"

int main()
{

    int sock_desk = socket(AF_INET, SOCK_STREAM, 0);

    if(sock_desk<0){
        print_error("Error create socket\n");
        return 1;
    }


    struct sockaddr_in addr; memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT_MODEL); // или любой другой порт...
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    
    if(connect(sock_desk,(struct sockaddr *)&addr, sizeof(addr) ) < 0)
    {
        print_error("Not connetc to model\n");
        return 1;
    }

    send(sock_desk, message, sizeof(message), 0);
    recv(sock_desk, buf, 2, 0);
    
    print_debug("kvit = %d\n", buf[0]);
    
    close(sock_desk);
    


    return 0;
}