#include "includes/mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->packetsTable->insertRow(0);
    QTableWidgetItem *item;
    item = new QTableWidgetItem("test");
    item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
    ui->packetsTable->setItem(0,0, item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionStop_triggered()
{
    std::cout << "stop" << std::endl;
}

void MainWindow::on_actionStart_triggered()
{
    std::cout << "start" << std::endl;
}

void MainWindow::on_actionRefresh_interfaces_triggered()
{
    std::cout << "refresh interfaces" << std::endl;
}

void MainWindow::on_actionOptions_triggered()
{
    std::cout << "options" << std::endl;
}

void MainWindow::on_actionRestart_triggered()
{
    std::cout << "restart" << std::endl;
}
