link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(pomodoro main.cpp 
    MainWindow.cpp)

target_include_directories(pomodoro PUBLIC ../include)

target_link_libraries(pomodoro 
    ${GTKMM_LIBRARIES}  )