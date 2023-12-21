#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <windows.h>//for sleep
#include <unistd.h>//for sleep
#include <cstdlib>//for random game
#include <ctime>//for random game


#include <vector> //hangman
#include <algorithm> //hangman
//#include <ctime> //hangman
#include <cctype> //hangman


//#include <iostream>
//#include <string>
//#include <vector>
//#include <ctime>
//#include <cstdlib>

//#include <iostream>
#include <cstring>//tictactoe
//#include <cstdlib>

using namespace std;

void welcome_screen();
class user;
void user_login();
void user_registration();
void add_details();
void app_options(string username);
void faq();
void games();
void game1_guessthenumber();
void game2_rockpaperscissor();
void game3_hangman();
void game4_jumbled();
string g4_getRandomWord();
string g4_jumbleWord(const string& word);
void game5_tictactoe();
bool g5_checkDraw(char board[3][3]);
bool g5_checkWin(char board[3][3], char symbol);
void g5_printBoard(char board[3][3]);

void dots();


int main()
{
    system("color BD");
    cout << "Main is running" << endl;
    welcome_screen();
    return 0;
}

void dots()
{
    for (int i = 0; i < 4; i++) {
        Sleep(1000);//one second delay
        cout << ".";
    }
}

void dots_purchase()
{
    for (int i = 0; i < 10; i++) {
        Sleep(1000);//one second delay
        cout << ".";
    }
}

void welcome_screen()
{
    system("cls");
    int choice;
    cout << "\n\n\t\t\t----------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t  WELCOME TO STEAM" << endl;
    cout << "\t\t\t----------------------------------------------------------------------\n\n" << endl;
    cout << "\t\t\t\t\tPlease select an option from below:\n\n " << endl;
    cout << "\t\t\t\t\t\t  1. Login \n" << endl;
    cout << "\t\t\t\t\t\t  2. Register \n" << endl;
    cout << "\t\t\t\t\t\t  3. Exit \n" << endl;
    cout << "\n\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        user_login();
    }


    else if (choice == 2)
    {
        user_registration();
    }



    else if (choice == 3)
    {
        system("cls");
        cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";
        dots();
        exit(0);
        //break;
    }

    else
    {
        cout << "\t\t\t\tINVALID INPUT.";
        cout << "\t\t\t\tTry again in 3 seconds.";
        dots();
        welcome_screen();
    }
}

void user_login()
{
    system("cls");
    string username, password;
    cout << "\n\n\t\t\t----------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t  USER LOGIN PAGE" << endl;
    cout << "\t\t\t----------------------------------------------------------------------\n\n" << endl;
    cout << "\t\t\t\t Please Enter your User-Name and Password to Login" << endl;
    cout << "\n\n\t\t\t\t\t   Enter your User-Name: ";
    cin >> username;


    cout << "\n\t\t\t\t\t   Enter your Password: ";
    cin >> password;

    ifstream myfile;
    myfile.open("all_users.txt", ios::in);
    string stored_user, stored_password;
    string line;
    bool found = false;
    while (getline(myfile, line, '\n'))
    {
        if (line == username + " " + password)
        {
            found = true;
            break;
        }
    }
    if (found == true) {
        cout << "\n\n\t\t\t\t\t\tSuccessfully Logged In!" << endl;
        cout << "\n\n\n\t\t\t\t\t      Connecting to Games Portal";
        dots();
        app_options(username);

    }

    else
    {
        cout << "\n\n\n\t\t\t\t\t Login failed! " << endl;
        cout << "\n\n\n\t\t\t\t\t Try again in 3 seconds!";
        dots();
        welcome_screen();

    }

}

void user_registration()
{
    string username;
    system("cls");

    cout << "\n\n\t\t\t----------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t  USER REGISTRATION PAGE" << endl;
    cout << "\t\t\t----------------------------------------------------------------------\n\n" << endl;


    add_details();
    cout << "You've successfully registered" << endl;
    dots();
    sleep(3);
    //user_login();
    app_options(username);


}



class user
{
protected:

    string password;
    string email;
    string name;
    string gender;
    string upi;

    //float wallet;

public:
    string username;
    user()
    {
        string ch;
        fflush(stdin);
        //Its purpose is to clear (or flush) the output buffer and move the buffered data to console
        cout << "\n\n";
        cout << "\t\t\t\t\t Enter your username: ";
        getline(cin, username);
        fflush(stdin);
        cout << "\t\t\t\t\t Enter your password: ";
        getline(cin, password);
        fflush(stdin);
        cout << "\t\t\t\t\t Enter your name: ";
        getline(cin, name);
        fflush(stdin);

        while (1) {
            cout << "\t\t\t\t\t Enter your gender F/M: ";
            fflush(stdin);
            getline(cin, gender);
            fflush(stdin);
            if (gender == "m" || gender == "f" || gender == "F" || gender == "M")
                break;
        }

        cout << "\t\t\t\t\t Enter email: ";
        getline(cin, email);

        cout << "\t\t\t\t\t Enter UPI ID: ";
        getline(cin, upi);

        ofstream file1;
        file1.open("all_users.txt", ios::app);
        if (file1.is_open())
        {
            file1 << username << " " << password << endl;
            file1.close();
        }
        else {
            cout << "Could not register, please try again" << endl;
        }

        ///////upi
        ofstream file_upi;
        file_upi.open("all_upi.txt", ios::app);
        if (file_upi.is_open())
        {
            file_upi << upi << endl;
            file_upi.close();
        }
        ///////

        string filename = username + ".txt";

        ofstream myfile;

        myfile.open(filename, ios::app);

        if (myfile.is_open())
        {
            myfile << username + '\n';
            myfile << password + '\n';
            myfile << name + '\n';
            myfile << gender + '\n';
            myfile << email + '\n';
            myfile << upi + '\n';

            myfile.close();
        }
        else
        {
            cout << "Error, cannot register you in. Please try again";
            dots();
            welcome_screen();
        }
    }

    void putData()
    {
        cout << "Username: " << username << endl;
        cout << "Name of user: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Email: " << email << endl;
        cout << "UPI: " << upi << endl;
    }



};

void add_details()
{
    cout << "\t\t\t\t     Please Enter Your Details to Register Yourself" << endl;
    user u;
}


void app_options(string username)
{
    system("cls");
    int ch;
    //user us1;
    cout << "\n\n\t\t\t----------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tWELCOME TO YOUR FAVOURITE GAME STATION! " << endl;
    cout << "\t\t\t----------------------------------------------------------------------\n\n" << endl;
    cout << "\t\t\t\t\t    What do you wish to do access? ";
    cout << "\n\n\n\t\t\t\t\t\t 1. Gaming Library ";
    cout << "\n\n\n\t\t\t\t\t\t 2. FAQ ";
    //cout << "\n\n\n\t\t\t\t\t\t 3. Your Info: ";
    cout << "\n\n\n\t\t\t\t\t\t 3. Log out ";


    cout << "\n\n\n\t\t\t\t\t       Enter Your Choice: ";
    cin >> ch;

    if (ch == 1)
    {
        system("cls");
        games();



    }



    else if (ch == 2)
    {
        system("cls");
        faq();
        system("pause");
        system("cls");
        app_options(username);

    }

    //else if (ch == 3)
    //{
        //system("cls");
        //us1.putData();
    //}



    else if (ch == 3)
    {

        system("cls");
        cout << "Logging you out.";
        dots();
        welcome_screen();

    }

}


void faq()
{
    cout << "\n\n\n\t\t\t\tFREQUENTLY ASKED QUESTIONS" << endl;
    cout << "\t\t\t\t==========================\n" << endl;
    cout << "\t\t\tQ1. What if you can't login?" << endl;
    cout << "\t\t\t A. Try again after sometime, and if the problem persists contact admin\n" << endl;
    cout << "\t\t\tQ2. How many free games are available?" << endl;
    cout << "\t\t\t A. 2 free games are available.\n" << endl;
    cout << "\t\t\tQ3. Do I have to buy games everytime i play?" << endl;
    cout << "\t\t\t A. Currently, yes but its coming with new features soon.\n" << endl;
    cout << "\t\t\tQ4. How do i contact the app in case of any query? " << endl;
    cout << "\t\t\t A. You can contact us at steam@hotmail.com\n" << endl;
    cout << "\t\t\tQ5. Will you add any new games?" << endl;
    cout << "\t\t\t A. Yes,we are hiring high quality game devs.\n" << endl;
}



void view_details()
{
    cout << "Your details are as follows: " << endl;
    ifstream myfile;
    myfile.open("all_details.txt");


    if(myfile.is_open())
    {
        string username, password, name, email, upi; int i = 1;
        while(getline(myfile, username, ','))
        {
            getline(myfile, name, ',');
            getline(myfile, upi, '\n');
            cout << i << ": " << username << " - " << name << " - " << upi << endl;
            i++;
        }
        system("pause");
    }
    else{
        cout << "No students found" << endl;
    }
}

void games()
{
    string username;
    cout << "\n\n\t\t\t----------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t     WELCOME TO YOUR GAMING LIBRARY" << endl;
    cout << "\t\t\t----------------------------------------------------------------------\n\n" << endl;
    cout << "\t\t\t\t       Please select which game you want to play!\n" << endl;

    cout << "\n\n\t\t\t\t\t\t   1. Guessing Game" << endl;
    cout << "\n\n\t\t\t\t\t\t   2. Rock Paper Scissor" << endl;
    cout << "\n\n\t\t\t\t\t\t   3. Hangman" << endl;
    cout << "\n\n\t\t\t\t\t\t   4. Jumbled Words" << endl;
    cout << "\n\n\t\t\t\t\t\t   5. Tic Tac Toe" << endl;



    cout << "\n\n\t\t\t\t\t\t   6. Go back to home page " << endl;



    int ch;

    cout << "\n\n\n\t\t\t\t\t\tEnter Your Choice: ";
    cin >> ch;

    if (ch == 1)
    {
        system("cls");
        game1_guessthenumber();

    }

    else if (ch == 2)
    {
        system("cls");
        game2_rockpaperscissor();
    }

    else if (ch == 3)
    {
        system("cls");
        game3_hangman();
    }

    else if (ch == 4)
    {
        system("cls");
        game4_jumbled();
    }

    else if (ch == 5)
    {
        system("cls");
        game5_tictactoe();
    }


    else if (ch == 6)
    {
        system("cls");
        app_options(username);

    }

    else
    {
        cout << "Invalid choice! Please enter again: ";
        cin >> ch;
    }




}

void game1_guessthenumber()
{
    string username;

    srand(time(NULL));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int numGuesses = 0;

    int ch;

    cout << "\n\n\t\t\t----------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t     WELCOME TO THE GUESSING GAME" << endl;
    cout << "\t\t\t----------------------------------------------------------------------\n\n" << endl;


    cout << "\t\t\t    I'm thinking of a number between 1 and 100. Can you guess it?\n" << endl;

    while (true)
    {
        cout << "\n\t\t\t\t\t\t  Enter your guess: ";
        cin >> guess;

        numGuesses++;

        if (guess == secretNumber)
        {
            cout << "\n\n\t\t\t    Congratulations, you guessed the secret number in " << numGuesses << " guesses!" << endl;
            //system("pause");
            cout << "\n\t\t\t\t      Press 1 if you wish to play this game again!" << endl;
            cout << "\n\t\t\t\t      Press 2 if you wish to explore other games!" << endl;
            cout << "\n\t\t\t\t          Press 3 to exit to the main menu!" << endl;
            cout << "\n\t\t\t\t                  Enter your choice: ";
            cin >> ch;

            if (ch == 1)
            {
                system("cls");
                game1_guessthenumber();

            }
            else if (ch == 2)
            {

                system("cls");
                games();


            }

            else if (ch == 3)
            {
                system("cls");
                app_options(username);
            }

            else
            {
                cout << "\n\t\t\t\tInvalid option entered! Taking back to main menu. ";
                system("cls");
                app_options(username);
            }


        }
        else if (guess < secretNumber)
        {
            cout << "\t\t\t\t\t\t  Too low. Guess again." << endl;
        }
        else
        {
            cout << "\t\t\t\t\t\t  Too high. Guess again." << endl;
        }
    }

    //return 0;
}



void game2_rockpaperscissor()
{
    srand(time(NULL));

    int computerChoice = rand() % 3 + 1;
    int userChoice;

    cout << "Let's play Rock-Paper-Scissors!" << endl;
    cout << "Choose your weapon: 1 = Rock, 2 = Paper, 3 = Scissors" << endl;
    cin >> userChoice;

    switch (userChoice)
    {
    case 1: // Rock
        if (computerChoice == 1)
        {
            cout << "It's a tie! We both chose rock." << endl;
        }
        else if (computerChoice == 2)
        {
            cout << "You lose! Paper beats rock." << endl;
        }
        else
        {
            cout << "You win! Rock beats scissors." << endl;
        }
        break;
    case 2: // Paper
        if (computerChoice == 1)
        {
            cout << "You win! Paper beats rock." << endl;
        }
        else if (computerChoice == 2)
        {
            cout << "It's a tie! We both chose paper." << endl;
        }
        else
        {
            cout << "You lose! Scissors beats paper." << endl;
        }
        break;
    case 3: // Scissors
        if (computerChoice == 1)
        {
            cout << "You lose! Rock beats scissors." << endl;
        }
        else if (computerChoice == 2)
        {
            cout << "You win! Scissors beats paper." << endl;
        }
        else
        {
            cout << "It's a tie! We both chose scissors." << endl;
        }
        break;
    default:
        cout << "Invalid choice. Please choose 1 for Rock, 2 for Paper, or 3 for Scissors." << endl;
        break;
    }

    //return 0;
}



void game3_hangman()//50
{
    string upi;
    //string upi_id;
    string username;
    cout << "\t\t\t\t\n     This game is paid" << endl;
    cout << "\t\t\t\t\n 1. Would you like to purchase the game." << endl;
    cout << "\t\t\t\t\n 2. Exit back to gaming library" << endl;


    int ch;

    cout << "\n\n\n\t\t\t\t\t ENTER YOUR CHOICE: ";
    cin >> ch;

    if (ch == 1)
    {
        cout << "Pay 150 Rs on steam@upi ;" << endl;
        cout << "Enter your UPI ID: ";
        cin >> upi;
        dots_purchase();


        //file handling upi match




        ifstream file_upi;
        file_upi.open("all_upi.txt", ios::in);
        string stored_upi;
        string line;
        bool found = false;
        while (getline(file_upi, line, '\n'))
        {
            if (line == upi)
            {
                found = true;
                break;
            }
        }
        //if (found = true)
        {

            //cout<<"Welcome";
        }







        if (found = true)// upi id match))
            // Set up the game
        {
            system("cls");
            cout << endl << "UPI ID verified, Congratulations on purchasing this game.Enjoy!!" << endl;




            const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

            vector<string> words;  // collection of possible words to guess
            words.push_back("GUESS");
            words.push_back("HANGMAN");
            words.push_back("DIFFICULT");

            srand(static_cast<unsigned int>(time(0)));
            random_shuffle(words.begin(), words.end());

            const string THE_WORD = words[0];  // word to guess
            int wrong = 0;  // number of incorrect guesses
            string soFar(THE_WORD.size(), '-');  // word guessed so far
            string used = "";  // letters already guessed

            cout << "Welcome to Hangman. Good luck!\n";

            // Main game loop
            while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
                cout << "\n\nYou have " << (MAX_WRONG - wrong);
                cout << " incorrect guesses left.\n";
                cout << "\nYou've used the following letters:\n" << used << endl;
                cout << "\nSo far, the word is:\n" << soFar << endl;

                char guess;
                cout << "\n\nEnter your guess: ";
                cin >> guess;
                guess = toupper(guess);  // make uppercase since secret word is in uppercase

                while (used.find(guess) != string::npos) {
                    cout << "\nYou've already guessed " << guess << endl;
                    cout << "Enter your guess: ";
                    cin >> guess;
                    guess = toupper(guess);
                }

                used += guess;

                if (THE_WORD.find(guess) != string::npos) {
                    cout << "That's right! " << guess << " is in the word.\n";

                    // update the word guessed so far with the correct guess
                    for (unsigned int i = 0; i < THE_WORD.length(); ++i) {
                        if (THE_WORD[i] == guess) {
                            soFar[i] = guess;
                        }
                    }
                }
                else {
                    cout << "Sorry, " << guess << " isn't in the word.\n";
                    ++wrong;
                }
            }

            // Game over - print out the result
            if (wrong == MAX_WRONG) {
                cout << "\nYou've been hanged!";
            }
            else {
                cout << "\nYou guessed it!";
            }

            cout << "\nThe word was " << THE_WORD << endl;

            int choice;
            cout << "\n\t\t\t\t      Press 1 if you wish to play this game again!" << endl;
            cout << "\n\t\t\t\t      Press 2 if you wish to explore other games!" << endl;
            cout << "\n\t\t\t\t          Press 3 to exit to the main menu!" << endl;
            cout << "\n\t\t\t\t                  Enter your choice: ";
            cin >> ch;

            if (choice == 1)
            {
                system("cls");
                game3_hangman();

            }
            else if (choice == 2)
            {

                system("cls");
                games();


            }

            else if (choice == 3)
            {
                system("cls");
                app_options(username);
            }

            else
            {
                cout << "\n\t\t\t\tInvalid option entered! Taking back to main menu. ";
                system("cls");
                app_options(username);
            }


        }
        else//upi id mismatch)
        {
            cout << "Try again" << endl;
            game3_hangman();
        }

    }

    else if (ch == 2)
    {
        games();


    }

    //return 0;
}




//using namespace std;

const vector<string> WORDS = { "computer", "program", "language", "algorithm", "memory", "debug", "compiler", "syntax", "variable", "binary" };

string g4_getRandomWord() {
    // get a random word from the WORDS vector
    int index = rand() % WORDS.size();
    return WORDS[index];
}

string g4_jumbleWord(const string& word) {
    // jumble the letters of the word
    string jumbled = word;
    int length = jumbled.size();
    for (int i = 0; i < length; ++i) {
        int index1 = rand() % length;
        int index2 = rand() % length;
        char temp = jumbled[index1];
        jumbled[index1] = jumbled[index2];
        jumbled[index2] = temp;
    }
    return jumbled;
}

bool playAgain() {
    // ask the player if they want to play again
    cout << "Do you want to play again? (y/n) ";
    char answer;
    cin >> answer;
    return answer == 'y' || answer == 'Y';
}

void game4_jumbled()
{
    string upi;
    string username;


    //string upi_id;
    cout << "\t\t\t\t\n     This game is paid" << endl;
    cout << "\t\t\t\t\n 1. Would you like to purchase the game." << endl;
    cout << "\t\t\t\t\n 2. Exit back to gaming library" << endl;


    int ch;

    cout << "\n\n\n\t\t\t\t\t ENTER YOUR CHOICE: ";
    cin >> ch;

    if (ch == 1)
    {
        cout << "Pay 150 Rs on steam@upi ;" << endl;
        cout << "Enter your UPI ID: ";
        cin >> upi;
        dots_purchase();

        //upi id file handling
        ifstream file_upi;
        file_upi.open("all_upi.txt", ios::in);
        string stored_upi;
        string line;
        bool found = false;
        while (getline(file_upi, line, '\n'))
        {
            if (line == upi)
            {
                found = true;
                break;
            }
        }
        //if (found = true)
        {

            //cout<<"Welcome";
        }










        if (found = true)//upi id match)
        {


            system("cls");
            cout << endl << "UPI ID verified, Congratulations on purchasing this game.Enjoy!!" << endl;

            srand(static_cast<unsigned int>(time(0)));

            cout << "Welcome to Word Jumble!\n";
            bool playing = true;

            while (playing) {
                string word = g4_getRandomWord();
                string jumbled = g4_jumbleWord(word);
                int tries = 0;

                cout << "The jumbled word is: " << jumbled << endl;

                while (tries < 3) {
                    string guess;
                    cout << "Enter your guess: ";
                    cin >> guess;

                    if (guess == word) {
                        cout << "Congratulations! You guessed the word.\n";
                        break;
                    }
                    else {
                        cout << "Sorry, that's not the word.\n";
                        ++tries;
                    }
                }

                if (tries == 3) {
                    cout << "You ran out of tries. The word was " << word << endl;
                }

                playing = playAgain();
            }

            cout << "Thanks for playing!\n";
            //return 0;



            ////
            int choice;
            cout << "\n\t\t\t\t      Press 1 if you wish to play this game again!" << endl;
            cout << "\n\t\t\t\t      Press 2 if you wish to explore other games!" << endl;
            cout << "\n\t\t\t\t          Press 3 to exit to the main menu!" << endl;
            cout << "\n\t\t\t\t                  Enter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                system("cls");
                game4_jumbled();

            }
            else if (choice == 2)
            {

                system("cls");
                games();


            }

            else if (choice == 3)
            {
                system("cls");
                app_options(username);
            }

            else
            {
                cout << "\n\t\t\t\tInvalid option entered! Taking back to main menu. ";
                system("cls");
                app_options(username);
            }


        }

        else//upi id mismatch)
        {
            cout << "Try again" << endl;
            game4_jumbled();
        }
    }

    else if (ch == 2)
    {
        games();
    }



}




//using namespace std;

void g5_printBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

bool g5_checkWin(char board[3][3], char symbol)
{
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true; // horizontal win
        }
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true; // vertical win
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true; // diagonal win
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true; // diagonal win
    }
    return false;
}

bool g5_checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // empty space found, game not over
            }
        }
    }
    return true; // no empty spaces found, game over (draw)
}

void game5_tictactoe()//200
{


    string upi;
    string username;
    cout << "\t\t\t\t\n     This game is paid" << endl;
    cout << "\t\t\t\t\n 1. Would you like to purchase the game." << endl;
    cout << "\t\t\t\t\n 2. Exit back to gaming library" << endl;


    int ch;

    cout << "\n\n\n\t\t\t\t\t ENTER YOUR CHOICE: ";
    cin >> ch;

    if (ch == 1)
    {
        cout << "Pay 150 Rs on steam@upi ;" << endl;
        cout << "Enter your UPI ID: ";
        cin >> upi;
        dots_purchase();

        //upi id file handling

        ifstream file_upi;
        file_upi.open("all_upi.txt", ios::in);
        string stored_upi;
        string line;
        bool found = false;
        while (getline(file_upi, line, '\n'))
        {
            if (line == upi)
            {
                found = true;
                break;
            }
        }
        //if (found = true)













        if (found = true)//upi id match)
        {
            system("cls");
            cout << endl << "UPI ID verified, Congratulations on purchasing this game.Enjoy!!" << endl;

            char board[3][3];
            memset(board, ' ', sizeof(board)); // initialize board with empty spaces
            char player1 = 'X';
            char player2 = 'O';
            int currentPlayer = 1;
            bool gameOver = false;

            cout << "Welcome to Tic Tac Toe!" << endl;
            g5_printBoard(board);

            do {
                int row, col;
                cout << "Player " << currentPlayer << ", enter row (1-3): ";
                cin >> row;
                cout << "Player " << currentPlayer << ", enter column (1-3): ";
                cin >> col;

                if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                    cout << "Invalid move. Try again." << endl;
                    continue;
                }

                if (currentPlayer == 1)
                {
                    board[row - 1][col - 1] = player1;
                    if (g5_checkWin(board, player1))
                    {
                        cout << "Player 1 wins!" << endl;

                        int choice;
                        cout << "\n\t\t\t\t      Press 1 if you wish to play this game again!" << endl;
                        cout << "\n\t\t\t\t      Press 2 if you wish to explore other games!" << endl;
                        cout << "\n\t\t\t\t          Press 3 to exit to the main menu!" << endl;
                        cout << "\n\t\t\t\t                  Enter your choice: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            system("cls");
                            game5_tictactoe();

                        }
                        else if (choice == 2)
                        {

                            system("cls");
                            games();


                        }

                        else if (choice == 3)
                        {
                            system("cls");
                            app_options(username);
                        }

                        else
                        {
                            cout << "\n\t\t\t\tInvalid option entered! Taking back to main menu. ";
                            system("cls");
                            app_options(username);
                        }
                        gameOver = true;
                    }
                }
                else
                {
                    board[row - 1][col - 1] = player2;
                    if (g5_checkWin(board, player2))
                    {
                        cout << "Player 2 wins!" << endl;

                        int choice;
                        cout << "\n\t\t\t\t      Press 1 if you wish to play this game again!" << endl;
                        cout << "\n\t\t\t\t      Press 2 if you wish to explore other games!" << endl;
                        cout << "\n\t\t\t\t          Press 3 to exit to the main menu!" << endl;
                        cout << "\n\t\t\t\t                  Enter your choice: ";
                        cin >> choice;

                        if (choice == 1)
                        {
                            system("cls");
                            game5_tictactoe();

                        }
                        else if (choice == 2)
                        {

                            system("cls");
                            games();


                        }

                        else if (choice == 3)
                        {
                            system("cls");
                            app_options(username);
                        }

                        else
                        {
                            cout << "\n\t\t\t\tInvalid option entered! Taking back to main menu. ";
                            system("cls");
                            app_options(username);
                        }

                        gameOver = true;
                    }
                }

                if (g5_checkDraw(board)) {
                    cout << "It's a draw!" << endl;

                    int choice;

                    cout << "\n\t\t\t\t      Press 1 if you wish to play this game again!" << endl;
                    cout << "\n\t\t\t\t      Press 2 if you wish to explore other games!" << endl;
                    cout << "\n\t\t\t\t          Press 3 to exit to the main menu!" << endl;
                    cout << "\n\t\t\t\t                  Enter your choice: ";
                    cin >> choice;

                    if (choice == 1)
                    {
                        system("cls");
                        game5_tictactoe();

                    }
                    else if (choice == 2)
                    {

                        system("cls");
                        games();


                    }

                    else if (choice == 3)
                    {
                        system("cls");
                        app_options(username);
                    }

                    else
                    {
                        cout << "\n\t\t\t\tInvalid option entered! Taking back to main menu. ";
                        system("cls");
                        app_options(username);
                    }


                    gameOver = true;
                }

                g5_printBoard(board);
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            } while (!gameOver);

            //return 0;


        }

        else//upi id mistmatch)
        {
            cout << "Try again" << endl;
            game5_tictactoe;
        }

    }

    else if (ch == 2)
    {
        games();
    }


}

