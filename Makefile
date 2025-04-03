#Directory definition
LIBFT_DIR := libft
LIBMLX_DIR := mlx42
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := lib

#Filenames definition
NAME := cub3D
NAME_BONUS = $(NAME)

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
			structs_free.c \
			structs_init.c

SRC_NAMES_BONUS := hooks_bonus.c

INC_NAMES := cub3d.h

INC_NAMES_BONUS := cub3d.h

OBJECTS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC_NAMES)))

OBJECTS_BONUS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC_NAMES_BONUS)))

INCLUDES := $(patsubst %.h, $(INC_DIR)/%.h, $(INC_NAMES))

INCLUDES_BONUS := $(patsubst %.h, $(INC_DIR)/%.h, $(INC_NAMES_BONUS))

DEPS := $(OBJECTS:.o=.d)
DEPS_BONUS := $(OBJECTS_BONUS:.o=.d)

CFLAGS += -Wall -Werror -Wextra -MMD -MP -g -Ofast -I $(INC_DIR) #-fsanitize=address 

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

bonus: libft libmlx $(OBJECTS_BONUS) bonus_m 

$(NAME): $(LIBFT_DIR)/libft.a $(LIB_DIR)/libmlx42.a Makefile $(INCLUDES) $(OBJECTS) | $(LIB_DIR)
	cc $(CFLAGS) -L libft -L lib $(DEBUG) $(OBJECTS) -o $@ $(LIBS_TAG) $(LIBS_TAG)

bonus_m: $(LIBFT_DIR)/libft.a $(LIB_DIR)/libmlx42.a Makefile $(INCLUDES_BONUS) $(OBJECTS) $(OBJECTS_BONUS) | $(LIB_DIR)
	cc $(CFLAGS) -L libft -L lib $(DEBUG) $(OBJECTS) $(OBJECTS_BONUS) -o $@ $(LIBS_TAG) $(LIBS_TAG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	cc $(CFLAGS) $(DEBUG) -c $< -o $@ 

libft: 
	@$(MAKE) -C $(LIBFT_DIR)

libmlx: 
	cmake -DDEBUG=1 -S $(LIBMLX_DIR) -B $(CUR_DIR)/$(LIB_DIR)
	@$(MAKE) -C $(CUR_DIR)/$(LIB_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)


$(LIB_DIR):
	@mkdir $(LIB_DIR)

flags:
	@echo $(CFLAGS)

show:
	@echo $(OBJECTS)
	@echo $(OBJECTS_BONUS)
#	@echo $(SRC_NAMES)

clean: 
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -rf $(LIB_DIR)

re: fclean all
ifneq ($(DEPS), )
-include $(DEPS)
endif
ifneq ($(DEPS_BONUS), )
-include $(DEPS)
endif
.PHONY: all flags clean fclean re show libft mlx bonus
