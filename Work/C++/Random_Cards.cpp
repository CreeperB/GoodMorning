#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Define the suits and ranks
enum Suit { Hearts, Diamonds, Clubs, Spades };
std::string suits[] = {"♥️", "♦️", "♣️", "♠️"};
enum Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
std::string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};

// Define a Card structure
struct Card {
    Suit suit;
    Rank rank;
};

Card create_card(int suit, int rank) {
    Card tmp = {static_cast<Suit>(suit), static_cast<Rank>(rank)};
    return tmp;
}

// Function to initialize a standard deck of cards
std::vector<Card> initializeDeck() {
    std::vector<Card> deck;
    for (int suit = Hearts; suit <= Spades; ++suit) {
        for (int rank = Ace; rank <= King; ++rank) {
            deck.push_back(create_card(suit, rank));
        }
    }
    return deck;
}

// Function to shuffle a deck of cards
void shuffleDeck(std::vector<Card>& deck) {
    for (int i = 0; i < 52; i++) {
        int rng = std::rand() % 52;
        Card tmp = deck[i];
        deck[i] = deck[rng];
        deck[rng] = tmp;
    }
}

int main() {
    // Initialize the deck
    std::vector<Card> deck = initializeDeck();

    // Shuffle the deck
    shuffleDeck(deck);

    // Deal all cards to the four players
    for (int player = 1; player <= 4; ++player) {
        std::cout << "Player " << player << " cards: ";
        for (int i = 0; i < 13; ++i) {
            Card currentCard = deck.back();
            deck.pop_back();
            std::cout << suits[static_cast<int>(currentCard.suit)] << ranks[static_cast<int>(currentCard.rank)];

            // Add a comma if it's not the last card in the player's hand
            if (i < 12) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}