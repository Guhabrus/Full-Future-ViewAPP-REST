/**
 * @file ModelRequest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//**************LOCAL**********************
#include "ModelRequest.h"
#include "../../../../debug/debug.h"



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





bool ModelRequest::send_request(){

    // int sock_desk = socket(AF_INET, SOCK_STREAM, 0);

    // if(sock_desk<0){
    //     print_error("Error create socket\n");
    //     return false;
    // }


    // struct sockaddr_in addr; memset(&addr, 0, sizeof(addr));

    // addr.sin_family = AF_INET;
    // addr.sin_port = htons(PORT_MODEL); // или любой другой порт...
    // addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    
    // if(connect(sock_desk,(struct sockaddr *)&addr, sizeof(addr) ) < 0)
    // {
    //     print_error("Not connetc to model\n");
    //     return false;
    // }

    // send(sock_desk, message, sizeof(message), 0);
    // recv(sock_desk, buf, 2, 0);
    
    // print_debug("kvit = %d\n", buf[0]);
    
    // close(sock_desk);
    


    return true;
}