#include "vertical.h"

vertical::vertical()
{

}

void vertical::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row=clicked->row;
    int col=clicked->colum;
    int num=clicked->number;

    switch (mode) {
    case 1:
        clicked->number=12;//紅色
        b[row-1][col]->number=0;
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        break;
    case 2:
        clicked->number=22;//黃色
        b[row-1][col]->number=0;
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        break;
    case 3:
        clicked->number=32;//綠色
        b[row-1][col]->number=0;
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        break;
    case 4:
        clicked->number=42;//藍色
        b[row-1][col]->number=0;
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        break;
    case 5:
        clicked->number=12;//紅色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row+1][col]->number=0;
        break;
    case 6:
        clicked->number=22;//黃色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row+1][col]->number=0;
        break;
    case 7:
        clicked->number=32;//綠色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row+1][col]->number=0;
        break;
    case 8:
        clicked->number=42;//藍色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row+1][col]->number=0;
        break;
    }

}

void vertical::eliminate(Blank *b[10][10], Blank *clicked)//垂直消除一整行
{
    int col=clicked->colum;
    for(int i=0;i<10;i++){
        b[i][col]->number=0;
    }
}

int vertical::condition(Blank *b[10][10], Blank *clicked)
{
    int row=clicked->row;//這是甚麼意思QQ
    int col=clicked->colum;
    int num=clicked->number;
    if(num!=0&&num!=5){
       //上一下二
    if(num%10==0){//普通糖果
       if(row>=1&&row<=7&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10*10))&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10*10))&&((num==b[row+2][col]->number||num==b[row+2][col]->number/10*10))){
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
    else if((num%10)!=0){//特殊糖果可能會有問題
       num/=10;
       num=num*10;
       if(row>=1&&row<=7&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number||num==b[row+2][col]->number/10))){
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
       if(row>=2&&row<=8&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10*10))&&((num==b[row-2][col]->number||num==b[row-2][col]->number/10*10))&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10*10))){
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
    else if(num/10!=0){//特殊糖果可能會有問題
       num/=10;
       num=num*10;
       if(row>=2&&row<=8&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10))&&((num==b[row-2][col]->number||num==b[row-2][col]->number/10))&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10))){
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
  }
    return 0;
}

vertical::~vertical()
{

}



