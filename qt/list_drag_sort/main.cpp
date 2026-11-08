#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        // 设置窗口标题和大小
        setWindowTitle("拖拽排序初版 Demo");
        resize(400, 300);

        // 中心控件及布局
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        // 说明标签
        QLabel *infoLabel = new QLabel("✨ 拖拽任意项目即可重新排序", this);
        infoLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(infoLabel);

        // ----- 核心控件：QListWidget -----
        listWidget = new QListWidget(this);
        // 1. 允许拖拽
        listWidget->setDragEnabled(true);
        // 2. 允许接收拖放
        listWidget->setAcceptDrops(true);
        // 3. 设置拖放模式为内部移动 (关键!)
        listWidget->setDragDropMode(QAbstractItemView::InternalMove);
        // 4. 设置移动方式为“吸附” (让拖拽移动体验更平滑)
        listWidget->setMovement(QListView::Snap);

        // 添加一些示例项目
        for (int i = 1; i <= 6; ++i) {
            QListWidgetItem *item = new QListWidgetItem(QString("项目 %1").arg(i));
            // 可选的：让项目可选中、可拖拽的标志 (默认已满足)
            item->setFlags(item->flags() | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
            listWidget->addItem(item);
        }

        layout->addWidget(listWidget);

        // 可选：一个重置按钮，用于恢复初始顺序 (演示用)
        QPushButton *resetBtn = new QPushButton("恢复初始顺序", this);
        layout->addWidget(resetBtn);

        connect(resetBtn, &QPushButton::clicked, this, &MainWindow::resetOrder);
    }

private slots:
    void resetOrder()
    {
        // 清空原顺序
        listWidget->clear();
        // 重新按 1 到 6 添加
        for (int i = 1; i <= 6; ++i) {
            QListWidgetItem *item = new QListWidgetItem(QString("项目 %1").arg(i));
            item->setFlags(item->flags() | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
            listWidget->addItem(item);
        }
    }

private:
    QListWidget *listWidget;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}