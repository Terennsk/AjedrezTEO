#include "chessboard.h"
#include "chessbox.h"
#include "game.h"
#include "queen.h"
#include "rook.h"
#include "pawn.h"
#include "king.h"
#include "knight.h"
#include "bishop.h"
extern Game *game;
ChessBoard::ChessBoard()
{
    setUpBlack();
    setUpWhite();
}
void ChessBoard::drawBoxes(int x,int y)
{
    int SHIFT = 100;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            ChessBox *box = new ChessBox();
            game->collection[i][j] = box;
            box->rowLoc = i;
            box->colLoc = j;
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                //colores del tablero
                box->setOriginalColor(QColor(119, 149, 87));
            else
                box->setOriginalColor(QColor(236, 236, 208));
            game->addToScene(box);



        }
    }

}

void ChessBoard::addChessPiece() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessBox *box =game->collection[i][j];
            if(i < 2) {
                static int k;
                box->placePiece(black[k]);
                game->alivePiece.append(black[k]);
                game->addToScene(black[k++]);
            }
            if(i > 5) {
                static int h;
                box->placePiece(white[h]);
                game->alivePiece.append(white[h]);
                game->addToScene(white[h++]);
            }

        }
    }
}

void ChessBoard::setUpWhite()
{
    ChessPiece *piece;
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("blancos");
        white.append(piece);
    }
    piece = new Rook("blancos");
    white.append(piece);
    piece = new Knight("blancos");
    white.append(piece);
    piece = new Bishop("blancos");
    white.append(piece);
    piece = new Queen("blancos");
    white.append(piece);
    piece = new King("blancos");
    white.append(piece);
    piece = new Bishop("blancos");
    white.append(piece);
    piece = new Knight("blancos");
    white.append(piece);
    piece = new Rook("blancos");
    white.append(piece);

}

void ChessBoard::setUpBlack()
{
    ChessPiece *piece;
    piece = new Rook("negros");
    black.append(piece);
    piece = new Knight("negros");
    black.append(piece);
    piece = new Bishop("negros");
    black.append(piece);
    piece = new Queen("negros");
    black.append(piece);
    piece = new King("negros");
    black.append(piece);
    piece = new Bishop("negros");
    black.append(piece);
    piece = new Knight("negros");
    black.append(piece);
    piece = new Rook("negros");
    black.append(piece);
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("negros");
        black.append(piece);
    }
}


void ChessBoard::reset() {
    int k = 0; int h = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessBox *box =game->collection[i][j];
            box->setHasChessPiece(false);
            box->setChessPieceColor("NONE");
            box->currentPiece = NULL;
            if(i < 2) {

                box->placePiece(black[k]);
                black[k]->setIsPlaced(true);
                black[k]->firstMove = true;
                game->alivePiece.append(black[k++]);

            }
            if(i > 5) {

                box->placePiece(white[h]);
                white[h]->setIsPlaced(true);
                white[h]->firstMove = true;
                game->alivePiece.append(white[h++]);

            }

        }
    }
}
