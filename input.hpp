#ifndef INPUT_HPP
#define INPUT_HPP

#include "widgets.hpp"
#include <string>

class Input : public Widget {
protected:
    std::string _content;
    int _cursor_pos;

public:

    Input(Base* b,int x, int y, int sx, int sy);

    virtual void draw() override;
    virtual void handle(genv::event ev) override;


    virtual std::string get_value() const { return _content; }
    virtual void reset();
    virtual void setfoc(bool state);
};

#endif
