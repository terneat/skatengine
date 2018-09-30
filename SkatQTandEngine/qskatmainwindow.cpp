#include "qskatmainwindow.h"
#include "ui_qskatmainwindow.h"


QSkatMainWindow::QSkatMainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::QSkatMainWindow), skat_window(nullptr)
{
    ui->setupUi(this);
}

QSkatMainWindow::~QSkatMainWindow()
{
    delete ui;
}

void QSkatMainWindow::showGameWindow()
{

    skat_window = new SkatGameWindow(nullptr, this);

    this->skat_window->show();
    this->skat_window->exec_Game();

}

void QSkatMainWindow::activate()
{
    this->show();
    delete skat_window;
}
