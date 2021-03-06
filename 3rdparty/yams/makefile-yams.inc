include ../ff-flags

# working dirs

YAMS2DIR =$(abs_top_builddir)/3rdparty/yams/freeyams$(yams_VERSION)
EXEDIR = $(abs_top_builddir)/3rdparty/bin
SRCDIR = $(YAMS2DIR)/sourceslib
OBJDIR = $(YAMS2DIR)/objects
ARCDIR = $(YAMS2DIR)/archives
DIRDIR = $(EXEDIR) $(OBJDIR) $(ARCDIR)
INCDIR = -I$(YAMS2DIR)/sourcesnew -I$(abs_top_builddir)/src/libMesh/
LDLDIR = -L$(abs_top_builddir)/3rdparty/lib  -lMesh 
VPATH  = $(SRCDIR)

# objects list
src    = $(wildcard $(SRCDIR)/*.c)
header = $(wildcard $(SRCDIR)/*.h)
objs   = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(src:.c=.o))
prog   = yams2
lib    = $(OBJDIR)/libyams.a

#.SILENT:

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(OPT64)  $(INCDIR) $(CFLAGS) -c $< -o $@

$(EXEDIR)/$(prog):$(DIRDIR) $(objs) 
	echo "#define COMPIL " '"' `date` '"' > $(SRCDIR)/compil.date
	$(CC) -c $(CFLAGS) $(INCDIR) $(SRCDIR)/yams0.c -o $(OBJDIR)/yams0.o -I../../../src/libMesh/ 
	$(CC) -c $(CFLAGS) $(INCDIR) $(SRCDIR)/../yams.c -I$(SRCDIR)  -o $(OBJDIR)/yams.o -I../../../src/libMesh/ 
	$(AR) $(ARFLAGS) $(lib) $(objs)
	$(CC)  $(LDFLAGS) $(OPT64) $(LDLDIR) $(OBJDIR)/yams.o -o $@ $(lib) -lm -L../../../src/libMesh/ -lMesh $(LIBS)
	$(RANLIB) $(lib)

$(objs):$(header)

$(DIRDIR):
	@[ -d $@ ] || mkdir $@

clean:
	-rm $(objs) $(EXEDIR)/$(prog)

tar:$(DIRDIR)
	tar czf $(ARCDIR)/$(prog).`date +"%Y.%m.%d"`.tgz sources makefile

target: $(EXEDIR)/$(prog)
