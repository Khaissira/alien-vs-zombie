// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT6L
// Names: DIVYASHREE A/P SELVANYGAM | NOR KHAISSIRA BINTI KHAIRUDDIN | NABILA NADIA BINTI MD ZAID
// IDs: 1221303777 | 1221304058 | 1221303636
// Emails: 1221303777@student.mmu.edu.my | 1221304058@student.mmu.edu.my | 1221303636@student.mmu.edu.my
// Phones: 010-2342132 | 012-3342105 | 019-9120610
// *********************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 5;

struct character {
    char symbol;
    int row;
    int col;
    int health;
};

character *player_char, alien, zombie;

void init_characters() {
    alien = {'A', rand() % BOARD_SIZE, rand() % BOARD_SIZE, 100};
    zombie = {'Z', rand() % BOARD_SIZE, rand() % BOARD_SIZE, 100};
    player_char = &alien;
}

void print_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row == player_char->row && col == player_char->col) {
                cout << player_char->symbol << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

void move_character(character *player_char, int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        cout << "Invalid move." << endl;
    } else {
        player_char->row = row;
        player_char->col = col;
    }
}

void alien_move() {
    int row = player_char->row + rand() % 3 - 1;
    int col = player_char->col + rand() % 3 - 1;
    move_character(&alien, row, col);
}

void alien_attack() {
    if (rand() % 2 == 0) {
        zombie.health -= 10;
    }
}

void zombie_move() {
    int row = player_char->row + rand() % 3 - 1;
    int col = player_char->col + rand() % 3 - 1;
    move_character(&zombie, row, col);
}

void zombie_attack() {
    if (rand() % 2 == 0) {
        alien.health -= 10;
    }
}

void run_game() {
    cout << "Welcome to the game!" << endl;
    cout << "You are the alien. Try to defeat the zombie." << endl;
    init_characters();

    while (alien.health > 0 && zombie.health > 0) {
        print_board();

        int player = (player_char == &alien) ? 1 : 2;
        cout << "Player " << player << "'s turn:" << endl;

        if (player_char == &alien) {
            alien_move();
            alien_attack();
        } else {
            zombie_move();
            zombie_attack();
        }

        cout << "Alien health: " << alien.health << endl;
        cout << "Zombie health: " << zombie.health << endl;
    }

    if (alien.health <= 0) {
        cout << "Zombie wins!" << endl;
    } else {
        cout << "Alien wins!" << endl;
    }
}

int main() {
    srand(time(NULL));
    run_game();
    return 0;
}