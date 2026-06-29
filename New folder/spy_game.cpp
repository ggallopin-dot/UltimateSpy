//week 3; Gary Gallopin
// portfolio: Spy Game code
// 2 - level game level 1 - easy; level 2 - more difficult

#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

class Guard
{
private:
    int xpos;
    int ypos;
    char icon;
public:
    Guard()
    {
        xpos = 0;
        ypos = 0;
        icon = ' ';
    }

    Guard(int x, int y, char i)
    {
        xpos = x;
        ypos = y;
        icon = i;
    }

    int get_x()
    {
        return xpos;
    }

    int get_y()
    {
        return ypos;
    }

    char getIcon()
    {
        return icon;
    }

    void set_x(int x)
    {
        xpos = x;
    }

    void set_y(int y)
    {
        ypos = y;
    }

    void setIcon(char i)
    {
        icon = i;
    }
};

class Spy
{
private:
    int xspy;
    int yspy;
    char iconspy;
public:
    Spy()
    {
        xspy = 0;
        yspy = 0;
        iconspy = ' ';
    }

    Spy(int x, int y, char i)
    {
        xspy = x;
        yspy = y;
        iconspy = i;
    }

    int getSpy_x()
    {
        return xspy;
    }

    int getSpy_y()
    {
        return  yspy;
    }

    char getSpyIcon()
    {
        return iconspy;
    }

    void setSpyx(int x)
    {
        xspy = x;
    }

    void setSpyy(int y)
    {
        yspy = y;
    }

};

class Goal
{
private:
    int xgoal;
    int ygoal;
    char icongoal;
public:
    Goal()
    {
        xgoal = 0;
        ygoal = 0;
        icongoal = ' ';
    }
    Goal(int x, int y, char i)
    {
        xgoal = x;
        ygoal = y;
        icongoal = i;
    }

    int getGoal_x()
    {
        return xgoal;
    }

    int getGoal_y()
    {
        return  ygoal;
    }

    char getGoalIcon()
    {
        return icongoal;
    }

    void setGoalx(int x)
    {
        xgoal = x;
    }

    void setGoaly(int y)
    {
        ygoal = y;
    }


};


bool Game_board_play(int level);
int compareStrings(string str1, string str2);
int getUserChoice();
string getNextMove();
vector<string>  game_board_setup(int c);
void move_guard(vector<string>& board, int& x, int& y, char& i);



int main()
{   
    int choice;
    do
    {
    
    // display menu choices
    cout << "\nWelcome to Ultra-Spy!" << endl;
    cout << "Select a level: " << endl; 
    cout << "1. Green Light" << endl;
    cout << "2. Red Alert" << endl;
    cout << "3. Exit: " << endl;   
    
    //get user data 
    choice = getUserChoice();
    if (choice == 3)
    {
        return 0;
    }
    //initialize board

    vector<string> GameBoard = game_board_setup(choice);
    string spy_nxt_move = getNextMove();                    // Spy makes his first move
    if (0 == compareStrings(spy_nxt_move, "abort"))   // Before a decisive result, player leaves the game.
    {
        cout << "Game aborted by player!" << endl;
        return 0;
    }
    cout << "Spy next move is "  << spy_nxt_move << endl;
        for (int i = 0; i < GameBoard.size(); i++)   /////// testing
        {                                           ///////
            cout << GameBoard[i] << endl;           //////
        }

    //play the chosen level
    if (choice == 1)
    {
        //play level 1
        // init guard1 and guard2
        Guard guard1(6,5,'v');
        Guard guard2(2,4,'>');
        bool keep_playing = true;

        while (keep_playing)  ////loop until abort or decisive result
        {
            int x = guard1.get_x();
            int y = guard1.get_y();
            char icon = guard1.getIcon();
            cout <<  "y: " << y << endl;   //////testing
            move_guard(GameBoard, x, y, icon); //move guard1
            cout  << "y: " << y << endl;    /////testing
            guard1.set_x(x);
            guard1.set_y(y);
            guard1.setIcon(icon); // if guard reverses direction will need to update this

            int x2 = guard2.get_x();
            int y2 = guard2.get_y();
            char icon2 = guard2.getIcon();
            cout  << "y2: " << y2 << endl; ///////// testing
            move_guard(GameBoard, x2, y2, icon2); //move guard2
            cout  << "y2: " << y2 << endl; ///////// testing
            guard1.set_x(x2);
            guard1.set_y(y2);
            guard1.setIcon(icon2); // if guard reverses direction

            for (int i = 0; i < GameBoard.size(); i++)   /////// testing
            {
                cout << GameBoard[i] << endl;
            }

            keep_playing = Game_board_play(choice);
        }


        //Game_board_play(1);
    }
    else if (choice == 2)
    {
        // play level 2

        // init guard1, guard2 and guard3
        Guard guard1(6,6,'v');
        Guard guard2(2,5,'>');
        Guard guard3(10,4,'<');

        bool keep_playing = true;

        while (keep_playing)  ////loop until abort or decisive result
        {
            int x = guard1.get_x();
            int y = guard1.get_y();
            char icon = guard1.getIcon();
            cout <<  "y: " << y << endl;   //////testing
            move_guard(GameBoard, x, y, icon); //move guard1
            cout  << "y: " << y << endl;    /////testing
            guard1.set_x(x);
            guard1.set_y(y);
            guard1.setIcon(icon); // if guard reverses direction will need to update this

            int x2 = guard2.get_x();
            int y2 = guard2.get_y();
            char icon2 = guard2.getIcon();
            cout  << "y2: " << y2 << endl; ///////// testing
            move_guard(GameBoard, x2, y2, icon2); //move guard2
            cout  << "y2: " << y2 << endl; ///////// testing
            guard2.set_x(x2);
            guard2.set_y(y2);
            guard2.setIcon(icon2); // if guard reverses direction

            for (int i = 0; i < GameBoard.size(); i++)   /////// testing
            {
                cout << GameBoard[i] << endl;
            }

            int x3 = guard3.get_x();
            int y3 = guard3.get_y();
            char icon3 = guard3.getIcon();
            cout  << "y3: " << y3 << endl; ///////// testing
            move_guard(GameBoard, x3, y3, icon3); //move guard3
            cout  << "y3: " << y3 << endl; ///////// testing
            guard3.set_x(x3);
            guard3.set_y(y3);
            guard3.setIcon(icon3); // if guard reverses direction

            for (int i = 0; i < GameBoard.size(); i++)   /////// testing
            {
                cout << GameBoard[i] << endl;
            }

            keep_playing = Game_board_play(choice);
        }

        //Game_board_play(2);


    }
    else
    {
        cout << "Invalid choice! Choose 1, 2, or 3." << endl;
    }

    } while (choice != 3);
    
    
    return 0;
}



bool Game_board_play(int level)
{
    //update the board each move
    // update guard movement first
    if (level == 1)
    {

    }
    if (level == 2)
    {

    }
    return false;
}

int compareStrings(string str1, string str2)
{
    // loop through string one character at a time until
    // a mismatch is found or the entire string is equal
    // it uses tolower to turn upper case into lower case; found this function using A.I.
    int length;
    int length1 = str1.length();
    int length2 = str2.length();
    // First determine if the two strings have the same length
    // to determine loop termination.
    if (length1 <= length2) {length = length1;}
    else {length = length2;}

    for (int i = 0; i < length; i++)
    {
        if (tolower(str1[i]) != tolower(str2[i]))
        {
            if (tolower(str1[i]) < tolower(str2[i]) ){return -1;}
            else {return 1;}
        }
    }
    // check for length diff between to determine if there is a tie breaker
    if (length1 != length2) 
    {
        if (length1 < length2) {return -1;}
        else {return 1;}
    }
    return 0;
}

int getUserChoice()
{
    // collect and check user's choice of level of play
    //getline(cin,str_var);

    string player_choice;
    int result = -1;
    
    do
    {
        cout << "Choose your level of play or exit:_  ";
        getline(cin, player_choice);

        // compare player_choice with available choices: "1", "green light," "2", "red alert"
        if(0 == compareStrings(player_choice, "1") || 0 == compareStrings(player_choice, "green light"))
        {
            result = 1;
            return result; // level 1 chosen
        }
        
        if(0 == compareStrings(player_choice, "2") || 0 == compareStrings(player_choice, "red alert"))
        {
           result = 2;
           return result; // level 2 chosen
        }

        if(0 == compareStrings(player_choice, "3") || 0 == compareStrings(player_choice, "exit"))
        {
            result = 3;
            return result; // exit chosen
        }

        cout << "Invalid input! Choose \"1\", \"Green Light\", \"2\", or \"Red Alert\"." << endl;
        cout << "Or, choose \"3\", or \"Exit\", to exit the game." << endl;

    } while (result == -1);

    return result;

}


       
vector<string>  game_board_setup(int c)
{
    //illustrate initial board position based on user choice for level - c
    if (c == 1)
    {
        //level 1

        vector<string> board_rows = {"########", "#    v #", "#>  #  #","#   #  #", "#@  # $#", "########"};
        for (int i = 0; i < board_rows.size(); i++)
        {
            cout << board_rows[i] << endl;
        }
        return board_rows;
    }

    if (c == 2) //more difficult level with more walls and guards
    {
        // level 2

        vector<string> board_rows = {"###########", "#    v    #", "#>  #     #","#   #    <#", "#   #     #", "#@  #    $#", "###########"};
        for (int i = 0; i < board_rows.size(); i++)
        {
            cout << board_rows[i] << endl;
        }
        return board_rows;
    }
}

void move_guard(vector<string>& GameBoard, int& x, int& y, char& i)
{
    const char RIGHT = '>';
    const char LEFT = '<';
    const char UP = '^';
    const char DOWN = 'v';
    char icon;
    int row;
    int col;
    string row_string;
    size_t vectorSize = GameBoard.size();

    cout << " reached move_guard" << endl;   //////testing

    //vector<string> GameBoard&
    //row_string = GameBoard[y];

    if (i == RIGHT)
    {
        //get correct row: row == ((num of rows + 1) - y) - 1
        row = (vectorSize + 1) - y;
        row_string = GameBoard[row-1]; // vec starts at vec[0]
        icon = row_string[x - 1];
        row_string[x - 1] = ' ';
        row_string[x] = icon;           // (x - 1) + 1
        GameBoard[row - 1] = row_string;
        //new position on x, y: x changes; y stays the same
        x = x + 1; //one step to the right

    }
    else if (i == LEFT)
    {
        //move guard one step left
        //get correct row: row == (num of rows - y) - 1
        row = (vectorSize + 1) - y;
        row_string = GameBoard[row-1]; // vec starts at vec[0]
        icon = row_string[x - 1];
        row_string[x - 1] = ' ';
        row_string[x - 2] = icon;      // (x - 1) - 1
        GameBoard[row - 1] = row_string;
        //new position on x, y
        x = x - 1;  // one step to the left

    }
    else if (i == UP)
    {
        //move guard one step up
        row = (vectorSize + 1) - y;
        row_string = GameBoard[row - 1]; // vec starts at vec[0]
        icon = row_string[x - 1];
        row_string[x - 1] = ' ';
        GameBoard[row - 1] = row_string;
        // go up
        row_string = GameBoard[row - 2]; // going up means to a lower row
        row_string[x - 1] = icon;
        GameBoard[row - 2] = row_string;
        //new position on x,y
        y = y + 1;

    }
    else if (i == DOWN)
    {
        // move guard one step down
        row = (vectorSize + 1) - y;
        row_string = GameBoard[row - 1]; // vec starts at vec[0]
        icon = row_string[x - 1];
        row_string[x - 1] = ' ';
        GameBoard[row - 1] = row_string;
        // go down
        row_string = GameBoard[row]; // going down means to a higher row
        row_string[x - 1] = icon;
        GameBoard[row] = row_string;
        //new position on x,y
        y = y - 1;
    }

}

string getNextMove()
{
    //let player select the next move by the spy
    // display menu choices
    cout << "\nNext spy move:" << endl;
    cout << "Select a direction: " << endl;
    cout << "W - Up" << endl;
    cout << "S - Down" << endl;
    cout << "A - Left" << endl;
    cout << "D - Right" << endl;
    cout << "Abort -- end Ultra-Spy!" << endl;

    string player_choice;
    bool result = false;
    while (result == false) {
        cout << "Choose direction of spy's next move:_  ";
        getline(cin, player_choice);
        //check to make sure one of the options has been chosen
        if (0 == compareStrings(player_choice, "abort"))
        {
            // cout << "Game aborted by player!" << endl;      // Abort
            result = true;
            return player_choice;
        }

        else if (0 == compareStrings(player_choice, "w")) // W
        {
            result = true;
        }

        else if (0 == compareStrings(player_choice, "s")) // S
        {
            result = true;
        }

        else if (0 == compareStrings(player_choice, "a")) // A
        {
            result = true;
        }

        else if (0 == compareStrings(player_choice, "d")) // D
        {
            result = true;
        }

        else
        {
            cout << "Invalid input! Choose \"W\", \"S\", \"A\", or \"D\"." << endl;
            cout << "Or, choose \"Abort\", to end the game." << endl;


        }
    }
    return player_choice;
}
/*

######## 8 across; 6 down
#    v #   guard position (6,5); wall positions (1,5), (8,5)
#>  #  #   guard position (2,4); wall positions (1,4), (5,4), (8,4)
#   #  #   wall positions (1,3), (5,3), (8,3)
#@  # $#   spy position (2, 2); goal position (7,2); wall positions (1,2), (5,2), (8,2)
########

use a vector for each row with ability to fill '#'
int n = 8;
char wall_char = '#';
vector<char> wall_vector(n, wall_char);

        cout << "###########" << endl;
        cout << "#    v    #" << endl;
        cout << "#>  #     #" << endl;
        cout << "#   #    <#" << endl;
        cout << "#   #     #" << endl;
        cout << "#@  #    $#" << endl;
        cout << "###########" << endl;

        cout << "########" << endl;
        cout << "#    v #" << endl;
        cout << "#>  #  #" << endl;
        cout << "#   #  #" << endl;
        cout << "#@  # $#" << endl;
        cout << "########" << endl;

        //init spy
        Spy spy(2, 2, '@');

        //init goal; goal is stationary
        //int goal_arr[2]; // permanent position of goal
        //goal_arr[0] = 7; // x == 7
        //goal_arr[1] = 2; // y == 2
        //char goal_icon ='$';
        //g1.get_x();
        Goal goal(7, 2, '@');
        init guards
        Guard g1(2, 4, '>');
        Guard g2(6, 5, 'v');
        init guards
        Guard g1(2, 5, '>');
        Guard g2(6, 7, 'v');
        Guard g3(7, 4, '<');

        //init spy
        Spy s1(2, 2, '@');

        //init goal; goal is stationary
        //int goal_arr[2]; // permanent position of goal
        //goal_arr[0] = 10; // x == 10
        //goal_arr[1] = 2;  // y == 2
        //const char goal_icon ='$';

        Goal goal(10, 2, '$');
        // char testc = goal.getGoalIcon();
        // cout << "test: here is the goal icon: " << testc << endl;

Every turn, the player can move one step in the four cardinal directions, by typing W (up), A (left), S (down), or D (right).
If the player attempts to move into a wall, the move will fail, and the player may try again without having spent their turn.
If the player attempts to move into a guard, they will lose. If the player moves into the goal, they will win.




*/