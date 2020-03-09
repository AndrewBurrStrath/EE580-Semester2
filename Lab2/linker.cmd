/*************************************************************************
* linker.cmd for BIOS Workshop LAB 2A
**************************************************************************/

-stack 0x00010000
-heap 0x00000800

MEMORY
{
	IRAM: 			ORIGIN = 0x11800000 LENGTH = 0x00040000
	L3_shared_RAM:	ORIGIN = 0x80000000 LENGTH = 0x00020000
	DDR2_data:		ORIGIN = 0xC0000000 LENGTH = 0x08000000
}
SECTIONS
{
	.text > IRAM
	.const > IRAM
	.bss > IRAM
	.far > IRAM
	.switch > IRAM
	.stack > IRAM
	.data > IRAM
	.cinit > IRAM
	.sysmem > IRAM
	.cio > IRAM
}
