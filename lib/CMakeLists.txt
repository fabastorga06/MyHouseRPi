#add include to directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

#set the proper macros
set(LIBRARY_NAME myhouserpi)
set(SRC_FILES gpio_handler.c door_handler.c light_handler.c)
set(INCLUDE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/gpio_handler.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/light_handler.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/door_handler.h
)

#add the library
add_library(${LIBRARY_NAME} SHARED ${SRC_FILES} ${INCLUDE_FILES})

#installing the library
install (TARGETS ${LIBRARY_NAME} DESTINATION lib)
install (FILES ${INCLUDE_FILES} DESTINATION include)