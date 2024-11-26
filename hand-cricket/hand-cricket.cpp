#include <iostream>
#include <random>
#include <utility>

int user_score = 0;
int computer_score = 0;


int get_random() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1,6);

    int random_number = dist(gen);
    
    return random_number;
}

std::pair<int, int> get_values() {
    // return user  value, computer value
    int user, computer;
    std::cout << "You: ";
    std::cin >> user;

    computer = get_random();
    std::cout << "Computer: " << computer << std::endl;

    return std::make_pair(user, computer);
}

bool toss(int a) {
    std::pair<int, int> input = get_values();

    if ((input.first + input.second)%2 != a-1) // a=1:odd, 2:even so mod should not be equal to a-1
        return true;
    else
        return false;
}

void bat(){
    std::pair<int, int> input = get_values();
    int user = input.first;
    int computer = input.second;

    if (user == computer)
        return;

    user_score += user;
    std::cout << "Your score: " << user_score << std::endl;
    bat();
}

void bowl(){
    std::pair<int, int> input = get_values();
    int user = input.first;
    int computer = input.second;

    if (user == computer)
        return;

    computer_score += computer;
    std::cout << "Computer score: " << computer_score << std::endl;
    bowl();
}

int main() {
    int toss_choice, choice;
    std::cout << "1. Odd" << std::endl;
    std::cout << "2. Even" << std::endl;
    std::cout << "(1 or 2): ";
    std::cin >> toss_choice;

    if (toss(toss_choice)) {
        std::cout << "1. Bat" << std::endl;
        std::cout << "2. Bowl" << std::endl;
        std::cout << "(1 or 2): ";
        std::cin >> choice;
    } else {
        choice = get_random() % 2 + 1;
    }

    if (choice == 1) { // batting
        std::cout << "You are batting" << std::endl;
        bat();
        std::cout << "Out!" << std::endl;
        std::cout << "Computer target: " << user_score+1 << std::endl;
        std::cout << "You are bowling" << std::endl;
        bowl();
    } else{ // bowling
        std::cout << "You are bowling" << std::endl;
        bowl();
        std::cout << "Out!" << std::endl;
        std::cout << "Your target: " << computer_score+1 << std::endl;
        std::cout << "You are batting" << std::endl;
        bat();
    }

    if (user_score == computer_score)
        std::cout << "It's a draw";
    else if (user_score > computer_score)
        std::cout << "You won by " << user_score - computer_score << " runs";
    else if (user_score < computer_score)
        std::cout << "Computer won by " << computer_score - user_score  << " runs";

    return 0;
}
