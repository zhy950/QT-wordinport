#include "picturecatalogsetting.h"
#include <QDebug>
PictureCatalogSetting::PictureCatalogSetting(QObject *parent) : QObject(parent)
{

}
PictureCatalogSetting::~PictureCatalogSetting()
{

}

//bool PictureCatalogSetting::findPic(QString candidateNumber)
//{
//    QDir picdir(globalfunction::m_uploadZip);
//    if(!picdir.exists())
//    {
//        return false;
//    }
//    QStringList filter;
//    filter <<"*" + candidateNumber + ".zip";//可以客户自行选择
//    picdir.setNameFilters(filter);//设置文件名称过滤器，只为filter格式
//    QFileInfoList list = picdir.entryInfoList();
//    if((list.size()<1))
//    {
//        return false;
//    }

//    return true;
//}

//bool PictureCatalogSetting::selectImage(QString candidateNumber)
//{
//    QDir picdir(globalfunction::m_cutPath);
//    if(!picdir.exists())
//    {
//        return false;
//    }
//    QStringList filter;
//    filter <<"*-" + candidateNumber + ".jpg"; //可以客户自行选择
//    picdir.setNameFilters(filter);
//    picdir.setSorting(QDir::Name);
//    QFileInfoList list = picdir.entryInfoList();

//    if((list.size()<1))
//    {
//        return false;
//    }

//    QFileInfo fileInfo;
//    QString path;
//    //将切割目录的图片重命名并放入待压缩文件夹
//    for (int i = 0; i < list.size(); ++i)
//    {
//        QString toPath = globalfunction::m_upload + candidateNumber + "/" + candidateNumber + "-" + QString::number(i) + ".jpg";
//        fileInfo = list.at(i);
//        path = fileInfo.filePath();
//        QFile::copy(path,toPath);
//    }
//}


////获取扫描学生试卷图片列表
//QStringList PictureCatalogSetting::getImageList()
//{
//    QDir picdir(globalfunction::m_scanPath);
//    if(!picdir.exists())
//    {
//        //Do nothing
//    }

//    QStringList filter;
//    filter << "*.jpg";
//    picdir.setNameFilters(filter);
//    picdir.setSorting(QDir::Name);
//    QFileInfoList list = picdir.entryInfoList();//文件夹内图片数

//    if((list.size()<1))
//    {

//    }

//    QFileInfo fileInfo;
//    QString path;
//    QStringList pathlist;
//    for (int i = 0; i < list.size(); ++i)
//    {
//        fileInfo = list.at(i);
//        path = fileInfo.filePath();
//        pathlist << path;
//    }
//    return pathlist;
//}

//QString PictureCatalogSetting::onePicDeal(QString nPicdir,int num)
//{
//    QDir picdir(nPicdir);
//    if(!picdir.exists())
//    {
//        return false;
//    }
//    QStringList filter;
//    QString str = "*" + QString::number(num) + ".jpg"; //可以客户自行选择
//    filter << str;
//    picdir.setNameFilters(filter);
//    QFileInfoList list = picdir.entryInfoList();
//    if((list.size()<1))
//    {
//        return false;
//    }
//    QFileInfo fileInfo;
//    QString path;

//    for (int i = 0; i < list.size(); ++i)
//    {
//        fileInfo = list.at(i);
//        path = fileInfo.filePath();
//        return path;
//    }
//}


////切割试题图片保存到 imageResult 文件夹
//void PictureCatalogSetting::cutPictrue(int serialNumber, QString filename, QList<SubjectQuestion> subList, int pageNum, QString result, QPoint point)
//{
//    //根据页面获取当页的切割坐标，从获取的ini文件解析出来的数据

//    QImage *picture = new QImage;

//    QStringList pathlist;

//    int xx = point.x();//当前页固定点x
//    int yy = point.y();//当前页固定点y

//    if(!(picture->load(filename)))
//    {
//        delete picture;
//    }
//    else
//    {
//        //重命名切割当页原图并保存
//        picture->save(globalfunction::m_cutPath + QString::number(pageNum) + "-" + QString::number(serialNumber) + ".jpg");

//        if(subList.size()<= 0) {
//           delete picture;
//           return;
//        }

//        if(creatDir(globalfunction::m_cutPath + "/" + QString::number(serialNumber)))
//        {
//            for(int i = 0; i < subList.size(); ++i)
//            {
//                SubjectQuestion subjectQuestion = subList.at(i);
//                QRect rect = subjectQuestion.rect;

//                //以特定命名格式保存切割好的图片,路径，页数，题号，学生学号
//                QString str = globalfunction::m_cutPath + "/" + QString::number(serialNumber) + "/" + subjectQuestion.number + ".jpg";

//                //切割函数，需要加上固定点的坐标才能得到相应原图的位置
//                if(QPixmap::fromImage(picture->copy(rect.x() + xx , rect.y() + yy , rect.width() , rect.height())).save(str,NULL,30))//文件格式会不会改变
//                {

//                }
//            }
//            delete picture;
//        }
//    }
//}

//用于创建文件夹
bool PictureCatalogSetting:: creatDir(QString path)
{
    QDir *temp = new QDir;
    bool exist = temp->exists(path);
    if(exist)
    {
        delete temp;
        return true;
    }
    else
    {
        bool ok = temp->mkdir(path);

        if(ok)
        {
            delete temp;
            return true;
        }
        else
        {
            delete temp;
            return false;
        }
    }
}

////未用
//void PictureCatalogSetting::deleteFile(QString dirName)
//{
//    QFile picdir(globalfunction::m_uploadZip + dirName + ".zip");
//    picdir.remove();
//}


//未用
//删除文件加
//bool PictureCatalogSetting::deleteDir(const QString &dirName)
//{
//    QDir dir(dirName);
//    QFileInfoList fileList;
//    QFileInfo curFile;

//    if(!dir.exists())
//    {
//        return false;//文件不存在，则返回false
//    }
//    // 首先获取目标文件夹内所有文件及文件夹信息
//    fileList=dir.entryInfoList(QDir::Dirs|QDir::Files
//                      |QDir::Readable|QDir::Writable
//                      |QDir::Hidden|QDir::NoDotAndDotDot
//                      ,QDir::Name);

//    qDebug()<<tr("----要删除的路径----")<<dirName;
//    qDebug()<<tr("----该路径下文件与文件夹总数----")<<fileList.size();

//    while(fileList.size() > 0)
//    {

//        int infoNum=fileList.size();//如果有文件的话，文件数

//        for(int i = infoNum-1; i >= 0; --i)
//        {
//            curFile=fileList[i];

//            if(curFile.isFile())//如果是文件，删除文件,基本用不上全是文件夹
//            {
//               QFile fileTemp(curFile.filePath());
//               fileTemp.remove();
//               fileList.removeAt(i);
//            }

//            if(curFile.isDir())//如果是文件夹
//            {
//               QDir dirTemp(curFile.filePath());
//               QFileInfoList fileList1=dirTemp.entryInfoList(QDir::Dirs|QDir::Files
//                                                             |QDir::Readable|QDir::Writable
//                                                             |QDir::Hidden|QDir::NoDotAndDotDot
//                                                             ,QDir::Name);

//               if(fileList1.size() == 0)//下层没有文件或文件夹
//               {
//                   dirTemp.rmdir(".");//"."是删除当前文件夹
//                   fileList.removeAt(i);

//               }
//               else//下层有文件夹或文件
//               {
//                   for(int j = 0; j < fileList1.size(); ++j)//将文件数加到文件夹数上获得总数
//                   {
//                       if(!(fileList.contains(fileList1[j])))
//                           fileList.append(fileList1[j]);
//                   }
//               }
//            }
//        }
//    }
//    return true;
//}


////未用
//bool  PictureCatalogSetting::changeStudentPictrue(QString errorId,QString correctId)
//{
//    QDir picdir(globalfunction::m_cutPath);
//    if(!picdir.exists())
//    {
//        return false;
//    }
//    QStringList filter;
//    filter << "*" + errorId + ".jpg";//可以客户自行选择
//    picdir.setNameFilters(filter);
//    QFileInfoList list = picdir.entryInfoList();

//    if((list.size() < 1))
//    {
//       // return false;
//    }

//    QFileInfo fileInfo;
//    QString path;

//    for (int i = 0; i < list.size(); ++i)
//    {
//        fileInfo = list.at(i);
//        path = fileInfo.filePath();
//        QString oldPath = path;
//        QString topath = path.replace(QRegExp(errorId),correctId);
//        qDebug()<<QFile::rename(oldPath,topath);
//    }

//}
