#ifndef GROPROCONTROL_H
#define GROPROCONTROL_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QQmlEngine>
#include <QQmlContext>
#include <QtQml>
#include <QQuickView>
#include <QQuickItem>

/*
 This is a class for the GroPro controller App functionality. It allows easy utilisation of networking behaviour and the sending of event data from the UI over the established QTcpSocket connection.
 */

class GroProControl : public QObject
{
    Q_OBJECT
public:
    explicit GroProControl(QObject *parent = nullptr);
    ~GroProControl();
    QTcpSocket *m_pClientsocket;

    Q_INVOKABLE void test(); // Tests Event Trigger Message
    Q_INVOKABLE void connectToDevice(QString ipAddress); // Connects to device using TCP
    Q_INVOKABLE void disconnectFromDevice(); // Disconnects from TCP Server
    Q_INVOKABLE void sendMessage(QString identifier, QString message); // Sends String message over TCP connection


private:
    int m_portNum {5002};
    QScopedPointer<QObject> HostNotFoundErrorMessageDialog; // Runs dialog box with Host Not Found error message
    QScopedPointer<QObject> ConnectionRefusedErrorMessageDialog; // Runs dialog box with Connection Refused error message
    QScopedPointer<QObject> OtherErrorMessageDialog; // Runs dialog box with Other error message

signals:

public slots:

private slots:
    void displayError ( QAbstractSocket::SocketError socketError ); // Slot connected to ConnectToDevice to catch errors if connection is unsuccessful

};

#endif // GROPROCONTROL_H
