#ifndef STATICTEXT_H
#define STATICTEXT_H
#include "widgets.hpp";
class statictext:public Widget
{
protected:
    std::string content;
public:
    statictext(Base* b,int x, int y, int sx, int sy);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    void setContent(std::string con);
    std::string getContent();
};

#endif // STATICTEXT_H
