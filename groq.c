#include <math.h>
#include <mlx.h>

#define WIDTH 640
#define HEIGHT 480
#define FOV 60
#define HALF_FOV (FOV / 2)
#define NEAR 0.1
#define FAR 100
#define MAP_WIDTH 16
#define MAP_HEIGHT 16

typedef struct s_point {
    float x, y;
} t_point;

t_point dir = {0, 0};
t_point plane = {0, 0};
t_point ray_dir[WIDTH];
t_point map;
int map_data[MAP_HEIGHT][MAP_WIDTH];

void	my_mlx_pixel_put(t_point *img, int x, int y, int color)
{
    img->x = x;
    img->y = y;
    mlx_pixel_put(img->x, img->y, color);
}

void	cast_rays(t_point *img)
{
    float angle;
    int x;

    x = 0;
    angle = dir.x - FOV / 2 + 0.5;
    while (x < WIDTH)
    {
        ray_dir[x].x = cos(angle * M_PI / 180);
        ray_dir[x].y = sin(angle * M_PI / 180);
        // Cast ray here
        // Calculate distance to the wall
        // Draw the ray
        x++;
        angle += FOV / WIDTH;
    }
}

int	main(void)
{
    t_point *img;
    int x;

    mlx_window_size(mlx_init(), WIDTH, HEIGHT, "Raycasting");
    img = mlx_new_image(mlx_init(), WIDTH, HEIGHT);
    cast_rays(img);
    x = 0;
    while (x < WIDTH)
    {
        my_mlx_pixel_put(img, x, HEIGHT / 2, 0xFF0000);
        x++;
    }
    mlx_put_image_to_window(mlx_init(), mlx_new_window(mlx_init(), WIDTH, HEIGHT, "Raycasting"), img, 0, 0);
    mlx_hook(mlx_get_window(img, 0), 2, 1L << 0, key_press, NULL);
    mlx_loop(mlx_init());
    return (0);
}
