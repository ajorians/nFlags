CONVERTIMG = ConvertImg
CONVERTFLAGS = --format jpgdata

IMAGE_OBJS = $(patsubst %.bmp,%.h,$(wildcard *.bmp))
IMAGE_JPGS = $(patsubst %.bmp,%.jpg,$(wildcard *.bmp))

%.h: %.bmp
	$(CONVERTIMG) $(CONVERTFLAGS) $^ $@

%.jpg: %.bmp
	convert $^ $@

#all: $(IMAGE_JPGS)
all: $(IMAGE_OBJS)

clean:
	rm -f *.h
