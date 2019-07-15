/* To control both keypad and textLCD in once,
make one file contain both keypad and textLCD codes*/

/*In this code, I used keypad file as a base code and add textLCD part where needed*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#define FPGA_BASEADDRESS        0x05000000
#define PIEZO_OFFSET		0x50
#define KEY_COL_OFFSET		0x70
#define KEY_ROW_OFFSET		0x72
//from keypad

#define TEXTLCD_OFFSET		0x10

void setcommand(unsigned short command);
void writebyte(char ch);
void initialize_textlcd();
int function_set(int rows, int nfonts);
int display_control(int display_enable, int cursor_enable, int nblink);
int cursor_shift(int set_screen, int set_rightshit);
int entry_mode_set(int increase, int nshift);
int return_home();
int clear_display();
int set_ddram_address(int pos);
//from textLCD

unsigned short *addr_fpga, *pTextlcd;

int main(int argc, char **argv) //We need to show text on textLCD screen when we press 1 and 2 buttons in main method.
																//so add textLCD parameter
{
	short value;
	unsigned short *addr_fpga;
	unsigned short *keypad_row_addr, *keypad_col_addr, *piezo_addr;
	int fd;
	int i,quit=1;
	if ((fd=open("/dev/mem",O_RDWR|O_SYNC)) < 0) {
		perror("mem open fail\n");
		exit(1);
	}

	addr_fpga= (unsigned short *)mmap(NULL, 4096,
PROT_WRITE|PROT_READ, MAP_SHARED, fd, FPGA_BASEADDRESS);
	keypad_col_addr = addr_fpga +
KEY_COL_OFFSET/sizeof(unsigned short);
	keypad_row_addr = addr_fpga +
KEY_ROW_OFFSET/sizeof(unsigned short);
	piezo_addr = addr_fpga + PIEZO_OFFSET/sizeof(unsigned short);

	if(*keypad_row_addr ==(unsigned short)-1 ||
*keypad_col_addr ==(unsigned short)-1 )
{
		close(fd);
		printf("mmap error\n");
		exit(1);
	}

	printf("- Keypad\n");
	printf("press the key button!\n");
	printf("press the key 16 to exit!\n");

	while(quit) {
		*keypad_row_addr =  0x01;	//insert textLCD code in 'press 1 button' part
		usleep(1000);
		value =(*keypad_col_addr & 0x0f);
		*keypad_row_addr = 0x00;
		switch(value) {
			case 0x01 :	{
							int fd;
							int i, len1=9,len2=11; //to prevent dummy values to be shown, use exact length
							char buf1[9] = "201602357";	//student number
						  char buf2[11] = "Sun Min Lee"; //student name

							if ((fd=open("/dev/mem", O_RDWR|O_SYNC)) < 0) {
								printf("mem open fail\n");
								exit(1);
							}

							addr_fpga= (unsigned short *)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, FPGA_BASEADDRESS);
							pTextlcd = addr_fpga + TEXTLCD_OFFSET/sizeof(unsigned short);

							if(*pTextlcd == (unsigned short)-1) {
								close(fd);
						               printf("mmap error\n");
						               exit(1);
							}

							if(argc == 2) {
								len1 = strlen(argv[1]);
								len2 = 0;
								strcpy(buf1,argv[1]);
							}else if(argc >= 3) {
								len1 = strlen(argv[1]);
								len2 = strlen(argv[2]);
								strcpy(buf1,argv[1]);
								strcpy(buf2,argv[2]);
							}
							initialize_textlcd();

							for(i=0;i<len1;i++) writebyte(buf1[i]);
							set_ddram_address(0x40);
							for(i=0;i<len2;i++) writebyte(buf2[i]);

							printf("- Textlcd\n");
							printf("LINE 1 :	");
							for(i=0;i<len1;i++) printf("%c", buf1[i]);	//set strings will be printed on textLCD
							printf("\nLINE 2 :	");
							for(i=0;i<len2;i++) printf("%c", buf2[i]);	//set strings will be printed on textLCD
							printf("\n");

							munmap(pTextlcd,4096);
							close(fd);
				*piezo_addr=0x01;	// C
			    usleep(150000);
			    *piezo_addr=0x02;	//D
			    usleep(150000);
			    *piezo_addr=0x03;	//E
			    usleep(150000);
			    *piezo_addr=0x0;	//stop
				break;
			}value = 0x01; break;
			case 0x02 :	{	//insert textLCD code in 'press 2 button' part
				int fd;
							int i, len1=8,len2=10;
							char buf1[8] = "ICE HUFS";	//sentence which needs to be printed
						    char buf2[11] = "Sun Min Lee";	//student number

							if ((fd=open("/dev/mem", O_RDWR|O_SYNC)) < 0) {
								printf("mem open fail\n");
								exit(1);
							}

							addr_fpga= (unsigned short *)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, FPGA_BASEADDRESS);
							pTextlcd = addr_fpga + TEXTLCD_OFFSET/sizeof(unsigned short);

							if(*pTextlcd == (unsigned short)-1) {
								close(fd);
						               printf("mmap error\n");
						               exit(1);
							}

							if(argc == 2) {
								len1 = strlen(argv[1]);
								len2 = 0;
								strcpy(buf1,argv[1]);
							}else if(argc >= 3) {
								len1 = strlen(argv[1]);
								len2 = strlen(argv[2]);
								strcpy(buf1,argv[1]);
								strcpy(buf2,argv[2]);
							}
							initialize_textlcd();

							for(i=0;i<len1;i++) writebyte(buf1[i]);
							set_ddram_address(0x40);
							for(i=0;i<len2;i++) writebyte(buf2[i]);

							printf("- Textlcd\n");
							printf("LINE 1 :	");
							for(i=0;i<len1;i++) printf("%c", buf1[i]);
							printf("\nLINE 2 :	");
							for(i=0;i<len2;i++) printf("%c", buf2[i]);
							printf("\n");

							munmap(pTextlcd,4096);
							close(fd);
		       	 value = 0x02;
			    *piezo_addr=0x04;	//F
			    usleep(150000);
			    *piezo_addr=0x05;	//G
			    usleep(150000);
			    *piezo_addr=0x06;	//H
			    usleep(150000);
			    *piezo_addr=0x0;	//stop

				break;
			}
			case 0x04 :	value = 0x03; break;
			case 0x08 :	value = 0x04; break;
		}
		if(value != 0x00) goto stop_poll;

		*keypad_row_addr = 0x02;
		for(i=0;i<2000;i++);
		value = value|(*keypad_col_addr & 0x0f);
		*keypad_row_addr = 0x00;

		switch(value) {
			case 0x01 :	value = 0x05; break;
			case 0x02 :	value = 0x06; break;
			case 0x04 :	value = 0x07; break;
			case 0x08 :	value = 0x08; break;
		}
		if(value != 0x00) goto stop_poll;

		*keypad_row_addr = 0x04;
		for(i=0;i<2000;i++);
		value = value|(*keypad_col_addr & 0x0f);
		*keypad_row_addr = 0x00;
		switch(value) {
			case 0x01 :	value = 0x09; break;
			case 0x02 :	value = 0x0a; break;
			case 0x04 :	value = 0x0b; break;
			case 0x08 :	value = 0x0c; break;
		}
		if(value != 0x00) goto stop_poll;

		*keypad_row_addr = 0x08;
		for(i=0;i<2000;i++);
		value = value|(*keypad_col_addr & 0x0f);
		*keypad_row_addr = 0x00;
		switch(value) {
			case 0x01 :	value = 0x0d; break;
			case 0x02 :	value = 0x0e; break;
			case 0x04 :	value = 0x0f; break;
			case 0x08 :	value = 0x10; break;
		}

	stop_poll:
		if(value>0) {
			printf("\n pressed key = %02d\n",value);
		/*	*piezo_addr=0x1;
			usleep(50000);
			*piezo_addr=0x0;
			*/
		}
		else *keypad_row_addr = 0x00;
		for(i=0;i<4000000;i++);

		if(value == 16) {
			printf("\nExit Program!! (key = %02d)\n\n", value);
			/*
			*piezo_addr=0x1;
			usleep(150000);
			*piezo_addr=0x0;
			*/
			quit = 0;

		}
	}

	munmap(addr_fpga,4096);
	close(fd);
	return 0;
}
//add methods used for textLCD control
void setcommand(unsigned short command)
{
 	command &= 0x00FF;
	*pTextlcd = command | 0x0000;
	usleep(1000);
	*pTextlcd = command | 0x0100;
	usleep(1000);
	*pTextlcd = command | 0x0000;
	usleep(1000);
}
void writebyte(char ch)
{
	unsigned short data;
	data = ch & 0x00FF;
	*pTextlcd = data&0x400;
	usleep(1000);
	*pTextlcd = data|0x500;
	usleep(1000);
	*pTextlcd = data|0x400;
	usleep(1000);

}
void initialize_textlcd() {
	function_set(2,0);
	display_control(1,0,0);
	clear_display();
	entry_mode_set(1,0);
	return_home();
}

int function_set(int rows, int nfonts) {
	unsigned short command = 0x30;

	if(rows == 2) command |= 0x08;
	else if(rows == 1) command &= 0xf7;
	else return -1;

	command = nfonts ? (command | 0x04) :	command;
	setcommand(command);
	return 1;
}
int display_control(int display_enable, int cursor_enable, int nblink) {
	unsigned short command = 0x08;
	command = display_enable ? (command | 0x04) :	command;
	command = cursor_enable ? (command | 0x02) :	command;
	command = nblink ? (command | 0x01) :	command;
	setcommand(command);
	return 1;
}

int cursor_shift(int set_screen, int set_rightshit) {
	unsigned short command = 0x10;
	command = set_screen ? (command | 0x08) :	command;
	command = set_rightshit ? (command | 0x04) :	command;
	setcommand(command);
	return 1;
}
int entry_mode_set(int increase, int nshift) {
	unsigned short command = 0x04;
	command = increase ? (command | 0x2) :	command;
	command = nshift ? ( command | 0x1) :	command;
	setcommand(command);
	return 1;
}

int return_home() {
	unsigned short command = 0x02;
	setcommand(command);
	return 1;
}

int clear_display() {
	unsigned short command = 0x01;
	setcommand(command);
	return 1;
}
int set_ddram_address(int pos) {
	unsigned short command = 0x80;
	command += pos;
	setcommand(command);
	return 1;
}
