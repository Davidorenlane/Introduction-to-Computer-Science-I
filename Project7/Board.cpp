//
//  Board.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    Board::Board() : mRound( 0 )
    {
        // initialize each BoardRow
        for (int i = 1; i <= 6; i++)
        {
            mBoardRow[ i ].setRound( i );
        }
    }
    
    void Board::setCurrentRound( int round )
    {
        // unset the current board row
        if (mRound >= 0 && mRound <= 6)
            mBoardRow[ mRound ].setCurrentRound( false );
        mRound = round;
        // set the current board row
        if (mRound >=0 && mRound <=6)
            mBoardRow[ mRound ].setCurrentRound(true);
    }
    
    void Board::markHumanAsWinner()
    {
		mBoardRow[mRound].setHumanAsWinner(); // calls the function within the boardrow class to set the Human as the winner for the given mround 
    }
    
    void Board::markComputerAsWinner() 
    {
		mBoardRow[mRound].setComputerAsWinner(); // calls the function within the boardrow class to set the computer as the winner for the given mround 
    }
    
    // stringify the Board
    std::string Board::display( ) const
    {
        std::string s = "\t\t  Bunco Game\n\tHuman\t\t\tComputer\n";
        
        for( int i = 1; i <= 6; i++)
        {
            s += mBoardRow[ i ].display() + "\n";
        }
        
        return( s );
    }
    
    int Board::countUpHumanRoundWins( ) const
    {
		int roundWins = 0; //temp integer
		for (int i = 1; i <= 6; i++) { //goes through each round
			if (mBoardRow[i].didHumanWin()) { // calls the checker function within the boardrow class for the corresponding round to see if human won that round
				roundWins++; //if so, increments the temp integer
			}
		}
        return roundWins;// returns the temp integer
    }
    
    int Board::countUpComputerRoundWins( ) const
    {
		int roundWins = 0; //temp integer
		for (int i = 1; i <= 6; i++) { //goes through each round
			if (mBoardRow[i].didComputerWin()) { // calls the checker function within the boardrow class for the corresponding round to see if computer won that round
				roundWins++; //if so, increments the temp integer
			}
		}
		return roundWins; // returns the temp integer
    }

    
}