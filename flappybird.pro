#-------------------------------------------------
#
# Project created by QtCreator 2017-12-13T17:51:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = flappybird
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    ../../../Desktop/FlappyBird/Images/bg.png \
    ../../../Desktop/FlappyBird/Images/bird1.png \
    ../../../Desktop/FlappyBird/Images/bird2.png \
    ../../../Desktop/FlappyBird/Images/bird3.png \
    ../../../Desktop/FlappyBird/Images/gameover.png \
    ../../../Desktop/FlappyBird/Images/ground.png \
    ../../../Desktop/FlappyBird/Images/guid1.png \
    ../../../Desktop/FlappyBird/Images/guid2.png \
    ../../../Desktop/FlappyBird/Images/guid3.png \
    ../../../Desktop/FlappyBird/Images/medal0.png \
    ../../../Desktop/FlappyBird/Images/medal1.png \
    ../../../Desktop/FlappyBird/Images/medal2.png \
    ../../../Desktop/FlappyBird/Images/pipe1.png \
    ../../../Desktop/FlappyBird/Images/pipe2.png \
    ../../../Desktop/FlappyBird/Images/rank.png \
    ../../../Desktop/FlappyBird/Images/replay.png \
    ../../../Desktop/FlappyBird/Images/scoreboard.png

RESOURCES += \
    image/image.qrc \
    image.qrc
