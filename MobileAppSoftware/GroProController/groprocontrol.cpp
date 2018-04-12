#include "groprocontrol.h"



GroProControl::GroProControl(QObject *parent) : QObject(parent)
{
     m_pClientsocket = new QTcpSocket(this);
     m_pClientsocket->flush();
}

GroProControl::~GroProControl()
{
    m_pClientsocket->flush();
    m_pClientsocket->close();
}

void GroProControl::test()
{
    qDebug() << "this is an event trigger test";
}

void GroProControl::connectToDevice(QString ipAddress)
{
    m_pClientsocket->connectToHost(ipAddress,quint16(m_portNum) );
    connect(m_pClientsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void GroProControl::disconnectFromDevice()
{
    m_pClientsocket->flush();
    m_pClientsocket->close();
}

void GroProControl::sendMessage(QString identifier, QString message)
{
    // Only send the text to the chat server if it's not empty:
    if(!message.isEmpty())
    {
        m_pClientsocket->write(QString(QString(identifier) +  message + "\r\n\r\n\r\n").toUtf8());
    }

    qDebug() << "Button Pressed";
}

void GroProControl::displayError ( QAbstractSocket::SocketError socketError )
{
    //Creates Popup messages displaying errors when different issues occur when connecting to the network.
    switch (socketError) {
         case QAbstractSocket::RemoteHostClosedError:
         {
             break;
         }
         case QAbstractSocket::HostNotFoundError:
         {
                QQuickView view;
                view.setSource(QUrl::fromLocalFile(":/RemoteHostClosedError.qml"));
                QQmlComponent component(view.engine()
                        , QUrl::fromLocalFile(":/RemoteHostClosedError.qml"));
                HostNotFoundErrorMessageDialog.reset(component.create());

                QQmlProperty::write(HostNotFoundErrorMessageDialog.data(), "parent"
                                    , QVariant::fromValue<QObject*>(view.rootObject()));
                QQmlEngine::setObjectOwnership(HostNotFoundErrorMessageDialog.data(), QQmlEngine::CppOwnership);
                //object->deleteLater();
             break;
         }
         case QAbstractSocket::ConnectionRefusedError:
         {
                QQuickView view2;
                view2.setSource(QUrl::fromLocalFile(":/ConnectionRefusedError.qml"));
                QQmlComponent component2(view2.engine()
                        , QUrl::fromLocalFile(":/ConnectionRefusedError.qml"));
                ConnectionRefusedErrorMessageDialog.reset(component2.create());

                QQmlProperty::write(ConnectionRefusedErrorMessageDialog.data(), "parent"
                                    , QVariant::fromValue<QObject*>(view2.rootObject()));
                QQmlEngine::setObjectOwnership(ConnectionRefusedErrorMessageDialog.data(), QQmlEngine::CppOwnership);
                //object2->deleteLater();
             break;
         }
         default:
         {
                QQuickView view3;
                view3.setSource(QUrl::fromLocalFile(":/OtherError.qml"));
                QQmlComponent component3(view3.engine()
                        , QUrl::fromLocalFile(":/OtherError.qml"));
                OtherErrorMessageDialog.reset(component3.create());

                QQmlProperty::write(OtherErrorMessageDialog.data(), "parent"
                                    , QVariant::fromValue<QObject*>(view3.rootObject()));
                QQmlEngine::setObjectOwnership(OtherErrorMessageDialog.data(), QQmlEngine::CppOwnership);
                //object3->deleteLater();
             break;
          }

         }
}

