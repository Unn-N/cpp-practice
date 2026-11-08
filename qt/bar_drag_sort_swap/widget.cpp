#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("鼠标拖拽排序演示");
    resize(1000, 500);

    barWidget = new SortableBarsWidget(this);
    barWidget->setGeometry(0, 0, width(), height());
}

Widget::~Widget()
{
    delete ui;
}