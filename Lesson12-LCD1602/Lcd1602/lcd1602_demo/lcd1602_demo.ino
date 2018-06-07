#define    DB0   2   // the number of the ROW_ pin 9 
#define    DB1   3   // the number of the ROW_ pin 14 
#define    DB2   4   // the number of the ROW_ pin 8 
#define    DB3   5   // the number of the ROW_ pin 12 
#define    DB4   6   // the number of the COL_ pin 13 
#define    DB5   7   // the number of the COL_ pin 3 
#define    DB6   8   // the number of the COL_ pin 4 
#define    DB7   9   // the number of the COL_ pin 10 
#define    LCD1602_RS   10  // the number of the COL_ pin 6 
#define    LCD1602_RW   11  // the number of the COL_ pin 11 
#define    LCD1602_E    12  // the number of the COL_ pin 15 
const char LCD1602_DB[8]={DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7};
void lcd1602_write_cmd(unsigned char cmd)
{
	int i ;
	for ( i = 0 ; i < 8 ; i++ )
	{
		digitalWrite( LCD1602_DB[i] ,cmd & ( 1 << i )); //cmd hung on data pin
	}
	digitalWrite(LCD1602_RW , LOW ) ; // write data
	digitalWrite(LCD1602_RS , LOW) ;  // cmd mode
	digitalWrite(LCD1602_E , LOW ) ;  // write data
	delayMicroseconds(1);
	digitalWrite(LCD1602_E, HIGH) ;   // enable
	delay(10);
	digitalWrite(LCD1602_E,LOW);
	delay(10);
}
void lcd1602_write_data(unsigned char dat)
{
	int i;
	for(i=0;i<8;i++)
	{
		digitalWrite( LCD1602_DB[i],dat&(1<<i));//cmd hung on data pin
	}
	digitalWrite(LCD1602_RS , HIGH);// data mode
	digitalWrite(LCD1602_RW , LOW );// write data
	digitalWrite(LCD1602_E, HIGH);// enable
	delay(10);
	digitalWrite(LCD1602_E,LOW);
	delay(10);
}
void lcd1602_disp_str(int line ,const char *str)
{
	unsigned char addr;
	if( line ==1)
	{
		addr=0x80;
	}
	else if( line ==2)
	{
		addr=0xc0;
	}
	lcd1602_write_cmd(addr);
	while(*str++!=0)
	{
		lcd1602_write_data(*str);
	}
}
void lcd1602_init(void)
{
	lcd1602_write_cmd(0x38);//CMD6 8-bit  ，2 line，5x7 word size                                  
	delay(20);
	lcd1602_write_cmd(0x06);//CMD3 input mode auto increase， no shift
	delay(20);
	lcd1602_write_cmd(0x0E);//CM4  display setting  open lcd
	delay(20);
	lcd1602_write_cmd(0x01);//CMD1 clean screen
	delay(100);
}
void setup(){
	// put your setup code here, to run once:
	int i =0;
	Serial.begin(115200);

	for( i =0; i <8; i++)
	{
		pinMode(LCD1602_DB[i], OUTPUT );
	}
	pinMode(LCD1602_RS,OUTPUT);
	pinMode(LCD1602_RW,OUTPUT);
	pinMode(LCD1602_E,OUTPUT);
	delay(100);
	lcd1602_init();
	Serial.println("Start display \n");
}

void loop(){
	// put your main code here, to run repeatedly:
	lcd1602_disp_str(1," Hello Ardunio ! ");
	lcd1602_disp_str(2," made by keywish! ");
	while(1);
}

