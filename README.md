# Group-project

Group: 168

Chan Tak Lung (UID: 3035926992)
Sin Chung Hang (UID: 3035928067)

Description of the game: Blackjack

1 dealer 1 player
dealer is an AI

The goal of blackjack is to beat the dealer's hand without going over 21.
Player starts with two cards, dealer start with one card.
Face cards are worth 10. Aces are worth 1 or 11, whichever makes a better hand. 2-10 cars are worth 2-10 respectively.
The player can draw the card whatever they want until its point over 21.
If you go over 21 you bust, and the dealer wins regardless of the dealer's hand.
If you are dealt 21 from the start (Ace & 10), you got a blackjack.
Dealer will hit until his/her cards total 17 or higher.
Winning rules: blackjack > 21 points > 20 points ...

Apart from the normal black jack game, we also provide 21+3 and perfect pairs for player to play.
21+3 and perfect pairs are optional for the player, the player need use one tokens for each if the want to bet.
21+3 mean the the special cases of the first three cards( two are the players cards and one is the dealer cards).
- If these three cards form a flush + three of a kind, the player will gain 50 tokens.
- If these three cards form a flush + straight , the player will gain 25 tokens.
- If these three cards form three of a kind only, the player will gain 25 tokens.
- If these three cards form a straight only, the player will gain 10 tokens.
- If these three cards form a flush only, the player will gain 5 tokens.
- If all the above cases haven't happened, the player will lose 1 token on 21+3.

Perfect pairs mean the special cases of the two player cards.
- If these two cards form a flush and pairs, they player will gain 30 tokens.
- If these two cards form a pairs only, the player will gain 5 tokens.
- If all the above cases haven't happened , the player will lose 1 token on the perfect pairs.

Assumption:
Each players have 20 tokens originally. The player can only bet one token on each game, 21+3 and perfect pairs. Then, they will coninue on blackjack using 1 token. When the player have less than 3 tokens left, the game will give the player 20 more tokens.

Input of the game:
In the beginning of the game, the player need to input a number to start the game as a seed to the random function and input whether he/she bet the 21+3 and perfect pair or not. 

Next, they need to determine whether they draw the card or not due to the card combinations.


Code requirement:

1.generation of random sets: the cards recieved by the dealer or players are determined by the random function in C++

2.Data structure for storing game status.
-integer for the tokens remained 
-int for the cards drawn. 
-linked list of the cards in hand of each player.
  
3.Dynamic memory management: 
-we use pointer and linked list to store and add the player card and dealer card.
  
4. File input and output:

4.1 file input
- read in the tokens of the player before each game start by the token.txt file.
 
4.2 File output:
- output the tokens remain of the player after the end of each game to the token.txt for game status storage.
    
5. Program codes in mutliple files:

5.1 bjmain.cpp
- Asking the player draw card or not
- Printing the cards of player and dealer
- Storing the cards state of player and dealer
- Printing the result of the game

5.2 readwrite.cpp
- input the file of tokens of player to the main function 

5.3 readwrite.h
- header file

5.4 specialcase.cpp
- return true or false of each special cases e.g 21+3 and perfect number

5.5 specialcase.h
- header file of specialcase.cpp

5.6 token.txt
- storing the tokens remained of the player

6.Compilation and execution in struction:

For compilation, please type the command "make bjmain" in the terminal to comile the bjmain.cpp file to bjmain. Then, type "./bjmain" to execute the program in the terminal.
