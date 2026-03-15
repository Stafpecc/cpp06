override SRC_DIR := srcs

override FORM_SRC := \
	main \
	ScalarConverter \

override SRCS := $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(FORM_SRC)))
