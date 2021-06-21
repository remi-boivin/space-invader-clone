# Target Makefile

include space_invaders.var.mk

.PHONY: all clean

all: $(OUTFILE)

$(OUTFILE): $(OBJ) | $(OUTDIR)
	$(CXX) -o $@ $(OBJ) $(LIBDIRS) $(LIBS) $(LINKFLAGS)

$(INTDIR)/%.o: %.cpp | $(INTDIR)
	$(CXX) -o $@ -c $< -MMD -MP $(CXXFLAGS) $(INCLUDEDIRS) $(DEFINES)

$(INTDIR):
	@test -d $@ || mkdir -p $@

$(OUTDIR):
	@test -d $@ || mkdir -p $@

-include $(INTDIR)/*.d

# Clean every binary file. Obj files and executables
clean:
	@test -d $(BINDIR) && rm -r $(BINDIR)
