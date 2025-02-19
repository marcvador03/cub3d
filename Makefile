#Directory definition
LIBFT_DIR := libft
MLX_DIR := minilibx
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := lib

#Filenames definition
NAME := cub3D

SRC_NAMES = cub3d.c

INC_NAMES := cub3d.h

OBJECTS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC_NAMES)))

INCLUDES := $(patsubst %.h, $(INC_DIR)/%.h, $(INC_NAMES))

DEPS := $(OBJECTS:.o=.d)

CFLAGS += -Wall -Werror -Wextra -MMD -MP -g -I $(INC_DIR)

LIB_NAMES := libft.a \
			libmlx.a 
LIBS_TAG := $(patsubst lib%.a, -l%, $(LIB_NAMES))

DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
all: libft mlx $(OBJECTS) $(NAME) 

$(NAME): $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a Makefile $(INCLUDES) $(OBJECTS)
	cc $(CFLAGS) -L libft $(DEBUG) $(OBJECTS) -o $@ $(LIBS_TAG) $(LIBS_TAG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	cc $(CFLAGS) $(DEBUG) -c $< -o $@ 

libft: 
	@$(MAKE) -C $(LIBFT_DIR)

mlx: 
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

flags:
	@echo $(CFLAGS)

show:
	@echo $(OBJECTS)
	@echo $(SRC_NAMES)

clean: 
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

re: fclean all
ifneq ($(DEPS), )
-include $(DEPS)
endif
.PHONY: all flags clean fclean re show libft mlx
