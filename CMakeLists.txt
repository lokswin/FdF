cmake_minimum_required(VERSION 3.14)
project(fdf_new C)

set(CMAKE_C_STANDARD 99)

add_executable(fdf_new src/main.c src/fdf_draw.c src/fdf_ui.c src/fdf_p_struct.c src/fdf_reform.c src/fdf_new_win.c src/fdf_colors.c)

include_directories (libft/ /usr/local/include .)

find_library(FT ft libft)

find_library(MLX mlx /usr/local/lib)

target_link_libraries(fdf_new LINK_PUBLIC ${FT})

target_link_libraries(fdf_new LINK_PUBLIC ${MLX})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

