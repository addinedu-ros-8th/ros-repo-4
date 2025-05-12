# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_admin_gui_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED admin_gui_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(admin_gui_FOUND FALSE)
  elseif(NOT admin_gui_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(admin_gui_FOUND FALSE)
  endif()
  return()
endif()
set(_admin_gui_CONFIG_INCLUDED TRUE)

# output package information
if(NOT admin_gui_FIND_QUIETLY)
  message(STATUS "Found admin_gui: 0.0.0 (${admin_gui_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'admin_gui' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT admin_gui_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(admin_gui_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${admin_gui_DIR}/${_extra}")
endforeach()
