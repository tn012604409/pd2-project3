#include "nineblock.h"

nineblock::nineblock()
{

}

void nineblock::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row=clicked->row;
    int col=clicked->colum;
    int num=clicked->number;

    switch (mode) {
    case 1:
        clicked->number=13;//紅色
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 2:
        clicked->number=23;//黃色
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 3:
        clicked->number=33;//綠色
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 4:
        clicked->number=43;//藍色
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 5:
        clicked->number=13;//紅色
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 6:
        clicked->number=23;//黃色
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 7:
        clicked->number=33;//綠色
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 8:
        clicked->number=43;//藍色
        b[row+1][col]->number=0;
        b[row+2][col]->number=0;
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 9:
        clicked->number=13;//紅色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 10:
        clicked->number=23;//黃色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 11:
        clicked->number=33;//綠色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 12:
        clicked->number=43;//藍色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 13:
        clicked->number=13;//紅色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 14:
        clicked->number=23;//黃色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 15:
        clicked->number=33;//綠色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 16:
        clicked->number=43;//藍色
        b[row-1][col]->number=0;
        b[row-2][col]->number=0;
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    }
}

void nineblock::eliminate(Blank *b[10][10], Blank *clicked)
{
    int row=clicked->row;
    int col=clicked->colum;
    if(row>=1&&col>=1)b[row-1][col-1]->number=0;    //左上
    if(row>=1)b[row-1][col]->number=0;      //上中
    if(row>=1&&col<=8)b[row-1][col+1]->number=0;    //右上
    if(col>=1)b[row][col-1]->number=0;      //右中
    if(col<=8)b[row][col+1]->number=0;      //左中
    if(row<=8&&col>=1)b[row+1][col-1]->number=0;    //左下
    if(row<=8)b[row+1][col]->number=0;      //下中
    if(row<=8&&col<=8)b[row+1][col+1]->number=0;    //右下
}

int nineblock::condition(Blank *b[10][10], Blank *clicked)
{
    int row=clicked->row;//這是甚麼意思QQ
    int col=clicked->colum;
    int num=clicked->number;
    if(num!=0&&num!=5){
       //上一下二
    if(num%10==0){//普通糖果
        //左上L
        if(row>=0&&row<=7&&col>=0&&col<=7&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10*10))&&((num==b[row+2][col]->number||num==b[row+2][col]->number/10*10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10*10))){
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
        else if(num%10!=0){//特殊糖果
            if(row>=0&&row<=7&&col>=0&&col<=7&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10*10))&&((num==b[row+2][col]->number||num==b[row+2][col]->number/10*10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10*10))){
                num/=10;
                num=num*10;
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
        //右上L
        if(row>=0&&row<=7&&col>=2&&col<=9&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10*10))&&((num==b[row+2][col]->number||num==b[row+2][col]->number/10*10))&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))){
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
        else if(num%10!=0){//特殊糖果
            if(row>=0&&row<=7&&col>=2&&col<=9&&((num==b[row+1][col]->number||num==b[row+1][col]->number/10*10))&&((num==b[row+2][col]->number||num==b[row+2][col]->number/10*10))&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))){
                num/=10;
                num=num*10;
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
        //左下L
        if(row>=2&&row<=9&&col>=0&&col<=7&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10*10))&&((num==b[row-2][col]->number||num==b[row-2][col]->number/10*10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10*10))){
            if(num==10){
               return 9;
            }
            else if(num==20){
               return 10;
            }
            else if(num==30){
               return 11;
            }
            else if(num==40){
               return 12;
            }
       }
        else if(num%10!=0){//特殊糖果
            if(row>=2&&row<=9&&col>=0&&col<=7&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10*10))&&((num==b[row-2][col]->number||num==b[row-2][col]->number/10*10))&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10*10))){
                num/=10;
                num=num*10;
                if(num==10){
                   return 9;
                }
                else if(num==20){
                   return 10;
                }
                else if(num==30){
                   return 11;
                }
                else if(num==40){
                   return 12;
                }
            }
        }
        //右下L
        if(row>=2&&row<=9&&col>=2&&col<=9&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10*10))&&((num==b[row-2][col]->number||num==b[row-2][col]->number/10*10))&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))){
            if(num==10){
               return 13;
            }
            else if(num==20){
               return 14;
            }
            else if(num==30){
               return 15;
            }
            else if(num==40){
               return 16;
            }
       }
        else if(num%10!=0){//特殊糖果
            if(row>=2&&row<=9&&col>=2&&col<=9&&((num==b[row-1][col]->number||num==b[row-1][col]->number/10*10))&&((num==b[row-2][col]->number||num==b[row-2][col]->number/10*10))&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))){
                num/=10;
                num=num*10;
                if(num==10){
                   return 13;
                }
                else if(num==20){
                   return 14;
                }
                else if(num==30){
                   return 15;
                }
                else if(num==40){
                   return 16;
                }
            }
        }
     }
   }
   return 0;

}

nineblock::~nineblock()
{

}

