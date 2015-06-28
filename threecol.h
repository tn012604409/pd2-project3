#ifndef THREECOL_H
#define THREECOL_H
#include"blank.h"
#include"Destroy.h"
#include "nineblock.h"
#include"horizontal.h"

class threecol:public Destroy
{
public:
    threecol();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void eliminate(Blank*b[10][10],Blank*clicked);
    virtual int condition(Blank*b[10][10],Blank*clicked);
    virtual ~threecol();
};

#endif // THREECOL_H
