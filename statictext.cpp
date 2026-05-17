#include "statictext.h"

statictext::statictext(Base* b,int x, int y, int sx, int sy):Widget(b,x,y,sx,sy) {
    content="";

}
void statictext::draw(){
    int szoveg_szelesseg = genv::gout.twidth(content);
    int szoveg_magassag = genv::gout.cascent() + genv::gout.cdescent();
    int cel_x = _x + (_size_x - szoveg_szelesseg) / 2;
    int cel_y = _y + (_size_y - szoveg_magassag) / 2 + genv::gout.cascent();
    genv::gout << genv::move_to(cel_x, cel_y)
               << genv::color(255, 255, 255)
               << genv::text(content);

}

void statictext::handle(genv::event){

}

void statictext::setContent(std::string con){
    content=con;
}
std::string statictext::getContent(){
    return content;
}
