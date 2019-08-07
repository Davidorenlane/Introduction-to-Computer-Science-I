//
//  Bunco.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Bunco.h"
#include <iostream>

namespace cs31
{
    Bunco::Bunco() : mRound( 0 )
    {
        
    }
    
    // stringify the game by stringifying the board
    std::string Bunco::display( std::string msg ) const
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (gameIsOver())
        {
            if (determineGameOutcome() == TIEDGAME)
            {
                s = s + "\n\t\tBunco wound up tied!\n";
            }
            else if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Bunco!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Bunco!\n";
            }
        }
        return( s );
    }
    
    // set the current round of play, notifying the board and each
    // player of the current round
    void Bunco::setRound( int round )
    {
        mRound = round;
        mBoard.setCurrentRound( round );
        mHuman.setRound(round);
        mComputer.setRound(round);
    }
    
    int Bunco::humanPlay( int amount )
    {
      return mHuman.roll(amount); //calls the roll function in the player member class (which changes score) and returns the result of the roll
    }
    
    int Bunco::computerPlay( int amount )
    {
        return mComputer.roll(amount); //calls the roll function in the player member class (which changes score) and returns the result of the roll
	}
    //SOME TROUBLE HERE
    Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome( ) 
    {		
        ROUNDOUTCOME result = ROUNDOUTCOME::NOTDECIDED; //default outcome, if the round is not over, will return accordingly
		if (mHuman.getScore() > mComputer.getScore()) { //using getter function for player member class, if the humans score > the computer score...
			mBoard.markHumanAsWinner();  //calls the markHumanAsWinner function for the board which calls a function in boardrow class to put an x on the board and sets the human as the winner for that boardrow
			return HUMANWON; //returns the corresponding enum
		}
		if (mHuman.getScore() < mComputer.getScore()) { //using getter function for player member class, if the humans score < the computer score...
			mBoard.markComputerAsWinner(); //calls the markComputerAsWinner function for the board which calls a function in boardrow class to put an x on the board and sets the comp as the winner for that boardrow
			return COMPUTERWON; //returns the corresponding enum
		}
		
        return( result );
    }
    //SOME TROUBLE HERE
    Bunco::GAMEOUTCOME  Bunco::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER; //default outcome, if the game is not over, will return accordingly
		if (mBoard.countUpComputerRoundWins() + mBoard.countUpHumanRoundWins() == 6) { //logic to ensure game is complete if so the total of all rounds won by both players won must equal 6
			if (mBoard.countUpComputerRoundWins() == mBoard.countUpHumanRoundWins()) // calling the functions in the board class used to sum up each players round victories,
				result = TIEDGAME;
			if (mBoard.countUpComputerRoundWins() < mBoard.countUpHumanRoundWins())// checks to see who has won more rounds or if equal, AND 
				result = HUMANWONGAME;
			if (mBoard.countUpComputerRoundWins() > mBoard.countUpHumanRoundWins()) //changes the GAMEOUTCOME enum  to TIEDGAME, HUMANWONGAME, or COMPUTERWONGAME, accordingLY
				result = COMPUTERWONGAME;
		}
        return( result ); //returns the result
    }
    
    // is the game over?
    bool Bunco::gameIsOver() const
    {
        GAMEOUTCOME result = determineGameOutcome();
        return( result != GAMENOTOVER );
    }

}