
#ifndef HELLOWORLDSERVER_H
#define HELLOWORLDSERVER_H

#include <QTcpServer>

#include "MainWindow.h"
class MainWindow;

class HelloWorldServer : public QTcpServer
{
public:

    Q_OBJECT

        public:
            HelloWorldServer(MainWindow* pHelloServer,QObject *parent=0);
        MainWindow* m_pHelloWindow;

        private slots:
            void readyRead();
            void disconnected();

        protected:
            void incomingConnection(int socketfd);

        private:
            QSet<QTcpSocket*> clients;


};

#endif // HELLOWORLDSERVER_H
