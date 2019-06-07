link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(pomodoro main.cpp 
    MainWindow.cpp)

add_custom_command(
        TARGET pomodoro POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/resources/MainWindow.css
                /usr/local/share/pomodoro/MainWindow.css)

target_include_directories(pomodoro PUBLIC ../include)

target_link_libraries(pomodoro 
    ${GTKMM_LIBRARIES}  )