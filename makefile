DIRs = weather_textfile edit_textfile main
.PHONY: all clean

all:
	@for d in $(DIRs); \
	do \
		$(MAKE) -C $$d; \
	done

clean:
	@for d in $(DIRs); \
	do \
		$(MAKE) -C $$d clean; \
	done

