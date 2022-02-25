TARGET		= videoe

SRCDIR		= src
OBJDIR		= objects

CXXFILES	= $(wildcard $(SRCDIR)/*.cc)

CXXFLAGS	= -g -O2 -std=c++20
LDFLAGS		= -Wl,--gc-sections -mwindows

ifeq  ($(shell uname),Linux)

CXXFLAGS += -Iports/linux
LDFLAGS = -Wl,--gc-sections $(shell wx-config-gtk3 --libs)
CXXFLAGS += $(wildcard ports/linux/src/*.c) $(shell wx-config-gtk3 --cxxflags)

endif

OBJFILES	= $(patsubst %.cc,$(OBJDIR)/%.o,$(notdir $(CXXFILES)))

all: $(TARGET)

clean:
	@rm *.exe
	@rm -rf $(OBJDIR)

re: clean all

$(OBJDIR)/%.o: $(SRCDIR)/%.cc $(SRCDIR)/$(TARGET).h
	@echo $<
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	@g++ $(CXXFLAGS) -c -o $@ $<

$(TARGET): $(OBJFILES)
	@echo linking...
	@g++ $(LDFLAGS) -o $@ $^