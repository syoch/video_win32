TARGET		= videoe

SRCDIR		= src
OBJDIR		= objects

CXXFILES	= $(wildcard $(SRCDIR)/*.cc)
OBJFILES	= $(patsubst %.cc,$(OBJDIR)/%.o,$(notdir $(CXXFILES)))

CXXFLAGS	= -g -O2 -std=c++20
LDFLAGS		= -Wl,--gc-sections -mwindows

ifeq  ($(shell uname),Linux)

CXXFLAGS += -Iports/linux

endif

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