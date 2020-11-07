#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>

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

private:
    Ui::Table *ui;
    QPixmap Watame;
};

#endif // TABLE_H
