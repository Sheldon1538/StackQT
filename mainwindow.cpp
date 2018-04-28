/*******************************************************
 * Copyright (C) 2018 Akchurin Konstantin <rfkao89@gmail.com>
 *
 * This file is part of stackLab1.
 *
 * stackLab1 can not be copied and/or distributed without the express
 * permission of Akchurin Konstantin
 *******************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stack.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushStackItemBtn_clicked() // Push item to the stack.
{
    if (ui->stackTextInput->text() != "") {
        QString newItem = ui->stackTextInput->text();
        if (mainStack.checkIfIntegers(newItem) == true) {
            int finalItem = newItem.toInt();
            mainStack.pushStackItem(finalItem);
        }
    }
}

void MainWindow::on_popStackItemBtn_clicked()
{
    if (mainStack.checkIfEmpty() == true) {
        ui->poppedItemLabel->setText("Stack is empty!");
    } else {
        int poppedValue = mainStack.popStackItem();
        ui->poppedItemLabel->setText(QString::number(poppedValue));
    }
}

void MainWindow::on_outputLastStackItem_clicked() // Output last stack item.
{
    if (mainStack.checkIfEmpty() == true) {
        ui->stackValueLabel->setText("Stack is empty!");
    } else {
    int outValue = mainStack.outputLastStackItem();
    ui->stackValueLabel->setText(QString::number(outValue));
    }
}
