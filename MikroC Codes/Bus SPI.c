// EL ASRI - AIT OMAR - EL HAOUCHI

// DAC module connections
sbit Chip_Select at RC0_bit;
sbit SoftSpi_CLK at RC3_bit;
sbit SoftSpi_SDI at RC4_bit;
sbit SoftSpi_SDO at RC5_bit;
sbit Chip_Select_Direction at TRISC0_bit;
sbit SoftSpi_CLK_Direction at TRISC3_bit;
sbit SoftSpi_SDI_Direction at TRISC4_bit;
sbit SoftSpi_SDO_Direction at TRISC5_bit;
// End DAC module connections
unsigned int value;
void InitMain() {
TRISA0_bit = 1; // Set RA0 pin as input
TRISA1_bit = 1; // Set RA1 pin as input
Chip_Select = 1; // Deselect DAC
Chip_Select_Direction = 0; // Set CS# pin as Output
Soft_SPI_Init(); // Initialize Soft_SPI
}
// DAC increments (0..4095) --> output voltage (0..Vref)
void DAC_Output(unsigned int valueDAC) {
char temp;
Chip_Select = 0; // Select DAC chip
// Send High Byte
temp = (valueDAC >> 8) & 0x0F; // Store valueDAC[11..8] to temp[3..0]
temp |= 0x30; // Define DAC setting, see MCP4921 datasheet
Soft_SPI_Write(temp); // Send high byte via Soft SPI
// Send Low Byte
temp = valueDAC; // Store valueDAC[7..0] to temp[7..0]
Soft_SPI_Write(temp); // Send low byte via Soft SPI
Chip_Select = 1; // Deselect DAC chip
}
void main() {
ANSEL = 0; // Configure AN pins as digital
ANSELH = 0;
C1ON_bit = 0; // Disable comparators
C2ON_bit = 0;
InitMain(); // Perform main initialization
value = 2048; // When program starts, DAC gives
// the output in the mid-range
while (1) { // Endless loop
if ((RA0_bit) && (value < 4095)) { // If RA0 button is pressed
value++; // increment value
}
else {
if ((RA1_bit) && (value > 0)) { // If RA1 button is pressed
value--; // decrement value}}
DAC_Output(value); // Send value to DAC chip
Delay_ms(1); // Slow down key repeat pace
}
}