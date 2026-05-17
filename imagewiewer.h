#ifndef IMAGEWIEWER_H
#define IMAGEWIEWER_H
#include "widgets.hpp"
class imagewiewer:public Widget
{
protected:
    std::string source;
    genv::canvas img;
    bool csre;
    void load();
public:
    imagewiewer(Base* b,int x, int y, int sx, int sy,std::string sc);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    void setSource(std::string s);
    std::string getSource();
    bool getCere();
    void setCere(bool b);

};

#endif // IMAGEWIEWER_H
