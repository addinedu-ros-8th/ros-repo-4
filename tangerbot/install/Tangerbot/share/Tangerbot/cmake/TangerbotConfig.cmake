# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_Tangerbot_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED Tangerbot_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(Tangerbot_FOUND FALSE)
  elseif(NOT Tangerbot_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(Tangerbot_FOUND FALSE)
  endif()
  return()
endif()
set(_Tangerbot_CONFIG_INCLUDED TRUE)

# output package information
if(NOT Tangerbot_FIND_QUIETLY)
  message(STATUS "Found Tangerbot: 0.0.0 (${Tangerbot_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'Tangerbot' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT Tangerbot_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(Tangerbot_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${Tangerbot_DIR}/${_extra}")
endforeach()
