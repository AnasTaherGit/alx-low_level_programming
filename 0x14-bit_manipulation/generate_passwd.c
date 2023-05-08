#include <stdio.h>
#include <stdint.h>
#include <string.h>

int check_password(const char *a1)
{
	unsigned char i;

	if (strlen(a1) != 4)
		return 0LL;
	for (i = 0; i <= 3u; ++i)
	{
		if ((unsigned char)a1[i] != (unsigned char)(0x46C6F48u >> (8 * i)))
			return 0LL;
	}
	return 1LL;
}

int main()
{
	uint32_t hex_number = 0x46C6F48u;
	char password[5];

	for (int i = 0; i < 4; i++)
	{
		password[i] = (char)(hex_number >> (8 * i));
	}
	password[4] = '\0'; // Null-terminate the password string

	printf("Generated password:");
	puts(password);

	if (check_password(password))
	{
		printf("The password is valid!\n");
	}
	else
	{
		printf("The password is not valid.\n");
	}
	// Write the password to a file
    FILE *file = fopen("101-password", "w");
    if (file == NULL)
    {
        printf("Error: Unable to open the file for writing.\n");
        return 1;
    }

    fprintf(file, "%s", password);
    fclose(file);
    printf("Password saved to password.txt.\n");
	return 0;
}
