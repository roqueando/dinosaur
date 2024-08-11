file(GLOB HEADER_LIST
  CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/**/*.hpp")
file(GLOB SOURCE_LIST
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
)

add_library(${DINOSAUR_LIBRARY_NAME} ${SOURCE_LIST} ${HEADER_LIST})


target_link_libraries (${DINOSAUR_LIBRARY_NAME} dlib::dlib rapidjson highfive)
target_include_directories(${DINOSAUR_LIBRARY_NAME} PUBLIC ../include)

target_compile_features(${DINOSAUR_LIBRARY_NAME} PRIVATE cxx_std_20)
