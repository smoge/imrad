option(FT_DISABLE_BROTLI ON)
option(FT_DISABLE_BZIP2 ON)
option(FT_DISABLE_HARFBUZZ ON)
option(FT_DISABLE_PNG ON)
option(FT_DISABLE_ZLIB ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/freetype)
