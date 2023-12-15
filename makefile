# ----------------------------
# Makefile Options
# ----------------------------

NAME = HW
ICON = icon.png
DESCRIPTION = "Doing things"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)

