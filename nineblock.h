#ifndef NINEBLOCK_H
#define NINEBLOCK_H
#include"blank.h"
#include"Destroy.h"
#include "horizontal.h"
#include "star.h"
#include"vertical.h"

class nineblock:public Destroy
{
public:
    nineblock();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void eliminate(Blank*b[10][10],Blank*clicked);
    virtual int condition(Blank*b[10][10],Blank*clicked);
    virtual ~nineblock();
};

#endif // NINEBLOCK_H
