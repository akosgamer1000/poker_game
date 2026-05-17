


#include "input.hpp"
#include "graphics.hpp"

using namespace genv;

Input::Input(Base* b,int x, int y, int sx, int sy)
    : Widget(b,x, y, sx, sy), _content(""){}
void Input::setfoc(bool state){
    _focused=state;
}
void Input::draw() {

    if (_focused) gout << color(255, 255, 255);
    else gout << color(150, 150, 150);


    gout << move_to(_x, _y) << box(_size_x, _size_y);
    gout << move_to(_x + 2, _y + 2) << color(0, 0, 0) << box(_size_x - 4, _size_y - 4);


    std::string visible_text = _content;
    int max_width = _size_x - 20;


    while (gout.twidth(visible_text) > max_width && visible_text.length() > 0) {
        visible_text.erase(0, 1);
    }

    gout << move_to(_x + 10, _y + _size_y / 2 + (gout.cascent() + gout.cdescent()) / 4)
         << color(255, 255, 255) << text(visible_text);

    if (_focused) {
        int cursor_pos = gout.twidth(visible_text);
        gout << move_to(_x + 10 + cursor_pos, _y + 5) << line(0, _size_y - 10);
    }
}

void Input::handle(event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left) {
        _focused = (ev.pos_x > _x && ev.pos_x < _x + _size_x &&
                    ev.pos_y > _y && ev.pos_y < _y + _size_y);
    }

    if (_focused && ev.type == ev_key) {
        if (ev.keycode == key_backspace && _content.length() > 0) {
            _content.pop_back();
        }

        else if (ev.keycode >= 32 && ev.keycode <= 255) {
            _content += (char)ev.keycode;
        }
    }
}
void Input::reset(){
    _content="";
}
