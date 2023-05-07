#include <cstdio>
int main()
{
	char buf[100] = "";
    int n=0;
	printf("scanf: Enter a text from keyboard\n");
	scanf ("%s", buf);
	printf("printf: %s was entered from keyboard\n\n", buf);

	printf("sprintf: Writing %d to char array\n", 100);
	sprintf(buf, "%d", 100);
	sscanf(buf, "%d", &n);
    printf("sscanf: Parsed number from char array is %d\n\n", n);

	//writes 1000 to file output.txt
	printf("Opening output.txt file for write\n");
	FILE *fp = fopen("output.txt", "wt");
	printf("fprintf: Writing %d to output.txt file\n", 1000);
	fprintf(fp, "%d", 1000);
	fclose(fp);
	printf("Closing output.txt file\n\n");

	//reads an integer 1000 from file test.txt and assigns it to n
	printf("Opening output.txt file for read\n");
	fp = fopen("output.txt", "rt");
	fscanf(fp, "%d", &n);
	printf("fscanf: Read %d from output.txt file\n", n);
	fclose(fp);
	printf("Closing output.txt file\n\n");


	return 0;
}
