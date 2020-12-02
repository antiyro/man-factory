/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_factory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:13:10 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/28 12:13:11 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAN_FACTORY_H
# define MAN_FACTORY_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>

// TEXT COLORS AND FONTS

#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"      	/* Black */
#define RED     	"\033[31m"      	/* Red */
#define GREEN   	"\033[32m"      	/* Green */
#define YELLOW  	"\033[33m"      	/* Yellow */
#define BLUE    	"\033[34m"      	/* Blue */
#define MAGENTA 	"\033[35m"      	/* Magenta */
#define CYAN   		"\033[36m"      	/* Cyan */
#define WHITE   	"\033[37m"      	/* White */
#define BOLDBLACK   "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"	/* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"	/* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"	/* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"	/* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"	/* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"	/* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"	/* Bold White */

// FONCTIONS

int					ft_isequal(char *s1, char *s2);
char				*ft_char_tostr(char c);
void				ft_clean_stdin(void);
int					ft_check_file_exist(char *name);
size_t              ft_strlen(const char *str);

#endif
