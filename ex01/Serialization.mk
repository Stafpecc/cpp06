override SRC_DIR := srcs

override FORM_SRC := \
	main \
	Serialization \

override SRCS := $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(FORM_SRC)))
