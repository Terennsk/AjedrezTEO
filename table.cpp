#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);

    Watame.load("/home/teren/AjedrezTEO/a.jpg");
}

Table::~Table()
{
    delete ui;
}

void Table::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),Watame);
}
