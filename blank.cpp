#include "blank.h"
#include <ctime>
#include <cstdlib>

Blank::Blank(int R,int C, QWidget *parent):row(R),colum(C), QObject(parent)
{
    buttom=new QPushButton(parent);//在mainwindow建立buttom
    buttom->setGeometry(colum*50,row*50,50,50);//(colum的間隔,row的間隔,寬,高)
    connect(buttom,SIGNAL(clicked()),this,SLOT(click()));//接收訊號，this指的是Blank，指到Blank.h裡的void click()，在指到.cpp裡的click()
    shift=1;
    time=new QTimer();

}

void Blank::setNumber()
{
        number=(rand()%4+1)*10;//產生10~40
        return;
}

void Blank::setButtonPicture()
{
    switch(number){
    case 10:
        buttom->setIcon(QIcon(QPixmap(":/pic/red.png")));buttom->setIconSize(buttom->size());break;
    case 20:
        buttom->setIcon(QIcon(QPixmap(":/pic/yellow.png")));buttom->setIconSize(buttom->size());break;
    case 30:
        buttom->setIcon(QIcon(QPixmap(":/pic/green.png")));buttom->setIconSize(buttom->size());break;
    case 40:
        buttom->setIcon(QIcon(QPixmap(":/pic/blue.png")));buttom->setIconSize(buttom->size());break;
    case 5:
        buttom->setIcon(QIcon(QPixmap(":/pic/star.png")));buttom->setIconSize(buttom->size());break;
    case 11:
        buttom->setIcon(QIcon(QPixmap(":/pic/red_row")));buttom->setIconSize(buttom->size());break;
    case 21:
        buttom->setIcon(QIcon(QPixmap(":/pic/yellow_row.png")));buttom->setIconSize(buttom->size());break;
    case 31:
        buttom->setIcon(QIcon(QPixmap(":/pic/green_row.png")));break;
    case 41:
        buttom->setIcon(QIcon(QPixmap(":/pic/blue_row.png")));break;
    case 12:
        buttom->setIcon(QIcon(QPixmap(":/pic/red_colum.png")));buttom->setIconSize(buttom->size());break;
    case 22:
        buttom->setIcon(QIcon(QPixmap(":/pic/yellow_colum.png")));break;
    case 32:
        buttom->setIcon(QIcon(QPixmap(":/pic/green_colum.png")));break;
    case 42:
        buttom->setIcon(QIcon(QPixmap(":/pic/blue_colum.png")));break;
    case 13:
        buttom->setIcon(QIcon(QPixmap(":/pic/red_bumb.png")));buttom->setIconSize(buttom->size());break;
    case 23:
        buttom->setIcon(QIcon(QPixmap(":/pic/yellow_bumb.png")));break;
    case 33:
        buttom->setIcon(QIcon(QPixmap(":/pic/green_bumb.png")));break;
    case 43:
        buttom->setIcon(QIcon(QPixmap(":/pic/blue_bumb.png")));break;
    default:
        buttom->setIcon(QIcon(QPixmap("")));//no picture
    }
}

Blank::~Blank()
{

}
void Blank::click(){//emit 發出訊號
    emit Click(row,colum);//emit 發出訊號b[i][j]
}
void Blank::moveleft(){//讓button有移動的感覺
    buttom->setGeometry(colum *50-shift*10,row*50,50,50);
    shift++;
    if(shift>5){
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveleft()));
        buttom->setGeometry(colum*50,row*50,50,50);
        setButtonPicture();
        emit movedone();
    }
}
void Blank::moveright(){
    buttom->setGeometry(colum *50+shift*10,row*50,50,50);
    shift++;
    if(shift==5){
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveright()));
        buttom->setGeometry(colum*50,row*50,50,50);
        setButtonPicture();
    }
}

void Blank::moveup()
{       buttom->setGeometry(colum *50,row*50+shift*10,50,50);
        shift++;
        if(shift==5){
            shift=1;
            disconnect(time,SIGNAL(timeout()),this,SLOT(moveup()));
            buttom->setGeometry(colum*50,row*50,50,50);
            setButtonPicture();
        }
    emit movedone();
}

void Blank::movedown()
{
    buttom->setGeometry(colum *50,row*50-shift*10,50,50);
            shift++;
            if(shift==5){
                shift=1;
                disconnect(time,SIGNAL(timeout()),this,SLOT(movedown()));
                buttom->setGeometry(colum*50,row*50,50,50);
                setButtonPicture();
            }
}
void Blank::operator -(Blank *b){
    int tmp_Num=b->number;
    b->number=number;
    number=tmp_Num;
    connect(time,SIGNAL(timeout()),this,SLOT(moveright()));
    connect(b->time,SIGNAL(timeout()),b,SLOT(moveleft()));
    time->start(100);
    b->time->start(100);

}
void Blank::operator |(Blank *b){
    int tmp_Num=b->number;
    b->number=number;
    number=tmp_Num;
    connect(time,SIGNAL(timeout()),this,SLOT(moveup()));
    connect(b->time,SIGNAL(timeout()),b,SLOT(movedown()));
    time->start(100);
    b->time->start(100);

}

