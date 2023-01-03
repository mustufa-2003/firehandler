#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
const int i_max = 6; // max row size
const int j_max = 7; // max column size
char Board[i_max][j_max];
// ERROR screen
void error()
{

cout << "  __ __  __   __  ___    _\n ";
cout << "|  _|  _ \\|  _ \\ / _ \\|  __ \\  | |\n";
cout << " | |_  | |) | |) | |  | | |_) | | |\n";
cout << " |  __| |  _  /|  _  /| |  | |  _  /  | |\n";
cout << " | |_| | \\ \\| | \\ \\| || | | \\ \\  ||\n";
cout << " |__||  \\\\_|  \\_\\\\__/||  \\\\ (_)\n";

}
// TITLE SCREEN
void title()
{
    cout << endl;
    cout << endl;
    cout << "\t\t  .oooooo.     .oooooo.   ooooo      ooo ooooo      ooo oooooooooooo   .oooooo.   ooooooooooooo            .o   \n";
    cout << "\t\t d8P'  `Y8b   d8P'  `Y8b  `888b.     `8' `888b.     `8' `888'     `8  d8P'  `Y8b  8'   888   `8          .d88   \n";
    cout << "\t\t888          888      888  8 `88b.    8   8 `88b.    8   888         888               888             .d'888   \n";
    cout << "\t\t888          888      888  8   `88b.  8   8   `88b.  8   888oooo8    888               888           .d'  888   \n";
    cout << "\t\t888          888      888  8     `88b.8   8     `88b.8   888         888               888           88ooo888oo \n";
    cout << "\t\t`88b    ooo  `88b    d88'  8       `888   8       `888   888       o `88b    ooo       888                888   \n";
    cout << "\t\t `Y8bood8P'   `Y8bood8P'  o8o        `8  o8o        `8  o888ooooood8  `Y8bood8P'      o888o              o888o  \n";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t \t \t \t \t \t  Press any key to continue  \n";
    int enter = getch();

    system("cls");
}
//GUIDE
void guide()
{
    cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << endl;
    cout << "\t \t \t \tTHE MAIN OBJECTIVE OF THE GAME IS: \n";
    cout << endl;

    cout << " To consecutively connect 4 identically coloured discs/pieces either vertically, horizontally or diagonally.\n";

    cout << endl;
    cout << "--------------------------------------------------------------------"
            "-----------------------------------------\n";
    cout << endl;
    cout << "\t \t \t \t \tHOW TO PLAY: \n";
    cout << endl;
    cout << "1. The players choose a disc/piece which they use to play the game. It can only be R or Y "
            "\n";
    cout << "2. Turns between players are alternated and only one piece is "
            "played at a time.\n";
    cout << "3. On your turn drop your piece from the top of the board to any "
            "column that is not full.\n";
    cout << "4. This concludes your turn and the next player can now make their "
            "move in the same way.\n";
    cout << "5. Error occurs when the piece is dropped in a coloumn that exceeds the max column number of the board\n   or if you try to drop the piece in an already full coloumn. \n";        
    cout << "6. The game ends when there is a 4-in-a-row either vertically, "
            "horizontally or diagonally \n   or a stalemate is reached with no "
            "winner.\n";        
    cout << endl;
    cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << endl;
}
//assign names to players according to their choices
string player_name(char PLAYER_MOVE, string n1, string n2)
{
    if (PLAYER_MOVE == 'R')
    {
        return n1;
    }
    else
    {
        return n2;
    }
    return 0;
}

// initilaizes board
void InitialiseBoard()
{
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
         << "\n";
    for (int j = i_max - 1; j >= 0; --j)
    {
        for (int i = 0; i < j_max; ++i)
        {
            Board[i][j] = ' ';
            cout << "| " << Board[i][j] << " ";
        }
        cout << "|"
             << "\n";
        cout << "-----------------------------"
             << "\n";
    }
}
// shows updated board every time a move has been made
void displayboard()
{
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
         << "\n";
    for (int j = i_max - 1; j >= 0; --j)
    {
        for (int i = 0; i < j_max; ++i)
        {
            cout << "| " << Board[i][j] << " ";
        }
        cout << "|"
             << "\n";
        cout << "-----------------------------"
             << "\n";
    }
}
void Player_makes_a_move(int column_no, char &Player_move) // takes desired column and move of the player as
                                                          // arguments and subsequently updates the board
{
    for (int i = 0; i < i_max; ++i)
    {
        if (Board[column_no][i] == ' ')
        {
            Board[column_no][i] = Player_move;
            if (Player_move == 'Y') // swapping of turns
            {
                Player_move = 'R';
            }
            else if (Player_move == 'R')
            {
                Player_move = 'Y';
            }
            displayboard();
            return;
        }
    }
    error();
    cout << "\n";

}

bool check_for_full() // checking for full board
{
    for (int b = i_max - 1; b >= 0; --b)
    {
        for (int a = 0; a < j_max; ++a)
        {
            if (Board[a][b] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

bool check_vertical_line() // checking for winner acrosss vertical line
{
    int counter_player_1 = 0;
    int counter_player_2 = 0;
    for (int j = 0; j < j_max; ++j)
    {
        for (int i = 0; i < i_max; ++i)
        {
            if (Board[i][j] == 'R')
            {
                counter_player_1 = counter_player_1 + 1;
                counter_player_2 = 0;
            }
            else if (Board[i][j] == 'Y')
            {
                counter_player_1 = 0;
                counter_player_2 = counter_player_2 + 1;
            }
            else
            {
                counter_player_1 = 0;
                counter_player_2 = 0;
            }
            if (counter_player_1 >= 4)
            {
                return true;
            }
            else if (counter_player_2 >= 4)
            {
                return true;
            }
        }
        counter_player_1 = 0;
        counter_player_2 = 0;
    }
    return false;
}
bool check_diagonal_line() // check for victory across the diagonal
{
    for (int a = 0; a < j_max - 3; ++a)
    {
        for (int b = 0; b < i_max - 3; ++b)
        {
            if ((Board[a][b] != ' ') && (Board[a][b] == Board[a + 1][b + 1]) &&
                (Board[a][b] == Board[a + 2][b + 2]) &&
                (Board[a][b] == Board[a + 3][b + 3]))
            {
                return true;
            }
        }
    }
    for (int a = 0; a < j_max - 3; ++a)
    {
        for (int b = 3; b < i_max; ++b)
        {
            if ((Board[a][b] != ' ') && (Board[a][b] == Board[a + 1][b - 1]) &&
                (Board[a][b] == Board[a + 2][b - 2]) &&
                (Board[a][b] == Board[a + 3][b - 3]))
            {
                return true;
            }
        }
    }
    return false;
}

bool check_horizontal_line() // checks for potential winner along the horizontal line
{
    int counter_player_1 = 0;
    int counter_player_2 = 0;
    for (int z = 0; z < i_max; ++z)
    {
        for (int i = 0; i < j_max; ++i)
        {
            if (Board[z][i] == 'R')
            {
                counter_player_1 = counter_player_1 + 1;
                counter_player_2 = 0;
            }
            else if (Board[z][i] == 'Y')
            {
                counter_player_1 = 0;
                counter_player_2 = counter_player_2 + 1;
            }
            else
            {
                counter_player_1 = 0;
                counter_player_2 = 0;
            }
            if (counter_player_1 >= 4)
            {
                return true;
            }
            else if (counter_player_2 >= 4)
            {
                return true;
            }
        }
        counter_player_1 = 0;
        counter_player_2 = 0;
    }
    return false;
}
// checks for the outcome of the game
bool check_game_finished()
{
    return (check_diagonal_line() || check_horizontal_line() ||
            check_vertical_line());
}
//main interface
int main()
{
    int choice = 0;
    int column_no;
    char Player_move;
    string player_1, player_2, player = " ";
    int option;
    title();
    cout << "\t\t\t\t\t\t|********|\n";
    cout << "\t\t\t\t\t\t|  WELCOME TO CONNECT 4! |\n";
    cout << "\t\t\t\t\t\t ********\n";
    cout << endl;
    cout << "PLEASE SELECT AN OPTION: \n";
    cout << "PRESS 1 TO VIEW THE GUIDE\n";
    cout << "PRESS 2 TO START A MATCH\n";
    cout << "PRESS 3 TO EXIT THE GAME\n";
    cin >> option;
    while (option != 3 || option == 1 || option == 2)
    {

        if (option == 2)
        {
            cout << "Please enter name of player 1: ";
            cin >> player_1;
            cout << "\n";
            cout << "Please enter name of player 2:  ";
            cin >> player_2;
            cout << "\n";
            cout << "Please enter your move: ";
            cin >> Player_move;
            while ((Player_move != 'R') && (Player_move != 'Y'))
            {
                cout << "Please enter your move: ";
                cin >> Player_move;
            }
            InitialiseBoard();
            while (true)
            {
                player = player_name(Player_move, player_1, player_2);
                cout << "The turn is of " << player << "\n";
                cout << "Please enter column no: ";
                cin >> column_no;
                system("cls");
                Player_makes_a_move((column_no - 1), Player_move);

                if (check_game_finished())
                {
                    break;
                }

                if (check_for_full())
                {
                    cout << "THE GAME TIED (^_^)"
                         << "\n";
                    break;
                }
            }

            if (Player_move == 'R')
            {
                player = player_2;
                Player_move = 'Y';
            }
            else
            {
                player = player_1;
                Player_move = 'R';
            }

            cout << "\n\nCONGRATULATIONS!" << player << " WINS \\(^O^)/"<<"\n";
        }
        if (option == 1)
        {
            guide();

            while (option == 1)
            {
                cout << "PLEASE SELECT AN OPTION: \n";
                cout << "PRESS 1 TO VIEW THE GUIDE\n";
                cout << "PRESS 2 TO START A MATCH\n";
                cout << "PRESS 3 TO EXIT THE GAME\n";
                cin >> option;
                if (option == 2)
                {
                    cout << "Please enter name of Player one:  ";
                    cin >> player_1;
                    cout << "\n";
                    cout << "Please enter name of Player two:  ";
                    cin >> player_2;
                    cout << "\n";
                    cout << "Please enter your move: ";
                    cin >> Player_move;
                    while ((Player_move != 'R') && (Player_move != 'Y'))
                    {
                        cout << "Please enter your move: ";
                        cin >> Player_move;
                    }
                    InitialiseBoard();
                    while (true)
                    {
                        player = player_name(Player_move, player_1, player_2);
                        cout << "The turn is of " << player << "\n";
                        cout << "Please enter column no: ";
                        cin >> column_no;
                        system("cls");
                        Player_makes_a_move((column_no - 1), Player_move);
                        if (check_game_finished())
                        {
                            break;
                        }

                        if (check_for_full())
                        {
                            cout << "THE GAME TIED (^_^)"
                                 << "\n";
                        }
                    }
                    if (Player_move == 'R')
                    {
                        player = player_2;
                        Player_move = 'Y';
                    }
                    else
                    {
                        player = player_1;
                        Player_move = 'R';
                    }

                    cout << "\n\nCONGRATULATIONS!" << player << " WINS \\(^O^)/"
                         << "\n";
                }
                else if (option == 3)
                {
                    break;
                }
            }
        }
        if (option == 3)
        {
            break;
        }
        cout << "PLEASE SELECT AN OPTION: \n";
        cout << "PRESS 1 TO VIEW THE GUIDE\n";
        cout << "PRESS 2 TO START A MATCH\n";
        cout << "PRESS 3 TO EXIT THE GAME\n";
        cin >> option;
    }

    cout << "GAME EXITED! (T T)";

    return 0;
}
