#ifndef SORTABLEBARWIDGET_H
#define SORTABLEBARWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>

class SortableBarsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SortableBarsWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    struct Bar {
        int value;
        int x;
        int width;
        bool isDragging;
    };

    QVector<Bar> bars;
    int draggedIndex;
    QPoint dragOffset;
    bool isDragging;

    void initBars();
    void drawBar(QPainter &painter, const Bar &bar, bool isDragging = false);
    void swapBars(int index1, int index2);
};

#endif