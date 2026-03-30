# ============================================================
# COMPATIBILITY CHECK
# pycglib requires a modern OS and Python 3.10+
# Unsupported platforms:
#   - Windows 32-bit
#   - Linux with glibc < 2.28 (Ubuntu 18.04 and older,
#     CentOS/RHEL 7 and older, Debian 9 and older)
#   - Alpine Linux (musllinux)
#   - Python < 3.10 or > 3.13
#   - macOS < 15.0 (Sequoia)
# ============================================================
import sys
import platform

# Check Python version
if sys.version_info < (3, 10) or sys.version_info >= (3, 14):
    raise RuntimeError(
        "pycglib requires Python 3.10 to 3.13. "
        f"You are using Python {sys.version}. "
        "Please use a supported Python version."
    )

# Check Windows 32-bit
if sys.maxsize <= 2**32 and platform.system() == "Windows":
    raise RuntimeError(
        "pycglib does not support Windows 32-bit. "
        "Please use a 64-bit Python installation."
    )

# Check OS version on Mac
if platform.system() == "Darwin":
    mac_version = tuple(int(x) for x in platform.mac_ver()[0].split(".")[:2])
    if mac_version < (15, 0):
        raise RuntimeError(
            "pycglib requires macOS 15.0 (Sequoia) or later. "
            f"You are using macOS {platform.mac_ver()[0]}. "
            "Please upgrade your macOS."
        )

# Check Linux glibc version
if platform.system() == "Linux":
    try:
        glibc_version = tuple(int(x) for x in platform.libc_ver()[1].split(".")[:2])
        if glibc_version < (2, 28):
            raise RuntimeError(
                "pycglib requires glibc 2.28 or later. "
                "Supported Linux distributions: Ubuntu 20.04+, "
                "Debian 10+, RHEL 8+, CentOS 8+. "
                f"Your system has glibc {platform.libc_ver()[1]}."
            )
    except Exception:
        pass

# ============================================================
# IMPORT THE COMPILED CGAL MODULE
# If this fails, run: pip install --upgrade pycglib
# ============================================================
try:
    from .pycglib_core import *
except ImportError as e:
    raise ImportError(
        "pycglib could not load the compiled CGAL module. "
        "Your platform may not be supported. "
        "Please check https://github.com/armukilan/pycglib "
        "for the list of supported platforms. "
        f"Original error: {e}"
    )