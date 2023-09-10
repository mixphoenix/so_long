#include  "so_long.h"


t_player_pos    ft_get_player_pos(char **lines)
{
    t_player_pos pos;
    int i;
    int j;

    i = -1;
    while (lines[++i])
    {
        j = 0;
        while(lines[i][j])
        {
            if (lines[i][j] == 'P')
            {
                pos.i = i;
                pos.j = j;
            }
            j++;
        }
    }
    return (pos);
}