#include <QtGui>
#include <QApplication>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QTextEdit>
#include <QCheckBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QObject>

#include <parsefile.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;
    ParseFile file;

    QMenuBar* menu = new QMenuBar();
    QMenu* mfile = new QMenu("&File");
    menu->addMenu(mfile);
    QAction* exit = new QAction("Exit",&wgt);

    mfile->addAction(exit);

// Верхняя часть
    QLabel* filename = new QLabel("file");
    QPushButton* openButton = new QPushButton("Open");
    QObject::connect(openButton,SIGNAL(clicked()),&file,SLOT(open()));

    QBoxLayout* top = new QBoxLayout(QBoxLayout::LeftToRight);
    top->addWidget(filename,1);
    top->addWidget(openButton);

//Нижняя часть
    QTextEdit* body = new QTextEdit();

    // чекбоксы
    QCheckBox* wrn = new QCheckBox("warning");
    QCheckBox* ftl = new QCheckBox("fatal");
    QCheckBox* inf = new QCheckBox("info");

    QBoxLayout* options = new QBoxLayout(QBoxLayout::TopToBottom);
    options->addWidget(inf);
    options->addWidget(wrn);
    options->addWidget(ftl);
    options->addStretch(1);

    QBoxLayout* bottom = new QBoxLayout(QBoxLayout::LeftToRight);
    bottom->addWidget(body,1);
    bottom->addLayout(options);


//Склеивание всех частей
    QBoxLayout* mainCnt = new QBoxLayout(QBoxLayout::TopToBottom);
    mainCnt->addWidget(menu);
    mainCnt->addLayout(top);
    mainCnt->addLayout(bottom,1);

    wgt.setLayout(mainCnt);
    wgt.show();

    return a.exec();
}
