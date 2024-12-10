// src/web.cpp
#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextStream>
#include <QDebug>

class SimpleWebServer : public QTcpServer
{
    Q_OBJECT

public:
    SimpleWebServer(QObject *parent = nullptr) : QTcpServer(parent) {
        connect(this, &QTcpServer::newConnection, this, &SimpleWebServer::handleNewConnection);
    }

protected:
    void handleNewConnection() {
        QTcpSocket *clientSocket = nextPendingConnection();
        connect(clientSocket, &QTcpSocket::readyRead, this, [clientSocket, this]() {
            QTextStream stream(clientSocket);
            QString request = stream.readAll();
            qDebug() << "Request received:" << request;

            // 간단한 HTTP 응답 반환
            QString response = "HTTP/1.1 200 OK\r\n"
                               "Content-Type: text/html\r\n\r\n"
                               "<html><body><h1>Hello from Qt Web Server!</h1></body></html>";
            clientSocket->write(response.toUtf8());
            clientSocket->disconnectFromHost();
        });
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    SimpleWebServer server;
    if (!server.listen(QHostAddress::Any, 8080)) {  // 포트 8080에서 대기
        qCritical() << "Unable to start the server:" << server.errorString();
        return -1;
    }

    qDebug() << "Server started on port" << server.serverPort();
    return app.exec();
}

#include "webTest.moc"
