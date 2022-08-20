/**
 * @file Observer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Observer.h"

#include "../config.h"

Observer::Observer(){
    Config::getInstance().connect(this);
}


