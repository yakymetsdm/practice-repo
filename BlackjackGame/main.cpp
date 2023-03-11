// This program is Blackjack card game
//
#include <iostream>
#include <ctime>
#include <array>
#include <string>

//Suits of cards
enum CardSuit
{
	SUIT_CLOVER,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS
};

//Card ranks
enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_J,
	RANK_Q,
	RANK_K,
	RANK_A,
	MAX_RANKS
};

//Blackjack game results 
enum class Blackjack
{
	RESULT_PLAYER_WIN,
	RESULT_DEALER_WIN,
	RESULT_DRAW
};

struct Card
{
	CardRank rank;
	CardSuit suit;
};

int getRandomNumber(int min, int max);
int getCardValue(const Card& card);
std::string getPlayerChoice();

void printCard(const Card& card);
void printDeck(const std::array<Card, 52>& cards);
void swapCards(Card& card1, Card& card2);
void shuffleDeck(std::array<Card, 52>& deck);

Blackjack playBlackjack(std::array<Card, 52>& deck);

int main()
{
	srand(static_cast<unsigned>(time(0)));
	rand();

	const int numCards = 52;		//cards in the deck
	std::array<Card, numCards> deck;

	int indexCard = 0;				//position where the card placed in the deck
	for (int rank = 0; rank < MAX_RANKS; ++rank)
	{
		//I lay out cards of the same rank next to each other
		for (int suit = 0; suit < MAX_SUITS; ++suit)
		{
			deck[indexCard].rank = static_cast<CardRank>(rank);
			deck[indexCard].suit = static_cast<CardSuit>(suit);
			++indexCard;
		}
	}

	//Contorls for the game
	char startPlay, playAgain;

	do
	{
		std::cout << "Do you want play Blackjack (y)/(n): ";
		std::cin >> startPlay;

		if (std::cin.fail())
			std::cin.clear();

		std::cin.ignore(32767, '\n');

	} while (startPlay != 'y' && startPlay != 'n');

	//Start playing
	if (startPlay == 'y')
	{
		do {
			//Result of one game
			switch (playBlackjack(deck))
			{
			case Blackjack::RESULT_PLAYER_WIN:	std::cout << "You win!" << std::endl;	break;
			case Blackjack::RESULT_DEALER_WIN:	std::cout << "You lose." << std::endl;	break;
			case Blackjack::RESULT_DRAW:		std::cout << "Draw!" << std::endl;		break;
			}
			//Play again
			do {
				std::cout << "\nDo you want play again (y)/(n): ";
				std::cin >> playAgain;
				if (std::cin.fail())
					std::cin.clear();
				std::cin.ignore(32767, '\n');
			} while (playAgain != 'y' && playAgain != 'n');
		} while (playAgain != 'n');

		std::cout << "\nThanks for the game. Goodbye!" << std::endl;
	}
	else
		std::cout << "Goodbye!" << std::endl;

	return 0;
}


int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>((rand() * fraction * (static_cast<double>(max) - min)) + 1 + min);
}

int getCardValue(const Card& card)
{
	switch (card.rank)
	{
	case RANK_2: return 2;
	case RANK_3: return 3;
	case RANK_4: return 4;
	case RANK_5: return 5;
	case RANK_6: return 6;
	case RANK_7: return 7;
	case RANK_8: return 8;
	case RANK_9: return 9;
	case RANK_10: return 10;
	case RANK_J: return 10;
	case RANK_Q: return 10;
	case RANK_K: return 10;
	case RANK_A: return 11;
	}
	return 0;
}

void printCard(const Card& card)
{
	switch (card.rank)
	{
	case RANK_2:	std::cout << "2";		break;
	case RANK_3:	std::cout << "3";		break;
	case RANK_4:	std::cout << "4";		break;
	case RANK_5:	std::cout << "5";		break;
	case RANK_6:	std::cout << "6";		break;
	case RANK_7:	std::cout << "7";		break;
	case RANK_8:	std::cout << "8";		break;
	case RANK_9:	std::cout << "9";		break;
	case RANK_10:	std::cout << "10";		break;
	case RANK_J:	std::cout << "J";		break;
	case RANK_Q:	std::cout << "Q";		break;
	case RANK_K:	std::cout << "K";		break;
	case RANK_A:	std::cout << "A";		break;
	}

	switch (card.suit)
	{
	case SUIT_CLOVER:	std::cout << "C";	break;
	case SUIT_DIAMOND:	std::cout << "D";	break;
	case SUIT_HEART:	std::cout << "H";	break;
	case SUIT_SPADE:	std::cout << "S";	break;
	}
}

void printDeck(const std::array<Card, 52>& deck)
{
	int i = 0;
	for (const auto& card : deck)
	{
		if (i % 4 == 0)
			std::cout << std::endl;
		printCard(card);
		std::cout << "   ";
		++i;
	}
}

void swapCards(Card& card1, Card& card2)
{
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}

void shuffleDeck(std::array<Card, 52>& deck)
{
	for (int i = 0; i < 52; ++i)
	{
		int swapIndex = getRandomNumber(0, 51);
		swapCards(deck[i], deck[swapIndex]);
	}
}

std::string getPlayerChoice()
{
	std::string choice;
	do {
		std::cout << "To take choice, type hit or stand: ";
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
		}

		std::cin.ignore(32767, '\n');
	} while (choice != "hit" && choice != "stand");

	return choice;
}

Blackjack playBlackjack(std::array<Card, 52>& deck)
{
	shuffleDeck(deck);

	//Players scores
	int playerScore = 0, dealerScore = 0;

	//First card in the deck
	const Card* cardPtr = &deck[0];

	//Dealer recieves card
	dealerScore += getCardValue(*cardPtr++);
	std::cout << "The dealer is showing: " << dealerScore << std::endl;
	dealerScore += getCardValue(*cardPtr++);

	//Player recieves two cards
	playerScore += getCardValue(*cardPtr++);
	playerScore += getCardValue(*cardPtr++);

	while (true)
	{
		std::cout << "You have: " << playerScore << std::endl;

		//If player has more than 21 points - he LOSE
		if (playerScore > 21)
			return Blackjack::RESULT_DEALER_WIN;

		//Player chooses whether to take another card
		std::string choice = getPlayerChoice();
		if (choice == "stand")
			break;
		//Player recieves another card
		playerScore += getCardValue(*cardPtr++);
	}

	//Dealer turn
	while (dealerScore < 17)
	{
		//Dealer recieves another card
		dealerScore += getCardValue(*cardPtr++);
	}

	//If dealer has more than 21 points - player WIN
	if (dealerScore > 21)
		return Blackjack::RESULT_PLAYER_WIN;

	std::cout << "Dealer has: " << dealerScore << std::endl;

	if (playerScore > dealerScore)
		return Blackjack::RESULT_PLAYER_WIN;
	else if (playerScore < dealerScore)
		return Blackjack::RESULT_DEALER_WIN;

	return Blackjack::RESULT_DRAW;
}