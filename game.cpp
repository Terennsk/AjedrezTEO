#include "game.h"
#include <QPixmap>
#include "king.h"
#include <QDebug>
Game::Game(QWidget *parent ):QGraphicsView(parent)
{

    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1400,900);
    setFixedSize(1400,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black); //cabezera
    setBackgroundBrush(brush);
    pieceToMove = NULL;

    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-100,10);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turno de los blancos");

    check = new QGraphicsTextItem();
    check->setPos(width()/2-100,860);
    check->setZValue(4);
    check->setDefaultTextColor(QColor(227,224,57));
    check->setFont(QFont("",18));
    check->setPlainText("Check!");
    check->setVisible(false);
    setTurn("blancos");

}

void Game::drawChessBoard()
{
    chess = new ChessBoard();
    drawDeadHolder(0,0);
    drawDeadHolder(1100,0);
     chess->drawBoxes(width()/2-400,50);

}

void Game::displayDeadWhite()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = whiteDead.size(); i<n; i++) {
            if(j == 4){
                k++;
                j = 0;
            }
            whiteDead[i]->setPos(40+SHIFT*j++,100+SHIFT*2*k);
    }
}

void Game::displayDeadBlack()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = blackDead.size(); i<n; i++) {
        if(j == 4){
            k++;
            j = 0;
        }
        blackDead[i]->setPos(1140+SHIFT*j++,100+SHIFT*2*k);
    }
}

void Game::placeInDeadPlace(ChessPiece *piece)
{
    if(piece->getSide() == "blancos") {
        whiteDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if(g){

            check->setPlainText("Ganan los negros");
            gameOver();
        }
        displayDeadWhite();
    }
    else{
        blackDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if(g){

            check->setPlainText("Ganan los blancos");
            gameOver();
        }
        displayDeadBlack();
    }
    alivePiece.removeAll(piece);
}

void Game::addToScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);

}

QString Game::getTurn()
{
    return turn;
}

void Game::setTurn(QString value)
{
    turn = value;
}

void Game::changeTurn()
{
    if(getTurn() == "blancos")
        setTurn("negros");
    else
        setTurn("blancos");
    turnDisplay->setPlainText("Turno de los " + getTurn());
}

void Game::start()
{
    for(size_t i =0, n = listG.size(); i < n; i++)
        removeFromScene(listG[i]);

    addToScene(turnDisplay);
    QGraphicsTextItem* blancascomidas = new QGraphicsTextItem();
    blancascomidas->setPos(70,10);
    blancascomidas->setZValue(1);
    blancascomidas->setDefaultTextColor(Qt::white);
    blancascomidas->setFont(QFont("",14));
    blancascomidas->setHtml(QString("<div style='background:rgba(242, 163, 74, 60%);'>" + QString("PIEZAS BLANCAS") + QString("</div>")));
    addToScene(blancascomidas);
    QGraphicsTextItem *negrascomidas = new QGraphicsTextItem();

    negrascomidas->setPos(1170,10);
    negrascomidas->setZValue(1);
    negrascomidas->setDefaultTextColor(Qt::black);
    negrascomidas->setFont(QFont("",14));
    negrascomidas->setHtml(QString("<div style='background:rgba(242, 163, 74, 60%);'>" + QString("PIEZAS NEGRAS") + QString("</div>")));
    addToScene(negrascomidas);
    addToScene(check);
    chess->addChessPiece();
}

void Game::drawDeadHolder(int x, int y)
{
    deadHolder = new QGraphicsRectItem(x,y,300,900);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setTexture(QPixmap(":/images/mesa.jpg"));
    deadHolder->setBrush(brush);
    addToScene(deadHolder);
}

void Game::gameOver()
{
    setTurn("blancos");
    alivePiece.clear();
    chess->reset();

}

void Game::removeAll(){
    QList<QGraphicsItem*> itemsList = gameScene->items();
    for(size_t i = 0, n = itemsList.size();i<n;i++) {
        if(itemsList[i]!=check)
          removeFromScene(itemsList[i]);
    }
}
