#include	<stdio.h>
#include	<stdlib.h>
#include	<jpeglib.h>
#include	<jerror.h>
#include	"colorjpeg.h"

/* Cette fonction se place en debut de main et vérifie que le nombre de paramètre est bon */
void		display_usage(int ac, char **av)
{
  if (ac != 3)
    {
      printf("USAGE : %s [FILE_IN] [FILE_OUT]\n",av[0]);
      exit(1);
    }
}

/* Cette fonction ouvre un fichier 'name' avec les droits 'right' */
int		init_file(FILE **file, char *name, char *right)
{
  *file = fopen(name, right);
  if (*file == NULL)
    {
      printf("Ouverture du fichier %s impossible\n", name);
      return (1);
    }
  return (0);
}

/*Fonction sécurisé de malloc. */
void		*xmalloc(int size)
{
  void		*str;

  if ((str = malloc(size)) == NULL)
    {
      puts("Malloc error \n");
      exit(EXIT_FAILURE);
    }
  return (str);
}

