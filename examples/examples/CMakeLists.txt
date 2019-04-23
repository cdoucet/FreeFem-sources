FILE(GLOB EDP_FILES *.edp)

if(NOT FF_PLUGIN_TETGEN)
  list(REMOVE_ITEM EDP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Poisson3d.edp
                             ${CMAKE_CURRENT_SOURCE_DIR}/all.edp
                             ${CMAKE_CURRENT_SOURCE_DIR}/makeref.edp
                             ${CMAKE_CURRENT_SOURCE_DIR}/ref.edp
                             ${CMAKE_CURRENT_SOURCE_DIR}/regtests.edp
                             )
endif(NOT FF_PLUGIN_TETGEN)

FOREACH(EDP_FILE ${EDP_FILES})
  GET_FILENAME_COMPONENT(FILENAME ${EDP_FILE} NAME_WE)
  ADD_TEST(NAME ${FILENAME} COMMAND "${CMAKE_BINARY_DIR}/src/FreeFem++" ${EDP_FILE}
                            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/examples/examples)

ENDFOREACH(EDP_FILE)

