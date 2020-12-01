#ifndef PIECE_H
#define PIECE_H
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QImage>

namespace Ui {
class Piece;
}
class Piece:public QLabel
{
   Q_OBJECT
public:
   explicit Piece(QWidget *parent = nullptr);
   virtual void MovePiece()=0;
   virtual ~Piece(){};
   //void paintEvent(QPaintEvent * event) override;
protected:
   Ui::Piece *ui;

   QPixmap PieceIcon;
};

#endif // PIECE_H
