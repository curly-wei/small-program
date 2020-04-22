cmake_minimum_required(VERSION 3.8)

project(myproject)

if (WIN32)
  set (
    CMAKE_TOOLCHAIN_FILE "C:/SDKs/vcpkg/scripts/buildsystems/vcpkg.cmake" 
		CACHE PATH "vcpkg toolchain, fill <vcpkg-DIR>/vcpkg.cmak"
	)  
else ()
endif()

# Instruct CMake to run moc automatically when needed.
set (CMAKE_AUTOMOC ON)

set (CMAKE_AUTOUIC ON)
set (CMAKE_AUTORCC ON)

# Find the Qt libraries for Qt Quick/QML
find_package(Qt5 REQUIRED Qml Quick Gui)

# add the qml.qrc file
qt5_add_resources(qml_QRC src/qml.qrc)

# add source files
set(SOURCE 
	${SOURCE}
	src/main.cpp
)

# Tell CMake to create the helloworld executable
add_executable(helloworld ${SOURCE} ${qml_QRC})

# Use the Qml/Quick modules from Qt 5.
target_link_libraries(helloworld Qt5::Qml Qt5::Quick)
