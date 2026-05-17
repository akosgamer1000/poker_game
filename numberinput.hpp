#ifndef NUMBERINPUT_H
#define NUMBERINPUT_H

#include "widgets.hpp"
#include <string>

class Number_input : public Widget {
protected:
    int _content;
    int _cursor_pos;
    bool _focused;

    int _min;
    int _max;



public:
   Number_input(Base *b,int x, int y, int sx, int sy, int min, int max);

    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    int get_number() const;
    void set_number(int n);


};

#endif
