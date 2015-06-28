#include "star.h"
#include"Destroy.h"
#include"nineblock.h"
#include"horizontal.h"
#include"vertical.h"
star::star()
{

}

int star::condition(Blank *b[10][10], Blank *clicked)
{
    int row=clicked->row;//這是甚麼意思QQ
    int col=clicked->colum;
    int num=clicked->number;
    if(num!=0&&num!=5){
        if(num%10==0){//普通糖果
            if(row>=2&&row<=7&&((num==b[row-2][col]->number||num==b[row-2][col]->number/10*10))&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10*10))&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10*10))&&((num==b[row+2][col]->number||num==b[row+2][col]->number/10*10))){
                return 1;//vertical normal
            }
            if(col>=2&&col<=7&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10*10))){
                return 2;//horizontal normal
            }
        }
        else if((num%10)!=0){
            num/=10;//判斷顏色是否相同
            num=num*10;
            if(row>=2&&row<=7&&((num==b[row-2][col]->number||num==b[row-2][col]->number/10*10))&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10*10))&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10*10))&&((num==b[row+2][col]->number||num==b[row+2][col]->number/10*10))){
                return 1;//vertical normal
            }
            if(col>=2&&col<=7&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10*10))){
                return 2;//horizontal normal
            }
        }
    }return 0;
}

void star::eliminate(Blank *b[10][10], Blank *clicked)
{

}

void star::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row=clicked->row;
    int col=clicked->colum;
    int num=clicked->number;
    //int FiveNum[5]={0};
    switch (mode) {
    case 1://橫的星星
        clicked->number=5;
        b[row-2][col]->number=0;
        b[row-1][col]->number=0;
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        break;
   case 2:
        clicked->number=5;//直的星星
        b[row][col-2]->number=0;
        b[row][col-1]->number=0;
        b[row][col+2]->number=0;
        b[row][col+1]->number=0;
        break;
    }
}

star::~star()
{

}

