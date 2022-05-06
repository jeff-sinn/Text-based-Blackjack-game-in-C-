#include <iostream>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <fstream>
#include "readwrite.h"
#include "specialcase.h"
#define SPADE   "\xE2\x99\xA0"//for printing out the suit of the card
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

using namespace std;

struct Desk { // linked list for card
    int card; // the number of card
    Desk* next = NULL; // the pointer pointing the next card in the desk
    Desk() {
        card = rand() % 52;
    }
};

void PrintCard(int cards) { // for printing the card
    string suit[] = { SPADE,HEART,CLUB,DIAMOND };
    string no[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
    cout << suit[cards / 13] << no[cards % 13] << " ";
    // the suit of first 13 numbers are spade and the second 13 numbers are heart and so on
}

class Player { // class of player
public:
    Player() { // constructor of player
        Desk* head = new Desk();  // Add two cards to the desk
        Desk* p = new Desk();
        head->next = p;
        desk = head;
        tail = p;
        addSum(head->card);
        addSum(p->card);
    }
    void print() { // function to print to desk
        Desk* head = desk;
        while (head != NULL) {
            PrintCard(head->card);
            head = head->next;
        }
        cout << endl;
    }
    void addSum(int x) {
        //get the number of the card by % 13
        x = x % 13;
        //if the number is 10,J,Q,K, all value = 10
        if (x > 9) {
            x = 9;
        }
        else if (x == 0) { // If the card is Ace, sum add 11
            Atime ++ ;
            x = 10;
        }
        sum += x+1;  // adjust the x because x is 0~51 originally
        if (sum > 21 && Atime > 0){ // if the sum is greater than 21, change Ace to 1 instead of 11.
            sum -= 10;
            Atime-- ;
        }
    }
    void addCard() {  // Add a new card to the desk
        Desk* p = new Desk();
        tail->next = p;
        tail = p;
        addSum(p->card); // calculate the sum
        count ++; //increase the number of card by 1
    }
    bool end() {
        if (sum > 21 || count == 5) { // If sum is greater than 21 or the number of card is equal to five, player can't add card.
            return true;
        }
        else {
            return false;
        }
    }
    int getSum() { // get the sum of the player desk
        return sum;
    }
    bool isBlackJack(){ // Check BlackJack
        if (sum == 21 && count == 2)
            return true;
        return false;
    }
    Desk * getplayerdesk(){ // get the player desk
        return desk;
    }

private:
    Desk* desk; // the head of linked list
    Desk* tail;// the tail of linked list
    int sum = 0;
    int count = 2; //number of card
    int Atime = 0; // count of Ace
};

class Dealer {
public:
    Dealer() { // Constructor
        Desk* head = new Desk();
        desk = head;
        tail = head;
        addSum(head->card);
    }
    void print() { // print the desk
        Desk* head = desk;
        while (head != NULL) {
            PrintCard(head->card);
            head = head->next;
        }
        cout << endl;
    }

    void addSum(int x) {
        //get the number of the card
        x = x % 13;
        //if the number is 10,J,Q,K, all value = 10
        if (x > 9) {
            x = 9;
        }
        else if (x == 0) { // If the card is Ace, x = 11
            Atime ++ ;
            x = 10;
        }
        sum += x+1;
        if (sum > 21 && Atime > 0){
            sum -= 10;
            Atime-- ;
        }
    }
    void addCard() { // Add card to dealer desk
        Desk* p = new Desk();
        tail->next = p;
        tail = p;
        addSum(p->card);
        count ++;
    }

    int getSum() { //get the sum of the dealer
        return sum;
    }
    bool isBlackJack(){ // Check blackjack
        if (sum == 21 && count == 2)
            return true;
        return false;
    }
    int getcount(){
        return count;
    }
    Desk * getdealerdesk(){ //get the dealer desk
        return desk;
    }

private:
    Desk* desk; // head of linked list
    Desk* tail;
    int sum = 0;
    int count = 1; // number of card
    int Atime = 0; // count of Ace
};

int check21plus3(Desk* player, Desk * dealer, int token){ // check 21+3
    int x = player->card;
    int y = player->next->card;
    int z = dealer->card;
    int xnum = x % 13+1;
    int ynum = y % 13+1;
    int znum = z % 13+1;
    int xsuit = x / 13;
    int ysuit = y / 13;
    int zsuit = z / 13;
    if (checkthreeofakind(xnum,ynum,znum) && checkflush(xsuit,ysuit,zsuit)){
        cout << "You get flush three of a kind !!" << endl;
        cout << "You earn 50 tokens !!" << endl;
        token += 50;
    }
    else if (checkstraight(xnum,ynum,znum) && checkflush(xsuit,ysuit,zsuit)){
        cout << "You get flush straight !!" << endl;
        cout << "You earn 25 tokens !! "<< endl;
        token += 25;
    }
    else if (checkthreeofakind(xnum,ynum,znum)){
        cout << "You get three of a kind !!" << endl;
        cout << "You earn 25 tokens !! " << endl;
        token += 25;
    }
    else if (checkflush(xsuit,ysuit,zsuit)){
        cout << "You get a flush !!" << endl;
        cout << "You earn 5 tokens !!" << endl;
        token += 5;
    }
    else if (checkstraight(xnum,ynum,znum)){
        cout << "You get a straight !!" << endl;
        cout << "You earn 10 tokens !!" << endl;
        token += 10;
    }
    else{
        cout << "You didn't have any special cases." << endl;
        cout << "You lose 1 token." << endl;
        token -=1; 
    }
    return token;
}
int perfectpair(Desk * player, int token){ //check perfect pairs
    int x = player->card;
    int y = player->next->card;
    int xnum = x % 13+1;
    int ynum = y % 13+1;
    int xsuit = x / 13;
    int ysuit = y / 13;
    if (checkpairs(xnum, ynum) && checkpairsflush(xsuit,ysuit)){
        cout << "You get a pair flush !!" << endl;
        cout << "You earn 30 tokens !!" << endl;
        token += 30;
    }
    else if (checkpairs(xnum, ynum)){
        cout << "You get a pair !!" << endl;
        cout << "You earn 5 tokens !!" << endl;
        token += 5;
    }
    else{
        cout << "You didn't have any pairs. " << endl;
        cout << "You lose 1 token. " << endl;
        token -= 1;
    }
    return token;
}




int main()
{
    int x;
    cout << "Please input a lucky number to start the game:";
    cin >> x;
    srand(x);
    Player player; // create player
    Dealer dealer; //create dealer
    char get = 'y'; //initialize 'get'
    char yesorno1, yesorno2;
    int token, result = 0; // result = 0 = lose, result = 1 = win, result = 2 = draw
    token = readinfile();
    cout << "Will you bet the 21+3 (input y/n):";
    cin >> yesorno1;
    cout << "Will you bet the perfectpair (input y/n):";
    cin >> yesorno2;
    if (yesorno1 == 'y' || yesorno2 == 'y'){
        cout << "Dealer's desk: ";
        dealer.print();   //print dealer's desk
        cout << "Player's desk: ";
        player.print();  //print player's desk
    }
    if (yesorno1 == 'y'){
        token = check21plus3(player.getplayerdesk(),dealer.getdealerdesk(), token);
    }
    if (yesorno2 == 'y'){
        token = perfectpair(player.getplayerdesk(), token);
    }
    //Game start
    while (!player.end() && !(get == 'n')) { // While player can to add card

        cout << "Dealer's desk: ";
        dealer.print();   //print dealer's desk
        cout << "Player's desk: ";
        player.print();  //print player's desk
        cout << "Draw card or not (input y/n): ";
        cin >> get;
        while (!(get == 'n') && !(get == 'y')) { // error checking
            cout << "Please input valid character!";
            cin >> get;
        }
        if (get == 'y') {
            player.addCard(); // add a card to player's desk

        }
    }


//if dealer's sum less than 17 or number of card less than 5, add a card
    while(dealer.getSum() < 17 && dealer.getcount()<5){
        dealer.addCard();

    }


    //Game calculate
    cout << "Your desk: ";
    player.print();
    if (player.getSum() > 21) {  // player's sum over 21, player lose
        cout << "Your total:" << player.getSum() << endl;
        cout << "over 21! you lose" << endl;
    }
    else if (player.isBlackJack() ){
        cout << "Dealer's desk: ";
        dealer.print();
        if (dealer.isBlackJack()){ //player blackjack and dealer also blackjack , draw
            cout << "Both are Black Jack, Draw !!!" << endl;
            result = 2;
        }
        else{ //only player blackjack, player win
            cout << "You are Black Jack, You win !!!" << endl;
            result = 1;
        }
    }
    else if (dealer.isBlackJack()){// only dealer blackjack, dealer win
        cout << "Dealer's desk: ";
        dealer.print();
        cout << "Dealer is Black Jack, You lose" << endl;
    }
    else{
        cout << "Your total:" << player.getSum() << endl;
        cout << "Dealer's desk: ";
        dealer.print();
        cout << "Dealer's total: " << dealer.getSum() << endl;
        if (dealer.getSum() > 21) {// dealer's sum over 21, player win
            cout << "dealer over 21. You win!" << endl;
            result = 1;
        }
        else if(dealer.getSum()> player.getSum()){//dealer's sum is greater than
            cout << "Dealer's total is greater than yours, you lose!" << endl;
        }
        else if(dealer.getSum() == player.getSum()){ //dealer's sum equal to player's sum, draw
            cout << "Both are " << dealer.getSum() << " Draw!" << endl;
            result = 2;
        }
        else{ //player's sum is greater than dealer's sum, player win
            cout << "Your total is greater dealer's, you win!" << endl;
            result = 1;
        }
    }
    writetofile(token, result);

}
