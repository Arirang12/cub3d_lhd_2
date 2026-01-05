Perfect — if you’ve got **15 days** left and want a **tight, focused schedule**, here’s an **intensive day-by-day plan** to finish **cub3d**.

> 🧠 Assumption: You're comfortable with C basics, pointers, and can use Makefiles.
> If you're not, let me know and I’ll adjust the plan.

---

## 🗓️ **15-Day Hardcore Cub3D Schedule**

### 🔰 PHASE 1: Setup & Parsing (Day 1–3)

> Goal: Understand project structure, parse `.cub` file, prepare your engine base.

| Day       | Tasks                                                                                                                                                                         |
| --------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Day 1** | 🔹 Set up repository + Makefile<br>🔹 Read subject fully<br>🔹 Understand `.cub` format<br>🔹 Start writing the parser (open, read, split, etc.)                              |
| **Day 2** | 🔹 Finish parser: extract map, player position, textures, floor/ceiling colors<br>🔹 Validate map (closed by walls, only allowed chars)<br>🔹 Print parsed data for debugging |
| **Day 3** | 🔹 Store map in a 2D array<br>🔹 Implement flood-fill or DFS for map validation<br>🔹 Parse player orientation (N, S, E, W)<br>🔹 Set up player struct (pos, dir, plane)      |

---

### 🎮 PHASE 2: Rendering Base & Raycasting (Day 4–7)

> Goal: Render walls using raycasting (the heart of the project).

| Day       | Tasks                                                                                                                                                        |
| --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Day 4** | 🔹 Initialize MiniLibX<br>🔹 Open window<br>🔹 Draw basic 2D map top-down (for debugging only)<br>🔹 Place player on map                                     |
| **Day 5** | 🔹 Implement raycasting loop<br>🔹 Cast rays for each vertical stripe on screen<br>🔹 Use DDA algorithm to detect wall hits                                  |
| **Day 6** | 🔹 Calculate perpendicular wall distance<br>🔹 Calculate line height and start/end points<br>🔹 Render basic walls (gray lines on black background)          |
| **Day 7** | 🔹 Fix fisheye distortion<br>🔹 Add basic movement (WASD)<br>🔹 Add player rotation (left/right arrows)<br>🔹 Clamp movements to avoid walking through walls |

---

### 🧱 PHASE 3: Textures & Colors (Day 8–10)

> Goal: Add realism with textures and floor/ceiling rendering.

| Day        | Tasks                                                                                                                                         |
| ---------- | --------------------------------------------------------------------------------------------------------------------------------------------- |
| **Day 8**  | 🔹 Load textures using MiniLibX (XPM files)<br>🔹 Apply correct texture slice per wall face                                                   |
| **Day 9**  | 🔹 Calculate texture X and Y correctly<br>🔹 Render walls with textures<br>🔹 Fix bugs (fish-eye, wrong texture face, etc.)                   |
| **Day 10** | 🔹 Add floor and ceiling color filling<br>🔹 Ensure it's read from the `.cub` file<br>🔹 Handle edge cases (invalid colors, duplicates, etc.) |

---

### 🚨 PHASE 4: Error Handling & Cleanup (Day 11–13)

> Goal: Finish logic, clean code, validate inputs.

| Day        | Tasks                                                                                                                                                              |
| ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Day 11** | 🔹 Error handling (missing texture, bad map, bad color, etc.)<br>🔹 Invalid map structure (open map, bad chars)<br>🔹 Validate `.cub` file                         |
| **Day 12** | 🔹 Free memory on exit<br>🔹 Handle ESC key to quit<br>🔹 Prevent memory leaks (use Valgrind)                                                                      |
| **Day 13** | 🔹 Organize code into modules:<br>📁 `parsing/`, `raycasting/`, `rendering/`, `utils/`, etc.<br>🔹 Add useful comments<br>🔹 Clean Makefile, remove debugging code |

---

### 🧪 PHASE 5: Final Testing & Bonus (Day 14–15)

> Goal: Polish, add bonuses (if you want), and prepare for submission.

| Day        | Tasks                                                                                                                                                                     |
| ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Day 14** | 🔹 Test on edge cases (invalid maps, textures, inputs)<br>🔹 Run on another machine (1337 Mac?)<br>🔹 Ensure no crash on bad files                                        |
| **Day 15** | 🔹 If all mandatory is 100% working:<br> → Add a minimap (optional)<br> → Add sprite rendering (bonus)<br> → Polish UI<br>🔹 Submit and test with moulinette if available |

---

## 🧰 Optional Starter Structure

```
cub3d/
├── Makefile
├── main.c
├── include/
│   └── cub3d.h
├── src/
│   ├── parsing/
│   ├── rendering/
│   ├── raycasting/
│   ├── events/
│   └── utils/
├── textures/
│   └── wall_north.xpm, ...
└── maps/
    └── test_map.cub
```

---

## 🧠 Want Visuals or Boilerplate?

Let me know if you'd like:

* A diagram of raycasting steps
* A `.cub` file example
* Starter code for:

  * DDA algorithm
  * Map parsing
  * MiniLibX window opening

---

Would you like me to generate a sample `.cub` file and the player struct layout for you next?
