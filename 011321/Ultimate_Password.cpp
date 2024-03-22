#include <bits/stdc++.h>
#include <windows.h>  // for _sleep() cuz I want the computer to guess like real
#define ouo ios_base::sync_with_stdio(false), cin.tie(0)
#define ll long long
#define db double
using namespace std;

// const number can be reset
int MAX_NUM = 1000;
int MIN_NUM = 0;

void welcomeToPlay();
void init();
void playGame();
int getRandomNumber(int minNum, int maxNum);
void showRange();
void setRange();
void foolProofing();
int option = -1;
int maxNumber = MAX_NUM, minNumber = MIN_NUM;

int main() {
    srand(time(NULL));
    while (option != 0) {
        welcomeToPlay();
        init();
        cin >> option;
        switch (option) {
            case 1:
                playGame();
                break;
            case 2:
                setRange();
                break;
            case 0:
                foolProofing();
            case -1:
                break;
            default:
                cout << "U type wrong number";
                break;
        }
    }
}

void welcomeToPlay() {
    system("cls");
    cout << "#####################################\n"
         << "#                                   #\n"
         << "# Welcome to play Ultimate Password #\n"
         << "# [1] Play                          #\n"
         << "# [2] Set                           #\n"
         << "# --------------------------------- #\n"
         << "# [0] Exit                          #\n"
         << "#                                   #\n"
         << "#####################################\n";
}

void init() {
    maxNumber = MAX_NUM, minNumber = MIN_NUM;
    option = -1;
}

void playGame() {
    int ans = getRandomNumber(MIN_NUM, MAX_NUM);
    int guessNumber;
    int guesser = 0;  // player is 0, computer is 1
    system("cls");
    cout << "#####################################\n"
         << "#                                   #\n"
         << "# Who goes first?                   #\n"
         << "# [1] Player                        #\n"
         << "# [2] Computer                      #\n"
         << "# --------------------------------- #\n"
         << "# [0] Back                          #\n"
         << "#                                   #\n"
         << "#####################################\n";
    cin >> guesser;
    if (guesser == 0) return;  // back
    --guesser;
    system("cls");

    // guessing
    while (true) {
        showRange();
        // computer
        if (guesser) {
            guessNumber = getRandomNumber(minNumber, maxNumber);
            cout << "It's The Computer's Turn: ";
            _sleep(1000);
            cout << guessNumber << "\n";
        }
        // player
        else {
            cout << "It's Your Turn: ";
            do {
                cin >> guessNumber;
                if (guessNumber <= minNumber || guessNumber >= maxNumber) {
                    cout << "It's out of range. "
                         << "Please retry: ";
                }
            } while (guessNumber <= minNumber || guessNumber >= maxNumber);
        }

        if (guessNumber == ans) {
            cout << "\nBOOM! " << (guesser ? "You win" : "You lose") << "\n\n";
            system("pause");
            break;
        } else if (guessNumber > ans) {
            maxNumber = guessNumber;
        } else {
            minNumber = guessNumber;
        }

        guesser ^= 1;
    }
}

int getRandomNumber(int minNum, int maxNum) {
    return minNum + (rand() % (maxNum - minNum - 1)) + 1;
}

void showRange() {
    cout << "Range: " << minNumber << " to " << maxNumber << "\n";
}

void setRange() {
    while (true) {
        int tempOption;
        int tempNumber;

        system("cls");
        cout << "#####################################\n"
             << "#                                   #\n"
             << "# Which one do u wanna set          #\n"
             << "# [1] Min number                    #\n"
             << "# [2] Max number                    #\n"
             << "# --------------------------------- #\n"
             << "# [0] Back                          #\n"
             << "#                                   #\n"
             << "#####################################\n";
        cout << "Current: \n"
             << "MIN_NUM = " << MIN_NUM << "\n"
             << "MAX_NUM = " << MAX_NUM << "\n";

        cin >> tempOption;
        if (tempOption == 1) {
            cout << "Please set the min number: ";
            do {
                cin >> tempNumber;
                if (tempNumber >= MAX_NUM) {
                    cout << "It's out of range. "
                         << "Please retry: ";
                }
            } while (tempNumber >= MAX_NUM);
            MIN_NUM = tempNumber;
        } else if (tempOption == 2) {
            cout << "Please set the max number: ";
            do {
                cin >> tempNumber;
                if (tempNumber <= MIN_NUM) {
                    cout << "It's out of range. "
                         << "Please retry: ";
                }
            } while (tempNumber <= MIN_NUM);
            MAX_NUM = tempNumber;
        } else if (tempOption == 0) {
            return;
        } else {
            cout << "U type wrong number\n";
            continue;
        }
    }
}

void foolProofing() {
    while (true) {
        system("cls");
        cout << "#####################################\n"
             << "#                                   #\n"
             << "# Sure to exit?                     #\n"
             << "# [1] Yes, I'm stupid.              #\n"
             << "# [2] NO, I'm smart.                #\n"
             << "#                                   #\n"
             << "#####################################\n";
        int tempOption;
        cin >> tempOption;
        if (tempOption == 1) {
            system("cls");
            cout << "=_= Bye, idiot.";
            return;
        } else if (tempOption == 2) {
            option = -1;
            return;
        }
    }
}
