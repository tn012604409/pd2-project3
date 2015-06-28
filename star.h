#ifndef STAR_H
#define STAR_H
#include"blank.h"
#include"Destroy.h"

class star:public Destroy
{
public:
    star();
    virtual void spawn(Blank*b[10][10],Blank*clicked,int mode);
    virtual void eliminate(Blank*b[10][10],Blank*clicked);
    virtual int condition(Blank*b[10][10],Blank*clicked);
    virtual ~star();
};

#endif // STAR_H
