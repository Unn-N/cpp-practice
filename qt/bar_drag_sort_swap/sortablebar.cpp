#include "sortablebar.h"

SortableBarsWidget::SortableBarsWidget(QWidget *parent)
    : QWidget(parent), draggedIndex(-1), isDragging(false)
{
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet("background-color: #f0e9e0;");
    initBars();
}

void SortableBarsWidget::initBars()
{
    QVector<int> values = {12, 21, 35, 11, 19, 43, 66, 51, 27, 59, 22, 63, 80, 92};
    int barWidth = 40;
    int spacing = 15;
    int startX = 30;

    bars.clear();
    for (int i = 0; i < values.size(); ++i) {
        Bar bar;
        bar.value = values[i];
        bar.width = barWidth;
        bar.x = startX + i * (barWidth + spacing);
        bar.isDragging = false;
        bars.append(bar);
    }
}

void SortableBarsWidget::drawBar(QPainter &painter, const Bar &bar, bool isDragging)
{
    painter.save();

    int maxHeight = 300;
    int barHeight = (bar.value * maxHeight) / 100;
    int y = height() - barHeight - 20;

    if (isDragging)
        painter.setBrush(QColor("#e06c48"));
    else
        painter.setBrush(Qt::white);

    painter.setPen(QPen(Qt::lightGray, 1));
    painter.drawRect(bar.x, y, bar.width, barHeight);

    painter.setPen(Qt::black);
    painter.drawText(bar.x, height() - 5, bar.width, 15, Qt::AlignCenter, QString::number(bar.value));

    painter.restore();
}

void SortableBarsWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) return;

    QPoint pos = event->pos();
    draggedIndex = -1;

    for (int i = 0; i < bars.size(); ++i) {
        Bar &bar = bars[i];
        int maxHeight = 300;
        int barHeight = (bar.value * maxHeight) / 100;
        int y = height() - barHeight - 20;

        if (pos.x() >= bar.x && pos.x() <= bar.x + bar.width &&
            pos.y() >= y && pos.y() <= height() - 20)
        {
            draggedIndex = i;
            bar.isDragging = true;
            dragOffset = pos - QPoint(bar.x, y);
            isDragging = true;
            break;
        }
    }
    update();
}

void SortableBarsWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!isDragging || draggedIndex < 0) return;

    QPoint pos = event->pos();
    Bar &draggedBar = bars[draggedIndex];
    draggedBar.x = pos.x() - dragOffset.x();

    if (draggedBar.x < 0) draggedBar.x = 0;
    if (draggedBar.x + draggedBar.width > width())
        draggedBar.x = width() - draggedBar.width;

    for (int i = 0; i < bars.size(); ++i) {
        if (i == draggedIndex) continue;
        Bar &otherBar = bars[i];
        int center = draggedBar.x + draggedBar.width / 2;
        if (center >= otherBar.x && center <= otherBar.x + otherBar.width) {
            swapBars(draggedIndex, i);
            draggedIndex = i;
            break;
        }
    }
    update();
}

void SortableBarsWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton || !isDragging) return;

    isDragging = false;
    bars[draggedIndex].isDragging = false;

    int bw = 40, sp = 15;
    for (int i = 0; i < bars.size(); ++i)
        bars[i].x = 30 + i * (bw + sp);

    draggedIndex = -1;
    update();
}

void SortableBarsWidget::swapBars(int i1, int i2)
{
    qSwap(bars[i1].value, bars[i2].value);
    qSwap(bars[i1].x, bars[i2].x);
}

void SortableBarsWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (int i = 0; i < bars.size(); ++i) {
        if (!bars[i].isDragging)
            drawBar(painter, bars[i]);
    }
    if (draggedIndex >= 0)
        drawBar(painter, bars[draggedIndex], true);
}