#include	<stdio.h>
#include	<stdlib.h>
#include	<jpeglib.h>
#include	<jerror.h>
#include	"colorjpeg.h"

/*Cette fonction alloue la memoire d'un char ***/
unsigned char	**init_tab_img(unsigned char **t_img,
			       int height, int width, int s_pix)
{
  int		i;

  i = 0;
  t_img = xmalloc(sizeof(char *) * height);
  while (i < height)
    {
      t_img[i] = xmalloc(sizeof(unsigned char) * width * s_pix);
      i++;
    }
  return (t_img);
}

int		main(int ac, char **av)
{
  struct jpeg_decompress_struct	cinfo;
  struct jpeg_compress_struct	cinfo_out;
  struct jpeg_error_mgr		jerr;
  FILE				*img1;
  FILE				*img2;
  unsigned char			**t_img;
  unsigned char			**t_img_new;

  img1 = NULL;
  img2 = NULL;
  t_img = NULL;
  t_img_new = NULL;
  display_usage(ac, av);
  puts("Initialisation ...");
  if (init_file(&img1, av[1], "r") == 1)
    exit(2);
  init_jpeg_read(&cinfo, &jerr, img1);
  t_img = init_tab_img(t_img, cinfo.output_height, cinfo.output_width,
		       cinfo.output_components);
  t_img = load_file_t_img(t_img, &cinfo);
  t_img_new = init_tab_img(t_img_new, cinfo.output_height,
			   cinfo.output_width, 1);
  t_img_new = color_into_bn(t_img, t_img_new, &cinfo);
  if (init_file(&img2, av[2], "w+") == 1)
    exit(2);
  init_jpeg_write(&cinfo_out, &jerr, img2, &cinfo, 1, JCS_GRAYSCALE);
  jpeg_write(&cinfo_out, t_img_new);
  destroy_jpeg_read(&cinfo);
  destroy_jpeg_write(&cinfo_out);
  free(img1);
  free(t_img);
  free(t_img_new);
  puts("Programme terminée correctement");
  return (0);
}
