#include "upload.h"

Upload::Upload(QObject *parent) : QObject(parent)
{
    //new一个QNetworkAccessManager的对象，可以管理多个网络传输
    m_pNetWorkManager = new QNetworkAccessManager();

}
Upload::~Upload()
{
    delete m_pNetWorkManager;
}


//上传模板信息
void Upload::postPaperMsg(QString path)
{
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart imagePart;

    //设置头信息
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\"; filename=\"%2\"").arg("path").arg(QFileInfo(path).fileName())));
    //上传文件内容
    QFile *file = new QFile(path);
    file->open(QIODevice::ReadOnly);
    imagePart.setBodyDevice(file);

    file->setParent(multiPart);
    multiPart->append(imagePart);

    //设置url
    QNetworkRequest request;

    //需要改
    //QString webPath =  globalfunction::g_web + "detector/api/view/v4/scanExam/uploadPaperModelInfo?paperId=" + globalfunction::paperId;//上传路径
    QString webPath;
    qDebug()<<"上传地址---"<<webPath;
    request.setUrl(webPath);

    //发送请求
    m_pNetWorkManager->post(request, multiPart);

    connect(m_pNetWorkManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slotReplyPostMsgFinish(QNetworkReply*)));
}


//解析上传回馈信息,reply为服务器返回信息
void Upload::slotReplyPostMsgFinish(QNetworkReply *reply  )
{
    //错误调试
    QByteArray ca = reply->readAll();
    QJsonParseError jsonpe;
    QJsonDocument json = QJsonDocument::fromJson(ca, &jsonpe);

    //解析 需要根据返回值改
    if(jsonpe.error == QJsonParseError::NoError)
    {
        if(json.isObject()) //.................................................ture/flase   JSON 文档为对象
        {
            QJsonObject obj = json.object();  // ...............................转化为对象

            if(obj.contains("recode"))   // ...................................包含指定的 key
            {
                if(obj["recode"] == 0)//........................................成功
                {

                    if(obj.contains("errmsg"))
                    {
                        qDebug()<< "  successed " << obj["errmsg"].toString();


                           // emit signalReplyMessage(0);//...........................上传信息回馈信号

                    }
                }
                else if(obj["recode"] == 1)//失败
                {
                    if(obj.contains("errmsg"))
                    {
                        qDebug()<< " failed " << obj["errmsg"].toString();


                          //  emit signalReplyMessage(1);//...........................上传信息回馈信号
                    }
                }
            }
        }
    }
    else
    {
        switch(jsonpe.error)
        {
        case 0:
            qDebug()<<tr("模板上传错误回馈")<<tr("未发生错误");
            break;
        case 1:
            qDebug()<<tr("模板上传错误回馈")<<tr("对象不正确地终止以右花括号结束");
            break;
        case 2:
            qDebug()<<tr("模板上传错误回馈")<<tr("分隔不同项的逗号丢失");
            break;
        case 3:
            qDebug()<<tr("模板上传错误回馈")<<tr("数组不正确地终止以右中括号结束");
            break;
        case 4:
            qDebug()<<tr("模板上传错误回馈")<<tr("对象中分割 key/value 的冒号丢失");
            break;
        case 5:
            qDebug()<<tr("模板上传错误回馈")<<tr("值是非法的");
            break;
        case 6:
            qDebug()<<tr("模板上传错误回馈")<<tr("在解析数字时，输入流结束");
            break;
        case 7:
            qDebug()<<tr("模板上传错误回馈")<<tr("数字格式不正确");
            break;
        case 8:
            qDebug()<<tr("模板上传错误回馈")<<tr("在输入时，发生一个非法转义序列");
            break;
        case 9:
            qDebug()<<tr("模板上传错误回馈")<<tr("在输入时，发生一个非法 UTF8 序列");
            break;
        case 10:
            qDebug()<<tr("模板上传错误回馈")<<tr("字符串不是以引号结束");
            break;
        case 11:
            qDebug()<<tr("模板上传错误回馈")<<tr("一个对象是预期的，但是不能被发现");
            break;
        case 12:
            qDebug()<<tr("模板上传错误回馈")<<tr("对解析器来说，JSON 文档嵌套太深");
            break;
        case 13:
            qDebug()<<tr("模板上传错误回馈")<<tr("对解析器来说，JSON 文档太大");
            break;
        case 14:
            qDebug()<<tr("模板上传错误回馈")<<tr("解析的文档在末尾处包含额外的乱码");
            break;
        }
    }
}
