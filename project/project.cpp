#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <time.h> 
//#include <>
using namespace std;

struct questions {
    string oneAnswerQuestions[2] = { "Who is current president of Poland?\n", "What color is your blood?\n" };
    string oneAnswerAnswers[2][2] = { {"A) Adam Mickiewicz\t B) Andrzej Duda\t C) Nikola Tesla\t D) Mateush Miotk\n", "A) Red\t B) Blue\t C) Violet\t D) Rainbowish\n"}, {"B", "A"} };

    string fewAnswerQuestions[2] = { "Name the oceans?", "What type the blood can be?"};
    string fewAnswerAnswers[2][4] = { {"A) Pacific\t B) Framklinburgen\t C) Indian\t D) Swift\n", "A) A+\t B) H--\t C) AB+\t D) CSS-\n"}, {"AC", "CA", "AC", "CA"} };

    string trueFalseQuestions[2] = { "Is Andrzej Duda current president of Poland ?", "Some people's blood could be different color?" };
    string trueFalseAnswers[2] = { "T", "T" };

    string shortQuestions[2] = { "Who is current president of Poland?", "What color is your blood?" };
    string shortAnswers[2] = { "Andrzej Duda", "Red" };

    string listQuestions[2] = { "Who invented Radio?\n", "Who was the first woman to gain the Noble Prize?\n"};
    string listAnswers[2][2] = { {"Andrzej Duda, Tomas Eddison, Marie Curie, Gugliemo Marconi, Alexander Noble, Albert Einstein, Nicola Tesla" },{"Gugliemo Marconi ", "Marie Curie"}};

};

void chooseQuiz(int &result);

void start(string &userName, int& result) {
    cout << "*******************************************\n"<<"*             Quiz                        *\n" << "*******************************************\n";
    cout << "Greetings new player, what should I call you?\n";
    cin >> userName;
    cout << "\nSo, " << userName << "! Let's start our little game! Please, choose type of the Quiz!\n";

}

void oneAnswerQuiz(int& result, int i=0) {
    questions OA;
    string answer;
    cout << OA.oneAnswerQuestions[i] << " ";
    cout << OA.oneAnswerAnswers[0][i] << " ";
    cin >> answer;
    if (answer == OA.oneAnswerAnswers[1][i]) {
        cout << "Correct! +1 point!" << endl;;
        result++;
    }
    else {
        cout << "Incorrect, the real answer is " << OA.oneAnswerAnswers[1][i] << "!\n";
    }

    return i < 1 ? oneAnswerQuiz(result, i + 1) : chooseQuiz(result);

}

void fewAnswerQuiz(int& result, int i=0) {
    questions FA;
    string answer;
    cout << FA.fewAnswerQuestions[i] << " ";
    cout << FA.fewAnswerAnswers[0][i] << " ";
    cin >> answer;
    if (answer == FA.fewAnswerAnswers[1][2*i] || answer == FA.fewAnswerAnswers[1][2 * i+1]) {
        cout << "Correct! +1 point!" << endl;;
        result++;
    }
    else {
        cout << "Incorrect, the real answer is " << FA.fewAnswerAnswers[1][2*i] << "!\n";
    }

    return i < 1 ? fewAnswerQuiz(result, i + 1) : chooseQuiz(result);
}

void trueFalseQuiz(int& result, int i = 0) {
    questions TF;
    string answer;
    cout << TF.trueFalseQuestions[i] << " ";
    cin >> answer;
    if (answer == TF.trueFalseAnswers[i]) {
        cout << "Correct! +1 point!" << endl;;
        result++;
    }
    else {
        cout << "Incorrect, the real answer is " << TF.trueFalseAnswers[i] << "!\n";
    }

    return i < 1 ? trueFalseQuiz(result, i + 1) : chooseQuiz(result);
}

void shortAnswerQuiz(int& result, int i=0) {
    questions Short;
    string answer;
    cout << Short.shortQuestions[i]<< " ";
    cin >> answer;
    if (answer == Short.shortAnswers[i]) {
        cout << "Correct! +1 point!" << endl;;
        result++;
    }
    else {
        cout << "Incorrect, the real answer is " << Short.shortAnswers[i] << "!\n";
    }

    return i < 1 ? shortAnswerQuiz(result, i + 1) : chooseQuiz(result);
}

void listAnswerQuiz(int& result, int i=0) {
    questions List;
    string answer;
    cout << List.listQuestions[i] << endl;
    cout << List.listAnswers[0][0] << endl;
    cin >> answer;
    if (answer == List.listAnswers[1][i]) {
        cout << "Correct! +1 point!" << endl;;
        result++;
    }
    else {
        cout << "Incorrect, the real answer is " << List.listAnswers[1][i] << "!\n";
    }

    return i < 1 ? listAnswerQuiz(result, i + 1) : chooseQuiz(result);
}

void wordAnswerQuiz(int& result, int i = 0) {
    string word;
    string guess;
    srand(time(NULL));
    cout << "\nEnter the word: \n";
    cin >> word;

    int length = word.length();
    string ukryte_slowo = word;
    int random = rand() % length;
        ukryte_slowo[random] = '_';
    std::cout << "Secret letter: " << ukryte_slowo << endl;
    cout << "What it should be? \n";
    std::cin >> guess;
        if (word[random] == guess[0])
        {
            ukryte_slowo[random] = guess[0];
            cout << "Correct! +1 point!" << endl;
            result++;
        }
        else {
            cout << "Inorrect! The answer should be " << word[random] << endl;
        }
    return i<2? wordAnswerQuiz(result, i + 1) : chooseQuiz(result);
}

void chooseQuiz(int &result) {
    cout << "Your current score is " << result << "!\n";
    cout << "\n 1) With one Answer\n 2) With several answers\n 3) True/False\n 4) Short answer\n 5) Choose from the list\n 6) Finish the word\n";
    for (int key = 0; key != 'q'; key = _kbhit() ? _getch() : 0) {
        switch (key) {
        case '1':
            oneAnswerQuiz(result);
            break;
        case '2':
            fewAnswerQuiz(result);
            break;
        case '3':
            trueFalseQuiz(result);
            break;
        case '4':
            shortAnswerQuiz(result);
            break;
        case '5':
            listAnswerQuiz(result);
            break;
        case '6':
            wordAnswerQuiz(result);
            break;
    }
    }
}

int main(void)
{
    string userName;
    int score=0;

    start(userName, score);
    chooseQuiz(score);

    return 0;
}
