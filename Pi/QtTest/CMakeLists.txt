cmake_minimum_required(VERSION 3.5)

project(QtTest)

# Qt5 위젯 라이브러리를 찾습니다.
find_package(Qt5 COMPONENTS Widgets Core Network REQUIRED)

# MOC 파일 자동 생성 설정
set(CMAKE_AUTOMOC ON)

# src 폴더 내의 소스 파일을 컴파일 대상으로 추가
file(GLOB MAIN src/main.cpp src/menuButton.cpp src/menuList.cpp src/HeaderWidget.cpp src/touchButton.cpp)
file(GLOB CLIENT src/client.cpp)
file(GLOB SERVER src/server.cpp)
#file(GLOB WEB src/webTest.cpp)

# test와 client 실행 파일을 생성합니다.
add_executable(main ${MAIN})
add_executable(server ${SERVER})
add_executable(client ${CLIENT})
#add_executable(web ${WEB})

# Qt5 위젯 라이브러리와 연결합니다.
target_link_libraries(main Qt5::Widgets)
#target_link_libraries(web Qt5::Core Qt5::Network)