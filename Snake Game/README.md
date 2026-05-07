# 🐍 Snake Game

---

# 📋 Requirements

- **Turbo C++ or Borland C++** — required compiler for `graphics.h` support
- **BGI folder at `C:\TC\BGI`** — contains BGI driver files (path can be changed in source)
- **DOS environment or DOSBox emulator** — designed for a 640×480 screen resolution

---

# 🚀 Getting Started

1. Open `SNAKEG.CPP` in Turbo C++
2. Press `Ctrl + F9` to compile and run
3. Verify the BGI path — change `"C:\\TC\\BGI"` in `initgraph()` if needed

---

# 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move Up |
| `S` | Move Down |
| `A` | Move Left |
| `D` | Move Right |

> Reversing into the opposite direction is ignored by the game.

---

# ✨ Features

- Light gray background grid
- Snake head renders eyes based on movement direction
- Triangular tail tip
- Yellow circular food spawns at random positions
- Score tracking — **10 points** per food eaten
- Game Over screen on wall or self-collision

---

# 🧩 Code Structure

| Function | Description |
|----------|-------------|
| `drawGrid()` | Renders the background grid lines |
| `drawSnake()` | Draws the snake body, head (with eyes), and tail |
| `moveSnake()` | Shifts all segments and advances the head |
| `generateFood()` | Picks a random grid-aligned food position |
| `checkCollision()` | Detects wall or self-intersection hits |

---

# 📊 Stats

| Metric | Value |
|--------|-------|
| Lines of code | ~130 |
| Max snake length | 50 |
| Points per food | 10 |
| Screen resolution | 640×480 |
| Move delay | 100ms |

---

# ⚠️ Notes

- Uses `void main()` — non-standard in modern C++. Replace with `int main()` when porting to modern compilers.
- `graphics.h` is specific to Turbo/Borland C++ and is **not compatible** with GCC or MSVC without a wrapper like WinBGIm.
- To run on modern systems, consider using **DOSBox** or porting to a modern graphics library like **SDL2** or **SFML**.
