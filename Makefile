# Master Makefile

include space_invaders.var.mk

.PHONY: all clean

all:
	@echo "---------[ Building : $(PROJECT) - $(CONFIG) ]---------"
	@$(MAKE) -f "space_invaders.mk"

clean:
	@echo "---------[ Cleaning : $(PROJECT) - $(CONFIG) ]---------"
	@$(MAKE) -f "space_invaders.mk" clean
