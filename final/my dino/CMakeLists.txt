project(thegame)

add_executable(thegame thegame.c)

target_link_libraries(thegame SDL2)
target_link_libraries(thegame SDL2_image)
target_link_libraries(thegame SDL2_mixer)
target_link_libraries(thegame SDL2_ttf)