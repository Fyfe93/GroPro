#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
     QTcpSocket *m_pClientsocket;
private slots:
    void displayError ( QAbstractSocket::SocketError socketError );

private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonSend_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
