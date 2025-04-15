#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int getRandomTarget() {
    return rand() % 30 + 1;
}

int getBattingOutcome(int choice) {
    switch (choice) {
        case 1: return rand() % 3; // Defensive: 0–2 runs
        case 2: return rand() % 5; // Normal: 0–4 runs
        case 3: {
            double chance = static_cast<double>(rand()) / RAND_MAX;
            if (chance < 0.4) return -1; // Out
            int options[3] = {0, 4, 6};
            return options[rand() % 3]; // Power shot: 0/4/6
        }
        default: return 0;
    }
}

void playAsBatsman() {
    int target = getRandomTarget();
    int runs = 0;

    cout << "\n To chase: " << target << " runs in 6 balls!\n";

    for (int ball = 1; ball <= 6; ++ball) {
        cout << "\nBall " << ball << " - Choose your shot:\n";
        cout << "1. Defensive Shot (0-2 runs)\n";
        cout << "2. Normal Shot (0-4 runs)\n";
        cout << "3. Power Shot (0/4/6, risk of getting out)\n";
        cout << "Your choice: ";
        int choice;
        cin >> choice;

        string deliveries[5] = {"Yorker", "Bouncer", "Full toss", "Good length", "Short ball"};
        string randomBall = deliveries[rand() % 5];
        cout << "Computer bowls a " << randomBall << "...\n";

        int run = getBattingOutcome(choice);

        if (run == -1) {
            cout << "Oh no! You're OUT! ❌\n";
            break;
        } else {
            runs += run;
            cout << "You scored " << run << " run(s). Total: " << runs << endl;

            if (runs >= target) {
                cout << "🎉 You chased down the target! You win!\n";
                return;
            }
        }
    }

    if (runs < target) {
        cout << "\n💔 You couldn't chase the target. You lose.\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed randomness

    cout << "Welcome to the Final Over Cricket Game!\n";
    cout << "You will be batting to chase a target in the final over!\n";
    playAsBatsman();

    return 0;
}
