if(ENABLE_GEOLOCATION)
    if(USE_GRAPHICS STREQUAL "GTK")
        pkg_check_modules(GEOCLUE REQUIRED geoclue)
        set(GEOLOCATION_INCLUDE_DIRS ${GEOCLUE_INCLUDE_DIRS})
        set(GEOLOCATION_LIBRARIES ${GEOCLUE_LIBRARIES})

        set(DEB_PACKAGE_DEPENDS "${DEB_PACKAGE_DEPENDS}, libgeoclue0")
    endif(USE_GRAPHICS STREQUAL "GTK")

    if(USE_GRAPHICS MATCHES "^SDL*")
        set(USE_GEO_SDL TRUE)
        mark_as_advanced(USE_GEO_SDL)
    endif(USE_GRAPHICS MATCHES "^SDL*")
endif(ENABLE_GEOLOCATION)
