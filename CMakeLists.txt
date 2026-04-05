cmake_minimum_required(VERSION 3.19)
project(A9 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(A9
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    AdoptionRepository.h CSVRepo.h Dog.h Exception.h HtmlRepo.h RepoFile.h Repository.h Service.h UI.h Utils.h Validation.h
    CSVRepo.cpp HtmlRepo.cpp RepoFile.cpp Repository.cpp Service.cpp UI.cpp Utils.cpp
    choosewindow.h choosewindow.cpp choosewindow.ui
    Adopted.csv adopted.html
    adminwindow.h adminwindow.cpp adminwindow.ui
    Dogs.txt
    userwindow.h userwindow.cpp userwindow.ui
    UndoRedo.h
    adoptiontable.h adoptiontable.cpp
)

target_link_libraries(A9
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS A9
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET A9
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
