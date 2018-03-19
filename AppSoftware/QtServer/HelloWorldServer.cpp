
#include "helloworldserver.h"
#include <QTcpSocket>

HelloWorldServer::HelloWorldServer(MainWindow* pHelloServer,QObject *parent) : QTcpServer(parent)
{
    m_pHelloWindow=pHelloServer;
}

void HelloWorldServer::incomingConnection(int socketfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);

    m_pHelloWindow->addMessage("New client from: "+client->peerAddress().toString());

    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void HelloWorldServer::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    while(client->canReadLine())
    {
        QString line = QString::fromUtf8(client->readLine()).trimmed();
        //qDebug() << "Read line:" << line;
        m_pHelloWindow->addMessage(line);

    }
}

void HelloWorldServer::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    qDebug() << "Client disconnected:" << client->peerAddress().toString();

    clients.remove(client);


}
