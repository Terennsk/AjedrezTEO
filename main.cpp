
#include <QApplication>
#include "game.h"

Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->setFixedSize(1366,768);
    game->show();
    game->drawChessBoard();
    game->start();
    return a.exec();
}
