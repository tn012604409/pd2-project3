#include "threerow.h"

threerow::threerow()
{

}

threerow::~threerow()
{

}



void threerow::spawn(Blank *b[10][10], Blank *clicked, int mode)
{
    int row=clicked->row;
    int col=clicked->colum;
    int num=clicked->number;

    switch (mode) {
    case 1:
        clicked->number=0;//紅色
        b[row][col+1]->number=0;
        b[row][col-1]->number=0;
        break;
    case 2:
        clicked->number=0;//黃色
        b[row][col+1]->number=0;
        b[row][col-1]->number=0;
        break;
    case 3:
        clicked->number=0;//綠色
        b[row][col+1]->number=0;
        b[row][col-1]->number=0;
        break;
    case 4:
        clicked->number=0;//藍色
        b[row][col+1]->number=0;
        b[row][col-1]->number=0;
        break;
    case 5:
        clicked->number=0;//紅色
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 6:
        clicked->number=0;//黃色
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 7:
        clicked->number=0;//綠色
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 8:
        clicked->number=0;//藍色
        b[row][col-1]->number=0;
        b[row][col-2]->number=0;
        break;
    case 9:
        clicked->number=0;//紅色
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 10:
        clicked->number=0;//黃色
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 11:
        clicked->number=0;//綠色
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    case 12:
        clicked->number=0;//藍色
        b[row][col+1]->number=0;
        b[row][col+2]->number=0;
        break;
    }
}

void threerow::eliminate(Blank *b[10][10], Blank *clicked)
{
    int col=clicked->colum;
    for(int i=0;i<10;i++){
        b[i][col]->number=0;
    }
}

int threerow::condition(Blank *b[10][10], Blank *clicked)
{
    int row=clicked->row;//這是甚麼意思QQ
    int col=clicked->colum;
    int num=clicked->number;
    if(num!=0&&num!=5){
       //上一下二
    if(num%10==0){//普通糖果
        //左一右一
        if(row>=0&&row<=9&&col>=1&&col<=8&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))){
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
            num/=10;
            num=num*10;
        if(row>=0&&row<=9&&col>=1&&col<=8&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))){
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
    }
    if(num%10==0){//普通糖果
        //左二右一
        if(row>=0&&row<=9&&col>=2/*&&col<=8*/&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))){
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
            num/=10;
            num=num*10;
        if(row>=0&&row<=9&&col>=2/*&&col<=8*/&&((num==b[row][col-1]->number||num==b[row][col-1]->number/10*10))&&((num==b[row][col-2]->number||num==b[row][col-2]->number/10*10))){
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
    if(num%10==0){//普通糖果
        //左一右二
        if(row>=0&&row<=9/*&&col>=1*/&&col<=7&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10*10))){
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
            num/=10;
            num=num*10;
        if(row>=0&&/*row<=9&&col>=1&&*/col<=7&&((num==b[row][col+1]->number||num==b[row][col+1]->number/10*10))&&((num==b[row][col+2]->number||num==b[row][col+2]->number/10*10))){

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
    }
   }
    return 0;
}
