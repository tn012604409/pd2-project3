#ifndef VERTICAL_H
#define VERTICAL_H
#include"blank.h"
#include"Destroy.h"
#include "nineblock.h"
#include"horizontal.h"

class vertical:public Destroy
{
public:
    vertical();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void eliminate(Blank*b[10][10],Blank*clicked);
    virtual int condition(Blank*b[10][10],Blank*clicked);
    virtual ~vertical();
};

#endif // VERTICAL_H
