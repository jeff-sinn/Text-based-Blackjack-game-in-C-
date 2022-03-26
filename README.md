# Group-project

Group: 168

Chan Tak Lung (UID: 3035926992)
Sin Chung Hang (UID: 3035928067)


Description of the game: Blackjack
`
1 dealer 1-3 players
dealer is an AI

The goal of blackjack is to beat the dealer's hand without going over 21.
Each player starts with two cards, one of the dealer's cards is hidden until the end.
Face cards are worth 10. Aces are worth 1 or 11, whichever makes a better hand. 2-10 cars are worth 2-10 respectively.
To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn.
If you go over 21 you bust, and the dealer wins regardless of the dealer's hand.
If you are dealt 21 from the start (Ace & 10), you got a blackjack.
Dealer will hit until his/her cards total 17 or higher.
Winning rules: blackjack > 21 points > 20 points ...
Each players have 100 tokens. When one of the player have no tokens left, the player/banker with most tokens win.

Code requirement:
generation of random sets: the cards recieved by the dealer or players are determined by the random function in C++
Data structure for storing game status: 1.integer for the tokens remained 2.string/int for the cards drawn. 3.arrays of the cards in hand of each player.
Dynamic memory management: We don't know what it is. May you teach us how to apply it into our project?
File input: Number of the players (1-3) / Whether the player 'hit' to ask for the cards.
File output: the card board of the players / the player win or lose against the dealer / tokens left in each round / which player have the most tokens left when the game ends

program codes in multiple files: 1.Calculate and show the number of tokens 2.Input the number of players and generate the cards for players and banker. 3.Determine the a player win/lose against the dealer. 4.print the card board of the players and banker
