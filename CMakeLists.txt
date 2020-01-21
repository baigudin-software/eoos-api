# EOOS RT API.
#
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2019, Sergey Baigudin, Baigudin Software
# @license   http://embedded.team/license/

target_include_directories(target-eoos
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
)

target_sources(target-eoos
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/source/Allocator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/System.cpp
)
