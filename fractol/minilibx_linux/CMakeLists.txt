cmake_minimum_required(VERSION 3.15)
project(minilibx C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(minilibx
        test/main.c
        test/new_win.c
        mlx.h
        mlx_clear_window.c
        mlx_destroy_image.c
        mlx_destroy_window.c
        mlx_expose_hook.c
        mlx_flush_event.c
        mlx_get_color_value.c
        mlx_get_data_addr.c
        mlx_hook.c
        mlx_init.c
        mlx_int.h
        mlx_int_anti_resize_win.c
        mlx_int_do_nothing.c
        mlx_int_get_visual.c
        mlx_int_param_event.c
        mlx_int_set_win_event_mask.c
        mlx_int_str_to_wordtab.c
        mlx_int_wait_first_expose.c
        mlx_key_hook.c
        mlx_lib_xpm.c
        mlx_loop.c
        mlx_loop_hook.c
        mlx_mouse_hook.c
        mlx_new_image.c
        mlx_new_window.c
        mlx_pixel_put.c
        mlx_put_image_to_window.c
        mlx_rgb.c
        mlx_string_put.c
        mlx_xpm.c)
