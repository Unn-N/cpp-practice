#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPoint>

class SortWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SortWidget(QWidget *parent = nullptr);

protected:
    // 绘制柱子
    void paintEvent(QPaintEvent *event) override;

    // 鼠标事件实现拖拽
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    // 初始化随机数据
    void initRandomBars();

    // 检查是否排好序
    bool isSorted();

    // 柱子信息
    QVector<int> barHeights;
    const int barWidth = 50;
    const int barMargin = 15;

    // 拖拽相关
    int draggingIndex = -1;
    QPoint dragStartPos;
};

#endif // SORTWIDGET_H