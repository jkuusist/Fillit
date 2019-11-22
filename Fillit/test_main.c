#include <stdio.h>
#include <fcntl.h>

int		check_input(int fd);

int main()
{
	int fd = open("../Test_Files_TBR!/1_NoEOF", O_RDONLY);
	int function_ret = check_input(fd);
	printf("open returned: %d\nfunction returned: %d\n", fd, function_ret);

	return (0);	
}
