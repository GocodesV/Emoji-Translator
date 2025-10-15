#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Function to compare case-insensitive
int compareIgnoreCase(char *a, char *b) {
    while (*a && *b) {
        if (tolower(*a) != tolower(*b)) return 0;
        a++;
        b++;
    }
    return (*a == '\0' && *b == '\0');
}

int main() {
    // Categories: Emojis and answers
    char *animals[] = {"🐶","🐱","🦁","🐵","🐘","🦊","🐼","🐨","🐯","🐮","🐸","🦉","🐔","🐧","🐍","🦒","🦓","🦍"};
    char *animalsAns[] = {"Dog","Cat","Lion","Monkey","Elephant","Fox","Panda","Koala","Tiger","Cow","Frog","Owl","Chicken","Penguin","Snake","Giraffe","Zebra","Gorilla"};

    char *vehicles[] = {"🚗","🚲","✈️","🚂","🚢","🛵","🚁","🚤","🚑","🛺"};
    char *vehiclesAns[] = {"Car","Bicycle","Airplane","Train","Ship","Scooter","Helicopter","Speedboat","Ambulance","Auto"};

    char *shapes[] = {"⚫","🔺","⬛","⭐","⬜","⬟","⬣","🛢"};
    char *shapesAns[] = {"Circle","Triangle","Square","Star","Rectangle","Hexagon","Pentagon","Cylinder"};

    char *profession[] = {"👮","🧑‍🍳","🧑‍🎓","👩‍🏫","👨‍💻","👨‍🔧","👩‍🔬","🧑‍🎨","🧑‍✈️","🧑‍🚀","🧑‍⚖️","👩‍⚕️","🕵️‍♂️","💂"};
    char *professionAns[] = {"Police","Chef","Student","Teacher","Coder","Mechanic","Scientist","Painter","Pilot","Astronaut","Lawyer","Doctor","Detective","Guard"};

    char *sports[] = {"⚽","🏀","🎱","🏑","🏏","🏸","🏓","🥊","🥋","🛼","🎯"};
    char *sportsAns[] = {"Football","Basketball","Pool","Hockey","Cricket","Badminton","TableTennis","Boxing","Karate","Skating","Darts"};

    int category, idx, score, rounds = 3;
    char answer[50];
    char playAgain;

    srand(time(0));

    do {
        score = 0;  // reset score

        printf("\n🎮 Welcome to Guess the Emoji Game!\n");
        printf("Choose a category:\n");
        printf("1. Animals 🐾\n2. Vehicles 🚘\n3. Shapes 🔺\n4. Professions 👩‍⚕️\n5. Sports 🏀\n");
        printf("Enter your choice: ");
        scanf("%d", &category);

        if (category < 1 || category > 5) {
            printf("Invalid category!\n");
            return 0;
        }

        for (int i = 0; i < rounds; i++) {
            if (category == 1) {
                idx = rand() % 18;
                printf("\nRound %d: What is this? %s\n", i+1, animals[idx]);
                printf("Type your answer: ");
                scanf(" %[^\n]", answer);

                if (compareIgnoreCase(answer, animalsAns[idx])) {
                    printf("✅ Correct!\n");
                    score++;
                } else {
                    printf("❌ Wrong! Answer: %s\n", animalsAns[idx]);
                }
            } 
            else if (category == 2) {
                idx = rand() % 10;
                printf("\nRound %d: What is this? %s\n", i+1, vehicles[idx]);
                printf("Type your answer: ");
                scanf(" %[^\n]", answer);

                if (compareIgnoreCase(answer, vehiclesAns[idx])) {
                    printf("✅ Correct!\n");
                    score++;
                } else {
                    printf("❌ Wrong! Answer: %s\n", vehiclesAns[idx]);
                }
            } 
            else if (category == 3) {
                idx = rand() % 8;
                printf("\nRound %d: What is this? %s\n", i+1, shapes[idx]);
                printf("Type your answer: ");
                scanf(" %[^\n]", answer);

                if (compareIgnoreCase(answer, shapesAns[idx])) {
                    printf("✅ Correct!\n");
                    score++;
                } else {
                    printf("❌ Wrong! Answer: %s\n", shapesAns[idx]);
                }
            }
            else if (category == 4) {
                idx = rand() % 14;
                printf("\nRound %d: What is this? %s\n", i+1, profession[idx]);
                printf("Type your answer: ");
                scanf(" %[^\n]", answer);

                if (compareIgnoreCase(answer, professionAns[idx])) {
                    printf("✅ Correct!\n");
                    score++;
                } else {
                    printf("❌ Wrong! Answer: %s\n", professionAns[idx]);
                }
            }
            else if (category == 5) {
                idx = rand() % 11;
                printf("\nRound %d: What is this? %s\n", i+1, sports[idx]);
                printf("Type your answer: ");
                scanf(" %[^\n]", answer);

                if (compareIgnoreCase(answer, sportsAns[idx])) {
                    printf("✅ Correct!\n");
                    score++;
                } else {
                    printf("❌ Wrong! Answer: %s\n", sportsAns[idx]);
                }
            }
        }

        printf("\n🏆 Game Over! Your Score: %d/%d\n", score, rounds);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing! 👋\n");
    return 0;
}
