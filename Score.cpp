//
//  Score.cpp
//  Bunco
//
//  Created by Howard Stahl on 2/21/22.
//  Copyright © 2022 Howard Stahl. All rights reserved.
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

    // setup a default score - all WRONG ANSWER's
    Score::Score()
    {
        for (int i = 0; i < REQUIREDLENGTH; i++)
        {
            array[i] = WRONG;
        }
    }

    // TODO comparing the played move to the answer move,
    //      build the ANSWER array of this Score

    /////////////////////////////////////////////////////

    //              ADDED SECTION OF CODE

    /////////////////////////////////////////////////////

    Score::Score(Move move, Move answer)
    {
        bool used[REQUIREDLENGTH] = { false };

        for (int i = 0; i < REQUIREDLENGTH; i++)
        {
            LETTER moveChar = move.getPiece(i).getLetter(); //grabs the current leeters
            LETTER answerChar = answer.getPiece(i).getLetter();

            if (moveChar == answerChar) //if current index matches 
            {
                array[i] = ANSWER::RIGHT; // then answer is right
                used[i] = true;
            }
            else
            {

                array[i] = ANSWER::WRONG; // Default to WRONG answer
                for (int j = 0; j < REQUIREDLENGTH; j++)
                {
                    if (!used[j] && moveChar == answer.getPiece(j).getLetter()) //iterate inner loop by j for letter that hasn't been used but present

                    {
                        array[i] = ANSWER::MAYBE;
                        used[j] = true;
                        break;
                    }
                }


            }
        }
    }



    // trivial getter but throw logic_error if the index is out of range
    ANSWER Score::getAnswer(int i)
    {
        if (i >= 0 && i < REQUIREDLENGTH)
            return(array[i]);
        else
            throw std::logic_error("invalid i value");
    }

    // stringify this Score
    std::string Score::to_string() const
    {
        std::string s = "";
        int mCount = 0;
        int rCount = 0;
        for (int i = 0; i < REQUIREDLENGTH; i++)
        {
            switch (array[i])
            {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
            }
        }
        return(s);
    }

    // TODO is the ANSWER array all RIGHT ANSWER's?

    /////////////////////////////////////////////////////

    //              ADDED SECTION OF CODE

    /////////////////////////////////////////////////////
    bool Score::isExactMatch() const
    {
        for (int i = 0; i < REQUIREDLENGTH; i++)
        {
            if (array[i] != ANSWER::RIGHT)  // <-- Add ANSWER:: namespace
            {
                return false;
            }
        }
        return true;
    }


}

