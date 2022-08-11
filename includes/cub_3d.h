#ifndef CUB_3D_H
# define CUB_3D_H

#include <unistd.h>
#include <stdio.h> //à enlever
#include <stdlib.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

typedef struct s_game {
	char		**array;
}				t_game;


char	**fill_array(char	*file);

#endif