#ifndef BLANK_H
#define BLANK_H
#include <QPushButton>
#include <QObject>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <QKeyEvent>
#include <QString>
class Blank:public QObject
{
    Q_OBJECT//copy QObject的function??
public:
    Blank(int R,int C, QWidget *parent);//*parent:mainwindow的代名詞
    ~Blank();
public:
    const int row;
    const int colum;
    int number;//用數字代表顏色和炸彈
    QPushButton * buttom;//點擊(signal->slot(一開始沒有關係，需要connect(繼承QObject)))
    void setNumber();
    void setButtonPicture();//設置圖片
    QTimer *time;
    int shift;
    void operator-(Blank *b);
    void operator|(Blank *b);
public slots://只有這裡可以吃訊號
    void click();//function的形式
    void moveleft();
    void moveright();
    void moveup();
    void movedown();
signals://發出訊號的人
    void Click(int R,int C);//可以發出row跟colum
    void movedone();
};

#endif // BLANK_H
