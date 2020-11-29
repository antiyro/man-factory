/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 10:24:53 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/28 10:24:57 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Documents/42/libft_project/libft/libft.h"
#include "man_factory"

int     main(int argc, char **argv)
{
    if (argc < 2)
        printf("Quelle page du manuel veux-tu?");
    if (ft_isequal(argv[1], "ft_memset"))
        ft_memset_answer();
    else if (ft_isequal(argv[1], "ft_bzero"))
        ft_bzero_answer();
    else
        printf("Aucune page de manuel pour %s", argv[1]);
    return (0);
}

