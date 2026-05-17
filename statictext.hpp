#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP
#include "widgets.hpp"


class Statictext:public Widget
{
protected :

    std::string textt;
public:
           Statictext(int x, int y, int sx, int sy,std::string _text);
         virtual void draw() override ;
        virtual void handle(genv::event ev);


};

#endif // STATICTEXT_HPP
