#Directory definition
LIBFT_DIR := libft
LIBMLX_DIR := mlx42
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := lib

#Filenames definition
NAME := cub3D

SRC_NAMES = cub3d.c \
			exit_utils.c \
			free_utils.c \
			hooks.c \
			list_utils.c \
			map_checks.c \
			map_conversion.c \
			memory_utils.c \
			move_check_pos.c \
			move_player.c \
			parsing_utils.c \
			parsing.c \
			player_direction.c \
			raycast.c \
			render.c \
			str_utils.c \
			structs_init.c
			
INC_NAMES := cub3d.h

OBJECTS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC_NAMES)))

INCLUDES := $(patsubst %.h, $(INC_DIR)/%.h, $(INC_NAMES))

DEPS := $(OBJECTS:.o=.d)

CFLAGS += -Wall -Werror -Wextra -MMD -MP -g -I $(INC_DIR) -fsanitize=address

LIB_NAMES := libft.a \
			libmlx42.a 
LIBS_TAG :=  -ldl \
			 -lglfw \
			 -pthread \
			 -lm
LIBS_TAG += $(patsubst lib%.a, -l%, $(LIB_NAMES))

DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
all: libft libmlx $(OBJECTS) $(NAME) 

$(NAME): $(LIBFT_DIR)/libft.a $(LIB_DIR)/libmlx42.a Makefile $(INCLUDES) $(OBJECTS)
	cc $(CFLAGS) -L libft -L lib $(DEBUG) $(OBJECTS) -o $@ $(LIBS_TAG) $(LIBS_TAG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	cc $(CFLAGS) $(DEBUG) -c $< -o $@ 

libft: 
	@$(MAKE) -C $(LIBFT_DIR)

libmlx: 
	cmake -S $(LIBMLX_DIR) -B $(CUR_DIR)/$(LIB_DIR)
	@$(MAKE) -C $(CUR_DIR)/$(LIB_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

flags:
	@echo $(CFLAGS)

show:
	@echo $(OBJECTS)
	@echo $(SRC_NAMES)

clean: 
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
ifneq ($(DEPS), )
-include $(DEPS)
endif
.PHONY: all flags clean fclean re show libft mlx
