#include "sortwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QHBoxLayout>

SortWidget::SortWidget(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(700, 400);
    setStyleSheet("background-color: #f0f2f5;");
    initRandomBars();
}

// 生成随机高度柱子
void SortWidget::initRandomBars()
{
    barHeights.clear();
    for (int i = 0; i < 8; ++i) {
        int h = QRandomGenerator::global()->bounded(60, 280);
        barHeights.append(h);
    }
    update();
}

// 检查是否升序排列
bool SortWidget::isSorted()
{
    for (int i = 1; i < barHeights.size(); ++i) {
        if (barHeights[i] < barHeights[i-1])
            return false;
    }
    return true;
}

// 绘制柱子
void SortWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int x = 50;
    int baseY = height() - 30;

    for (int i = 0; i < barHeights.size(); ++i) {
        int h = barHeights[i];

        // 拖拽中的柱子高亮
        if (i == draggingIndex) {
            p.setBrush(QColor("#ff7043"));
        } else {
            p.setBrush(QColor("#42a5f5"));
        }

        p.drawRect(x, baseY - h, barWidth, h);
        x += barWidth + barMargin;
    }
}

// 鼠标按下：选中柱子
void SortWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) return;

    int x = 50;
    draggingIndex = -1;

    for (int i = 0; i < barHeights.size(); ++i) {
        QRect barRect(x, height() - 30 - barHeights[i], barWidth, barHeights[i]);
        if (barRect.contains(event->pos())) {
            draggingIndex = i;
            dragStartPos = event->pos();
            break;
        }
        x += barWidth + barMargin;
    }
}

// 鼠标拖拽：实时交换位置
void SortWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (draggingIndex < 0) return;

    int dx = event->x() - dragStartPos.x();
    int step = barWidth + barMargin;

    // 向左拖
    if (dx < -step && draggingIndex > 0) {
        qSwap(barHeights[draggingIndex], barHeights[draggingIndex-1]);
        draggingIndex--;
        dragStartPos = event->pos();
        update();
    }

    // 向右拖
    if (dx > step && draggingIndex < barHeights.size()-1) {
        qSwap(barHeights[draggingIndex], barHeights[draggingIndex+1]);
        draggingIndex++;
        dragStartPos = event->pos();
        update();
    }
}

// 鼠标松开：检查是否完成排序
void SortWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (draggingIndex == -1) return;

    draggingIndex = -1;
    update();

    if (isSorted()) {
        QMessageBox::information(this, "完成", "✅ 恭喜你排序成功！");
        initRandomBars();
    }
}