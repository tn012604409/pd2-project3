#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include"blank.h"
#include"Destroy.h"
#include "nineblock.h"
#include"vertical.h"

class horizontal:public Destroy
{
public:
    horizontal();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void eliminate(Blank*b[10][10],Blank*clicked);
    virtual int condition(Blank*b[10][10],Blank*clicked);
    virtual ~horizontal();
};

#endif // HORIZONTAL_H
