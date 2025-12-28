#include "../cub.h"

void    set_pdir2(t_game *game, char c)
{
 if (c == 'E')
                                {
                                        game->player.dirX = 1;
                                        game->player.dirY = 0;
                                        game->player.planeX = 0;
                                        game->player.planeY = game->player.fov;
                                }
                                else if (c == 'W')
                                {
                                        game->player.dirX = -1;
                                        game->player.dirY = 0;
                                        game->player.planeX = 0;
                                        game->player.planeY = -game->player.fov;
                                }
}
void    set_pdir(t_game *game, char c)
{
    //     ft_bzero(&g, sizeof(t_game));
    // ft_bzero(&g.frame, sizeof(t_img));
    ft_bzero(&game->keys, sizeof(t_keys));
       game->rot_speed = ROT_SPEED;
        game->move_speed = MOVE_SPEED;
                                if (c == 'N')
                                {
                                        game->player.dirX = 0;
                                        game->player.dirY = -1;
                                        game->player.planeX = game->player.fov;
                                        game->player.planeY = 0;
                                }
                                else if (c == 'S')
                                {
                                        game->player.dirX = 0;
                                        game->player.dirY = 1;
                                        game->player.planeX = -game->player.fov;
                                        game->player.planeY = 0;
                                }
                                set_pdir2(game, c);
}

void     init_player(t_game *game, char **map)
{
        int     y = 0;
        int     x = 0;
        game->player.fov = tan(FOV_DEG * M_PI / 360.0);
printf("player fov how [%f]==========\n", game->player.fov);
        while (map[y])
        {
                x = 0;
                while (map[y][x])
                {
                        char c = map[y][x];
                        if (map[y][x] == '\r')
                                map[y][x] = '\0';
                        if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
                        {
                                game->player.posX = x + 0.5;
                                game->player.posY = y + 0.5;
                                map[y][x] = '0';
                                set_pdir(game, c);
                                return ;
                        }
                        x++;
                }
                y++;
        }
}