# 🎮 Multiplayer Reversi (Othello) in C

A 3-player extended variant of the classic strategy board game **Reversi (Othello)**, implemented entirely in pure C[cite: 1]. This project demonstrates core programming concepts including 2D array manipulation, multi-directional search algorithms, and game loop state management[cite: 1].

---

## 🚀 Features

* **3-Player Gameplay:** Custom rules tailored for three dynamic colors/players: Red (`K`), Yellow (`S`), and Blue (`M`)[cite: 1].
* **Dynamic Board Size:** Supports customizable grid layouts from 3x3 up to 23x23[cite: 1].
* **Automated Sandwich & Flip Logic:** Multi-directional (8-way) validation checks and structural flipping mechanics for trapped tokens[cite: 1].
* **Score Evaluation:** Automated end-game validation that counts cell dominance and declares the winner or a tie[cite: 1].

---

## 🛠️ Tech Stack & Concepts

* **Language:** C (C99 Standard)[cite: 1]
* **Concepts Covered:**
  * Multi-directional Vector Arrays (`yon_x` and `yon_y` boundaries)[cite: 1]
  * Matrix-based Game Loop Simulation[cite: 1]
  * Input Validation & Boundary Constraints[cite: 1]

---

## 🎮 How to Play

1. **Setup:** The game starts on your preferred board size with an initial Red (`K`) token placed at the exact center[cite: 1].
2. **Turns:** Players takes turns inputting coordinates in a `row column` format (e.g., `5 4`)[cite: 1].
3. **Valid Moves:** A move is valid if placed in an empty cell adjacent to any existing token on the board[cite: 1].
4. **Flipping Mechanics:** Placing a token traps the opponent's tokens between your newly placed token and an existing token of your color in any of the 8 directions, flipping them to your color[cite: 1].
5. **Winning:** The game concludes when the grid is completely full[cite: 1]. The player with the highest token count wins[cite: 1]!

---

## 💻 Compilation & Execution

You can compile and run this project using any standard C compiler (GCC/Clang):

```bash
# Compile the source code
gcc reversi.c -o reversi_game

# Run the executable
./reversi_game