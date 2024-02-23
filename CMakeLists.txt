cmake_minimum_required(VERSION 3.8)

project(hw-009  VERSION 1.0
                DESCRIPTION "homework-009"                
                LANGUAGES CXX)

#target_compile_features(hw-009 PUBLIC cxx_std_17)


add_executable(hw-009  src/main.cpp)

set_target_properties(hw-009  PROPERTIES
                              CXX_STANDARD_REQUIRED ON
                              RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_include_directories(hw-009 PUBLIC library)

               
 























if (MSVC)
   target_compile_options(hw-009 PUBLIC /W4 /WX)
 else ()
   target_compile_options(hw-009 PUBLIC 
#                                        -Wall
#                                        -Wextra
#                                        -Werror
#                                        -pedantic
#                                        -g
#                                        -fsanitize=thread
#                                        -fsanitize=address
#                                        -fsanitize=undefined
                                        )

   target_link_options(hw-009 PUBLIC    
#                                        -fsanitize=thread
#                                        -fsanitize=address
#                                        -fsanitize=undefined
                                        )
  endif()