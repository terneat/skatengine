#include "skatgamewindow.h"
#include "ui_skatgamewindow.h"

#include "qskatmainwindow.h"
#include "skatEngine/skatengine.h"

#include <QMessageBox>

#include <iostream>
#include <utility>
#include <vector>

SkatGameWindow::SkatGameWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::SkatGameWindow)
{

}

SkatGameWindow::SkatGameWindow(QWidget *parent, QSkatMainWindow* mainw):
    QWidget(parent), ui(nullptr), mainwindow(nullptr), qloop(nullptr)
{

    this->mainwindow = mainw;
    ui = new Ui::SkatGameWindow;
    ui->setupUi(this);
    lowerScene = new showCardsScene(1200, this);
    ui->mycardsView->setScene(lowerScene);

    upperScene = new showCardsScene(1200, this);
    upperScene->setOtherScene(lowerScene);
    ui->skatView->setScene(upperScene);

    qloop = new QEventLoop(this);
}

SkatGameWindow::~SkatGameWindow()
{
    delete lowerScene;
    delete qloop;
    delete ui;
}


void SkatGameWindow::exec_Game()
{
    mainwindow->hide();

    skatEngine::Controller& sk1 = skatEngine::Controller::getController();
    sk1.setPlayers(skatEngine::PlayerType::HUMAN, "Terne",skatEngine::PlayerType::CPU, "cpu1",skatEngine::PlayerType::CPU, "cpu2");

    sk1.initNewRound();
    lowerScene->setPlayerCards( sk1.getPlayerCards(1) );
    upperScene->setSkatCards(std::make_pair(sk1.getSkatCard(1), sk1.getSkatCard(2)));

    qloop->exec();

}

void SkatGameWindow::exitGame()
{

    skatEngine::Controller::destroyController();
    this->exitloop();
    this->close();

}

void SkatGameWindow::exitloop()
{
     qloop->quit();
}

void SkatGameWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;

    msgBox.setWindowTitle("-- Scaten v1.0 --");
    msgBox.setText("Spiel beenden?");
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Ok)
    {
        this->exitGame();
        mainwindow->show();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
