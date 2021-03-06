PROJECT(Gnorasi)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0 FATAL_ERROR)
include(cmake/commonconf.cmake)

################################################################################
# handle target dependencies
################################################################################
IF(VRN_BUILD_GNORASI)
    SET(VRN_BUILD_LIB_VOREENQT ON)
ENDIF()

IF(VRN_BUILD_LIB_VOREENQT OR VRN_BUILD_TESTAPPS OR
       VRN_BUILD_BLASTEST OR VRN_BUILD_ITKWRAPPER)
    SET(VRN_BUILD_LIB_VOREENCORE ON)
ENDIF()

IF(VRN_BUILD_LIB_VOREENCORE)
    SET(VRN_BUILD_LIB_TGT ON)
ENDIF()

################################################################################
# include targets
################################################################################
IF(VRN_BUILD_LIB_TGT)
    ADD_SUBDIRECTORY(ext/tgt)
ENDIF()

IF(VRN_BUILD_LIB_VOREENCORE)
    ADD_SUBDIRECTORY(src/core)
ENDIF()

IF(VRN_BUILD_LIB_VOREENQT)
    ADD_SUBDIRECTORY(src/qt)
ENDIF()

IF(VRN_BUILD_GNORASI)
    ADD_SUBDIRECTORY(apps/voreenve)
ENDIF()

#-------------------------------------------------------------------------------

IF(VRN_BUILD_TESTAPPS AND EXISTS ${VRN_HOME}/apps/tests)
    ADD_SUBDIRECTORY(apps/tests/descriptiontest)
    ADD_SUBDIRECTORY(apps/tests/processorcreatetest)
    ADD_SUBDIRECTORY(apps/tests/processorinittest)
    ADD_SUBDIRECTORY(apps/tests/regressiontest)
    ADD_SUBDIRECTORY(apps/tests/serializertest)
    ADD_SUBDIRECTORY(apps/tests/volumeorigintest)
    IF(VRN_MODULE_OPENCL)
        ADD_SUBDIRECTORY(apps/tests/voreenblastest)
    ENDIF()
ENDIF()

IF(VRN_BUILD_ITKWRAPPER AND EXISTS ${VRN_HOME}/apps/itk_wrapper)
    ADD_SUBDIRECTORY(apps/itk_wrapper)
ENDIF()

      
################################################################################
# copy/install external DLLs
################################################################################
IF(WIN32)
    LIST(REMOVE_DUPLICATES VRN_EXTERNAL_DEBUG_DLLS)
    LIST(REMOVE_DUPLICATES VRN_EXTERNAL_RELEASE_DLLS)

    IF(VRN_COPY_EXTERNAL_DLLS)
        COPY_EXTERNAL_DLLS(VRN_EXTERNAL_DEBUG_DLLS VRN_EXTERNAL_RELEASE_DLLS false)
    ENDIF()
    
    IF(VRN_ADD_INSTALL_TARGET)
        INSTALL(FILES ${VRN_EXTERNAL_DEBUG_DLLS} 
            DESTINATION .
            CONFIGURATIONS Debug
        )
        INSTALL(FILES ${VRN_EXTERNAL_RELEASE_DLLS}
            DESTINATION .
            CONFIGURATIONS Release
        )
    ENDIF()
ENDIF()
