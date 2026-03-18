NAME            := Identify
EXEC            := exec/$(NAME)
OBJS_DIR        := .objs/
EXEC_DIR        := exec/

CC              := c++
CPP      		:= -std=c++98
MAKE            := make
RM              := rm -f
RM_DIR          := rm -rf

CFLAGS          := -Wall -Wextra -Werror
CPPFLAGS		:= -MMD -MP -I includes/
INC             := -I./includes

PURPLE          := \033[1;35m
GREEN           := \033[1;32m
RED             := \033[1;31m
YELLOW          := \033[33m
BOLD_UNDERLINE  := \033[1;4m
RESET           := \033[0m