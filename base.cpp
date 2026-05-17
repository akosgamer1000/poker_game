#include "base.hpp"
#include "graphics.hpp"
Base::Base(int _w,int _h) {
    w=_w;
    h=_h;

}
using namespace genv;
void Base::opengui(){
    gout.open(w,h);

    gout.load_font("LiberationSans-regular.ttf", 10);
}
void Base::setH(int _h){
    h=_h;
}
void Base::setW(int _w){
    w=_w;
}
void Base::event_loop(){
    event ev;
    int focus = -1;

    while(gin >> ev ) {

        if (ev.type == ev_mouse && ev.button == btn_left) {
            int uj_focus = -1;

            for (size_t i = 0; i < _widgets.size(); i++) {
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    uj_focus = i;
                }
            }



            if (uj_focus != focus) {

                if (focus != -1) {
                    _widgets[focus]->unselect();
                }


                focus = uj_focus;


                if (focus != -1) {
                    _widgets[focus]->select();
                }
            }
        }

        if (focus!=-1) {
            _widgets[focus]->handle(ev);
        }
        gout << color(0,0,0) << move_to(0,0) << box(w,h);
        for (Widget * w : _widgets) {
            w->draw();
        }

        gout << refresh;
    }
}
void Base::register_widget(Widget *wid){
    _widgets.push_back(wid);
}


