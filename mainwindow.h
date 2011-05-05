#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <editablesqlmodel.h>


namespace Ui {
    class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

private slots:

    void on_radioButton_6_released();
    void on_radioButton_5_released();
    void on_radioButton_4_released();
    void on_radioButton_3_released();
    void on_radioButton_2_released();
    void on_radioButton_released();

    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_action_2_triggered();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_action_triggered();
};

#endif // MAINWINDOW_H
