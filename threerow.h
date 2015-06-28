#ifndef THREEROW_H
#define THREEROW_H
#include"blank.h"
#include"Destroy.h"
#include "nineblock.h"
#include"horizontal.h"

class threerow:public Destroy
{
public:
    threerow();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void eliminate(Blank*b[10][10],Blank*clicked);
    virtual int condition(Blank*b[10][10],Blank*clicked);
    virtual ~threerow();
};

#endif // THREEROW_H
