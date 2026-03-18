override SRC_DIR := srcs

override FORM_SRC := \
	main \
	identify \
	generate \
	Base \

override SRCS := $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(FORM_SRC)))
