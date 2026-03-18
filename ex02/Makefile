.SILENT:

include config.mk
include Identify.mk

OBJS := $(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

all: $(NAME)
.PHONY: all

$(NAME): Makefile $(OBJS) | $(EXEC_DIR)
	echo "$(PURPLE)Compiling $(NAME) in progress...$(RESET)"
	$(CC) $(CFLAGS) $(CPP) $(CPPFLAGS) -o $(EXEC) $(OBJS)
	echo "$(GREEN)$(EXEC) completed successfully!$(RESET)"

	echo "$(GREEN)"
	echo "┌───────────────────────────────────────────────────────────┐"
	echo "│      Compilation finished successfully! ᕕ(⌐■_■)ᕗ ♪♬       │"
	echo "└───────────────────────────────────────────────────────────┘"
	echo "                      ☆  *    .      ☆"
	echo "                        ∧＿∧   ∩    * ☆"
	echo "                 *  ☆ ( ・∀・)/ ."
	echo "                  .  ⊂      ノ* ☆"
	echo "                ☆ * (つ   ノ  .☆"
	echo "                      (ノ"
	echo "$(RESET)"
.PHONY: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR)
	mkdir -p $(dir $@)
	echo "$(PURPLE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $(CPP) $(CPPFLAGS) -c -o $@ $<
	echo "$(GREEN)$< compiled successfully!$(RESET)"

$(OBJS_DIR):
	echo "$(YELLOW)Creating directory $(OBJS_DIR)...$(RESET)"
	mkdir -p $(OBJS_DIR)
.PHONY: $(OBJS_DIR)

$(EXEC_DIR):
	echo "$(YELLOW)Creating directory $(EXEC_DIR)...$(RESET)"
	mkdir -p $(EXEC_DIR)
.PHONY: $(EXEC_DIR)

clean:
	$(RM_DIR) $(OBJS_DIR)
	$(RM) *_shrubbery
	echo "$(RED)Cleaning of .o and .d files completed successfully! ／人◕ ‿‿ ◕人＼$(RESET)"
.PHONY: clean

fclean: clean
	$(RM_DIR) $(EXEC_DIR)
	echo "$(RED)"
	echo "┌──────────────────────────────────────────────────────────┐"
	echo "│      Deletion finished successfully! ( ◔ ω ◔) ノシ       │"
	echo "└──────────────────────────────────────────────────────────┘"
	echo "                           ╱|、"
	echo "                         (˚ˎ 。7"
	echo "                          |、˜|"
	echo "                         じしˍ,)ノ"
	echo "$(RESET)"
.PHONY: fclean

launch: all
	echo "$(PURPLE)────────────────────────────────────────────$(RESET)"
	echo "$(PURPLE)🚀 Launching $(NAME) with args: $(BOLD_UNDERLINE)$(ARGS)$(RESET)"
	echo "$(PURPLE)────────────────────────────────────────────$(RESET)"
	./$(EXEC) $(ARGS)
	echo "$(GREEN)────────────────────────────────────────────$(RESET)"
	echo "$(GREEN)✅ Execution of $(NAME) finished! ✨$(RESET)"
	echo "$(GREEN)────────────────────────────────────────────$(RESET)"
.PHONY: launch

re: fclean all
.PHONY: re

-include $(DEPS)
