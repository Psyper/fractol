cmake_minimum_required(VERSION 3.15)
project(fractol C)

set(CMAKE_C_STANDARD 99)
find_package(Threads)
#link_libraries(m)
add_executable(fractol minilibx_macos/mlx.h main.c fractol.h initialize.c draw.c fractal.c
        linux_controls.c operations.c ft_strcmp.c ft_putstr.c threads.c)
target_link_libraries(fractol "-L." "-I." mlx m Xext X11 pthread)
#target_link_libraries(fractol  "-framework OpenGL" "-framework AppKit")