link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(pomodoro main.cpp 
    MainWindow.cpp MainGrid.cpp ClockView.cpp resources.c)

add_custom_command(
        OUTPUT ${CMAKE_SOURCE_DIR}/src/resources.c
        COMMAND glib-compile-resources 
                --sourcedir=${CMAKE_SOURCE_DIR}/resources/ 
                --target=${CMAKE_SOURCE_DIR}/src/resources.c 
                --generate-source ${CMAKE_SOURCE_DIR}/resources/resources.xml 
        )

target_include_directories(pomodoro PUBLIC ../include)

target_link_libraries(pomodoro 
    ${GTKMM_LIBRARIES}  )