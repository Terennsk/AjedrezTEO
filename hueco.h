#ifndef HUECO_H
#define HUECO_H

#include <QWidget>

namespace Ui {
class hueco;
}

class hueco : public QWidget
{
    Q_OBJECT

public:
    explicit hueco(QWidget *parent = nullptr);
    ~hueco();

private:
    Ui::hueco *ui;
};

#endif // HUECO_H
