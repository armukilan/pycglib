cmake_minimum_required(VERSION 3.15)
project(pygeometry)

# ============================================================
# WHAT IS THIS FILE?
# This is the generic build file. It works on any OS,
# any machine, any Python version. No hardcoded paths.
# scikit-build-core automatically handles finding Python.
# CGAL is installed by cibuildwheel before this runs.
# ============================================================

# ============================================================
# FIND REQUIRED PACKAGES
# These are found automatically on any machine.
# No hardcoded paths needed.
# ============================================================

# Find Python automatically - scikit-build-core handles this
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)

# Find pybind11 automatically
find_package(pybind11 CONFIG REQUIRED)

# Find CGAL automatically
# On Windows: installed by vcpkg in GitHub Actions
# On Linux: installed by apt-get in GitHub Actions  
# On Mac: installed by homebrew in GitHub Actions
find_package(CGAL REQUIRED)

# ============================================================
# BUILD THE PYTHON MODULE
# Compiles wrapper.cpp and distance.cpp together into
# a single Python module called pygeometry_core
# Add new .cpp files here as you add more CGAL functions:
# Example:
# pybind11_add_module(pygeometry_core
#     src/pygeometry/wrapper.cpp
#     cgal/distance.cpp
#     cgal/convex_hull.cpp    ← add new files here
# )
# ============================================================
pybind11_add_module(pygeometry_core
    src/pygeometry/wrapper.cpp
    cgal/distance.cpp
)

# ============================================================
# LINK CGAL
# Links the CGAL library into the compiled module
# ============================================================
target_link_libraries(pygeometry_core PRIVATE CGAL::CGAL)

# ============================================================
# INSTALL
# Places the compiled .pyd/.so file inside the
# pygeometry package folder so Python can find it
# ============================================================
install(TARGETS pygeometry_core
    DESTINATION pygeometry
    COMPONENT python_modules
)