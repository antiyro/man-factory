/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_factory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:50:14 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/28 11:50:15 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42/libft_project/libft/libft.h"
#include "man_factory.h"

void clean_stdin(void) 
{ 
    int c; 
  
    while (c != '\n' && c != EOF)
        c = getchar();
}

void    ft_mamwriter(char *name, char *s_descri, char *library, char *prototype, char *descri, char *return_v)
{
    FILE* file = NULL;
    file = fopen(name, "w");
    if (file != NULL)
    {
        fputs(return_v, file);
        printf("%*s", 50, "MAN FACTORY\n\n");
        printf(BOLDWHITE);
        printf("NAME\n");
        printf(RESET);
        printf("\t%s - %s\n\n", name, s_descri);
        printf(BOLDWHITE);
        printf("SYNOPSIS\n");
        printf(RESET);
        printf("\t%s\n\n%s\n\n", library, prototype);
        printf(BOLDWHITE);
        printf("DESCRIPTION\n");
        printf(RESET);
        printf("\t%s\n\n", descri);
        printf(BOLDWHITE);
        printf("RETURN VALUE\n");
        printf(RESET);
        printf("\t%s\n\n", return_v);

        fclose(file);
    }
    else
        printf("ERROR");
    //printf("%s\n%s\n%s\n%s\n%s\n%s\n", name, s_descri, library, prototype, descri, return_v);
}

void    ft_manmaker(void)
{
    char    name[25];
    char    s_descri[100];
    char    library[25];
    char    prototype[200];
    char    descri[2000];
    char    return_v[1000];

    printf("Enter the name of your fonction : ");
    fgets(name, 25, stdin);
    name[ft_strlen(name) - 1] = '\0';
    
    printf("A short description of it : ");
    fgets(s_descri, 100, stdin);
    s_descri[ft_strlen(s_descri) - 1] = '\0';

    printf("It library : ");
    fgets(library, 25, stdin);
    library[ft_strlen(library) - 1] = '\0';

    printf("It protoype : ");
    fgets(prototype, 200, stdin);
    prototype[ft_strlen(prototype) - 1] = '\0';

    printf("It detailled description : ");
    fgets(descri, 2000, stdin);
    descri[ft_strlen(descri) - 1] = '\0';

    printf("And finally it return value : ");
    fgets(return_v, 1000, stdin);
    return_v[ft_strlen(return_v) - 1] = '\0';
    printf("\n");
    ft_mamwriter(name, s_descri, library, prototype, descri, return_v);
}

int     main(int argc, char **argv)
{
    printf("\n");
    system("cat banner");
    char    y_or_n[2];
    int error;

    error = 1;
    printf(BOLDWHITE);
    printf("Would you like to create a new manual page ? (y/n) : ");
    while (error)
    {
        fgets(y_or_n, 2, stdin);
        if (ft_isequal(y_or_n, "y"))
        {
            printf("\rNice lets start !\n");
            error = 0;
            clean_stdin();
            ft_manmaker();
        }
        else if (ft_isequal(y_or_n, "n"))
        {
            printf("Ok, see you soon then !");
            clean_stdin();
            error = 0;
        }
        if (error)
        {
            printf("Please answer with an \"y\" for yes or an \"n\" for no : ");
            clean_stdin();
        }
        printf(RESET);
    }
    return (0);
}
