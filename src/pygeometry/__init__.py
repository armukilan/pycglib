# This file makes pygeometry a proper Python package.
# It imports everything from the compiled C++ module
# so users can simply do:
#     import pygeometry as pg
#     pg.squared_distance(a, b)

from .pygeometry_core import *