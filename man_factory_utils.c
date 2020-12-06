/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_factory_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:50:21 by nbouhada          #+#    #+#             */
/*   Updated: 2020/12/02 19:50:23 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "man_factory.h"

void ft_clean_stdin(void) 
{ 
    int c; 
  
    while (c != '\n' && c != EOF)
        c = getchar();
}

int ft_check_file_exist(char *name)
{
    FILE *file;

    if ((file = fopen(name, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int     ft_isequal(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    if (s2[i] != '\0')
        return (0);
    return (1);
}

char    *ft_char_tostr(char c)
{
    char *str;
    *str = c;
    return (str);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


