#include "button.h"
using namespace genv;
Button::Button(Base* _b,int _x, int _y, int _sx, int _sy,std::function<void()> _func,std::string _text):Widget(_b,_x,_y,_sx,_sy) {
    func=_func;
    text=_text;
}
void Button::draw(){
    if(_visible){
        int r;
        int g;
        int b;
        if(_activ){
            r=145;
            g=145;
            b=145;
        } else {
            r=100;
            g=145;
            b=100;
        }
        gout << move_to(_x, _y)
        << color(r,g,b)
        << box(_size_x, _size_y);


        gout << color(0,0,0);


        int tx = _x + (_size_x - gout.twidth(text)) / 2;
        int ty = _y + (_size_y + gout.cascent()) / 2 - 2;

        gout << move_to(tx, ty)
             << genv::text(text);
    }

}
void Button::handle(genv::event ev){
    if(_activ && ev.type == genv::ev_mouse && ev.button == genv::btn_left){
        func();
    }

}
void Button::setTtext(std::string t){
    text=t;
}
