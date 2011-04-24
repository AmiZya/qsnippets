#-------------------------------------------------
#
# Project started by Mohammed Amine ZYAD a.k.a AmiZya on 2011-04-03T21:55:12
#
# This project is licenced under the GPLv3 Licence.
#
# Any questions or suggestions are welcome at <amizya@live.com>
#
#-------------------------------------------------

QT       += core gui sql

TARGET = QSnippets
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    snippetmodel.cpp \
    treeitem.cpp \
    treemodel.cpp \
    colorize.cpp

RESOURCES += data.qrc

HEADERS  += mainwindow.h \
    snippetmodel.h \
    treeitem.h \
    treemodel.h \
    colorize.h \
    LexersHeader.h

FORMS    += mainwindow.ui

LIBS += -lqscintilla2
