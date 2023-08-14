#include "global.h"

NAKED void AgbMain(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	sub sp, #4\n\
	ldr r1, _08000408 @ =0x04000204\n\
	ldr r2, _0800040C @ =0x00004014\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r5, _08000410 @ =0x02020400\n\
	ldr r0, [r5]\n\
	mov r8, r0\n\
	ldr r4, _08000414 @ =0x02020404\n\
	ldr r6, [r4]\n\
	movs r0, #1\n\
	bl RegisterRamReset\n\
	mov r2, r8\n\
	str r2, [r5]\n\
	str r6, [r4]\n\
	movs r4, #0\n\
	str r4, [sp]\n\
	ldr r1, _08000418 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0x12\n\
	str r0, [r1, #4]\n\
	ldr r0, _0800041C @ =0x85001F40\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	bl FUN_0824c598\n\
	bl FUN_0823d91c\n\
	bl FUN_0823e4ec\n\
	bl m4aSoundInit\n\
	bl FUN_08229cc4\n\
	movs r0, #0x40\n\
	bl EEPROMConfigure\n\
	bl FUN_0823a870\n\
	bl FUN_08231c28\n\
	bl FUN_08230734\n\
	bl FUN_08229d80\n\
	bl FUN_082326a0\n\
	bl FUN_0822b0a0\n\
	ldr r0, _08000420 @ =0x0000CEAA\n\
	ldr r1, _08000424 @ =0x00003002\n\
	bl FUN_082310cc\n\
	bl FUN_0822b0d0\n\
	ldr r0, _08000428 @ =0x000098F5\n\
	ldr r1, _0800042C @ =0x0000FF54\n\
	bl FUN_082310cc\n\
	bl FUN_0822b148\n\
	ldr r3, _08000430 @ =0x04000208\n\
	strh r4, [r3]\n\
	ldr r1, _08000434 @ =0x04000200\n\
	ldrh r2, [r1]\n\
	strh r4, [r1]\n\
	movs r0, #4\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	bl FUN_08237e98\n\
	ldr r0, _08000438 @ =0x0023A666\n\
	ldr r1, _0800043C @ =0x008BC000\n\
	movs r2, #0\n\
	bl FUN_082401e8\n\
	bl FUN_08231bec\n\
	bl FUN_0823acbc\n\
_08000400:\n\
	bl entity_08230c00\n\
	b _08000400\n\
	.align 2, 0\n\
_08000408: .4byte 0x04000204\n\
_0800040C: .4byte 0x00004014\n\
_08000410: .4byte 0x02020400\n\
_08000414: .4byte 0x02020404\n\
_08000418: .4byte 0x040000D4\n\
_0800041C: .4byte 0x85001F40\n\
_08000420: .4byte 0x0000CEAA\n\
_08000424: .4byte 0x00003002\n\
_08000428: .4byte 0x000098F5\n\
_0800042C: .4byte 0x0000FF54\n\
_08000430: .4byte 0x04000208\n\
_08000434: .4byte 0x04000200\n\
_08000438: .4byte 0x0023A666\n\
_0800043C: .4byte 0x008BC000\n\
 .syntax divided\n");
}
