#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"blank.h"
#include"Destroy.h"
#include"star.h"
#include"vertical.h"
#include"horizontal.h"
#include"nineblock.h"
#include <QDebug>
#include"threecol.h"
#include"threerow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            b[i][j]=new Blank(i,j,this);//跑10*10次在mainwindow設立100個buttom
            connect(b[i][j],SIGNAL(Click(int,int)),this,SLOT(button_clicked(int,int)));
            connect(b[i][j],SIGNAL(movedone()),this,SLOT(zeroVanish()));//this是mainwindow接收
        }
    gamestart();
}
void MainWindow::gamestart(){
     for(int i=0; i<10; i++){
         for(int j=0; j<10; j++){
             b[i][j]->setNumber();
             b[i][j]->setButtonPicture();
             if(j>=2&&b[i][j]->number==b[i][j-2]->number&&b[i][j]->number==b[i][j-1]->number)
                 j--;
             if(i>=2&&b[i][j]->number==b[i-2][j]->number&&b[i][j]->number==b[i-1][j]->number)
                j--;
         }
     }
}

void MainWindow::setClickPicture(Blank *b)
{
    if(!isClicked){
        switch(b->number){
        case 10:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/red_choose.png")));b->buttom->setIconSize(b->buttom->size());break;
        case 20:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/yellow_choose.png")));b->buttom->setIconSize(b->buttom->size());break;
        case 30:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/green_choose.png")));b->buttom->setIconSize(b->buttom->size());break;
        case 40:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/blue_choose.png")));b->buttom->setIconSize(b->buttom->size());break;
        case 5:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/star_choose.png")));b->buttom->setIconSize(b->buttom->size());break;
        case 11:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/red_row_choose.png")));b->buttom->setIconSize(b->buttom->size());break;
        case 21:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/yellow_row_choose.png")));b->buttom->setIconSize(b->buttom->size());break;
        case 31:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/green_row_choose.png")));break;
        case 41:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/blue_row_choose.png")));break;
        case 12:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/red_colum_choose.png")));b->buttom->setIconSize(b->buttom->size());break;
        case 22:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/yellow_colum_choose.png")));break;
        case 32:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/green_colum_choose.png")));break;
        case 42:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/blue_colum_choose.png")));break;
        case 13:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/red_bumb_choose.png")));b->buttom->setIconSize(b->buttom->size());break;
        case 23:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/yellow_bumb_choose.png")));break;
        case 33:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/green_bumb_choose.png")));break;
        case 43:
            b->buttom->setIcon(QIcon(QPixmap(":/pic/blue_bumb_choose.png")));break;
        }
    }
        else{
            b->setButtonPicture();
    }
}

bool MainWindow::Judge(int row1, int col1, int row2, int col2)
{
    bool A[12]={0};
    A[0]=JudgeStar(row1,col1);
    A[1]=JudgeStar(row2,col2);
    A[2]=JudgeNine(row1,col1);
    A[3]=JudgeNine(row2,col2);
    A[4]=JudgeVertical(row1,col1);
    A[5]=JudgeVertical(row2,col2);
    A[6]=JudgeHorizontal(row1,col1);
    A[7]=JudgeHorizontal(row2,col2);
    A[8]=JudgeThreeRow(row1,col1);
    A[9]=JudgeThreeRow(row2,col2);
    A[10]=JudgeThreeCol(row1,col1);
    A[11]=JudgeThreeCol(row2,col2);
    /*for(int i=0;i<12;i++){
        if(A[i]==true){
            while(1){
                setboard();//呼叫重新整理的function
                if(TotalJudge()==true){
                    break;
                }
            }
            for(int i=9; i>=0; i--){
                for(int j=9; j>=0; j--){
                    if(b[i][j]->number==0){
                        b[i][j]->setNumber();
                        b[i][j]->setButtonPicture();
                        if(j>=2&&b[i][j]->number==b[i][j-2]->number&&b[i][j]->number==b[i][j-1]->number)
                            j++;//left
                        else if(j<=7&&b[i][j]->number==b[i][j+1]->number&&b[i][j]->number==b[i][j+2]->number)
                            j++;//right
                        else if(j>=1&&j<=8&&b[i][j]->number==b[i][j-1]->number&&b[i][j]->number==b[i][j+1]->number)
                            j++;//middle
                        else if(i<=7&&b[i][j]->number==b[i+2][j]->number&&b[i][j]->number==b[i+1][j]->number)
                            j++;//down
                    }
                }
            }
        return true;
        }
    }qDebug()<<"LLLL";
    return false;*/

}
void MainWindow::setboard()//我是重新整理的function
{

    int temp[10]={0};
    for(int j=0;j<10;j++)
    {
    int h=0;
    int k=10;
    for(int i=0;i<10;i++)
        if(b[i][j]->number!=0){
            temp[10-k]=b[i][j]->number;
            k--;
    }
    for(int i=0;i<10;i++){
        b[i][j]->number=0;
    }
    for(int i=9;i>=0;--i){
        if(temp[i]!=0){
            b[9-h][j]->number=temp[i];
            h++;
        }
    }
    for(int i=0;i<10;i++){
        temp[i]=0;
    }
    }



}


bool MainWindow::JudgeStar(int row, int col)
{
    int return_value;
    bool Any_spawn=false;//有沒有生成星星
    Destroy *d=new star;//為何知道是誰的function，是因為指到star嗎??
    return_value=d->condition(b,b[row][col]);//知道要消去的狀況
    qDebug()<<"STAR"<<return_value;
    if(return_value){
        switch (return_value) {
        case 1:
            d->spawn(b,b[row][col],1);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 2:
            d->spawn(b,b[row][col],2);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        }
    }
    delete d;
    /*return_value=star::condition(b,b[row][col]);
    if(return_value){
        switch (return_value) {
        case 1:
            star::spawn(b,b[row][col],1);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            break;
        case 2:
            star::spawn(b,b[row][col],2);
            Any_spawn=true;
            break;
        }*/
    return Any_spawn;

}

void MainWindow::reNewPicture()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            b[i][j]->setButtonPicture();
        }
}

bool MainWindow::JudgeVertical(int row, int col)
{
    int return_value;
    bool Any_spawn=false;//有沒有生成星星
    Destroy *t=new vertical ;//為何知道是誰的function，是因為指到star嗎??
    return_value=t->condition(b,b[row][col]);//知道要消去的狀況
    qDebug()<<"Ver"<<return_value;
    if(return_value){
        switch (return_value) {
        case 1:
            t->spawn(b,b[row][col],1);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 2:
            t->spawn(b,b[row][col],2);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 3:
            t->spawn(b,b[row][col],3);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 4:
            t->spawn(b,b[row][col],4);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 5:
            t->spawn(b,b[row][col],5);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 6:
            t->spawn(b,b[row][col],6);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 7:
            t->spawn(b,b[row][col],7);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 8:
            t->spawn(b,b[row][col],8);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        }
    }
    delete t;
    return Any_spawn;
}

bool MainWindow::JudgeHorizontal(int row, int col)
{
    int return_value;
    bool Any_spawn=false;//有沒有生成星星
    Destroy *t=new horizontal ;//為何知道是誰的function，是因為指到star嗎??
    return_value=t->condition(b,b[row][col]);//知道要消去的狀況
    qDebug()<<"Hor"<<return_value;
    if(return_value){
        switch (return_value) {
        case 1:
            t->spawn(b,b[row][col],1);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 2:
            t->spawn(b,b[row][col],2);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 3:
            t->spawn(b,b[row][col],3);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 4:
            t->spawn(b,b[row][col],4);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 5:
            t->spawn(b,b[row][col],5);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 6:
            t->spawn(b,b[row][col],6);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 7:
            t->spawn(b,b[row][col],7);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 8:
            t->spawn(b,b[row][col],8);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        }
    }
    delete t;
    return Any_spawn;

}

bool MainWindow::JudgeNine(int row, int col)
{
    int return_value;
    bool Any_spawn=false;//有沒有生成星星
    Destroy *t=new nineblock ;//為何知道是誰的function，是因為指到star嗎??
    return_value=t->condition(b,b[row][col]);//知道要消去的狀況
    qDebug()<<"nine"<<return_value;
    if(return_value){
        switch (return_value) {
        case 1:
            t->spawn(b,b[row][col],1);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 2:
            t->spawn(b,b[row][col],2);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 3:
            t->spawn(b,b[row][col],3);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 4:
            t->spawn(b,b[row][col],4);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 5:
            t->spawn(b,b[row][col],5);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 6:
            t->spawn(b,b[row][col],6);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 7:
            t->spawn(b,b[row][col],7);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 8:
            t->spawn(b,b[row][col],8);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 9:
            t->spawn(b,b[row][col],9);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 10:
            t->spawn(b,b[row][col],10);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 11:
            t->spawn(b,b[row][col],11);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 12:
            t->spawn(b,b[row][col],12);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 13:
            t->spawn(b,b[row][col],13);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 14:
            t->spawn(b,b[row][col],14);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 15:
            t->spawn(b,b[row][col],15);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 16:
            t->spawn(b,b[row][col],16);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        }
    }
    delete t;
    return Any_spawn;
}

bool MainWindow::JudgeThreeCol(int row, int col)
{
    int return_value;
    bool Any_spawn=false;//有沒有生成星星
    Destroy *t=new threecol ;//為何知道是誰的function，是因為指到star嗎??
    return_value=t->condition(b,b[row][col]);//知道要消去的狀況
    qDebug()<<"Threecol"<<return_value;
    if(return_value){
        switch (return_value) {
        case 1:
            t->spawn(b,b[row][col],1);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 2:
            t->spawn(b,b[row][col],2);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 3:
            t->spawn(b,b[row][col],3);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 4:
            t->spawn(b,b[row][col],4);
            Any_spawn=true;
            break;
        case 5:
            t->spawn(b,b[row][col],5);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 6:
            t->spawn(b,b[row][col],6);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 7:
            t->spawn(b,b[row][col],7);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 8:
            t->spawn(b,b[row][col],8);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 9:
            t->spawn(b,b[row][col],9);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 10:
            t->spawn(b,b[row][col],10);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 11:
            t->spawn(b,b[row][col],11);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 12:
            t->spawn(b,b[row][col],12);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        }
    }
    delete t;
    return Any_spawn;
}

bool MainWindow::JudgeThreeRow(int row, int col)
{
    int return_value;
    bool Any_spawn=false;//有沒有生成星星
    Destroy *t=new threerow ;//為何知道是誰的function，是因為指到star嗎??
    return_value=t->condition(b,b[row][col]);//知道要消去的狀況
    qDebug()<<"threeRow"<<return_value;
    if(return_value){
        switch (return_value) {
        case 1:
            t->spawn(b,b[row][col],1);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 2:
            t->spawn(b,b[row][col],2);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 3:
            t->spawn(b,b[row][col],3);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 4:
            t->spawn(b,b[row][col],4);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 5:
            t->spawn(b,b[row][col],5);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 6:
            t->spawn(b,b[row][col],6);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 7:
            t->spawn(b,b[row][col],7);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 8:
            t->spawn(b,b[row][col],8);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 9:
            t->spawn(b,b[row][col],9);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 10:
            t->spawn(b,b[row][col],10);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 11:
            t->spawn(b,b[row][col],11);//指到star裡的spawn
            Any_spawn=true;//生成星星了
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        case 12:
            t->spawn(b,b[row][col],12);
            Any_spawn=true;
            for(int i=0;i<10;i++){
                    qDebug()<<(b[i][0]->number)<<(b[i][1]->number)<<(b[i][2]->number)<<(b[i][3]->number)<<(b[i][4]->number)<<(b[i][5]->number)<<(b[i][6]->number)<<(b[i][7]->number)<<(b[i][8]->number)<<(b[i][9]->number);
                }
            break;
        }
    }
    delete t;
    return Any_spawn;
}

bool MainWindow::TotalJudge()
{
           for(int i=0;i<10;i++){
               for(int j=0;j<10;j++){
                   if(JudgeStar(i,j))
                       return true;
               }
           }
           for(int i=0;i<10;i++){
               for(int j=0;j<10;j++){
                   if(JudgeNine(i,j))
                       return true;
               }
           }
           for(int i=0;i<10;i++){
               for(int j=0;j<10;j++){
                   if(JudgeVertical(i,j))
                       return true;
               }
           }
           for(int i=0;i<10;i++){
               for(int j=0;j<10;j++){
                   if(JudgeHorizontal(i,j))
                       return true;
               }
           }
           /*for(int i=0;i<10;i++){
               for(int j=0;j<10;j++){
                   if(JudgeThreeCol(i,j))
                       return true;
               }
           }
           for(int i=0;i<10;i++){
               for(int j=0;j<10;j++){
                   if(JudgeThreeRow(i,j))
                       return true;
               }
           }*/
           return false;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_clicked(int R, int C)
{
    if(!isClicked){
        setClickPicture(b[R][C]);
        isClicked=true;
        record_R=R;
        record_C=C;
    }else{
        if(record_R==R&&C-1==record_C){
            *b[record_R][record_C]-b[R][C];
            if(!Judge(record_R,record_C,R,C)){
                *b[record_R][record_C]-b[R][C];qDebug()<<"左";
            }
        }
        else if(record_R==R&&C+1==record_C){
            *b[R][C]-b[record_R][record_C];
            if(!Judge(record_R,record_C,R,C)){
                *b[R][C]-b[record_R][record_C];qDebug()<<"右";
            }
        }
        else if (R-1==record_R&&record_C==C){
            *b[record_R][record_C]|b[R][C];
            if(!Judge(record_R,record_C,R,C)){
                *b[record_R][record_C]|b[R][C];qDebug()<<"上";
            }
        }
        else if(R+1==record_R&&record_C==C){
            *b[R][C]|b[record_R][record_C];
            if(!Judge(record_R,record_C,R,C)){
                *b[R][C]|b[record_R][record_C];qDebug()<<"下";
            }
        }
        else{
            setClickPicture(b[record_R][record_C]);
        }
        isClicked=false;
    }
}

void MainWindow::zeroVanish()
{
    reNewPicture();
}


