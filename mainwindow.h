#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"blank.h"
#include <QMainWindow>
#include <ctime>
#include <cstdlib>
#include <QDebug>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void gamestart();
    void setClickPicture(Blank *b);
    bool isClicked;
    int record_R;
    int record_C;
    bool Judge(int row1,int col1,int row2,int col2);
    bool JudgeStar(int row ,int col);
    void reNewPicture();
    void setboard();
    bool JudgeVertical(int row, int col);
    bool JudgeHorizontal(int row, int col);
    bool JudgeNine(int row, int col);
    bool JudgeThreeCol(int row, int col);
    bool JudgeThreeRow(int row, int col);
    bool TotalJudge();
    QString str;
    int score;
    int level;
    int level2;
    int level3;





private:
    Ui::MainWindow *ui;
    Blank *b[10][10];   //10*10的button
public slots:
    void button_clicked(int R,int C);
    void zeroVanish();
};

#endif // MAINWINDOW_H
