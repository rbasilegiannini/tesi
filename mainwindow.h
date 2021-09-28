#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow //ereditarietà
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSassoClicked();
    void onCartaClicked();
    void onForbiceClicked();
    void onLizardClicked();
    void onSpockClicked();
    void onProssimoClicked();
    void onRivincitaClicked();

private:
    Ui::MainWindow *ui; //estensione della classe
    int mossaPlayer1;
    int mossaPlayer2;
    int scorePlayer1;
    int scorePlayer2;

    void calcolaVincitore();
    void vincePlayer1();
    void vincePlayer2();
    void fermaGioco();
    void riprendiGioco();
    void reset();
};
#endif // MAINWINDOW_H
