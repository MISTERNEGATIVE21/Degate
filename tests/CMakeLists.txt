#####################################################################
# This file is part of the IC reverse engineering tool Degate.
#
# Copyright 2008, 2009, 2010 by Martin Schobert
# Copyright 2019-2020 Dorian Bachelot
#
# Degate is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# Degate is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with degate. If not, see <http://www.gnu.org/licenses/>.
#
#####################################################################

project(DegateTests LANGUAGES CXX)

find_package(Catch2 CONFIG REQUIRED)
include(Catch)

#
# The tests source files
#
file(GLOB_RECURSE TEST_SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" LIST_DIRECTORIES false
    "src/*.cc"
    "src/*.cpp"
    "src/*.h"
    "src/*.hpp"
)

#
# Link
#
qt_add_executable(DegateTests ${TEST_SRC_FILES})
target_link_libraries(DegateTests PRIVATE ${LIBS} DegateCore Catch2::Catch2)

#
# Output specifications
#
set_target_properties(DegateTests
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "out/lib"
    LIBRARY_OUTPUT_DIRECTORY "out/lib"
    RUNTIME_OUTPUT_DIRECTORY "out/bin"
)

#
# Automatic Qt deploy
#
# qt_generate_deploy_app_script(
#     TARGET DegateTests
#     OUTPUT_SCRIPT deploy_script
#     NO_UNSUPPORTED_PLATFORM_ERROR
# )
# install(SCRIPT ${deploy_script})

#
# Link Catch2 tests to CTest
#
catch_discover_tests(DegateTests)

#
# Copy test files
#
add_custom_command(
        TARGET DegateTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/tests/tests_files/
        $<TARGET_FILE_DIR:DegateTests>/tests_files/)
