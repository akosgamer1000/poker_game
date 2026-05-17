#include "imagewiewer.h"
#include "fstream"
using namespace genv;
imagewiewer::imagewiewer(Base* b,int x, int y, int sx, int sy,std::string sc):Widget(b,x,y,sx,sy) {
    source=sc;

        load();


}
void imagewiewer::load() {
    std::ifstream f(source);
    if (!f.is_open()) return;

    int w, h;

    if (!(f >> w >> h)) return;

    img.open(w, h);
    _size_x = w;
    _size_y = h;

    int r, g, b;

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (f >> r >> g >> b) {
                img << move_to(x, y)
                << color(r, g, b)
                << dot;
            }
        }
    }
    f.close();
}
void imagewiewer::setSource(std::string s){
    source=s;
    load();
}
std::string imagewiewer::getSource(){
    return source;
}
void imagewiewer::draw(){
    if(_visible){
        int bal_szel = _x - _size_x / 2;
        int felso_szel = _y - _size_y / 2;


        gout << stamp(img, bal_szel, felso_szel);
    }


}
void imagewiewer::handle(event){

}
void imagewiewer::setCere(bool b){
    csre=b;
}
bool imagewiewer::getCere(){
    return csre;
}

