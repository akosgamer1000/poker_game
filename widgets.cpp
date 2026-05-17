#include "widgets.hpp"
#include "graphics.hpp"
#include"base.hpp"
using namespace genv;

Widget::Widget(Base* b, int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy),_pareant(b),_focused(false)
{
    b->register_widget(this);
}
void Widget::unselect(){
    _focused=false;
}
void Widget::select(){
    _focused=true;
}
bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Widget::setX(int x){
    _x=x;
}

void Widget::setY(int y){
    _y=y;
}

void Widget::set_size_X(int x){
    _size_x=x;
}

void Widget::set_size_Y(int y){
    _size_y=y;
}
int Widget::get_size_X(){
    return _size_x;

}
int Widget::get_size_Y(){
    return _size_y;

}

void Widget::setActiv(bool ac){
    _activ=ac;
}
void Widget::setVisibility(bool vs){
    _visible=vs;
}


