#ifndef		COLORJPEG_H_
# define	COLORJPEG_H_


/*  utils.c  */
void		display_usage(int ac, char **av);
int		init_file(FILE **file, char *name, char *right);
void		*xmalloc(int size);

/*  transform.c  */
unsigned char	**color_into_bn(unsigned char **t_img,
				unsigned char **t_img_new,
				struct jpeg_decompress_struct *cinfo);

/*  jpeg_write.c  */
int		init_jpeg_write(struct jpeg_compress_struct *cinfo,
				struct jpeg_error_mgr *jerr,
				FILE *img,
				struct jpeg_decompress_struct *cinfo_origin,
				unsigned int compo,
				unsigned int space);
int		jpeg_write(struct jpeg_compress_struct *cinfo,
			   unsigned char **t_img_new);
int		destroy_jpeg_write(struct jpeg_compress_struct *cinfo);

/*  jpeg_read.c  */

int		init_jpeg_read(struct jpeg_decompress_struct *cinfo,
			  struct jpeg_error_mgr *jerr,
			  FILE *img);
unsigned char	**load_file_t_img(unsigned char ** t_img,
				  struct jpeg_decompress_struct	*cinfo);
int		destroy_jpeg_read(struct jpeg_decompress_struct	*cinfo);


/*  main.c  */
unsigned char	**init_tab_img(unsigned char **t_img,
			       int height, int width, int s_pix);


#endif		/* COLORJPEG_H_ */
