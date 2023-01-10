include_directories(headers)

add_library(ulistmodel STATIC
    headers/commonlistitem.h
    commonlistitem.cpp
    headers/commonlistmodel.h
    commonlistmodel.cpp
)

target_link_libraries(ulistmodel PRIVATE Qt${QT_VERSION_MAJOR}::Core)
