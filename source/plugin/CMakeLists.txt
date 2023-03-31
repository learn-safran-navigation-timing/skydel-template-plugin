set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB PLUGIN_SRC *.h *.cpp *.ui)

add_library(plugin SHARED
    ${PLUGIN_SRC}
    )

target_link_libraries(plugin PUBLIC
    SkydelPlugin
    )

set_target_properties(plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS plugin RUNTIME DESTINATION ${PLUGIN_INSTALL_DIR})
