#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece
{
public:
    explicit Pawn(QWidget *parent = nullptr);
    void MovePiece(){};
};

#endif // PAWN_H
