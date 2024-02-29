#include <string>
#include <vector>
#include "Point.h"

using namespace std;

#define PURPLE "\033[35m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m" #define CYAN    "\033[36m"
#define GRAY    "\033[90m"
#define BOLD    "\033[1m"

const string TEST = "🚫";
const string POINT = "💥";
const string SEEK = "🔍";
const string WARN = "⚠️";
const string CART = "🛒";
const string DRUM = "🛢️";
const string WOOD = "🪵";
const string MEAT = "🥩";
const string PLAYER = "🐊";
const string BASKET = "🧺";
const string SPACE = "  ";
static int Delay = 100;

static bool Lost = false;
static vector<vector<string>> Map; 
static vector<vector<string>> Backup; 
static vector<Point> Boxes; 
static vector<Point> Meat; 
static Point Player; 
static int row_limit; 
static int col_limit;
static int score;
