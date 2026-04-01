import pycglib as pg

a = (0, 0)
b = (3, 4)

print(pg.squared_distance(a, b))  # Should print 25.0

import sys
import os

# ============================================================
# WHAT IS THIS FILE?
# This is the only file you interact with daily.
# It imports the compiled CGAL module and calls CGAL functions
# as if they were normal Python functions.
# You never need to touch any C++ file to use CGAL here.
# ============================================================

# ============================================================
# WHEN TO RUN THIS FILE?
# Every time you want to run your CGAL code:
#     python main.py
#
# If you changed any C++ file before running this,
# make sure to run python setup.py first to rebuild.
# ============================================================

# ============================================================
# HOW TO ADD A NEW FUNCTION CALL?
# Step 1: Write the function in original/your_file.cpp
# Step 2: Declare and expose it in cgal_wrapper.cpp
# Step 3: Add the .cpp file to CMakeLists.txt
# Step 4: Run python setup.py
# Step 5: Call the function here like any normal Python function
#         Example: result = pg.your_function(args)
# ============================================================

# --------------------------------------------------------
# PATH SETUP
# Tells Python where to find the compiled .pyd module.
# The .pyd file is located in build/Release/ after setup.py
# is run. Without this line, Python cannot find pg.
# DO NOT change this line.
# --------------------------------------------------------
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "build", "Release"))

# --------------------------------------------------------
# IMPORT THE CGAL MODULE
# This imports the compiled pg.pyd module.
# If this fails, make sure you have run python setup.py first.
# --------------------------------------------------------

# --------------------------------------------------------
# CALL CGAL FUNCTIONS
# Call your CGAL functions here just like normal Python.
# Values are passed from Python → wrapper → C++ → CGAL
# and the result comes back to Python automatically.
#
# FORMAT:
#   result = pg.function_name(arg1, arg2, ...)
#
# Add more function calls below as you add more CGAL functions.
# --------------------------------------------------------

# Calls run_distance() from original/distance.cpp
# Passes two points p(0, 0) and q(3, 4)
# Returns the squared distance between them
result = pg.run_distance(0, 0, 3, 4)

# Print the result
# Expected output: 25.0  (because 3² + 4² = 25)
print(result)

## Run:
# Remove-Item -Recurse -Force build
# python setup.py
# python main.py


print("====================POINTTS========================================")
# Replicating the CGAL tutorial example
p1 = pg.Point2(1.0, -1.0)
p2 = pg.Point2(4.0, 3.0)
v1 = pg.Vector2(-1, 10)

v2 = p2 - p1        # (3, 4)
v1 = v1 + v2        # (2, 14)
p3 = p2 + v1 * 2    # (8, 31)

print(f"v2: {v2}")          # Vector2(3.0, 4.0)
print(f"v1 after add: {v1}")# Vector2(2.0, 14.0)
print(f"p3: {p3}")          # Point2(8.0, 31.0)

# Assertions so you know immediately if something breaks
assert v2.x == 3.0  and v2.y == 4.0,  f"v2 wrong: {v2}"
assert v1.x == 2.0  and v1.y == 14.0, f"v1 wrong: {v1}"
assert p3.x == 8.0  and p3.y == 31.0, f"p3 wrong: {p3}"

# scalar * vector (tests __rmul__)
v3 = 3 * pg.Vector2(1.0, 2.0)
assert v3.x == 3.0 and v3.y == 6.0, f"rmul wrong: {v3}"

# zero vector
v_zero = pg.Vector2(0, 0)
p_moved = pg.Point2(5.0, 5.0) + v_zero
assert p_moved.x == 5.0 and p_moved.y == 5.0, f"zero vector wrong: {p_moved}"

# negative coordinates
p_neg = pg.Point2(-3.0, -4.0)
p_pos = pg.Point2(3.0, 4.0)
v_neg = p_neg - p_pos   # (-6, -8)
assert v_neg.x == -6.0 and v_neg.y == -8.0, f"negative coords wrong: {v_neg}"

print("All tests passed.")
print()




print("=============ORIENTATION=============================")

p1 = pg.Point2(0.0, 0.0)
p2 = pg.Point2(1.0, 0.0)
p3 = pg.Point2(0.0, 1.0)

result = pg.orientation(p1, p2, p3)

# Full result as string
print(result)                   # Left turn

# Boolean checks
print(result.left_turn())       # True
print(result.right_turn())      # False
print(result.collinear())       # False

# Right turn case
p4 = pg.Point2(0.0, -1.0)
r2 = pg.orientation(p1, p2, p4)
print(r2)                       # Right turn
print(r2.right_turn())          # True

# Collinear case
p5 = pg.Point2(2.0, 0.0)
r3 = pg.orientation(p1, p2, p5)
print(r3)                       # Collinear
print(r3.collinear())           # True

# Assertions
assert result.left_turn()  == True
assert r2.right_turn()     == True
assert r3.collinear()      == True
print("All orientation tests passed.")
print()



print("=================SEGMENT====================================")

p1 = pg.Point2(0.0, 0.0)
p2 = pg.Point2(3.0, 4.0)
s  = pg.Segment2(p1, p2)

# Operations
print(s.source())           # Point2(0.0, 0.0) (Use .x, .y to extract value)
print(s.target())           # Point2(3.0, 4.0) (Use .x, .y to extract value)
print(s.min())              # Point2(0.0, 0.0) (Use .x, .y to extract value)
print(s.max())              # Point2(3.0, 4.0) (Use .x, .y to extract value)
print(s.vertex(0))          # Point2(0.0, 0.0) (Use .x, .y to extract value)
print(s.vertex(1))          # Point2(3.0, 4.0) (Use .x, .y to extract value)
print(s[0])                 # Point2(0.0, 0.0) (Use .x, .y to extract value)
print(s.squared_length())   # 25.0
print(s.direction())        # Direction2(3.0, 4.0)
print(s.direction().dx)
print(s.direction().dy)
print(s.to_vector())        # Vector2(3.0, 4.0) (Use .x, .y to extract value)
print(s.opposite())         # Segment2((3.0, 4.0), (0.0, 0.0))
opp = s.opposite()
print(opp.source().x, opp.source().y)    # 3.0, 4.0
print(opp.target().x, opp.target().y)    # 0.0, 0.0
print(s.supporting_line())  # Line2(a=..., b=..., c=...)
line = s.supporting_line()
print(line.a)    # float
print(line.b)    # float
print(line.c)    # float

# Predicates
print(s.is_degenerate())    # False
print(s.is_horizontal())    # False
print(s.is_vertical())      # False
print(s.has_on(cg.Point2(1.5, 2.0)))        # True
print(s.collinear_has_on(cg.Point2(1.5, 2.0))) # True

# Miscellaneous
print(s.bbox())             # Bbox2(0.0, 0.0, 3.0, 4.0)

# Equality
s2 = cg.Segment2(p1, p2)
print(s == s2)              # True
print(s != s2)              # False

# Assertions
assert s.squared_length() == 25.0
assert s.is_degenerate()   == False
assert s.is_horizontal()   == False
assert s.is_vertical()     == False
assert s == s2
print("All Segment2 tests passed.")
