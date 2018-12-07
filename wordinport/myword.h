#ifndef MYWORD_H
#define MYWORD_H

#include <QMainWindow>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintPreviewDialog>

class QMdiSubWindow;
class QObject;
class QMdiArea;//TextEdit
class QAction;//动作
class QMenu;//主菜单
class QComboBox;
class QFontComboBox;
class MyChild;
class QSignalMapper;//信号映射器，它可以实现对多个子窗口部件的相同信号进行映射，首先为其添加字符串或者数值参数，然后在发送出去。

class MyWord : public QMainWindow
{
    Q_OBJECT

public:
    MyWord(QWidget *parent = 0);
    ~MyWord();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void about();
    void fileNew();                         //新建文件操作
    void fileOpen();                        //打开文件操作
    void fileSave();                        //保存文件操作
    void fileSaveAs();                      //另存为文件操作

    void undo();                            //撤销
    void redo();                            //重做
    void cut();                             //剪切
    void copy();                            //复制
    void paste();                           //粘贴

    void textBold();                        //加粗
    void textItalic();                      //倾斜
    void textUnderline();                   //下划线

    void textFamily(const QString &f);      //字体选择框
    void textSize(const QString &p);        //字号
    void textAlign (QAction *a);            //设置段落对齐格式
    void textColor();                       //设置字体颜色
    void textStyle(int styleIndex);         //设置段落的风格

    void filePrint();                       //打印文档
    void filePrintPreview();                //打印预览文档
    void printPreview(QPrinter *);          //

    void updateMenus();                     //更新菜单
    void updateWindowMenu();                //更新窗口菜单
    MyChild *createMyChild();               //创建子窗口
    void setActiveSubWindow(QWidget *window);
private:
    void createActions();//创建动作
    void createMenus();//创建主菜单
    void createToolBars();//创建工具栏
    void createStatusBar();//创建状态栏
    void enabledText();//使格式下的各个子菜单项可用
    void colorChanged(const QColor &c);//设置动作栏颜色


    QMdiSubWindow *findMyChild(const QString &fileName); //查找子窗口

    MyChild *activeMyChild();//活动窗口
    QMdiArea *mdiArea;
    QSignalMapper *windowMapper;

    //文件菜单
    QMenu *fileMenu;
    QAction *newAct;//新建
    QAction *openAct;//打开
    QAction *saveAct;//保存
    QAction *saveAsAct;//另存为
    QAction *printAct;//打印
    QAction *printPreviewAct;//打印预览
    QAction *exitAct;//退出

    //编辑菜单
    QMenu *editMenu;
    QAction *undoAct;//撤销
    QAction *redoAct;//重做
    QAction *cutAct;//剪切
    QAction *copyAct;//复制
    QAction *pasteAct;//粘贴

    //格式菜单
    QMenu *formatMenu;//格式菜单
    QMenu *fontMenu;//字体子菜单
    QMenu *alignMenu;//段落子菜单
    QAction *boldAct;//加粗
    QAction *italicAct;//倾斜
    QAction *underlineAct;//下划线
    QAction *leftAlignAct;//左对齐
    QAction *centerAct;//居中
    QAction *rightAlignAct;//右对齐
    QAction *justifyAct;//两端对齐
    QAction *colorAct;//颜色


    //窗口主菜单
    QMenu *windowMenu;
    QAction *closeAct;//关闭
    QAction *closeAllAct;//关闭所有
    QAction *tileAct;//平铺
    QAction *cascadeAct;//层叠
    QAction *nextAct;//下一个
    QAction *previousAct;//前一个
    QAction *separatorAct;


    //帮助主菜单
    QMenu *helpMenu;
    QAction *aboutAct;//关于本软件
    QAction *aboutQtAct;//关于Qt

    QToolBar *fileToolBar;//文件工具条
    QToolBar *editToolBar;//编辑工具条
    QToolBar *formatToolBar;//格式工具条
    QToolBar *comboToolBar;//组合选择栏
    QComboBox *comboStyle;//标号与编号类型选择框
    QFontComboBox *comboFont;//字体选择框
    QComboBox *comboSize;//字号选择框


};

#endif // MYWORD_H
