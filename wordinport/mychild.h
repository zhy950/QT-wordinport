#ifndef MYCHILD_H
#define MYCHILD_H

#include <QWidget>
#include <QTextEdit>
#include <QtPrintSupport/QPrinter>

class MyChild : public QTextEdit
{
    Q_OBJECT

public:
    MyChild();
    void newFile();  //新建操作

    QString userFriendlyCurrentFile();//提取文件名
    QString currentFile(){return curFile;} // 返回当前文件路径

    bool loadFile(const QString &fileName); //加载文件
    bool save();//保存文件
    bool saveAs();//另存为
    bool saveFile(QString fileName);
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);//字体格式设置

    void setAlign(int align);//设置段落对齐格式
    void setStyle(int style);               //设置段落标号、编号

protected:
    void closeEvent(QCloseEvent *event); //关闭事件

private slots:
    void documentWasModified();//文档被更改时，窗口显示更改状态标识

private:
    QString strippedName(const QString &fullFileName);//获取较短的绝对路径
    QString curFile;//保存当前文件路径
    bool isUntitled;//作为当前文件是否被保存到硬盘上的标识

    void setCurrentFile(const QString &fileName);
    bool maybeSave();
};

#endif // MYCHILD_H
