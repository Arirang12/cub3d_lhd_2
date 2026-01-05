The code you've provided **builds its own raycasting logic** rather than using a pre-made or library-provided raycasting function. Let's break it down to clarify how this is achieved.

### Key Points Indicating Custom Raycasting Logic:

1. **Raycasting Initialization**:

   * The `distance_to_wall` function (which is where the core raycasting logic begins) calculates the ray's direction and the player's position:

     ```c
     d->ray_cos = cos(angle);
     d->ray_sin = sin(angle);
     ```

     This sets the ray's direction in both the X and Y axes based on the current angle (`angle`).

2. **Ray Casting in `cast_ray`**:

   * In `cast_ray`, the function continuously increments the ray’s position until it hits a wall or reaches the boundaries of the map:

     ```c
     while (1)
     {
         dis->mx = (int)(d->ray_x / TILE_SIZE);
         dis->my = (int)(d->ray_y / TILE_SIZE);
         // Check for map boundaries and collisions
         if (check_collision(cube, d, dis, rend)) {
             return (sqrtf(dis->dx * dis->dx + dis->dy * dis->dy));
         }
         // Move the ray forward
         d->ray_x += d->ray_cos;
         d->ray_y += d->ray_sin;
     }
     ```

     This is **raycasting in action**: starting from the player's position (`ray_x`, `ray_y`), the ray is cast in the direction of `ray_cos` and `ray_sin` (which are based on the angle) and moved forward by a small step (`d->ray_x += d->ray_cos` and `d->ray_y += d->ray_sin`).

3. **Collision Detection**:

   * The function `check_collision` checks if the ray has hit a wall by comparing the current map position (calculated with the ray's `x` and `y` coordinates) to the map grid:

     ```c
     if (cube->cub->v_map->map[dis->my][dis->mx] == '1'
         || cube->cub->v_map->map[dis->my][dis->mx] == ' '
         || cube->cub->v_map->map[dis->my][dis->mx] == '\0')
     ```

     This checks whether the ray has hit a wall ('1'), empty space (' '), or the boundary of the map (indicated by `'\0'`).

4. **Wall Distance Calculation**:

   * Once the collision is detected, the distance from the ray's origin to the point of collision is calculated:

     ```c
     dis->dx = d->ray_x - dis->base_x;
     dis->dy = d->ray_y - dis->base_y;
     ```

     The distance is then calculated using the Pythagorean theorem:

     ```c
     return (sqrtf(dis->dx * dis->dx + dis->dy * dis->dy));
     ```

5. **Adjusting for Wall Height**:

   * The height of the wall on the screen (`wall_height`) is calculated based on the distance to the wall:

     ```c
     render.wall_height = (WALL_HEIGHT / render.corrected_dist) * (cube->height / 2.0f);
     ```

     This simulates perspective: the farther away the wall, the shorter the projected height on the screen.

### Comparison with Pre-made Raycasting Libraries:

In pre-made raycasting libraries, you'd typically have a function that handles the entire raycasting process (casting rays, checking for collisions, calculating distances, etc.). But here, the **entire raycasting algorithm** is built from scratch in the code you've provided.

### Specific Custom Logic:

* **Ray Direction**: Custom calculation of ray direction using the player's current angle (`cos(angle)` and `sin(angle)`).
* **Ray Movement**: The ray's position is updated incrementally (`ray_x += ray_cos` and `ray_y += ray_sin`).
* **Collision Check**: Custom function to check if the ray has collided with a wall.
* **Distance Calculation**: Custom distance calculation based on the ray's final position.

In conclusion, the code does **not** use a pre-made raycasting library. Instead, it implements its own raycasting logic from scratch, which is common in simple 3D engines like **Cub3D** to keep the engine lightweight and customizable.
