/**
 * @file observer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief 
 * 
 */

class Observer
{
    public:
        Observer();
        virtual ~Observer(){}

        virtual void update() =0;
};







#endif