add_definitions(-DWANT_DEPRECATED_KRESOURCE_API)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

########### next target ###############

set(testresources_SRCS testresources.cpp)

kde4_add_unit_test(testresources TESTNAME kresources-testresources ${testresources_SRCS})

target_link_libraries(testresources ${KDE4_KDECORE_LIBS} ${KDE4_KDEUI_LIBS} kresources)

########### next target ###############

set(idmappertest_SRCS idmappertest.cpp)

kde4_add_unit_test(idmappertest TESTNAME kresources-idmappertest ${idmappertest_SRCS})

target_link_libraries(idmappertest
  ${KDE4_KDECORE_LIBS}
  ${QT_QTTEST_LIBRARY}
  ${QT_QTGUI_LIBRARY}
  kresources
)
