#
# Cross Platform Makefile
# Compatible with Ubuntu 14.04.1 and macOS

OBJS = cimgui.o
OBJS += ./imgui/imgui.o
OBJS += ./imgui/imgui_draw.o
OBJS += ./imgui/imgui_demo.o
OBJS += ./imgui/imgui_tables.o
OBJS += ./imgui/imgui_widgets.o
OBJS += ./imgui/backends/imgui_impl_sdl.o
OBJS += ./imgui/backends/imgui_impl_opengl3.o

CXXFLAGS=-O2 -fno-exceptions -fno-rtti

UNAME_S := $(shell uname -s)

AR := ar -rc

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"

	OUTPUTNAME = cimgui.so
	CXXFLAGS += -I./imgui/
	CXXFLAGS += -Wall
	CXXFLAGS += -shared -fPIC
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(UNAME_S), Darwin) #APPLE
	ECHO_MESSAGE = "macOS"

	OUTPUTNAME = cimgui.dylib
	CXXFLAGS += -I/usr/local/include -I./imgui/
	CXXFLAGS += -Wall
	LINKFLAGS = -dynamiclib
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(OS), Windows_NT)
	ECHO_MESSAGE = "Windows"

	OUTPUTNAME = cimgui.dll
	CXXFLAGS += -I./imgui/
	CXXFLAGS += -Wall
	CXXFLAGS += -shared
	LINKFLAGS = -limm32
	CFLAGS = $(CXXFLAGS)
endif

CXXFLAGS += `sdl2-config --cflags` -DIMGUI_IMPL_API="extern \"C\""
CFLAGS += `sdl2-config --cflags` -DIMGUI_IMPL_API="extern \"C\""
LINKFLAGS += `sdl2-config --libs`

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all:$(OUTPUTNAME)
	@echo Build complete for $(ECHO_MESSAGE)

static:$(OBJS)
	$(AR) libcimgui.a $(OBJS)

$(OUTPUTNAME):$(OBJS)
	$(CXX) -o $(OUTPUTNAME) $(OBJS) $(CXXFLAGS) $(LINKFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OUTPUTNAME)

re: fclean all

.PHONY: all clean fclean re static
