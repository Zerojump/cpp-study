project(INHERIT)
message("-- ${PROJECT_NAME} build in " ${CMAKE_CURRENT_BINARY_DIR})

#但要记得在 PROJECT(< project_name>)命令前放置它，否则它将无法工作！
add_library(inheritPrac STATIC scheduler_save.cpp scheduler_save.h scheduler_save_kid.cpp scheduler_save_kid.h key_builder.cpp key_builder.h)
INSTALL(TARGETS inheritPrac ARCHIVE DESTINATION lib)
INSTALL(FILES key_builder.h scheduler_save.h scheduler_save_kid.h DESTINATION include/inheritPrac)