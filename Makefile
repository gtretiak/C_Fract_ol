# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 12:13:42 by gtretiak          #+#    #+#              #
#    Updated: 2025/01/30 12:04:49 by gtretiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_B = fractol_bonus
FRACTOL_LIB_B = fractol_bonus.a
FRACTOL_LIB = fractol.a
HEADER = fractol.h
HEADER_B = fractol_bonus.h
LIBFT_DIR = Libft/
LIBFT = libft.a
MLX_DIR = minilibx-linux/
MLX = libmlx_Linux.a
SRCS_DIR = Sources/
SRCS_B_DIR = Sources_bonus/
SRCS = utils.c math.c fractol.c render.c events.c init.c
SRCS_B = utils_bonus.c math_bonus.c fractol_bonus.c \
	 render_bonus.c events_bonus.c init_bonus.c
OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
OBJS_B = $(addprefix $(SRCS_B_DIR), $(SRCS_B:.c=.o))
CFLAGS = -Wall -Wextra -Werror
MLX_FEATURES = -lX11 -lXext -lXrender -lXrandr -lm -lpthread

all: $(LIBFT) $(MLX) $(FRACTOL_LIB) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(FRACTOL_LIB): $(MLX_DIR)$(MLX) $(OBJS) $(HEADER) $(LIBFT_DIR)$(LIBFT)
	ar -rc $(FRACTOL_LIB) $^

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER) $(MLX_DIR)$(MLX) $(LIBFT_DIR)$(LIBFT)
	cc $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@ 
	
$(NAME): $(FRACTOL_LIB) $(LIBFT) $(MLX) $(OBJS)
	@if [ $(FRACTOL_LIB) -nt $(NAME) ] || [ $(LIBFT) -nt $(NAME) ] \
		|| [ ! -f $(NAME) ]; then \
		cc -O3 $(FRACTOL_LIB) -lft $(MLX_DIR)$(MLX) \
		-L$(LIBFT_DIR) $(MLX_FEATURES) -o $(NAME); fi

.PHONY: mlx bonus clean fclean re clean_bonus fclean_bonus re_bonus

bonus: $(LIBFT) $(MLX) $(FRACTOL_LIB_B) $(NAME_B)

$(FRACTOL_LIB_B): $(MLX_DIR)$(MLX) $(OBJS_B) $(HEADER_B) $(LIBFT_DIR)$(LIBFT)
	ar -rc $(FRACTOL_LIB_B) $^

$(SRCS_B_DIR)%.o: $(SRCS_B_DIR)%.c $(HEADER_B) $(MLX_DIR)$(MLX) $(LIBFT_DIR)$(LIBFT)
	cc $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@ 
	
$(NAME_B): $(FRACTOL_LIB_B) $(LIBFT) $(MLX) $(OBJS_B)
	@if [ $(FRACTOL_LIB_B) -nt $(NAME_B) ] || [ $(LIBFT) -nt $(NAME_B) ] \
		|| [ ! -f $(NAME_B) ]; then \
		cc -O3 $(FRACTOL_LIB_B) -lft $(MLX_DIR)$(MLX) \
		-L$(LIBFT_DIR) $(MLX_FEATURES) -o $(NAME_B); fi

clean_bonus:
	rm -f $(OBJS_B)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean_bonus: clean_bonus
	rm -f $(FRACTOL_LIB_B)
	rm -f $(NAME_B)
	@make fclean -C $(LIBFT_DIR)

re_bonus: fclean_bonus bonus

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(FRACTOL_LIB)
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
