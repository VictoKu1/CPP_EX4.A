# Pandemic - Stage A

*"To practice dealing with global pandemics, we need games"*
[(Bill Gates, 2015)](https://www.ted.com/talks/bill_gates_the_next_outbreak_we_re_not_ready#t-389693).

One of the games created to practice dealing with pandemics is [Pandemic](https://www.zmangames.com/en/products/pandemic/). This is a board game for 2-4 players who play cooperatively to cure diseases and discover treatments.

In this assignment, we implement part of the game rules for a single player.

## Table of Contents

- [Task Description](#task-description)
  - [The Board](#the-board)
  - [The Cards](#the-cards)
  - [The Diseases](#the-diseases)
  - [The Player](#the-player)
  - [Roles](#roles)
- [Solution](#solution)
  - [Project Structure](#project-structure)
  - [Implementation Details](#implementation-details)
  - [Key Classes](#key-classes)
  - [Game Mechanics](#game-mechanics)
  - [Testing Strategy](#testing-strategy)
  - [Build Instructions](#build-instructions)
- [Usage](#usage)
- [Contributing](#contributing)

## Task Description

### The Board

The game board is a world map with 48 cities. Some cities are connected by lines that allow travel between them. You can see the list of cities and their connections in [this image](https://media.wnyc.org/i/1500/900/c/80/1/1537_Pandemic_main.jpg). The cities are divided into four colors - blue, yellow, black, and red - with 12 cities of each color.

The list of cities, colors, and connections is also available in the file [cities_map.txt](cities_map.txt) - you can use it at your discretion (not mandatory). The file was provided by Uri Alperin - thank you very much!

In this assignment, the board is represented by the `Board` class.

### The Cards

There are 48 cards - one card for each city.

City names in the code will be exactly as they appear on the map, without spaces. For example, the name of New York City is `NewYork`. Care must be taken with spelling to prevent compilation errors.

### The Diseases

There are diseases of four colors - blue, yellow, black, and red. Each city may have "disease cubes" of the color corresponding to that city.

In the "Board" class, the following methods must be implemented (see example files):

* Square bracket operator [] - takes a city identifier as a parameter and allows reading and updating the disease level (= number of disease cubes) in that city.
  For example: `board[City::HongKong] = 2` places two red disease cubes in Hong Kong.
* Output operator - displays the board state in some format of your choice. The board state includes:
  * Disease level in each of the cities;
  * Cures discovered so far (see explanation below);
  * Research stations built so far (see explanation below).
* `is_clean` - a boolean method without parameters that returns "true" if and only if the entire board is clean - there are no disease cubes.
* `remove_cures` - a method without parameters that removes all cures discovered so far from the board (see explanation below). This method is intended for writing tests; it never throws an exception and does not need to be checked specially.

### The Player

The player starts the game in one of the cities and receives a number of cards. In each turn, they can perform one of the following actions (see example files):

1. **Drive** - `drive` - moving from the current city to an adjacent city (according to the connection map).
2. **Direct Flight** - `fly_direct` - moving from the current city to a city of any card in their hand. To perform this action, the appropriate card for the city being flown to must be discarded.
3. **Charter Flight** - `fly_charter` - moving from the current city to any city. To perform this action, the appropriate card for the city *they are currently in* must be discarded.
4. **Shuttle Flight** - `fly_shuttle` - if there is a research station in the current city, you can fly to any other city that has a research station.
5. **Build** - `build` - building a research station in the city they are currently in. To perform this action, the appropriate card for the city they are currently in must be discarded.
   * Each city can have at most one research station. If there is already a research station in the current city and the "build" action is performed again, there is no need to throw an exception, and the card remains in the player's hand.
6. **Discover Cure** - `discover_cure` - discovering a cure for a disease of a specific color. To perform this action, you must be in a city that has a research station and discard 5 cards of the disease's color. The color of the city you are in does not matter.
   * Each disease has one cure. If a cure for a disease has already been discovered and the "discover cure" action is performed again for the same disease, there is no need to throw an exception, and the cards remain in the player's hand.
7. **Treat Disease** - `treat` - removing one disease cube from the city you are currently in (reducing the disease level by 1).
   * If a cure for the disease of the city's color has already been discovered, then the "treat disease" action removes all disease cubes from the city you are currently in (reducing the disease level to 0).
   * If there is no infection in the city at all (disease level is 0), then the action will throw an exception.

Each action should update the board state and player location accordingly. If the action is not legal, an appropriate exception should be thrown.

Additionally, the following methods must be implemented:

* `role` - a function that returns the player's role (see list of roles below), for display purposes.
* `take_card` - taking any city card. This action simulates the process where the player receives cards from the deck at the beginning of the game or during it.
  * There is only one card of each city, so if the `take_card` action is performed on a card that is already in the player's hand, there will be no change in the player's state.
  * There is no need to check the validity of this method. In particular: there is no need to check that the card is still in the deck, or that a card is not given twice, etc. The method always succeeds.

Notes:
* There can be two or more players in the same city - nothing special happens in this situation.

### Roles

There are different player roles that have special abilities (the abilities are similar but not identical to the original game):

1. **Operations Expert** - `OperationsExpert`: Can perform the "build" action in any city they are in, without discarding an appropriate city card.
2. **Dispatcher** - `Dispatcher`: When they are at a research station, they can perform the "direct flight" action to any city they want, without discarding a city card.
3. **Scientist** - `Scientist`: Can perform the "discover cure" action with only `n` cards (instead of 5), where the parameter `n` is passed in the constructor (in the original game `n=4`).
4. **Researcher** - `Researcher`: Can perform the "discover cure" action in any city - does not need to be at a research station.
5. **Medic** - `Medic`: When they perform the "treat disease" action, they remove all disease cubes from the city they are in, not just one.
   * If a cure for the disease has already been discovered, they automatically remove all disease cubes from any city they are in, even without performing the "treat disease" action.
6. **Virologist** - `Virologist`: Can perform the "treat disease" action, not only in the city they are in, but in any city in the world - by discarding a card of that city.
7. **Gene Splicer** - `GeneSplicer`: Can perform the "discover cure" action with any 5 cards - not necessarily of the disease's color.
8. **Field Doctor** - `FieldDoctor`: Can perform the "treat disease" action not only in the city they are in but in any city adjacent to the city they are in (according to the connection map), without discarding a city card.

In Stage A, you need to write:

* A header file including all required functions (without implementation). Note: The headers need to be correct according to what was learned in lectures - it is recommended to review the material before starting to write.
* Comprehensive tests for all required functions.
  * There is no need to test the output operator - since we did not define the format.
  * There is no need to test illegal states of the `take_card` function.
  * There is no need to test the `remove_cures` function.

Write all necessary files so that the following commands work without errors:

```bash
make demo1 && ./demo1
make demo2 && ./demo2
make test && ./test
```

It is also recommended to run:

```bash
make tidy
make valgrind
```

Do not modify existing files, only add new files.

## Solution

### Project Structure

The project implements a C++ version of the Pandemic board game, focusing on the core game mechanics and player roles. The implementation follows object-oriented design principles with clear separation of concerns.

**Key Files:**
- `Board.hpp/cpp` - Game board representation and disease management
- `Player.hpp/cpp` - Base player class with common functionality
- Role-specific classes (e.g., `OperationsExpert`, `Scientist`, etc.) - Specialized player roles
- `Demo1.cpp`, `Demo2.cpp` - Demonstration programs
- `Test.cpp` - Comprehensive test suite
- `Makefile` - Build configuration

### Implementation Details

**Board Class:**
- Uses operator overloading for intuitive disease cube management
- Implements city-disease mapping with color-coded systems
- Provides methods for cure discovery and research station management
- Includes utility functions for game state validation

**Player Class:**
- Abstract base class defining common player functionality
- Implements all seven core game actions (drive, fly, build, etc.)
- Manages player location and card inventory
- Provides role-based ability system

**Role System:**
Each role extends the base Player class and overrides specific methods to implement their unique abilities:

- **OperationsExpert**: Bypasses card requirement for building
- **Dispatcher**: Enhanced flight capabilities from research stations
- **Scientist**: Reduced card requirement for cure discovery
- **Researcher**: Flexible cure discovery location
- **Medic**: Enhanced disease treatment capabilities
- **Virologist**: Remote disease treatment
- **GeneSplicer**: Flexible cure discovery requirements
- **FieldDoctor**: Adjacent city treatment

### Key Classes

1. **Board**: Manages the game world state including disease levels, research stations, and discovered cures
2. **Player**: Abstract base class for all player types with common game mechanics
3. **City**: Enumeration of all 48 cities with proper naming conventions
4. **Color**: Enumeration of disease colors (blue, yellow, black, red)
5. **Role Classes**: Specialized implementations for each player role

### Game Mechanics

**Movement System:**
- Direct connections between cities
- Multiple flight types (direct, charter, shuttle)
- Role-specific movement enhancements

**Disease Management:**
- Color-coded disease cubes
- Progressive infection levels (0-3 cubes)
- Cure discovery mechanics
- Treatment actions with role variations

**Resource Management:**
- City cards as limited resources
- Research stations as strategic assets
- Cure discovery as win conditions

### Testing Strategy

The project includes comprehensive testing covering:

- **Unit Tests**: Individual method functionality
- **Integration Tests**: Multi-component interactions
- **Edge Cases**: Boundary conditions and error handling
- **Role-Specific Tests**: Unique abilities for each player type
- **Game Flow Tests**: Complete game scenarios

**Testing Tools:**
- `doctest.h` framework for unit testing
- Valgrind for memory leak detection
- Clang-tidy for code quality analysis

### Build Instructions

**Prerequisites:**
- C++20 compatible compiler (clang++-9 recommended)
- Make build system
- Valgrind (for memory checking)
- Clang-tidy (for code analysis)

**Build Commands:**
```bash
# Compile and run demos
make demo1 && ./demo1
make demo2 && ./demo2

# Run test suite
make test && ./test

# Code quality checks
make tidy
make valgrind

# Clean build artifacts
make clean
```

**Build Configuration:**
- C++20 standard with strict error checking
- Warning-as-error compilation
- Memory safety validation
- Code style enforcement

## Usage

1. **Compile the project:**
   ```bash
   make all
   ```

2. **Run demonstrations:**
   ```bash
   ./demo1  # Basic game mechanics
   ./demo2  # Advanced role interactions
   ```

3. **Execute tests:**
   ```bash
   ./test   # Comprehensive test suite
   ```

4. **Code quality checks:**
   ```bash
   make tidy    # Static analysis
   make valgrind # Memory leak detection
   ```

## Contributing

This is an academic project implementing the Pandemic board game. The codebase follows C++ best practices with:

- Clear separation of concerns
- Comprehensive error handling
- Extensive test coverage
- Memory safety considerations
- Modern C++ features (C++20)

For development:
1. Follow the existing code style
2. Add tests for new functionality
3. Ensure all build targets pass
4. Run memory checks before committing
5. Maintain backward compatibility with existing interfaces

---

*This implementation provides a solid foundation for the Pandemic game mechanics, demonstrating object-oriented design principles and modern C++ programming practices.*
