#include "widget.h"
#include "ui_widget.h"
#include<QDateTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btnMax, SIGNAL(clicked()), this, SLOT(showMaximized()));

    connect(ui->btnTitle, &QPushButton::clicked, this, [this]() {
        QString title = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        this->setWindowTitle(title);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    this->showMinimized();
}

