cmake_minimum_required(VERSION 3.21)
project(bl-stm32f446 LANGUAGES C ASM)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

add_executable(${PROJECT_NAME})
add_subdirectory(cmake/stm32cubemx)
include(cmake/soes.cmake)

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/external/bl-stm32f4xx-ecat/stm32f446/STM32F446RETX_FLASH.ld")
target_link_options(${PROJECT_NAME} PRIVATE
    "-T${LINKER_SCRIPT}"
    --specs=nosys.specs
    -Wl,-z,max-page-size=8
)
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY LINK_DEPENDS "${LINKER_SCRIPT}")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.bin
    VERBATIM
)
