#ifndef UPLOAD_H
#define UPLOAD_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrlQuery>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QHttpPart>
#include <QFileInfo>
#include <QDataStream>
#include <QThread>
#include <QCoreApplication>
#include <QVariant>
#include <QFileDialog>
#include "globalfunction.h"

class Upload : public QObject
{
    Q_OBJECT

public:
    explicit Upload(QObject *parent = 0);
    ~Upload();


    QNetworkAccessManager *m_pNetWorkManager;

    void postPaperMsg(QString path);//上传文件

public slots:
    void slotReplyPostMsgFinish(QNetworkReply *reply);//上传信息回馈
};














#endif // UPLOAD_H
