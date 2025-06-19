# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 12:13:42 by gtretiak          #+#    #+#              #
#    Updated: 2025/06/19 13:01:51 by gtretiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_B = fractol_bonus
FRACTOL_LIB_B = fractol_bonus.a
FRACTOL_LIB = fractol.a
HEADER = fractol.h
HEADER_B = fractol_bonus.h
LIBFT_DIR = C_libft/
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
	@if [ -d $(LIBFT_DIR) ]; then \
		echo "C_libft is already cloned"; \
	else \
		git clone git@github.com:gtretiak/C_libft.git $(LIBFT_DIR); \
	fi
	@if [ -f $(LIBFT_DIR)$(LIBFT) ]; then \
		echo "libft.a is already compiled"; \
	else \
		$(MAKE) -C $(LIBFT_DIR); \
	fi

$(MLX):
	@if [ -d $(MLX_DIR) ]; then \
		echo "minilibx-Linux is already cloned"; \
	else \
		git clone git@github.com:42paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@if [ -f $(MLX_DIR)$(MLX) ]; then \
		echo "mlx.a is already compiled"; \
	else \
		$(MAKE) -C $(MLX_DIR); \
	fi

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
	@if [ -d $(LIBFT_DIR) ]; then make clean -C $(LIBFT_DIR); fi
	@if [ -d $(MLX_DIR) ]; then make clean -C $(MLX_DIR); fi

fclean_bonus: clean_bonus
	@if [ -f $(FRACTOL_LIB_B) ]; then rm -f $(FRACTOL_LIB_B); fi
	@if [ -f $(NAME_B) ]; then rm -f $(NAME_B); fi
	@if [ -d $(LIBFT_DIR) ]; then make fclean -C $(LIBFT_DIR); fi
	@if [ -d $(LIBFT_DIR) ]; then rm -rf $(LIBFT_DIR); fi
	@if [ -d $(MLX_DIR) ]; then rm -rf $(MLX_DIR); fi

re_bonus: fclean_bonus bonus

clean:
	rm -f $(OBJS)
	@if [ -d $(LIBFT_DIR) ]; then make clean -C $(LIBFT_DIR); fi
	@if [ -d $(MLX_DIR) ]; then make clean -C $(MLX_DIR); fi

fclean: clean
	@if [ -f $(FRACTOL_LIB) ]; then rm -f $(FRACTOL_LIB); fi
	@if [ -f $(NAME) ]; then rm -f $(NAME); fi
	@if [ -d $(LIBFT_DIR) ]; then make fclean -C $(LIBFT_DIR); fi
	@if [ -d $(LIBFT_DIR) ]; then rm -rf $(LIBFT_DIR); fi
	@if [ -d $(MLX_DIR) ]; then rm -rf $(MLX_DIR); fi

re: fclean all
