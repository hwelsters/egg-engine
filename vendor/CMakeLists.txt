set( BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE )

# ===========================================
# SDL
# ===========================================
set( SDL_LIBC ON CACHE BOOL "" FORCE )
set( SDL_TEST OFF CACHE BOOL "" FORCE )
add_subdirectory( sdl )
target_link_libraries( ${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2-static )

# ===========================================
# spdlog
# ===========================================
add_subdirectory( spdlog )
target_link_libraries( ${PROJECT_NAME} spdlog::spdlog )