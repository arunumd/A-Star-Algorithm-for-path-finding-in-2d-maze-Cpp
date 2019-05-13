.PHONY: clean All

All:
	@echo "----------Building project:[ new - Debug ]----------"
	@"$(MAKE)" -f  "new.mk"
clean:
	@echo "----------Cleaning project:[ new - Debug ]----------"
	@"$(MAKE)" -f  "new.mk" clean
