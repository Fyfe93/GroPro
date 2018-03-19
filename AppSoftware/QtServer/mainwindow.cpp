#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButtonStart_clicked()
{
   m_pBoxServer= new HelloWorldServer(this);

    bool success = m_pBoxServer->listen(QHostAddress::Any, quint16(ui->textEditPort->toPlainText().toInt()));
    if(!success)
    {
        addMessage("Server failed...");

    }
    else
    {
        addMessage("Server Started...");
    }
}

void MainWindow::addMessage(QString Msg)
{

    ui->textEditStatus->setText(Msg);

}
