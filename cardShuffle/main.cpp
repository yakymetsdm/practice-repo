// cardShuffle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <ctime>

enum CardSuit
{
	SUIT_CLOVER,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS
};

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

struct Card
{
	CardRank rank;
	CardSuit suit;
};

int getRandomNumber(int min, int max);
void printCard(const Card& card);
void printDeck(const std::array<Card, 52>& cards);
void swapCards(Card& card1, Card& card2);
void shuffleDeck(std::array<Card, 52>& deck);

int main()
{
	srand(static_cast<unsigned>(time(0)));
	rand();

	const int numCards = 52;
	std::array<Card, numCards> deck;

	int indexCard = 0;
	for (int rank = 0; rank < MAX_RANKS; ++rank)
	{
		for (int suit = 0; suit < MAX_SUITS; ++suit)
		{
			deck[indexCard].rank = static_cast<CardRank>(rank);
			deck[indexCard].suit = static_cast<CardSuit>(suit);
			++indexCard;
		}
	}

	printDeck(deck);

	shuffleDeck(deck);

	std::cout << std::endl;

	printDeck(deck);

	return 0;
}
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>((rand() * fraction * (static_cast<double>(max) - min)) + 1 + min);
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
