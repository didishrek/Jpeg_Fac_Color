#include	<stdio.h>
#include	<stdlib.h>
#include	<jpeglib.h>
#include	<jerror.h>
#include	"colorjpeg.h"


/*Cette fonction transform une image couleur en image noir et blanc*/
unsigned char	**color_into_bn(unsigned char **t_img,
				unsigned char **t_img_new,
				struct jpeg_decompress_struct *cinfo)
{
  float		s_coeff;
  float		r_coeff;
  float		b_coeff;
  float		v_coeff;
  unsigned int	cpt_img;
  unsigned int	cpt_img_new;
  unsigned int	i;
  float		tmp;

  r_coeff = 0.3;
  b_coeff = 0.59;
  v_coeff = 0.11;
  s_coeff = r_coeff + b_coeff + v_coeff;
  i = 0;
  puts("Debut de la conversion ...");
  while (i < cinfo->output_height)
    {
      cpt_img = 1;
      cpt_img_new = 0;
      while (cpt_img_new < cinfo->output_width)
	{
	  tmp  = (t_img[i][cpt_img - 1] * r_coeff +
		  t_img[i][cpt_img] * b_coeff +
		  t_img[i][cpt_img + 1] * v_coeff) / s_coeff;
	  if (tmp > 255.0)
	    tmp = 255.0;
	  else if (tmp < 0.0000000001)
	    tmp = 0.00;
	  t_img_new[i][cpt_img_new] = (unsigned char)tmp;
	  cpt_img+=3;
	  cpt_img_new++;
	}
      i++;
    }
  puts("Conversion terminée");
  return (t_img_new);
}
