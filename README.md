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
If these three cards form a flush + three of a kind, the player will gain 50 tokens.
If these three cards form a flush + straight , the player will gain 25 tokens.
If these three cards form three of a kind only, the player will gain 25 tokens.
If these three cards form a straight only, the player will gain 10 tokens.
If these three cards form a flush only, the player will gain 5 tokens.
If all the above cases haven't happened, the player will lose 1 token on 21+3.
Perfect pairs mean the special cases of the two player cards.
If these two cards form a flush and pairs, they player will gain 30 tokens.
If these two cards form a pairs only, the player will gain 5 tokens.
If all the above cases haven't happened , the player will lose 1 token on the perfect pairs.
Each players have 20 tokens originally. The player can only bet one token on each game, 21+3 and perfect pairs. When the player have 3 tokens left, the game will give the player 20 more tokens.
In the beginning of the game, the player need to input a number to start the game and whether he/she bet the 21+3 and perfect pair or not.
Next, they need to determine whether they draw the card or not due to the card combinations.


Code requirement:
generation of random sets: the cards recieved by the dealer or players are determined by the random function in C++
Data structure for storing game status: 1.integer for the tokens remained 2.string/int for the cards drawn. 3.arrays of the cards in hand of each player.
Dynamic memory management: We don't know what it is. May you teach us how to apply it into our project?
File input: Number of the players (1-3) / Whether the player 'hit' to ask for the cards.
File output: the card board of the players / the player win or lose against the dealer / tokens left in each round / which player have the most tokens left when the game ends

program codes in multiple files: 1.Calculate and show the number of tokens 2.Input the number of players and generate the cards for players and banker. 3.Determine the a player win/lose against the dealer. 4.print the card board of the players and banker

Questions:
1.Is our project difficulty level enough? if it is not enough, we can add more rules in it.
2.We dont know what exactly dynamic memory management is. How can it be applied to our project?
3.We dont know what a list of features is in specific. How can it be applied to our project?
4.Any other recommendation / improvement made for our project outline? (e.g. creative elements that can be added to our proj)
