#include <iostream>
#include <string>
#include <time.h>  
#include <vector>
#include <iomanip>
#include <cctype>
#include "hangman.hpp"
using namespace std;

void Menu::nacrtajMenu()
{
        cout << setw(25) << "HANGMAN!" << endl << endl
            << " ___________.._______" << endl
            << "| .__________))______|" << endl
            << "| | / /      ||" << endl
            << "| |/ /       ||" << endl
            << "| | /        ||.-\'\'." << endl
            << "| |/         |/  _  \\" << endl
            << "| |          ||  `/,|" << endl
            << "| |          (\\`_.' " << endl
            << "| |         .-`--'." << endl
            << "| |        /Y . . Y\\\\" << endl
            << "| |       // |   |  \\\\" << endl
            << "| |      //  | . |   \\\\" << endl
            << "| |     ')   |   |    (`" << endl
            << "| |          || ||" << endl
            << "| |          || ||" << endl
            << "| |          || ||" << endl
            << "| |          || ||" << endl
            << "| |         / | | \\" << endl
            << "__________| `-  `-  |_____|" << endl
            << "| |       \\ \         | |" << endl
            << "| |        \\ \        | |" << endl
            << ": :         \\ \       : :" << endl;
    
}
void Menu::nacrtajHangMana(const int greske) {
    switch (greske) {
    case 0: cout << "_________" << endl
        << " |     | " << endl
        << " | " << endl
        << " | " << endl
        << " | " << endl
        << " | " << endl
        << "``````````" << endl;
        break;
    case 1: cout << "_________" << endl
        << " |     | " << endl
        << " |   (   )" << endl
        << " | " << endl
        << " | " << endl
        << " | " << endl
        << "``````````" << endl;
        break;
    case 2: cout << "_________" << endl
        << " |     | " << endl
        << " |   (o_o)" << endl
        << " |     " << endl
        << " |     " << endl
        << " | " << endl
        << "``````````" << endl;
        break;
    case 3: cout << "_________" << endl
        << " |     | " << endl
        << " |   (o_o)" << endl
        << " |     | " << endl
        << " |     |" << endl
        << " | " << endl
        << "``````````" << endl;
        break;
    case 4: cout << "_________" << endl
        << " |     | " << endl
        << " |   (o_o)" << endl
        << " |    _| " << endl
        << " |     |" << endl
        << " | " << endl
        << "``````````" << endl;
        break;
    case 5: cout << "_________" << endl
        << " |     | " << endl
        << " |   (o_o)" << endl
        << " |    _|_ " << endl
        << " |     |" << endl
        << " |     " << endl
        << "``````````" << endl;
        break;
    case 6: cout << "_________" << endl
        << " |     | " << endl
        << " |   (o_o)" << endl
        << " |    _|_ " << endl
        << " |     |" << endl
        << " |    / " << endl
        << "``````````" << endl;
        break;
    case 7: cout << "_________" << endl
        << " |     | " << endl
        << " |   (O_O)" << endl
        << " |    \\|/ " << endl
        << " |     |" << endl
        << " |    / \\" << endl
        << "``````````" << endl;
        break;
    case 8: cout << "_________" << endl
        << " |     | " << endl
        << " |   (x_x)" << endl
        << " |     | " << endl
        << " |    /|\\" << endl
        << " |    / \\" << endl
        << " ````\\" << endl
        << "      \\" << endl;
        break;
    case 9: cout << endl
        << "    (^_^)" << endl
        << "     \\|/ " << endl
        << "      |" << endl
        << "     / \\" << endl;
        break;
    }
    return;
}