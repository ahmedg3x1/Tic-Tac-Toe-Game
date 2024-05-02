QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game.cpp \
    entry_menu.cpp \
    main.cpp \
    login_window.cpp \
    profile_menu.cpp \
    register_window.cpp

HEADERS += \
    Game.h \
    entry_menu.h \
    login_window.h \
    profile_menu.h \
    register_window.h

FORMS += \
    entry_menu.ui \
    login_window.ui \
    profile_menu.ui \
    register_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
