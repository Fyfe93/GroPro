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

class GroProControl : public QObject
{
    Q_OBJECT
public:
    explicit GroProControl(QObject *parent = nullptr);
    ~GroProControl();
    QTcpSocket *m_pClientsocket;

    Q_INVOKABLE void test();
    Q_INVOKABLE void connectToDevice(QString ipAddress);
    Q_INVOKABLE void disconnectFromDevice();
    Q_INVOKABLE void sendMessage(QString identifier, QString message);


private:
    int m_portNum {5002};
    QScopedPointer<QObject> HostNotFoundErrorMessageDialog;
    QScopedPointer<QObject> ConnectionRefusedErrorMessageDialog;
    QScopedPointer<QObject> OtherErrorMessageDialog;

signals:

public slots:

private slots:
    void displayError ( QAbstractSocket::SocketError socketError );

};

#endif // GROPROCONTROL_H
