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
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 2; i++) { // Fill the combobox with data.
        ui->comboBox->addItem(mainStack.getStringMode(i));
    }
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

void MainWindow::on_popStackItemBtn_clicked() // Pop stack item out of the stack.
{
    if (mainStack.checkIfEmpty() == true) {
        ui->poppedItemLabel->setText("Eempty!");
    } else {
        int poppedValue = mainStack.popStackItem();
        ui->poppedItemLabel->setText(QString::number(poppedValue));
    }
}

void MainWindow::on_outputLastStackItem_clicked() // Output last stack item.
{
    if (mainStack.checkIfEmpty() == true) {
        ui->stackValueLabel->setText("Empty!");
    } else {
    int outValue = mainStack.outputLastStackItem();
    ui->stackValueLabel->setText(QString::number(outValue));
    }
}

void MainWindow::on_pushButton_clicked() // Choose new program mode (stack or queue).
{
    int cboxValue = ui->comboBox->currentIndex();
    if (cboxValue == 0) {
        qDebug("Stack");
        ui->pushStackItemBtn->setText("Push item to the stack");
        ui->popStackItemBtn->setText("Pop item out of the stack");
        ui->outputLastStackItem->setText("Show last item of the stack");
        mainStack.setCurrentMode(cboxValue);
    }
    if (cboxValue == 1) {
        qDebug("Queue");
        ui->pushStackItemBtn->setText("Push item to the queue");
        ui->popStackItemBtn->setText("Pop item out of the queue");
        ui->outputLastStackItem->setText("Show last item of the stack");
        mainStack.setCurrentMode(cboxValue);
    }
    mainStack.resetData();
}
