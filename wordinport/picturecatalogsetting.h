#ifndef PICTURECATALOGSETTING_H
#define PICTURECATALOGSETTING_H

#include <QObject>
#include <QDir>
#include <QStringList>
#include <QFileInfoList>
#include <QFileInfo>
#include <QMessageBox>
#include <QDateTime>

#include "globalfunction.h"

class PictureCatalogSetting : public QObject
{
    Q_OBJECT
public:
    explicit PictureCatalogSetting(QObject *parent = 0);
    ~PictureCatalogSetting();

    //void cutPictrue(int serialNumber, QString filename, QList<SubjectQuestion> subList,int pageNum, QString result, QPoint point);

    bool creatDir(QString path);

    //QString onePicDeal(QString nPicdir, int num);

    //bool selectImage(QString candidateNumber);

   // bool deleteDir(const QString &dirName);

    //bool changeStudentPictrue(QString errorId,QString correctId);//未用

    //bool findPic(QString candidateNumber);

    //QStringList getImageList();

    //void deleteFile(QString dirName);//未用



signals:

public slots:

private:
};

#endif // PICTURECATALOGSETTING_H
