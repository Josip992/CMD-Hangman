#include <iostream>
#include <string>
#include <time.h>  
#include <vector>
#include <iomanip>
#include <cctype>
#include "hangman.hpp"

using namespace std;

void menu() {

    Menu M;
    M.nacrtajMenu();
    cout << "Pravila igre: " << endl
        << "- Imate 8 pokusaja da pogodite naziv zivotinje!" << endl
        << "- Ponavljanje pogodenih slova ne racuna se kao pokusaj!" << endl
        << "- Kod pogadanja nema dijakritickih znakova!" << endl
        << "- Unosenje brojeva nije dozvoljeno, a u slucaju da ga unesete igra se prekida!" << endl
        << "- Sudbina Stickmana ovisi o vama!!" << endl;
    system("pause");
    system("cls");
}

void responsePrint(vector<char> responseVec) {

    vector<char>::iterator it;
    cout << "Slova koja ste do sad upisali su: ";
    for (it = responseVec.begin(); it != responseVec.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
}
void won(const string display, const string word, const int misses, Menu M) {
    cout << "\t! " << display << " !" << endl;
    system("pause");
    system("cls");
    cout << endl;
    cout << "******************" << endl;
    cout << "*                *" << endl;
    cout << "* Pobijedili ste *" << endl;
    cout << "*                *" << endl;
    cout << "******************" << endl;
    M.nacrtajHangMana(9);
    cout << "\nIspravno ste pogodili rijec: " << word << endl;
    cout << "Broj pogresaka: " << misses << endl;
    cout << "Hvala sto ste igrali!" << endl;
}
void lost(const string word) {
    system("pause");
    system("cls");
    cout << endl;
    cout << "******************" << endl;
    cout << "*                *" << endl;
    cout << "*  Izgubili ste  *" << endl;
    cout << "*                *" << endl;
    cout << "******************" << endl;
    cout << "\t   (/)" << endl;
    cout << "\t   (/)" << endl;
    cout << "\t   (/)" << endl;
    cout << "\t   (/)" << endl;
    cout << "\t   (/)" << endl;
    cout << "\t   (/)" << endl;
    cout << "\t   (/)" << endl;
    cout << "\t  (/)(/)" << endl;
    cout << "\t (/)  (/)" << endl;
    cout << "\t(/)    (/)" << endl;
    cout << "\t(/)    (/)" << endl;
    cout << "\t(/)    (/)" << endl;
    cout << "\t(/)    (/)" << endl;
    cout << "\t (/)  (/)" << endl;
    cout << "\t  (/)(/)" << endl;
    cout << "\t    `""`" << endl;
    cout << "Rijec je bila: " << word << endl;
    cout << "Hvala sto ste igrali!" << endl;
}
void repeatLetter(const char response, bool& duplicate) {
    cout << "Vec ste pogodili slovo" << " " << response << endl;
    duplicate = true;
}
void hit(const int i, string& display, const string word, int& exposed, bool& goodGuess) {
    display[i] = word[i];
    exposed++;
    goodGuess = true;
}
void miss(int& misses, int& i, const char response, Menu M) {
    misses++;
    M.nacrtajHangMana(misses);
    i++;
    cout << response << " " << "nije slovo u nazivu zivotinje!" << endl;
}
int main()
{
    Menu M;
    srand(time(NULL));
    int misses = 0;
    int exposed = 0;
    int i = 0;
    vector <char> responseVec;
    vector <string> wordList = { "ptica","bubamara","pas","komarac","pauk","koala","orangutan",
                                 "slon","dupin","konj","lemur","noj","tigar","puma","leopard",
                                 "gepard","lav","bik","divokoza","orao","sokol","galeb","babun" };
    string word = wordList[rand() % wordList.size()];
    string display = word;

    for (int i = 0; i < display.length(); i++)
        display[i] = '*';

    menu();

    while (i < 8) {

        char response;
        bool goodGuess = false;
        bool duplicate = false;

        cout << "Promasaji: " << misses << " --> ";
        cout << "Unesite slovo iz imena zivotinje: ";
        cout << display << " : ";
        cin >> response;
        if (isdigit(response)) {
            cout << "Unjeli ste broj, a unosenje broja prekida igru!" << endl;
            cout << endl;
            break;
        }
        if (isalpha(response)) {
            responseVec.push_back(response);
        }
        responsePrint(responseVec);

        for (int i = 0; i < word.length(); i++) {
            if (response == word[i])
                if (display[i] == word[i])
                {
                    repeatLetter(response, duplicate);
                    break;
                }
                else
                {
                    hit(i, display, word, exposed, goodGuess);
                }
        }
        if (duplicate)
            continue;
        if (!goodGuess)
        {
            miss(misses, i, response, M);
        }
        if (display == word) {
            won(display, word, misses, M);
            break;
        }

    }
    if (misses == 8) {
        lost(word);
        system("pause");
        system("cls");
    }

    return 0;
}
