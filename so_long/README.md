# so_long
## so_long project is about create a 2D Game
![image](https://github.com/user-attachments/assets/071618c8-8439-417f-9c13-057afd7279a4)

Here's a **README.md** for your **So_long** project:

Your **README.md** is ready! Let me know if you want any modifications. 🚀

A 2D game built with **MiniLibX**. Navigate the map, collect all items, and escape!  

---

## What is so_long?  
**so_long** is a minimalist 2D game where the player (`P`) must collect every item (`C`) on a grid-based map before exiting (`E`). Walls (`1`) define boundaries, and the game enforces rules like:  
- The map must be rectangular and fully enclosed by walls.  
- Exactly **1 player** and **1 exit**, with **≥1 collectible**.  
- The game ends only when all `C` are collected and the player reaches `E`.  

---

## Core Logic  

### Step 1: Map Parsing & Validation  
The game reads a `.ber` map file and verifies:  
1. **Valid characters**: Only `0`, `1`, `P`, `C`, `E` are allowed.  
2. **Boundaries**: The map must be surrounded by walls.  
3. **Components**: Exactly one `P` and `E`, and at least one `C`.  

**Example Valid Map**:  
111111  
1P0001  
1C0E11  
111111  


### Step 2: Graphics Initialization  
**MiniLibX** handles window creation and rendering:  
- Textures (walls, player, exit, collectibles) are loaded as XPM images.  
- The map is drawn tile-by-tile based on the parsed `.ber` file.  

### Step 3: Player Movement  
- **WASD/Arrow Keys** move the player.  
- Collision detection prevents walking through walls (`1`).  
- Each move increments a counter displayed in the terminal.  

### Step 4: Game State Management  
- Collectibles (`C`) are removed from the map when touched.  
- The exit (`E`) only triggers a win if all `C` are collected.  
- Pressing **ESC** or closing the window quits the game.  

---

## Why These Steps?  
1. **Map Validation**: Ensures the game is playable and rule-compliant.  
2. **Texture Rendering**: MiniLibX’s low-level API requires manual image loading and placement.  
3. **Movement Restrictions**: Prevents cheating/glitches by enforcing grid-based movement.  
4. **Win Condition**: Forces full exploration of the map (no skipping collectibles).  

---

## Performance Considerations  
- **Efficient Rendering**: Only redraws updated tiles (not the entire map).  
- **Path Validation**: Optional bonus to check if the exit is reachable (prev impossible maps).  

---

## Final Thoughts  
**so_long** combines simple mechanics with strict rules to create a polished 2D experience. The focus on map validation and clean MiniLibX integration makes it a great introduction to game development fundamentals.  
