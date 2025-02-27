#define DEMO7

#include <cstdlib>
#include <iostream>
using namespace std;

#if defined( DEMO1 ) // Simples bot�o sem c�digo a ele associado

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton hello("Hello world!");
    hello.resize(100, 30);

    hello.show();
    
    return app.exec();
}

#elif defined(DEMO2) // Um bot�o para terminar a aplica��o

#include <QApplication>
#include <QFont>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton quit("Sair");
    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    quit.show();
    return app.exec();
}

#elif defined(DEMO3) // Cria uma janela principal para a aplica��o anterior

#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     // As 2 linhas seguintes criam a janela principal 
     QWidget window;
     window.resize(200, 120);

     QPushButton quit("Quit", &window);
     quit.setFont(QFont("Times", 18, QFont::Bold));
     quit.setGeometry(10, 40, 180, 40);
     QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

     window.show();
     return app.exec();
 }
 
#elif defined(DEMO4) // Como definir uma nova Widget

 #include <QApplication>
 #include <QFont>
 #include <QPushButton>
 #include <QWidget>

 class MyWidget : public QWidget
 {
 public:
     MyWidget(QWidget *parent = 0);
 };

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     setFixedSize(200, 120);

     QPushButton *quit = new QPushButton(tr("Quit"), this);
     quit->setGeometry(62, 40, 75, 30);
     quit->setFont(QFont("Times", 18, QFont::Bold));

     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
 }

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MyWidget widget;
     widget.show();
     return app.exec();
 }

#elif defined(DEMO5) // Como conectar v�rias widgets utilizando o mecanismo 
                     // "signal e slot"

 #include <QApplication>
 #include <QFont>
 #include <QLCDNumber>
 #include <QPushButton>
 #include <QSlider>
 #include <QVBoxLayout>
 #include <QWidget>

 class MyWidget : public QWidget
 {
 public:
     MyWidget(QWidget *parent = 0);
 };

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     QPushButton *quit = new QPushButton(tr("Quit"));
     quit->setFont(QFont("Times", 18, QFont::Bold));

     QLCDNumber *lcd = new QLCDNumber(2);
     lcd->setSegmentStyle(QLCDNumber::Filled);

     QSlider *slider = new QSlider(Qt::Horizontal);
     slider->setRange(0, 99);
     slider->setValue(0);

     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
     connect(slider, SIGNAL(valueChanged(int)),
             lcd, SLOT(display(int)));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(quit);
     layout->addWidget(lcd);
     layout->addWidget(slider);
     setLayout(layout);
 }

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MyWidget widget;
     widget.show();
     return app.exec();
 }
 
#elif defined(DEMO6) // Como encapsular dois ou mais widgets em um �nico
                     // V�rios tipos de layouts s�o utilizados para encapsular
                  

 #include <QApplication>
 #include <QFont>
 #include <QGridLayout>
 #include <QLCDNumber>
 #include <QPushButton>
 #include <QSlider>
 #include <QVBoxLayout>
 #include <QWidget>

 class LCDRange : public QWidget
 {
 public:
     LCDRange(QWidget *parent = 0);
 };

 LCDRange::LCDRange(QWidget *parent)
     : QWidget(parent)
 {
     QLCDNumber *lcd = new QLCDNumber(2);
     lcd->setSegmentStyle(QLCDNumber::Filled);

     QSlider *slider = new QSlider(Qt::Horizontal);
     slider->setRange(0, 99);
     slider->setValue(0);
     connect(slider, SIGNAL(valueChanged(int)),
             lcd, SLOT(display(int)));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(lcd);
     layout->addWidget(slider);
     setLayout(layout);
 }

 class MyWidget : public QWidget
 {
 public:
     MyWidget(QWidget *parent = 0);
 };

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     QPushButton *quit = new QPushButton(tr("Quit"));
     quit->setFont(QFont("Times", 18, QFont::Bold));
     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

     QGridLayout *grid = new QGridLayout;
     for (int row = 0; row < 3; ++row) {
         for (int column = 0; column < 3; ++column) {
             LCDRange *lcdRange = new LCDRange;
             grid->addWidget(lcdRange, row, column);
         }
     }

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(quit);
     layout->addLayout(grid);
     setLayout(layout);
 }

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MyWidget widget;
     widget.show();
     return app.exec();
 }
 
#elif defined( DEMO7) // Como criar widgets customizadas com signals e slots

 #include <QApplication>
 #include <QFont>
 #include <QGridLayout>
 #include <QPushButton>
 #include <QWidget>

 #include "MyLCD.h"

 class MyWidget : public QWidget
 {
 public:
     MyWidget(QWidget *parent = 0);
 };

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     QPushButton *quit = new QPushButton(tr("Quit"));
     quit->setFont(QFont("Times", 18, QFont::Bold));

     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

     QGridLayout *grid = new QGridLayout;
     MyLCD *previousRange = 0;

     for (int row = 0; row < 3; ++row) {
         for (int column = 0; column < 3; ++column) {
             MyLCD *lcdRange = new MyLCD;
             grid->addWidget(lcdRange, row, column);
             if (previousRange)
                 connect(lcdRange, SIGNAL(valueChanged(int)),
                         previousRange, SLOT(setValue(int)));
             previousRange = lcdRange;
         }
     }
     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(quit);
     layout->addLayout(grid);
     setLayout(layout);
 }

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MyWidget widget;
     widget.show();
     return app.exec();
 }
#endif
