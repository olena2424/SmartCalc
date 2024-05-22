QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calc.c \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    polish_notation.c \
    qcustomplot.cpp \
    stack.c

HEADERS += \
    graph.h \
    mainwindow.h \
    qcustomplot.h \
    s21_smart_calc.h

FORMS += \
    graph.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    C:/Users/alina/Downloads/QCustomPlot.tar.gz
