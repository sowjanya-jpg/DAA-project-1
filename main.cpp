#include <iostream>
#include <vector>
using namespace std;

class HangmanGame {
private:
    string codeword;
    string answer;
    int misses;
    vector<char> incorrect;

public:
    // Constructor to initialize game variables
    HangmanGame(string word)
        : codeword(word), answer(string(word.length(), '_')), misses(0) {}

    // Member functions
    void greet() {
        cout << "=====================\n";
        cout << "Hangman: The Game\n";
        cout << "=====================\n";
        cout << "Instructions: Save your friend from being hanged by guessing the letters in the codeword.\n";
    }

    void display_misses() const {
        // Draw the hangman based on the number of misses
        if (misses == 0) {
            cout << "  +---+ \n";
            cout << "  |   | \n";
            cout << "      | \n";
            cout << "      | \n";
            cout << "      | \n";
            cout << "      | \n";
            cout << " ========= \n";
        } else if (misses == 1) {
            cout << "  +---+ \n";
            cout << "  |   | \n";
            cout << "  O   | \n";
            cout << "      | \n";
            cout << "      | \n";
            cout << "      | \n";
            cout << " ========= \n";
        } else if (misses == 2) {
            cout << "  +---+ \n";
            cout << "  |   | \n";
            cout << "  O   | \n";
            cout << "  |   | \n";
            cout << "      | \n";
            cout << "      | \n";
            cout << " ========= \n";
        } else if (misses == 3) {
            cout << "  +---+ \n";
            cout << "  |   | \n";
            cout << "  O   | \n";
            cout << " /|   | \n";
            cout << "      | \n";
            cout << "      | \n";
            cout << " ========= \n";
        } else if (misses == 4) {
            cout << "  +---+ \n";
            cout << "  |   | \n";
            cout << "  O   | \n";
            cout << " /|\\  | \n";
            cout << "      | \n";
            cout << "      | \n";
            cout << " ========= \n";
        } else if (misses == 5) {
            cout << "  +---+ \n";
            cout << "  |   | \n";
            cout << "  O   | \n";
            cout << " /|\\  | \n";
            cout << " /    | \n";
            cout << "      | \n";
            cout << " ========= \n";
        } else if (misses == 6) {
            cout << "  +---+ \n";
            cout << "  |   | \n";
            cout << "  O   | \n";
            cout << " /|\\  | \n";
            cout << " / \\  | \n";
            cout << "      | \n";
            cout << " ========= \n";
        }
    }

    void display_status() const {
        cout << "Incorrect guesses: ";
        for (size_t i = 0; i < incorrect.size(); ++i) {
            cout << incorrect[i] << " ";
        }
        cout << endl;

        cout << "Current word: ";
        for (size_t i = 0; i < answer.size(); ++i) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }

    void play_turn() {
        char letter;
        bool guess = false;

        cout << "\n\nPlease enter your guess: ";
        cin >> letter;

        // Check if the guessed letter is in the codeword
        for (size_t i = 0; i < codeword.length(); ++i) {
            if (letter == codeword[i]) {
                answer[i] = letter;
                guess = true;
            }
        }

        if (guess) {
            cout << "\nCorrect!\n";
        } else {
            cout << "\nIncorrect! Another portion of the person has been drawn.\n";
            incorrect.push_back(letter);
            misses++;
        }
    }

    void end_game() const {
        if (answer == codeword) {
            cout << "Hooray! You saved the person from being hanged and earned a medal of honor!\n";
            cout << "Congratulations!\n";
        } else {
            cout << "Oh no! The man is hanged!\n";
        }
    }

    bool is_game_over() const {
        return (answer == codeword || misses >= 7);
    }

    void run() {
        greet();

        // Run the game loop until the game is over
        while (!is_game_over()) {
            display_misses();
            display_status();
            play_turn();
        }

        end_game();
    }
};

int main() {
    HangmanGame game("srm");
    game.run();
    return 0;
}

