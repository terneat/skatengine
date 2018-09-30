#ifndef SKATGAMEWINDOW_H
#define SKATGAMEWINDOW_H

#include "ui/showcardsscene.h"

#include <QWidget>
#include <QEventLoop>
#include <QCloseEvent>

class QSkatMainWindow;

namespace Ui {
class SkatGameWindow;
}

class SkatGameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SkatGameWindow(QWidget *parent = 0);
    SkatGameWindow(QWidget *parent, QSkatMainWindow *mainw);
    ~SkatGameWindow();
    void exec_Game();
private:
    Ui::SkatGameWindow *ui;
    QSkatMainWindow* mainwindow;
    QEventLoop* qloop;
    showCardsScene* lowerScene;
    showCardsScene* upperScene;

private slots:
    void exitloop();
    void exitGame();

protected:
    virtual void closeEvent(QCloseEvent*);
};

#endif // SKATGAMEWINDOW_H
