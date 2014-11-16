#include	<stdio.h>
#include	<stdlib.h>
#include	<jpeglib.h>
#include	<jerror.h>
#include	"colorjpeg.h"

/* Cette fonction prépare la lecture d'un fichier jpeg */
int		init_jpeg_read(struct jpeg_decompress_struct *cinfo,
			  struct jpeg_error_mgr *jerr,
			  FILE *img)
{
  cinfo->err = jpeg_std_error(jerr);
  jpeg_create_decompress(cinfo);
  jpeg_stdio_src(cinfo, img);
  jpeg_read_header(cinfo, TRUE);
  jpeg_start_decompress(cinfo);
  return (0);
}

/* Cette fonction lit l'image ligne par ligne et la stock dans un tableau */
unsigned char	**load_file_t_img(unsigned char ** t_img,
				  struct jpeg_decompress_struct	*cinfo)
{
  unsigned char	**buffer;
  unsigned int	i;
  unsigned int	j;

  i = 0;
  buffer = xmalloc(sizeof(unsigned char *));
  buffer[0] = xmalloc(sizeof(unsigned char) *
		      cinfo->output_components * cinfo->output_width);
  while (i < cinfo->output_height)
    {
      j = 0;
      jpeg_read_scanlines(cinfo, buffer, 1);
      while (j < cinfo->output_width * 3)
      	{
      	  t_img[i][j] = buffer[0][j];
      	  j++;
      	}
      i++;
    }
  return (t_img);
}

int		destroy_jpeg_read(struct jpeg_decompress_struct	*cinfo)
{
  jpeg_finish_decompress(cinfo);
  jpeg_destroy_decompress(cinfo);
  return (0);
}


