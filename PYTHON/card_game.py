import random

# Card class
class Card:
    suits = ['Hearts', 'Diamonds', 'Clubs', 'Spades']
    values = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']

    def __init__(self, suit, value):
        self.suit = suit
        self.value = value

    def __str__(self):
        """Return the string representation of a card."""
        return f"{self.value} of {self.suit}"

    def __eq__(self, other):
        """Check if two cards are equal in value."""
        return self.values.index(self.value) == other.values.index(other.value)

    def __lt__(self, other):
        """Compare the value of two cards."""
        return self.values.index(self.value) < other.values.index(other.value)

# Deck class
class Deck:
    def __init__(self):
        """Initialize the deck with 52 cards."""
        self.cards = [Card(suit, value) for suit in Card.suits for value in Card.values]
        self.shuffle()

    def shuffle(self):
        """Shuffle the deck."""
        random.shuffle(self.cards)

    def draw(self):
        """Draw a card from the deck."""
        if self.cards:
            return self.cards.pop()
        return None

# Hand class
class Hand:
    def __init__(self):
        """Initialize a hand with an empty list of cards."""
        self.cards = []

    def add_card(self, card):
        """Add a card to the hand."""
        self.cards.append(card)

    def calculate_score(self):
        """Calculate the score of the hand based on card values."""
        score = 0
        for card in self.cards:
            if card.value in ['J', 'Q', 'K']:
                score += 10
            elif card.value == 'A':
                score += 11  # We'll simplify the ace as always 11
            else:
                score += int(card.value)
        return score

    def __str__(self):
        """Return string representation of the hand."""
        return ', '.join(str(card) for card in self.cards)

# Player class
class Player:
    def __init__(self, name):
        self.name = name
        self.hand = Hand()

    def draw(self, deck):
        """Draw a card from the deck and add it to the player's hand."""
        card = deck.draw()
        if card:
            self.hand.add_card(card)
            return card
        return None

    def calculate_score(self):
        """Calculate the player's total score based on their hand."""
        return self.hand.calculate_score()

    def __str__(self):
        """Return the player's name and hand."""
        return f"{self.name} has {self.hand}"

# Game class
class Game:
    def __init__(self, players):
        self.players = [Player(name) for name in players]
        self.deck = Deck()
        self.round = 0

    def start_game(self):
        """Start the card game."""
        print("Game started!")
        self.deck.shuffle()

        # Deal 2 cards to each player
        for _ in range(2):
            for player in self.players:
                card = player.draw(self.deck)
                print(f"{player.name} draws {card}")

        # Show hands
        for player in self.players:
            print(f"{player.name}'s hand: {player.hand}")

    def play_round(self):
        """Play a single round of the card game."""
        print("\nPlaying a round...\n")
        for player in self.players:
            card = player.draw(self.deck)
            print(f"{player.name} draws {card}")

        # Determine the winner based on scores
        scores = [(player.name, player.calculate_score()) for player in self.players]
        winner = max(scores, key=lambda x: x[1])
        print(f"{winner[0]} wins the round with a score of {winner[1]}!")

# game setup
if __name__ == "__main__":
    player_names = ["Alice", "Bob"]
    game = Game(player_names)
    game.start_game()
    game.play_round()
