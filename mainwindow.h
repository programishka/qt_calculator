#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonNumberReleased();

    void on_bAc_clicked();

    void on_bAdd_clicked();

    void on_bEqual_clicked();

    void on_bSubtract_clicked();

    void on_bMultiply_clicked();

    void on_bDividion_clicked();

    void on_bDot_clicked();

    void on_bAm_clicked();

    void on_bPercent_clicked();

    void on_bSqrt_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
