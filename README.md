# 🎮 Multiplayer Reversi (Othello) in C

A 3-player extended variant of the classic strategy board game **Reversi (Othello)**, implemented entirely in pure C. This project demonstrates core programming concepts including 2D array manipulation, multi-directional search algorithms, and game loop state management.

---

## 🚀 Features

* **3-Player Gameplay:** Custom rules tailored for three dynamic colors/players: Red (`K`), Yellow (`S`), and Blue (`M`).
* **Dynamic Board Size:** Supports customizable grid layouts from 3x3 up to 23x23.
* **Automated Sandwich & Flip Logic:** Multi-directional (8-way) validation checks and structural flipping mechanics for trapped tokens.
* **Score Evaluation:** Automated end-game validation that counts cell dominance and declares the winner or a tie.

---

## 🛠️ Tech Stack & Concepts

* **Language:** C (C99 Standard)
* **Concepts Covered:**
  * Multi-directional Vector Arrays (`yon_x` and `yon_y` boundaries)
  * Matrix-based Game Loop Simulation
  * Input Validation & Boundary Constraints

---

## 🎮 How to Play

1. **Setup:** The game starts on your preferred board size with an initial Red (`K`) token placed at the exact center.
2. **Turns:** Players takes turns inputting coordinates in a `row column` format (e.g., `5 4`).
3. **Valid Moves:** A move is valid if placed in an empty cell adjacent to any existing token on the board.
4. **Flipping Mechanics:** Placing a token traps the opponent's tokens between your newly placed token and an existing token of your color in any of the 8 directions, flipping them to your color.
5. **Winning:** The game concludes when the grid is completely full.The player with the highest token count wins[cite: 1]!

---

## 💻 Compilation & Execution

You can compile and run this project using any standard C compiler (GCC/Clang):

```bash
# Compile the source code
gcc reversi.c -o reversi_game

# Run the executable
./reversi_game