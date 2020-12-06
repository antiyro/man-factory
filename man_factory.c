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

#include "man_factory.h"

void    ft_manwriter(char *name, char *s_descri, char *library, char *prototype, char *descri, char *return_v)
{
    FILE* file = NULL;
    file = fopen(name, "w");

    if (file != NULL)
    {
        fputs(BOLDWHITE, file);
        fputs("\n\t\t\t\t\tMAN FACTORY\n\n", file);
        fputs("\033[1m\033[37mNAME\n\t", file);
        fputs(RESET, file);
        fputs(name, file);
        fputs(" - ", file);
        fputs(s_descri, file);
        fputs("\n\n\033[1m\033[37mSYNOPSIS\n\t", file);
        fputs(RESET, file);
        fputs(library, file);
        fputs("\n\n\t", file);
        fputs(prototype, file);
        fputs("\n\n\033[1m\033[37mDESCRIPTION\n\t", file);
        fputs(RESET, file);
        fputs(descri, file);
        fputs("\n\n\033[1m\033[37mRETURN VALUE\n\t", file);
        fputs(RESET, file);
        fputs(return_v, file);
        fputs("\n\n", file);

        fclose(file);
    }
    else
        printf("ERROR");
}

void    ft_manreader(char *name, char *s_descri, char *library, char *prototype, char *descri, char *return_v)
{
    ft_manwriter(name, s_descri, library, prototype, descri, return_v);
    FILE* file = NULL;
    file = fopen(name, "r");
    if (file != NULL)
    {
        printf("\n");
        printf(BOLDWHITE);
        printf("%*s", 50, "MAN FACTORY\n\n");
        printf("NAME\n");
        printf(RESET);
        printf("\t%s - %s\n\n", name, s_descri);
        printf(BOLDWHITE);
        printf("SYNOPSIS\n");
        printf(RESET);
        printf("\t%s\n\n\t%s\n\n", library, prototype);
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
    }

void    ft_manmaker(void)
{
    printf(BOLDWHITE);
    char    name[25];       //Modify those values if you want to write more text in your man
    char    s_descri[100];
    char    library[25];
    char    prototype[200];
    char    descri[2000];
    char    return_v[1000];
    int     check_error;

    check_error = 1;
    printf("Enter the name of your fonction : ");
    printf(RESET);
    while (check_error)
    {
        fgets(name, 25, stdin);
        name[ft_strlen(name) - 1] = '\0';
        if (ft_check_file_exist(name))
            printf("A manual page already exists for this name.\nPlease enter a new one : ");
        else if (!ft_strlen(name))
            printf("You need to give a name to your manual page. \nPlease enter one : ");
        else
            check_error = 0;
    }
    
    printf(BOLDWHITE);
    printf("A short description of it : ");
    printf(RESET);
    fgets(s_descri, 100, stdin);
    s_descri[ft_strlen(s_descri) - 1] = '\0';

    printf(BOLDWHITE);
    printf("It library : ");
    printf(RESET);
    fgets(library, 25, stdin);
    library[ft_strlen(library) - 1] = '\0';

    printf(BOLDWHITE);
    printf("It protoype : ");
    printf(RESET);
    fgets(prototype, 200, stdin);
    prototype[ft_strlen(prototype) - 1] = '\0';

    printf(BOLDWHITE);
    printf("It detailled description : ");
    printf(RESET);
    fgets(descri, 2000, stdin);
    descri[ft_strlen(descri) - 1] = '\0';

    printf(BOLDWHITE);
    printf("And finally it return value : ");
    printf(RESET);
    fgets(return_v, 1000, stdin);
    return_v[ft_strlen(return_v) - 1] = '\0';
    printf("\n");
    ft_manreader(name, s_descri, library, prototype, descri, return_v);
}

int     main(int argc, char **argv)
{
    printf("\n");
    system("cat ~/Documents/man_factory/banner"); //Change the location if needed
    char    y_or_n[2];
    int     check_error;

    check_error = 1;
    printf(BOLDWHITE);
    printf("Would you like to create a new manual page ? (y/n) : ");
    printf(RESET);
    while (check_error)
    {
        fgets(y_or_n, 2, stdin);
        if (ft_isequal(y_or_n, "y"))
        {
            printf(BOLDWHITE);
            printf("\rNice lets start !\n");
            printf(RESET);
            check_error = 0;
            ft_clean_stdin();
            ft_manmaker();
        }
        else if (ft_isequal(y_or_n, "n"))
        {
            printf(BOLDWHITE);
            printf("Ok, see you soon then !");
            printf(RESET);
            ft_clean_stdin();
            check_error = 0;
        }
        if (check_error)
        {
            printf(BOLDWHITE);
            printf("Please answer with an \"y\" for yes or an \"n\" for no : ");
            printf(RESET);
            ft_clean_stdin();
        }
    }
    printf(RESET);
    return (0);
}