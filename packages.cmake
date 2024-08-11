include(cmake/CPM.cmake)

CPMAddPackage(
  NAME rapidjson
  GITHUB_REPOSITORY Tencent/rapidjson
  DOWNLOAD_ONLY YES
  GIT_TAG v1.1.0)

CPMAddPackage(
  NAME highfive
  GITHUB_REPOSITORY BlueBrain/highfive
  DOWNLOAD_ONLY YES
  VERSION 2.10.0)

CPMAddPackage(
  NAME dlib
  GITHUB_REPOSITORY davisking/dlib
  VERSION 19.24)

if(rapidjson_ADDED)
  add_library(rapidjson INTERFACE IMPORTED)
  target_include_directories(rapidjson INTERFACE "${rapidjson_SOURCE_DIR}/include")
endif()

if(highfive_ADDED)
  add_library(highfive INTERFACE IMPORTED)
  target_include_directories(highfive INTERFACE "${highfive_SOURCE_DIR}/include")
endif()
