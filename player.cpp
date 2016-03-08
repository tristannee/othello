#include "player.h"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /* 
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
     pBoard = new Board(); // player board
     pBoard->Board::copy(); // set up the board
     timeTaken = 30000;
     theSide = side;
     
     /* The inner square (surrounds the starting square), is the safest
      * place to play if there are no good edges or corners available. */
     int innerSquare[] = {2 + 8 * 3, 2 + 8 * 4, 3 + 8 * 2, 3 + 8 * 4, 
					4 + 8 * 2, 4 + 8 * 4, 5 + 8 * 3, 5 + 8 * 4};
				
	 /* These are the corners of the inner square. */
	 int goodInnerCorners[] = {2 + 8 * 2, 2 + 8 * 4, 5 + 8 * 2, 5 + 8 * 4};
					   
	 /* The corners are the best possible moves to play. */
	 int corners[] = {0 + 8 * 0, 0 + 8 * 7, 7 + 8 * 0, 7 + 8 * 7};
	 
	 /* The good edges are all the edges except the corners and the edge
	  * spots adjacent to the corners. These are the second best moves to
	  * be played, right after the corners. */
	 int goodEdges[] = {0 + 8 * 2, 0 + 8 * 3, 0 + 8 * 4, 0 + 8 * 5,
				  7 + 8 * 2, 7 + 8 * 3, 7 + 8 * 4, 7 + 8 * 5,
				  2 + 8 * 0, 3 + 8 * 0, 4 + 8 * 0, 5 + 8 * 0,
				  2 + 8 * 7, 3 + 8 * 7, 4 + 8 * 7, 5 + 8 * 7};
				  
	 /* The spots diagonal to the corners are the worst spots to play.*/
	 int worstFour[] = {1 + 8 * 1, 1 + 8 * 6, 6 + 8 * 1, 6 + 8 * 6};
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
    if (this->timeTaken >= msLeft && msLeft != -1)
    {
        cout << "Opponent Disqualified!" <<endl;
        return NULL;
    }

    pBoard->Board::doMove(opponentsMove, this->theSide);
    
    return NULL;
}
