#include "hueco.h"
#include "ui_hueco.h"

hueco::hueco(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hueco)
{
    ui->setupUi(this);
}

hueco::~hueco()
{
    delete ui;
}
