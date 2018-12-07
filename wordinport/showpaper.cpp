#include "showpaper.h"
#include "ui_showpaper.h"
#include <QRegExp>
//点击按键中平间的空白处会崩溃？？？？？？？？

//数据没有组合，等全部弄完在组合？


ShowPaper::ShowPaper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowPaper)
{
    ui->setupUi(this);

//    globalfunction::g_picNum =0;

    choose_num = 0;
    mutichoose_num = 0;
    judge_num = 0;
    answer_num = 0;
    fillin_num = 0;

    str_tatle = "";//试卷名
    str_meterial = "";//教材版本
    str_subject = "";//学科学段
    str_term = "";//适用学期
    str_totalPoints = "";//试卷总分
    str_time = "";//建议答题时长
    str_paperType = "";//试卷类型
    str_paperSource = "";//试卷来源
    str_division = "";//区分度
    str_totalQuesNum = "";//试题数总计

    quesText = "";
    m_ques.clear();
    globalfunction::g_picNameList.clear();
    globalfunction::g_picList.clear();


    readJson();
    initInfo();
    initCreateCatalog();
    //qDebug()<<globalfunction::g_picList;

}

ShowPaper::~ShowPaper()
{
    delete ui;
}

//打开就创建时间文件夹
void ShowPaper::initCreateCatalog()
{
    QDateTime currenTime =QDateTime::currentDateTime();
    QString currenTimeStr =currenTime.toString("yyyy.MM.dd.hh.mm");

    PictureCatalogSetting m_picDir;

    QString rootPath = QCoreApplication::applicationDirPath() + "/examdata";
    m_picDir.creatDir(rootPath);

    QString m_rootPath = QCoreApplication::applicationDirPath() + "/examdata/"+currenTimeStr+"/";

    globalfunction::g_newFile = m_rootPath;

    //qDebug()<<m_rootPath;
    m_picDir.creatDir(m_rootPath);
}

void ShowPaper::initInfo()
{

    ui->label_paperTitle->setText(str_tatle);
    ui->label_subject->setText(str_subject);
    ui->label_textBook->setText(str_meterial);
    ui->label_term->setText(str_term);
    ui->label_testTime->setText(str_time);

    ui->label_totalpoint->setText(str_totalPoints);
    ui->label_paperType->setText(str_paperType);
    ui->label_paperSource->setText(str_paperSource);
    ui->label_Division->setText(str_division);
    ui->label_totalQuesNum->setText(str_totalQuesNum);

    ui->label_choose->setText(QString::number(choose_num) );
    ui->label_mutichoose->setText(QString::number(mutichoose_num) );
    ui->label_fillin->setText( QString::number(fillin_num) );
    ui->label_answerques->setText(QString::number(answer_num));
    ui->label_judge->setText(QString::number(judge_num));

   // ui->textBrowser->setText(quesText);//显示所有题

    globalfunction::g_picNum = globalfunction::g_picNameList.size();

    QNetworkAccessManager *manager;
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));

//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/932e475e321a4e8d8355449643304cc2.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/7e0342872252437cb7619bb7061ba5bf.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/78a2f45eeeeb44618075e8283db6084c.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/ec5b680a940b4ba885b4cfab5daff48d.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/02008d661db741238218259c9c266c2c.png")));//
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/fd52f8e813ee448986b01b897ff31469.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/c01ca5ed7fbe434b8c7d1a33cec287a5.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/07ae4185c0d6426c925114f68bce2a22.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/9345c971359b4384bd863777bee40260.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/3c73eb2a7c1d408982e074afcbc263a4.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/0dea8ba25ba549cf8de4649284bf816d.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/a03fae0e096a4b13975db93a118aac52.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/188cbc6fd16c43e4bd06a34ab3d0ce4f.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/3a7530e8ea4341f39971755b17751c16.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/12cc4fe10369475aa00509470c440cfd.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/f21293aa3d9e4bf0824bdbc0793f3adf.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/159d579069e84948b0a4149b766e4114.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/5d6c24680c904f61a19845857729f124.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/9a67db3cfc1f4ab9913f22e01ec3f402.png")));
//    manager->get(QNetworkRequest(QUrl("http://img2.51youpu.com/Public2/pic/ba1b2d9060c94d7a9dc9391cbf72dc8f.png")));


    for(int i =0;i<globalfunction::g_picList.size();i++)
    {
        //下载图片
        manager->get(QNetworkRequest(QUrl(globalfunction::g_picList.at(i))));

        QString curNameStr;
        curNameStr = globalfunction::g_picList.at(i);
        curNameStr.remove(0,36);

        globalfunction::g_picNameList.append(curNameStr);//全部图片名字的 list

        globalfunction::g_currentPicName = curNameStr;//每一个图片的名字 str

        qDebug()<<"VVVVVVVVVVVVVV"<<globalfunction::g_picList.at(i);
        //qDebug()<<"AAAAAAAAAAAA"<<globalfunction::g_currentPicName;

    }

    QString str_first;
    for(int i =0;i<m_ques.value("1").size();i++)
    {
        str_first.append(m_ques.value("1").at(i));
    }
    ui->textBrowser->setText(str_first);//显示单道题
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(m_ques.size());



}

void ShowPaper::on_btn_ok_clicked()
{

  //  qDebug()<<"sss"<< ui->spinBox->text();

    QString str_oneQues;
    for(int i =0;i<m_ques.value(ui->spinBox->text()).size();i++)
    {
        str_oneQues.append(m_ques.value(ui->spinBox->text()).at(i));

    }
    qDebug()<<"TTTTTTTT"<<str_oneQues;

    //ui->label_3->setText(str_oneQues);

    ui->textBrowser->setText(str_oneQues);

}

void ShowPaper::on_btn_edit_clicked()
{

    myword = new MyWord();
    myword->show();

  //  QProcess::startDetached("C:\\Users\\mingren\\Desktop\\MyselfWord.exe", QStringList());

}

//有多少个下载项进入多少次，一起进入
//bug 下载时是随机下载图片，和图片名对不上
int flagNum = 0;
void ShowPaper::replyFinished(QNetworkReply *reply)
{
    // 获取响应状态码，200表示正常
    QVariant nCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    // qDebug()<<"状态"<<nCode<<"   "<<flagNum;

    if(reply->error() == QNetworkReply::NoError)
    {
        QPixmap currentPicture;

        QByteArray bytes = reply->readAll();

        //获取字节流构造 QPixmap 对象
        currentPicture.loadFromData(bytes);

        //ui->label_3->setPixmap(currentPicture);

        //图片另存
        //QDateTime now;
        //QString filename = now.currentDateTime().toString("yyyyMMddhhmmss.png");
        //QString filename = ("e32a4482a54748a999978559ed36325a.png");//另存名


        QString aaa;

        //aaa=globalfunction::g_picNameList.at(i)+".png";
        aaa = globalfunction::g_picNameList.at(flagNum);
        //aaa = QString::number( flagNum) +".png";

        //保存图片
        QFile file(globalfunction::g_newFile + aaa);
        if(file.open(QIODevice::Append))
        {
            file.write(bytes);
        }


        file.close();

    }
    else
    {
        // 错误处理-显示错误信息，或显示上一次缓存的图片或叉图。
    }

    flagNum++;

    if(flagNum == globalfunction::g_picNameList.size())
    {
        flagNum = 0;
    }

    //qDebug()<<flagNum;
}


void ShowPaper::readJson()
{


    QStringList aaaa;
    QFile *file = new QFile(QCoreApplication::applicationDirPath() + "/aaa.json");

    if(!file->open(QIODevice::ReadOnly))
    {
        //do error
    }
    else
    {
        //m_templateData.clear();
        QByteArray b = file->readAll();
        QJsonParseError *error = new QJsonParseError;
        QJsonDocument doc = QJsonDocument::fromJson(b,error);// 转化为 JSON 文档



        if(error->error == QJsonParseError::NoError)// 解析未发生错误
        {
            if(doc.isObject())// JSON 文档为对象
            {

                QJsonObject obj = doc.object();//取得最外层这个大对象// 转化为对象

                //tatle试卷名
                if(obj.contains("Tatle"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("Tatle");// 获取指定 key 对应的 value
                    if(value.isString())// 判断 value 是否为字符串
                    {
                        QString strTatle = value.toString();  // 将 value 转化为字符串

                        str_tatle = strTatle;

                        qDebug() << "Tatle : " << strTatle;

                    }
                }

                //attribute  属性，空的
                if(obj.contains("Attribute"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("Attribute");// 获取指定 key 对应的 value
                    if(value.isString())// 判断 value 是否为字符串
                    {
                        QString Attribute = value.toString();  // 将 value 转化为字符串
                        qDebug() << "Attribute : " << Attribute;
                    }
                }

                //Material 教材版本
                if(obj.contains("Material"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("Material");// 获取指定 key 对应的 value
                    if(value.isString())// 判断 value 是否为字符串
                    {
                        QString Material = value.toString();  // 将 value 转化为字符串

                        str_meterial = Material;
                        //globalfunction::g_str_meterial = Material;
                        qDebug() << "Material : " << Material;
                    }
                }

                //subject 学科学段
                if(obj.contains("Subject"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("Subject");// 获取指定 key 对应的 value
                    if(value.isDouble())// 判断 value 是否为字符串
                    {
                        double Subject = value.toDouble();  // 将 value 转化为字符串

                        str_subject = QString::number(Subject);
                        //globalfunction::g_str_subject = QString::number(Subject);
                        qDebug() << "Subject : " << Subject;
                    }
                }

                //term 适用学期
                if(obj.contains("Term"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("Term");// 获取指定 key 对应的 value
                    if(value.isString())// 判断 value 是否为字符串
                    {
                        QString Term = value.toString();  // 将 value 转化为字符串
                        str_term = Term;
                        //globalfunction::g_str_term = Term;
                        qDebug() << "Term : " << Term;
                    }
                }

                //totalpoints
                if(obj.contains("TotalPoints"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("TotalPoints");// 获取指定 key 对应的 value
                    if(value.isDouble())// 判断 value 是否为字符串
                    {
                        double TotalPoints = value.toDouble();  // 将 value 转化为字符串
                        str_totalPoints = QString::number(TotalPoints);
                        qDebug() << "TotalPoints : " << TotalPoints;
                    }
                }

                //time 建议答题时长
                if(obj.contains("Time"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("Time");// 获取指定 key 对应的 value
                    if(value.isDouble())// 判断 value 是否为字符串
                    {
                        double Time = value.toDouble();  // 将 value 转化为字符串
                        str_time = QString::number(Time);
                        //globalfunction::g_str_useTime = QString::number(Time);
                        qDebug() << "Time : " << Time;
                    }
                }

                //paperytpe 试卷类型
                if(obj.contains("Papertype"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("Papertype");// 获取指定 key 对应的 value
                    if(value.isString())// 判断 value 是否为字符串
                    {
                        QString Papertype = value.toString();  // 将 value 转化为字符串
                        str_paperType = Papertype;
                        qDebug() << "Papertype : " << Papertype;
                    }
                }

                //papersource 试卷来源
                if(obj.contains("Papersource"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("Papersource");// 获取指定 key 对应的 value
                    if(value.isString())// 判断 value 是否为字符串
                    {
                        QString Papersource = value.toString();  // 将 value 转化为字符串
                        str_paperSource = Papersource;
                        qDebug() << "Papersource : " << Papersource;
                    }
                }

                //question 开始解析试题
                if(obj.contains("question"))// 包含指定的 key
                {
                    QJsonValue value = obj.value("question");// 获取指定 key 对应的 value

                    if(value.isArray())// 判断 value 是否为数组
                    {
                        QJsonArray array = value.toArray();
                        int nSize = array.size();

                        str_totalQuesNum = QString::number(nSize);//试题数总计


                        //试题数进行循环
                        for (int i = 0; i < nSize; ++i)
                        {
                            QJsonValue value = array.at(i);
                            QStringList list;

                            if (value.isObject())
                            {
                                QJsonObject obj = value.toObject();

                                //空的
                                if(obj.contains("Question_Id"))
                                {
                                    QJsonValue value = obj.value("Question_Id");
                                    if(value.isDouble())
                                    {
                                        double Question_Id = value.toDouble();
                                        qDebug() << "Question_Id : " << Question_Id;
                                    }
                                }

                                //题号
                                if(obj.contains("Num"))
                                {
                                    QJsonValue value = obj.value("Num");
                                    if(value.isDouble())
                                    {
                                        double Num = value.toDouble();
                                        qDebug() << "Num : " << Num;
                                        quesNum = Num;
                                    }
                                }

                                if(obj.contains("Fid"))
                                {
                                    QJsonValue value = obj.value("Fid");
                                    if(value.isDouble())
                                    {
                                        double Fid = value.toDouble();
                                        qDebug() << "Fid : " << Fid;
                                    }
                                }

                                //小题分数
                                if(obj.contains("Score"))
                                {
                                    QJsonValue value = obj.value("Score");
                                    if(value.isDouble())
                                    {
                                        double Score = value.toDouble();
                                        qDebug() << "Score : " << Score;
                                    }
                                }

                                //学段学科
                                if(obj.contains("Type"))
                                {
                                    QJsonValue value = obj.value("Type");
                                    if(value.isDouble())
                                    {
                                        double Type = value.toDouble();
                                        qDebug() << "Type : " << Type;

                                        if(Type == 1)
                                        {
                                            choose_num++;
                                        }
                                        else if(Type == 2)
                                        {
                                            mutichoose_num++;
                                        }
                                        else if(Type == 3)
                                        {
                                            fillin_num++;
                                        }
                                        else if(Type == 4)
                                        {
                                            answer_num++;
                                        }
                                        else if(Type == 5)
                                        {
                                            judge_num++;
                                        }
                                        else
                                        {
                                            //Do nothing
                                        }

                                    }
                                }

                                if(obj.contains("Core"))
                                {
                                    QJsonValue value = obj.value("Core");
                                    if(value.isDouble())
                                    {
                                        double Core = value.toDouble();
                                        qDebug() << "Core : " << Core;
                                    }
                                }

                                if(obj.contains("Synchronization"))
                                {
                                    QJsonValue value = obj.value("Synchronization");
                                    if(value.isDouble())
                                    {
                                        double Synchronization = value.toDouble();
                                        qDebug() << "Synchronization : " << Synchronization;
                                    }
                                }

                                if(obj.contains("Douthree"))
                                {
                                    QJsonValue value = obj.value("Douthree");
                                    if(value.isDouble())
                                    {
                                        double Douthree = value.toDouble();
                                        qDebug() << "Douthree : " << Douthree;
                                    }
                                }

                                if(obj.contains("Hide"))
                                {
                                    QJsonValue value = obj.value("Hide");
                                    if(value.isDouble())
                                    {
                                        double Hide = value.toDouble();
                                        qDebug() << "Hide : " << Hide;
                                    }
                                }

                                if(obj.contains("Correct"))
                                {
                                    QJsonValue value = obj.value("Correct");
                                    if(value.isDouble())
                                    {
                                        double Correct = value.toDouble();
                                        qDebug() << "Correct : " << Correct;
                                    }
                                }

                                if(obj.contains("Checnote"))
                                {
                                    QJsonValue value = obj.value("Checnote");
                                    if(value.isDouble())
                                    {
                                        double Checnote = value.toDouble();
                                        qDebug() << "Checnote : " << Checnote;
                                    }
                                }

                                //题干
                                if(obj.contains("Text"))
                                {
                                    QJsonValue value = obj.value("Text");
                                    if(value.isString())
                                    {
                                        //QString Text = value.toString();
                                        QString Text = "第" + QString::number( quesNum) +"题" + value.toString();
                                        quesText.append(Text.toUtf8());

                                        list.append(Text);

                                        if(!Text.isEmpty())
                                        {
                                            QRegExp rx;
                                            rx.setPattern( "(http|https)://((\\w)*|([0-9]*)|([-|_])*)+([\\.|/]((\\w)*|([0-9]*)|([-|_])*))+");

                                            int pos = 0;
                                            while((pos = rx.indexIn(Text,pos)) != -1)
                                            {
                                                globalfunction::g_picList.append(rx.cap(0));
                                                aaaa << rx.cap(0);
                                                //qDebug()<<"++++++++++++++"<<aaaa<<pos;
                                                pos += rx.matchedLength();
                                            }
                                        }

                                        qDebug() <<"第"<< quesNum <<"题" <<".Text : " << Text;
                                    }
                                }

                                //选项
                                if(obj.contains("Options"))//选择题选项
                                {
                                    QJsonValue value = obj.value("Options");

                                    if(value.isArray())
                                    {
                                        QJsonArray array = value.toArray();

                                        int nSize = array.size();

                                        for(int i = 0; i < nSize; ++i)
                                        {
                                            QJsonValue value = array.at(i);

                                            if(value.isObject())
                                            {
                                                QJsonObject obj = value.toObject();

                                                if(obj.contains("Id"))
                                                {
                                                    QJsonValue value = obj.value("Id");

                                                    if(value.isDouble())
                                                    {
                                                        double Id = value.toDouble();
                                                        qDebug() << "Id : " << Id;
                                                    }
                                                }

                                                if(obj.contains("Index"))
                                                {
                                                    QJsonValue value = obj.value("Index");

                                                    if(value.isDouble())
                                                    {
                                                        double Index = value.toDouble();

                                                        if(Index == 1)
                                                        {
                                                            if(obj.contains("IsRight"))
                                                            {
                                                                QJsonValue value = obj.value("IsRight");

                                                                if(value.isBool())
                                                                {
                                                                    bool IsRight = value.toBool();
                                                                    qDebug() << "IsRight : " << IsRight;

                                                                    if(IsRight)
                                                                    {
                                                                        quesText.append("#A");

                                                                        list.append("#A");

                                                                    }
                                                                    else
                                                                    {
                                                                        quesText.append("A");

                                                                        list.append("A");
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        else if(Index == 2)
                                                        {
                                                            if(obj.contains("IsRight"))
                                                            {
                                                                QJsonValue value = obj.value("IsRight");

                                                                if(value.isBool())
                                                                {
                                                                    bool IsRight = value.toBool();
                                                                    qDebug() << "IsRight : " << IsRight;

                                                                    if(IsRight)
                                                                    {
                                                                        quesText.append("#B");

                                                                        list.append("#B");

                                                                    }
                                                                    else
                                                                    {
                                                                        quesText.append("B");

                                                                        list.append("B");
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        else if(Index == 3)
                                                        {
                                                            if(obj.contains("IsRight"))
                                                            {
                                                                QJsonValue value = obj.value("IsRight");

                                                                if(value.isBool())
                                                                {
                                                                    bool IsRight = value.toBool();
                                                                    qDebug() << "IsRight : " << IsRight;

                                                                    if(IsRight)
                                                                    {
                                                                        quesText.append("#C");

                                                                        list.append("#C");

                                                                    }
                                                                    else
                                                                    {
                                                                        quesText.append("C");

                                                                        list.append("C");
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        else if(Index == 4)
                                                        {
                                                            if(obj.contains("IsRight"))
                                                            {
                                                                QJsonValue value = obj.value("IsRight");

                                                                if(value.isBool())
                                                                {
                                                                    bool IsRight = value.toBool();
                                                                    qDebug() << "IsRight : " << IsRight;

                                                                    if(IsRight)
                                                                    {
                                                                        quesText.append("#D");

                                                                        list.append("#D");

                                                                    }
                                                                    else
                                                                    {
                                                                        quesText.append("D");

                                                                        list.append("D");
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                            //Do nothing
                                                        }
                                                        qDebug() << "Index : " << Index;
                                                    }
                                                }

                                                if(obj.contains("Text"))
                                                {
                                                    QJsonValue value = obj.value("Text");

                                                    if(value.isString())
                                                    {
                                                        QString Text = value.toString();
                                                        quesText.append(Text.toUtf8());

                                                        list.append(Text);

                                                        if(!Text.isEmpty())
                                                        {
                                                            QRegExp rx;
                                                            rx.setPattern( "(http|https)://((\\w)*|([0-9]*)|([-|_])*)+([\\.|/]((\\w)*|([0-9]*)|([-|_])*))+");

                                                            int pos = 0;
                                                            while((pos = rx.indexIn(Text,pos)) != -1)
                                                            {
                                                                globalfunction::g_picList.append(rx.cap(0));
                                                                aaaa << rx.cap(0);
                                                                //qDebug()<<"++++++++++++++"<<aaaa<<pos;
                                                                pos += rx.matchedLength();
                                                            }
                                                        }

                                                        qDebug() << "Text : " << Text;
                                                    }
                                                }
                                            }
                                        }

                                    }
                                }

                                //分析
                                if(obj.contains("Explain"))
                                {
                                    QJsonValue value = obj.value("Explain");
                                    if(value.isString())
                                    {
                                        QString Explain = value.toString();
                                        quesText.append(Explain.toUtf8());

                                        list.append(Explain);


                                        if(!Explain.isEmpty())
                                        {
                                            QRegExp rx;
                                            rx.setPattern( "(http|https)://((\\w)*|([0-9]*)|([-|_])*)+([\\.|/]((\\w)*|([0-9]*)|([-|_])*))+");

                                            int pos = 0;
                                            while((pos = rx.indexIn(Explain,pos)) != -1)
                                            {
                                                globalfunction::g_picList.append(rx.cap(0));
                                                aaaa << rx.cap(0);
                                                //qDebug()<<"++++++++++++++"<<aaaa<<pos;
                                                pos += rx.matchedLength();
                                            }
                                        }



                                        qDebug() << "Explain : " << Explain;
                                    }
                                }

                                //解答
                                if(obj.contains("Analysis"))
                                {
                                    QJsonValue value = obj.value("Analysis");
                                    if(value.isString())
                                    {
                                        QString Analysis = "解答：" + value.toString();
                                        quesText.append(Analysis.toUtf8());

                                        list.append(Analysis);

                                        if(!Analysis.isEmpty())
                                        {
                                            QRegExp rx;
                                            rx.setPattern( "(http|https)://((\\w)*|([0-9]*)|([-|_])*)+([\\.|/]((\\w)*|([0-9]*)|([-|_])*))+");

                                            int pos = 0;
                                            while((pos = rx.indexIn(Analysis,pos)) != -1)
                                            {
                                                globalfunction::g_picList.append(rx.cap(0));
                                                aaaa << rx.cap(0);
                                                //qDebug()<<"++++++++++++++"<<aaaa<<pos;
                                                pos += rx.matchedLength();
                                            }
                                        }


                                        qDebug() << "Analysis : " << Analysis;
                                    }
                                }

                                //空的
                                if(obj.contains("Answer"))
                                {
                                    QJsonValue value = obj.value("Answer");
                                    if(value.isDouble())
                                    {
                                        double Answer = value.toDouble();
                                        qDebug() << "Answer : " << Answer;
                                    }
                                }

                                //点评
                                if(obj.contains("Comments"))
                                {
                                    QJsonValue value = obj.value("Comments");
                                    if(value.isString())
                                    {
                                        QString Comments = value.toString();
                                        quesText.append(Comments.toUtf8());

                                        list.append(Comments);

                                        if(!Comments.isEmpty())
                                        {
                                            QRegExp rx;
                                            rx.setPattern( "(http|https)://((\\w)*|([0-9]*)|([-|_])*)+([\\.|/]((\\w)*|([0-9]*)|([-|_])*))+");

                                            int pos = 0;
                                            while((pos = rx.indexIn(Comments,pos)) != -1)
                                            {
                                                globalfunction::g_picList.append(rx.cap(0));
                                                aaaa << rx.cap(0);
                                                //qDebug()<<"++++++++++++++"<<aaaa<<pos;
                                                pos += rx.matchedLength();
                                            }
                                        }

                                        qDebug() << "Comments : " << Comments;
                                    }
                                }

                                if(obj.contains("Division"))
                                {
                                    QJsonValue value = obj.value("Division");
                                    if(value.isString())
                                    {
                                        QString Division = value.toString();
                                        str_division = Division;
                                        qDebug() << "Division : " << Division;
                                    }
                                }

                                if(obj.contains("Difficulty"))
                                {
                                    QJsonValue value = obj.value("Difficulty");
                                    if(value.isString())
                                    {
                                        QString Difficulty = value.toString();
                                        qDebug() << "Difficulty : " << Difficulty;
                                    }
                                }

                                if(obj.contains("Spenttime"))
                                {
                                    QJsonValue value = obj.value("Spenttime");
                                    if(value.isString())
                                    {
                                        QString Spenttime = value.toString();
                                        qDebug() << "Spenttime : " << Spenttime;
                                    }
                                }

                                if(obj.contains("Special_topics"))
                                {
                                    QJsonValue value = obj.value("Special_topics");
                                    if(value.isString())
                                    {
                                        QString Special_topics = value.toString();
                                        qDebug() << "Special_topics : " << Special_topics;
                                    }
                                }

                                if(obj.contains("Ability"))
                                {
                                    QJsonValue value = obj.value("Ability");
                                    if(value.isString())
                                    {
                                        QString Ability = value.toString();
                                        qDebug() << "Ability : " << Ability;
                                    }
                                }

                                if(obj.contains("Thoughtway"))
                                {
                                    QJsonValue value = obj.value("Thoughtway");
                                    if(value.isString())
                                    {
                                        QString Thoughtway = value.toString();
                                        qDebug() << "Thoughtway : " << Thoughtway;
                                    }
                                }

                                if(obj.contains("Examination_points"))
                                {
                                    QJsonValue value = obj.value("Examination_points");
                                    if(value.isString())
                                    {
                                        QString Examination_points = value.toString();
                                        qDebug() << "Examination_points : " << Examination_points;
                                    }
                                }

                                if(obj.contains("From"))
                                {
                                    QJsonValue value = obj.value("From");
                                    if(value.isString())
                                    {
                                        QString From = value.toString();
                                        qDebug() << "From : " << From;
                                    }
                                }

                                if(obj.contains("Knowledge_points"))
                                {
                                    QJsonValue value = obj.value("Knowledge_points");

                                    if(value.isArray())
                                    {
                                        QJsonArray array = value.toArray();
                                        int nSize = array.size();
                                        QStringList Knowledge_points;

                                        for(int i = 0; i < nSize; ++i)
                                        {
                                            QJsonValue value = array.at(i);
                                            if(value.isString())
                                            {
                                                Knowledge_points.append(value.toString());
                                            }
                                        }
                                        qDebug() << "Knowledge_points : " << Knowledge_points;
                                    }
                                }
                            }
                            list22 = list;
                            m_ques.insert(QString::number(quesNum),list);

                            qDebug()<<"mappppppppppppppp"<<list22;
                        }
                    }
                }
            }
        }
        else
        {
            qDebug()<<"error"<<error->errorString();

        }
    }

    file->close();
}


//编辑卷头
void ShowPaper::on_btn_editTitle_clicked()
{
    initEditTitleDialog();
    dialogEditTitle->show();
}

//编辑卷头对话框初始化
void ShowPaper::initEditTitleDialog()
{
    dialogEditTitle = new QDialog(this);
    dialogEditTitle->setWindowTitle("编辑卷头");

    dialogEditTitle->resize(600,400);


    label_title = new QLabel("试卷名称：",dialogEditTitle);
    label_subject = new QLabel("学科学段：",dialogEditTitle);
    label_meterial = new QLabel("教材版本：",dialogEditTitle);
    label_term = new QLabel("学期(册)：",dialogEditTitle);
    label_useTime = new QLabel("要求答题时长：",dialogEditTitle);
    label_title->setFixedWidth(70);
    label_subject->setFixedWidth(70);
    label_meterial->setFixedWidth(70);
    label_term->setFixedWidth(70);
    label_useTime->setFixedWidth(70);

    lineEdit_title = new QLineEdit(dialogEditTitle);
    lineEdit_title->setText(str_tatle);
    lineEdit_title->setFixedWidth(430);
    lineEdit_useTime = new QLineEdit(dialogEditTitle);
    lineEdit_useTime->setText(str_time);
    lineEdit_useTime->setFixedWidth(430);

    combox_subject = new QComboBox(dialogEditTitle);
    combox_meterial = new QComboBox(dialogEditTitle);
    combox_term = new QComboBox(dialogEditTitle);
    combox_subject->setFixedWidth(430);
    combox_meterial->setFixedWidth(430);
    combox_term->setFixedWidth(430);
    combox_subject->setCurrentIndex(0);
    combox_subject->insertItem(0,"选择学科");
    combox_subject->insertItem(1,"小学数学");//5
    combox_subject->insertItem(2,"小学语文");//20
    combox_subject->insertItem(3,"初中数学");//1
    combox_subject->insertItem(4,"初中物理");//2
    combox_subject->insertItem(5,"初中化学");//10
    combox_subject->insertItem(6,"初中英语");//11
    combox_subject->insertItem(7,"初中历史");//23
    combox_subject->insertItem(8,"初中生物");//14
    combox_subject->insertItem(9,"初中地理");//16
    combox_subject->insertItem(10,"初中政治");//21
    combox_subject->insertItem(11,"初中语文");//18
    combox_subject->insertItem(12,"高中数学");//9
    combox_subject->insertItem(13,"高中物理");//6
    combox_subject->insertItem(14,"高中化学");//7
    combox_subject->insertItem(15,"高中生物");//15
    combox_subject->insertItem(16,"高中历史");//23
    combox_subject->insertItem(17,"高中地理");//17
    combox_subject->insertItem(18,"高中政治");//22
    combox_subject->insertItem(19,"高中语文");//19
    combox_subject->insertItem(20,"高中英语");//12

    combox_meterial->setCurrentIndex(0);
    combox_meterial->insertItem(0,"选择版本");

    combox_term->setCurrentIndex(0);
    combox_term->insertItem(0,"选择学期");


    btn_editDialog_cancel = new QPushButton("取消",dialogEditTitle);
    btn_editDialog_ok = new QPushButton("确定",dialogEditTitle);
    btn_editDialog_cancel->setFixedWidth(80);
    btn_editDialog_ok->setFixedWidth(80);



    QHBoxLayout *layoutTitle = new QHBoxLayout;
    QHBoxLayout *layoutSubject = new QHBoxLayout;
    QHBoxLayout *layoutMeterial = new QHBoxLayout;
    QHBoxLayout *layoutTerm = new QHBoxLayout;
    QHBoxLayout *layoutUseTime = new QHBoxLayout;
    QHBoxLayout *layoutBtn = new QHBoxLayout;


    layoutTitle->addWidget(label_title,0,Qt::AlignLeft);
    layoutTitle->addWidget(lineEdit_title,0,Qt::AlignRight);
    layoutTitle->addStretch(10);


    layoutSubject->addWidget(label_subject,0,Qt::AlignLeft);
    layoutSubject->addWidget(combox_subject,0,Qt::AlignRight);
    layoutSubject->addStretch(10);


    layoutMeterial->addWidget(label_meterial,0,Qt::AlignLeft);
    layoutMeterial->addWidget(combox_meterial,0,Qt::AlignRight);
    layoutMeterial->addStretch(10);


    layoutTerm->addWidget(label_term,0,Qt::AlignLeft);
    layoutTerm->addWidget(combox_term,0,Qt::AlignRight);
    layoutTerm->addStretch(10);


    layoutUseTime->addWidget(label_useTime,0,Qt::AlignLeft);
    layoutUseTime->addWidget(lineEdit_useTime,0,Qt::AlignRight);
    layoutUseTime->addStretch(10);

    layoutBtn->addStretch(10);
    layoutBtn->addWidget(btn_editDialog_cancel,0,Qt::AlignLeft);
    layoutBtn->addStretch(10);
    layoutBtn->addWidget(btn_editDialog_ok,0,Qt::AlignRight);
    layoutBtn->addStretch(10);

    QGridLayout *girdLayout = new QGridLayout;
    girdLayout->addLayout(layoutTitle,0,0);
    girdLayout->addLayout(layoutSubject,1,0);
    girdLayout->addLayout(layoutMeterial,2,0);
    girdLayout->addLayout(layoutTerm,3,0);
    girdLayout->addLayout(layoutUseTime,4,0);
    girdLayout->addLayout(layoutBtn,5,0);

    girdLayout->setContentsMargins(50,50,50,50);
    dialogEditTitle->setLayout(girdLayout);

    connect(btn_editDialog_cancel, &QPushButton::clicked,this,&ShowPaper::dialog_editTitle_btn_cancel_clicked);
    connect(btn_editDialog_ok, &QPushButton::clicked,this,&ShowPaper::dialog_editTitle_btn_ok_clicked);//查看详情
}

//编辑卷头取消按钮
void ShowPaper::dialog_editTitle_btn_cancel_clicked()
{
    dialogEditTitle->close();
}

//编辑卷头确定按钮
void ShowPaper::dialog_editTitle_btn_ok_clicked()
{
    str_meterial = combox_meterial->currentText();
    str_subject = combox_subject->currentText();
    str_tatle = lineEdit_title->text();
    str_term = combox_term->currentText();
    str_time = lineEdit_useTime->text();

    ui->label_paperTitle->setText(str_tatle);
    ui->label_subject->setText(str_subject);
    ui->label_textBook->setText(str_meterial);
    ui->label_term->setText(str_term);
    ui->label_testTime->setText(str_time);

    dialogEditTitle->close();
}


//题组题，暂时不做
void ShowPaper::on_checkBox_QuesBankGroup_clicked(bool checked)
{
//    if(ui->checkBox_QuesBankGroup->isChecked())
//    {
//        dialogQuesBankGroup = new QDialog(this);

//        dialogQuesBankGroup->setWindowTitle("编辑卷头");

//        dialogQuesBankGroup->resize(600,400);
//        dialogQuesBankGroup->show();
//    }
//    else
//    {
//        qDebug()<<"jjjjjjjjjjjjjjj";
//    }

}
