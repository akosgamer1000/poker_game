#ifndef BUTTON_H
#define BUTTON_H
#include "widgets.hpp"
#include <functional>
class Button:public Widget
{
public:
    Button(Base* b,int x, int y, int sx, int sy,std::function<void()> func,std::string text);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    void setTtext(std::string t);

protected:
    std::function<void()> func;
    std::string text;
};

#endif // BUTTON_H.
