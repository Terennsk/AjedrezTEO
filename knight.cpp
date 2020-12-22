#include "knight.h"
#include "game.h"
extern Game *game;

Knight::Knight(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Knight::setImage()
{
    if(side == "blancos")
        setPixmap(QPixmap(":/images/horse1.png"));
    else
        setPixmap(QPixmap(":/images/horse.png"));
}



void Knight::moves()
{
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    int i ,j;
    QString team  = this->getSide();



    i = row - 2;
    j = col - 1;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(QColor(227,224,57));
        else
            location.last()->setColor(QColor(246, 248, 121));
    }

    i = row - 2;
    j = col + 1;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(QColor(227,224,57));
        else
            location.last()->setColor(QColor(246, 248, 121));
    }


    i = row + 2;
    j = col - 1;
    if(i <= 7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(QColor(227,224,57));
        else
            location.last()->setColor(QColor(246, 248, 121));
    }


    i = row + 2;
    j = col + 1;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(QColor(227,224,57));
        else
            location.last()->setColor(QColor(246, 248, 121));
    }

    i = row - 1;
    j = col - 2;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(QColor(227,224,57));
        else
            location.last()->setColor(QColor(246, 248, 121));
    }

    i = row + 1;
    j = col - 2;
    if(i <=7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(QColor(227,224,57));
        else
            location.last()->setColor(QColor(246, 248, 121));
    }

    i = row - 1;
    j = col + 2;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(QColor(227,224,57));
        else
            location.last()->setColor(QColor(246, 248, 121));
    }

    i = row + 1;
    j = col +  2;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(QColor(227,224,57));
        else
            location.last()->setColor(QColor(246, 248, 121));
    }

}

