#include "cub3d.h"

int check_extension(t_cup3D *cub)
{
    int i = 0;
    while (cub->file_name[i])
        i++;
    if (cub->file_name[i-4] != '.' || cub->file_name[i-3] != 'b' || \
    cub->file_name[i-2] != 'u' || cub->file_name[i-1] != 'c' || i < 4)
        return 0;
    else
        return 1;
}

int main(int argc, char **argv)
{
    t_cub3D *cub;

    if (argc == 2)
    {
        cub = ft_calloc(1, sizeof(t_cub3D));
        (void)argc;

        if(!cub)
        {
            perror("Allocation error!");
            return 1;
        }

        cub->file_name = calloc(1, ft_strlen(argv[1]) * sizeof(char));
        cub->file_name = argv[1];
        printf("%d", check_extension(cub->file_name));
    }

}