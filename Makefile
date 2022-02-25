TARGET		= videoe

TOPDIR		?= $(CURDIR)

OBJDIR		:= objects
INCLDIR		:= include
SRCDIR		:= src
SUBDIR		:= Application

CFLAGS		= -g -O2 -I $(INCLUDES)
CXXFLAGS	= $(CFLAGS) -std=c++20 -fno-rtti
LDFLAGS		= -Wl,--gc-sections -mwindows

%.o: %.c
	@echo $(notdir $<)
	@gcc $(CFLAGS) -MMD -MP -MF $*.d -c -o $@ $<

%.o: %.cc
	@echo $(notdir $<)
	@g++ $(CXXFLAGS) -MMD -MP -MF $*.d -c -o $@ $<

ifneq ($(OBJDIR),$(notdir $(CURDIR)))

CFILES		= $(foreach dir,$(VPATH),$(notdir $(wildcard $(dir)/*.c)))
CXXFILES	= $(foreach dir,$(VPATH),$(notdir $(wildcard $(dir)/*.cc)))

export OUTPUT	= $(CURDIR)/$(TARGET)
export TOPDIR	= $(CURDIR)
export VPATH	= $(CURDIR)/$(SRCDIR) $(foreach dir,$(SUBDIR),$(CURDIR)/$(SRCDIR)/$(dir))
export OFILES	= $(CFILES:.c=.o) $(CXXFILES:.cc=.o)
export INCLUDES	= $(foreach dir,$(INCLDIR),$(CURDIR)/$(dir))

all: $(OBJDIR)

clean:
	@rm -rf $(OBJDIR) $(TARGET).exe

re: clean all

$(OBJDIR):
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) --no-print-directory -C $(OBJDIR) -f $(CURDIR)/Makefile

else

DEPENDS	= $(OFILES:.o=.d)

$(OUTPUT).exe: $(OFILES)
	@echo linking...
	@g++ $(LDFLAGS) -o $@ $^

-include $(DEPENDS)

endif