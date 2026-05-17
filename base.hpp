#ifndef BASE_H
#define BASE_H
#include "widgets.hpp"
using namespace std;
class Base
{
public:
    Base(int w,int h);
    void event_loop();
    void register_widget(Widget *);
    virtual void action(std::string id)=0;
    void opengui();
    void setW(int _w);
     void setH(int _H);

protected:
    vector<Widget*> _widgets;
    int w;
    int h;
    bool _visible;


};

#endif // BASE_H
