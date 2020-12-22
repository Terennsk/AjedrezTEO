#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <chessboard.h>
#include "chesspiece.h"
class Game:public QGraphicsView
{
    Q_OBJECT
public:

    Game(QWidget *parent = 0);

    void drawDeadHolder(int x, int y);
    void drawChessBoard();
    void displayDeadWhite();
    void displayDeadBlack();
    void placeInDeadPlace(ChessPiece *piece);


    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    ChessPiece *pieceToMove;

    QString getTurn() ;
    void setTurn( QString value);
    void changeTurn();

    ChessBox *collection[8][8];
    QGraphicsTextItem *check;
    QList <ChessPiece *> alivePiece;
    void displayMainMenu();

    void gameOver();
    void removeAll();
public slots:
    void start();
private:
    QGraphicsScene *gameScene;
    QList <ChessPiece *> whiteDead;
    QList <ChessPiece *> blackDead;
    QGraphicsRectItem * deadHolder;
    QString turn;
    ChessBoard *chess;
    QList <QGraphicsItem *> listG;
    QGraphicsTextItem * turnDisplay;


};

#endif // GAME_H
