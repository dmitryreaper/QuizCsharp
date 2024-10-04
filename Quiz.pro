QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_CXXFLAGS += -fpermissive

ICON = img/app.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connect.cpp \
    generalwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    quiz.cpp \
    registration.cpp

HEADERS += \
    connect.h \
    generalwindow.h \
    mainwindow.h \
    quiz.h \
    registration.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/tut.jpg \
    img/tutor.png
    img/tut.jpg
    img/app.ico
    db/users.db

RESOURCES += \
    resources.qrc

