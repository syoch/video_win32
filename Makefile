TARGET		= videoe

TOPDIR		?= $(CURDIR)

OBJDIR		:= objects
INCLDIR		:= include
SRCDIR		:= src
SUBDIR		:= Application

CFLAGS		= -g -O2 $(addprefix -I,$(INCLUDES)) $(shell wx-config-gtk3 --cxxflags)
CXXFLAGS	= $(CFLAGS) -std=c++20 -fno-rtti
LDFLAGS		= -Wl,--gc-sections $(shell wx-config-gtk3 --libs)

%.o: %.c
	@echo $(notdir $<)
	@gcc $(CFLAGS) -MMD -MP -MF $*.d -c -o $@ $<

%.o: %.cc
	@echo $(notdir $<)
	@g++ $(CXXFLAGS) -MMD -MP -MF $*.d -c -o $@ $<

ifneq ($(OBJDIR),$(notdir $(CURDIR)))

export OUTPUT	= $(CURDIR)/$(TARGET)
export TOPDIR	= $(CURDIR)
export VPATH	= $(foreach dir,$(SRCDIR),$(CURDIR)/$(dir)) $(foreach dir,$(SUBDIR),$(CURDIR)/$(SRCDIR)/$(dir))

CFILES		= $(foreach dir,$(VPATH),$(notdir $(wildcard $(dir)/*.c)))
CXXFILES	= $(foreach dir,$(VPATH),$(notdir $(wildcard $(dir)/*.cc)))

export OUTPUT	= $(CURDIR)/$(TARGET)
export TOPDIR	= $(CURDIR)
export VPATH	= $(CURDIR)/$(SRCDIR) $(foreach dir,$(SUBDIR),$(CURDIR)/$(SRCDIR)/$(dir)) $(CURDIR)/ports/linux/src
export OFILES	= $(CFILES:.c=.o) $(CXXFILES:.cc=.o)
export INCLUDES	= $(foreach dir,$(INCLDIR),$(CURDIR)/$(dir)) $(CURDIR)/ports/linux/include

all: $(OBJDIR)
	@$(MAKE) --no-print-directory -C $(OBJDIR) -f $(CURDIR)/Makefile

clean:
	@rm -rf $(OBJDIR) $(TARGET).exe

re: clean all

$(OBJDIR):
	@[ -d $@ ] || mkdir -p $@


else

DEPENDS	= $(OFILES:.o=.d)

$(OUTPUT): $(OFILES)
	@echo linking...
	@g++ $(LDFLAGS) -o $@ $^

-include $(DEPENDS)

endif