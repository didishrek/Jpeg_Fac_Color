#include	<stdio.h>
#include	<stdlib.h>
#include	<jpeglib.h>
#include	<jerror.h>
#include	"colorjpeg.h"

/* Cette fonction prépare l'écriture d'un fichier jpeg */
int		init_jpeg_write(struct jpeg_compress_struct *cinfo,
				struct jpeg_error_mgr *jerr,
				FILE *img,
				struct jpeg_decompress_struct *cinfo_origin,
				unsigned int compo,
				unsigned int space)
{
  cinfo->err = jpeg_std_error(jerr);
  jpeg_create_compress(cinfo);
  jpeg_stdio_dest(cinfo, img);
  cinfo->image_width = cinfo_origin->output_width;
  cinfo->image_height = cinfo_origin->output_height;
  cinfo->input_components = compo;
  cinfo->in_color_space = space;
  jpeg_set_defaults(cinfo);
  jpeg_start_compress(cinfo, TRUE);
  return (0);
}

/* Cette fonction permet d'écrire dans le fichier jpeg */
int		jpeg_write(struct jpeg_compress_struct *cinfo,
			   unsigned char **t_img_new)
{
  unsigned int	i;

  i = 0;
  jpeg_write_scanlines(cinfo, t_img_new, cinfo->image_width);
  return (0);
}

int		destroy_jpeg_write(struct jpeg_compress_struct *cinfo)
{
  jpeg_finish_compress(cinfo);
  jpeg_destroy_compress(cinfo);
  return (0);
}
