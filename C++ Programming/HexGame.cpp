#include <ctime>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum class Player
{
   WHITE,
   BLACK
};
// --------------------------Class Prototypes----------------------------------
class Board
{
private:
   static int direct[6][2];
   static char white;
   static char black;
   static char empty;
   int size;
   string line;
   vector<vector<char>> board;

public:
   Board() {}
   Board(int size) : size(size), board(size, vector<char>(size, '+'))
   {
      line = "\\"; // easier to follow paths
      for (int i = 1; i < size; i++)
         line += " / \\";
   } // matrix presentation looks best for this game
   bool place(int x, int y, Player p);
   bool badMove(int x, int y);
   vector<pair<int, int>> getEmpty();
   bool win(int x, int y);
   Player winner();
   void printBoard();

private:
   bool inBoard(int x, int y);
   void borders(int x, int y, vector<bool> &condition, char side);
   void bfsSearch(vector<pair<int, int>> &start, vector<bool> &condition);
};

class AI // based on montecarlo simulation
{
public:
   static vector<int> generatePermutation(int size);
   static double getWins(Board &board, Player p);
   virtual pair<int, int> next(Board &board, Player p);
};

class Game
{
private:
   Player computer;
   Player player;
   AI robotAI;
   Board board;

public:
   Game() {}
   Game(AI &robotAI) : robotAI(robotAI) {}
   void play();

private:
   void setup();
   void choose();
   bool computerTurn();
   bool playerTurn();
};

// static defintions
int Board::direct[6][2] =
    {
        {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0} // corners
};

char Board::white = 'W';
char Board::black = 'B';
char Board::empty = '+';

// -------------------------------Main Client----------------------------------
int main()
{
   AI gameAI;
   Game hexGame(gameAI);
   srand(time(0));
   hexGame.play();
   return 0;
}

// --------------------------Class Definitions---------------------------------

// checks if placed piece is a legal and in bounds
bool Board::inBoard(int x, int y)
{
   return (x < size && y < size && x >= 0 && y >= 0);
}

// helper for win(), mutates conditionals (2 element vector) to check borders
void Board::borders(int x, int y, vector<bool> &condition, char side)
{
   if (side == black)
   {
      if (y == 0)
         condition[0] = true;
      if (y == size - 1)
         condition[1] = true;
   }
   else
   {
      if (x == 0)
         condition[0] = true;
      if (x == size - 1)
         condition[1] = true;
   }
}

// "places" a piece on the board, assigns cell block to B or W
bool Board::place(int x, int y, Player p)
{
   if (inBoard(x, y) && board[x][y] == empty)
   {
      if (p == Player::BLACK)
         board[x][y] = black;
      else
         board[x][y] = white;
      return true;
   }
   return false;
}

// retracts a badMove (or in my case the random suboptimals)
bool Board::badMove(int x, int y)
{
   if (inBoard(x, y))
   {
      board[x][y] = empty;
      return true;
   }
   return false;
}

// returns all the empty spots on the board, useful for mcts
vector<pair<int, int>> Board::getEmpty()
{
   vector<pair<int, int>> blankSpots;
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
         if (board[i][j] == empty)
            blankSpots.push_back(make_pair(i, j));
   }
   return blankSpots;
}
// Breadth-first search and checks borders() win conditionals
void Board::bfsSearch(vector<pair<int, int>> &start, vector<bool> &condition)
{
   if (start.size() != 0)
   {
      int x = start[0].first;
      int y = start[0].second;
      char side = board[x][y];

      vector<vector<bool>> visited(size, vector<bool>(size));
      queue<pair<int, int>> trace;

      for (auto itr = start.cbegin(); itr != start.cend(); ++itr)
      {
         trace.push(*itr);
         visited[itr->first][itr->second] = true;
      }
      while (!(trace.empty()))
      {
         auto top = trace.front();
         borders(top.first, top.second, condition, side);
         trace.pop();

         for (int i = 0; i < 6; i++)
         {
            int xCursor = top.first + direct[i][0];
            int yCursor = top.second + direct[i][1];
            if (inBoard(xCursor, yCursor) && board[xCursor][yCursor] == side && visited[xCursor][yCursor] == false)
            {
               visited[xCursor][yCursor] = true;
               trace.push(make_pair(xCursor, yCursor));
            }
         }
      }
   }
}

// BFS last registed move (x,y) returns true if path made
bool Board::win(int x, int y)
{
   if (inBoard(x, y) && board[x][y] != empty)
   {

      vector<bool> condition(2, false); // two opposite ends
      vector<pair<int, int>> start(1, make_pair(x, y));

      bfsSearch(start, condition);
      return condition[0] && condition[1];
   }
   return false;
}

// there logically must be one winner so when win condition met use
// BFS to check if black made a path from left to right, if not
// white is necessarily the winner
Player Board::winner()
{
   vector<bool> condition(2, false); // tracks side to side win
   vector<pair<int, int>> start;
   for (int i = 0; i < size; i++)
      if (board[i][0] == black)
         start.push_back(make_pair(i, 0));

   bfsSearch(start, condition);
   return (condition[0] && condition[1]) ? Player::BLACK : Player::WHITE;
}

// printing a board
void Board::printBoard()
{
   if (size <= 0)
      return;

   // start top left
   cout << "  0";
   for (int i = 1; i < size; i++)
      cout << " w " << i; // readability
   cout << endl;

   // print the first line
   cout << "0 " << board[0][0];
   for (int i = 1; i < size; i++)
      cout << "---" << board[0][i];
   cout << endl;

   string indent = "";
   for (int i = 1; i < size; i++)
   {
      indent += ' ';
      cout << indent << "b " << line << endl;
      if (i < 10)
      {
         indent += ' ';
         cout << indent << i << ' ' << board[i][0];
      }
      else
      {
         cout << indent << i << ' ' << board[i][0];
         indent += ' ';
      }

      for (int j = 1; j < size; j++)
         cout << "---" << board[i][j];
      cout << endl;
   }
   cout << "_________________________________________________________" << endl;
}

// play function to handle subfunctions also lots of robot overlord stuff
void Game::play()
{
   cout << "You wish to challenge a computer in Hex? Very well, Let's play!"
        << endl
        << endl;
   while (true)
   {
      setup();
      choose();
      char userIn;
      bool counter = false;

      int turn = (computer == Player::BLACK ? 0 : 1);
      while (!counter)
      {
         turn = !turn;
         if (turn)
            counter = computerTurn();
         else
            counter = playerTurn();
      }

      if (turn == 1)
      {
         cout << "I win! Robots > Mankind!!" << endl;
         cout << "Want to redeem yourself? (y/n) ";
         cin >> userIn;
      }
      else
      {
         cout << "What?!?! How did you win???" << endl;
         cout << "That was a fluke! Let me try again! (y/n) ";
         cin >> userIn;
      }

      if (userIn != 'y' && userIn != 'Y')
         break;
      cin.clear();
   }
   cout << "Shutting down now, come challenge me again!" << endl;
}

// customizable dimensions
// CAREFUL FOR >11 IT GETS SLOW
void Game::setup()
{
   string border(25, '+');

   int dimensions;
   cout << "How big of a board do you want to play on? (5 - 11 recommended): ";
   cin >> dimensions;

   if (dimensions > 0)
   {
      cin.clear();
      board = Board(dimensions);
   }
   else
   {
      cout << "Hey! That's not a positive number! I guess I'll pick 9.\n";
      board = Board(9); // could have while(true) but code expects competency
   }
   cout << "Good! The board is set!\n";
   board.printBoard();
}

// no implementation of PIE RULE yet... stay tuned
void Game::choose()
{
   char side = 'w';

   cout << "Now we need to pick sides. I'll let you pick. (b/w): ";
   cin >> side;
   if (side == 'b' || side == 'B')
   {
      player = Player::BLACK;
      computer = Player::WHITE;
   }
   else if (side == 'w' || side == 'W')
   {
      player = Player::WHITE;
      computer = Player::BLACK;
   }
   else
   {
      cout << "That's not a valid side...not taking this seriously, huh?\n";
      cout << "I guess I'll choose then...I'm player black!" << endl
           << endl;
      player = Player::WHITE;
      computer = Player::BLACK;
   }
   cin.clear();
}

// turns true if AI won otherwise AI turn handler
bool Game::computerTurn()
{
   cout << "My turn! I move: ";
   auto move = robotAI.next(board, computer); // calculate optimal move
   board.place(move.first, move.second, computer);
   cout << move.first << " " << move.second << endl;
   board.printBoard();
   return board.win(move.first, move.second);
}

// returns true if u win otherwise player turn handler
bool Game::playerTurn()
{
   int x, y;
   cout << "Your turn!" << endl;
   while (true)
   {
      cout << "Where are you putting your piece? (x y = ) ";
      cin >> x >> y;
      if (board.place(x, y, player))
         break;
      cout << "You can't do that!" << endl;
   }
   board.printBoard();
   return board.win(x, y);
}

// helper for next()
// all  empty spots on board stored on  permutation
// then rand. empty spot picked and played off of,
// wins are tracked and the win value is then returned.
double AI::getWins(Board &board, Player player)
{
   auto blank = board.getEmpty();
   int winCount = 0;
   vector<int> perm(blank.size());
   for (int i = 0; i < perm.size(); i++)
      perm[i] = i;

   for (int n = 0; n < 3; n++)
   {
      int turn = (player == Player::BLACK ? 0 : 1);
      for (int i = perm.size(); i > 1; i--)
      {
         int swap = rand() % i;
         int temp = perm[i - 1];
         perm[i - 1] = perm[swap];
         perm[swap] = temp; // prand the permutation
      }
      for (int i = 0; i < perm.size(); i++)
      {
         turn = !turn; // easy bool turn tracking
         int x = blank[perm[i]].first;
         int y = blank[perm[i]].second;
         if (turn)
         {
            board.place(x, y, Player::WHITE);
         }
         else
         {
            board.place(x, y, Player::BLACK);
         }
      }
      if (board.winner() == player)
          winCount++;
          cout<< winCount <<endl;
      for (auto itr = blank.begin(); itr != blank.end(); ++itr)
         board.badMove(itr->first, itr->second); // take back rand moves
   }
   return static_cast<double>(winCount) / 2;
}

// montecarlo simulation, with getWins() it finds the
// value of moves by making random permutations and doing simulation moves
// on each and tracks no. wins. The moves are given the no.wins as a move
// value, the best value is the best move.
pair<int, int> AI::next(Board &board, Player p)
{
   auto blank = board.getEmpty();
   double bestMove = 0;
   pair<int, int> move = blank[0];

   for (int i = 0; i < blank.size(); i++)
   {
      int x = blank[i].first;
      int y = blank[i].second;
      board.place(x, y, p);

      double moveValue = getWins(board, p);
      if (moveValue > bestMove)
      {
         move = blank[i];
         bestMove = moveValue;

      }

      board.badMove(x, y);
   }
   return move;
}
