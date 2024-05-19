# Sokoban.AI

Sokoban.AI is an AI-based solver for the classic Sokoban game. The solver utilizes various search algorithms to find solutions for different game levels. This project aims to demonstrate the application of artificial intelligence in solving puzzle games efficiently.

## Table of Contents

- [Introduction](#introduction)
- [Game Interface](#game-interface)
- [Showcase](#showcase)
- [Algorithms](#algorithms)
- [Installation](#installation)
- [Contributing](#contributing)


## Introduction

Sokoban is a classic puzzle game where the player pushes boxes (🧺) onto designated Meat/Point locations (🥩). The player (🐊) can only push the boxes and cannot pull them. The objective is to place all the boxes on the storage locations with the least number of moves.

Sokoban.AI implements various search algorithms to solve the Sokoban puzzles. The current implementation supports the following algorithms:
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- A* Search
- Greedy Best-First Search

## Game Interface

The game board is represented using emojis for better visualization:
- `🪵`: Wall
- `  `: Empty space
- `🐊`: Player
- `🥩`: Box
- `🧺`: Storage location

Here is an example of a Sokoban game level:

```
🪵🪵🪵🪵🪵
🪵      🪵
🪵      🪵
🪵🐊  🧺🪵
🪵🪵🪵  🪵
🪵🥩  🧺🪵
🪵    🥩🪵
🪵🪵🪵🪵🪵
```

## Showcase 


https://github.com/Mhijazi16/SOKOBAN.AI/assets/45119497/d98a672e-62c8-474d-a9af-94ab7fe88777



![20240301_23h33m34s_grim](https://github.com/Mhijazi16/SOKOBAN.AI/assets/45119497/40462634-8607-4698-abeb-4cea896ce290)

![20240301_23h31m43s_grim](https://github.com/Mhijazi16/SOKOBAN.AI/assets/45119497/542ee03e-a33b-42a2-9e21-9b21c1afc86b)


## Algorithms

The project includes implementations of the following search algorithms:

### Breadth-First Search (BFS)
BFS explores all possible moves level by level, ensuring the shortest path to the solution.

### Depth-First Search (DFS)
DFS explores as far as possible along each branch before backtracking, which may not find the shortest path but is memory efficient.

### A* Search
A* Search uses heuristics to prioritize moves that appear to lead more directly to the goal, often resulting in faster solutions.

### Greedy Best-First Search
This algorithm expands the most promising node based on a heuristic, potentially finding solutions more quickly but not guaranteeing the shortest path.

## Files

The project consists of the following files:

- `Constants.h`: Defines constants used throughout the project.
- `Game.cpp`: Contains the main game logic and implementation.
- `GamePrinter.h`: Handles the printing of the game board and states.
- `GameContext.h`: Manages the game context and state.
- `HumanStrategy.h`: Implements the strategy for human player moves.
- `ISimulateStrategy.h`: Interface for different simulation strategies.
- `Movement.h`: Defines possible movements in the game.
- `Point.h`: Represents points on the game board.

## Installation

To install and run Sokoban.AI, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/sokoban.AI.git
    ```

2. Navigate to the project directory:
    ```sh
    cd sokoban.AI
    ```

3. Compile the project using a C++ compiler:
    ```sh
    g++ -o sokoban Game.cpp
    ```
## Contributing
Contributions are welcome! Please fork the repository and create a pull request with your changes. Ensure that your code follows the project's coding standards and includes appropriate tests.
Enjoy solving Sokoban with AI! 🐊🥩🧺
