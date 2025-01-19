#include "../inc/mlx.h"

int close_window(int keycode, void *param)
{
    if (keycode == 65307) // ESC keycode
        mlx_destroy_window(param, param);
    return (0);
}

int main()
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 100, 100, "Empty Window");

    mlx_key_hook(window, close_window, window); // Close window on ESC press
    mlx_loop(mlx);

    return (0);
}

