#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    Watame.load("/home/teren/Downloads/AjedrezTEO-main/a.jpg");

    peon = std::make_unique<Pawn>(this);

    peon ->move(0,0);
    peon ->show();
    drawBoxes();
}

Table::~Table()
{
    delete ui;
}

void Table::paintEvent(QPaintEvent *){
    //imprime watame
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),Watame);
}
void Table::drawBoxes(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            hueco *hoyo=new hueco(this);
            matriz[i][j]=hoyo;
            hoyo->move(62*j,62*i);
            hoyo->show();
        }
    }
}
/*//agarrar y soltar
void Table::mousePressEvent(QMouseEvent *event){
    auto child = childAt(event->pos());
    if(child==nullptr){
        return;
    }
    QByteArray data;
    QDataStream dataStream(&data, QIODevice::WriteOnly);
    dataStream<<QPoint(event->pos()-child->pos());

    QMimeData *mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata", data);
    QDrag *drag=new QDrag(this);
    drag->setMimeData(mimeData);
    drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}
void Table::dragEnterEvent(QDragEnterEvent *event){
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if(event->source()==this){
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else{
            event->acceptProposedAction();
        }
    }else{
        event->ignore();
    }
}
void Table::dragMoveEvent(QDragMoveEvent *event){
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if(event->source()==this){
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else{
            event->acceptProposedAction();
        }
    }else{
        event->ignore();
    }
}
void Table::dropEvent(QDropEvent *event){
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        QByteArray data=event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&data, QIODevice::ReadOnly);
        QPoint offset;
        dataStream>>offset;
        peon->move(event->pos()-offset);
        if(event->source()==this){
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else{
            event->acceptProposedAction();
        }
    }else{
        event->ignore();
    }
}*/
