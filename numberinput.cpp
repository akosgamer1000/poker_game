#include "numberinput.hpp"
#include "graphics.hpp"
#include <string>

using namespace genv;



int Number_input::get_number() const {
    return _content;
}

void Number_input::set_number(int n) {
    if (n < _min) n = _min;
    if (n > _max) n = _max;
    _content = n;
}


Number_input::Number_input(Base* b,int x, int y, int sx, int sy, int min, int max)
    : Widget(b,x, y, sx, sy),
    _content(0),
    _cursor_pos(0),
    _focused(false),
    _min(min),
    _max(max) {}


void Number_input::draw() {
    if(_visible){
        if (_focused) gout << color(255, 255, 255);
        else gout << color(150, 150, 150);


        gout << move_to(_x, _y) << box(_size_x, _size_y);


        gout << move_to(_x + 2, _y + 2)
             << color(0, 0, 0)
             << box(_size_x - 4, _size_y - 4);

        int arrow_x = _x + 5;
        int mid_y = _y + _size_y / 2;

        gout << color(255, 255, 255);


        gout << move_to(arrow_x, mid_y - 5)
             << line(5, -5)
             << move_to(arrow_x + 5, mid_y - 10)
             << line(5, 5);


        gout << move_to(arrow_x, mid_y + 5)
             << line(5, 5)
             << move_to(arrow_x + 5, mid_y + 10)
             << line(5, -5);


        std::string visible_text = std::to_string( ( _content));
        int max_width = _size_x - 40;

        while (gout.twidth(visible_text) > max_width && visible_text.length() > 0) {
            visible_text.erase(0, 1);
        }

        gout << move_to(_x + 25,
                        _y + _size_y / 2 + (gout.cascent() + gout.cdescent()) / 4)
             << color(255, 255, 255)
             << text(visible_text);


        if (_focused) {
            int cursor_pos = gout.twidth(visible_text);
            gout << move_to(_x + 25 + cursor_pos, _y + 5)
                 << line(0, _size_y - 10);
        }
    }

}


void Number_input::handle(event ev) {
    if(_activ && _visible){
        if (ev.type == ev_mouse && ev.button == btn_left) {

            int arrow_left = _x;
            int arrow_right = _x + 20;
            int mid_y = _y + _size_y / 2;


            if (ev.pos_x > arrow_left && ev.pos_x < arrow_right &&
                ev.pos_y > _y && ev.pos_y < mid_y) {

                set_number(get_number() + 1);
                return;
            }


            if (ev.pos_x > arrow_left && ev.pos_x < arrow_right &&
                ev.pos_y > mid_y && ev.pos_y < _y + _size_y) {

                set_number(get_number() - 1);
                return;
            }

            _focused = (ev.pos_x > _x && ev.pos_x < _x + _size_x &&
                        ev.pos_y > _y && ev.pos_y < _y + _size_y);
        }

        if (_focused && ev.type == ev_key) {


            if (ev.keycode == key_backspace) {
                _content /= 10;
            }


            else if (ev.keycode >= '0' && ev.keycode <= '9') {
                int digit = ev.keycode - '0';

                int new_value;

                if (_content >= 0)
                    new_value = _content * 10 + digit;
                else
                    new_value = _content * 10 - digit;

                if (new_value >= _min && new_value <= _max) {
                    _content = new_value;
                }
            }


            else if (ev.keycode == '-') {


                if (_min < 0) {
                    _content = -_content;
                }
            }


            else if (ev.keycode == key_up) {
                set_number(get_number() + 1);
            }


            else if (ev.keycode == key_down) {
                set_number(get_number() - 1);
            }


            else if (ev.keycode == key_pgup) {
                set_number(get_number() + 10);
            }


            else if (ev.keycode == key_pgdn) {
                set_number(get_number() - 10);
            }
        }
    }


}


