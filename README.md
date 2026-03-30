# pycglib — CGAL Python Bindings

Python bindings for CGAL — Computational Geometry Algorithms Library, powered by pybind11.

> ⚠️ **Work in Progress:** This package is currently in active development and not intended for public use yet. API may change without notice.

## What is CGAL?
CGAL (Computational Geometry Algorithms Library) is a powerful C++ library that provides
efficient and reliable algorithms for computational geometry. It covers a wide range of topics
including triangulations, mesh generation, spatial searching, boolean operations, and much more.
It is widely used in robotics, GIS, computer graphics, and scientific computing.

## What is Python?
Python is one of the most popular programming languages in the world, known for its simplicity,
readability, and a rich ecosystem of libraries for data science, machine learning, and engineering.

## Why Python for CGAL?
CGAL is written in C++, which makes it fast but harder to access for many developers and researchers
who work primarily in Python. By wrapping CGAL using pybind11, pycglib brings the full power of
CGAL's geometry algorithms to Python — no C++ knowledge required. This makes computational geometry
accessible to a much wider audience.

---

## Installation

### Prerequisites
- Python 3.10 to 3.13 (64-bit)
- Windows x86-64, Linux (glibc 2.28+), or macOS 15.0 (Sequoia)+
- pip 21.0 or later

### Install via pip
```bash
pip install pycglib
```

---

## Verify Installation

Run the following snippet to confirm pycglib is installed and working correctly:
```python
import pycglib as pg

a = (0, 0)
b = (3, 4)
result = pg.squared_distance(a, b)
print(result)  # Expected output: 25.0
```

If you see `25.0`, your installation is successful!

---

## Supported Platforms

| Platform | Supported |
|---|---|
| Windows x86-64 | ✅ |
| Linux (glibc 2.28+) | ✅ |
| macOS 15.0+ (ARM64) | ✅ |
| Windows 32-bit | ❌ |
| Alpine Linux (musllinux) | ❌ |
| macOS < 15.0 | ❌ |

## Supported Python Versions

| Python Version | Supported |
|---|---|
| 3.10 | ✅ |
| 3.11 | ✅ |
| 3.12 | ✅ |
| 3.13 | ✅ |
| < 3.10 or > 3.13 | ❌ |

---

## Links
- [PyPI](https://pypi.org/project/pycglib/)
- [GitHub](https://github.com/armukilan/pycglib)
- [Issues](https://github.com/armukilan/pycglib/issues)
- [CGAL Official Website](https://www.cgal.org/)