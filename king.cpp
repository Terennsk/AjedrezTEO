#include "king.h"
#include "game.h"
#include "pawn.h"
extern Game *game;
King::King(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void King::setImage()
{
    if(side == "blancos")
        setPixmap(QPixmap(":/images/king1.png"));
    else
        setPixmap(QPixmap(":/images/king.png"));
}


void King::moves()
{

    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSide();

        if(col > 0 && row > 0 && !(game->collection[row-1][col-1]->getChessPieceColor() == team)) {//diagonal superior izquierda
            location.append(game->collection[row-1][col-1]);
            game->collection[row-1][col-1]->setColor(QColor(246,248,121));
            if(location.last()->getHasChessPiece()){
                location.last()->setColor(QColor(227,224,57));
            }
        }
        if(col < 7 && row > 0 && !(game->collection[row-1][col+1]->getChessPieceColor() == team)) { // diagonal superior derecha
            location.append(game->collection[row-1][col+1]);
            game->collection[row-1][col+1]->setColor(QColor(246,248,121));
            if(location.last()->getHasChessPiece()){
                location.last()->setColor(QColor(227,224,57));
            }
        }
        if(row>0 && !(game->collection[row-1][col]->getChessPieceColor() == team)) {//arriba
            location.append(game->collection[row-1][col]);
            game->collection[row-1][col]->setColor(QColor(246,248,121));
            if(location.last()->getHasChessPiece()){
                location.last()->setColor(QColor(227,224,57));
            }
        }
        if(row<7 && !(game->collection[row+1][col]->getChessPieceColor() == team)) {//abajo
            location.append(game->collection[row+1][col]);
            game->collection[row+1][col]->setColor(QColor(246,248,121));
            if(location.last()->getHasChessPiece()){
                location.last()->setColor(QColor(227,224,57));
            }
        }
        if(col>0 && !(game->collection[row][col-1]->getChessPieceColor() == team)) {// izquierda
            location.append(game->collection[row][col-1]);
            game->collection[row][col-1]->setColor(QColor(246,248,121));
            if(location.last()->getHasChessPiece()){
                location.last()->setColor(QColor(227,224,57));
            }
        }
        if(col<7 && !(game->collection[row][col+1]->getChessPieceColor() == team)) {//derecha
            location.append(game->collection[row][col+1]);
            game->collection[row][col+1]->setColor(QColor(246,248,121));
            if(location.last()->getHasChessPiece()){
                location.last()->setColor(QColor(227,224,57));
            }
        }
        if(col > 0 && row < 7  && !(game->collection[row+1][col-1]->getChessPieceColor() == team)) {//diagonal inferior izquierda
            location.append(game->collection[row+1][col-1]);
            game->collection[row+1][col-1]->setColor(QColor(246,248,121));
            if(location.last()->getHasChessPiece()){
                location.last()->setColor(QColor(227,224,57));
            }
        }
        if(col < 7 && row < 7 && !(game->collection[row+1][col+1]->getChessPieceColor() == team)) {//diagonal inferior derecha
            location.append(game->collection[row+1][col+1]);
            game->collection[row+1][col+1]->setColor(QColor(246,248,121));
            if(location.last()->getHasChessPiece()){
                location.last()->setColor(QColor(227,224,57));
            }
        }


            findUnSafeLocation();


}

void King::findUnSafeLocation() {
    QList <ChessPiece *> pList = game->alivePiece;
    for(size_t i = 0,n = pList.size(); i < n; i++) {

        if(pList[i]->getSide() != this->getSide())
        {
            QList <ChessBox *> bList = pList[i]->moveLocation();

            for(size_t j = 0, n = bList.size(); j < n; j++) {
                Pawn *c = dynamic_cast<Pawn *> (pList[i]) ;
                if(c)
                    continue;
                for(size_t k = 0, n = location.size(); k < n; k++) {
                   if(bList[j] == location [k]) {
                       location[k]->setColor(Qt::red);
                   }
                }
            }
        }
    }
}
