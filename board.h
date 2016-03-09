#ifndef __BOARD_H__
#define __BOARD_H__

#include <bitset>
#include <vector>
#include <iostream>
#include "common.h"
using namespace std;

class Board {
   
private:
    bitset<64> black;
    bitset<64> taken;    
       
    bool occupied(int x, int y);
    bool get(Side side, int x, int y);
    void set(Side side, int x, int y);
    bool onBoard(int x, int y);
      
public:
    Board();
    ~Board();
    Board *copy();
        
    bool isDone();
    bool hasMoves(Side side);
    bool checkMove(Move *m, Side side);
    Move *firstPossMove(Side side);
    Move *bestMoveSpace(Side side);
    vector<Move*> potentialMoves(Side side);
    void doMove(Move *m, Side side);
    int countChange(Move *m, Side side);
    int count(Side side);
    int countBlack();
    int countWhite();
    int scoreSpace(Side side);

    void setBoard(char data[]);
};

#endif
