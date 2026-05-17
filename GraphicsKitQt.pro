TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        base.cpp \
        button.cpp \
        imagewiewer.cpp \
        input.cpp \
        main.cpp \
        graphics/graphics.cpp \
        numberinput.cpp \
        statictext.cpp \
        widgets.cpp


INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2.dll

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2_ttf.dll


INCLUDEPATH += $$PWD/SDL2
DEPENDPATH += $$PWD/SDL2

HEADERS += \
    base.hpp \
    button.h \
    imagewiewer.h \
    input.hpp \
    numberinput.hpp \
    statictext.h \
    widgets.hpp

DISTFILES += \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/C10.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/C2.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/C3.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/C4.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/C5.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/C6.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/C7.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/C8.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/C9.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Ca.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Cj.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Ck.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Cq.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/D10.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/D2.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/D3.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/D4.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/D5.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/D6.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/D7.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/D8.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/D9.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Da.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Dj.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Dk.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Dq.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/H10.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/H2.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/H3.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/H4.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/H5.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/H6.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/H7.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/H8.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/H9.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Ha.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Hj.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Hk.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Hq.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/S10.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/S2.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/S3.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/S4.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/S5.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/S6.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/S7.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/S8.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/S9.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Sa.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Sj.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Sk.bmp.kep \
    build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/Sq.bmp.kep
