/*******************************************************
 * Copyright (C) 2018 Akchurin Konstantin <rfkao89@gmail.com>
 *
 * This file is part of stackLab1.
 *
 * stackLab1 can not be copied and/or distributed without the express
 * permission of Akchurin Konstantin
 *******************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushStackItemBtn_clicked();

    void on_popStackItemBtn_clicked();

    void on_outputLastStackItem_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
