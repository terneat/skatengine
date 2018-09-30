#ifndef QSKATMAINWINDOW_H
#define QSKATMAINWINDOW_H

#include "ui/skatgamewindow.h"

#include <QMainWindow>

namespace Ui {
class QSkatMainWindow;
}

class QSkatMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QSkatMainWindow(QWidget *parent = 0);
    ~QSkatMainWindow();
    virtual void activate();

private:
    Ui::QSkatMainWindow *ui;
    SkatGameWindow* skat_window;

public slots:
    void showGameWindow();

protected: /*nested classes*/
    class showCardsScene;
};

#endif // QSKATMAINWINDOW_H
