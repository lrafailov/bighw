#ifndef COMMON_H
#define COMMON_H

#include <QString>


typedef struct Game
{
    QString id;
    bool rated;
    QString victoryStatus;
    QString winner;
    QString whiteId;
    int whiteRating;
    QString blackId;
    int blackRating;
    QString allMoves;
} Game;

#endif
