#include "horizontal.h"

horizontal::horizontal()
{

}

void horizontal::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row=clicked->row;
    int col=clicked->colum;
    int num=clicked->number;

    switch (mode) {
    case 1:
        clicked->number=11;//紅色
        b[row][col-1]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 2:
        clicked->number=21;//黃色
        b[row][col-1]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 3:
        clicked->number=31;//綠色
        b[row][col-1]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 4:
        clicked->number=41;//藍色
        b[row][col-1]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 5:
        clicked->number=11;//紅色
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        b[row][col+1]->number=0;
        break;
    case 6:
        clicked->number=21;//黃色
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        b[row][col+1]->number=0;
        break;
    case 7:
        clicked->number=31;//綠色
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        b[row][col+1]->number=0;
        break;
    case 8:
        clicked->number=41;//藍色
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        b[row][col+1]->number=0;
        break;
    }

}

void horizontal::eliminate(Blank *b[10][10], Blank *clicked)
{
    int row=clicked->row;
    int col=clicked->colum;
    int num=clicked->number;
}

int horizontal::condition(Blank *b[10][10], Blank *clicked)
{
    int row=clicked->row;
    int col=clicked->colum;
    int num=clicked->number;
    if(num!=0&&num!=5){
       //上一下二
    if(num%10==0){//普通糖果
       if(col>=1&&col<=7&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10*10))){
            if(num==10){
               return 1;
            }
            else if(num==20){
               return 2;
            }
            else if(num==30){
               return 3;
            }
            else if(num==40){
               return 4;
            }
       }
    }
    else if((num%10)!=0){//特殊糖果
       num/=10;
       if(col>=1&&col<=7&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10))){
           if(num==10){
              return 1;
           }
           else if(num==20){
              return 2;
           }
           else if(num==30){
              return 3;
           }
           else if(num==40){
              return 4;
           }
       }
    }
    if(num%10==0){//普通糖果
       if(col>=2&&col<=8&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))){
            if(num==10){
               return 5;
            }
            else if(num==20){
               return 6;
            }
            else if(num==30){
               return 7;
            }
            else if(num==40){
               return 8;
            }
       }
    }
    else if(num/10!=0){//特殊糖果，還沒把row跟colum對調
       num/=10;
       if(col>=2&&col<=8&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))){
           if(num==1){
              return 5;
           }
           else if(num==2){
              return 6;
           }
           else if(num==3){
              return 7;
           }
           else if(num==4){
              return 8;
           }
       }
    }
  }
 return 0;
}

horizontal::~horizontal()
{

}

