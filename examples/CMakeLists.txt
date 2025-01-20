function(add_sample_app)
  get_filename_component(FILE_BASENAME ${ARGV0} NAME_WE)
  add_executable(${FILE_BASENAME} ${ARGV0})
  target_include_directories(${FILE_BASENAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
endfunction()

set(EXAMPLE_SRCS computenbody.cpp axpy.cpp)

foreach(SRC ${EXAMPLE_SRCS})
  add_sample_app(${SRC})
endforeach()