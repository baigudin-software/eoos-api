# EOOS RT API.
#
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2019, Sergey Baigudin, Embedded Team
# @license   http://embedded.team/license/

target_include_directories(eoos
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(eoos
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/source/Allocator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/System.cpp
)
