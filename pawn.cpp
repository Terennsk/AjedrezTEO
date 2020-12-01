#include "pawn.h"

Pawn::Pawn(QWidget *parent) : Piece(parent)
{
    PieceIcon.load("/home/teren/AjedrezTEO/korone_listener.png");
    this->resize(64,64);
    this->setPixmap(PieceIcon);
}
