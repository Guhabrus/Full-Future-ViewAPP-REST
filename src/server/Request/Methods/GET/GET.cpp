/**
 * @file GET.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */


//********************LOCAL*************************
#include "GET.h"
#include "../../RequestObject/ObjectBase/ObjectBase.h"



bool Get::send_request(ObjectBase* object_p){
    object_p->send_request();                               
    return true;
}