#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <memory>
#include <pawn.h>
#include <QtWidgets>
#include <hueco.h>


namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

    void paintEvent(QPaintEvent * event) override;
    void drawBoxes();
private:
    Ui::Table *ui;
    QPixmap Watame;
    std::unique_ptr<Piece> peon;
    hueco* matriz[8][8];

    /*void mousePressEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;*/
};

#endif // TABLE_H
