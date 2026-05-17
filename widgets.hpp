#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
class Base;
class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    Base *_pareant;
    bool _focused;
     bool _visible=true;
      bool _activ=true;

public:
    Widget(Base* parent, int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual void unselect();
    virtual void select();
    virtual void setX(int _x);
    virtual void setY(int _y);
    virtual void set_size_X(int _x);
    virtual void set_size_Y(int _y);
    virtual int get_size_X();
    virtual int get_size_Y();
    virtual void setVisibility(bool vs);
    virtual void setActiv(bool ac);


};



#endif // WIDGETS_HPP_INCLUDED
