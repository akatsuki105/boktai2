#include "gba/gba.h"

// libagbrtc.a, pret/siirtc.c

#define STATUS_INTFE 0x02   // frequency interrupt enable
#define STATUS_INTME 0x08   // per-minute interrupt enable
#define STATUS_INTAE 0x20   // alarm interrupt enable
#define STATUS_24HOUR 0x40  // 0: 12-hour mode, 1: 24-hour mode
#define STATUS_POWER 0x80   // power on or power failure occurred

#define TEST_MODE 0x80  // flag in the "second" byte

#define ALARM_AM 0x00
#define ALARM_PM 0x80

#define OFFSET_YEAR offsetof(RtcDataOrg, year)
#define OFFSET_MONTH offsetof(RtcDataOrg, month)
#define OFFSET_DAY offsetof(RtcDataOrg, day)
#define OFFSET_DAY_OF_WEEK offsetof(RtcDataOrg, week)
#define OFFSET_HOUR offsetof(RtcDataOrg, hour)
#define OFFSET_MINUTE offsetof(RtcDataOrg, minute)
#define OFFSET_SECOND offsetof(RtcDataOrg, second)
#define OFFSET_STATUS offsetof(RtcDataOrg, status)
#define OFFSET_ALARM_HOUR offsetof(RtcDataOrg, alarm_hour)
#define OFFSET_ALARM_MINUTE offsetof(RtcDataOrg, alarm_minute)

#define INFO_BUF(info, index) (*((u8*)(info) + (index)))

#define DATETIME_BUF(info, index) INFO_BUF(info, OFFSET_YEAR + index)
#define DATETIME_BUF_LEN (OFFSET_SECOND - OFFSET_YEAR + 1)

#define TIME_BUF(info, index) INFO_BUF(info, OFFSET_HOUR + index)
#define TIME_BUF_LEN (OFFSET_SECOND - OFFSET_HOUR + 1)

#define WR 0  // command for writing data
#define RD 1  // command for reading data

#define CMD(n) (0x60 | (n << 1))
#define CMD_RESET CMD(0)
#define CMD_STATUS CMD(1)
#define CMD_DATETIME CMD(2)
#define CMD_TIME CMD(3)
#define CMD_ALARM CMD(4)

#define SCK_HI 1
#define SIO_HI 2
#define CS_HI 4

#define DIR_0_IN 0
#define DIR_0_OUT 1
#define DIR_1_IN 0
#define DIR_1_OUT 2
#define DIR_2_IN 0
#define DIR_2_OUT 4
#define DIR_ALL_IN (DIR_0_IN | DIR_1_IN | DIR_2_IN)
#define DIR_ALL_OUT (DIR_0_OUT | DIR_1_OUT | DIR_2_OUT)

#define GPIO_PORT_DATA (*(vu16*)0x080000C4)
#define GPIO_PORT_DIRECTION (*(vu16*)0x080000C6)
#define GPIO_PORT_READ_ENABLE (*(vu16*)0x080000C8)

const char AgbLibRtcVersion[] = "SIIRTC_V001";

static u16 ime_bkup;
static bool8 rtc_lock;  // 0x030026CA

const bool8* const RTCLocks[9] = {
    &rtc_lock, &rtc_lock, &rtc_lock, &rtc_lock, &rtc_lock, &rtc_lock, &rtc_lock, &rtc_lock, &rtc_lock,
};

bool8* const gRTCLocked = &rtc_lock;
void* const GpioCntRegp = (void*)0x080000C6;

// libagbrtc/agbrtc.c

NAKED void RtcIoEnable(void) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	mov r7, sp\n\
	bl GpioReadEnable\n\
	ldr r0, _0824C5AC @ =rtc_lock\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	pop {r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0824C5AC: .4byte rtc_lock\n\
 .syntax divided\n");
}

NAKED void RtcIoDisable(void) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	mov r7, sp\n\
	bl GpioReadDisable\n\
	ldr r0, _0824C5C4 @ =rtc_lock\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	pop {r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0824C5C4: .4byte rtc_lock\n\
 .syntax divided\n");
}

NAKED u8 RtcPowerOnCheck(void) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	sub sp, #0x10\n\
	mov r7, sp\n\
	adds r1, r7, #4\n\
	adds r0, r1, #0\n\
	bl RtcReadStat\n\
	lsls r1, r0, #0x18\n\
	lsrs r0, r1, #0x18\n\
	cmp r0, #0\n\
	bne _0824C5E2\n\
	movs r0, #0\n\
	b _0824C696\n\
_0824C5E2:\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0, #7]\n\
	movs r2, #0xc0\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	adds r2, r0, #0\n\
	lsls r1, r2, #0x18\n\
	lsrs r0, r1, #0x18\n\
	cmp r0, #0x80\n\
	beq _0824C612\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0, #7]\n\
	movs r2, #0xc0\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	adds r2, r0, #0\n\
	lsls r1, r2, #0x18\n\
	lsrs r0, r1, #0x18\n\
	cmp r0, #0\n\
	bne _0824C630\n\
	b _0824C612\n\
_0824C612:\n\
	bl RtcReset\n\
	lsls r1, r0, #0x18\n\
	lsrs r0, r1, #0x18\n\
	cmp r0, #0\n\
	bne _0824C622\n\
	movs r0, #0\n\
	b _0824C696\n\
_0824C622:\n\
	adds r1, r7, #0\n\
	adds r0, r7, #0\n\
	adds r1, r7, #0\n\
	ldrb r2, [r1]\n\
	adds r1, r2, #1\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
_0824C630:\n\
	adds r1, r7, #4\n\
	adds r0, r1, #0\n\
	bl RtcReadTime\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0, #6]\n\
	movs r2, #0x80\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	adds r2, r0, #0\n\
	lsls r1, r2, #0x18\n\
	lsrs r0, r1, #0x18\n\
	cmp r0, #0\n\
	beq _0824C67E\n\
	bl RtcReset\n\
	lsls r1, r0, #0x18\n\
	lsrs r0, r1, #0x18\n\
	cmp r0, #0\n\
	bne _0824C670\n\
	adds r0, r7, #0\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #4\n\
	adds r1, r0, #0\n\
	movs r2, #0xf\n\
	adds r0, r1, #0\n\
	bics r0, r2\n\
	adds r1, r0, #0\n\
	lsls r0, r1, #0x18\n\
	lsrs r1, r0, #0x18\n\
	adds r0, r1, #0\n\
	b _0824C696\n\
_0824C670:\n\
	adds r1, r7, #0\n\
	adds r0, r7, #0\n\
	adds r1, r7, #0\n\
	ldrb r2, [r1]\n\
	adds r1, r2, #1\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
_0824C67E:\n\
	adds r0, r7, #0\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #4\n\
	adds r1, r0, #0\n\
	movs r2, #1\n\
	adds r0, r1, #0\n\
	orrs r0, r2\n\
	adds r1, r0, #0\n\
	lsls r0, r1, #0x18\n\
	lsrs r1, r0, #0x18\n\
	adds r0, r1, #0\n\
	b _0824C696\n\
_0824C696:\n\
	add sp, #0x10\n\
	pop {r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 RtcReset(void) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	sub sp, #0x10\n\
	mov r7, sp\n\
	ldr r0, _0824C6B4 @ =rtc_lock\n\
	ldrb r1, [r0]\n\
	cmp r1, #1\n\
	bne _0824C6B8\n\
	movs r0, #0\n\
	b _0824C71C\n\
	.align 2, 0\n\
_0824C6B4: .4byte rtc_lock\n\
_0824C6B8:\n\
	ldr r0, _0824C710 @ =rtc_lock\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, _0824C714 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C714 @ =ROM_GPIODATA\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	ldr r0, _0824C718 @ =ROM_GPIODIR\n\
	movs r1, #7\n\
	strh r1, [r0]\n\
	movs r0, #0x60\n\
	bl RtcWriteCom\n\
	ldr r0, _0824C714 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C714 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C710 @ =rtc_lock\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0, #7]\n\
	movs r2, #0\n\
	ands r1, r2\n\
	adds r2, r1, #0\n\
	movs r3, #0x40\n\
	adds r1, r2, #0\n\
	orrs r1, r3\n\
	adds r2, r1, #0\n\
	strb r2, [r0, #7]\n\
	adds r1, r7, #4\n\
	adds r0, r1, #0\n\
	bl RtcWriteStat\n\
	adds r1, r7, #0\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	ldrb r1, [r0]\n\
	adds r0, r1, #0\n\
	b _0824C71C\n\
	.align 2, 0\n\
_0824C710: .4byte rtc_lock\n\
_0824C714: .4byte ROM_GPIODATA\n\
_0824C718: .4byte ROM_GPIODIR\n\
_0824C71C:\n\
	add sp, #0x10\n\
	pop {r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 RtcReadStat(RtcDataOrg* r) {
  asm(".syntax unified\n\
	push {r4, r7, lr}\n\
	sub sp, #8\n\
	mov r7, sp\n\
	str r0, [r7]\n\
	ldr r0, _0824C738 @ =rtc_lock\n\
	ldrb r1, [r0]\n\
	cmp r1, #1\n\
	bne _0824C73C\n\
	movs r0, #0\n\
	b _0824C7E8\n\
	.align 2, 0\n\
_0824C738: .4byte rtc_lock\n\
_0824C73C:\n\
	ldr r0, _0824C7DC @ =rtc_lock\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, _0824C7E0 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C7E0 @ =ROM_GPIODATA\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	ldr r0, _0824C7E4 @ =ROM_GPIODIR\n\
	movs r1, #7\n\
	strh r1, [r0]\n\
	movs r0, #0x63\n\
	bl RtcWriteCom\n\
	ldr r0, _0824C7E4 @ =ROM_GPIODIR\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	bl RtcReadData\n\
	adds r1, r7, #4\n\
	strb r0, [r1]\n\
	ldr r0, [r7]\n\
	adds r1, r7, #4\n\
	ldrb r2, [r1]\n\
	movs r3, #0xc0\n\
	adds r1, r2, #0\n\
	ands r1, r3\n\
	adds r2, r7, #4\n\
	ldrb r3, [r2]\n\
	movs r4, #0x20\n\
	adds r2, r3, #0\n\
	ands r2, r4\n\
	adds r4, r2, #0\n\
	lsls r3, r4, #0x18\n\
	lsrs r2, r3, #0x18\n\
	lsrs r3, r2, #3\n\
	adds r2, r3, #0\n\
	orrs r1, r2\n\
	adds r2, r7, #4\n\
	ldrb r3, [r2]\n\
	movs r4, #8\n\
	adds r2, r3, #0\n\
	ands r2, r4\n\
	adds r4, r2, #0\n\
	lsls r3, r4, #0x18\n\
	lsrs r2, r3, #0x18\n\
	lsrs r3, r2, #2\n\
	adds r2, r3, #0\n\
	orrs r1, r2\n\
	adds r2, r7, #4\n\
	ldrb r3, [r2]\n\
	movs r4, #2\n\
	adds r2, r3, #0\n\
	ands r2, r4\n\
	adds r4, r2, #0\n\
	lsls r3, r4, #0x18\n\
	lsrs r2, r3, #0x18\n\
	lsrs r3, r2, #1\n\
	adds r2, r3, #0\n\
	orrs r1, r2\n\
	ldrb r2, [r0, #7]\n\
	movs r3, #0\n\
	ands r2, r3\n\
	adds r3, r2, #0\n\
	adds r2, r3, #0\n\
	orrs r2, r1\n\
	adds r1, r2, #0\n\
	strb r1, [r0, #7]\n\
	ldr r0, _0824C7E0 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C7E0 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C7DC @ =rtc_lock\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	b _0824C7E8\n\
	.align 2, 0\n\
_0824C7DC: .4byte rtc_lock\n\
_0824C7E0: .4byte ROM_GPIODATA\n\
_0824C7E4: .4byte ROM_GPIODIR\n\
_0824C7E8:\n\
	add sp, #8\n\
	pop {r4, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 RtcWriteStat(RtcDataOrg* r) {
  asm(".syntax unified\n\
	push {r4, r7, lr}\n\
	sub sp, #8\n\
	mov r7, sp\n\
	str r0, [r7]\n\
	ldr r0, _0824C804 @ =rtc_lock\n\
	ldrb r1, [r0]\n\
	cmp r1, #1\n\
	bne _0824C808\n\
	movs r0, #0\n\
	b _0824C890\n\
	.align 2, 0\n\
_0824C804: .4byte rtc_lock\n\
_0824C808:\n\
	ldr r0, _0824C884 @ =rtc_lock\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, _0824C888 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C888 @ =ROM_GPIODATA\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	adds r0, r7, #4\n\
	ldr r1, [r7]\n\
	ldrb r2, [r1, #7]\n\
	movs r3, #4\n\
	adds r1, r2, #0\n\
	ands r1, r3\n\
	adds r2, r1, #0\n\
	lsls r1, r2, #3\n\
	ldr r2, [r7]\n\
	ldrb r3, [r2, #7]\n\
	movs r4, #2\n\
	adds r2, r3, #0\n\
	ands r2, r4\n\
	adds r3, r2, #0\n\
	lsls r2, r3, #2\n\
	adds r3, r2, #0\n\
	movs r4, #0x40\n\
	adds r2, r3, #0\n\
	orrs r2, r4\n\
	orrs r1, r2\n\
	ldr r2, [r7]\n\
	ldrb r3, [r2, #7]\n\
	movs r4, #1\n\
	adds r2, r3, #0\n\
	ands r2, r4\n\
	adds r3, r2, #0\n\
	lsls r2, r3, #1\n\
	orrs r1, r2\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	ldr r0, _0824C88C @ =ROM_GPIODIR\n\
	movs r1, #7\n\
	strh r1, [r0]\n\
	movs r0, #0x62\n\
	bl RtcWriteCom\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0]\n\
	adds r0, r1, #0\n\
	bl RtcWriteData\n\
	ldr r0, _0824C888 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C888 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C884 @ =rtc_lock\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	b _0824C890\n\
	.align 2, 0\n\
_0824C884: .4byte rtc_lock\n\
_0824C888: .4byte ROM_GPIODATA\n\
_0824C88C: .4byte ROM_GPIODIR\n\
_0824C890:\n\
	add sp, #8\n\
	pop {r4, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 RtcReadDate(RtcDataOrg* r) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	sub sp, #8\n\
	mov r7, sp\n\
	str r0, [r7]\n\
	ldr r0, _0824C8AC @ =rtc_lock\n\
	ldrb r1, [r0]\n\
	cmp r1, #1\n\
	bne _0824C8B0\n\
	movs r0, #0\n\
	b _0824C940\n\
	.align 2, 0\n\
_0824C8AC: .4byte rtc_lock\n\
_0824C8B0:\n\
	ldr r0, _0824C8E4 @ =rtc_lock\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, _0824C8E8 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C8E8 @ =ROM_GPIODATA\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	ldr r0, _0824C8EC @ =ROM_GPIODIR\n\
	movs r1, #7\n\
	strh r1, [r0]\n\
	movs r0, #0x65\n\
	bl RtcWriteCom\n\
	ldr r0, _0824C8EC @ =ROM_GPIODIR\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	adds r0, r7, #4\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
_0824C8DA:\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0]\n\
	cmp r1, #6\n\
	bls _0824C8F0\n\
	b _0824C90E\n\
	.align 2, 0\n\
_0824C8E4: .4byte rtc_lock\n\
_0824C8E8: .4byte ROM_GPIODATA\n\
_0824C8EC: .4byte ROM_GPIODIR\n\
_0824C8F0:\n\
	bl RtcReadData\n\
	adds r1, r7, #4\n\
	ldrb r2, [r1]\n\
	ldr r3, [r7]\n\
	adds r1, r2, r3\n\
	strb r0, [r1]\n\
	adds r1, r7, #4\n\
	adds r0, r7, #4\n\
	adds r1, r7, #4\n\
	ldrb r2, [r1]\n\
	adds r1, r2, #1\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	b _0824C8DA\n\
_0824C90E:\n\
	ldr r1, [r7]\n\
	adds r0, r1, #4\n\
	ldr r2, [r7]\n\
	adds r1, r2, #4\n\
	ldrb r2, [r1]\n\
	movs r3, #0x7f\n\
	adds r1, r2, #0\n\
	ands r1, r3\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	ldr r0, _0824C938 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C938 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C93C @ =rtc_lock\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	b _0824C940\n\
	.align 2, 0\n\
_0824C938: .4byte ROM_GPIODATA\n\
_0824C93C: .4byte rtc_lock\n\
_0824C940:\n\
	add sp, #8\n\
	pop {r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 RtcWriteDate(RtcDataOrg* r) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	sub sp, #8\n\
	mov r7, sp\n\
	str r0, [r7]\n\
	ldr r0, _0824C95C @ =rtc_lock\n\
	ldrb r1, [r0]\n\
	cmp r1, #1\n\
	bne _0824C960\n\
	movs r0, #0\n\
	b _0824C9DC\n\
	.align 2, 0\n\
_0824C95C: .4byte rtc_lock\n\
_0824C960:\n\
	ldr r0, _0824C990 @ =rtc_lock\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, _0824C994 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C994 @ =ROM_GPIODATA\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	ldr r0, _0824C998 @ =ROM_GPIODIR\n\
	movs r1, #7\n\
	strh r1, [r0]\n\
	movs r0, #0x64\n\
	bl RtcWriteCom\n\
	adds r0, r7, #4\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
_0824C984:\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0]\n\
	cmp r1, #6\n\
	bls _0824C99C\n\
	b _0824C9BC\n\
	.align 2, 0\n\
_0824C990: .4byte rtc_lock\n\
_0824C994: .4byte ROM_GPIODATA\n\
_0824C998: .4byte ROM_GPIODIR\n\
_0824C99C:\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0]\n\
	ldr r2, [r7]\n\
	adds r0, r1, r2\n\
	ldrb r1, [r0]\n\
	adds r0, r1, #0\n\
	bl RtcWriteData\n\
	adds r1, r7, #4\n\
	adds r0, r7, #4\n\
	adds r1, r7, #4\n\
	ldrb r2, [r1]\n\
	adds r1, r2, #1\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	b _0824C984\n\
_0824C9BC:\n\
	ldr r0, _0824C9D4 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C9D4 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824C9D8 @ =rtc_lock\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	b _0824C9DC\n\
	.align 2, 0\n\
_0824C9D4: .4byte ROM_GPIODATA\n\
_0824C9D8: .4byte rtc_lock\n\
_0824C9DC:\n\
	add sp, #8\n\
	pop {r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 RtcReadTime(RtcDataOrg* r) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	sub sp, #8\n\
	mov r7, sp\n\
	str r0, [r7]\n\
	ldr r0, _0824C9F8 @ =rtc_lock\n\
	ldrb r1, [r0]\n\
	cmp r1, #1\n\
	bne _0824C9FC\n\
	movs r0, #0\n\
	b _0824CA90\n\
	.align 2, 0\n\
_0824C9F8: .4byte rtc_lock\n\
_0824C9FC:\n\
	ldr r0, _0824CA30 @ =rtc_lock\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, _0824CA34 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824CA34 @ =ROM_GPIODATA\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	ldr r0, _0824CA38 @ =ROM_GPIODIR\n\
	movs r1, #7\n\
	strh r1, [r0]\n\
	movs r0, #0x67\n\
	bl RtcWriteCom\n\
	ldr r0, _0824CA38 @ =ROM_GPIODIR\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	adds r0, r7, #4\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
_0824CA26:\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0]\n\
	cmp r1, #2\n\
	bls _0824CA3C\n\
	b _0824CA5C\n\
	.align 2, 0\n\
_0824CA30: .4byte rtc_lock\n\
_0824CA34: .4byte ROM_GPIODATA\n\
_0824CA38: .4byte ROM_GPIODIR\n\
_0824CA3C:\n\
	bl RtcReadData\n\
	adds r1, r7, #4\n\
	ldrb r2, [r1]\n\
	ldr r3, [r7]\n\
	adds r1, r2, r3\n\
	adds r2, r1, #4\n\
	strb r0, [r2]\n\
	adds r1, r7, #4\n\
	adds r0, r7, #4\n\
	adds r1, r7, #4\n\
	ldrb r2, [r1]\n\
	adds r1, r2, #1\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	b _0824CA26\n\
_0824CA5C:\n\
	ldr r1, [r7]\n\
	adds r0, r1, #4\n\
	ldr r2, [r7]\n\
	adds r1, r2, #4\n\
	ldrb r2, [r1]\n\
	movs r3, #0x7f\n\
	adds r1, r2, #0\n\
	ands r1, r3\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	ldr r0, _0824CA88 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824CA88 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824CA8C @ =rtc_lock\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	b _0824CA90\n\
	.align 2, 0\n\
_0824CA88: .4byte ROM_GPIODATA\n\
_0824CA8C: .4byte rtc_lock\n\
_0824CA90:\n\
	add sp, #8\n\
	pop {r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 RtcWriteTime(RtcDataOrg* r) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	sub sp, #8\n\
	mov r7, sp\n\
	str r0, [r7]\n\
	ldr r0, _0824CAAC @ =rtc_lock\n\
	ldrb r1, [r0]\n\
	cmp r1, #1\n\
	bne _0824CAB0\n\
	movs r0, #0\n\
	b _0824CB2C\n\
	.align 2, 0\n\
_0824CAAC: .4byte rtc_lock\n\
_0824CAB0:\n\
	ldr r0, _0824CAE0 @ =rtc_lock\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, _0824CAE4 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824CAE4 @ =ROM_GPIODATA\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	ldr r0, _0824CAE8 @ =ROM_GPIODIR\n\
	movs r1, #7\n\
	strh r1, [r0]\n\
	movs r0, #0x66\n\
	bl RtcWriteCom\n\
	adds r0, r7, #4\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
_0824CAD4:\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0]\n\
	cmp r1, #2\n\
	bls _0824CAEC\n\
	b _0824CB0E\n\
	.align 2, 0\n\
_0824CAE0: .4byte rtc_lock\n\
_0824CAE4: .4byte ROM_GPIODATA\n\
_0824CAE8: .4byte ROM_GPIODIR\n\
_0824CAEC:\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0]\n\
	ldr r2, [r7]\n\
	adds r0, r1, r2\n\
	adds r1, r0, #4\n\
	ldrb r2, [r1]\n\
	adds r0, r2, #0\n\
	bl RtcWriteData\n\
	adds r1, r7, #4\n\
	adds r0, r7, #4\n\
	adds r1, r7, #4\n\
	ldrb r2, [r1]\n\
	adds r1, r2, #1\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	b _0824CAD4\n\
_0824CB0E:\n\
	ldr r0, _0824CB24 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824CB24 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824CB28 @ =rtc_lock\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	b _0824CB2C\n\
	.align 2, 0\n\
_0824CB24: .4byte ROM_GPIODATA\n\
_0824CB28: .4byte rtc_lock\n\
_0824CB2C:\n\
	add sp, #8\n\
	pop {r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED u8 RtcWriteAlarm(RtcDataOrg* r) {
  asm(".syntax unified\n\
	push {r4, r7, lr}\n\
	sub sp, #0xc\n\
	mov r7, sp\n\
	str r0, [r7]\n\
	ldr r0, _0824CB48 @ =rtc_lock\n\
	ldrb r1, [r0]\n\
	cmp r1, #1\n\
	bne _0824CB4C\n\
	movs r0, #0\n\
	b _0824CC60\n\
	.align 2, 0\n\
_0824CB48: .4byte rtc_lock\n\
_0824CB4C:\n\
	ldr r0, _0824CBB4 @ =rtc_lock\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	adds r0, r7, #0\n\
	adds r0, #8\n\
	ldr r1, [r7]\n\
	ldrb r2, [r1, #8]\n\
	movs r3, #0xf\n\
	adds r1, r2, #0\n\
	ands r1, r3\n\
	ldr r2, [r7]\n\
	ldrb r3, [r2, #8]\n\
	lsrs r2, r3, #4\n\
	adds r3, r2, #0\n\
	movs r4, #0xf\n\
	adds r2, r3, #0\n\
	ands r2, r4\n\
	adds r4, r2, #0\n\
	lsls r3, r4, #0x18\n\
	lsrs r2, r3, #0x18\n\
	adds r4, r2, #0\n\
	lsls r3, r4, #2\n\
	adds r3, r3, r2\n\
	lsls r2, r3, #1\n\
	adds r1, r1, r2\n\
	ldrb r2, [r0]\n\
	movs r3, #0\n\
	ands r2, r3\n\
	adds r3, r2, #0\n\
	adds r2, r3, #0\n\
	orrs r2, r1\n\
	adds r1, r2, #0\n\
	strb r1, [r0]\n\
	adds r0, r7, #0\n\
	adds r0, #8\n\
	ldrb r1, [r0]\n\
	cmp r1, #0xb\n\
	bhi _0824CBB8\n\
	adds r0, r7, #0\n\
	adds r0, #8\n\
	ldr r1, [r7]\n\
	ldrb r2, [r0]\n\
	movs r3, #0\n\
	ands r2, r3\n\
	adds r3, r2, #0\n\
	ldrb r1, [r1, #8]\n\
	adds r2, r3, #0\n\
	orrs r2, r1\n\
	adds r1, r2, #0\n\
	strb r1, [r0]\n\
	b _0824CBD6\n\
	.align 2, 0\n\
_0824CBB4: .4byte rtc_lock\n\
_0824CBB8:\n\
	adds r0, r7, #0\n\
	adds r0, #8\n\
	ldr r1, [r7]\n\
	ldrb r2, [r1, #8]\n\
	movs r3, #0x80\n\
	adds r1, r2, #0\n\
	orrs r1, r3\n\
	ldrb r2, [r0]\n\
	movs r3, #0\n\
	ands r2, r3\n\
	adds r3, r2, #0\n\
	adds r2, r3, #0\n\
	orrs r2, r1\n\
	adds r1, r2, #0\n\
	strb r1, [r0]\n\
_0824CBD6:\n\
	adds r0, r7, #0\n\
	adds r0, #8\n\
	ldr r1, [r7]\n\
	ldrb r2, [r0, #1]\n\
	movs r3, #0\n\
	ands r2, r3\n\
	adds r3, r2, #0\n\
	ldrb r1, [r1, #9]\n\
	adds r2, r3, #0\n\
	orrs r2, r1\n\
	adds r1, r2, #0\n\
	strb r1, [r0, #1]\n\
	ldr r0, _0824CC18 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824CC18 @ =ROM_GPIODATA\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	ldr r0, _0824CC1C @ =ROM_GPIODIR\n\
	movs r1, #7\n\
	strh r1, [r0]\n\
	movs r0, #0x68\n\
	bl RtcWriteCom\n\
	adds r0, r7, #4\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
_0824CC0C:\n\
	adds r0, r7, #4\n\
	ldrb r1, [r0]\n\
	cmp r1, #1\n\
	bls _0824CC20\n\
	b _0824CC42\n\
	.align 2, 0\n\
_0824CC18: .4byte ROM_GPIODATA\n\
_0824CC1C: .4byte ROM_GPIODIR\n\
_0824CC20:\n\
	adds r0, r7, #0\n\
	adds r0, #8\n\
	adds r1, r7, #4\n\
	ldrb r2, [r1]\n\
	adds r0, r0, r2\n\
	ldrb r1, [r0]\n\
	adds r0, r1, #0\n\
	bl RtcWriteData\n\
	adds r1, r7, #4\n\
	adds r0, r7, #4\n\
	adds r1, r7, #4\n\
	ldrb r2, [r1]\n\
	adds r1, r2, #1\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	b _0824CC0C\n\
_0824CC42:\n\
	ldr r0, _0824CC58 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824CC58 @ =ROM_GPIODATA\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r0, _0824CC5C @ =rtc_lock\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	b _0824CC60\n\
	.align 2, 0\n\
_0824CC58: .4byte ROM_GPIODATA\n\
_0824CC5C: .4byte rtc_lock\n\
_0824CC60:\n\
	add sp, #0xc\n\
	pop {r4, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// pret: WriteCommand
NAKED static s32 RtcWriteCom(u8 value) {
  asm(".syntax unified\n\
	push {r4, r5, r7, lr}\n\
	sub sp, #4\n\
	mov r7, sp\n\
	adds r1, r0, #0\n\
	adds r2, r7, #0\n\
	strb r1, [r2]\n\
	adds r1, r7, #1\n\
	movs r2, #0\n\
	strb r2, [r1]\n\
_0824CC7A:\n\
	adds r1, r7, #1\n\
	ldrb r2, [r1]\n\
	cmp r2, #7\n\
	bls _0824CC84\n\
	b _0824CD04\n\
_0824CC84:\n\
	adds r1, r7, #2\n\
	adds r3, r7, #0\n\
	ldrb r2, [r3]\n\
	adds r3, r7, #1\n\
	ldrb r4, [r3]\n\
	movs r5, #7\n\
	subs r3, r5, r4\n\
	asrs r2, r3\n\
	adds r3, r2, #0\n\
	movs r4, #1\n\
	adds r2, r3, #0\n\
	ands r2, r4\n\
	adds r3, r2, #0\n\
	strb r3, [r1]\n\
	ldr r1, _0824CD00 @ =ROM_GPIODATA\n\
	adds r2, r7, #2\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #0\n\
	lsls r3, r2, #1\n\
	adds r2, r3, #0\n\
	movs r3, #4\n\
	orrs r2, r3\n\
	adds r3, r2, #0\n\
	strh r3, [r1]\n\
	ldr r1, _0824CD00 @ =ROM_GPIODATA\n\
	adds r2, r7, #2\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #0\n\
	lsls r3, r2, #1\n\
	adds r2, r3, #0\n\
	movs r3, #4\n\
	orrs r2, r3\n\
	adds r3, r2, #0\n\
	strh r3, [r1]\n\
	ldr r1, _0824CD00 @ =ROM_GPIODATA\n\
	adds r2, r7, #2\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #0\n\
	lsls r3, r2, #1\n\
	adds r2, r3, #0\n\
	movs r3, #4\n\
	orrs r2, r3\n\
	adds r3, r2, #0\n\
	strh r3, [r1]\n\
	ldr r1, _0824CD00 @ =ROM_GPIODATA\n\
	adds r2, r7, #2\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #0\n\
	lsls r3, r2, #1\n\
	adds r2, r3, #0\n\
	movs r3, #5\n\
	orrs r2, r3\n\
	adds r3, r2, #0\n\
	strh r3, [r1]\n\
	adds r2, r7, #1\n\
	adds r1, r7, #1\n\
	adds r2, r7, #1\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #1\n\
	adds r3, r2, #0\n\
	strb r3, [r1]\n\
	b _0824CC7A\n\
	.align 2, 0\n\
_0824CD00: .4byte ROM_GPIODATA\n\
_0824CD04:\n\
	add sp, #4\n\
	pop {r4, r5, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// pret: WriteData
NAKED static s32 RtcWriteData(u8 value) {
  asm(".syntax unified\n\
	push {r4, r7, lr}\n\
	sub sp, #4\n\
	mov r7, sp\n\
	adds r1, r0, #0\n\
	adds r2, r7, #0\n\
	strb r1, [r2]\n\
	adds r1, r7, #1\n\
	movs r2, #0\n\
	strb r2, [r1]\n\
_0824CD1E:\n\
	adds r1, r7, #1\n\
	ldrb r2, [r1]\n\
	cmp r2, #7\n\
	bls _0824CD28\n\
	b _0824CDA4\n\
_0824CD28:\n\
	adds r1, r7, #2\n\
	adds r3, r7, #0\n\
	ldrb r2, [r3]\n\
	adds r3, r7, #1\n\
	ldrb r4, [r3]\n\
	asrs r2, r4\n\
	adds r3, r2, #0\n\
	movs r4, #1\n\
	adds r2, r3, #0\n\
	ands r2, r4\n\
	adds r3, r2, #0\n\
	strb r3, [r1]\n\
	ldr r1, _0824CDA0 @ =ROM_GPIODATA\n\
	adds r2, r7, #2\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #0\n\
	lsls r3, r2, #1\n\
	adds r2, r3, #0\n\
	movs r3, #4\n\
	orrs r2, r3\n\
	adds r3, r2, #0\n\
	strh r3, [r1]\n\
	ldr r1, _0824CDA0 @ =ROM_GPIODATA\n\
	adds r2, r7, #2\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #0\n\
	lsls r3, r2, #1\n\
	adds r2, r3, #0\n\
	movs r3, #4\n\
	orrs r2, r3\n\
	adds r3, r2, #0\n\
	strh r3, [r1]\n\
	ldr r1, _0824CDA0 @ =ROM_GPIODATA\n\
	adds r2, r7, #2\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #0\n\
	lsls r3, r2, #1\n\
	adds r2, r3, #0\n\
	movs r3, #4\n\
	orrs r2, r3\n\
	adds r3, r2, #0\n\
	strh r3, [r1]\n\
	ldr r1, _0824CDA0 @ =ROM_GPIODATA\n\
	adds r2, r7, #2\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #0\n\
	lsls r3, r2, #1\n\
	adds r2, r3, #0\n\
	movs r3, #5\n\
	orrs r2, r3\n\
	adds r3, r2, #0\n\
	strh r3, [r1]\n\
	adds r2, r7, #1\n\
	adds r1, r7, #1\n\
	adds r2, r7, #1\n\
	ldrb r3, [r2]\n\
	adds r2, r3, #1\n\
	adds r3, r2, #0\n\
	strb r3, [r1]\n\
	b _0824CD1E\n\
	.align 2, 0\n\
_0824CDA0: .4byte ROM_GPIODATA\n\
_0824CDA4:\n\
	add sp, #4\n\
	pop {r4, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// pret: ReadData
NAKED static u8 RtcReadData(void) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	sub sp, #4\n\
	mov r7, sp\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
_0824CDB8:\n\
	adds r0, r7, #0\n\
	ldrb r1, [r0]\n\
	cmp r1, #7\n\
	bls _0824CDC2\n\
	b _0824CE28\n\
_0824CDC2:\n\
	ldr r0, _0824CE24 @ =ROM_GPIODATA\n\
	movs r1, #4\n\
	strh r1, [r0]\n\
	ldr r0, _0824CE24 @ =ROM_GPIODATA\n\
	movs r1, #4\n\
	strh r1, [r0]\n\
	ldr r0, _0824CE24 @ =ROM_GPIODATA\n\
	movs r1, #4\n\
	strh r1, [r0]\n\
	ldr r0, _0824CE24 @ =ROM_GPIODATA\n\
	movs r1, #4\n\
	strh r1, [r0]\n\
	ldr r0, _0824CE24 @ =ROM_GPIODATA\n\
	movs r1, #4\n\
	strh r1, [r0]\n\
	ldr r0, _0824CE24 @ =ROM_GPIODATA\n\
	movs r1, #5\n\
	strh r1, [r0]\n\
	adds r0, r7, #1\n\
	ldr r1, _0824CE24 @ =ROM_GPIODATA\n\
	ldrh r2, [r1]\n\
	movs r3, #2\n\
	adds r1, r2, #0\n\
	ands r1, r3\n\
	adds r3, r1, #0\n\
	lsls r2, r3, #0x10\n\
	lsrs r1, r2, #0x10\n\
	lsrs r2, r1, #1\n\
	adds r1, r2, #0\n\
	strb r1, [r0]\n\
	adds r0, r7, #2\n\
	adds r1, r7, #2\n\
	ldrb r2, [r1]\n\
	lsrs r1, r2, #1\n\
	adds r2, r7, #1\n\
	ldrb r3, [r2]\n\
	lsls r2, r3, #7\n\
	orrs r1, r2\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	adds r1, r7, #0\n\
	adds r0, r7, #0\n\
	adds r1, r7, #0\n\
	ldrb r2, [r1]\n\
	adds r1, r2, #1\n\
	adds r2, r1, #0\n\
	strb r2, [r0]\n\
	b _0824CDB8\n\
	.align 2, 0\n\
_0824CE24: .4byte ROM_GPIODATA\n\
_0824CE28:\n\
	adds r0, r7, #2\n\
	ldrb r1, [r0]\n\
	adds r0, r1, #0\n\
	b _0824CE30\n\
_0824CE30:\n\
	add sp, #4\n\
	pop {r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// libagbrtc/gpiorom.c

// pret: EnableGpioPortRead
NAKED static void GpioReadEnable(void) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	mov r7, sp\n\
	ldr r0, _0824CE48 @ =ROM_GPIOCNT\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	pop {r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0824CE48: .4byte ROM_GPIOCNT\n\
 .syntax divided\n");
}

// pret: DisableGpioPortRead
NAKED static void GpioReadDisable(void) {
  asm(".syntax unified\n\
	push {r7, lr}\n\
	mov r7, sp\n\
	ldr r0, _0824CE5C @ =ROM_GPIOCNT\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	pop {r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0824CE5C: .4byte ROM_GPIOCNT\n\
 .syntax divided\n");
}
