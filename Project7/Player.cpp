//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"



namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 )
    {
        
    }
    
    int Player::roll( int amount )
    {
		int rollNumb = 0; //temporary integer
		if (amount == 0) { //if amount inputted is 0
			mDie.roll(); // calls the roll function for the member class mDie which sets the die to a random int 1-6
			rollNumb = mDie.getValue(); //sets the temp integer to that random value using a getter function
		}
		else
			rollNumb = amount; //if the amount paramater is not 0 we force a certain value to the temp integer
		if (rollNumb == mRound) // if the temp integer equals the round number, bunco rules mean that we must increment score
			mScore++;
        return rollNumb;
    }
    
    void Player::setRound( int round )
    {
		mRound = round; //sets the round
		mScore = 0; //resets players score

    }
    
    int  Player::getScore( ) const
    {
        return(mScore); //simple getter function for private variable mScore
    }
    
    
}