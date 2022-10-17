void	flag_check(char **point)
{
	flags	f;
	flags	cmp_f;
	t_flag	flag;

	cmp_f = 0;
	while (!(is_type (**point)))
	{
		f = check_flags (&flag, **point);
		if (cmp_f >= f)
			return (NULL);
		cmp_f = f;
		(**point)++;
	}
}

