# External EtherCAT stack and bootloader, separate from the HAL configuration.
set(SOES_DIR "${CMAKE_SOURCE_DIR}/external/soes")
set(BOOTLOADER_DIR "${CMAKE_SOURCE_DIR}/external/bl-stm32f4xx-ecat")
if(NOT EXISTS "${SOES_DIR}/soes/esc.c" OR NOT EXISTS "${BOOTLOADER_DIR}/user_code.c")
    message(FATAL_ERROR "Missing external sources. Run: git submodule update --init --recursive")
endif()
target_include_directories(stm32cubemx INTERFACE
    "${SOES_DIR}"
    "${SOES_DIR}/soes"
    "${SOES_DIR}/soes/include"
    "${SOES_DIR}/soes/include/sys/gcc"
    "${SOES_DIR}/soes/hal/advr_esc"
    "${BOOTLOADER_DIR}/include"
    "${CMAKE_BINARY_DIR}/generated/include"
)
target_sources(${PROJECT_NAME} PRIVATE
    ${SOES_DIR}/soes/ecat_slv.c
    ${SOES_DIR}/soes/esc.c
    ${SOES_DIR}/soes/esc_coe.c
    ${SOES_DIR}/soes/esc_eep.c
    ${SOES_DIR}/soes/esc_eoe.c
    ${SOES_DIR}/soes/esc_foe.c
    ${SOES_DIR}/soes/hal/advr_esc/esc_hw_lan9252.c
    ${SOES_DIR}/soes/hal/advr_esc/esc_hw_lan9252_spi.c
    ${SOES_DIR}/soes/hal/advr_esc/hal_ec_STM32F4xx.c
    ${BOOTLOADER_DIR}/globals.c
    ${BOOTLOADER_DIR}/objectlist.c
    ${BOOTLOADER_DIR}/flash_utils.c
    ${BOOTLOADER_DIR}/foe_utils.c
    ${BOOTLOADER_DIR}/soes_hook.c
    ${BOOTLOADER_DIR}/user_code.c
    ${BOOTLOADER_DIR}/morse.c
)
# Refresh metadata before each build, without writing into a submodule.
add_custom_target(generate_build_info
    COMMAND ${CMAKE_COMMAND}
        "-DSOURCE_DIR=${CMAKE_SOURCE_DIR}"
        "-DOUTPUT_FILE=${CMAKE_BINARY_DIR}/generated/include/build_info.h"
        -P "${CMAKE_SOURCE_DIR}/cmake/build_info.cmake"
    BYPRODUCTS "${CMAKE_BINARY_DIR}/generated/include/build_info.h"
    VERBATIM
)
add_dependencies(${PROJECT_NAME} generate_build_info)
