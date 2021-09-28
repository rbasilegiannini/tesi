#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mossaPlayer1 = 0;
    mossaPlayer2 = 0;
    scorePlayer1 = 0;
    scorePlayer2 = 0;

    ui->setupUi(this);
    ui->Esito->setReadOnly(true);
    ui->Esito->setPlainText(tr("Turno di Player1"));
    ui->TextPlayer1->setDisabled(true);
    ui->TextPlayer1->setStyleSheet("QLineEdit "
                                   "{ background: rgb(0, 255, 255); "
                                   "selection-background-color: rgb(233, 99, 0); }");
    ui->TextPlayer2->setDisabled(true);
    ui->TextPlayer2->setStyleSheet("QLineEdit "
                                   "{ background: rgb(255,160,122); "
                                   "selection-background-color: rgb(0, 0, 0); }");
    ui->Player1->display(0);
    ui->Player2->display(0);

    ui->ProssimoTurno->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vincePlayer1()
{
    scorePlayer1 = scorePlayer1+1;
    ui->Esito->setPlainText(tr("Player1 ha vinto!"));
    ui->Player1->display(scorePlayer1);
}

void MainWindow::vincePlayer2()
{
    scorePlayer2 = scorePlayer2+1;
    ui->Esito->setPlainText(tr("Player2 ha vinto!"));
    ui->Player2->display(scorePlayer2);
}

void MainWindow::calcolaVincitore()
{

    switch (mossaPlayer1)
    {
        case 1:
        if (mossaPlayer2==1)
        {
            ui->Esito->setPlainText(tr("Pareggio!"));
            fermaGioco();
        }
        else if (mossaPlayer2==2 || mossaPlayer2==5)
        {
            vincePlayer1();
            fermaGioco();
        }
        else
        {
            vincePlayer2();
            fermaGioco();
        }
        break;

        case 2:
        if (mossaPlayer2==2)
        {
            ui->Esito->setPlainText(tr("Pareggio!"));
            fermaGioco();
        }
        else if (mossaPlayer2==3 || mossaPlayer2==4)
        {
            vincePlayer1();
            fermaGioco();
        }
        else
        {
            vincePlayer2();
            fermaGioco();
        }
        break;

        case 3:
        if (mossaPlayer2==3)
        {
            ui->Esito->setPlainText(tr("Pareggio!"));
            fermaGioco();
        }
        else if (mossaPlayer2==1 || mossaPlayer2==4)
        {
            vincePlayer1();
            fermaGioco();
        }
        else
        {
            vincePlayer2();
            fermaGioco();
        }
        break;

        case 4:
        if (mossaPlayer2==4)
        {
            ui->Esito->setPlainText(tr("Pareggio!"));
            fermaGioco();
        }
        else if (mossaPlayer2==1 || mossaPlayer2==5)
        {
            vincePlayer1();
            fermaGioco();
        }
        else
        {
            vincePlayer2();
            fermaGioco();
        }
        break;

        case 5:
        if (mossaPlayer2==5)
        {
            ui->Esito->setPlainText(tr("Pareggio!"));
            fermaGioco();
        }
        else if (mossaPlayer2==2 || mossaPlayer2==3)
        {
            vincePlayer1();
            fermaGioco();
        }
        else
        {
            vincePlayer2();
            fermaGioco();
        }
        break;

    }

}

void MainWindow::fermaGioco()
{
    ui->Carta->setDisabled(true);
    ui->Sasso->setDisabled(true);
    ui->Forbice->setDisabled(true);
    ui->Lizard->setDisabled(true);
    ui->Spock->setDisabled(true);

    ui->ProssimoTurno->setDisabled(false);
}

void MainWindow::riprendiGioco()
{
     ui->Carta->setDisabled(false);
     ui->Sasso->setDisabled(false);
     ui->Forbice->setDisabled(false);
     ui->Lizard->setDisabled(false);
     ui->Spock->setDisabled(false);

     ui->ProssimoTurno->setDisabled(true);
}

void MainWindow::reset()
{
    mossaPlayer1 = 0;
    mossaPlayer2 = 0;
    scorePlayer1 = 0;
    scorePlayer2 = 0;

    ui->Esito->setPlainText(tr("Turno di Player1"));
    ui->Player1->display(0);
    ui->Player2->display(0);

    riprendiGioco();
}

void MainWindow:: onCartaClicked()
{
    if (mossaPlayer1 == 0)
    {
        mossaPlayer1 = 1;
        ui->Esito->setPlainText(tr("Turno di Player2"));
    }

    else
    {
        mossaPlayer2 = 1;
        calcolaVincitore();
    }
}

void MainWindow:: onSassoClicked()
{
    if (mossaPlayer1 == 0)
    {
        mossaPlayer1 = 2;
        ui->Esito->setPlainText(tr("Turno di Player2"));
    }

    else
    {
        mossaPlayer2 = 2;
        calcolaVincitore();
    }
}

void MainWindow:: onForbiceClicked()
{
    if (mossaPlayer1 == 0)
    {
        mossaPlayer1 = 3;
        ui->Esito->setPlainText(tr("Turno di Player2"));
    }

    else
    {
        mossaPlayer2 = 3;
        calcolaVincitore();
    }
}

void MainWindow:: onLizardClicked()
{
    if (mossaPlayer1 == 0)
    {
        mossaPlayer1 = 4;
        ui->Esito->setPlainText(tr("Turno di Player2"));
    }

    else
    {
        mossaPlayer2 = 4;
        calcolaVincitore();
    }
}

void MainWindow:: onSpockClicked()
{
    if (mossaPlayer1 == 0)
    {
        mossaPlayer1 = 5;
        ui->Esito->setPlainText(tr("Turno di Player2"));
    }

    else
    {
        mossaPlayer2 = 5;
        calcolaVincitore();
    }
}

void MainWindow:: onProssimoClicked()
{
    mossaPlayer1 = 0;
    mossaPlayer2 = 0;
    ui->Esito->setPlainText(tr("Turno di Player1"));

    riprendiGioco();
}

void MainWindow:: onRivincitaClicked()
{
    reset();
}



