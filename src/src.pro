QT = widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        fileSystemProvider.cpp \
        main.cpp \
        stringHelper.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    fileSystemProvider.h \
    mainWindow.h \
    nestJsCliConfigFile.h \
    nestJsControllerFile.h \
    nestJsMainFile.h \
    nestJsModule.h \
    nestJsModuleFile.h \
    nestJsPackageFile.h \
    nestJsProjectCreator.h \
    nestJsProjectFile.h \
    nestJsServiceFile.h \
    nestJsTsConfigBuildFile.h \
    nestJsTsConfigFile.h \
    stringHelper.h
