	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_08188784
FUN_08188784: @ 0x08188784
	push {r4, r5, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	movs r5, #0xcb
	lsls r5, r5, #3
	adds r4, r2, r5
	ldr r0, [r4]
	lsls r0, r0, #2
	adds r0, r2, r0
	ldrh r3, [r1, #2]
	adds r5, #4
	adds r0, r0, r5
	strh r3, [r0]
	ldr r0, [r4]
	lsls r0, r0, #2
	adds r2, r2, r0
	ldrh r0, [r1, #4]
	ldr r1, _081887BC @ =0x0000065E
	adds r2, r2, r1
	strh r0, [r2]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081887BC: .4byte 0x0000065E

	thumb_func_start FUN_081887c0
FUN_081887c0: @ 0x081887C0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081887d8
FUN_081887d8: @ 0x081887D8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	mov r1, sp
	movs r0, #9
	strh r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _08188848 @ =0x0000065C
	adds r4, r0, r2
	movs r5, #0xf
_081887F2:
	ldrh r0, [r4]
	cmp r0, #0
	beq _08188802
	ldrb r0, [r4, #2]
	ldrh r2, [r4]
	mov r1, sp
	bl FUN_080ec848
_08188802:
	adds r4, #4
	subs r5, #1
	cmp r5, #0
	bge _081887F2
	ldr r4, _0818884C @ =0x030046A0
	ldr r0, [r4]
	ldr r3, _08188850 @ =0x00000948
	adds r1, r0, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r3, _08188854 @ =0x0000270E
	cmp r0, r3
	bgt _08188822
	adds r0, r2, #1
	strh r0, [r1]
_08188822:
	ldr r0, [r4]
	movs r4, #0xf8
	lsls r4, r4, #1
	adds r1, r0, r4
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bgt _08188838
	adds r0, r2, #1
	strh r0, [r1]
_08188838:
	adds r0, r6, #0
	bl FUN_080e9178
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08188848: .4byte 0x0000065C
_0818884C: .4byte 0x030046A0
_08188850: .4byte 0x00000948
_08188854: .4byte 0x0000270E

	thumb_func_start FUN_08188858
FUN_08188858: @ 0x08188858
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r4, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	bgt _08188892
	adds r0, r4, #0
	bl FUN_081887d8
	adds r0, r4, #0
	bl FUN_0818889c
	adds r0, r4, #0
	bl Free
_08188892:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0818889c
FUN_0818889c: @ 0x0818889C
	push {lr}
	bl FUN_080ec6fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_081888a8
FUN_081888a8: @ 0x081888A8
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	adds r5, r0, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_080e37e8
	strh r4, [r5]
	ldr r0, _08188900 @ =0x000001DF
	adds r1, r5, r0
	movs r0, #0xf
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0818890E
	movs r0, #0xce
	lsls r0, r0, #1
	adds r6, r5, r0
	movs r4, #4
_081888F2:
	bl VM_GetPC
	cmp r0, #0
	beq _08188904
	bl Script_GetValue
	b _08188906
	.align 2, 0
_08188900: .4byte 0x000001DF
_08188904:
	movs r0, #0
_08188906:
	stm r6!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081888F2
_0818890E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xcd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _08188950 @ =0x0000060C
	adds r1, r5, r0
	ldr r0, _08188954 @ =0x085ADCD0
	str r0, [r1]
	ldr r2, _08188958 @ =0x0000057C
	adds r1, r5, r2
	ldr r0, _0818895C @ =FUN_080f09e0
	str r0, [r1]
	ldr r0, _08188960 @ =0x0000061C
	adds r1, r5, r0
	ldr r0, _08188964 @ =FUN_08188858
	str r0, [r1]
	adds r2, #0xa4
	adds r1, r5, r2
	ldr r0, _08188968 @ =FUN_0818889c
	str r0, [r1]
	adds r0, r5, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818896C
	movs r0, #0
	b _08188970
	.align 2, 0
_08188950: .4byte 0x0000060C
_08188954: .4byte 0x085ADCD0
_08188958: .4byte 0x0000057C
_0818895C: .4byte FUN_080f09e0
_08188960: .4byte 0x0000061C
_08188964: .4byte FUN_08188858
_08188968: .4byte FUN_0818889c
_0818896C:
	movs r0, #1
	rsbs r0, r0, #0
_08188970:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08188978
FUN_08188978: @ 0x08188978
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_080edda0
	cmp r0, #0
	bne _081889B0
	ldr r5, _081889B8 @ =0x0000069C
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081889B0
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_081888a8
	cmp r0, #0
	bge _081889B0
	adds r0, r4, #0
	bl FUN_0818889c
	adds r0, r4, #0
	bl Free
_081889B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081889B8: .4byte 0x0000069C

	thumb_func_start FUN_081889bc
FUN_081889bc: @ 0x081889BC
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081889F0
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081889F0
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _081889F8 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081889F0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081889F8: .4byte 0xFEFFFFFF

	thumb_func_start FUN_081889fc
FUN_081889fc: @ 0x081889FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08188A1C
	b _081890EC
_08188A1C:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x20
	ldr r2, _08188A38 @ =0x00000F2C
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08188A3C
	movs r0, #1
	b _08188A3E
	.align 2, 0
_08188A38: .4byte 0x00000F2C
_08188A3C:
	movs r0, #0
_08188A3E:
	cmp r0, #0
	beq _08188A44
	b _081890EC
_08188A44:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08188A54
	b _081890D8
_08188A54:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _08188A7C
	ldr r4, _08188A78 @ =0x0000048C
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08188A6C
	b _081890D8
_08188A6C:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081890D8
	.align 2, 0
_08188A78: .4byte 0x0000048C
_08188A7C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08188A8C
	b _081890D8
_08188A8C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08188A9C
	b _08188DA8
_08188A9C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _08188AAE
	b _081890D8
_08188AAE:
	ldr r2, _08188B40 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08188AC2
	b _081890D8
_08188AC2:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08188AD0
	b _081890D8
_08188AD0:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _08188AE8
	b _08188C30
_08188AE8:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08188B50
	ands r3, r1
	cmp r3, #0
	beq _08188B50
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08188B0E
	rsbs r1, r1, #0
_08188B0E:
	cmp r1, #0x20
	bgt _08188B50
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08188B44 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08188B48 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08188B4C @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081890D8
	.align 2, 0
_08188B40: .4byte 0x0000A007
_08188B44: .4byte 0x000004BE
_08188B48: .4byte 0x0000048C
_08188B4C: .4byte 0x0000044E
_08188B50:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08188B78 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08188B80
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188B7C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08188BEE
	.align 2, 0
_08188B78: .4byte 0x0000048A
_08188B7C: .4byte 0x03002BE0
_08188B80:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08188B9C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08188B98 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08188BEE
	.align 2, 0
_08188B98: .4byte 0x03002BE0
_08188B9C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08188BB8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08188BB4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08188BEE
	.align 2, 0
_08188BB4: .4byte 0x03002BE0
_08188BB8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08188BD4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08188BD0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08188BEE
	.align 2, 0
_08188BD0: .4byte 0x03002BE0
_08188BD4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08188BE6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08188BEE
_08188BE6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08188BF0
_08188BEE:
	movs r3, #1
_08188BF0:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _08188C24 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08188C12
	b _08188D68
_08188C12:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08188C28
	movs r0, #1
	b _08188C2A
	.align 2, 0
_08188C24: .4byte 0x0000049C
_08188C28:
	movs r0, #0
_08188C2A:
	cmp r0, #0
	bne _08188D0E
	b _08188D24
_08188C30:
	strh r2, [r7, #0x3e]
	ldr r1, _08188C58 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08188C60
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188C5C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08188CCE
	.align 2, 0
_08188C58: .4byte 0x0000048A
_08188C5C: .4byte 0x03002BE0
_08188C60:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08188C7C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08188C78 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08188CCE
	.align 2, 0
_08188C78: .4byte 0x03002BE0
_08188C7C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08188C98
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08188C94 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08188CCE
	.align 2, 0
_08188C94: .4byte 0x03002BE0
_08188C98:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08188CB4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08188CB0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08188CCE
	.align 2, 0
_08188CB0: .4byte 0x03002BE0
_08188CB4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08188CC6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08188CCE
_08188CC6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08188CD0
_08188CCE:
	movs r3, #1
_08188CD0:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _08188D04 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08188D68
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08188D08
	movs r0, #1
	b _08188D0A
	.align 2, 0
_08188D04: .4byte 0x0000049C
_08188D08:
	movs r0, #0
_08188D0A:
	cmp r0, #0
	beq _08188D24
_08188D0E:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188D20 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08188D30
	.align 2, 0
_08188D20: .4byte 0x03002BE0
_08188D24:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08188D68
_08188D30:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08188D68:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08188D94
	ldr r5, _08188DA0 @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08188D94
	strh r1, [r2]
_08188D94:
	ldr r5, _08188DA4 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081890D8
	.align 2, 0
_08188DA0: .4byte 0x0000024E
_08188DA4: .4byte 0x0000048C
_08188DA8:
	ldr r0, _08188DBC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08188DC0
	movs r0, #1
	b _08188DC2
	.align 2, 0
_08188DBC: .4byte 0x030047A4
_08188DC0:
	movs r0, #0
_08188DC2:
	cmp r0, #0
	beq _08188DD0
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _08188DD8
_08188DD0:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_08188DD8:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08188E10 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08188E14 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08188E06
	cmp r2, #0x17
	bne _08188E18
_08188E06:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _08188E3A
	.align 2, 0
_08188E10: .4byte 0x0000048C
_08188E14: .4byte 0x000001DF
_08188E18:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08188E06
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08188E68 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08188E3A
	movs r1, #0
_08188E3A:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08188E76
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08188E6C
	asrs r0, r0, #1
	b _08188E72
	.align 2, 0
_08188E68: .4byte 0x00000187
_08188E6C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08188E72:
	mov r2, sb
	strh r0, [r2]
_08188E76:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08188E94
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08188E90 @ =0x000001DD
	adds r1, r6, r4
	b _08188F08
	.align 2, 0
_08188E90: .4byte 0x000001DD
_08188E94:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08188EF4
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08188EF4
	ldr r2, _08188EE4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08188EE8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08188EEC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08188EF0 @ =0x000001DD
	adds r1, r6, r4
	b _08188F08
	.align 2, 0
_08188EE4: .4byte 0x030046B8
_08188EE8: .4byte 0x000003FF
_08188EEC: .4byte 0x0203B400
_08188EF0: .4byte 0x000001DD
_08188EF4:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08188F28 @ =0x000001DD
	adds r1, r6, r3
_08188F08:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08188F30
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08188F2C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08188F9E
	.align 2, 0
_08188F28: .4byte 0x000001DD
_08188F2C: .4byte 0x03002BE0
_08188F30:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08188F4C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08188F48 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08188F9E
	.align 2, 0
_08188F48: .4byte 0x03002BE0
_08188F4C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08188F68
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188F64 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08188F9E
	.align 2, 0
_08188F64: .4byte 0x03002BE0
_08188F68:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08188F84
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08188F80 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08188F9E
	.align 2, 0
_08188F80: .4byte 0x03002BE0
_08188F84:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08188F96
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08188F9E
_08188F96:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08188FA0
_08188F9E:
	movs r3, #1
_08188FA0:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _08188FD4 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0818903C
	movs r1, #2
	ldr r2, _08188FD8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08188FDC
	movs r0, #1
	b _08188FDE
	.align 2, 0
_08188FD4: .4byte 0x0000049C
_08188FD8: .4byte 0x00000474
_08188FDC:
	movs r0, #0
_08188FDE:
	cmp r0, #0
	beq _08188FF8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188FF4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08189004
	.align 2, 0
_08188FF4: .4byte 0x03002BE0
_08188FF8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0818903C
_08189004:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0818903C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08189070
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08189070
	ldr r0, _08189088 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08189070
	strh r1, [r2]
_08189070:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0818908C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08189090 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08189094
	movs r0, #1
	b _08189096
	.align 2, 0
_08189088: .4byte 0x0000024E
_0818908C: .4byte 0x030046A0
_08189090: .4byte 0x00000934
_08189094:
	movs r0, #0
_08189096:
	ldr r1, _081890FC @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081890AE
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081890AE:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081890D8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x40
	ldr r2, _08189100 @ =0x00000F2C
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
_081890EC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081890FC: .4byte 0x0000048A
_08189100: .4byte 0x00000F2C

	thumb_func_start FUN_08189104
FUN_08189104: @ 0x08189104
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08189120 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08189124
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08189126
	.align 2, 0
_08189120: .4byte 0x0000046D
_08189124:
	movs r0, #0
_08189126:
	cmp r0, #0
	beq _0818920E
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0818e6cc
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0818916C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08189178
	ldr r1, _08189170 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08189174 @ =0x0000046E
	adds r7, r5, r0
	b _081891FA
	.align 2, 0
_0818916C: .4byte 0x0000025D
_08189170: .4byte 0x000004B7
_08189174: .4byte 0x0000046E
_08189178:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081891E8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081891EC @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081891B2
	ldrb r0, [r7]
	cmp r0, #0
	bne _081891B2
	cmp r4, #1
	bne _081891A4
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081891FE
_081891A4:
	cmp r4, #0
	bne _081891B2
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081891FE
_081891B2:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081891C4
	movs r3, #6
_081891C4:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081891F0
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081891F8
	.align 2, 0
_081891E8: .4byte 0x000004B7
_081891EC: .4byte 0x0000046E
_081891F0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081891F8:
	str r0, [r6, #8]
_081891FA:
	movs r0, #0
	strb r0, [r7]
_081891FE:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	b _081892F0
_0818920E:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0818e6cc
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08189250 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818925C
	ldr r1, _08189254 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08189258 @ =0x0000046E
	adds r7, r5, r0
	b _081892DE
	.align 2, 0
_08189250: .4byte 0x0000025D
_08189254: .4byte 0x000004B7
_08189258: .4byte 0x0000046E
_0818925C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081892CC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081892D0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08189296
	ldrb r0, [r7]
	cmp r0, #0
	bne _08189296
	cmp r4, #1
	bne _08189288
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081892E2
_08189288:
	cmp r4, #0
	bne _08189296
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081892E2
_08189296:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081892A8
	movs r3, #6
_081892A8:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081892D4
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081892DC
	.align 2, 0
_081892CC: .4byte 0x000004B7
_081892D0: .4byte 0x0000046E
_081892D4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081892DC:
	str r0, [r6, #8]
_081892DE:
	movs r0, #0
	strb r0, [r7]
_081892E2:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
_081892F0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081892fc
FUN_081892fc: @ 0x081892FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08189318 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818931C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818931E
	.align 2, 0
_08189318: .4byte 0x0000046D
_0818931C:
	movs r0, #0
_0818931E:
	cmp r0, #0
	beq _0818940A
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0818e6cc
	ldr r1, _08189364 @ =0x00000504
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08189368 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08189374
	ldr r1, _0818936C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08189370 @ =0x0000046E
	adds r7, r5, r0
	b _081893F6
	.align 2, 0
_08189364: .4byte 0x00000504
_08189368: .4byte 0x0000025D
_0818936C: .4byte 0x000004B7
_08189370: .4byte 0x0000046E
_08189374:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081893E4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081893E8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081893AE
	ldrb r0, [r7]
	cmp r0, #0
	bne _081893AE
	cmp r4, #1
	bne _081893A0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081893FA
_081893A0:
	cmp r4, #0
	bne _081893AE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081893FA
_081893AE:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081893C0
	movs r3, #6
_081893C0:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081893EC
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081893F4
	.align 2, 0
_081893E4: .4byte 0x000004B7
_081893E8: .4byte 0x0000046E
_081893EC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081893F4:
	str r0, [r6, #8]
_081893F6:
	movs r0, #0
	strb r0, [r7]
_081893FA:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	b _081894F0
_0818940A:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0818e6cc
	ldr r1, _0818944C @ =0x00000504
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08189450 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818945C
	ldr r1, _08189454 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08189458 @ =0x0000046E
	adds r7, r5, r0
	b _081894DE
	.align 2, 0
_0818944C: .4byte 0x00000504
_08189450: .4byte 0x0000025D
_08189454: .4byte 0x000004B7
_08189458: .4byte 0x0000046E
_0818945C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081894CC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081894D0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08189496
	ldrb r0, [r7]
	cmp r0, #0
	bne _08189496
	cmp r4, #1
	bne _08189488
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081894E2
_08189488:
	cmp r4, #0
	bne _08189496
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081894E2
_08189496:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081894A8
	movs r3, #6
_081894A8:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081894D4
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081894DC
	.align 2, 0
_081894CC: .4byte 0x000004B7
_081894D0: .4byte 0x0000046E
_081894D4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081894DC:
	str r0, [r6, #8]
_081894DE:
	movs r0, #0
	strb r0, [r7]
_081894E2:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
_081894F0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081894fc
FUN_081894fc: @ 0x081894FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08189558 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08189514
	movs r0, #0
	strb r0, [r1]
_08189514:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0818e6cc
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0818955C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08189568
	ldr r1, _08189560 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08189564 @ =0x0000046E
	adds r7, r5, r0
	b _081895EA
	.align 2, 0
_08189558: .4byte 0x0000046D
_0818955C: .4byte 0x0000025D
_08189560: .4byte 0x000004B7
_08189564: .4byte 0x0000046E
_08189568:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081895D8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081895DC @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081895A2
	ldrb r0, [r7]
	cmp r0, #0
	bne _081895A2
	cmp r4, #1
	bne _08189594
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081895EE
_08189594:
	cmp r4, #0
	bne _081895A2
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081895EE
_081895A2:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081895B4
	movs r3, #6
_081895B4:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081895E0
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081895E8
	.align 2, 0
_081895D8: .4byte 0x000004B7
_081895DC: .4byte 0x0000046E
_081895E0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081895E8:
	str r0, [r6, #8]
_081895EA:
	movs r0, #0
	strb r0, [r7]
_081895EE:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f3ac
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08189608
FUN_08189608: @ 0x08189608
	bx lr
	.align 2, 0

	thumb_func_start FUN_0818960c
FUN_0818960c: @ 0x0818960C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08189610
FUN_08189610: @ 0x08189610
	bx lr
	.align 2, 0

	thumb_func_start FUN_08189614
FUN_08189614: @ 0x08189614
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0818963C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08189640
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08189642
	.align 2, 0
_0818963C: .4byte 0x0000046D
_08189640:
	movs r0, #0
_08189642:
	cmp r0, #0
	beq _0818973E
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r5, #5]
	add r1, sp, #8
	add r2, sp, #0xc
	bl FUN_0818e6cc
	movs r7, #0x9f
	lsls r7, r7, #3
	adds r0, r5, r7
	ldrb r2, [r0]
	ldr r3, [sp, #8]
	ldr r4, [sp, #0xc]
	ldr r1, _08189698 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081896A0
	subs r7, #0x41
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _0818969C @ =0x0000046E
	adds r7, r5, r0
	b _08189722
	.align 2, 0
_08189698: .4byte 0x0000025D
_0818969C: .4byte 0x0000046E
_081896A0:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08189710 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08189714 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081896DA
	ldrb r0, [r7]
	cmp r0, #0
	bne _081896DA
	cmp r4, #1
	bne _081896CC
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08189726
_081896CC:
	cmp r4, #0
	bne _081896DA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08189726
_081896DA:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081896EC
	movs r3, #6
_081896EC:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08189718
	ldr r0, [r6, #8]
	mov r2, sb
	orrs r0, r2
	b _08189720
	.align 2, 0
_08189710: .4byte 0x000004B7
_08189714: .4byte 0x0000046E
_08189718:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08189720:
	str r0, [r6, #8]
_08189722:
	movs r0, #0
	strb r0, [r7]
_08189726:
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	mov r0, r8
	movs r1, #0xf
	bl FUN_0818f5f4
	movs r0, #2
	ldr r2, _08189798 @ =0x00000F2C
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0818973E:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r4, #0
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r2, _0818979C @ =0x05000002
	bl CpuSet
	ldr r0, _081897A0 @ =0x00000F46
	add r0, r8
	ldrb r0, [r0]
	movs r2, #0xc8
	cmp r0, #3
	bls _0818975E
	adds r2, #0x64
_0818975E:
	movs r7, #0xdf
	lsls r7, r7, #1
	adds r1, r5, r7
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r2
	blt _081897B0
	ldr r3, _081897A4 @ =FUN_08189958
	movs r2, #0x26
	ldr r7, _081897A8 @ =0x0000046D
	adds r1, r5, r7
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081897AC @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _08189944
	.align 2, 0
_08189798: .4byte 0x00000F2C
_0818979C: .4byte 0x05000002
_081897A0: .4byte 0x00000F46
_081897A4: .4byte FUN_08189958
_081897A8: .4byte 0x0000046D
_081897AC: .4byte 0x0000046B
_081897B0:
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _081897C4
	movs r4, #1
	ldrh r0, [r1]
	adds r0, #0xa
	b _081897CA
_081897C4:
	movs r4, #2
	ldrh r0, [r1]
	adds r0, #0x28
_081897CA:
	strh r0, [r1]
	ldrb r0, [r5, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081897F0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _081897F4
	asrs r1, r0, #0xc
	b _081897FA
	.align 2, 0
_081897F0: .4byte 0x085B0A08
_081897F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081897FA:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08189812
	asrs r2, r0, #0xc
	b _08189818
_08189812:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08189818:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	mov r0, r8
	movs r1, #4
	bl FUN_0818f17c
	movs r6, #0
	mov ip, r6
	ldr r0, _0818985C @ =0x00000F36
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp ip, r0
	blt _08189838
	b _08189944
_08189838:
	ldr r3, _08189860 @ =0x085B0A08
	movs r4, #0
	ldr r2, _08189864 @ =0x00000674
	add r2, r8
	movs r7, #0x92
	lsls r7, r7, #1
	mov sb, r7
_08189846:
	mov r1, r8
	adds r0, r4, r1
	movs r1, #2
	ldr r7, _08189868 @ =0x0000077A
	adds r0, r0, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818986C
	movs r0, #1
	b _0818986E
	.align 2, 0
_0818985C: .4byte 0x00000F36
_08189860: .4byte 0x085B0A08
_08189864: .4byte 0x00000674
_08189868: .4byte 0x0000077A
_0818986C:
	movs r0, #0
_0818986E:
	cmp r0, #0
	beq _0818992E
	mov r1, r8
	adds r0, r4, r1
	movs r1, #5
	ldr r7, _08189888 @ =0x0000077A
	adds r0, r0, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818988C
	movs r0, #1
	b _0818988E
	.align 2, 0
_08189888: .4byte 0x0000077A
_0818988C:
	movs r0, #0
_0818988E:
	cmp r0, #0
	bne _0818992E
	cmp r6, #0
	beq _081898A2
	cmp r6, #1
	beq _081898DE
	ldrh r0, [r5, #8]
	strh r0, [r2]
	ldrh r0, [r5, #0xc]
	b _0818992A
_081898A2:
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	blt _081898BE
	asrs r1, r0, #0xc
	b _081898C4
_081898BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081898C4:
	ldrh r0, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	bge _0818991C
	b _08189920
_081898DE:
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081898FC
	asrs r1, r0, #0xc
	b _08189902
_081898FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189902:
	ldrh r0, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08189920
_0818991C:
	asrs r1, r0, #0xc
	b _08189926
_08189920:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189926:
	ldrh r0, [r5, #0xc]
	subs r0, r0, r1
_0818992A:
	strh r0, [r2, #4]
	adds r6, #1
_0818992E:
	add r4, sb
	add r2, sb
	movs r0, #1
	add ip, r0
	ldr r0, _08189954 @ =0x00000F36
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	bge _08189944
	b _08189846
_08189944:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08189954: .4byte 0x00000F36

	thumb_func_start FUN_08189958
FUN_08189958: @ 0x08189958
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08189980 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08189984
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08189986
	.align 2, 0
_08189980: .4byte 0x0000046D
_08189984:
	movs r0, #0
_08189986:
	cmp r0, #0
	beq _081899BE
	ldr r0, _081899F0 @ =0x00000E3C
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081899F4 @ =0x00000E3D
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081899F8 @ =0x00000D78
	adds r1, r6, r2
	movs r0, #0x40
	strh r0, [r1]
	movs r1, #0xd4
	lsls r1, r1, #1
	ldr r2, _081899FC @ =0x000001A3
	adds r0, r5, #0
	movs r3, #0x40
	bl FUN_08192fe4
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, _08189A00 @ =0x00000F2C
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081899BE:
	mov r2, r8
	cmp r2, #0x13
	bgt _08189A6C
	ldrb r0, [r5, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081899F0 @ =0x00000E3C
	adds r0, r6, r2
	mov r4, sp
	ldrb r7, [r0]
	ldr r2, _08189A04 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08189A08
	asrs r1, r0, #0xc
	b _08189A0E
	.align 2, 0
_081899F0: .4byte 0x00000E3C
_081899F4: .4byte 0x00000E3D
_081899F8: .4byte 0x00000D78
_081899FC: .4byte 0x000001A3
_08189A00: .4byte 0x00000F2C
_08189A04: .4byte 0x085B0A08
_08189A08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189A0E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _08189A26
	asrs r0, r0, #0xc
	b _08189A2C
_08189A26:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08189A2C:
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	strh r0, [r5, #8]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r2, [r5, #0xc]
	adds r0, r0, r2
	strh r0, [r5, #0xc]
	mov r0, r8
	movs r1, #5
	bl Mod
	cmp r0, #0
	beq _08189A50
	b _08189B56
_08189A50:
	ldr r1, _08189A68 @ =0x00000E3C
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #2
	strb r1, [r0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #0xa
	strh r0, [r1]
	b _08189B56
	.align 2, 0
_08189A68: .4byte 0x00000E3C
_08189A6C:
	mov r0, r8
	cmp r0, #0x29
	bgt _08189A82
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08189B56
_08189A82:
	mov r2, r8
	cmp r2, #0x3f
	bgt _08189B56
	ldrb r3, [r5, #5]
	ldr r1, _08189AB0 @ =0x00000E3C
	adds r0, r6, r1
	mov r4, sp
	ldrb r7, [r0]
	ldr r2, _08189AB4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08189AB8
	asrs r1, r0, #0xc
	b _08189ABE
	.align 2, 0
_08189AB0: .4byte 0x00000E3C
_08189AB4: .4byte 0x085B0A08
_08189AB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189ABE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08189AD6
	asrs r0, r0, #0xc
	b _08189ADC
_08189AD6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08189ADC:
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	strh r0, [r5, #8]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r1, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	ldr r1, _08189B10 @ =0x00000E3D
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08189B14
	asrs r2, r0, #0xc
	b _08189B1A
	.align 2, 0
_08189B10: .4byte 0x00000E3D
_08189B14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08189B1A:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r2, _08189B9C @ =0x00000E3D
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #0xa
	strb r0, [r1]
	mov r0, r8
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _08189B46
	ldr r0, _08189BA0 @ =0x00000E3C
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08189B46:
	mov r1, r8
	cmp r1, #0x34
	bne _08189B56
	movs r2, #0xaa
	lsls r2, r2, #2
	adds r0, r5, r2
	bl FUN_08013984
_08189B56:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_0818f17c
	ldr r1, _08189BA4 @ =0x00000D78
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _08189B90
	ldr r3, _08189BA8 @ =FUN_08189bb4
	movs r2, #0x29
	ldr r0, _08189BAC @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08189BB0 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_08189B90:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08189B9C: .4byte 0x00000E3D
_08189BA0: .4byte 0x00000E3C
_08189BA4: .4byte 0x00000D78
_08189BA8: .4byte FUN_08189bb4
_08189BAC: .4byte 0x0000046D
_08189BB0: .4byte 0x0000046B

	thumb_func_start FUN_08189bb4
FUN_08189bb4: @ 0x08189BB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r7, r0, #0
	str r1, [sp, #0x44]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _08189BE0 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08189BE4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08189BE6
	.align 2, 0
_08189BE0: .4byte 0x0000046D
_08189BE4:
	movs r0, #0
_08189BE6:
	ldr r1, _08189C34 @ =0x00000F2C
	add r1, sb
	mov sl, r1
	cmp r0, #0
	bne _08189BF2
	b _08189D50
_08189BF2:
	ldrb r0, [r7, #5]
	add r2, sp, #0x18
	add r1, sp, #0x14
	bl FUN_0818e6cc
	movs r2, #0xa1
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrb r2, [r0]
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	ldr r1, _08189C38 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08189C44
	ldr r1, _08189C3C @ =0x000004B7
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _08189C40 @ =0x0000046E
	adds r6, r7, r2
	b _08189CC6
	.align 2, 0
_08189C34: .4byte 0x00000F2C
_08189C38: .4byte 0x0000025D
_08189C3C: .4byte 0x000004B7
_08189C40: .4byte 0x0000046E
_08189C44:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _08189CB4 @ =0x000004B7
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08189CB8 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _08189C7E
	ldrb r0, [r6]
	cmp r0, #0
	bne _08189C7E
	cmp r4, #1
	bne _08189C70
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08189CCA
_08189C70:
	cmp r4, #0
	bne _08189C7E
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08189CCA
_08189C7E:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08189C90
	movs r3, #6
_08189C90:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08189CBC
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _08189CC4
	.align 2, 0
_08189CB4: .4byte 0x000004B7
_08189CB8: .4byte 0x0000046E
_08189CBC:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08189CC4:
	str r0, [r5, #8]
_08189CC6:
	movs r0, #0
	strb r0, [r6]
_08189CCA:
	ldr r1, _08189CF8 @ =0x000001A3
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r0, r7, #0
	movs r3, #0x80
	bl FUN_08192fe4
	ldr r2, _08189CFC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08189D00 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08189D04 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08189D0C
	ldr r1, _08189D08 @ =0x00000E3F
	add r1, sb
	movs r0, #1
	b _08189D12
	.align 2, 0
_08189CF8: .4byte 0x000001A3
_08189CFC: .4byte 0x030046B8
_08189D00: .4byte 0x000003FF
_08189D04: .4byte 0x0203B400
_08189D08: .4byte 0x00000E3F
_08189D0C:
	ldr r1, _08189D64 @ =0x00000E3F
	add r1, sb
	movs r0, #0
_08189D12:
	strb r0, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _08189D68 @ =0x00000546
	adds r0, r7, r2
	ldr r2, _08189D6C @ =0x00000F2C
	add r2, sb
	mov sl, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08189D4A
	ldrb r0, [r7, #5]
	adds r0, #0x30
	ldr r1, _08189D70 @ =0x00000E3D
	add r1, sb
	strb r0, [r1]
	ldr r1, _08189D74 @ =0x00000E3C
	add r1, sb
	movs r0, #0xa
	strb r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08189D4A:
	ldr r0, _08189D78 @ =0x000003DE
	bl PlaySound_082406e0
_08189D50:
	movs r1, #0x80
	lsls r1, r1, #7
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08189D7C
	movs r0, #1
	b _08189D7E
	.align 2, 0
_08189D64: .4byte 0x00000E3F
_08189D68: .4byte 0x00000546
_08189D6C: .4byte 0x00000F2C
_08189D70: .4byte 0x00000E3D
_08189D74: .4byte 0x00000E3C
_08189D78: .4byte 0x000003DE
_08189D7C:
	movs r0, #0
_08189D7E:
	cmp r0, #0
	bne _08189D84
	b _08189F5A
_08189D84:
	ldr r0, _08189D98 @ =0x00000E3D
	add r0, sb
	ldrb r1, [r0]
	ldrb r0, [r7, #5]
	subs r4, r1, r0
	cmp r4, #0x80
	ble _08189DA0
	ldr r0, _08189D9C @ =0xFFFFFF00
	adds r4, r4, r0
	b _08189DAE
	.align 2, 0
_08189D98: .4byte 0x00000E3D
_08189D9C: .4byte 0xFFFFFF00
_08189DA0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _08189DAE
	movs r1, #0x80
	lsls r1, r1, #1
	adds r4, r4, r1
_08189DAE:
	ldr r0, [sp, #0x44]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _08189E1C
	adds r0, r4, #0
	cmp r4, #0
	bge _08189DC2
	rsbs r0, r4, #0
_08189DC2:
	cmp r0, #7
	bgt _08189DEC
	ldr r1, _08189DE4 @ =0x00000E3D
	add r1, sb
	ldrb r0, [r1]
	strb r0, [r7, #5]
	ldr r2, [sp, #0x44]
	cmp r2, #0x30
	bgt _08189DFC
	subs r0, #0x66
	strb r0, [r1]
	ldr r1, _08189DE8 @ =0x00000E3C
	add r1, sb
	movs r0, #0xa
	strb r0, [r1]
	b _08189DFC
	.align 2, 0
_08189DE4: .4byte 0x00000E3D
_08189DE8: .4byte 0x00000E3C
_08189DEC:
	cmp r4, #0
	bge _08189DF6
	ldrb r0, [r7, #5]
	subs r0, #2
	b _08189DFA
_08189DF6:
	ldrb r0, [r7, #5]
	adds r0, #2
_08189DFA:
	strb r0, [r7, #5]
_08189DFC:
	ldr r0, _08189E0C @ =0x00000E3C
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	blt _08189E10
	asrs r1, r0, #1
	b _08189E16
	.align 2, 0
_08189E0C: .4byte 0x00000E3C
_08189E10:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08189E16:
	ldr r0, _08189E44 @ =0x00000E3C
	add r0, sb
	strb r1, [r0]
_08189E1C:
	ldr r0, _08189E44 @ =0x00000E3C
	add r0, sb
	add r3, sp, #0x1c
	ldrb r4, [r7, #5]
	ldrb r5, [r0]
	ldr r2, _08189E48 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _08189E4C
	asrs r1, r0, #0xc
	b _08189E52
	.align 2, 0
_08189E44: .4byte 0x00000E3C
_08189E48: .4byte 0x085B0A08
_08189E4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189E52:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08189E6A
	asrs r0, r0, #0xc
	b _08189E70
_08189E6A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08189E70:
	strh r0, [r3, #4]
	ldrh r0, [r6]
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	strh r0, [r7, #8]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	ldrh r2, [r7, #0xc]
	adds r0, r0, r2
	strh r0, [r7, #0xc]
	ldrb r0, [r7, #5]
	add r1, sp, #0x24
	add r2, sp, #0x28
	bl FUN_0818e6cc
	movs r1, #0xa1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r2, [r0]
	ldr r3, [sp, #0x24]
	ldr r4, [sp, #0x28]
	ldr r1, _08189EC8 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08189ED4
	ldr r1, _08189ECC @ =0x000004B7
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _08189ED0 @ =0x0000046E
	adds r6, r7, r2
	b _08189F56
	.align 2, 0
_08189EC8: .4byte 0x0000025D
_08189ECC: .4byte 0x000004B7
_08189ED0: .4byte 0x0000046E
_08189ED4:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _08189F44 @ =0x000004B7
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08189F48 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _08189F0E
	ldrb r0, [r6]
	cmp r0, #0
	bne _08189F0E
	cmp r4, #1
	bne _08189F00
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08189F5A
_08189F00:
	cmp r4, #0
	bne _08189F0E
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08189F5A
_08189F0E:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08189F20
	movs r3, #6
_08189F20:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08189F4C
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _08189F54
	.align 2, 0
_08189F44: .4byte 0x000004B7
_08189F48: .4byte 0x0000046E
_08189F4C:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08189F54:
	str r0, [r5, #8]
_08189F56:
	movs r0, #0
	strb r0, [r6]
_08189F5A:
	ldrb r0, [r7, #5]
	add r1, sp, #0x2c
	add r2, sp, #0x30
	bl FUN_0818e6cc
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x34]
	str r1, [sp, #0x38]
	ldr r0, [sp, #0x2c]
	cmp r0, #4
	bls _08189F74
	b _0818A0A4
_08189F74:
	lsls r0, r0, #2
	ldr r1, _08189F80 @ =_08189F84
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08189F80: .4byte _08189F84
_08189F84: @ jump table
	.4byte _08189F98 @ case 0
	.4byte _08189FB8 @ case 1
	.4byte _08189FF8 @ case 2
	.4byte _0818A03C @ case 3
	.4byte _0818A080 @ case 4
_08189F98:
	add r2, sp, #0x34
	ldrh r1, [r2]
	subs r1, #0x52
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08189FB4 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	subs r0, #0x60
	b _0818A098
	.align 2, 0
_08189FB4: .4byte 0xFFFF0000
_08189FB8:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _08189FD8
	add r0, sp, #0x34
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08189FD4 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x34]
	b _0818A0A4
	.align 2, 0
_08189FD4: .4byte 0xFFFF0000
_08189FD8:
	add r2, sp, #0x34
	ldrh r1, [r2]
	adds r1, #0x20
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08189FF4 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	subs r0, #0x84
	b _0818A098
	.align 2, 0
_08189FF4: .4byte 0xFFFF0000
_08189FF8:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0818A01C
	add r2, sp, #0x34
	ldrh r1, [r2]
	subs r1, #0x64
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0818A018 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	adds r0, #0x52
	b _0818A098
	.align 2, 0
_0818A018: .4byte 0xFFFF0000
_0818A01C:
	add r2, sp, #0x34
	ldrh r1, [r2]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0818A038 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	subs r0, #0x40
	b _0818A098
	.align 2, 0
_0818A038: .4byte 0xFFFF0000
_0818A03C:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0818A05C
	add r3, sp, #0x34
	ldrh r1, [r3, #4]
	adds r1, #0x60
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0818A058 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	b _0818A0A4
	.align 2, 0
_0818A058: .4byte 0xFFFF0000
_0818A05C:
	add r2, sp, #0x34
	ldrh r1, [r2]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0818A07C @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r1, [r2, #4]
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	b _0818A0A4
	.align 2, 0
_0818A07C: .4byte 0xFFFF0000
_0818A080:
	add r2, sp, #0x34
	ldrh r1, [r2]
	adds r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0818A110 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x34]
	ldrh r0, [r2, #4]
	adds r0, #0x40
_0818A098:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
_0818A0A4:
	ldr r0, _0818A114 @ =0x00000E3F
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818A0B0
	b _0818A260
_0818A0B0:
	ldr r1, _0818A118 @ =0x00000484
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #8
	bl Mod
	cmp r0, #0
	beq _0818A0C2
	b _0818A416
_0818A0C2:
	ldr r5, _0818A11C @ =0x0203B400
	ldr r4, _0818A120 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _0818A124 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	ldrb r6, [r7, #5]
	movs r1, #0x3f
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r3, sp, #0x3c
	adds r6, r6, r2
	subs r6, #0x10
	adds r4, r1, #0
	adds r4, #8
	ldr r2, _0818A128 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A12C
	asrs r1, r0, #0xc
	b _0818A132
	.align 2, 0
_0818A110: .4byte 0xFFFF0000
_0818A114: .4byte 0x00000E3F
_0818A118: .4byte 0x00000484
_0818A11C: .4byte 0x0203B400
_0818A120: .4byte 0x030046B8
_0818A124: .4byte 0x000003FF
_0818A128: .4byte 0x085B0A08
_0818A12C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A132:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0818A150 @ =0x085B0A08
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A154
	asrs r0, r0, #0xc
	b _0818A15A
	.align 2, 0
_0818A150: .4byte 0x085B0A08
_0818A154:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818A15A:
	strh r0, [r3, #4]
	add r2, sp, #0x34
	mov r8, r2
	movs r3, #0xc8
	lsls r3, r3, #1
	movs r0, #0xc
	str r0, [sp]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #8]
	adds r1, #0x1c
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	adds r2, #8
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	mov r0, r8
	add r1, sp, #0x3c
	movs r2, #4
	bl FUN_080df148
	ldr r5, _0818A1E8 @ =0x0203B400
	ldr r4, _0818A1EC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _0818A1F0 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	ldrb r6, [r7, #5]
	movs r1, #0x3f
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r4, sp, #0x3c
	adds r6, r6, r2
	subs r6, #0x10
	adds r3, r1, #0
	adds r3, #8
	ldr r2, _0818A1F4 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov r2, r8
	cmp r0, #0
	blt _0818A1F8
	asrs r1, r0, #0xc
	b _0818A1FE
	.align 2, 0
_0818A1E8: .4byte 0x0203B400
_0818A1EC: .4byte 0x030046B8
_0818A1F0: .4byte 0x000003FF
_0818A1F4: .4byte 0x085B0A08
_0818A1F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A1FE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _0818A21C @ =0x085B0A08
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0818A220
	asrs r0, r0, #0xc
	b _0818A226
	.align 2, 0
_0818A21C: .4byte 0x085B0A08
_0818A220:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818A226:
	strh r0, [r4, #4]
	movs r3, #0xc8
	lsls r3, r3, #1
	movs r0, #0xc
	str r0, [sp]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r1, #8
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #8]
	adds r1, #0x14
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	subs r1, #0xc
	adds r0, r7, r1
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	adds r0, r2, #0
	add r1, sp, #0x3c
	movs r2, #4
	bl FUN_080df148
	movs r0, #0x10
	b _0818A40A
_0818A260:
	ldr r2, _0818A2BC @ =0x00000484
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _0818A33A
	ldr r5, _0818A2C0 @ =0x0203B400
	ldr r4, _0818A2C4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _0818A2C8 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	ldrb r6, [r7, #5]
	movs r1, #0x3f
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r3, sp, #0x3c
	adds r6, r6, r2
	subs r6, #0x20
	adds r4, r1, #4
	ldr r2, _0818A2CC @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A2D0
	asrs r1, r0, #0xc
	b _0818A2D6
	.align 2, 0
_0818A2BC: .4byte 0x00000484
_0818A2C0: .4byte 0x0203B400
_0818A2C4: .4byte 0x030046B8
_0818A2C8: .4byte 0x000003FF
_0818A2CC: .4byte 0x085B0A08
_0818A2D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A2D6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A2F2
	asrs r0, r0, #0xc
	b _0818A2F8
_0818A2F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818A2F8:
	strh r0, [r3, #4]
	add r0, sp, #0x34
	movs r1, #0xc
	str r1, [sp]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r2, #8
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #8]
	adds r2, #0x14
	adds r1, r7, r2
	ldr r1, [r1]
	str r1, [sp, #0xc]
	subs r2, #0xc
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #0x10]
	add r1, sp, #0x3c
	movs r2, #4
	movs r3, #0x3c
	bl FUN_080df148
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0818A33A:
	ldr r2, _0818A398 @ =0x00000484
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x20
	bl Mod
	cmp r0, #0
	bne _0818A416
	ldr r5, _0818A39C @ =0x0203B400
	ldr r4, _0818A3A0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _0818A3A4 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	ldrb r6, [r7, #5]
	movs r1, #0x3f
	ands r2, r1
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r3, sp, #0x3c
	adds r6, r6, r2
	subs r6, #0x20
	adds r4, r1, #0
	adds r4, #8
	ldr r2, _0818A3A8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A3AC
	asrs r1, r0, #0xc
	b _0818A3B2
	.align 2, 0
_0818A398: .4byte 0x00000484
_0818A39C: .4byte 0x0203B400
_0818A3A0: .4byte 0x030046B8
_0818A3A4: .4byte 0x000003FF
_0818A3A8: .4byte 0x085B0A08
_0818A3AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A3B2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A3CE
	asrs r0, r0, #0xc
	b _0818A3D4
_0818A3CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818A3D4:
	strh r0, [r3, #4]
	add r0, sp, #0x34
	movs r3, #0xc8
	lsls r3, r3, #1
	movs r1, #0xc
	str r1, [sp]
	ldr r2, _0818A464 @ =0x0000022A
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r2, #8
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #8]
	adds r2, #0x16
	adds r1, r7, r2
	ldr r1, [r1]
	str r1, [sp, #0xc]
	subs r2, #0xe
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #0x10]
	add r1, sp, #0x3c
	movs r2, #8
	bl FUN_080df148
	movs r0, #0x20
_0818A40A:
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0818A416:
	ldr r0, _0818A468 @ =0x00000D78
	add r0, sb
	ldrh r4, [r0]
	cmp r4, #0
	bne _0818A452
	ldr r3, _0818A46C @ =FUN_0818a47c
	movs r2, #0x2a
	ldr r0, _0818A470 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818A474 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	ldr r0, _0818A478 @ =0xFFFFAFFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818A452:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818A464: .4byte 0x0000022A
_0818A468: .4byte 0x00000D78
_0818A46C: .4byte FUN_0818a47c
_0818A470: .4byte 0x0000046D
_0818A474: .4byte 0x0000046B
_0818A478: .4byte 0xFFFFAFFF

	thumb_func_start FUN_0818a47c
FUN_0818a47c: @ 0x0818A47C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, _0818A4A4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818A4A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818A4AA
	.align 2, 0
_0818A4A4: .4byte 0x0000046D
_0818A4A8:
	movs r0, #0
_0818A4AA:
	cmp r0, #0
	beq _0818A4BC
	ldr r0, _0818A508 @ =0x00000F36
	add r0, r8
	ldrh r0, [r0]
	subs r0, #1
	ldr r1, _0818A50C @ =0x00000ECA
	add r1, r8
	strh r0, [r1]
_0818A4BC:
	ldr r1, _0818A510 @ =0x00000C2A
	add r1, r8
	ldrh r0, [r1]
	subs r0, #0x80
	strh r0, [r1]
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0818e6cc
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0818A514 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818A520
	ldr r1, _0818A518 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _0818A51C @ =0x0000046E
	adds r7, r5, r0
	b _0818A5A2
	.align 2, 0
_0818A508: .4byte 0x00000F36
_0818A50C: .4byte 0x00000ECA
_0818A510: .4byte 0x00000C2A
_0818A514: .4byte 0x0000025D
_0818A518: .4byte 0x000004B7
_0818A51C: .4byte 0x0000046E
_0818A520:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0818A590 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0818A594 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0818A55A
	ldrb r0, [r7]
	cmp r0, #0
	bne _0818A55A
	cmp r4, #1
	bne _0818A54C
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0818A5A6
_0818A54C:
	cmp r4, #0
	bne _0818A55A
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0818A5A6
_0818A55A:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0818A56C
	movs r3, #6
_0818A56C:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0818A598
	ldr r0, [r6, #8]
	mov r1, sb
	orrs r0, r1
	b _0818A5A0
	.align 2, 0
_0818A590: .4byte 0x000004B7
_0818A594: .4byte 0x0000046E
_0818A598:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0818A5A0:
	str r0, [r6, #8]
_0818A5A2:
	movs r0, #0
	strb r0, [r7]
_0818A5A6:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _0818A5E4
	ldr r2, _0818A5F4 @ =0x00000F2C
	add r2, r8
	ldr r0, _0818A5F8 @ =0xFFFFDFFF
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r0, _0818A5FC @ =0x00000ECA
	add r0, r8
	strh r1, [r0]
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_080139a0
	ldr r1, _0818A600 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
_0818A5E4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818A5F4: .4byte 0x00000F2C
_0818A5F8: .4byte 0xFFFFDFFF
_0818A5FC: .4byte 0x00000ECA
_0818A600: .4byte 0x0000046B

	thumb_func_start FUN_0818a604
FUN_0818a604: @ 0x0818A604
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r3, [r0]
	ldr r1, _0818A66C @ =0x0000046D
	add r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818A628
	movs r0, #0
	strb r0, [r1]
_0818A628:
	movs r6, #0
	ldr r1, _0818A670 @ =0x00000F36
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	add r4, sp, #8
	mov sl, r4
	ldr r1, _0818A674 @ =0x0000025D
	add r1, r8
	str r1, [sp, #0xc]
	ldr r2, _0818A678 @ =0x000004B7
	add r2, r8
	mov sb, r2
	ldr r4, _0818A67C @ =0x0000046E
	add r4, r8
	str r4, [sp, #0x10]
	cmp r6, r0
	bge _0818A702
_0818A64C:
	lsls r2, r6, #3
	adds r0, r2, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #2
	ldr r4, _0818A680 @ =0x0000077A
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _0818A684
	movs r0, #1
	b _0818A686
	.align 2, 0
_0818A66C: .4byte 0x0000046D
_0818A670: .4byte 0x00000F36
_0818A674: .4byte 0x0000025D
_0818A678: .4byte 0x000004B7
_0818A67C: .4byte 0x0000046E
_0818A680: .4byte 0x0000077A
_0818A684:
	movs r0, #0
_0818A686:
	adds r5, r6, #1
	cmp r0, #0
	beq _0818A6F4
	adds r0, r4, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #5
	ldr r2, _0818A6A8 @ =0x0000077A
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818A6AC
	movs r0, #1
	b _0818A6AE
	.align 2, 0
_0818A6A8: .4byte 0x0000077A
_0818A6AC:
	movs r0, #0
_0818A6AE:
	adds r7, r0, #0
	adds r5, r6, #1
	cmp r7, #0
	bne _0818A6F4
	mov r1, r8
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	adds r1, r5, #0
	str r3, [sp, #0x14]
	bl Div
	adds r4, r4, r6
	lsls r4, r4, #3
	adds r4, r4, r6
	lsls r4, r4, #2
	ldr r3, [sp, #0x14]
	adds r4, r3, r4
	ldr r2, _0818A740 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _0818A744 @ =0x0000076E
	adds r0, r4, r1
	strh r7, [r0]
	mov r2, r8
	movs r1, #0x14
	ldrsh r0, [r2, r1]
	adds r1, r5, #0
	str r3, [sp, #0x14]
	bl Div
	movs r2, #0xee
	lsls r2, r2, #3
	adds r4, r4, r2
	strh r0, [r4]
	ldr r3, [sp, #0x14]
_0818A6F4:
	adds r6, r5, #0
	ldr r4, _0818A748 @ =0x00000F36
	adds r0, r3, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0818A64C
_0818A702:
	mov r2, r8
	ldrb r0, [r2, #5]
	add r1, sp, #4
	mov r2, sl
	bl FUN_0818e6cc
	movs r0, #0x9f
	lsls r0, r0, #3
	add r0, r8
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0818A74C
	mov r0, sb
	strb r2, [r0]
	mov r0, r8
	ldr r1, [r0, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	b _0818A7C0
	.align 2, 0
_0818A740: .4byte 0x0000076C
_0818A744: .4byte 0x0000076E
_0818A748: .4byte 0x00000F36
_0818A74C:
	mov r1, r8
	ldr r0, [r1, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, r2
	bne _0818A782
	ldr r1, [sp, #0x10]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0818A782
	cmp r4, #1
	bne _0818A774
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0818A7C6
_0818A774:
	cmp r4, #0
	bne _0818A782
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0818A7C6
_0818A782:
	mov r0, sb
	strb r2, [r0]
	movs r6, #4
	adds r0, r4, #0
	ands r0, r6
	movs r3, #4
	cmp r0, #0
	beq _0818A794
	movs r3, #6
_0818A794:
	mov r0, r8
	ldr r1, [r0, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0818A7B6
	ldr r0, [r5, #8]
	orrs r0, r6
	b _0818A7BE
_0818A7B6:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0818A7BE:
	str r0, [r5, #8]
_0818A7C0:
	movs r0, #0
	ldr r1, [sp, #0x10]
	strb r0, [r1]
_0818A7C6:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0818a7e4
FUN_0818a7e4: @ 0x0818A7E4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0818A7FC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818A800
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818A802
	.align 2, 0
_0818A7FC: .4byte 0x0000046D
_0818A800:
	movs r0, #0
_0818A802:
	cmp r0, #0
	beq _0818A816
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0818A816:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r5, #0
	str r5, [sp]
	mov r0, sp
	ldr r2, _0818A860 @ =0x05000002
	bl CpuSet
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xff
	ble _0818A870
	ldr r3, _0818A864 @ =FUN_0818a904
	movs r2, #0x22
	ldr r0, _0818A868 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818A86C @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	b _0818A8FC
	.align 2, 0
_0818A860: .4byte 0x05000002
_0818A864: .4byte FUN_0818a904
_0818A868: .4byte 0x0000046D
_0818A86C: .4byte 0x0000046B
_0818A870:
	ldr r3, _0818A884 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0x1d
	bgt _0818A888
	movs r5, #1
	adds r0, r2, #0
	adds r0, #0xa
	b _0818A88E
	.align 2, 0
_0818A884: .4byte 0x00000484
_0818A888:
	movs r5, #2
	adds r0, r2, #0
	adds r0, #0x28
_0818A88E:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _0818A8B4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0818A8B8
	asrs r1, r0, #0xc
	b _0818A8BE
	.align 2, 0
_0818A8B4: .4byte 0x085B0A08
_0818A8B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A8BE:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _0818A8D6
	asrs r2, r0, #0xc
	b _0818A8DC
_0818A8D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818A8DC:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xc
	bl FUN_0818fdd8
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x18
	movs r3, #0
	bl FUN_0818faf0
_0818A8FC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0818a904
FUN_0818a904: @ 0x0818A904
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	str r1, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0818A930 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818A934
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818A936
	.align 2, 0
_0818A930: .4byte 0x0000046D
_0818A934:
	movs r0, #0
_0818A936:
	cmp r0, #0
	beq _0818A942
	ldr r1, _0818A958 @ =0x00000ECD
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_0818A942:
	ldr r0, _0818A958 @ =0x00000ECD
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0818A95C
	ldrb r3, [r6, #5]
	b _0818A966
	.align 2, 0
_0818A958: .4byte 0x00000ECD
_0818A95C:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_0818A966:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _0818A988 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A98C
	asrs r1, r0, #0xc
	b _0818A992
	.align 2, 0
_0818A988: .4byte 0x085B0A08
_0818A98C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A992:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0818A9AA
	asrs r2, r0, #0xc
	b _0818A9B0
_0818A9AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818A9B0:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r1, _0818A9C8 @ =0x00000ECD
	add r1, r8
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r3, #0
	str r3, [sp, #4]
	movs r7, #0
	b _0818AB66
	.align 2, 0
_0818A9C8: .4byte 0x00000ECD
_0818A9CC:
	lsls r2, r7, #3
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	movs r1, #2
	ldr r3, _0818A9EC @ =0x0000077A
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _0818A9F0
	movs r0, #1
	b _0818A9F2
	.align 2, 0
_0818A9EC: .4byte 0x0000077A
_0818A9F0:
	movs r0, #0
_0818A9F2:
	adds r1, r7, #1
	mov sl, r1
	cmp r0, #0
	bne _0818A9FC
	b _0818AB64
_0818A9FC:
	mov r2, sb
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	movs r1, #5
	ldr r3, _0818AA1C @ =0x0000077A
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818AA20
	movs r0, #1
	b _0818AA22
	.align 2, 0
_0818AA1C: .4byte 0x0000077A
_0818AA20:
	movs r0, #0
_0818AA22:
	adds r5, r0, #0
	adds r0, r7, #1
	mov sl, r0
	cmp r5, #0
	beq _0818AA2E
	b _0818AB64
_0818AA2E:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	mov r2, sb
	adds r1, r2, r7
	lsls r1, r1, #3
	adds r1, r1, r7
	lsls r1, r1, #2
	mov r3, r8
	adds r4, r3, r1
	ldr r2, _0818AA80 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _0818AA84 @ =0x0000076E
	adds r0, r4, r3
	strh r5, [r0]
	movs r1, #0x14
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	movs r2, #0xee
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, [sp, #4]
	cmp r3, #0
	beq _0818AA88
	cmp r3, #1
	beq _0818AAE0
	ldrh r1, [r6, #8]
	subs r2, #0xfc
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _0818AB5C
	.align 2, 0
_0818AA80: .4byte 0x0000076C
_0818AA84: .4byte 0x0000076E
_0818AA88:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _0818AAA8 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _0818AAA8 @ =0x085B0A08
	cmp r0, #0
	blt _0818AAAC
	asrs r3, r0, #0xc
	b _0818AAB2
	.align 2, 0
_0818AAA8: .4byte 0x085B0A08
_0818AAAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0818AAB2:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _0818AADC @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	bge _0818AB38
	b _0818AB40
	.align 2, 0
_0818AADC: .4byte 0x00000674
_0818AAE0:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _0818AB04 @ =0x085B0A08
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _0818AB08
	asrs r3, r0, #0xc
	b _0818AB0E
	.align 2, 0
_0818AB04: .4byte 0x085B0A08
_0818AB08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0818AB0E:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _0818AB3C @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0818AB40
_0818AB38:
	asrs r2, r0, #0xc
	b _0818AB46
	.align 2, 0
_0818AB3C: .4byte 0x00000674
_0818AB40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818AB46:
	mov r3, sb
	adds r0, r3, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #0xc]
	subs r1, r1, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r0, r2
_0818AB5C:
	strh r1, [r0]
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_0818AB64:
	mov r7, sl
_0818AB66:
	ldr r0, _0818ABC0 @ =0x00000F36
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _0818AB74
	b _0818A9CC
_0818AB74:
	ldr r3, _0818ABC4 @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	movs r2, #0xc
	bl FUN_0818fdd8
	ldr r2, [sp]
	cmp r2, #0x3c
	ble _0818ABB0
	ldr r4, _0818ABC8 @ =FUN_0818abd4
	movs r3, #0x23
	ldr r0, _0818ABCC @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818ABD0 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
_0818ABB0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818ABC0: .4byte 0x00000F36
_0818ABC4: .4byte 0x0000FFFF
_0818ABC8: .4byte FUN_0818abd4
_0818ABCC: .4byte 0x0000046D
_0818ABD0: .4byte 0x0000046B

	thumb_func_start FUN_0818abd4
FUN_0818abd4: @ 0x0818ABD4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0818ABFC @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818AC00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818AC02
	.align 2, 0
_0818ABFC: .4byte 0x0000046D
_0818AC00:
	movs r0, #0
_0818AC02:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	beq _0818AC54
	adds r0, r6, #0
	bl FUN_081957c4
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, #4
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	strb r0, [r6, #5]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0818AC98 @ =0xFFEFFFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0818AC9C @ =0x00000F2C
	adds r2, r4, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818AC54:
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0818e6cc
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0818ACA0 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818ACAC
	ldr r1, _0818ACA4 @ =0x000004B7
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _0818ACA8 @ =0x0000046E
	adds r7, r6, r2
	b _0818AD2E
	.align 2, 0
_0818AC98: .4byte 0xFFEFFFFF
_0818AC9C: .4byte 0x00000F2C
_0818ACA0: .4byte 0x0000025D
_0818ACA4: .4byte 0x000004B7
_0818ACA8: .4byte 0x0000046E
_0818ACAC:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _0818AD1C @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0818AD20 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _0818ACE6
	ldrb r0, [r7]
	cmp r0, #0
	bne _0818ACE6
	cmp r4, #1
	bne _0818ACD8
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0818AD32
_0818ACD8:
	cmp r4, #0
	bne _0818ACE6
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0818AD32
_0818ACE6:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0818ACF8
	movs r3, #6
_0818ACF8:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0818AD24
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _0818AD2C
	.align 2, 0
_0818AD1C: .4byte 0x000004B7
_0818AD20: .4byte 0x0000046E
_0818AD24:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0818AD2C:
	str r0, [r5, #8]
_0818AD2E:
	movs r0, #0
	strb r0, [r7]
_0818AD32:
	adds r0, r6, #0
	movs r1, #0x12
	movs r2, #6
	movs r3, #0
	bl FUN_0818faf0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	movs r1, #0x10
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0818ADA4
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _0818AD94 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r4, _0818AD98 @ =FUN_0818adc4
	movs r2, #0x24
	ldr r0, _0818AD9C @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818ADA0 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	b _0818ADB4
	.align 2, 0
_0818AD94: .4byte 0xFFFFFEFF
_0818AD98: .4byte FUN_0818adc4
_0818AD9C: .4byte 0x0000046D
_0818ADA0: .4byte 0x0000046B
_0818ADA4:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0818ADB4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0818adc4
FUN_0818adc4: @ 0x0818ADC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0818AE2C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818ADE2
	movs r0, #0
	strb r0, [r1]
_0818ADE2:
	ldrb r0, [r6, #5]
	add r4, sp, #8
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_0818e6cc
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r7, [sp, #8]
	ldr r1, _0818AE30 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _0818AE3C
	ldr r0, _0818AE34 @ =0x000004B7
	adds r5, r6, r0
	strb r2, [r5]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r7, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	mov r8, r5
	ldr r1, _0818AE38 @ =0x0000046E
	adds r1, r1, r6
	mov sb, r1
	b _0818AEBE
	.align 2, 0
_0818AE2C: .4byte 0x0000046D
_0818AE30: .4byte 0x0000025D
_0818AE34: .4byte 0x000004B7
_0818AE38: .4byte 0x0000046E
_0818AE3C:
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _0818AEAC @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	mov r8, r0
	ldr r0, _0818AEB0 @ =0x0000046E
	adds r0, r0, r6
	mov sb, r0
	cmp r1, r2
	bne _0818AE78
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818AE78
	cmp r7, #1
	bne _0818AE6A
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0818AEC4
_0818AE6A:
	cmp r7, #0
	bne _0818AE78
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0818AEC4
_0818AE78:
	mov r1, r8
	strb r2, [r1]
	movs r5, #4
	adds r0, r7, #0
	ands r0, r5
	movs r3, #4
	cmp r0, #0
	beq _0818AE8A
	movs r3, #6
_0818AE8A:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r7, r0
	cmp r7, #0
	beq _0818AEB4
	ldr r0, [r4, #8]
	orrs r0, r5
	b _0818AEBC
	.align 2, 0
_0818AEAC: .4byte 0x000004B7
_0818AEB0: .4byte 0x0000046E
_0818AEB4:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0818AEBC:
	str r0, [r4, #8]
_0818AEBE:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_0818AEC4:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f3ac
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_0818fdd8
	ldr r0, [sp, #0xc]
	cmp r0, #0x28
	ble _0818AFAC
	ldrb r0, [r6, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_0818e6cc
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _0818AF20
	mov r0, r8
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	b _0818AF90
_0818AF20:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, r2
	bne _0818AF54
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _0818AF54
	cmp r4, #1
	bne _0818AF46
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0818AF96
_0818AF46:
	cmp r4, #0
	bne _0818AF54
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0818AF96
_0818AF54:
	mov r0, r8
	strb r2, [r0]
	movs r7, #4
	adds r0, r4, #0
	ands r0, r7
	movs r3, #4
	cmp r0, #0
	beq _0818AF66
	movs r3, #6
_0818AF66:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0818AF86
	ldr r0, [r5, #8]
	orrs r0, r7
	b _0818AF8E
_0818AF86:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0818AF8E:
	str r0, [r5, #8]
_0818AF90:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_0818AF96:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	ldr r0, _0818AFBC @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_0818AFAC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818AFBC: .4byte 0x0000046B

	thumb_func_start FUN_0818afc0
FUN_0818afc0: @ 0x0818AFC0
	push {lr}
	ldr r2, _0818AFD4 @ =0x0000046D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818AFD0
	movs r0, #0
	strb r0, [r1]
_0818AFD0:
	pop {r0}
	bx r0
	.align 2, 0
_0818AFD4: .4byte 0x0000046D

	thumb_func_start FUN_0818afd8
FUN_0818afd8: @ 0x0818AFD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _0818B000 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818B004
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818B006
	.align 2, 0
_0818B000: .4byte 0x0000046D
_0818B004:
	movs r0, #0
_0818B006:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r6
	mov sb, r3
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r4, r4, r6
	mov sl, r4
	movs r7, #0x83
	lsls r7, r7, #2
	adds r7, r6, r7
	str r7, [sp]
	movs r1, #0x85
	lsls r1, r1, #2
	adds r7, r6, r1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r2, r6, r2
	str r2, [sp, #4]
	movs r3, #0x86
	lsls r3, r3, #2
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #0
	beq _0818B084
	movs r0, #0x20
	subs r1, #0x94
	adds r4, r6, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0xd4
	bl PlaySound_082406e0
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r4, _0818B0B0 @ =0x00000F47
	adds r1, r5, r4
	ldrb r1, [r1]
	bl Div
	adds r4, r0, #0
	ldr r1, _0818B0B4 @ =0x00000F46
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _0818B084
	adds r5, r5, r1
_0818B076:
	adds r0, r6, #0
	bl FUN_08190634
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt _0818B076
_0818B084:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r3, sb
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #9
	mov r4, sl
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [sp]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r0, [r7, r3]
	subs r0, r1, r0
	cmp r0, #0
	blt _0818B0B8
	asrs r0, r0, #2
	b _0818B0BE
	.align 2, 0
_0818B0B0: .4byte 0x00000F47
_0818B0B4: .4byte 0x00000F46
_0818B0B8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0818B0BE:
	adds r2, r0, #0
	ldr r4, [sp, #4]
	movs r0, #0
	ldrsh r1, [r4, r0]
	mov r3, r8
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r0, r1, r0
	cmp r0, #0
	blt _0818B0D6
	asrs r0, r0, #2
	b _0818B0DC
_0818B0D6:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0818B0DC:
	adds r1, r0, #0
	cmp r2, #0xc8
	ble _0818B0E6
	movs r2, #0xc8
	b _0818B0F0
_0818B0E6:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0818B0F0
	adds r2, r0, #0
_0818B0F0:
	cmp r1, #0xc8
	ble _0818B0F8
	movs r1, #0xc8
	b _0818B102
_0818B0F8:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818B102
	adds r1, r0, #0
_0818B102:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r2
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
	ldrh r0, [r7]
	adds r0, r0, r2
	strh r0, [r7]
	mov r7, r8
	ldrh r0, [r7]
	adds r0, r0, r1
	strh r0, [r7]
	cmp r2, #0
	bne _0818B128
	cmp r1, #0
	bne _0818B128
	movs r0, #1
	b _0818B12A
_0818B128:
	movs r0, #0
_0818B12A:
	cmp r0, #0
	beq _0818B1A0
	ldr r1, _0818B1B0 @ =0x0000046B
	adds r0, r6, r1
	movs r5, #0
	movs r3, #1
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r4, _0818B1B4 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r7, _0818B1B8 @ =0x0000046D
	adds r0, r6, r7
	strb r3, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r5, [r0]
	movs r2, #5
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _0818B1BC @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0818B1C0 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _0818B1C4 @ =0x0000046C
	adds r0, r6, r2
	strb r3, [r0]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrb r0, [r0]
	strb r0, [r6, #5]
	adds r7, #0x18
	adds r0, r6, r7
	strh r3, [r0]
_0818B1A0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818B1B0: .4byte 0x0000046B
_0818B1B4: .4byte FUN_080e48d0
_0818B1B8: .4byte 0x0000046D
_0818B1BC: .4byte 0x00000469
_0818B1C0: .4byte 0x00000484
_0818B1C4: .4byte 0x0000046C

	thumb_func_start FUN_0818b1c8
FUN_0818b1c8: @ 0x0818B1C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, _0818B1E4 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818B1E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818B1EA
	.align 2, 0
_0818B1E4: .4byte 0x0000046D
_0818B1E8:
	movs r0, #0
_0818B1EA:
	cmp r0, #0
	beq _0818B252
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080e64b4
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _0818B34C @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _0818B350 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r4, _0818B354 @ =0x00000202
	adds r0, r6, r4
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xd8
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0xd2
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0818B252:
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _0818B27A
	adds r4, r6, #0
	adds r4, #8
	ldrb r2, [r6, #5]
	adds r0, r4, #0
	movs r1, #5
	movs r3, #0
	bl FUN_08192ae0
	ldrb r2, [r6, #5]
	adds r0, r4, #0
	movs r1, #5
	movs r3, #1
	bl FUN_08192ae0
_0818B27A:
	ldr r0, [r6, #0x44]
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818B28E
	b _0818B488
_0818B28E:
	adds r4, r6, #0
	adds r4, #8
	ldrb r2, [r6, #5]
	adds r0, r4, #0
	movs r1, #8
	movs r3, #0
	bl FUN_08192ae0
	ldrb r2, [r6, #5]
	adds r0, r4, #0
	movs r1, #8
	movs r3, #1
	bl FUN_08192ae0
	adds r0, r6, #0
	bl FUN_081906d4
	movs r1, #0x80
	lsls r1, r1, #3
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0818B2C8
	adds r0, r6, #0
	bl FUN_080e6658
_0818B2C8:
	movs r0, #0xcd
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _0818B32A
	movs r1, #8
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r6, r3]
	str r0, [sp, #4]
	movs r4, #0xc
	ldrsh r0, [r6, r4]
	str r0, [sp, #8]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _0818B358 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r7, sp
	str r7, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0818B32A:
	ldr r1, _0818B35C @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	cmp r0, #0x1f
	bgt _0818B364
	ldr r3, _0818B360 @ =0x030046A0
	ldr r2, [r3]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	b _0818B370
	.align 2, 0
_0818B34C: .4byte 0xFFFEBE3F
_0818B350: .4byte 0x0000021E
_0818B354: .4byte 0x00000202
_0818B358: .4byte 0xFFFF0000
_0818B35C: .4byte 0x000001DF
_0818B360: .4byte 0x030046A0
_0818B364:
	ldr r3, _0818B390 @ =0x030046A0
	ldr r2, [r3]
	movs r7, #0xe3
	lsls r7, r7, #2
	adds r2, r2, r7
	subs r0, #0x20
_0818B370:
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r3]
	ldr r1, _0818B394 @ =0x00000948
	adds r2, r0, r1
	ldrh r4, [r2]
	movs r7, #0
	ldrsh r1, [r2, r7]
	ldr r0, _0818B398 @ =0x0000270E
	cmp r1, r0
	bgt _0818B39C
	adds r0, r4, #1
	b _0818B3A0
	.align 2, 0
_0818B390: .4byte 0x030046A0
_0818B394: .4byte 0x00000948
_0818B398: .4byte 0x0000270E
_0818B39C:
	ldr r1, _0818B3BC @ =0x0000270F
	adds r0, r1, #0
_0818B3A0:
	strh r0, [r2]
	ldr r0, [r3]
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r0, _0818B3C0 @ =0x0000270E
	cmp r1, r0
	bgt _0818B3C4
	adds r0, r2, #1
	b _0818B3C8
	.align 2, 0
_0818B3BC: .4byte 0x0000270F
_0818B3C0: .4byte 0x0000270E
_0818B3C4:
	ldr r7, _0818B400 @ =0x0000270F
	adds r0, r7, #0
_0818B3C8:
	strh r0, [r3]
	adds r0, r6, #0
	bl FUN_080e9178
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0807a798
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ldr r3, _0818B404 @ =0x00000189
	adds r1, r6, r3
	ldrb r1, [r1]
	bl FUN_0807a840
	ldr r0, _0818B408 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0818B40C
	movs r0, #1
	b _0818B40E
	.align 2, 0
_0818B400: .4byte 0x0000270F
_0818B404: .4byte 0x00000189
_0818B408: .4byte 0x030047A4
_0818B40C:
	movs r0, #0
_0818B40E:
	cmp r0, #0
	bne _0818B42E
	movs r1, #0x80
	lsls r1, r1, #4
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0818B42E
	ldr r0, _0818B490 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r6]
	bl FUN_080ec5b4
_0818B42E:
	movs r7, #0xc9
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _0818B494 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r1, _0818B498 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r7, _0818B49C @ =0x0000046B
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _0818B4A0 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _0818B4A4 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #1
	adds r0, r6, r7
	strb r1, [r0]
_0818B488:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818B490: .4byte 0x03002B28
_0818B494: .4byte FUN_080e48d0
_0818B498: .4byte 0x0000046D
_0818B49C: .4byte 0x0000046B
_0818B4A0: .4byte 0x00000469
_0818B4A4: .4byte 0x00000484

	thumb_func_start FUN_0818b4a8
FUN_0818b4a8: @ 0x0818B4A8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818B4C8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818B4CC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818B4CE
	.align 2, 0
_0818B4C8: .4byte 0x0000046C
_0818B4CC:
	movs r0, #0
_0818B4CE:
	cmp r0, #0
	beq _0818B55E
	movs r3, #0xf3
	lsls r3, r3, #4
	adds r0, r6, r3
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r7, _0818B52C @ =0x00000F34
	adds r0, r6, r7
	movs r2, #0
	strh r4, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	ldr r7, _0818B530 @ =0x0000046D
	adds r0, r5, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _0818B534 @ =0x00000553
	adds r0, r5, r2
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_0818f918
	movs r2, #0x80
	lsls r2, r2, #8
	ldr r3, _0818B538 @ =0x00000F2C
	adds r1, r6, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0818B53C
	movs r0, #1
	b _0818B53E
	.align 2, 0
_0818B52C: .4byte 0x00000F34
_0818B530: .4byte 0x0000046D
_0818B534: .4byte 0x00000553
_0818B538: .4byte 0x00000F2C
_0818B53C:
	movs r0, #0
_0818B53E:
	cmp r0, #0
	bne _0818B552
	ldr r0, _0818B58C @ =0x000003E5
	bl PlaySound_082406e0
	movs r0, #0x80
	lsls r0, r0, #8
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_0818B552:
	adds r0, r5, #0
	movs r1, #2
	movs r2, #6
	movs r3, #1
	bl FUN_0819328c
_0818B55E:
	movs r7, #0xb1
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _0818B590 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818B598
	ldr r3, _0818B594 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0818B5A8
	.align 2, 0
_0818B58C: .4byte 0x000003E5
_0818B590: .4byte 0x0000A02F
_0818B594: .4byte 0x00000482
_0818B598:
	ldr r1, _0818B5CC @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0818B5A8
	movs r0, #1
	strh r0, [r2]
_0818B5A8:
	ldr r3, _0818B5D0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818B5D4
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0818B5EC
	.align 2, 0
_0818B5CC: .4byte 0x00000482
_0818B5D0: .4byte 0x0000025D
_0818B5D4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0818B5EC:
	ldr r1, _0818B624 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _0818B60E
	rsbs r2, r2, #0
_0818B60E:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0818B628
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0818B61C
	rsbs r2, r2, #0
_0818B61C:
	cmp r2, #0x20
	bgt _0818B628
	movs r0, #1
	b _0818B692
	.align 2, 0
_0818B624: .4byte 0x000004A4
_0818B628:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0818B634
	cmp r1, #0
	beq _0818B690
_0818B634:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _0818B658 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818B65C
	asrs r1, r0, #0xc
	b _0818B662
	.align 2, 0
_0818B658: .4byte 0x085B0A08
_0818B65C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818B662:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _0818B680 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818B684
	asrs r1, r0, #0xc
	b _0818B68A
	.align 2, 0
_0818B680: .4byte 0x085B0A08
_0818B684:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818B68A:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_0818B690:
	movs r0, #0
_0818B692:
	cmp r0, #0
	beq _0818B73C
	adds r0, r5, #0
	bl FUN_0818e6fc
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _0818B6EC @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818B6F4
	ldr r3, _0818B6F0 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0818B702
	.align 2, 0
_0818B6EC: .4byte 0x000004A4
_0818B6F0: .4byte 0xFFFFFF00
_0818B6F4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818B702
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818B702:
	cmp r1, #0
	bge _0818B708
	rsbs r1, r1, #0
_0818B708:
	cmp r1, #0x20
	ble _0818B73C
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818B734 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _0818B738 @ =0x0000046A
	adds r0, r5, r7
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	b _0818B80A
	.align 2, 0
_0818B734: .4byte 0x00000469
_0818B738: .4byte 0x0000046A
_0818B73C:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08190804
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #8
	bl FUN_0818fdd8
	ldr r1, _0818B76C @ =0x085B0A08
	ldr r2, _0818B770 @ =0x00000484
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _0818B774
	asrs r1, r0, #8
	b _0818B77A
	.align 2, 0
_0818B76C: .4byte 0x085B0A08
_0818B770: .4byte 0x00000484
_0818B774:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0818B77A:
	ldr r7, _0818B7E0 @ =0x00000BFE
	adds r0, r6, r7
	movs r4, #0
	strh r1, [r0]
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x1e
	bl FUN_08191774
	movs r3, #0xed
	lsls r3, r3, #4
	adds r2, r6, r3
	ldr r7, _0818B7E4 @ =0x00000D52
	adds r0, r6, r7
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bls _0818B7FC
	movs r1, #0x12
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _0818B7E8 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _0818B7EC @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r0, _0818B7F0 @ =0x00000484
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0818B7F4 @ =0x00000D56
	adds r0, r6, r3
	ldrh r1, [r0]
	ldr r7, _0818B7F8 @ =0x00000D4E
	adds r0, r6, r7
	strb r1, [r0]
	b _0818B80A
	.align 2, 0
_0818B7E0: .4byte 0x00000BFE
_0818B7E4: .4byte 0x00000D52
_0818B7E8: .4byte 0x00000469
_0818B7EC: .4byte 0x0000046A
_0818B7F0: .4byte 0x00000484
_0818B7F4: .4byte 0x00000D56
_0818B7F8: .4byte 0x00000D4E
_0818B7FC:
	adds r0, r1, #1
	strh r0, [r2]
	ldr r0, _0818B814 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818B80A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818B814: .4byte 0x00000484

	thumb_func_start FUN_0818b818
FUN_0818b818: @ 0x0818B818
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _0818B844 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818B848
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818B84A
	.align 2, 0
_0818B844: .4byte 0x0000046C
_0818B848:
	movs r0, #0
_0818B84A:
	ldr r7, _0818B8A0 @ =0x00000F2C
	add r7, sl
	cmp r0, #0
	beq _0818B902
	ldr r3, _0818B8A4 @ =0x00000256
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r0, _0818B8A8 @ =0x00000ED6
	add r0, sl
	strh r1, [r0]
	ldrh r6, [r0]
	ldr r7, _0818B8AC @ =0x00000F7C
	add r7, sl
	ldr r0, _0818B8B0 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818B8B4
	adds r0, #4
	b _0818B8C0
	.align 2, 0
_0818B8A0: .4byte 0x00000F2C
_0818B8A4: .4byte 0x00000256
_0818B8A8: .4byte 0x00000ED6
_0818B8AC: .4byte 0x00000F7C
_0818B8B0: .4byte 0x030046A4
_0818B8B4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818B8C0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	movs r2, #0x80
	lsls r2, r2, #8
	ldr r1, _0818B8E8 @ =0x00000F2C
	add r1, sl
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _0818B8EC
	movs r0, #1
	b _0818B8EE
	.align 2, 0
_0818B8E8: .4byte 0x00000F2C
_0818B8EC:
	movs r0, #0
_0818B8EE:
	cmp r0, #0
	bne _0818B902
	ldr r0, _0818B930 @ =0x000003E5
	bl PlaySound_082406e0
	movs r0, #0x80
	lsls r0, r0, #8
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
_0818B902:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r1, _0818B934 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818B93C
	ldr r0, _0818B938 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0818B94C
	.align 2, 0
_0818B930: .4byte 0x000003E5
_0818B934: .4byte 0x0000A02F
_0818B938: .4byte 0x00000482
_0818B93C:
	ldr r1, _0818B970 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0818B94C
	movs r0, #1
	strh r0, [r2]
_0818B94C:
	ldr r3, _0818B974 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818B978
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0818B990
	.align 2, 0
_0818B970: .4byte 0x00000482
_0818B974: .4byte 0x0000025D
_0818B978:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0818B990:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	adds r3, r0, #0
	cmp r1, #0x80
	ble _0818B9AC
	ldr r2, _0818B9A8 @ =0xFFFFFF00
	adds r1, r1, r2
	b _0818B9BA
	.align 2, 0
_0818B9A8: .4byte 0xFFFFFF00
_0818B9AC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818B9BA
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818B9BA:
	adds r6, r1, #0
	adds r0, r6, #0
	cmp r6, #0
	bge _0818B9C4
	rsbs r0, r6, #0
_0818B9C4:
	cmp r0, #8
	ble _0818BA1C
	ldr r2, _0818B9E8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0818B9EC
	asrs r0, r0, #0xc
	b _0818B9F2
	.align 2, 0
_0818B9E8: .4byte 0x085B0A08
_0818B9EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818B9F2:
	adds r1, r0, #0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _0818BA0A
	asrs r2, r0, #0xc
	b _0818BA10
_0818BA0A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818BA10:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
_0818BA1C:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	adds r2, r5, #0
	adds r2, #0x10
	ldrh r0, [r5, #0x10]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0818BA64
	cmp r1, #0
	blt _0818BA64
	ldr r0, _0818BA6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0818BA64
	ldr r0, _0818BA70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818BA74
_0818BA64:
	movs r2, #0
	mov r8, r2
	b _0818BA84
	.align 2, 0
_0818BA6C: .4byte 0x030046A8
_0818BA70: .4byte 0x030046AC
_0818BA74:
	ldr r0, _0818BB00 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
	mov r8, r0
_0818BA84:
	ldr r0, _0818BB04 @ =0x00000ED6
	add r0, sl
	ldrh r0, [r0]
	cmp r0, r8
	beq _0818BAD2
	mov r4, sp
	ldr r2, _0818BB08 @ =0x00000F7C
	add r2, sl
	ldrh r1, [r2]
	mov r0, sp
	ldrh r0, [r0]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #8
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	strh r1, [r5, #0x10]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #8
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r5, #0x14]
_0818BAD2:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #8
	bl FUN_0818fdd8
	ldr r2, _0818BB0C @ =0x085B0A08
	ldr r3, _0818BB10 @ =0x00000484
	adds r0, r5, r3
	movs r1, #0xff
	ldrb r0, [r0]
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0818BB14
	asrs r1, r0, #8
	b _0818BB1A
	.align 2, 0
_0818BB00: .4byte 0x030046A4
_0818BB04: .4byte 0x00000ED6
_0818BB08: .4byte 0x00000F7C
_0818BB0C: .4byte 0x085B0A08
_0818BB10: .4byte 0x00000484
_0818BB14:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0818BB1A:
	ldr r0, _0818BB30 @ =0x00000ADA
	add r0, sl
	strh r1, [r0]
	movs r1, #0x10
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0818BB34
	movs r0, #1
	b _0818BB36
	.align 2, 0
_0818BB30: .4byte 0x00000ADA
_0818BB34:
	movs r0, #0
_0818BB36:
	cmp r0, #0
	beq _0818BB4E
	adds r0, r5, #0
	bl FUN_08191a9c
	adds r0, r5, #0
	bl FUN_0819267c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818BC10
	b _0818BB58
_0818BB4E:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x14
	bl FUN_08191774
_0818BB58:
	adds r0, r6, #0
	cmp r6, #0
	bge _0818BB60
	rsbs r0, r6, #0
_0818BB60:
	cmp r0, #7
	bgt _0818BBE0
	ldr r0, _0818BB7C @ =0x00000ED6
	add r0, sl
	ldrh r0, [r0]
	cmp r0, r8
	bne _0818BC06
	movs r1, #0x10
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0818BB80
	movs r0, #1
	b _0818BB82
	.align 2, 0
_0818BB7C: .4byte 0x00000ED6
_0818BB80:
	movs r0, #0
_0818BB82:
	adds r2, r0, #0
	cmp r2, #0
	beq _0818BBB0
	movs r2, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _0818BBAC @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	b _0818BBD0
	.align 2, 0
_0818BBAC: .4byte 0x00000484
_0818BBB0:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0818BBD8 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _0818BBDC @ =0x0000046C
	adds r1, r5, r2
_0818BBD0:
	movs r0, #1
	strb r0, [r1]
	b _0818BC06
	.align 2, 0
_0818BBD8: .4byte 0x00000484
_0818BBDC: .4byte 0x0000046C
_0818BBE0:
	cmp r6, #0
	ble _0818BBF8
	ldr r3, _0818BBF4 @ =0x00000482
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #2
	ldrb r1, [r5, #5]
	adds r0, r0, r1
	b _0818BC04
	.align 2, 0
_0818BBF4: .4byte 0x00000482
_0818BBF8:
	ldr r2, _0818BC20 @ =0x00000482
	adds r0, r5, r2
	ldrh r1, [r0]
	lsls r1, r1, #2
	ldrb r0, [r5, #5]
	subs r0, r0, r1
_0818BC04:
	strb r0, [r5, #5]
_0818BC06:
	ldr r3, _0818BC24 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818BC10:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818BC20: .4byte 0x00000482
_0818BC24: .4byte 0x00000484

	thumb_func_start FUN_0818bc28
FUN_0818bc28: @ 0x0818BC28
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0818BC48 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818BC4C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818BC4E
	.align 2, 0
_0818BC48: .4byte 0x0000046C
_0818BC4C:
	movs r0, #0
_0818BC4E:
	cmp r0, #0
	beq _0818BCA2
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r6, _0818BCD4 @ =0x0000046D
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r1, r4, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0818BCD8 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818BCDC @ =0x00000F2C
	adds r2, r5, r0
	ldr r0, _0818BCE0 @ =0xFFFF7FFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818BCA2:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	ldr r2, _0818BCE4 @ =0x05000002
	bl CpuSet
	ldr r3, _0818BCE8 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0xef
	ble _0818BD44
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r4, r6
	ldrb r1, [r0]
	ldrb r0, [r4, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818BCF0
	ldr r0, _0818BCEC @ =0xFFFFFF00
	adds r1, r1, r0
	b _0818BCFE
	.align 2, 0
_0818BCD4: .4byte 0x0000046D
_0818BCD8: .4byte 0x000003E5
_0818BCDC: .4byte 0x00000F2C
_0818BCE0: .4byte 0xFFFF7FFF
_0818BCE4: .4byte 0x05000002
_0818BCE8: .4byte 0x00000484
_0818BCEC: .4byte 0xFFFFFF00
_0818BCF0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818BCFE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0818BCFE:
	movs r0, #0
	cmp r1, #0x1f
	bgt _0818BD06
	movs r0, #1
_0818BD06:
	cmp r0, #0
	beq _0818BD44
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r4, #5]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r3, _0818BD3C @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r2, [r0]
	ldr r2, _0818BD40 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _0818BDE4
	.align 2, 0
_0818BD3C: .4byte 0x00000469
_0818BD40: .4byte 0x00000484
_0818BD44:
	ldr r6, _0818BD5C @ =0x00000484
	adds r0, r4, r6
	ldr r0, [r0]
	cmp r0, #0x77
	bgt _0818BD60
	movs r5, #0x50
	movs r0, #8
	mov ip, r0
	movs r6, #2
	movs r7, #0xc3
	lsls r7, r7, #5
	b _0818BD7A
	.align 2, 0
_0818BD5C: .4byte 0x00000484
_0818BD60:
	cmp r0, #0xc7
	bgt _0818BD6E
	movs r5, #0x28
	movs r1, #8
	mov ip, r1
	movs r6, #4
	b _0818BD76
_0818BD6E:
	movs r5, #0x28
	movs r2, #8
	mov ip, r2
	movs r6, #6
_0818BD76:
	movs r7, #0x9b
	lsls r7, r7, #3
_0818BD7A:
	ldr r3, _0818BD98 @ =0x085B0A08
	ldrb r2, [r4, #5]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0818BD9C
	asrs r0, r0, #0xc
	b _0818BDA2
	.align 2, 0
_0818BD98: .4byte 0x085B0A08
_0818BD9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818BDA2:
	adds r1, r0, #0
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0818BDB6
	asrs r2, r0, #0xc
	b _0818BDBC
_0818BDB6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818BDBC:
	ldrb r0, [r4, #5]
	adds r0, r0, r6
	strb r0, [r4, #5]
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	mov r1, ip
	movs r2, #0xc
	adds r3, r7, #0
	bl FUN_0818fdd8
	ldr r3, _0818BDEC @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818BDE4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818BDEC: .4byte 0x00000484

	thumb_func_start FUN_0818bdf0
FUN_0818bdf0: @ 0x0818BDF0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818BE10 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818BE14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818BE16
	.align 2, 0
_0818BE10: .4byte 0x0000046C
_0818BE14:
	movs r0, #0
_0818BE16:
	cmp r0, #0
	beq _0818BE66
	ldr r4, _0818BEAC @ =FUN_08189614
	movs r3, #0x25
	ldr r0, _0818BEB0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818BEB4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0818BEB8 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818BEBC @ =0x00000F2C
	adds r2, r6, r0
	ldr r0, _0818BEC0 @ =0xFFFF7FFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818BE66:
	ldr r1, _0818BEB4 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0818BECC
	adds r0, r5, #0
	bl FUN_0818e6fc
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _0818BEC4 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0818BEC8 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0818BED6
	.align 2, 0
_0818BEAC: .4byte FUN_08189614
_0818BEB0: .4byte 0x0000046D
_0818BEB4: .4byte 0x0000046B
_0818BEB8: .4byte 0x000003E5
_0818BEBC: .4byte 0x00000F2C
_0818BEC0: .4byte 0xFFFF7FFF
_0818BEC4: .4byte 0x00000484
_0818BEC8: .4byte 0xFFEFFFFF
_0818BECC:
	ldr r2, _0818BEDC @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818BED6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0818BEDC: .4byte 0x00000484

	thumb_func_start FUN_0818bee0
FUN_0818bee0: @ 0x0818BEE0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818BF00 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818BF04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818BF06
	.align 2, 0
_0818BF00: .4byte 0x0000046C
_0818BF04:
	movs r0, #0
_0818BF06:
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r4, r5, r7
	cmp r0, #0
	beq _0818BFD6
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0818BF68 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0818BF6C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	ldr r7, _0818BF70 @ =0x00000553
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	ldr r7, _0818BF74 @ =0x000001DD
	adds r0, r5, r7
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r3, r5, r1
	ldrb r4, [r0]
	ldr r2, _0818BF78 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0818BF7C
	asrs r1, r0, #0xc
	b _0818BF82
	.align 2, 0
_0818BF68: .4byte 0x0000046D
_0818BF6C: .4byte 0x0000046B
_0818BF70: .4byte 0x00000553
_0818BF74: .4byte 0x000001DD
_0818BF78: .4byte 0x085B0A08
_0818BF7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818BF82:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0818BF9C
	asrs r0, r0, #0xc
	b _0818BFA2
_0818BF9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818BFA2:
	strh r0, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r0, #0x20
	strh r0, [r1]
	movs r7, #0xde
	lsls r7, r7, #1
	adds r1, r5, r7
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	movs r0, #0x80
	ldr r1, _0818C058 @ =0x00000F2C
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r4, r3, #0
_0818BFD6:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0818C06C
	adds r0, r5, #0
	bl FUN_0818e6fc
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _0818C05C @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r3, [r0]
	ldr r7, _0818C060 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r3, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #0x14
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _0818C064 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _0818C068 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r3, [r0]
	ldr r0, _0818C058 @ =0x00000F2C
	adds r2, r6, r0
	movs r0, #0x81
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0818C076
	.align 2, 0
_0818C058: .4byte 0x00000F2C
_0818C05C: .4byte 0x0000046D
_0818C060: .4byte 0x0000046B
_0818C064: .4byte 0x0000046A
_0818C068: .4byte 0x00000484
_0818C06C:
	ldr r2, _0818C07C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818C076:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818C07C: .4byte 0x00000484

	thumb_func_start FUN_0818c080
FUN_0818c080: @ 0x0818C080
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818C0A0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C0A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C0A6
	.align 2, 0
_0818C0A0: .4byte 0x0000046C
_0818C0A4:
	movs r0, #0
_0818C0A6:
	cmp r0, #0
	beq _0818C0D8
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r7, _0818C108 @ =0x0000046D
	adds r0, r5, r7
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0818C10C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_0818C0D8:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	ldr r7, _0818C110 @ =0x00000484
	adds r0, r5, r7
	ldr r0, [r0]
	cmp r0, #0x63
	bgt _0818C114
	movs r1, #0x14
	bl Mod
	cmp r0, #0
	bne _0818C12A
	adds r0, r5, #0
	movs r1, #0x28
	movs r2, #0x18
	movs r3, #0
	bl FUN_0818faf0
	b _0818C12A
	.align 2, 0
_0818C108: .4byte 0x0000046D
_0818C10C: .4byte 0x0000046B
_0818C110: .4byte 0x00000484
_0818C114:
	movs r1, #0x28
	bl Mod
	cmp r0, #0
	bne _0818C12A
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0x2c
	movs r3, #1
	bl FUN_0818faf0
_0818C12A:
	ldr r0, _0818C198 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0xc8
	ble _0818C1B0
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _0818C19C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0818C1A0 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	ldr r7, _0818C1A4 @ =0x00000553
	adds r0, r5, r7
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	strh r2, [r0]
	movs r4, #0x11
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r4, [r0]
	ldr r4, _0818C198 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r3, [r0]
	ldr r2, _0818C1A8 @ =0x00000D4F
	adds r0, r6, r2
	strb r1, [r0]
	ldr r4, _0818C1AC @ =0x00000D4E
	adds r1, r6, r4
	movs r0, #3
	strb r0, [r1]
	b _0818C1B4
	.align 2, 0
_0818C198: .4byte 0x00000484
_0818C19C: .4byte 0x0000046D
_0818C1A0: .4byte 0x0000046B
_0818C1A4: .4byte 0x00000553
_0818C1A8: .4byte 0x00000D4F
_0818C1AC: .4byte 0x00000D4E
_0818C1B0:
	adds r0, #1
	str r0, [r1]
_0818C1B4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0818c1bc
FUN_0818c1bc: @ 0x0818C1BC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0818C1D4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C1D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C1DA
	.align 2, 0
_0818C1D4: .4byte 0x0000046C
_0818C1D8:
	movs r0, #0
_0818C1DA:
	cmp r0, #0
	beq _0818C280
	ldr r1, _0818C230 @ =0x000005A4
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _0818C234 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r6, _0818C238 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _0818C23C @ =0x00000553
	adds r0, r5, r1
	strb r2, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r4, [r5, #5]
	ldr r2, _0818C240 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0818C244
	asrs r1, r0, #0xc
	b _0818C24A
	.align 2, 0
_0818C230: .4byte 0x000005A4
_0818C234: .4byte 0x0000046D
_0818C238: .4byte 0x0000046B
_0818C23C: .4byte 0x00000553
_0818C240: .4byte 0x085B0A08
_0818C244:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818C24A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0818C264
	asrs r2, r0, #0xc
	b _0818C26A
_0818C264:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818C26A:
	movs r0, #0
	strh r2, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #2
	strh r0, [r1]
_0818C280:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818C308
	adds r0, r5, #0
	bl FUN_0818e6fc
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0818C2F8 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0818C2FC @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818C300 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _0818C304 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _0818C312
	.align 2, 0
_0818C2F8: .4byte 0x0000046D
_0818C2FC: .4byte 0x0000046B
_0818C300: .4byte 0x0000046A
_0818C304: .4byte 0x00000484
_0818C308:
	ldr r0, _0818C318 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818C312:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0818C318: .4byte 0x00000484

	thumb_func_start FUN_0818c31c
FUN_0818c31c: @ 0x0818C31C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0818C33C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C340
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C342
	.align 2, 0
_0818C33C: .4byte 0x0000046C
_0818C340:
	movs r0, #0
_0818C342:
	cmp r0, #0
	beq _0818C35E
	ldr r3, _0818C3A4 @ =0x00000472
	adds r0, r4, r3
	ldr r2, _0818C3A8 @ =0xFFFFFF00
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	strh r1, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #8
	adds r0, r5, #0
	bl FUN_0819014c
_0818C35E:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xa
	bl FUN_08191774
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0818f17c
	ldr r3, _0818C3AC @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	cmp r0, #0x28
	ble _0818C3B0
	movs r2, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	subs r3, #0x1b
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0818C3AC @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _0818C3B4
	.align 2, 0
_0818C3A4: .4byte 0x00000472
_0818C3A8: .4byte 0xFFFFFF00
_0818C3AC: .4byte 0x00000484
_0818C3B0:
	adds r0, #1
	str r0, [r1]
_0818C3B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0818c3bc
FUN_0818c3bc: @ 0x0818C3BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _0818C3E8 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C3EC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C3EE
	.align 2, 0
_0818C3E8: .4byte 0x0000046C
_0818C3EC:
	movs r0, #0
_0818C3EE:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x34]
	cmp r0, #0
	bne _0818C3FC
	b _0818C6D2
_0818C3FC:
	ldr r1, _0818C468 @ =0xFFEFFFFF
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r5, _0818C46C @ =0x00000474
	adds r2, r7, r5
	movs r1, #0x21
	rsbs r1, r1, #0
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #1
	subs r5, #7
	adds r0, r7, r5
	strb r1, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _0818C470 @ =0x00000553
	adds r0, r7, r3
	strb r1, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0
	str r2, [sp, #0x30]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #6
	movs r3, #0
	bl FUN_0819328c
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r1, _0818C474 @ =0x00000F2C
	add r1, sl
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _0818C478
	movs r0, #1
	b _0818C47A
	.align 2, 0
_0818C468: .4byte 0xFFEFFFFF
_0818C46C: .4byte 0x00000474
_0818C470: .4byte 0x00000553
_0818C474: .4byte 0x00000F2C
_0818C478:
	movs r0, #0
_0818C47A:
	cmp r0, #0
	beq _0818C520
	movs r1, #0x80
	lsls r1, r1, #4
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0818C490
	movs r0, #1
	b _0818C492
_0818C490:
	movs r0, #0
_0818C492:
	cmp r0, #0
	beq _0818C4C0
	ldr r1, _0818C4B8 @ =0x00000F8C
	add r1, sl
	movs r5, #0x81
	lsls r5, r5, #2
	adds r2, r7, r5
	adds r0, r7, #0
	bl FUN_08193328
	ldr r0, _0818C4BC @ =0xFFFFF7FF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r3, #1
	str r3, [sp, #0x30]
	b _0818C534
	.align 2, 0
_0818C4B8: .4byte 0x00000F8C
_0818C4BC: .4byte 0xFFFFF7FF
_0818C4C0:
	ldr r2, _0818C4EC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818C4F0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0818C4F4 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0xcb
	bgt _0818C500
	ldr r1, _0818C4F8 @ =0x00000F8C
	add r1, sl
	ldr r0, _0818C4FC @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	adds r0, r7, #0
	bl FUN_08193328
	b _0818C534
	.align 2, 0
_0818C4EC: .4byte 0x030046B8
_0818C4F0: .4byte 0x000003FF
_0818C4F4: .4byte 0x0203B400
_0818C4F8: .4byte 0x00000F8C
_0818C4FC: .4byte 0x03002BE0
_0818C500:
	ldr r1, _0818C51C @ =0x00000F8C
	add r1, sl
	adds r4, r7, #0
	adds r4, #8
	movs r3, #0x90
	lsls r3, r3, #0xc
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	adds r2, r4, #0
	bl FUN_08193b50
	adds r6, r4, #0
	b _0818C538
	.align 2, 0
_0818C51C: .4byte 0x00000F8C
_0818C520:
	ldr r1, _0818C5B4 @ =0x00000F8C
	add r1, sl
	movs r0, #0x81
	lsls r0, r0, #2
	adds r2, r7, r0
	adds r0, r7, #0
	bl FUN_08193328
	movs r1, #1
	str r1, [sp, #0x30]
_0818C534:
	adds r6, r7, #0
	adds r6, #8
_0818C538:
	add r4, sp, #8
	ldr r5, _0818C5B4 @ =0x00000F8C
	add r5, sl
	ldrh r0, [r5]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r5, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	bl FUN_0823785c
	strb r0, [r7, #5]
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _0818C5B8 @ =0x000FFFFF
	mov sb, r4
	cmp r1, r0
	bhi _0818C5BC
	adds r0, r2, #0
	movs r1, #0x30
	bl Div
	movs r5, #0xe0
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x30
	strh r0, [r1]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r2, [r0]
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r1, #0x30
	bl Div
	adds r5, #4
	b _0818C688
	.align 2, 0
_0818C5B4: .4byte 0x00000F8C
_0818C5B8: .4byte 0x000FFFFF
_0818C5BC:
	ldr r0, _0818C5F8 @ =0x001DE83F
	cmp r1, r0
	bhi _0818C5FC
	adds r0, r2, #0
	movs r1, #0x3e
	bl Div
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x3e
	strh r0, [r1]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	strh r1, [r0]
	mov r2, sb
	movs r3, #4
	ldrsh r0, [r2, r3]
	movs r1, #0x3e
	bl Div
	adds r5, #6
	b _0818C688
	.align 2, 0
_0818C5F8: .4byte 0x001DE83F
_0818C5FC:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0818C612
	movs r1, #0x81
	lsls r1, r1, #2
	adds r2, r7, r1
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08193a60
	b _0818C624
_0818C612:
	movs r3, #0x80
	lsls r3, r3, #0xb
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08193b50
_0818C624:
	ldr r2, _0818C704 @ =0x00000F8C
	add r2, sl
	ldrh r1, [r2]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	add r4, sp, #8
	strh r1, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	mov r3, sb
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl FUN_0823785c
	strb r0, [r7, #5]
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r1, #0x38
	bl Div
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x38
	strh r0, [r1]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	mov r2, sb
	movs r3, #4
	ldrsh r0, [r2, r3]
	movs r1, #0x38
	bl Div
	movs r5, #0xe2
	lsls r5, r5, #1
_0818C688:
	adds r1, r7, r5
	strh r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #4
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	strh r0, [r2]
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r0, r7, r3
	bl FUN_08013984
	ldr r5, _0818C708 @ =0x00000472
	adds r0, r7, r5
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_08191a14
	ldr r0, _0818C70C @ =0x000003E7
	bl PlaySound_082406e0
	ldr r0, _0818C710 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818C714 @ =0xFFFF7FFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818C6D2:
	ldr r3, _0818C718 @ =0x00000484
	adds r0, r7, r3
	ldr r0, [r0]
	cmp r0, #9
	bgt _0818C720
	add r4, sp, #0x10
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #4
	adds r1, r4, #0
	ldr r2, _0818C71C @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
_0818C6F2:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #2
	ble _0818C6F2
	b _0818C77A
	.align 2, 0
_0818C704: .4byte 0x00000F8C
_0818C708: .4byte 0x00000472
_0818C70C: .4byte 0x000003E7
_0818C710: .4byte 0x000003E5
_0818C714: .4byte 0xFFFF7FFF
_0818C718: .4byte 0x00000484
_0818C71C: .4byte 0x05000002
_0818C720:
	cmp r0, #0x13
	bgt _0818C750
	add r4, sp, #0x18
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #4
	adds r1, r4, #0
	ldr r2, _0818C74C @ =0x05000002
	bl CpuSet
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r5, #0
_0818C73A:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #5
	ble _0818C73A
	b _0818C77A
	.align 2, 0
_0818C74C: .4byte 0x05000002
_0818C750:
	cmp r0, #0x3b
	bgt _0818C77A
	add r4, sp, #0x20
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #4
	adds r1, r4, #0
	ldr r2, _0818C840 @ =0x05000002
	bl CpuSet
	movs r0, #0x40
	strh r0, [r4, #2]
	movs r5, #0
_0818C76A:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #5
	ble _0818C76A
_0818C77A:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #4
	movs r2, #8
	bl FUN_0818fdd8
	mov r0, sl
	bl FUN_0818f008
	movs r1, #0x10
	ldr r5, [sp, #0x34]
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0818C874
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _0818C844 @ =0x00000472
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08191a14
	movs r0, #0xda
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_0818e6fc
	add r2, sp, #0x28
	ldr r3, _0818C848 @ =0x000004A4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	strh r1, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xd
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r5, [r0]
	ldr r5, _0818C84C @ =0x0000046A
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0818C850 @ =0x00000484
	adds r0, r7, r1
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r2, [r0]
	movs r5, #0xaa
	lsls r5, r5, #2
	adds r0, r7, r5
	bl FUN_080139a0
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0818C854 @ =0x00000F2C
	add r0, sl
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818C858
	movs r0, #1
	b _0818C85A
	.align 2, 0
_0818C840: .4byte 0x05000002
_0818C844: .4byte 0x00000472
_0818C848: .4byte 0x000004A4
_0818C84C: .4byte 0x0000046A
_0818C850: .4byte 0x00000484
_0818C854: .4byte 0x00000F2C
_0818C858:
	movs r0, #0
_0818C85A:
	cmp r0, #0
	beq _0818C87E
	ldr r0, _0818C86C @ =0x00000E42
	add r0, sl
	ldrb r1, [r0]
	ldr r0, _0818C870 @ =0x00000E41
	add r0, sl
	strb r1, [r0]
	b _0818C87E
	.align 2, 0
_0818C86C: .4byte 0x00000E42
_0818C870: .4byte 0x00000E41
_0818C874:
	ldr r0, _0818C890 @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818C87E:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818C890: .4byte 0x00000484

	thumb_func_start FUN_0818c894
FUN_0818c894: @ 0x0818C894
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0818C8C0 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C8C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C8C6
	.align 2, 0
_0818C8C0: .4byte 0x0000046C
_0818C8C4:
	movs r0, #0
_0818C8C6:
	ldr r3, _0818CA14 @ =0x00000F2C
	add r3, sb
	mov r8, r3
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r5, r4, r5
	str r5, [sp, #0x10]
	cmp r0, #0
	beq _0818C92E
	ldr r1, _0818CA18 @ =0x00000472
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r3, #0
	strh r0, [r4, #0xa]
	movs r0, #0x20
	ldr r5, _0818CA1C @ =0x00000474
	adds r2, r4, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x18
	strh r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
	ldr r1, _0818CA20 @ =0xFFEFFFFF
	ldr r3, [sp, #0x10]
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	ldr r1, _0818CA24 @ =0xFFFF7FFF
	ands r0, r1
	strh r0, [r5]
_0818C92E:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r4, #0
	movs r1, #6
	movs r2, #6
	bl FUN_0818fdd8
	movs r6, #0
	ldr r1, _0818CA28 @ =0x00000F36
	add r1, sb
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r6, r0
	bge _0818C9B8
	mov r3, sp
	adds r7, r4, #0
	adds r7, #8
	ldr r0, _0818CA18 @ =0x00000472
	adds r0, r4, r0
	str r0, [sp, #0xc]
	str r1, [sp, #8]
	mov r5, sb
	mov ip, r6
	movs r1, #0x92
	lsls r1, r1, #1
	mov sl, r1
_0818C962:
	mov r2, ip
	add r2, sb
	ldr r0, _0818CA2C @ =0x00000674
	adds r2, r2, r0
	ldrh r0, [r2]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _0818C9A8
	ldr r0, [sp, #0xc]
	ldrh r1, [r0]
	ldr r2, _0818CA30 @ =0x00000676
	adds r0, r5, r2
	strh r1, [r0]
_0818C9A8:
	add r5, sl
	add ip, sl
	adds r6, #1
	ldr r1, [sp, #8]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	blt _0818C962
_0818C9B8:
	mov r0, sb
	bl FUN_0818f008
	movs r1, #0x10
	ldr r3, [sp, #0x10]
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0818CA04
	adds r0, r4, #0
	adds r0, #8
	ldr r5, _0818CA18 @ =0x00000472
	adds r1, r4, r5
	ldrh r1, [r1]
	bl FUN_08191a14
	ldr r0, _0818CA34 @ =0x000001DF
	bl PlaySound_082406e0
	ldr r0, _0818CA38 @ =0x000003E5
	bl sound_08240740
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #8
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x20
	ldr r3, _0818CA1C @ =0x00000474
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0818CA04:
	movs r1, #8
	mov r5, r8
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0818CA3C
	movs r0, #1
	b _0818CA3E
	.align 2, 0
_0818CA14: .4byte 0x00000F2C
_0818CA18: .4byte 0x00000472
_0818CA1C: .4byte 0x00000474
_0818CA20: .4byte 0xFFEFFFFF
_0818CA24: .4byte 0xFFFF7FFF
_0818CA28: .4byte 0x00000F36
_0818CA2C: .4byte 0x00000674
_0818CA30: .4byte 0x00000676
_0818CA34: .4byte 0x000001DF
_0818CA38: .4byte 0x000003E5
_0818CA3C:
	movs r0, #0
_0818CA3E:
	cmp r0, #0
	bne _0818CA44
	b _0818CB3C
_0818CA44:
	ldrh r0, [r4, #0xa]
	subs r0, #0x80
	movs r5, #0
	movs r6, #0
	strh r0, [r4, #0xa]
	mov r0, sb
	bl FUN_0818f008
	cmp r0, #0
	bge _0818CB3C
	ldr r2, _0818CA90 @ =0x00000D4E
	add r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _0818CA9C
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r5, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r5, [r0]
	ldr r5, _0818CA94 @ =0x0000046A
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _0818CA98 @ =0x00000484
	adds r0, r4, r1
	str r6, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	b _0818CB46
	.align 2, 0
_0818CA90: .4byte 0x00000D4E
_0818CA94: .4byte 0x0000046A
_0818CA98: .4byte 0x00000484
_0818CA9C:
	ldr r3, _0818CAD0 @ =0x00000D4F
	add r3, sb
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #4
	ble _0818CAE0
	movs r1, #0xe
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r3, _0818CAD4 @ =0x00000469
	adds r0, r4, r3
	strb r5, [r0]
	ldr r5, _0818CAD8 @ =0x0000046A
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _0818CADC @ =0x00000484
	adds r0, r4, r1
	str r6, [r0]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _0818CB46
	.align 2, 0
_0818CAD0: .4byte 0x00000D4F
_0818CAD4: .4byte 0x00000469
_0818CAD8: .4byte 0x0000046A
_0818CADC: .4byte 0x00000484
_0818CAE0:
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	ldr r5, _0818CB30 @ =0x0000046A
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _0818CB34 @ =0x00000484
	adds r0, r4, r1
	str r6, [r0]
	adds r2, #3
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	adds r5, #8
	adds r0, r4, r5
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	ldr r0, _0818CB38 @ =0x00000474
	adds r2, r4, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b _0818CB46
	.align 2, 0
_0818CB30: .4byte 0x0000046A
_0818CB34: .4byte 0x00000484
_0818CB38: .4byte 0x00000474
_0818CB3C:
	ldr r2, _0818CB58 @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818CB46:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818CB58: .4byte 0x00000484

	thumb_func_start FUN_0818cb5c
FUN_0818cb5c: @ 0x0818CB5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0818CB88 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818CB8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818CB8E
	.align 2, 0
_0818CB88: .4byte 0x0000046C
_0818CB8C:
	movs r0, #0
_0818CB8E:
	cmp r0, #0
	beq _0818CBE6
	movs r4, #0x20
	ldr r3, _0818CBC8 @ =0x00000474
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0818CBCC @ =0x00000F2C
	add r2, r8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0818CBD0 @ =0x00000ECA
	add r0, r8
	strh r3, [r0]
	ldr r0, _0818CBD4 @ =0xFFFF7FFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ands r0, r4
	cmp r0, #0
	beq _0818CBD8
	movs r0, #1
	b _0818CBDA
	.align 2, 0
_0818CBC8: .4byte 0x00000474
_0818CBCC: .4byte 0x00000F2C
_0818CBD0: .4byte 0x00000ECA
_0818CBD4: .4byte 0xFFFF7FFF
_0818CBD8:
	movs r0, #0
_0818CBDA:
	cmp r0, #0
	beq _0818CBE6
	movs r0, #0xda
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0818CBE6:
	ldrh r2, [r6, #0xa]
	movs r5, #0xa
	ldrsh r1, [r6, r5]
	ldr r0, _0818CC4C @ =0xFFFFF800
	cmp r1, r0
	ble _0818CC70
	adds r0, r2, #0
	subs r0, #0x80
	strh r0, [r6, #0xa]
	ldr r0, [r6, #0x44]
	ldr r0, [r0]
	cmp r0, #0
	bne _0818CC76
	movs r7, #0xa
	ldrsh r0, [r6, r7]
	ldr r1, _0818CC50 @ =0x00000472
	adds r2, r6, r1
	ldrh r3, [r2]
	cmp r0, r3
	bge _0818CC76
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldrh r1, [r2]
	lsls r1, r1, #0x10
	ldr r2, _0818CC54 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrb r2, [r6, #5]
	mov r0, sp
	movs r1, #2
	movs r3, #0
	bl FUN_08192ae0
	ldr r2, [r6, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x20
	ldr r0, _0818CC58 @ =0x00000F2C
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818CC5C
	movs r0, #1
	b _0818CC5E
	.align 2, 0
_0818CC4C: .4byte 0xFFFFF800
_0818CC50: .4byte 0x00000472
_0818CC54: .4byte 0x0000FFFF
_0818CC58: .4byte 0x00000F2C
_0818CC5C:
	movs r0, #0
_0818CC5E:
	cmp r0, #0
	bne _0818CC76
	ldr r0, _0818CC6C @ =0x000001DF
	bl PlaySound_082406e0
	b _0818CC76
	.align 2, 0
_0818CC6C: .4byte 0x000001DF
_0818CC70:
	movs r0, #0xf8
	lsls r0, r0, #8
	strh r0, [r6, #0xa]
_0818CC76:
	ldr r5, _0818CC90 @ =0x00000484
	adds r0, r6, r5
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _0818CC94
	adds r0, r6, #0
	movs r1, #0xa
	movs r2, #4
	movs r3, #0
	bl FUN_0818fdd8
	b _0818CCA0
	.align 2, 0
_0818CC90: .4byte 0x00000484
_0818CC94:
	ldr r3, _0818CD60 @ =0x0000A410
	adds r0, r6, #0
	movs r1, #0xc
	movs r2, #6
	bl FUN_0818fdd8
_0818CCA0:
	movs r5, #0
	ldr r1, _0818CD64 @ =0x00000F36
	add r1, r8
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r5, r0
	bge _0818CD28
	add r3, sp, #8
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #0x14]
	ldr r2, _0818CD68 @ =0x00000472
	adds r2, r6, r2
	str r2, [sp, #0x10]
	mov sl, r1
	mov r4, r8
	mov ip, r5
	movs r7, #0x92
	lsls r7, r7, #1
	mov sb, r7
_0818CCC8:
	mov r2, ip
	add r2, r8
	ldr r0, _0818CD6C @ =0x00000674
	adds r2, r2, r0
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldr r7, [sp, #0x14]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _0818CD18
	ldr r0, _0818CD70 @ =0x00000676
	adds r2, r4, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r7, [sp, #0x10]
	ldrh r1, [r7]
	cmp r0, r1
	bge _0818CD18
	strh r1, [r2]
_0818CD18:
	add r4, sb
	add ip, sb
	adds r5, #1
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r5, r0
	blt _0818CCC8
_0818CD28:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0xa
	bl FUN_08191774
	mov r0, r8
	bl FUN_0818f008
	cmp r0, #0
	blt _0818CD3E
	b _0818CF98
_0818CD3E:
	ldr r0, _0818CD74 @ =0x000003E5
	bl sound_08240740
	ldr r2, _0818CD78 @ =0x00000F2C
	add r2, r8
	ldr r1, _0818CD7C @ =0xFFFF7FFF
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	mov sl, r2
	cmp r0, #0
	beq _0818CD80
	movs r0, #1
	b _0818CD82
	.align 2, 0
_0818CD60: .4byte 0x0000A410
_0818CD64: .4byte 0x00000F36
_0818CD68: .4byte 0x00000472
_0818CD6C: .4byte 0x00000674
_0818CD70: .4byte 0x00000676
_0818CD74: .4byte 0x000003E5
_0818CD78: .4byte 0x00000F2C
_0818CD7C: .4byte 0xFFFF7FFF
_0818CD80:
	movs r0, #0
_0818CD82:
	cmp r0, #0
	beq _0818CDC4
	ldr r3, _0818CDBC @ =0x00000484
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r0, #0xa0
	bgt _0818CD92
	b _0818CF98
_0818CD92:
	movs r2, #0x13
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	movs r1, #0
	strb r1, [r0]
	ldr r7, _0818CDC0 @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	subs r3, #0x1a
	adds r0, r6, r3
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r6, r5
	str r1, [r0]
	adds r7, #3
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	b _0818CF98
	.align 2, 0
_0818CDBC: .4byte 0x00000484
_0818CDC0: .4byte 0x00000469
_0818CDC4:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0818CDD6
	movs r0, #1
	b _0818CDD8
_0818CDD6:
	movs r0, #0
_0818CDD8:
	adds r4, r0, #0
	cmp r4, #0
	bne _0818CDE0
	b _0818CEE0
_0818CDE0:
	ldr r7, _0818CDF4 @ =0x00000E41
	add r7, r8
	ldrb r0, [r7]
	mov sb, r0
	cmp r0, #0
	beq _0818CDF8
	subs r0, #1
	strb r0, [r7]
	b _0818CFA2
	.align 2, 0
_0818CDF4: .4byte 0x00000E41
_0818CDF8:
	ldr r3, _0818CEA4 @ =0x00000472
	adds r4, r6, r3
	ldr r5, _0818CEA8 @ =0xFFFFFF00
	adds r0, r5, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r6, #0xa]
	adds r5, r6, #0
	adds r5, #8
	mov r0, r8
	adds r1, r5, #0
	bl FUN_0819014c
	ldrh r0, [r4]
	strh r0, [r6, #0xa]
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r3, #0
	strb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _0818CEAC @ =0x0000046A
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _0818CEB0 @ =0x00000484
	adds r0, r6, r1
	mov r2, sb
	str r2, [r0]
	adds r3, #2
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0818CEB4 @ =0x00000474
	adds r2, r6, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldrb r2, [r6, #5]
	adds r0, r5, #0
	movs r1, #2
	movs r3, #0
	bl FUN_08192ae0
	ldr r2, [r6, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r2, #0xe4
	lsls r2, r2, #4
	add r2, r8
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r0, _0818CEB8 @ =0x00000E42
	add r0, r8
	ldrb r0, [r0]
	strb r0, [r7]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r5, _0818CEBC @ =0x00000546
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0818CEC4
	ldrb r0, [r2]
	cmp r0, #4
	bhi _0818CE94
	b _0818CFA2
_0818CE94:
	movs r7, #0
	strb r7, [r2]
	ldr r0, _0818CEC0 @ =0xFFFFFBFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0818CFA2
	.align 2, 0
_0818CEA4: .4byte 0x00000472
_0818CEA8: .4byte 0xFFFFFF00
_0818CEAC: .4byte 0x0000046A
_0818CEB0: .4byte 0x00000484
_0818CEB4: .4byte 0x00000474
_0818CEB8: .4byte 0x00000E42
_0818CEBC: .4byte 0x00000546
_0818CEC0: .4byte 0xFFFFFBFF
_0818CEC4:
	ldrb r0, [r2]
	cmp r0, #2
	bls _0818CFA2
	movs r3, #0
	strb r3, [r2]
	ldr r0, _0818CEDC @ =0xFFFFFBFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	b _0818CFA2
	.align 2, 0
_0818CEDC: .4byte 0xFFFFFBFF
_0818CEE0:
	ldr r7, _0818CF2C @ =0x00000484
	adds r0, r6, r7
	movs r1, #0xd5
	lsls r1, r1, #4
	add r1, r8
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	ble _0818CF98
	ldr r2, _0818CF30 @ =0x00000D4E
	add r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _0818CF38
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r4, [r0]
	ldr r5, _0818CF34 @ =0x00000469
	adds r0, r6, r5
	strb r4, [r0]
	subs r7, #0x1a
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0818CF2C @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	adds r3, #4
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	b _0818CFA2
	.align 2, 0
_0818CF2C: .4byte 0x00000484
_0818CF30: .4byte 0x00000D4E
_0818CF34: .4byte 0x00000469
_0818CF38:
	movs r1, #0x16
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r4, [r0]
	ldr r7, _0818CF84 @ =0x00000469
	adds r0, r6, r7
	strb r4, [r0]
	ldr r2, _0818CF88 @ =0x0000046A
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _0818CF8C @ =0x00000484
	adds r0, r6, r3
	str r4, [r0]
	adds r5, #4
	adds r0, r6, r5
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0818CF90 @ =FUN_080e48d0
	movs r2, #0x10
	adds r7, #4
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0818CF94 @ =0x0000046B
	adds r0, r6, r1
	strb r4, [r0]
	adds r5, #0xe7
	adds r0, r6, r5
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	b _0818CFA2
	.align 2, 0
_0818CF84: .4byte 0x00000469
_0818CF88: .4byte 0x0000046A
_0818CF8C: .4byte 0x00000484
_0818CF90: .4byte FUN_080e48d0
_0818CF94: .4byte 0x0000046B
_0818CF98:
	ldr r2, _0818CFB4 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818CFA2:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818CFB4: .4byte 0x00000484

	thumb_func_start FUN_0818cfb8
FUN_0818cfb8: @ 0x0818CFB8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0818CFD8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818CFDC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818CFDE
	.align 2, 0
_0818CFD8: .4byte 0x0000046C
_0818CFDC:
	movs r0, #0
_0818CFDE:
	cmp r0, #0
	bne _0818CFE4
	b _0818D0FA
_0818CFE4:
	movs r2, #0x10
	ldr r3, _0818CFF8 @ =0x00000F2C
	adds r1, r7, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0818CFFC
	movs r0, #1
	b _0818CFFE
	.align 2, 0
_0818CFF8: .4byte 0x00000F2C
_0818CFFC:
	movs r0, #0
_0818CFFE:
	adds r2, r0, #0
	cmp r2, #0
	bne _0818D0FA
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r4, #1
	ldr r3, _0818D0C4 @ =0x0000046D
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_0818f918
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0818f17c
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r2, _0818D0C8 @ =0x00000472
	adds r4, r5, r2
	ldr r3, _0818D0CC @ =0xFFFFFF00
	adds r0, r3, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	adds r1, r5, #0
	adds r1, #8
	adds r0, r7, #0
	bl FUN_0819014c
	movs r0, #0x20
	ldr r3, _0818D0D0 @ =0x00000474
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	ldr r2, _0818D0D4 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrb r2, [r5, #5]
	mov r0, sp
	movs r1, #2
	movs r3, #0
	bl FUN_08192ae0
	ldr r0, _0818D0D8 @ =0x00000D44
	adds r2, r7, r0
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0818D0DC @ =0x00000D54
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0818D0E0 @ =0x00000D4C
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0x10
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0818D0E4
	movs r0, #1
	b _0818D0E6
	.align 2, 0
_0818D0C4: .4byte 0x0000046D
_0818D0C8: .4byte 0x00000472
_0818D0CC: .4byte 0xFFFFFF00
_0818D0D0: .4byte 0x00000474
_0818D0D4: .4byte 0x0000FFFF
_0818D0D8: .4byte 0x00000D44
_0818D0DC: .4byte 0x00000D54
_0818D0E0: .4byte 0x00000D4C
_0818D0E4:
	movs r0, #0
_0818D0E6:
	cmp r0, #0
	bne _0818D0FA
	ldr r0, _0818D128 @ =0x000003E5
	bl PlaySound_082406e0
	movs r0, #0x80
	lsls r0, r0, #8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
_0818D0FA:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _0818D12C @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818D134
	ldr r3, _0818D130 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0818D144
	.align 2, 0
_0818D128: .4byte 0x000003E5
_0818D12C: .4byte 0x0000A02F
_0818D130: .4byte 0x00000482
_0818D134:
	ldr r1, _0818D168 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0818D144
	movs r0, #1
	strh r0, [r2]
_0818D144:
	ldr r3, _0818D16C @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818D170
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0818D188
	.align 2, 0
_0818D168: .4byte 0x00000482
_0818D16C: .4byte 0x0000025D
_0818D170:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0818D188:
	ldr r1, _0818D1C0 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _0818D1AA
	rsbs r2, r2, #0
_0818D1AA:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0818D1C4
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0818D1B8
	rsbs r2, r2, #0
_0818D1B8:
	cmp r2, #0x20
	bgt _0818D1C4
	movs r0, #1
	b _0818D22E
	.align 2, 0
_0818D1C0: .4byte 0x000004A4
_0818D1C4:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0818D1D0
	cmp r1, #0
	beq _0818D22C
_0818D1D0:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _0818D1F4 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0818D1F8
	asrs r1, r0, #0xc
	b _0818D1FE
	.align 2, 0
_0818D1F4: .4byte 0x085B0A08
_0818D1F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818D1FE:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _0818D21C @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _0818D220
	asrs r1, r0, #0xc
	b _0818D226
	.align 2, 0
_0818D21C: .4byte 0x085B0A08
_0818D220:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818D226:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_0818D22C:
	movs r0, #0
_0818D22E:
	cmp r0, #0
	beq _0818D2F8
	adds r0, r5, #0
	bl FUN_0818e6fc
	add r2, sp, #8
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _0818D29C @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r1, #0xee
	lsls r1, r1, #1
	adds r3, r5, r1
	strb r0, [r3]
	ldr r2, _0818D2A0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818D2A4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0818D2A8 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _0818D2F8
	ldrb r1, [r3]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818D2B0
	ldr r3, _0818D2AC @ =0xFFFFFF00
	adds r1, r1, r3
	b _0818D2BE
	.align 2, 0
_0818D29C: .4byte 0x000004A4
_0818D2A0: .4byte 0x030046B8
_0818D2A4: .4byte 0x000003FF
_0818D2A8: .4byte 0x0203B400
_0818D2AC: .4byte 0xFFFFFF00
_0818D2B0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818D2BE
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818D2BE:
	cmp r1, #0
	bge _0818D2C4
	rsbs r1, r1, #0
_0818D2C4:
	cmp r1, #0x20
	ble _0818D2F8
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818D2F0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0818D2F4 @ =0x0000046A
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	b _0818D3CE
	.align 2, 0
_0818D2F0: .4byte 0x00000469
_0818D2F4: .4byte 0x0000046A
_0818D2F8:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08190804
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_0818fdd8
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_0818f938
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0818f17c
	ldr r0, _0818D3A8 @ =0x00000484
	adds r6, r5, r0
	ldr r0, [r6]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0818D336
	adds r0, r5, #0
	bl FUN_08191a9c
_0818D336:
	adds r0, r5, #0
	bl FUN_0819267c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818D3CE
	ldr r2, _0818D3AC @ =0x00000D4C
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	bne _0818D3C4
	movs r1, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r6, _0818D3B0 @ =0x00000469
	adds r0, r5, r6
	strb r4, [r0]
	ldr r2, _0818D3B4 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0818D3B8 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818D3BC @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r3, _0818D3C0 @ =0x00000F2C
	adds r2, r7, r3
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0818D3CE
	.align 2, 0
_0818D3A8: .4byte 0x00000484
_0818D3AC: .4byte 0x00000D4C
_0818D3B0: .4byte 0x00000469
_0818D3B4: .4byte 0x0000046A
_0818D3B8: .4byte FUN_080e48d0
_0818D3BC: .4byte 0x0000046B
_0818D3C0: .4byte 0x00000F2C
_0818D3C4:
	subs r0, #1
	strh r0, [r1]
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
_0818D3CE:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0818d3d8
FUN_0818d3d8: @ 0x0818D3D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0818D400 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818D404
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818D406
	.align 2, 0
_0818D400: .4byte 0x0000046C
_0818D404:
	movs r0, #0
_0818D406:
	cmp r0, #0
	beq _0818D4EA
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #1
	ldr r4, _0818D530 @ =0x0000046D
	adds r0, r7, r4
	movs r5, #0
	strb r1, [r0]
	ldr r3, _0818D534 @ =0x0000046B
	adds r0, r7, r3
	strb r5, [r0]
	adds r4, #0xe6
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r7, #5]
	adds r6, r7, #0
	adds r6, #8
	ldr r0, _0818D538 @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08193648
	subs r4, #0xdf
	adds r2, r7, r4
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r4, _0818D53C @ =0x00000F2C
	add r4, r8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x2a
	strh r0, [r1]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _0818D540 @ =0x00000472
	adds r5, r7, r2
	ldr r3, _0818D544 @ =0xFFFFF818
	adds r1, r3, #0
	ldrh r0, [r5]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _0818D548 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, r8
	mov r1, sp
	bl FUN_0819014c
	ldrh r1, [r5]
	adds r0, r6, #0
	bl FUN_08191a14
	movs r0, #0xcf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _0818D54C @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818D550 @ =0xFFFF7FFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #6
	movs r3, #0
	bl FUN_0819328c
	movs r0, #0x80
	lsls r0, r0, #6
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_0818D4EA:
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0818D55C
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #2
	movs r3, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r7, r4
	strb r2, [r0]
	ldr r2, _0818D554 @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	adds r4, #0x1b
	adds r0, r7, r4
	str r1, [r0]
	ldr r1, _0818D558 @ =0x0000046C
	adds r0, r7, r1
	strb r3, [r0]
	b _0818D5A0
	.align 2, 0
_0818D530: .4byte 0x0000046D
_0818D534: .4byte 0x0000046B
_0818D538: .4byte 0x03002BE0
_0818D53C: .4byte 0x00000F2C
_0818D540: .4byte 0x00000472
_0818D544: .4byte 0xFFFFF818
_0818D548: .4byte 0x0000FFFF
_0818D54C: .4byte 0x000003E5
_0818D550: .4byte 0xFFFF7FFF
_0818D554: .4byte 0x0000046A
_0818D558: .4byte 0x0000046C
_0818D55C:
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0818D572
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _0818D57A
_0818D572:
	adds r0, r7, #0
	movs r1, #3
	bl FUN_08191ca0
_0818D57A:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #4
	movs r2, #8
	bl FUN_0818fdd8
	mov r0, r8
	bl FUN_0818f008
	mov r0, r8
	movs r1, #4
	bl FUN_0818f17c
	ldr r3, _0818D5AC @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818D5A0:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818D5AC: .4byte 0x00000484

	thumb_func_start FUN_0818d5b0
FUN_0818d5b0: @ 0x0818D5B0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r2, _0818D5D8 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818D5DC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818D5DE
	.align 2, 0
_0818D5D8: .4byte 0x0000046C
_0818D5DC:
	movs r0, #0
_0818D5DE:
	cmp r0, #0
	beq _0818D69A
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #1
	ldr r4, _0818D744 @ =0x0000046D
	adds r0, r7, r4
	movs r3, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r3, [r0]
	subs r4, #0xe1
	adds r4, r7, r4
	str r4, [sp, #0x10]
	ldrh r0, [r4]
	strh r0, [r7, #0xa]
	movs r6, #0x20
	ldr r0, _0818D748 @ =0x00000474
	adds r2, r7, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0818D74C @ =0x00000F2C
	adds r4, r5, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r3, [r0]
	subs r2, #6
	adds r0, r7, r2
	strh r3, [r0]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _0818D750 @ =0xFFFFF818
	adds r1, r3, #0
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _0818D754 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0819014c
	ldr r0, _0818D758 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818D75C @ =0xFFFF7FFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	movs r1, #2
	movs r2, #6
	movs r3, #1
	bl FUN_0819328c
_0818D69A:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #6
	movs r2, #6
	bl FUN_0818fdd8
	adds r0, r5, #0
	bl FUN_0818f008
	movs r0, #0x10
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0818D6C0
	b _0818D7E8
_0818D6C0:
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r1, r0
	str r1, [r2]
	ldr r3, _0818D74C @ =0x00000F2C
	adds r2, r5, r3
	movs r1, #0x11
	rsbs r1, r1, #0
	ldrh r0, [r2]
	ands r1, r0
	movs r4, #0
	mov r8, r4
	movs r0, #0
	mov sb, r0
	strh r1, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	add r2, sp, #8
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _0818D760 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _0818D764 @ =0x00000D4F
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	movs r2, #0xed
	lsls r2, r2, #4
	adds r0, r5, r2
	mov r3, sb
	strh r3, [r0]
	ldrb r1, [r1]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818D76C
	ldr r4, _0818D768 @ =0xFFFFFF00
	adds r1, r1, r4
	b _0818D77A
	.align 2, 0
_0818D744: .4byte 0x0000046D
_0818D748: .4byte 0x00000474
_0818D74C: .4byte 0x00000F2C
_0818D750: .4byte 0xFFFFF818
_0818D754: .4byte 0x0000FFFF
_0818D758: .4byte 0x000003E5
_0818D75C: .4byte 0xFFFF7FFF
_0818D760: .4byte 0x000004A4
_0818D764: .4byte 0x00000D4F
_0818D768: .4byte 0xFFFFFF00
_0818D76C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818D77A
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818D77A:
	cmp r1, #0
	bge _0818D780
	rsbs r1, r1, #0
_0818D780:
	cmp r1, #0x20
	ble _0818D7B4
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818D7AC @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _0818D7B0 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r7, r3
	str r1, [r0]
	adds r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	b _0818D7F2
	.align 2, 0
_0818D7AC: .4byte 0x00000469
_0818D7B0: .4byte 0x0000046A
_0818D7B4:
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818D7DC @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _0818D7E0 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	ldr r2, _0818D7E4 @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _0818D7F2
	.align 2, 0
_0818D7DC: .4byte 0x00000469
_0818D7E0: .4byte 0x0000046A
_0818D7E4: .4byte 0x00000484
_0818D7E8:
	ldr r4, _0818D800 @ =0x00000484
	adds r1, r7, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818D7F2:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818D800: .4byte 0x00000484

	thumb_func_start FUN_0818d804
FUN_0818d804: @ 0x0818D804
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _0818D830 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818D834
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818D836
	.align 2, 0
_0818D830: .4byte 0x0000046C
_0818D834:
	movs r0, #0
_0818D836:
	cmp r0, #0
	beq _0818D8F4
	movs r4, #0xd3
	lsls r4, r4, #4
	add r4, sl
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
	ldr r2, _0818D94C @ =0x00000D38
	add r2, sl
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, _0818D950 @ =0x0203B400
	mov r8, r3
	ldr r3, _0818D954 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _0818D958 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r0, #0x40
	movs r5, #0x7f
	ands r2, r5
	adds r0, r0, r2
	movs r2, #0
	mov sb, r2
	movs r2, #0
	mov ip, r2
	strh r0, [r4]
	adds r1, #1
	ldr r0, _0818D958 @ =0x000003FF
	ands r1, r0
	str r1, [r3]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	ldr r2, _0818D95C @ =0x00000D34
	add r2, sl
	ldrh r0, [r2]
	subs r0, #0x40
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
	ldrb r1, [r7, #5]
	ldr r0, _0818D960 @ =0x00000D42
	add r0, sl
	strb r1, [r0]
	movs r1, #0xd4
	lsls r1, r1, #4
	add r1, sl
	movs r0, #0x3c
	strh r0, [r1]
	ldr r3, _0818D964 @ =FUN_0818a604
	movs r2, #0x27
	ldr r5, _0818D968 @ =0x0000046D
	adds r1, r7, r5
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818D96C @ =0x0000046B
	adds r0, r7, r1
	mov r5, sb
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r5, ip
	strh r5, [r0]
	ldr r4, _0818D970 @ =0x00000F2C
	add r4, sl
	movs r0, #0x41
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r0, _0818D974 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818D978 @ =0xFFFF7FFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_0818D8F4:
	movs r0, #0xd3
	lsls r0, r0, #4
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #8
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r4, #0xd4
	lsls r4, r4, #4
	add r4, sl
	ldrh r1, [r4]
	bl Div
	ldrh r1, [r7, #0x10]
	adds r1, r1, r0
	strh r1, [r7, #0x10]
	ldr r0, _0818D95C @ =0x00000D34
	add r0, sl
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #0xc
	ldrsh r1, [r7, r5]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	ldrh r1, [r7, #0x14]
	adds r1, r1, r0
	strh r1, [r7, #0x14]
	movs r1, #0x10
	ldrsh r0, [r7, r1]
	movs r2, #0x14
	ldrsh r1, [r7, r2]
	bl FUN_0823785c
	adds r2, r0, #0
	ldrb r0, [r7, #5]
	subs r1, r2, r0
	cmp r1, #0x80
	ble _0818D980
	ldr r3, _0818D97C @ =0xFFFFFF00
	adds r1, r1, r3
	b _0818D98E
	.align 2, 0
_0818D94C: .4byte 0x00000D38
_0818D950: .4byte 0x0203B400
_0818D954: .4byte 0x030046B8
_0818D958: .4byte 0x000003FF
_0818D95C: .4byte 0x00000D34
_0818D960: .4byte 0x00000D42
_0818D964: .4byte FUN_0818a604
_0818D968: .4byte 0x0000046D
_0818D96C: .4byte 0x0000046B
_0818D970: .4byte 0x00000F2C
_0818D974: .4byte 0x000003E5
_0818D978: .4byte 0xFFFF7FFF
_0818D97C: .4byte 0xFFFFFF00
_0818D980:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818D98E
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0818D98E:
	adds r0, r1, #0
	cmp r1, #0
	bge _0818D996
	rsbs r0, r1, #0
_0818D996:
	cmp r0, #0x1f
	bgt _0818D99E
	strb r2, [r7, #5]
	b _0818D9AE
_0818D99E:
	cmp r1, #0
	bge _0818D9A8
	ldrb r0, [r7, #5]
	subs r0, #4
	b _0818D9AC
_0818D9A8:
	ldrb r0, [r7, #5]
	adds r0, #4
_0818D9AC:
	strb r0, [r7, #5]
_0818D9AE:
	movs r6, #0xd4
	lsls r6, r6, #4
	add r6, sl
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0818DA2A
	movs r3, #0xd3
	lsls r3, r3, #4
	add r3, sl
	ldr r0, _0818DAD8 @ =0x00000D38
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r0, _0818DADC @ =0x0203B400
	mov sb, r0
	ldr r4, _0818DAE0 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r2, _0818DAE4 @ =0x000003FF
	ands r1, r2
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldrh r0, [r3]
	subs r0, #0x40
	movs r5, #0x7f
	mov r8, r5
	mov r5, r8
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ldr r0, _0818DAE4 @ =0x000003FF
	ands r1, r0
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldr r3, _0818DAE8 @ =0x00000D34
	add r3, sl
	ldrh r0, [r3]
	subs r0, #0x40
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ldr r2, _0818DAE4 @ =0x000003FF
	ands r1, r2
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x1e
	strh r0, [r6]
_0818DA2A:
	ldr r3, _0818DAEC @ =0x00000484
	adds r2, r7, r3
	ldr r1, [r2]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bgt _0818DA3A
	b _0818DCF8
_0818DA3A:
	ldr r5, _0818DAF0 @ =0x00000546
	adds r0, r7, r5
	ldrh r1, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _0818DA50
	b _0818DBAC
_0818DA50:
	ldr r2, _0818DAE0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818DAE4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0818DADC @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x2f
	ble _0818DA6A
	b _0818DB7C
_0818DA6A:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _0818DAF4 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	mov r2, sp
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _0818DAF8 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #4
	ldrsh r1, [r2, r5]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _0818DAFC @ =0x00000D4F
	add r0, sl
	movs r3, #0
	strb r3, [r0]
	ldrb r1, [r1]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818DB04
	ldr r5, _0818DB00 @ =0xFFFFFF00
	adds r1, r1, r5
	b _0818DB12
	.align 2, 0
_0818DAD8: .4byte 0x00000D38
_0818DADC: .4byte 0x0203B400
_0818DAE0: .4byte 0x030046B8
_0818DAE4: .4byte 0x000003FF
_0818DAE8: .4byte 0x00000D34
_0818DAEC: .4byte 0x00000484
_0818DAF0: .4byte 0x00000546
_0818DAF4: .4byte 0xFFEFFFFF
_0818DAF8: .4byte 0x000004A4
_0818DAFC: .4byte 0x00000D4F
_0818DB00: .4byte 0xFFFFFF00
_0818DB04:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818DB12
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818DB12:
	cmp r1, #0
	bge _0818DB18
	rsbs r1, r1, #0
_0818DB18:
	cmp r1, #0x20
	ble _0818DB4C
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818DB44 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r5, _0818DB48 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r7, r3
	str r1, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	b _0818DCFC
	.align 2, 0
_0818DB44: .4byte 0x00000469
_0818DB48: .4byte 0x0000046A
_0818DB4C:
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818DB70 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r5, _0818DB74 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _0818DB78 @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r7, r3
	b _0818DCE4
	.align 2, 0
_0818DB70: .4byte 0x00000469
_0818DB74: .4byte 0x0000046A
_0818DB78: .4byte 0x00000484
_0818DB7C:
	movs r1, #0x11
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0818DBA4 @ =0x00000469
	adds r0, r7, r3
	strb r2, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0818DBA8 @ =0x00000484
	adds r0, r7, r1
	movs r2, #0
	str r2, [r0]
	adds r3, #3
	adds r1, r7, r3
	b _0818DCE4
	.align 2, 0
_0818DBA4: .4byte 0x00000469
_0818DBA8: .4byte 0x00000484
_0818DBAC:
	ldr r2, _0818DC38 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818DC3C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0818DC40 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0xc1
	ble _0818DBC6
	b _0818DCC0
_0818DBC6:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _0818DC44 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	add r2, sp, #8
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _0818DC48 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r5, #4
	ldrsh r1, [r2, r5]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _0818DC4C @ =0x00000D4F
	add r0, sl
	movs r3, #0
	strb r3, [r0]
	movs r0, #0xed
	lsls r0, r0, #4
	add r0, sl
	movs r5, #0
	strh r5, [r0]
	ldrb r1, [r1]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818DC54
	ldr r0, _0818DC50 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0818DC62
	.align 2, 0
_0818DC38: .4byte 0x030046B8
_0818DC3C: .4byte 0x000003FF
_0818DC40: .4byte 0x0203B400
_0818DC44: .4byte 0xFFEFFFFF
_0818DC48: .4byte 0x000004A4
_0818DC4C: .4byte 0x00000D4F
_0818DC50: .4byte 0xFFFFFF00
_0818DC54:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818DC62
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0818DC62:
	cmp r1, #0
	bge _0818DC68
	rsbs r1, r1, #0
_0818DC68:
	cmp r1, #0x20
	ble _0818DC9C
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r1, [r0]
	ldr r5, _0818DC94 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r1, [r0]
	ldr r1, _0818DC98 @ =0x0000046C
	adds r0, r7, r1
	strb r2, [r0]
	b _0818DCFC
	.align 2, 0
_0818DC94: .4byte 0x00000469
_0818DC98: .4byte 0x0000046C
_0818DC9C:
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r1, [r0]
	ldr r5, _0818DCBC @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r1, [r0]
	b _0818DCE0
	.align 2, 0
_0818DCBC: .4byte 0x00000469
_0818DCC0:
	movs r1, #0x11
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	movs r3, #0
	strb r3, [r0]
	ldr r5, _0818DCEC @ =0x00000469
	adds r0, r7, r5
	strb r3, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _0818DCF0 @ =0x00000484
	adds r0, r7, r3
	movs r5, #0
	str r5, [r0]
_0818DCE0:
	ldr r0, _0818DCF4 @ =0x0000046C
	adds r1, r7, r0
_0818DCE4:
	movs r0, #1
	strb r0, [r1]
	b _0818DCFC
	.align 2, 0
_0818DCEC: .4byte 0x00000469
_0818DCF0: .4byte 0x00000484
_0818DCF4: .4byte 0x0000046C
_0818DCF8:
	adds r0, r1, #1
	str r0, [r2]
_0818DCFC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0818dd0c
FUN_0818dd0c: @ 0x0818DD0C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0818DD2C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818DD30
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818DD32
	.align 2, 0
_0818DD2C: .4byte 0x0000046C
_0818DD30:
	movs r0, #0
_0818DD32:
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r6, r5, r4
	cmp r0, #0
	beq _0818DDA0
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0818DDFC @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0818DE00 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	ldr r0, _0818DE04 @ =0x00000F2C
	adds r4, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0818DE08 @ =0x0000FFC0
	strh r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r1, _0818DE0C @ =0xFFEFFFFF
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r0, _0818DE10 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818DE14 @ =0xFFFF7FFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_0818DDA0:
	ldr r3, _0818DE18 @ =0x0000FFFF
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	adds r0, r7, #0
	bl FUN_0818f008
	movs r1, #0x10
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0818DDEA
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	movs r2, #0xd
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _0818DE1C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r3, [r0]
_0818DDEA:
	ldr r0, _0818DE1C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818DDFC: .4byte 0x0000046D
_0818DE00: .4byte 0x0000046B
_0818DE04: .4byte 0x00000F2C
_0818DE08: .4byte 0x0000FFC0
_0818DE0C: .4byte 0xFFEFFFFF
_0818DE10: .4byte 0x000003E5
_0818DE14: .4byte 0xFFFF7FFF
_0818DE18: .4byte 0x0000FFFF
_0818DE1C: .4byte 0x00000484

	thumb_func_start FUN_0818de20
FUN_0818de20: @ 0x0818DE20
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _0818DE44 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818DE48
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818DE4A
	.align 2, 0
_0818DE44: .4byte 0x0000046C
_0818DE48:
	movs r0, #0
_0818DE4A:
	adds r1, r0, #0
	cmp r1, #0
	bne _0818DE52
	b _0818E028
_0818DE52:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _0818DEE8 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	subs r4, #0xd3
	strh r4, [r6, #8]
	movs r0, #0xfc
	lsls r0, r0, #8
	strh r0, [r6, #0xa]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r6, #0xc]
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0819014c
	movs r0, #0x20
	ldr r1, _0818DEEC @ =0x00000474
	adds r3, r6, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0818DEF0 @ =0x00000F2C
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0818DEF4 @ =0x0000047A
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r4, r6, r4
	ldrh r0, [r4]
	adds r1, r1, r0
	ldr r4, _0818DEF8 @ =0x0000025D
	adds r0, r6, r4
	ldrb r0, [r0]
	adds r7, r5, #0
	mov r8, r3
	adds r5, r2, #0
	cmp r0, #0
	bne _0818DEFC
	ldr r0, [r6, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0818DF08
	.align 2, 0
_0818DEE8: .4byte 0x0000046D
_0818DEEC: .4byte 0x00000474
_0818DEF0: .4byte 0x00000F2C
_0818DEF4: .4byte 0x0000047A
_0818DEF8: .4byte 0x0000025D
_0818DEFC:
	ldr r2, [r6, #0x44]
	ldr r0, _0818DF78 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0818DF08:
	ldr r0, _0818DF7C @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #6
	movs r3, #0
	bl FUN_0819328c
	ldr r0, _0818DF80 @ =0x03002BE0
	add r2, sp, #4
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	strb r0, [r6, #5]
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r6, r4
	ldrb r4, [r6, #5]
	movs r0, #0x16
	mov ip, r0
	ldr r2, _0818DF84 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _0818DF88
	asrs r1, r0, #0xc
	b _0818DF8E
	.align 2, 0
_0818DF78: .4byte 0x03003584
_0818DF7C: .4byte 0xFFFFFEFF
_0818DF80: .4byte 0x03002BE0
_0818DF84: .4byte 0x085B0A08
_0818DF88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818DF8E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0818DFAC @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0818DFB0
	asrs r0, r0, #0xc
	b _0818DFB6
	.align 2, 0
_0818DFAC: .4byte 0x085B0A08
_0818DFB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818DFB6:
	movs r1, #0
	strh r0, [r3, #4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r0, #0x30
	strh r0, [r2]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	subs r4, #0x42
	adds r2, r6, r4
	ldr r1, _0818E014 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r6, #0
	bl FUN_081929cc
	ldr r1, _0818E018 @ =0x00000472
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl FUN_08191a14
	ldr r0, _0818E01C @ =0x000003E7
	bl PlaySound_082406e0
	ldr r0, _0818E020 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818E024 @ =0xFFFF7FFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	b _0818E146
	.align 2, 0
_0818E014: .4byte 0xFFEFFFFF
_0818E018: .4byte 0x00000472
_0818E01C: .4byte 0x000003E7
_0818E020: .4byte 0x000003E5
_0818E024: .4byte 0xFFFF7FFF
_0818E028:
	ldr r2, _0818E058 @ =0x00000484
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, #9
	bgt _0818E060
	add r4, sp, #0xc
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0818E05C @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
_0818E046:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #2
	ble _0818E046
	b _0818E0B8
	.align 2, 0
_0818E058: .4byte 0x00000484
_0818E05C: .4byte 0x05000002
_0818E060:
	cmp r0, #0x13
	bgt _0818E090
	add r4, sp, #0x14
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0818E08C @ =0x05000002
	bl CpuSet
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r5, #0
_0818E078:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #5
	ble _0818E078
	b _0818E0B8
	.align 2, 0
_0818E08C: .4byte 0x05000002
_0818E090:
	cmp r0, #0x3b
	bgt _0818E0B8
	add r4, sp, #0x1c
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0818E12C @ =0x05000002
	bl CpuSet
	movs r0, #0x40
	strh r0, [r4, #2]
	movs r5, #0
_0818E0A8:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #5
	ble _0818E0A8
_0818E0B8:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r6, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r3, #0xa
	ldrsh r1, [r6, r3]
	ldr r4, _0818E130 @ =0x00000472
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r1, r0
	blt _0818E0E0
	ldr r0, [r6, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0818E0E0:
	adds r0, r7, #0
	bl FUN_0818f008
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0818E13C
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x15
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818E134 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _0818E138 @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _0818E146
	.align 2, 0
_0818E12C: .4byte 0x05000002
_0818E130: .4byte 0x00000472
_0818E134: .4byte 0x00000469
_0818E138: .4byte 0x00000484
_0818E13C:
	ldr r4, _0818E154 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818E146:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818E154: .4byte 0x00000484

	thumb_func_start FUN_0818e158
FUN_0818e158: @ 0x0818E158
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r6, _0818E178 @ =0x0000046C
	adds r1, r5, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818E17C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818E17E
	.align 2, 0
_0818E178: .4byte 0x0000046C
_0818E17C:
	movs r0, #0
_0818E17E:
	cmp r0, #0
	beq _0818E1BC
	ldr r0, _0818E1B0 @ =0x00000F2C
	adds r2, r2, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0818E1B4 @ =0x00000474
	adds r2, r5, r1
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _0818E1B8 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0818E29C
	.align 2, 0
_0818E1B0: .4byte 0x00000F2C
_0818E1B4: .4byte 0x00000474
_0818E1B8: .4byte 0xFFEFFFFF
_0818E1BC:
	ldr r1, _0818E1D8 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x46
	beq _0818E200
	cmp r0, #0x46
	bgt _0818E1E2
	cmp r0, #0x1e
	beq _0818E200
	cmp r0, #0x1e
	bgt _0818E1DC
	cmp r0, #0xa
	beq _0818E1FA
	b _0818E206
	.align 2, 0
_0818E1D8: .4byte 0x00000484
_0818E1DC:
	cmp r0, #0x32
	beq _0818E200
	b _0818E206
_0818E1E2:
	cmp r0, #0x5a
	beq _0818E200
	cmp r0, #0x5a
	bgt _0818E1F0
	cmp r0, #0x50
	beq _0818E200
	b _0818E206
_0818E1F0:
	cmp r0, #0x5f
	beq _0818E200
	cmp r0, #0x64
	beq _0818E200
	b _0818E206
_0818E1FA:
	ldr r0, _0818E278 @ =0x000001A7
	bl PlaySound_082406e0
_0818E200:
	adds r0, r5, #0
	bl FUN_08190634
_0818E206:
	ldr r2, _0818E27C @ =0x00000484
	adds r4, r5, r2
	ldr r0, [r4]
	cmp r0, #0x19
	bne _0818E216
	ldr r0, _0818E280 @ =0x00000143
	bl PlaySound_082406e0
_0818E216:
	ldr r3, _0818E284 @ =0x00002EE0
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	ldr r0, [r4]
	cmp r0, #0x64
	ble _0818E298
	ldr r3, _0818E288 @ =FUN_0818b1c8
	movs r1, #0x11
	ldr r6, _0818E28C @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818E290 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _0818E294 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	b _0818E29C
	.align 2, 0
_0818E278: .4byte 0x000001A7
_0818E27C: .4byte 0x00000484
_0818E280: .4byte 0x00000143
_0818E284: .4byte 0x00002EE0
_0818E288: .4byte FUN_0818b1c8
_0818E28C: .4byte 0x0000046D
_0818E290: .4byte 0x00000469
_0818E294: .4byte 0x0000046C
_0818E298:
	adds r0, #1
	str r0, [r4]
_0818E29C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0818e2a4
FUN_0818e2a4: @ 0x0818E2A4
	ldr r1, _0818E2B0 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _0818E2B4 @ =0x085ADCF4
	str r1, [r0]
	bx lr
	.align 2, 0
_0818E2B0: .4byte 0x00000634
_0818E2B4: .4byte 0x085ADCF4

	thumb_func_start FUN_0818e2b8
FUN_0818e2b8: @ 0x0818E2B8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818E302
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x20
	ldr r2, _0818E2E4 @ =0x00000F2C
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818E2E8
	movs r0, #1
	b _0818E2EA
	.align 2, 0
_0818E2E4: .4byte 0x00000F2C
_0818E2E8:
	movs r0, #0
_0818E2EA:
	cmp r0, #0
	bne _0818E302
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _0818E308 @ =0x00000ED8
	adds r1, r1, r2
	ldrh r0, [r5]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_0818E302:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0818E308: .4byte 0x00000ED8

	thumb_func_start FUN_0818e30c
FUN_0818e30c: @ 0x0818E30C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818E31E
	b _0818E514
_0818E31E:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	movs r1, #0x20
	ldr r2, _0818E338 @ =0x00000F2C
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818E33C
	movs r0, #1
	b _0818E33E
	.align 2, 0
_0818E338: .4byte 0x00000F2C
_0818E33C:
	movs r0, #0
_0818E33E:
	adds r4, r0, #0
	cmp r4, #0
	beq _0818E346
	b _0818E514
_0818E346:
	ldr r3, _0818E3C4 @ =0x00000ED8
	adds r0, r7, r3
	ldrh r2, [r0]
	cmp r2, #0
	bne _0818E35C
	ldr r6, _0818E3C8 @ =0x0000048A
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _0818E35C
	b _0818E504
_0818E35C:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, r0, r2
	movs r3, #0
	strh r0, [r1]
	movs r2, #0
	ldrsh r6, [r1, r2]
	ldr r0, _0818E3C8 @ =0x0000048A
	adds r2, r5, r0
	ldrh r0, [r2]
	subs r0, r6, r0
	cmp r0, #0
	ble _0818E37C
	b _0818E4EC
_0818E37C:
	movs r6, #0x8b
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r4, [r0]
	adds r6, #5
	adds r0, r5, r6
	strb r3, [r0]
	ldr r6, _0818E3CC @ =0x0000048C
	adds r0, r5, r6
	strb r3, [r0]
	strh r4, [r2]
	ldr r2, _0818E3D0 @ =0x000004BE
	adds r0, r5, r2
	strh r4, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #0x20
	ldr r6, _0818E3D4 @ =0x00000F2C
	adds r0, r0, r6
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	movs r2, #4
	adds r1, r7, r6
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0818E3D8
	movs r0, #1
	b _0818E3DA
	.align 2, 0
_0818E3C4: .4byte 0x00000ED8
_0818E3C8: .4byte 0x0000048A
_0818E3CC: .4byte 0x0000048C
_0818E3D0: .4byte 0x000004BE
_0818E3D4: .4byte 0x00000F2C
_0818E3D8:
	movs r0, #0
_0818E3DA:
	cmp r0, #0
	bne _0818E4B8
	movs r1, #0x80
	lsls r1, r1, #6
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0818E3EE
	movs r0, #1
	b _0818E3F0
_0818E3EE:
	movs r0, #0
_0818E3F0:
	adds r4, r0, #0
	cmp r4, #0
	beq _0818E468
	ldr r2, _0818E454 @ =FUN_0818a47c
	movs r1, #0x2a
	ldr r3, _0818E458 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0818E45C @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818E460 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r2, _0818E464 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0818E4B8
	.align 2, 0
_0818E454: .4byte FUN_0818a47c
_0818E458: .4byte 0x0000046D
_0818E45C: .4byte 0x0000046B
_0818E460: .4byte 0x00000469
_0818E464: .4byte 0x0000046C
_0818E468:
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _0818E4D8 @ =0x0000046D
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _0818E4DC @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	movs r3, #0xd
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818E4E0 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _0818E4E4 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
_0818E4B8:
	ldrh r0, [r5]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	ldr r3, _0818E4E8 @ =0x0000025A
	adds r1, r5, r3
	ldrh r3, [r1]
	movs r1, #0
	str r1, [sp]
	bl FUN_0809c344
	bl FUN_080df478
	b _0818E504
	.align 2, 0
_0818E4D8: .4byte 0x0000046D
_0818E4DC: .4byte 0x0000046B
_0818E4E0: .4byte 0x0000046A
_0818E4E4: .4byte 0x00000484
_0818E4E8: .4byte 0x0000025A
_0818E4EC:
	ldrh r0, [r5]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	ldr r3, _0818E51C @ =0x0000025A
	adds r1, r5, r3
	ldrh r3, [r1]
	str r4, [sp]
	adds r1, r6, #0
	bl FUN_0809c344
_0818E504:
	ldr r6, _0818E520 @ =0x00000ED8
	adds r0, r7, r6
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0818E514:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818E51C: .4byte 0x0000025A
_0818E520: .4byte 0x00000ED8

	thumb_func_start FUN_0818e524
FUN_0818e524: @ 0x0818E524
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	cmp r1, #1
	beq _0818E558
	cmp r1, #1
	bgt _0818E540
	cmp r1, #0
	beq _0818E54A
	b _0818E5A0
_0818E540:
	cmp r1, #2
	beq _0818E574
	cmp r1, #3
	beq _0818E584
	b _0818E5A0
_0818E54A:
	ldr r1, _0818E554 @ =0x00000256
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r5, r0, #1
	b _0818E5A6
	.align 2, 0
_0818E554: .4byte 0x00000256
_0818E558:
	ldr r2, _0818E56C @ =0x00000256
	adds r1, r6, r2
	ldr r0, _0818E570 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldrh r1, [r1]
	adds r5, r0, r1
	b _0818E5A6
	.align 2, 0
_0818E56C: .4byte 0x00000256
_0818E570: .4byte 0x030046A4
_0818E574:
	ldr r1, _0818E580 @ =0x00000256
	adds r0, r6, r1
	ldrh r0, [r0]
	subs r5, r0, #1
	b _0818E5A6
	.align 2, 0
_0818E580: .4byte 0x00000256
_0818E584:
	ldr r2, _0818E598 @ =0x00000256
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r0, _0818E59C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r1, r0
	b _0818E5A6
	.align 2, 0
_0818E598: .4byte 0x00000256
_0818E59C: .4byte 0x030046A4
_0818E5A0:
	ldr r1, _0818E5D0 @ =0x00000256
	adds r0, r6, r1
	ldrh r5, [r0]
_0818E5A6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	ldr r2, _0818E5D0 @ =0x00000256
	adds r0, r6, r2
	ldrh r0, [r0]
	movs r1, #1
	bl FUN_08234224
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818E5D8
	adds r0, #4
	ldr r1, _0818E5D4 @ =0x030046A4
	mov r8, r1
	b _0818E5E6
	.align 2, 0
_0818E5D0: .4byte 0x00000256
_0818E5D4: .4byte 0x030046A4
_0818E5D8:
	ldr r2, _0818E628 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	mov r8, r2
_0818E5E6:
	ldrh r7, [r0, #2]
	mov sl, sp
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818E62C
	adds r0, #4
	b _0818E638
	.align 2, 0
_0818E628: .4byte 0x030046A4
_0818E62C:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818E638:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r2, sl
	strh r1, [r2, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r2, #4]
	mov r4, sp
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818E65E
	adds r0, #4
	b _0818E66A
_0818E65E:
	ldr r0, _0818E680 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818E66A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818E684
	cmp r2, #2
	beq _0818E688
	b _0818E68C
	.align 2, 0
_0818E680: .4byte 0x030046A4
_0818E684:
	ldrb r0, [r4, #4]
	b _0818E68A
_0818E688:
	ldrb r0, [r4]
_0818E68A:
	subs r1, r1, r0
_0818E68C:
	ldr r2, _0818E6B4 @ =0x00000472
	adds r0, r6, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	movs r0, #0x40
	ands r7, r0
	cmp r7, #0
	beq _0818E6AC
	cmp r1, #0
	beq _0818E6B8
	adds r0, r1, #0
	cmp r0, #0
	bge _0818E6A8
	rsbs r0, r0, #0
_0818E6A8:
	cmp r0, #0xfe
	ble _0818E6B8
_0818E6AC:
	movs r0, #1
	rsbs r0, r0, #0
	b _0818E6BA
	.align 2, 0
_0818E6B4: .4byte 0x00000472
_0818E6B8:
	adds r0, r5, #0
_0818E6BA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0818e6cc
FUN_0818e6cc: @ 0x0818E6CC
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0818E6F0
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _0818E6F4
_0818E6F0:
	str r1, [r3]
	movs r0, #0
_0818E6F4:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0818e6fc
FUN_0818e6fc: @ 0x0818E6FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	mov sl, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sl
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldr r0, _0818E750 @ =0x000004A4
	add r0, sl
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	mov r1, sl
	ldrb r0, [r1, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r3, r0, #6
	movs r1, #1
	rsbs r1, r1, #0
	add r0, sp, #0xc
_0818E72E:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _0818E72E
	movs r2, #0
	mov r8, r2
	movs r6, #1
	rsbs r6, r6, #0
	mov sb, r6
	ldr r1, [sp, #0x18]
	ldr r2, _0818E754 @ =0x00000F44
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne _0818E758
	adds r4, r3, #1
	b _0818E772
	.align 2, 0
_0818E750: .4byte 0x000004A4
_0818E754: .4byte 0x00000F44
_0818E758:
	cmp r0, #5
	bne _0818E784
	ldr r2, _0818E778 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818E77C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _0818E780 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r4, r3, r0
_0818E772:
	movs r0, #3
	ands r4, r0
	b _0818E786
	.align 2, 0
_0818E778: .4byte 0x030046B8
_0818E77C: .4byte 0x000003FF
_0818E780: .4byte 0x0203B400
_0818E784:
	adds r4, r3, #0
_0818E786:
	ldr r0, [sp, #0x18]
	ldr r1, _0818E7F4 @ =0x00000F44
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, #0x10
	bls _0818E7AE
	movs r0, #0xfe
	lsls r0, r0, #1
	add r0, sl
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, [sp, #0x18]
	ldr r6, _0818E7F8 @ =0x00000F45
	adds r1, r2, r6
	movs r2, #0
	strb r0, [r1]
	strb r2, [r5]
_0818E7AE:
	movs r6, #3
	movs r7, #3
	mov r1, r8
	lsls r0, r1, #2
	add r0, sp
	str r0, [sp, #0x38]
_0818E7BA:
	ldr r2, [sp, #0x18]
	ldr r1, _0818E7F8 @ =0x00000F45
	adds r0, r2, r1
	ldrb r0, [r0]
	subs r0, r4, r0
	cmp r0, #0
	bge _0818E7CA
	rsbs r0, r0, #0
_0818E7CA:
	cmp r0, #2
	beq _0818E806
	subs r0, r4, r3
	cmp r0, #0
	bge _0818E7D6
	rsbs r0, r0, #0
_0818E7D6:
	cmp r0, #2
	beq _0818E806
	mov r0, sl
	adds r1, r4, #0
	str r3, [sp, #0x3c]
	bl FUN_0818e524
	adds r5, r0, #0
	ldr r3, [sp, #0x3c]
	cmp r5, #0
	blt _0818E806
	cmp r4, r3
	bne _0818E7FC
	mov sb, r5
	b _0818E806
	.align 2, 0
_0818E7F4: .4byte 0x00000F44
_0818E7F8: .4byte 0x00000F45
_0818E7FC:
	ldr r2, [sp, #0x38]
	stm r2!, {r5}
	str r2, [sp, #0x38]
	movs r0, #1
	add r8, r0
_0818E806:
	adds r4, #1
	ands r4, r6
	subs r7, #1
	cmp r7, #0
	bge _0818E7BA
	mov r1, r8
	cmp r1, #0
	bne _0818E818
	b _0818E970
_0818E818:
	movs r7, #0
	ldr r4, [sp, #0x1c]
	adds r4, #0xc
	cmp r7, r8
	bge _0818E8BC
	mov r6, sp
_0818E824:
	ldr r1, [r6]
	mov r0, sl
	bl FUN_081920c4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818E8B4
	mov sb, r4
	ldr r5, [r6]
	ldr r7, _0818E870 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x1c]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818E874
	adds r0, #4
	b _0818E87E
	.align 2, 0
_0818E870: .4byte 0x030046A4
_0818E874:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818E87E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	mov r2, r8
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r1, [r6]
	mov r0, sl
	bl FUN_081920f4
	ldr r3, [sp, #0x18]
	ldr r6, _0818E8B0 @ =0x00000F44
	adds r1, r3, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r1, r3, r0
	b _0818EDF6
	.align 2, 0
_0818E8B0: .4byte 0x00000F44
_0818E8B4:
	adds r6, #4
	adds r7, #1
	cmp r7, r8
	blt _0818E824
_0818E8BC:
	ldr r2, _0818E91C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818E920 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0818E924 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	adds r7, r0, #0
	lsls r0, r7, #2
	add r0, sp
	mov sb, r4
	ldr r5, [r0]
	ldr r6, _0818E928 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x1c]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818E92C
	adds r0, #4
	b _0818E936
	.align 2, 0
_0818E91C: .4byte 0x030046B8
_0818E920: .4byte 0x000003FF
_0818E924: .4byte 0x0203B400
_0818E928: .4byte 0x030046A4
_0818E92C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818E936:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	mov r2, r8
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	lsls r0, r7, #2
	add r0, sp
	ldr r1, [r0]
	mov r0, sl
	bl FUN_081920f4
	ldr r3, [sp, #0x18]
	ldr r6, _0818E96C @ =0x00000F44
	adds r1, r3, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r1, r3, r0
	b _0818EDF6
	.align 2, 0
_0818E96C: .4byte 0x00000F44
_0818E970:
	movs r0, #1
	rsbs r0, r0, #0
	cmp sb, r0
	beq _0818EA04
	mov r0, sl
	mov r1, sb
	bl FUN_081920c4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818EA04
	ldr r7, [sp, #0x1c]
	adds r7, #0xc
	ldr r5, _0818E9C4 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	mov r0, sb
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	mov r0, sb
	bl Div
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x1c]
	strh r4, [r0, #0xc]
	mov r0, sb
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818E9C8
	adds r0, #4
	b _0818E9D4
	.align 2, 0
_0818E9C4: .4byte 0x030046A4
_0818E9C8:
	ldr r0, [r5]
	mov r2, sb
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818E9D4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	mov r0, sl
	mov r1, sb
	bl FUN_081920f4
	ldr r3, [sp, #0x18]
	ldr r6, _0818EA00 @ =0x00000F44
	adds r1, r3, r6
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r1, r3, r0
	b _0818EDF6
	.align 2, 0
_0818EA00: .4byte 0x00000F44
_0818EA04:
	ldr r1, [sp, #0x18]
	ldr r2, _0818EA20 @ =0x00000F45
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r0, #2
	movs r0, #3
	ands r6, r0
	cmp r6, #1
	beq _0818EA40
	cmp r6, #1
	bgt _0818EA24
	cmp r6, #0
	beq _0818EA2E
	b _0818EA90
	.align 2, 0
_0818EA20: .4byte 0x00000F45
_0818EA24:
	cmp r6, #2
	beq _0818EA60
	cmp r6, #3
	beq _0818EA70
	b _0818EA90
_0818EA2E:
	ldr r1, _0818EA3C @ =0x00000256
	add r1, sl
	ldrh r0, [r1]
	adds r7, r0, #1
	mov sb, r1
	b _0818EA98
	.align 2, 0
_0818EA3C: .4byte 0x00000256
_0818EA40:
	ldr r1, _0818EA58 @ =0x00000256
	add r1, sl
	ldr r0, _0818EA5C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r2, [r1]
	adds r7, r0, r2
	mov sb, r1
	b _0818EA98
	.align 2, 0
_0818EA58: .4byte 0x00000256
_0818EA5C: .4byte 0x030046A4
_0818EA60:
	ldr r1, _0818EA6C @ =0x00000256
	add r1, sl
	ldrh r0, [r1]
	subs r7, r0, #1
	mov sb, r1
	b _0818EA98
	.align 2, 0
_0818EA6C: .4byte 0x00000256
_0818EA70:
	ldr r1, _0818EA88 @ =0x00000256
	add r1, sl
	ldrh r2, [r1]
	ldr r0, _0818EA8C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	mov sb, r1
	b _0818EA98
	.align 2, 0
_0818EA88: .4byte 0x00000256
_0818EA8C: .4byte 0x030046A4
_0818EA90:
	ldr r0, _0818EAA8 @ =0x00000256
	add r0, sl
	ldrh r7, [r0]
	mov sb, r0
_0818EA98:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818EAAC
	adds r0, #4
	b _0818EAB8
	.align 2, 0
_0818EAA8: .4byte 0x00000256
_0818EAAC:
	ldr r0, _0818EAD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EAB8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x20]
	mov r0, sb
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818EAD8
	adds r0, #4
	b _0818EAE4
	.align 2, 0
_0818EAD4: .4byte 0x030046A4
_0818EAD8:
	ldr r0, _0818EAFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EAE4:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x24]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818EB00
	adds r0, #4
	b _0818EB0C
	.align 2, 0
_0818EAFC: .4byte 0x030046A4
_0818EB00:
	ldr r0, _0818EB50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EB0C:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x28]
	add r5, sp, #0x10
	ldr r1, _0818EB50 @ =0x030046A4
	mov r8, r1
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	str r0, [sp, #0x2c]
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818EB54
	adds r0, #4
	b _0818EB60
	.align 2, 0
_0818EB50: .4byte 0x030046A4
_0818EB54:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818EB60:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r5, #2]
	ldr r1, [sp, #0x2c]
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	add r4, sp, #0x10
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818EB84
	adds r0, #4
	b _0818EB90
_0818EB84:
	ldr r2, _0818EBA4 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EB90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818EBA8
	cmp r2, #2
	beq _0818EBAC
	b _0818EBB0
	.align 2, 0
_0818EBA4: .4byte 0x030046A4
_0818EBA8:
	ldrb r0, [r4, #4]
	b _0818EBAE
_0818EBAC:
	ldrb r0, [r4]
_0818EBAE:
	subs r1, r1, r0
_0818EBB0:
	str r1, [sp, #0x30]
	mov r2, sb
	ldrh r5, [r2]
	mov r3, sp
	adds r3, #0x10
	str r3, [sp, #0x34]
	ldr r1, _0818EBF8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _0818EBF8 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x10
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818EBFC
	adds r0, #4
	b _0818EC08
	.align 2, 0
_0818EBF8: .4byte 0x030046A4
_0818EBFC:
	ldr r3, _0818EC34 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818EC08:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	ldr r0, [sp, #0x34]
	strh r1, [r0, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	ldr r2, [sp, #0x34]
	strh r0, [r2, #4]
	mov r3, sb
	ldrh r4, [r3]
	add r5, sp, #0x10
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818EC38
	adds r0, #4
	b _0818EC44
	.align 2, 0
_0818EC34: .4byte 0x030046A4
_0818EC38:
	ldr r0, _0818EC58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818EC44:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818EC5C
	cmp r2, #2
	beq _0818EC60
	b _0818EC64
	.align 2, 0
_0818EC58: .4byte 0x030046A4
_0818EC5C:
	ldrb r0, [r5, #4]
	b _0818EC62
_0818EC60:
	ldrb r0, [r5]
_0818EC62:
	subs r1, r1, r0
_0818EC64:
	ldr r0, [sp, #0x30]
	subs r2, r0, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	ldr r1, [sp, #0x30]
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r3, [sp, #0x28]
	ands r3, r0
	cmp r3, #0
	beq _0818EC84
	b _0818EE00
_0818EC84:
	cmp r2, #0
	beq _0818ED76
	ldr r0, [sp, #0x20]
	cmp r0, #1
	bne _0818ECA8
	cmp r6, #1
	bne _0818EC9E
	ldr r3, [sp, #0x24]
	cmp r3, #1
	bne _0818ECBE
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ECCE
_0818EC9E:
	cmp r6, #3
	beq _0818ECA4
	b _0818EE00
_0818ECA4:
	ldr r0, [sp, #0x24]
	b _0818ECCC
_0818ECA8:
	ldr r3, [sp, #0x20]
	cmp r3, #2
	bne _0818ECD4
	cmp r6, #0
	bne _0818ECC4
	ldr r0, [sp, #0x24]
	cmp r0, #2
	bne _0818ECBE
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ECCE
_0818ECBE:
	cmp r1, #0
	beq _0818ECD4
	b _0818EE00
_0818ECC4:
	cmp r6, #2
	beq _0818ECCA
	b _0818EE00
_0818ECCA:
	ldr r3, [sp, #0x24]
_0818ECCC:
	ldr r0, _0818ECEC @ =0xFFFFFF00
_0818ECCE:
	cmp r1, r0
	beq _0818ECD4
	b _0818EE00
_0818ECD4:
	ldr r0, [sp, #0x24]
	cmp r0, #1
	bne _0818ED04
	cmp r6, #1
	bne _0818ECF6
	ldr r3, [sp, #0x20]
	cmp r3, #1
	bne _0818ECF0
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ED2C
	.align 2, 0
_0818ECEC: .4byte 0xFFFFFF00
_0818ECF0:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ED2C
_0818ECF6:
	cmp r6, #3
	beq _0818ECFC
	b _0818EE00
_0818ECFC:
	ldr r6, [sp, #0x20]
	cmp r6, #1
	beq _0818ED2A
	b _0818ED38
_0818ED04:
	ldr r0, [sp, #0x24]
	cmp r0, #2
	bne _0818ED48
	cmp r6, #0
	bne _0818ED20
	ldr r3, [sp, #0x20]
	cmp r3, #2
	bne _0818ED1A
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ED2C
_0818ED1A:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0818ED2C
_0818ED20:
	cmp r6, #2
	bne _0818EE00
	ldr r6, [sp, #0x20]
	cmp r6, #2
	bne _0818ED38
_0818ED2A:
	ldr r0, _0818ED34 @ =0xFFFFFF00
_0818ED2C:
	cmp r1, r0
	beq _0818ED3C
	b _0818EE00
	.align 2, 0
_0818ED34: .4byte 0xFFFFFF00
_0818ED38:
	cmp r1, #0
	bne _0818EE00
_0818ED3C:
	ldr r0, [sp, #0x24]
	cmp r0, #2
	bne _0818ED48
	ldr r1, [sp, #0x20]
	cmp r1, #2
	beq _0818ED54
_0818ED48:
	ldr r3, [sp, #0x24]
	cmp r3, #1
	bne _0818ED66
	ldr r6, [sp, #0x20]
	cmp r6, #1
	bne _0818ED66
_0818ED54:
	adds r1, r2, #0
	cmp r2, #0
	bge _0818ED5C
	rsbs r1, r2, #0
_0818ED5C:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _0818ED76
	b _0818EE00
_0818ED66:
	adds r0, r2, #0
	cmp r0, #0
	bge _0818ED6E
	rsbs r0, r0, #0
_0818ED6E:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _0818ED78
_0818ED76:
	adds r5, r7, #0
_0818ED78:
	cmp r5, #0
	blt _0818EE00
	ldr r0, [sp, #0x1c]
	adds r0, #0xc
	mov r8, r0
	ldr r6, _0818EDBC @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x1c]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818EDC0
	adds r0, #4
	b _0818EDCA
	.align 2, 0
_0818EDBC: .4byte 0x030046A4
_0818EDC0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818EDCA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	mov r0, sl
	adds r1, r5, #0
	bl FUN_081920f4
	ldr r2, [sp, #0x18]
	ldr r3, _0818EDFC @ =0x00000F44
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	movs r6, #0xf4
	lsls r6, r6, #4
	adds r1, r2, r6
_0818EDF6:
	movs r0, #0x28
	strh r0, [r1]
	b _0818EE10
	.align 2, 0
_0818EDFC: .4byte 0x00000F44
_0818EE00:
	ldr r1, [sp, #0x18]
	ldr r2, _0818EE20 @ =0x00000F45
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #3
	ands r1, r2
	strb r1, [r0]
_0818EE10:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818EE20: .4byte 0x00000F45

	thumb_func_start FUN_0818ee24
FUN_0818ee24: @ 0x0818EE24
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r0, _0818EE40 @ =0x00000F2F
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818EE44
	subs r0, #1
	strb r0, [r1]
	b _0818EE88
	.align 2, 0
_0818EE40: .4byte 0x00000F2F
_0818EE44:
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _0818EE90 @ =0x00000F36
	adds r4, r5, r1
	movs r0, #0
	ldrsh r1, [r4, r0]
	subs r1, #1
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r5
	ldr r0, _0818EE94 @ =0x00000674
	adds r2, r2, r0
	adds r0, r5, #0
	bl FUN_0818f844
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	ldr r0, _0818EE94 @ =0x00000674
	adds r2, r5, r0
	adds r0, r5, #0
	bl FUN_0818f844
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0818f844
_0818EE88:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0818EE90: .4byte 0x00000F36
_0818EE94: .4byte 0x00000674

	thumb_func_start FUN_0818ee98
FUN_0818ee98: @ 0x0818EE98
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818EF74 @ =0x00000F36
	adds r4, r6, r2
	movs r0, #6
	strh r0, [r4]
	movs r1, #6
	adds r2, #0x10
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0818EF78 @ =0x00000F48
	adds r1, r6, r0
	ldr r0, _0818EF7C @ =0x7FFFFFFF
	str r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r1, #1
	bl Div
	ldr r2, _0818EF80 @ =0x00000F47
	adds r1, r6, r2
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r7, #0
	movs r1, #0
	mov sb, r1
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp sb, r0
	bge _0818EFF2
	mov sl, r1
	movs r0, #0xe8
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r1, _0818EF84 @ =0x00000684
	adds r5, r6, r1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r6
	mov r8, r2
_0818EF0C:
	adds r0, r5, #0
	ldr r1, [sp, #0xc]
	bl Video_GetActorSprite
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _0818EF88 @ =0x000001A3
	bl FUN_0822b20c
	mov r0, sp
	ldrb r0, [r0, #0x14]
	strb r0, [r4, #0x14]
	ldr r2, [sp, #0x10]
	lsls r1, r2, #0x10
	ldr r0, _0818EF8C @ =0x0000922E
	lsrs r1, r1, #0x10
	bl GetFile
	str r0, [r4, #0x10]
	ldrb r0, [r4, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_0818e6cc
	ldr r1, _0818EF74 @ =0x00000F36
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp sb, r0
	bne _0818EF90
	ldr r1, [r4, #0x10]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0xb
	bl FUN_08236fac
	movs r0, #4
	ldrh r1, [r4, #0x3a]
	orrs r0, r1
	strh r0, [r4, #0x3a]
	b _0818EFB2
	.align 2, 0
_0818EF74: .4byte 0x00000F36
_0818EF78: .4byte 0x00000F48
_0818EF7C: .4byte 0x7FFFFFFF
_0818EF80: .4byte 0x00000F47
_0818EF84: .4byte 0x00000684
_0818EF88: .4byte 0x000001A3
_0818EF8C: .4byte 0x0000922E
_0818EF90:
	ldr r1, [r4, #0x10]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08236fac
	strh r7, [r4, #8]
	adds r7, #1
	cmp r7, #3
	ble _0818EFB2
	movs r7, #0
_0818EFB2:
	str r6, [r4, #0x34]
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x38]
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _0818EFCE
	mov r1, sl
	strb r1, [r4, #0x1a]
	movs r0, #2
	ldrh r1, [r4, #0x3a]
	orrs r0, r1
	strh r0, [r4, #0x3a]
	b _0818EFD4
_0818EFCE:
	ldr r2, [sp, #0x18]
	adds r2, #1
	str r2, [sp, #0x18]
_0818EFD4:
	movs r0, #0x18
	add sl, r0
	movs r1, #0x92
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r5, r5, r1
	add r8, r1
	movs r2, #1
	add sb, r2
	ldr r1, _0818F004 @ =0x00000F36
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _0818EF0C
_0818EFF2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F004: .4byte 0x00000F36

	thumb_func_start FUN_0818f008
FUN_0818f008: @ 0x0818F008
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0
	str r1, [sp]
	ldr r2, _0818F04C @ =0x00000F36
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _0818F02C
	b _0818F148
_0818F02C:
	movs r2, #0
	mov sl, r2
	ldr r0, _0818F050 @ =0x00000674
	adds r6, r7, r0
	ldr r1, _0818F054 @ =0x0000077A
	adds r1, r1, r7
	mov sb, r1
_0818F03A:
	movs r1, #1
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0818F058
	movs r0, #1
	b _0818F05A
	.align 2, 0
_0818F04C: .4byte 0x00000F36
_0818F050: .4byte 0x00000674
_0818F054: .4byte 0x0000077A
_0818F058:
	movs r0, #0
_0818F05A:
	cmp r0, #0
	bne _0818F128
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0818F082
	cmp r1, #0
	blt _0818F082
	ldr r0, _0818F088 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0818F082
	ldr r0, _0818F08C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818F090
_0818F082:
	movs r4, #0
	b _0818F09E
	.align 2, 0
_0818F088: .4byte 0x030046A8
_0818F08C: .4byte 0x030046AC
_0818F090:
	ldr r0, _0818F0B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0818F09E:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0818F0B4
	adds r0, #4
	b _0818F0C0
	.align 2, 0
_0818F0B0: .4byte 0x030046A4
_0818F0B4:
	ldr r0, _0818F0D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818F0C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818F0D8
	cmp r2, #2
	beq _0818F0DC
	b _0818F0E0
	.align 2, 0
_0818F0D4: .4byte 0x030046A4
_0818F0D8:
	ldrb r0, [r5, #4]
	b _0818F0DE
_0818F0DC:
	ldrb r0, [r5]
_0818F0DE:
	subs r1, r1, r0
_0818F0E0:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bge _0818F108
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r1, sl
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	bne _0818F102
	orrs r1, r3
	str r1, [r2]
_0818F102:
	movs r2, #1
	rsbs r2, r2, #0
	b _0818F126
_0818F108:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r1, sl
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0818F124
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_0818F124:
	movs r2, #1
_0818F126:
	add r8, r2
_0818F128:
	movs r0, #0x92
	lsls r0, r0, #1
	add sl, r0
	adds r6, r6, r0
	add sb, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	ldr r2, _0818F158 @ =0x00000F36
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp]
	cmp r2, r0
	bge _0818F148
	b _0818F03A
_0818F148:
	ldr r1, _0818F158 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _0818F15C
	movs r0, #1
	b _0818F16A
	.align 2, 0
_0818F158: .4byte 0x00000F36
_0818F15C:
	mov r1, r8
	cmn r1, r0
	ble _0818F166
	movs r0, #0
	b _0818F16A
_0818F166:
	movs r0, #1
	rsbs r0, r0, #0
_0818F16A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0818f17c
FUN_0818f17c: @ 0x0818F17C
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, _0818F1BC @ =0x00000F36
	adds r1, r2, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r3, r0
	bge _0818F1DE
	movs r5, #1
	adds r6, r1, #0
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r7, _0818F1C0 @ =0x0000077A
	adds r1, r0, r7
	adds r1, r1, r2
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r2, r0, r2
	movs r4, #0x92
	lsls r4, r4, #1
_0818F1AE:
	ldrh r0, [r1]
	ands r0, r5
	cmp r0, #0
	beq _0818F1C4
	movs r0, #1
	b _0818F1C6
	.align 2, 0
_0818F1BC: .4byte 0x00000F36
_0818F1C0: .4byte 0x0000077A
_0818F1C4:
	movs r0, #0
_0818F1C6:
	cmp r0, #0
	bne _0818F1D0
	ldr r0, [r2]
	orrs r0, r5
	str r0, [r2]
_0818F1D0:
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _0818F1AE
_0818F1DE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0818f1e4
FUN_0818f1e4: @ 0x0818F1E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, _0818F228 @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x10]
	cmp r2, r0
	blt _0818F208
	b _0818F396
_0818F208:
	movs r3, #0
	mov sl, r3
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
_0818F21A:
	ldrh r0, [r7, #0x3a]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0818F22C
	movs r0, #1
	b _0818F22E
	.align 2, 0
_0818F228: .4byte 0x00000F36
_0818F22C:
	movs r0, #0
_0818F22E:
	cmp r0, #0
	beq _0818F234
	b _0818F378
_0818F234:
	ldrb r0, [r7, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_0818e6cc
	ldrh r0, [r7, #0x3a]
	movs r2, #4
	ands r0, r2
	cmp r0, #0
	beq _0818F24C
	movs r0, #1
	b _0818F24E
_0818F24C:
	movs r0, #0
_0818F24E:
	cmp r0, #0
	beq _0818F274
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #0xb
	bl FUN_08236fac
	b _0818F2A0
_0818F274:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #0xc]
	lsls r0, r3, #2
	add r0, sb
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	bl FUN_08236fac
_0818F2A0:
	mov r6, r8
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0818F2D2
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	str r0, [r6]
	b _0818F2DE
_0818F2D2:
	mov r2, r8
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_0818F2DE:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0818F300
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0818F308
_0818F300:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0818F308:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0818F340 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0818F378
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0818F344
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0818F338
	ldrb r0, [r4, #5]
_0818F338:
	subs r0, #1
	strh r0, [r4, #8]
	b _0818F354
	.align 2, 0
_0818F340: .4byte 0x0000FFFF
_0818F344:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0818F354
	strh r1, [r4, #8]
_0818F354:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818F378
	movs r3, #1
	strb r3, [r4, #7]
_0818F378:
	movs r0, #0x92
	lsls r0, r0, #1
	add sl, r0
	adds r7, r7, r0
	add r8, r0
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r0, _0818F3A8 @ =0x00000F36
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _0818F396
	b _0818F21A
_0818F396:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F3A8: .4byte 0x00000F36

	thumb_func_start FUN_0818f3ac
FUN_0818f3ac: @ 0x0818F3AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, _0818F3F0 @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x10]
	cmp r2, r0
	blt _0818F3D0
	b _0818F55E
_0818F3D0:
	movs r3, #0
	mov sl, r3
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
_0818F3E2:
	ldrh r0, [r7, #0x3a]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0818F3F4
	movs r0, #1
	b _0818F3F6
	.align 2, 0
_0818F3F0: .4byte 0x00000F36
_0818F3F4:
	movs r0, #0
_0818F3F6:
	cmp r0, #0
	beq _0818F3FC
	b _0818F540
_0818F3FC:
	ldrb r0, [r7, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_0818e6cc
	ldrh r0, [r7, #0x3a]
	movs r2, #4
	ands r0, r2
	cmp r0, #0
	beq _0818F414
	movs r0, #1
	b _0818F416
_0818F414:
	movs r0, #0
_0818F416:
	cmp r0, #0
	beq _0818F43C
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #0xb
	bl FUN_08236fac
	b _0818F468
_0818F43C:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #0xc]
	lsls r0, r3, #2
	add r0, sb
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	bl FUN_08236fac
_0818F468:
	mov r6, r8
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0818F49A
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	str r0, [r6]
	b _0818F4A6
_0818F49A:
	mov r2, r8
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_0818F4A6:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0818F4C8
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0818F4D0
_0818F4C8:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0818F4D0:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0818F508 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0818F540
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0818F50C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0818F500
	ldrb r0, [r4, #5]
_0818F500:
	subs r0, #1
	strh r0, [r4, #8]
	b _0818F51C
	.align 2, 0
_0818F508: .4byte 0x0000FFFF
_0818F50C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0818F51C
	strh r1, [r4, #8]
_0818F51C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818F540
	movs r3, #1
	strb r3, [r4, #7]
_0818F540:
	movs r0, #0x92
	lsls r0, r0, #1
	add sl, r0
	adds r7, r7, r0
	add r8, r0
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r0, _0818F570 @ =0x00000F36
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _0818F55E
	b _0818F3E2
_0818F55E:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F570: .4byte 0x00000F36

	thumb_func_start FUN_0818f574
FUN_0818f574: @ 0x0818F574
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r6, #0
	ldr r2, _0818F5B4 @ =0x00000F36
	adds r0, r7, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0818F5E4
	movs r0, #1
	mov sb, r0
	adds r5, r1, #0
	ldr r1, _0818F5B8 @ =0x0000077A
	adds r4, r7, r1
_0818F5A4:
	ldrh r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0818F5BC
	movs r0, #1
	b _0818F5BE
	.align 2, 0
_0818F5B4: .4byte 0x00000F36
_0818F5B8: .4byte 0x0000077A
_0818F5BC:
	movs r0, #0
_0818F5BE:
	cmp r0, #0
	bne _0818F5CE
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
_0818F5CE:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	ldr r1, _0818F5F0 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _0818F5A4
_0818F5E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F5F0: .4byte 0x00000F36

	thumb_func_start FUN_0818f5f4
FUN_0818f5f4: @ 0x0818F5F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r0, _0818F640 @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r3, [sp, #0xc]
	cmp r3, r0
	blt _0818F61A
	b _0818F7A0
_0818F61A:
	movs r4, #0
	mov sl, r4
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
	lsls r2, r2, #0x18
	str r2, [sp, #0x10]
_0818F630:
	ldrh r0, [r7, #0x3a]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0818F644
	movs r0, #1
	b _0818F646
	.align 2, 0
_0818F640: .4byte 0x00000F36
_0818F644:
	movs r0, #0
_0818F646:
	cmp r0, #0
	beq _0818F64C
	b _0818F780
_0818F64C:
	ldrh r0, [r7, #0x3a]
	movs r2, #4
	ands r0, r2
	cmp r0, #0
	beq _0818F65A
	movs r0, #1
	b _0818F65C
_0818F65A:
	movs r0, #0
_0818F65C:
	cmp r0, #0
	beq _0818F680
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #8]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #0xb
	ldr r4, [sp, #0x10]
	lsrs r3, r4, #0x18
	bl FUN_08237040
	b _0818F6AA
_0818F680:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	add r0, sb
	movs r3, #0x98
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r2, [r0]
	ldr r4, [sp, #8]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	ldr r4, [sp, #0x10]
	lsrs r3, r4, #0x18
	bl FUN_08237040
_0818F6AA:
	mov r6, r8
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _0818F6DC
	ldr r0, [r6]
	movs r2, #4
	orrs r0, r2
	str r0, [r6]
	b _0818F6E8
_0818F6DC:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_0818F6E8:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0818F70A
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0818F712
_0818F70A:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0818F712:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0818F748 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0818F780
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0818F74C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0818F742
	ldrb r0, [r4, #5]
_0818F742:
	subs r0, #1
	strh r0, [r4, #8]
	b _0818F75C
	.align 2, 0
_0818F748: .4byte 0x0000FFFF
_0818F74C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0818F75C
	strh r1, [r4, #8]
_0818F75C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818F780
	movs r3, #1
	strb r3, [r4, #7]
_0818F780:
	movs r4, #0x92
	lsls r4, r4, #1
	add sl, r4
	adds r7, r7, r4
	add r8, r4
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	ldr r0, _0818F7B0 @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0xc]
	cmp r2, r0
	bge _0818F7A0
	b _0818F630
_0818F7A0:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F7B0: .4byte 0x00000F36

	thumb_func_start FUN_0818f7b4
FUN_0818f7b4: @ 0x0818F7B4
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _0818F7E4 @ =0x00000F36
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _0818F802
	movs r5, #1
	adds r6, r2, #0
	ldr r7, _0818F7E8 @ =0x0000077A
	adds r2, r1, r7
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r4, #0x92
	lsls r4, r4, #1
_0818F7D8:
	ldrh r0, [r2]
	ands r0, r5
	cmp r0, #0
	beq _0818F7EC
	movs r0, #1
	b _0818F7EE
	.align 2, 0
_0818F7E4: .4byte 0x00000F36
_0818F7E8: .4byte 0x0000077A
_0818F7EC:
	movs r0, #0
_0818F7EE:
	cmp r0, #0
	beq _0818F7F4
	str r5, [r1]
_0818F7F4:
	adds r2, r2, r4
	adds r1, r1, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _0818F7D8
_0818F802:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0818f808
FUN_0818f808: @ 0x0818F808
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r1, _0818F840 @ =0x00000F36
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _0818F83A
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r4, r6, r0
_0818F820:
	adds r0, r4, #0
	bl FUN_0822a4e0
	movs r1, #0x92
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r5, #1
	ldr r1, _0818F840 @ =0x00000F36
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0818F820
_0818F83A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0818F840: .4byte 0x00000F36

	thumb_func_start FUN_0818f844
FUN_0818f844: @ 0x0818F844
	lsls r3, r1, #3
	adds r3, r3, r1
	lsls r3, r3, #3
	adds r3, r3, r1
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, _0818F860 @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0]
	str r2, [r0, #4]
	bx lr
	.align 2, 0
_0818F860: .4byte 0x00000674

	thumb_func_start FUN_0818f864
FUN_0818f864: @ 0x0818F864
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r2, #0
	ldr r7, _0818F8A8 @ =0x00000F36
	adds r0, r3, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge _0818F908
	mov r5, sp
	add r7, sp, #8
	mov r8, r7
	ldr r0, _0818F8AC @ =0x00000674
	adds r4, r3, r0
	ldr r1, _0818F8B0 @ =0x00000754
	adds r6, r3, r1
_0818F898:
	movs r1, #1
	ldrh r0, [r6, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _0818F8B4
	movs r0, #1
	b _0818F8B6
	.align 2, 0
_0818F8A8: .4byte 0x00000F36
_0818F8AC: .4byte 0x00000674
_0818F8B0: .4byte 0x00000754
_0818F8B4:
	movs r0, #0
_0818F8B6:
	cmp r0, #0
	bne _0818F8F2
	mov r7, r8
	ldrh r0, [r7]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r7, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r7, #4
	ldrsh r1, [r5, r7]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	bl FUN_0823785c
	strb r0, [r6]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r3, [sp, #0x14]
	ldr r2, [sp, #0x10]
_0818F8F2:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r6, r6, r0
	adds r2, #1
	ldr r1, _0818F914 @ =0x00000F36
	adds r0, r3, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r2, r0
	blt _0818F898
_0818F908:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F914: .4byte 0x00000F36

	thumb_func_start FUN_0818f918
FUN_0818f918: @ 0x0818F918
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _0818F934 @ =0x00000F34
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	movs r0, #0xf3
	lsls r0, r0, #4
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0818F934: .4byte 0x00000F34

	thumb_func_start FUN_0818f938
FUN_0818f938: @ 0x0818F938
	push {r4, r5, lr}
	adds r4, r2, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _0818F95C @ =0x00000F34
	adds r0, r2, r3
	movs r5, #0
	ldrsh r3, [r0, r5]
	cmp r3, r1
	blt _0818F960
	strh r1, [r0]
	movs r0, #0xf3
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r0, #0xff
	b _0818F970
	.align 2, 0
_0818F95C: .4byte 0x00000F34
_0818F960:
	rsbs r1, r1, #0
	cmp r3, r1
	bgt _0818F972
	strh r1, [r0]
	movs r3, #0xf3
	lsls r3, r3, #4
	adds r1, r2, r3
	movs r0, #1
_0818F970:
	strb r0, [r1]
_0818F972:
	ldr r5, _0818F990 @ =0x00000F34
	adds r1, r2, r5
	movs r3, #0xf3
	lsls r3, r3, #4
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r4, r0
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0818F990: .4byte 0x00000F34

	thumb_func_start FUN_0818f994
FUN_0818f994: @ 0x0818F994
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0818F9A8 @ =0x00000ECC
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_0818F9A8: .4byte 0x00000ECC

	thumb_func_start FUN_0818f9ac
FUN_0818f9ac: @ 0x0818F9AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldr r2, _0818FA0C @ =0x00000ECC
	adds r1, r7, r2
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0818FA5C
	ldr r0, [r4, #0x44]
	ldr r5, [r0, #0x1c]
	ldr r6, [r0, #0x20]
	movs r0, #0
	mov ip, r0
	ldr r2, _0818FA10 @ =0x00000F36
	adds r1, r7, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp ip, r0
	bge _0818FA5C
	movs r0, #2
	mov sl, r0
	movs r2, #1
	mov sb, r2
	mov r8, r1
	adds r3, r7, #0
	ldr r7, _0818FA14 @ =0x0000077A
	adds r4, r3, r7
_0818F9FC:
	ldrh r0, [r4]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _0818FA18
	movs r0, #1
	b _0818FA1A
	.align 2, 0
_0818FA0C: .4byte 0x00000ECC
_0818FA10: .4byte 0x00000F36
_0818FA14: .4byte 0x0000077A
_0818FA18:
	movs r0, #0
_0818FA1A:
	cmp r0, #0
	beq _0818FA46
	ldrh r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0818FA2C
	movs r0, #1
	b _0818FA2E
_0818FA2C:
	movs r0, #0
_0818FA2E:
	cmp r0, #0
	bne _0818FA46
	ldr r7, _0818FA6C @ =0x00000674
	adds r0, r3, r7
	ldr r1, [r0]
	ldr r2, [r0, #4]
	adds r7, #0xf0
	adds r0, r3, r7
	str r5, [r0]
	str r6, [r0, #4]
	adds r6, r2, #0
	adds r5, r1, #0
_0818FA46:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r3, r3, r0
	adds r4, r4, r0
	movs r1, #1
	add ip, r1
	mov r2, r8
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp ip, r0
	blt _0818F9FC
_0818FA5C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818FA6C: .4byte 0x00000674

	thumb_func_start FUN_0818fa70
FUN_0818fa70: @ 0x0818FA70
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r3, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #2
	ldr r2, _0818FA9C @ =0x0000077A
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818FAA0
	movs r0, #1
	b _0818FAA2
	.align 2, 0
_0818FA9C: .4byte 0x0000077A
_0818FAA0:
	movs r0, #0
_0818FAA2:
	cmp r0, #0
	beq _0818FAE4
	lsls r2, r3, #3
	adds r0, r2, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #1
	ldr r6, _0818FAC4 @ =0x0000077A
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818FAC8
	movs r0, #1
	b _0818FACA
	.align 2, 0
_0818FAC4: .4byte 0x0000077A
_0818FAC8:
	movs r0, #0
_0818FACA:
	cmp r0, #0
	bne _0818FAE4
	adds r0, r2, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r1, _0818FAEC @ =0x0000076C
	adds r0, r0, r1
	ldr r1, [r5]
	ldr r2, [r5, #4]
	str r1, [r0]
	str r2, [r0, #4]
_0818FAE4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0818FAEC: .4byte 0x0000076C

	thumb_func_start FUN_0818faf0
FUN_0818faf0: @ 0x0818FAF0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r1, #0
	str r2, [sp]
	mov sl, r3
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r0, #0
	mov ip, r0
	ldr r1, _0818FB44 @ =0x00000F36
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _0818FB1C
	b _0818FC18
_0818FB1C:
	ldr r0, _0818FB48 @ =0x085B0A08
	mov sb, r0
	adds r4, r5, #0
	movs r6, #0
	ldr r1, _0818FB4C @ =0x0000075A
	adds r3, r5, r1
	movs r0, #0x92
	lsls r0, r0, #1
	mov r8, r0
_0818FB2E:
	adds r0, r6, r5
	ldr r1, _0818FB50 @ =0x0000077A
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0818FB54
	movs r0, #1
	b _0818FB56
	.align 2, 0
_0818FB44: .4byte 0x00000F36
_0818FB48: .4byte 0x085B0A08
_0818FB4C: .4byte 0x0000075A
_0818FB50: .4byte 0x0000077A
_0818FB54:
	movs r0, #0
_0818FB56:
	cmp r0, #0
	beq _0818FC02
	adds r0, r6, r5
	ldr r1, _0818FB70 @ =0x0000077A
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0818FB74
	movs r0, #1
	b _0818FB76
	.align 2, 0
_0818FB70: .4byte 0x0000077A
_0818FB74:
	movs r0, #0
_0818FB76:
	cmp r0, #0
	bne _0818FC02
	mov r0, sl
	cmp r0, #0
	bne _0818FBA4
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818FB94
	asrs r2, r0, #0xc
	b _0818FB9A
_0818FB94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818FB9A:
	ldr r0, _0818FBA0 @ =0x0000076E
	b _0818FBF2
	.align 2, 0
_0818FBA0: .4byte 0x0000076E
_0818FBA4:
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818FBBE
	asrs r2, r0, #0xc
	b _0818FBC4
_0818FBBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818FBC4:
	ldr r0, _0818FBE4 @ =0x0000076C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818FBE8
	asrs r2, r0, #0xc
	b _0818FBEE
	.align 2, 0
_0818FBE4: .4byte 0x0000076C
_0818FBE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818FBEE:
	movs r0, #0xee
	lsls r0, r0, #3
_0818FBF2:
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	ldr r1, [sp]
	adds r0, r0, r1
	strb r0, [r3]
_0818FC02:
	add r4, r8
	add r6, r8
	add r3, r8
	movs r0, #1
	add ip, r0
	ldr r1, _0818FC28 @ =0x00000F36
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	blt _0818FB2E
_0818FC18:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818FC28: .4byte 0x00000F36

	thumb_func_start FUN_0818fc2c
FUN_0818fc2c: @ 0x0818FC2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r4, r3, #0
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	subs r1, r4, #1
	ldr r7, [sp, #0x68]
	subs r1, r7, r1
	bl Div
	str r0, [sp, #0x30]
	movs r0, #0
	mov sl, r4
	cmp sl, r7
	blt _0818FC6E
	b _0818FDC8
_0818FC6E:
	mov r1, sp
	adds r1, #4
	str r1, [sp, #0x34]
	add r2, sp, #0xc
	mov sb, r2
	mov r3, sp
	adds r3, #0x14
	str r3, [sp, #0x38]
	add r4, sp, #0x1c
	mov r8, r4
	mov r7, sp
	adds r7, #0x24
	str r7, [sp, #0x40]
_0818FC88:
	adds r4, r0, #1
	ldr r0, [sp, #0x30]
	adds r5, r0, #0
	muls r5, r4, r5
	ldr r1, [sp, #0x38]
	ldrh r0, [r1]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3]
	ldr r7, [sp, #0x38]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	add r1, sp, #0x24
	ldr r2, _0818FCCC @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	str r4, [sp, #0x3c]
	cmp r0, #0
	blt _0818FCD0
	asrs r0, r0, #0xa
	b _0818FCD6
	.align 2, 0
_0818FCCC: .4byte 0x05000002
_0818FCD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0818FCD6:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _0818FCE4
	asrs r1, r0, #0xa
	b _0818FCEA
_0818FCE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0818FCEA:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	movs r4, #0
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	mov ip, r1
	subs r0, r2, r6
	adds r0, #1
	ldr r7, [sp, #0x40]
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	adds r7, r4, #0
	adds r4, r0, #0
	muls r4, r7, r4
	subs r1, r6, r2
	mov r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _0818FD28
	asrs r1, r0, #0xa
	b _0818FD2E
_0818FD28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0818FD2E:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	ldr r4, [sp, #0x34]
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	ldr r7, [sp, #0x40]
	movs r4, #2
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x44]
	mov r1, r8
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x44]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _0818FD68
	asrs r1, r0, #0xa
	b _0818FD6E
_0818FD68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0818FD6E:
	mov r4, sb
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #2]
	adds r1, r3, #1
	ldr r3, [sp, #0x40]
	movs r4, #4
	ldrsh r0, [r3, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	adds r1, r2, r6
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _0818FDA0
	asrs r1, r0, #0xa
	b _0818FDA6
_0818FDA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0818FDA6:
	mov r4, sb
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #4]
	ldr r0, [sp, #0x2c]
	mov r1, sl
	ldr r2, [sp, #0x34]
	bl FUN_0818f844
	ldr r0, [sp, #0x3c]
	movs r1, #1
	add sl, r1
	ldr r2, [sp, #0x68]
	cmp sl, r2
	bge _0818FDC8
	b _0818FC88
_0818FDC8:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0818fdd8
FUN_0818fdd8: @ 0x0818FDD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	str r0, [sp, #0x20]
	mov r8, r1
	mov sl, r2
	str r3, [sp, #0x24]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	ldr r2, _0818FE30 @ =0x00000ECA
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0818FE00
	b _0818FF0A
_0818FE00:
	ldr r3, [sp, #0x20]
	ldr r0, [r3, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r4, #0
	mov sb, r4
	ldr r1, _0818FE34 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	bge _0818FF0A
	ldr r3, _0818FE38 @ =0x00000764
	adds r6, r7, r3
	str r4, [sp, #0x2c]
_0818FE22:
	movs r1, #2
	ldrh r0, [r6, #0x16]
	ands r0, r1
	cmp r0, #0
	beq _0818FE3C
	movs r0, #1
	b _0818FE3E
	.align 2, 0
_0818FE30: .4byte 0x00000ECA
_0818FE34: .4byte 0x00000F36
_0818FE38: .4byte 0x00000764
_0818FE3C:
	movs r0, #0
_0818FE3E:
	cmp r0, #0
	beq _0818FEEE
	movs r1, #1
	ldrh r0, [r6, #0x16]
	ands r0, r1
	cmp r0, #0
	beq _0818FE50
	movs r0, #1
	b _0818FE52
_0818FE50:
	movs r0, #0
_0818FE52:
	cmp r0, #0
	bne _0818FEEE
	mov r5, sp
	ldr r0, [sp, #0x2c]
	adds r2, r0, r7
	ldr r3, _0818FFC8 @ =0x00000674
	adds r2, r2, r3
	ldrh r1, [r6]
	ldrh r0, [r2]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r4, #2
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, [sp, #0x24]
	cmp r1, r0
	ble _0818FEEE
	mov r1, r8
	cmp r1, #1
	bge _0818FEAC
	movs r4, #1
	mov r8, r4
_0818FEAC:
	adds r0, r2, #0
	mov r1, r8
	str r3, [sp, #0x30]
	bl Div
	ldr r1, [sp, #0x2c]
	adds r4, r7, r1
	ldr r3, [sp, #0x30]
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r2, #2
	ldrsh r0, [r5, r2]
	mov r1, r8
	bl Div
	ldr r3, _0818FFCC @ =0x00000676
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	mov r1, r8
	bl Div
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r4, r4, r2
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_0818FEEE:
	movs r3, #0x92
	lsls r3, r3, #1
	adds r6, r6, r3
	ldr r4, [sp, #0x2c]
	adds r4, r4, r3
	str r4, [sp, #0x2c]
	movs r0, #1
	add sb, r0
	ldr r1, _0818FFD0 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _0818FE22
_0818FF0A:
	ldr r3, _0818FFD4 @ =0x00000ECA
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	bne _0818FFDC
	ldr r4, [sp, #0x20]
	ldr r0, [r4, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r0, #0
	mov sb, r0
	ldr r1, _0818FFD0 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _0818FF32
	b _08190128
_0818FF32:
	add r5, sp, #8
	add r6, sp, #0x10
	ldr r3, _0818FFC8 @ =0x00000674
	adds r4, r7, r3
_0818FF3A:
	ldrh r0, [r6]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #0
	ldrsh r2, [r5, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _0818FFD8 @ =0x000031B4
	cmp r1, r0
	ble _0818FFA6
	adds r0, r2, #0
	mov r1, sl
	bl Div
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	movs r1, #2
	ldrsh r0, [r5, r1]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #2]
	adds r1, r1, r0
	strh r1, [r4, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	strh r1, [r4, #4]
_0818FFA6:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r4, r4, r3
	movs r0, #1
	add sb, r0
	ldr r1, _0818FFD0 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _0818FF3A
	b _08190128
	.align 2, 0
_0818FFC8: .4byte 0x00000674
_0818FFCC: .4byte 0x00000676
_0818FFD0: .4byte 0x00000F36
_0818FFD4: .4byte 0x00000ECA
_0818FFD8: .4byte 0x000031B4
_0818FFDC:
	ldrh r1, [r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r3, _08190140 @ =0x00000674
	adds r0, r0, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r0, [r2]
	subs r0, #1
	mov sb, r0
	add r4, sp, #0x10
	mov r8, r4
	add r6, sp, #0x18
	ldr r0, [sp, #0x20]
	adds r0, #8
	str r0, [sp, #0x28]
	mov r1, sb
	cmp r1, #0
	blt _081900A8
	adds r5, r6, #0
	lsls r0, r1, #3
	add r0, sb
	lsls r0, r0, #3
	add r0, sb
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r4, r0, r7
_0819001E:
	add r0, sp, #0x10
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	add r2, sp, #0x18
	strh r1, [r2]
	mov r3, sp
	ldrh r0, [r3, #0x12]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #0x14]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #0
	ldrsh r2, [r2, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08190144 @ =0x000031B4
	cmp r1, r0
	ble _08190090
	adds r0, r2, #0
	mov r1, sl
	bl Div
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	movs r1, #2
	ldrsh r0, [r5, r1]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #2]
	adds r1, r1, r0
	strh r1, [r4, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	strh r1, [r4, #4]
_08190090:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r3, _08190148 @ =0xFFFFFEDC
	adds r4, r4, r3
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _0819001E
_081900A8:
	add r0, sp, #0x10
	ldrh r0, [r0]
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #8]
	subs r0, r0, r1
	add r2, sp, #0x18
	strh r0, [r2]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldr r4, [sp, #0x28]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldrsh r2, [r2, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r6, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _08190144 @ =0x000031B4
	cmp r1, r0
	ble _08190128
	adds r0, r2, #0
	mov r1, sl
	bl Div
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x10]
	adds r1, r1, r0
	strh r1, [r2, #0x10]
	movs r3, #2
	ldrsh r0, [r6, r3]
	mov r1, sl
	bl Div
	ldr r4, [sp, #0x20]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r2, #4
	ldrsh r0, [r6, r2]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #0x14]
	adds r1, r1, r0
	strh r1, [r4, #0x14]
_08190128:
	ldr r0, [sp, #0x20]
	bl FUN_0818f864
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190140: .4byte 0x00000674
_08190144: .4byte 0x000031B4
_08190148: .4byte 0xFFFFFEDC

	thumb_func_start FUN_0819014c
FUN_0819014c: @ 0x0819014C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _08190198 @ =0x00000F36
	adds r7, r3, r0
	movs r2, #0
	ldrsh r0, [r7, r2]
	cmp r5, r0
	bge _0819018E
	ldr r2, [r1, #4]
	ldr r1, [r1]
	ldr r6, _0819019C @ =0x00000764
	adds r4, r3, r6
	ldr r0, _081901A0 @ =0x00000674
	adds r3, r3, r0
	movs r6, #0x92
	lsls r6, r6, #1
	mov r8, r6
	mov ip, r7
_08190176:
	str r1, [r3]
	str r2, [r3, #4]
	str r1, [r4]
	str r2, [r4, #4]
	add r4, r8
	add r3, r8
	adds r5, #1
	mov r7, ip
	movs r6, #0
	ldrsh r0, [r7, r6]
	cmp r5, r0
	blt _08190176
_0819018E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190198: .4byte 0x00000F36
_0819019C: .4byte 0x00000764
_081901A0: .4byte 0x00000674

	thumb_func_start FUN_081901a4
FUN_081901a4: @ 0x081901A4
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r4, r0, #0
	ldr r6, _0819022C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r6
	movs r2, #0x80
	orrs r0, r2
	ldr r5, _08190230 @ =0x0000FFFF
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r6
	orrs r0, r2
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r6
	str r0, [r2, #4]
	ldr r3, _08190234 @ =FUN_081889fc
	str r4, [sp]
	adds r0, r4, #0
	add r1, sp, #8
	bl FUN_080e3834
	ldr r0, [sp, #0x18]
	ands r0, r6
	movs r2, #0x52
	orrs r0, r2
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r6
	orrs r0, r2
	str r0, [r1, #4]
	movs r5, #0
	str r5, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r6
	str r0, [r2, #4]
	ldr r3, _08190238 @ =FUN_081889bc
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r4, #0
	bl FUN_080e3984
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r4, r0
	movs r0, #0x80
	lsls r0, r0, #3
	ldrh r1, [r4, #6]
	orrs r0, r1
	strh r0, [r4, #6]
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819022C: .4byte 0xFFFF0000
_08190230: .4byte 0x0000FFFF
_08190234: .4byte FUN_081889fc
_08190238: .4byte FUN_081889bc

	thumb_func_start FUN_0819023c
FUN_0819023c: @ 0x0819023C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r3, _081902A4 @ =0x00000F2C
	adds r2, r5, r3
	ldrh r1, [r2]
	ldr r0, _081902A8 @ =0x0000FFFD
	ands r0, r1
	movs r3, #0
	movs r1, #0
	strh r0, [r2]
	ldr r2, _081902AC @ =0x00000ED5
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r2, _081902B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081902B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081902B8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	ldr r2, _081902BC @ =0x00000F45
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _081902C0 @ =0x00000ECD
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x3f
	adds r1, r5, r2
	ldr r3, _081902C4 @ =0x0000025D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081902C8
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081902D2
	.align 2, 0
_081902A4: .4byte 0x00000F2C
_081902A8: .4byte 0x0000FFFD
_081902AC: .4byte 0x00000ED5
_081902B0: .4byte 0x030046B8
_081902B4: .4byte 0x000003FF
_081902B8: .4byte 0x0203B400
_081902BC: .4byte 0x00000F45
_081902C0: .4byte 0x00000ECD
_081902C4: .4byte 0x0000025D
_081902C8:
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081902D2:
	ldr r1, _08190358 @ =0x00000F84
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	adds r0, r4, #0
	bl FUN_0819208c
	adds r1, r4, #0
	adds r1, #8
	adds r0, r5, #0
	bl FUN_0819014c
	adds r0, r4, #0
	bl FUN_0818e6fc
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r5, _0819035C @ =0x00000469
	adds r0, r4, r5
	strb r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r2, [r0]
	ldr r1, _08190360 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	subs r5, #0x17
	adds r0, r4, r5
	strb r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08190358: .4byte 0x00000F84
_0819035C: .4byte 0x00000469
_08190360: .4byte 0x0000046C

	thumb_func_start FUN_08190364
FUN_08190364: @ 0x08190364
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r3, [r6, #0x44]
	ldr r2, _081903A0 @ =0x085B0A08
	ldr r4, _081903A4 @ =0x00000F2E
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #1
	cmp r0, #0
	blt _081903A8
	asrs r1, r0, #0xc
	b _081903AE
	.align 2, 0
_081903A0: .4byte 0x085B0A08
_081903A4: .4byte 0x00000F2E
_081903A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081903AE:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	ldr r1, [r6, #0x44]
	ldr r3, [sp, #0x24]
	ldr r4, _081903D0 @ =0x00000F2E
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #4
	cmp r0, #0
	blt _081903D4
	asrs r2, r0, #0xc
	b _081903DA
	.align 2, 0
_081903D0: .4byte 0x00000F2E
_081903D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081903DA:
	ldrh r0, [r1, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	ldr r0, [sp, #0x24]
	ldr r2, _0819042C @ =0x00000F2E
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	movs r5, #1
	mov sl, r5
	ldr r3, [sp, #0x24]
	ldr r4, _08190430 @ =0x00000F36
	adds r1, r3, r4
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sl, r0
	bge _0819046A
	ldr r0, _08190434 @ =0x085B0A08
	mov r8, r0
	mov sb, r1
	movs r1, #0x92
	lsls r1, r1, #1
	adds r3, r3, r1
	ldr r4, [sp, #0x24]
	ldr r7, _08190438 @ =0x0000087D
	adds r2, r4, r7
	movs r4, #0x92
	lsls r4, r4, #2
_08190416:
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0819043C
	asrs r0, r0, #0xc
	b _08190442
	.align 2, 0
_0819042C: .4byte 0x00000F2E
_08190430: .4byte 0x00000F36
_08190434: .4byte 0x085B0A08
_08190438: .4byte 0x0000087D
_0819043C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08190442:
	ldr r7, _081904F4 @ =0x00000674
	adds r1, r3, r7
	muls r0, r5, r0
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, #8
	strb r0, [r2]
	rsbs r5, r5, #0
	adds r3, r3, r4
	adds r2, r2, r4
	movs r0, #2
	add sl, r0
	mov r1, sb
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sl, r0
	blt _08190416
_0819046A:
	ldr r0, [r6, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0
	mov sl, r0
	ldr r1, [sp, #0x24]
	ldr r2, _081904F8 @ =0x00000F36
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #1
	cmp sl, r0
	blt _0819048A
	b _081905B4
_0819048A:
	add r4, sp, #4
	mov sb, r4
	add r7, sp, #0xc
	add r6, sp, #0x14
	movs r0, #0xf3
	lsls r0, r0, #3
	adds r5, r1, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
_0819049E:
	ldrh r0, [r5]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r0, [r5, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r2, #0
	str r2, [sp]
	mov r0, sp
	add r1, sp, #0x1c
	ldr r2, _081904FC @ =0x05000002
	bl CpuSet
	mov r3, r8
	movs r4, #0xc0
	lsls r4, r4, #2
	subs r1, r3, r4
	adds r1, #1
	add r2, sp, #0x1c
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	mov r3, r8
	subs r1, r0, r3
	movs r3, #0
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	mov ip, r2
	cmp r0, #0
	blt _08190500
	asrs r1, r0, #0xa
	b _08190506
	.align 2, 0
_081904F4: .4byte 0x00000674
_081904F8: .4byte 0x00000F36
_081904FC: .4byte 0x05000002
_08190500:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08190506:
	ldrh r0, [r7]
	adds r0, r0, r1
	mov r4, sb
	strh r0, [r4]
	mov r0, r8
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r3, r0, r1
	adds r1, r3, #1
	mov r2, ip
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, r8
	rsbs r2, r0, #0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r1, r2, r1
	str r1, [sp, #0x28]
	movs r1, #2
	ldrsh r0, [r6, r1]
	ldr r1, [sp, #0x28]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r4, #0
	orrs r0, r4
	cmp r0, #0
	blt _08190544
	asrs r1, r0, #0xa
	b _0819054A
_08190544:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0819054A:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r1, sb
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, ip
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r3, #0
	orrs r0, r3
	cmp r0, #0
	blt _08190578
	asrs r1, r0, #0xa
	b _0819057E
_08190578:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0819057E:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r4, sb
	strh r0, [r4, #4]
	ldr r0, [sp, #0x24]
	mov r1, sl
	mov r2, sb
	bl FUN_0818f844
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0x92
	lsls r0, r0, #2
	adds r5, r5, r0
	movs r1, #2
	add sl, r1
	ldr r2, [sp, #0x24]
	ldr r3, _081905C4 @ =0x00000F36
	adds r0, r2, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r0, #1
	cmp sl, r0
	bge _081905B4
	b _0819049E
_081905B4:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081905C4: .4byte 0x00000F36

	thumb_func_start FUN_081905c8
FUN_081905c8: @ 0x081905C8
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0
	movs r3, #0
	ldr r5, _08190600 @ =0x00000F36
	adds r2, r1, r5
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r3, r0
	bge _0819062C
	movs r7, #1
	movs r0, #3
	rsbs r0, r0, #0
	mov ip, r0
	adds r5, r2, #0
	ldr r0, _08190604 @ =0x0000077A
	adds r2, r1, r0
	movs r6, #0x92
	lsls r6, r6, #1
_081905F4:
	ldrh r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _08190608
	movs r0, #1
	b _0819060A
	.align 2, 0
_08190600: .4byte 0x00000F36
_08190604: .4byte 0x0000077A
_08190608:
	movs r0, #0
_0819060A:
	cmp r0, #0
	bne _08190620
	cmp r4, #1
	bne _08190616
	movs r4, #0
	b _08190620
_08190616:
	ldrh r1, [r2]
	mov r0, ip
	ands r0, r1
	strh r0, [r2]
	adds r4, #1
_08190620:
	adds r2, r2, r6
	adds r3, #1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r3, r0
	blt _081905F4
_0819062C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08190634
FUN_08190634: @ 0x08190634
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r4, _08190684 @ =0x00000F36
	adds r0, r6, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r5, r0, #1
	cmp r5, #0
	blt _081906C4
	movs r4, #1
	mov r8, r4
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r5
	lsls r2, r0, #2
	adds r0, r2, #0
	adds r0, #0x98
	adds r3, r0, r1
	movs r4, #0x91
	lsls r4, r4, #1
	adds r0, r2, r4
	adds r4, r0, r1
_08190674:
	ldrh r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08190688
	movs r0, #1
	b _0819068A
	.align 2, 0
_08190684: .4byte 0x00000F36
_08190688:
	movs r0, #0
_0819068A:
	cmp r0, #0
	bne _081906B8
	adds r0, r3, #0
	bl FUN_08236424
	ldrh r1, [r4]
	mov r0, r8
	orrs r0, r1
	strh r0, [r4]
	ldr r2, _081906B4 @ =0x00000F46
	adds r1, r6, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_08191774
	movs r0, #1
	b _081906C6
	.align 2, 0
_081906B4: .4byte 0x00000F46
_081906B8:
	ldr r0, _081906D0 @ =0xFFFFFEDC
	adds r3, r3, r0
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _08190674
_081906C4:
	movs r0, #0
_081906C6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081906D0: .4byte 0xFFFFFEDC

	thumb_func_start FUN_081906d4
FUN_081906d4: @ 0x081906D4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r4, _08190724 @ =0x00000F46
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0819075A
	ldr r2, _08190728 @ =0x00000F36
	adds r0, r7, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r5, r0, #1
	cmp r5, #0
	blt _0819075A
	movs r3, #1
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r5
	lsls r2, r0, #2
	adds r0, r2, #0
	adds r0, #0x98
	adds r6, r0, r1
	movs r4, #0x91
	lsls r4, r4, #1
	adds r0, r2, r4
	adds r4, r0, r1
_08190718:
	ldrh r0, [r4]
	ands r0, r3
	cmp r0, #0
	beq _0819072C
	movs r0, #1
	b _0819072E
	.align 2, 0
_08190724: .4byte 0x00000F46
_08190728: .4byte 0x00000F36
_0819072C:
	movs r0, #0
_0819072E:
	cmp r0, #0
	bne _0819074E
	adds r0, r6, #0
	str r3, [sp]
	bl FUN_08236424
	ldrh r1, [r4]
	ldr r3, [sp]
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _08190764 @ =0x00000F46
	adds r1, r7, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0819074E:
	ldr r1, _08190768 @ =0xFFFFFEDC
	adds r6, r6, r1
	adds r4, r4, r1
	subs r5, #1
	cmp r5, #0
	bge _08190718
_0819075A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190764: .4byte 0x00000F46
_08190768: .4byte 0xFFFFFEDC

	thumb_func_start FUN_0819076c
FUN_0819076c: @ 0x0819076C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r4, _081907BC @ =0x00000F46
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _081907F2
	ldr r2, _081907C0 @ =0x00000F36
	adds r0, r7, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r5, r0, #1
	cmp r5, #0
	blt _081907F2
	movs r3, #1
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r5
	lsls r2, r0, #2
	adds r0, r2, #0
	adds r0, #0x98
	adds r6, r0, r1
	movs r4, #0x91
	lsls r4, r4, #1
	adds r0, r2, r4
	adds r4, r0, r1
_081907B0:
	ldrh r0, [r4]
	ands r0, r3
	cmp r0, #0
	beq _081907C4
	movs r0, #1
	b _081907C6
	.align 2, 0
_081907BC: .4byte 0x00000F46
_081907C0: .4byte 0x00000F36
_081907C4:
	movs r0, #0
_081907C6:
	cmp r0, #0
	bne _081907E6
	adds r0, r6, #0
	str r3, [sp]
	bl FUN_08236424
	ldrh r1, [r4]
	ldr r3, [sp]
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _081907FC @ =0x00000F46
	adds r1, r7, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_081907E6:
	ldr r1, _08190800 @ =0xFFFFFEDC
	adds r6, r6, r1
	adds r4, r4, r1
	subs r5, #1
	cmp r5, #0
	bge _081907B0
_081907F2:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081907FC: .4byte 0x00000F46
_08190800: .4byte 0xFFFFFEDC

	thumb_func_start FUN_08190804
FUN_08190804: @ 0x08190804
	push {lr}
	cmp r1, #0
	beq _0819081C
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08190820 @ =0x00000F2E
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_0819081C:
	pop {r0}
	bx r0
	.align 2, 0
_08190820: .4byte 0x00000F2E

	thumb_func_start FUN_08190824
FUN_08190824: @ 0x08190824
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r5, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r3, #2
	ldrsh r0, [r1, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r2, r2, r0
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r2, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r6, r0
	ble _0819086A
	movs r6, #0xff
	b _08190874
_0819086A:
	cmp r6, #0x80
	ble _08190872
	movs r6, #0x7f
	b _08190874
_08190872:
	movs r6, #0x3f
_08190874:
	movs r2, #0
	mov ip, r2
	ldr r3, _081908AC @ =0x00000F36
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	bge _08190960
	ldr r2, _081908B0 @ =0x085B0A08
	mov sl, r2
	movs r7, #0
	movs r3, #0xcb
	lsls r3, r3, #3
	mov sb, r3
	ldr r0, _081908B4 @ =0x030046B8
	mov r8, r0
_08190894:
	adds r0, r7, r5
	add r0, sb
	movs r1, #0x91
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #2
	ands r0, r2
	cmp r0, #0
	beq _081908B8
	movs r0, #1
	b _081908BA
	.align 2, 0
_081908AC: .4byte 0x00000F36
_081908B0: .4byte 0x085B0A08
_081908B4: .4byte 0x030046B8
_081908B8:
	movs r0, #0
_081908BA:
	cmp r0, #0
	beq _0819094A
	adds r0, r7, r5
	add r0, sb
	movs r3, #0x91
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081908D6
	movs r0, #1
	b _081908D8
_081908D6:
	movs r0, #0
_081908D8:
	cmp r0, #0
	bne _0819094A
	mov r2, r8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08190914 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08190918 @ =0x0203B400
	adds r0, r0, r3
	ldrh r3, [r0]
	adds r2, r7, r5
	ldr r0, _0819091C @ =0x0000076C
	adds r2, r2, r0
	ands r3, r6
	movs r4, #0xc
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08190920
	asrs r1, r0, #0xc
	b _08190926
	.align 2, 0
_08190914: .4byte 0x000003FF
_08190918: .4byte 0x0203B400
_0819091C: .4byte 0x0000076C
_08190920:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08190926:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08190942
	asrs r0, r0, #0xc
	b _08190948
_08190942:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08190948:
	strh r0, [r2, #4]
_0819094A:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	movs r1, #1
	add ip, r1
	ldr r2, _08190970 @ =0x00000F36
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp ip, r0
	blt _08190894
_08190960:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190970: .4byte 0x00000F36

	thumb_func_start FUN_08190974
FUN_08190974: @ 0x08190974
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r2, [sp]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081909A2
	b _08190ACA
_081909A2:
	movs r0, #0
	mov sl, r0
	ldr r0, _081909D4 @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _081909B4
	b _08190ACA
_081909B4:
	ldr r7, _081909D8 @ =0x00000676
	add r7, sb
	ldr r6, _081909DC @ =0x00000674
	add r6, sb
	ldr r2, _081909E0 @ =0x0000077A
	add r2, sb
	mov r8, r2
_081909C2:
	movs r1, #2
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081909E4
	movs r0, #1
	b _081909E6
	.align 2, 0
_081909D4: .4byte 0x00000F36
_081909D8: .4byte 0x00000676
_081909DC: .4byte 0x00000674
_081909E0: .4byte 0x0000077A
_081909E4:
	movs r0, #0
_081909E6:
	cmp r0, #0
	beq _08190AAE
	movs r1, #1
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081909FA
	movs r0, #1
	b _081909FC
_081909FA:
	movs r0, #0
_081909FC:
	cmp r0, #0
	bne _08190AAE
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08190A24
	cmp r1, #0
	blt _08190A24
	ldr r0, _08190A28 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08190A24
	ldr r0, _08190A2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08190A30
_08190A24:
	movs r4, #0
	b _08190A3E
	.align 2, 0
_08190A28: .4byte 0x030046A8
_08190A2C: .4byte 0x030046AC
_08190A30:
	ldr r0, _08190A50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08190A3E:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08190A54
	adds r0, #4
	b _08190A60
	.align 2, 0
_08190A50: .4byte 0x030046A4
_08190A54:
	ldr r0, _08190A74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08190A60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08190A78
	cmp r2, #2
	beq _08190A7C
	b _08190A80
	.align 2, 0
_08190A74: .4byte 0x030046A4
_08190A78:
	ldrb r0, [r5, #4]
	b _08190A7E
_08190A7C:
	ldrb r0, [r5]
_08190A7E:
	subs r1, r1, r0
_08190A80:
	movs r3, #2
	ldrsh r0, [r6, r3]
	cmp r0, r1
	beq _08190AAE
	cmp r0, r1
	bge _08190AA0
	subs r0, r1, r0
	cmp r0, #0
	bge _08190A94
	rsbs r0, r0, #0
_08190A94:
	cmp r0, #0xff
	ble _08190AAC
	ldr r1, [sp]
	ldrh r0, [r1, #0xa]
	strh r0, [r7]
	b _08190AAE
_08190AA0:
	subs r0, r1, r0
	movs r1, #0xa
	bl Div
	ldrh r1, [r7]
	adds r1, r1, r0
_08190AAC:
	strh r1, [r7]
_08190AAE:
	movs r2, #0x92
	lsls r2, r2, #1
	adds r7, r7, r2
	adds r6, r6, r2
	add r8, r2
	movs r3, #1
	add sl, r3
	ldr r0, _08190ADC @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _08190ACA
	b _081909C2
_08190ACA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190ADC: .4byte 0x00000F36

	thumb_func_start FUN_08190ae0
FUN_08190ae0: @ 0x08190AE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r2, #0
	mov sl, r2
	ldr r7, _08190B2C @ =0x00000F36
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _08190BEE
	movs r6, #0
	ldr r2, _08190B30 @ =0x0000076E
	adds r3, r5, r2
	adds r4, r5, #0
	movs r7, #2
	mov sb, r7
	movs r0, #1
	mov r8, r0
	movs r1, #0x92
	lsls r1, r1, #1
	mov ip, r1
_08190B18:
	adds r0, r6, r5
	ldr r2, _08190B34 @ =0x0000077A
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r7, sb
	ands r0, r7
	cmp r0, #0
	beq _08190B38
	movs r0, #1
	b _08190B3A
	.align 2, 0
_08190B2C: .4byte 0x00000F36
_08190B30: .4byte 0x0000076E
_08190B34: .4byte 0x0000077A
_08190B38:
	movs r0, #0
_08190B3A:
	cmp r0, #0
	beq _08190BD8
	adds r0, r6, r5
	ldr r1, _08190B54 @ =0x0000077A
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _08190B58
	movs r0, #1
	b _08190B5A
	.align 2, 0
_08190B54: .4byte 0x0000077A
_08190B58:
	movs r0, #0
_08190B5A:
	cmp r0, #0
	bne _08190BD8
	ldr r7, _08190B94 @ =0x00000674
	adds r1, r4, r7
	ldr r0, _08190B98 @ =0x0000076C
	adds r2, r4, r0
	ldrh r0, [r2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldr r0, _08190B9C @ =0x00000676
	adds r1, r4, r0
	ldrh r0, [r3]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r3, #2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _08190BA0
	asrs r1, r0, #1
	b _08190BA6
	.align 2, 0
_08190B94: .4byte 0x00000674
_08190B98: .4byte 0x0000076C
_08190B9C: .4byte 0x00000676
_08190BA0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08190BA6:
	ldr r2, _08190BB8 @ =0x0000076C
	adds r0, r4, r2
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, #0
	blt _08190BBC
	asrs r0, r0, #1
	b _08190BC2
	.align 2, 0
_08190BB8: .4byte 0x0000076C
_08190BBC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08190BC2:
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _08190BD0
	asrs r0, r0, #1
	b _08190BD6
_08190BD0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08190BD6:
	strh r0, [r3, #2]
_08190BD8:
	add r6, ip
	add r3, ip
	add r4, ip
	movs r2, #1
	add sl, r2
	ldr r7, _08190BFC @ =0x00000F36
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _08190B18
_08190BEE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190BFC: .4byte 0x00000F36

	thumb_func_start FUN_08190c00
FUN_08190c00: @ 0x08190C00
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	movs r1, #2
	ldr r2, _08190C20 @ =0x00000F2C
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08190C24
	movs r0, #1
	b _08190C26
	.align 2, 0
_08190C20: .4byte 0x00000F2C
_08190C24:
	movs r0, #0
_08190C26:
	cmp r0, #0
	beq _08190C70
	movs r2, #4
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #0
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r2, [r0]
	ldr r2, _08190C84 @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r5, #2
	adds r1, r3, r5
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _08190C88 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _08190C8C @ =0x00000544
	adds r1, r3, r2
	movs r0, #0xb4
	strh r0, [r1]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r3, r5
	movs r0, #2
	strh r0, [r1]
_08190C70:
	ldr r1, _08190C90 @ =0x00000F2C
	adds r0, r4, r1
	movs r1, #3
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08190C84: .4byte 0x00000484
_08190C88: .4byte 0xFFEFFFFF
_08190C8C: .4byte 0x00000544
_08190C90: .4byte 0x00000F2C

	thumb_func_start FUN_08190c94
FUN_08190c94: @ 0x08190C94
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08190D06
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x20
	ldr r2, _08190CC4 @ =0x00000F2C
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08190CC8
	movs r0, #1
	b _08190CCA
	.align 2, 0
_08190CC4: .4byte 0x00000F2C
_08190CC8:
	movs r0, #0
_08190CCA:
	adds r2, r0, #0
	cmp r2, #0
	bne _08190D06
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldr r0, _08190D10 @ =0x00000ED8
	adds r1, r1, r0
	ldrh r0, [r5, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	add r4, sp, #0xc
	str r2, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _08190D14 @ =0x05000002
	bl CpuSet
	ldrh r1, [r5, #0x3e]
	adds r3, r6, #0
	adds r3, #0x1c
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0805fe7c
_08190D06:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08190D10: .4byte 0x00000ED8
_08190D14: .4byte 0x05000002

	thumb_func_start FUN_08190d18
FUN_08190d18: @ 0x08190D18
	bx lr
	.align 2, 0

	thumb_func_start FUN_08190d1c
FUN_08190d1c: @ 0x08190D1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08190D44
	b _08190F0E
_08190D44:
	movs r2, #0x20
	ldr r0, _08190D58 @ =0x00000F2C
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08190D5C
	movs r0, #1
	b _08190D5E
	.align 2, 0
_08190D58: .4byte 0x00000F2C
_08190D5C:
	movs r0, #0
_08190D5E:
	cmp r0, #0
	beq _08190D64
	b _08190F0E
_08190D64:
	adds r0, r7, #0
	adds r0, #0xdc
	ldrh r0, [r0]
	cmp r0, #0
	beq _08190D70
	b _08190F0E
_08190D70:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08236524
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x44
	strh r1, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08190c94
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	adds r0, r7, #0
	bl FUN_08192744
	movs r0, #0x40
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #4
	movs r2, #0x91
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08190DC0
	movs r0, #1
	b _08190DC2
_08190DC0:
	movs r0, #0
_08190DC2:
	cmp r0, #0
	beq _08190DD4
	ldr r0, _08190DD0 @ =0x000003E1
	bl PlaySound_082406e0
	b _08190DDC
	.align 2, 0
_08190DD0: .4byte 0x000003E1
_08190DD4:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08190DDC:
	adds r0, r6, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08190DEC
	b _08190F0E
_08190DEC:
	ldrh r1, [r5, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08190E00
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r3, [r0]
	b _08190E6C
_08190E00:
	add r4, sp, #0x10
	adds r3, r6, #0
	adds r3, #0xc
	adds r2, r5, #0
	adds r2, #0xc
	ldrh r0, [r5, #0xc]
	ldrh r1, [r6, #0xc]
	subs r0, r0, r1
	adds r1, r4, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	adds r0, r4, #0
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08190E58
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08190E58
	ldr r0, _08190E4C @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08190E50 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _08190E54 @ =0x0203B400
	adds r1, r1, r0
	ldrb r3, [r1]
	b _08190E6C
	.align 2, 0
_08190E4C: .4byte 0x030046B8
_08190E50: .4byte 0x000003FF
_08190E54: .4byte 0x0203B400
_08190E58:
	add r0, sp, #0x10
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #0x10
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_08190E6C:
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, _08190F20 @ =0x0203B400
	mov r8, r0
	ldr r1, _08190F24 @ =0x030046B8
	mov sl, r1
	ldr r4, [r1]
	adds r4, #1
	ldr r6, _08190F28 @ =0x000003FF
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08190F2C @ =0x0000FFFF
	mov sb, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r5, _08190F30 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r5
	movs r1, #0x3c
	orrs r0, r1
	mov r1, sb
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r5
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	adds r4, #1
	ands r4, r6
	lsls r0, r4, #1
	add r0, r8
	ldrh r5, [r0]
	movs r0, #7
	ands r5, r0
	adds r5, #4
	adds r4, #1
	ands r4, r6
	mov r1, sl
	str r4, [r1]
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r4]
	ands r1, r0
	adds r1, #8
	add r0, sp, #0x20
	str r5, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #2
	bl FUN_080ddcc8
_08190F0E:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190F20: .4byte 0x0203B400
_08190F24: .4byte 0x030046B8
_08190F28: .4byte 0x000003FF
_08190F2C: .4byte 0x0000FFFF
_08190F30: .4byte 0xFFFF0000

	thumb_func_start FUN_08190f34
FUN_08190f34: @ 0x08190F34
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r0, _08190F7C @ =0x00000F48
	adds r3, r1, r0
	ldr r0, [r3]
	ldr r4, _08190F80 @ =0x7FFFFFFF
	cmp r0, r4
	beq _08190FB2
	ldr r2, _08190F84 @ =0x00000F4C
	adds r0, r1, r2
	ldr r2, [r0]
	str r4, [r3]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r2, r4
	adds r1, r2, #0
	adds r1, #0xd8
	adds r4, #0x14
	adds r3, r2, r4
	ldrb r4, [r0]
	ldrh r5, [r1]
	ldr r2, _08190F88 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08190F8C
	asrs r1, r0, #0xc
	b _08190F92
	.align 2, 0
_08190F7C: .4byte 0x00000F48
_08190F80: .4byte 0x7FFFFFFF
_08190F84: .4byte 0x00000F4C
_08190F88: .4byte 0x085B0A08
_08190F8C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08190F92:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08190FAA
	asrs r0, r0, #0xc
	b _08190FB0
_08190FAA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08190FB0:
	strh r0, [r3, #4]
_08190FB2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08190fb8
FUN_08190fb8: @ 0x08190FB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08191060 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08191064 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0
	mov sb, r2
	ldr r3, _08191068 @ =0x00000F36
	adds r0, r6, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov sl, r1
	cmp sb, r0
	bge _081910C8
	ldr r3, _0819106C @ =0x00000674
	adds r3, r3, r6
	mov r8, r3
	movs r0, #0xde
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r7, r6, r1
_0819101A:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r2, sp, #0xc
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	ldr r2, _08191070 @ =0x00005009
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08191068 @ =0x00000F36
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp sb, r0
	bne _08191078
	ldr r3, _08191074 @ =0x00000ED3
	adds r0, r6, r3
	ldrb r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r3, [r0]
	adds r0, r4, #0
	bl FUN_08236514
	b _08191094
	.align 2, 0
_08191060: .4byte 0xFFFF0000
_08191064: .4byte 0x0000FFFF
_08191068: .4byte 0x00000F36
_0819106C: .4byte 0x00000674
_08191070: .4byte 0x00005009
_08191074: .4byte 0x00000ED3
_08191078:
	ldr r1, _08191184 @ =0x00000ED2
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r3, [r0]
	adds r0, r4, #0
	bl FUN_08236514
_08191094:
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _08191188 @ =FUN_08190d1c
	adds r2, r7, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0x92
	lsls r0, r0, #1
	add r8, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r1, #1
	add sb, r1
	ldr r2, _0819118C @ =0x00000F36
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp sb, r0
	blt _0819101A
_081910C8:
	movs r3, #0
	movs r2, #0x40
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	mov r0, sl
	strh r3, [r0]
	add r1, sp, #0x14
	movs r0, #0x80
	strh r0, [r1, #2]
	strh r3, [r1, #4]
	mov sb, r3
	ldr r1, _0819118C @ =0x00000F36
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	bge _08191174
	ldr r3, _08191190 @ =0x00000674
	adds r3, r3, r6
	mov r8, r3
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r7, r6, r1
_08191104:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r2, sp, #0xc
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	ldr r2, _08191194 @ =0x00002401
	movs r3, #0
	bl FUN_0823646c
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _08191198 @ =FUN_08190d18
	adds r2, r7, #0
	bl FUN_0823651c
	movs r0, #0x92
	lsls r0, r0, #1
	add r8, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r1, #1
	add sb, r1
	ldr r2, _0819118C @ =0x00000F36
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp sb, r0
	blt _08191104
_08191174:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08191184: .4byte 0x00000ED2
_08191188: .4byte FUN_08190d1c
_0819118C: .4byte 0x00000F36
_08191190: .4byte 0x00000674
_08191194: .4byte 0x00002401
_08191198: .4byte FUN_08190d18

	thumb_func_start FUN_0819119c
FUN_0819119c: @ 0x0819119C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0xc
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #9
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0xb
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081911e0
FUN_081911e0: @ 0x081911E0
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldr r1, _08191218 @ =0x00000546
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r2, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	ble _0819123C
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x10
	ldr r2, _0819121C @ =0x00000F2C
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08191220
	movs r0, #1
	b _08191222
	.align 2, 0
_08191218: .4byte 0x00000546
_0819121C: .4byte 0x00000F2C
_08191220:
	movs r0, #0
_08191222:
	cmp r0, #0
	beq _08191278
	ldr r2, _08191238 @ =0x085ADD54
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #2
	b _08191288
	.align 2, 0
_08191238: .4byte 0x085ADD54
_0819123C:
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #0x10
	ldr r2, _08191258 @ =0x00000F2C
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819125C
	movs r0, #1
	b _0819125E
	.align 2, 0
_08191258: .4byte 0x00000F2C
_0819125C:
	movs r0, #0
_0819125E:
	cmp r0, #0
	bne _08191278
	ldr r2, _08191274 @ =0x085ADD54
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	b _08191288
	.align 2, 0
_08191274: .4byte 0x085ADD54
_08191278:
	ldr r2, _08191290 @ =0x085ADD54
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #1
_08191288:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08191290: .4byte 0x085ADD54

	thumb_func_start FUN_08191294
FUN_08191294: @ 0x08191294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0xa0
	ldr r0, _081912C0 @ =0x00000F2C
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081912C4
	movs r0, #1
	b _081912C6
	.align 2, 0
_081912C0: .4byte 0x00000F2C
_081912C4:
	movs r0, #0
_081912C6:
	cmp r0, #0
	beq _081912CC
	b _081913C2
_081912CC:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r3
	cmp r2, #0
	blt _08191318
	cmp r1, #0
	blt _08191318
	ldr r0, _0819131C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191318
	ldr r0, _08191320 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191324
_08191318:
	movs r4, #0
	b _08191332
	.align 2, 0
_0819131C: .4byte 0x030046A8
_08191320: .4byte 0x030046AC
_08191324:
	ldr r0, _0819134C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08191332:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	mov r6, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191350
	adds r0, #4
	b _0819135C
	.align 2, 0
_0819134C: .4byte 0x030046A4
_08191350:
	ldr r0, _08191370 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0819135C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08191374
	cmp r2, #2
	beq _08191378
	b _0819137C
	.align 2, 0
_08191370: .4byte 0x030046A4
_08191374:
	ldrb r0, [r6, #4]
	b _0819137A
_08191378:
	ldrb r0, [r6]
_0819137A:
	subs r1, r1, r0
_0819137C:
	movs r2, #0
	mov sl, r2
	ldr r3, _081913B0 @ =0x00000472
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, r1
	bge _0819139C
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	mov r1, sl
	strh r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0819139C:
	ldr r1, _081913B4 @ =0x00002004
	ldr r0, _081913B8 @ =0x00000F2C
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081913BC
	movs r0, #1
	b _081913BE
	.align 2, 0
_081913B0: .4byte 0x00000472
_081913B4: .4byte 0x00002004
_081913B8: .4byte 0x00000F2C
_081913BC:
	movs r0, #0
_081913BE:
	cmp r0, #0
	beq _081913D0
_081913C2:
	ldr r1, _081913CC @ =0x00000ED5
	add r1, sb
	movs r0, #0
	strb r0, [r1]
	b _08191760
	.align 2, 0
_081913CC: .4byte 0x00000ED5
_081913D0:
	mov r3, sp
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r4, r8
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	mov r1, sp
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08191422
	cmp r1, #0
	blt _08191422
	ldr r0, _08191428 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191422
	ldr r0, _0819142C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191430
_08191422:
	movs r4, #0
	b _0819143E
	.align 2, 0
_08191428: .4byte 0x030046A8
_0819142C: .4byte 0x030046AC
_08191430:
	ldr r0, _08191450 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819143E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191454
	adds r0, #4
	b _08191460
	.align 2, 0
_08191450: .4byte 0x030046A4
_08191454:
	ldr r0, _08191474 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191460:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191478
	adds r0, #4
	b _08191484
	.align 2, 0
_08191474: .4byte 0x030046A4
_08191478:
	ldr r0, _08191498 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191484:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0819149C
	cmp r2, #2
	beq _081914A0
	b _081914A4
	.align 2, 0
_08191498: .4byte 0x030046A4
_0819149C:
	ldrb r0, [r7, #4]
	b _081914A2
_081914A0:
	ldrb r0, [r7]
_081914A2:
	subs r1, r1, r0
_081914A4:
	movs r0, #0x40
	ands r6, r0
	cmp r6, #0
	beq _081914B0
	cmp r1, #0
	bne _081914B8
_081914B0:
	movs r0, #0
	strh r0, [r5, #0x10]
	movs r2, #1
	mov sl, r2
_081914B8:
	mov r3, sp
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r4, r8
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	ldrh r0, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08191504
	cmp r1, #0
	blt _08191504
	ldr r0, _08191508 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191504
	ldr r0, _0819150C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191510
_08191504:
	movs r4, #0
	b _0819151E
	.align 2, 0
_08191508: .4byte 0x030046A8
_0819150C: .4byte 0x030046AC
_08191510:
	ldr r0, _08191530 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819151E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191534
	adds r0, #4
	b _08191540
	.align 2, 0
_08191530: .4byte 0x030046A4
_08191534:
	ldr r0, _08191554 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191540:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191558
	adds r0, #4
	b _08191564
	.align 2, 0
_08191554: .4byte 0x030046A4
_08191558:
	ldr r0, _08191578 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191564:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0819157C
	cmp r2, #2
	beq _08191580
	b _08191584
	.align 2, 0
_08191578: .4byte 0x030046A4
_0819157C:
	ldrb r0, [r7, #4]
	b _08191582
_08191580:
	ldrb r0, [r7]
_08191582:
	subs r1, r1, r0
_08191584:
	movs r0, #0x40
	ands r6, r0
	cmp r6, #0
	beq _08191590
	cmp r1, #0
	bne _08191598
_08191590:
	movs r0, #0
	strh r0, [r5, #0x14]
	movs r2, #1
	mov sl, r2
_08191598:
	mov r3, sp
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r4, r8
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	mov r1, sp
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r1, [r5, #0x14]
	ldrh r2, [r3, #4]
	adds r1, r1, r2
	strh r1, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081915F4
	cmp r1, #0
	blt _081915F4
	ldr r0, _081915F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081915F4
	ldr r0, _081915FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191600
_081915F4:
	movs r4, #0
	b _0819160E
	.align 2, 0
_081915F8: .4byte 0x030046A8
_081915FC: .4byte 0x030046AC
_08191600:
	ldr r0, _08191620 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819160E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191624
	adds r0, #4
	b _08191630
	.align 2, 0
_08191620: .4byte 0x030046A4
_08191624:
	ldr r0, _08191644 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191630:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191648
	adds r0, #4
	b _08191654
	.align 2, 0
_08191644: .4byte 0x030046A4
_08191648:
	ldr r0, _08191668 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191654:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0819166C
	cmp r2, #2
	beq _08191670
	b _08191674
	.align 2, 0
_08191668: .4byte 0x030046A4
_0819166C:
	ldrb r0, [r7, #4]
	b _08191672
_08191670:
	ldrb r0, [r7]
_08191672:
	subs r1, r1, r0
_08191674:
	movs r0, #0x40
	ands r6, r0
	cmp r6, #0
	beq _08191680
	cmp r1, #0
	bne _0819168A
_08191680:
	movs r0, #0
	strh r0, [r5, #0x10]
	strh r0, [r5, #0x14]
	movs r3, #1
	mov sl, r3
_0819168A:
	mov r4, sl
	cmp r4, #0
	beq _08191758
	ldr r1, _08191704 @ =0x00000ED5
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _08191760
	ldr r2, _08191708 @ =0x00000F45
	add r2, sb
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_0818e6fc
	mov r2, sp
	ldr r1, _0819170C @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	mov r4, r8
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r5, r4
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08191714
	ldr r0, _08191710 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08191722
	.align 2, 0
_08191704: .4byte 0x00000ED5
_08191708: .4byte 0x00000F45
_0819170C: .4byte 0x000004A4
_08191710: .4byte 0xFFFFFF00
_08191714:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08191722
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08191722:
	cmp r1, #0
	bge _08191728
	rsbs r1, r1, #0
_08191728:
	cmp r1, #0x20
	ble _08191760
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08191750 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _08191754 @ =0x0000046C
	adds r0, r5, r1
	b _0819175E
	.align 2, 0
_08191750: .4byte 0x00000469
_08191754: .4byte 0x0000046C
_08191758:
	ldr r0, _08191770 @ =0x00000ED5
	add r0, sb
	mov r2, sl
_0819175E:
	strb r2, [r0]
_08191760:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08191770: .4byte 0x00000ED5

	thumb_func_start FUN_08191774
FUN_08191774: @ 0x08191774
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov sb, r0
	adds r7, r1, #0
	adds r1, r2, #0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	cmp r1, #0
	beq _081917A6
	movs r0, #0xe5
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	bl Mod
	cmp r0, #0
	beq _081917A6
	b _081919FE
_081917A6:
	lsls r3, r7, #3
	adds r2, r3, r7
	lsls r2, r2, #3
	adds r2, r2, r7
	lsls r2, r2, #2
	add r2, sl
	ldr r1, _081917E4 @ =0x00000674
	adds r0, r2, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	ldr r0, _081917E8 @ =0x00000754
	adds r2, r2, r0
	add r5, sp, #0x38
	ldrb r6, [r2]
	ldr r2, _081917EC @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	str r3, [sp, #0x48]
	cmp r0, #0
	blt _081917F0
	asrs r1, r0, #0xc
	b _081917F6
	.align 2, 0
_081917E4: .4byte 0x00000674
_081917E8: .4byte 0x00000754
_081917EC: .4byte 0x085B0A08
_081917F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081917F6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08191814 @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _08191818
	asrs r0, r0, #0xc
	b _0819181E
	.align 2, 0
_08191814: .4byte 0x085B0A08
_08191818:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819181E:
	movs r3, #0
	strh r0, [r5, #4]
	add r1, sp, #0x38
	add r6, sp, #0x40
	ldrh r0, [r6]
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r2, _081918DC @ =0xFFFF0000
	ldr r1, _081918E0 @ =0x00000472
	add r1, sb
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x40]
	add r1, sp, #0x38
	ldrh r0, [r6, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r6, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r6, #4]
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	ldr r0, [sp, #0x48]
	adds r4, r0, r7
	lsls r4, r4, #3
	adds r4, r4, r7
	lsls r4, r4, #2
	add r4, sl
	ldr r1, _081918E4 @ =0x00000754
	adds r1, r1, r4
	mov r8, r1
	ldrb r0, [r1]
	adds r0, #0x80
	movs r5, #0xff
	ands r0, r5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x32
	str r0, [sp, #0x10]
	movs r0, #2
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r0, _081918E8 @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _081918EC @ =0x0000121B
	str r0, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	movs r0, #0xda
	str r0, [sp, #0x34]
	adds r0, r6, #0
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl FUN_081ee53c
	ldr r2, _081918F0 @ =0x00000674
	adds r4, r4, r2
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	mov r1, r8
	ldrb r0, [r1]
	adds r2, r0, #0
	adds r2, #0x40
	add r3, sp, #0x38
	ands r2, r5
	ldr r1, _081918F4 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _081918F8
	asrs r1, r0, #0xc
	b _081918FE
	.align 2, 0
_081918DC: .4byte 0xFFFF0000
_081918E0: .4byte 0x00000472
_081918E4: .4byte 0x00000754
_081918E8: .4byte 0x0000F422
_081918EC: .4byte 0x0000121B
_081918F0: .4byte 0x00000674
_081918F4: .4byte 0x085B0A08
_081918F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081918FE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0819191C @ =0x085B0A08
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _08191920
	asrs r0, r0, #0xc
	b _08191926
	.align 2, 0
_0819191C: .4byte 0x085B0A08
_08191920:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08191926:
	strh r0, [r3, #4]
	add r0, sp, #0x38
	ldrh r1, [r0]
	ldrh r0, [r6]
	adds r1, r1, r0
	add r0, sp, #0x40
	strh r1, [r0]
	ldr r1, _08191994 @ =0x00000472
	add r1, sb
	ldrh r1, [r1]
	strh r1, [r0, #2]
	add r1, sp, #0x38
	ldrh r1, [r1, #4]
	ldrh r2, [r0, #4]
	adds r1, r1, r2
	strh r1, [r0, #4]
	mov r1, sb
	ldrb r2, [r1, #5]
	movs r1, #2
	movs r3, #0
	bl FUN_08192ae0
	ldr r2, [sp, #0x48]
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, sl
	ldr r2, _08191998 @ =0x00000674
	adds r1, r0, r2
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	ldr r1, _0819199C @ =0x00000754
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r0, #0
	subs r3, #0x40
	movs r1, #0xff
	add r4, sp, #0x38
	ands r3, r1
	ldr r2, _081919A0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _081919A4
	asrs r1, r0, #0xc
	b _081919AA
	.align 2, 0
_08191994: .4byte 0x00000472
_08191998: .4byte 0x00000674
_0819199C: .4byte 0x00000754
_081919A0: .4byte 0x085B0A08
_081919A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081919AA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081919C8 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081919CC
	asrs r0, r0, #0xc
	b _081919D2
	.align 2, 0
_081919C8: .4byte 0x085B0A08
_081919CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081919D2:
	strh r0, [r4, #4]
	add r0, sp, #0x38
	ldrh r1, [r0]
	ldrh r6, [r6]
	adds r1, r1, r6
	add r0, sp, #0x40
	strh r1, [r0]
	ldr r1, _08191A10 @ =0x00000472
	add r1, sb
	ldrh r1, [r1]
	strh r1, [r0, #2]
	add r1, sp, #0x38
	ldrh r1, [r1, #4]
	ldrh r2, [r0, #4]
	adds r1, r1, r2
	strh r1, [r0, #4]
	mov r1, sb
	ldrb r2, [r1, #5]
	movs r1, #1
	movs r3, #1
	bl FUN_08192ae0
_081919FE:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08191A10: .4byte 0x00000472

	thumb_func_start FUN_08191a14
FUN_08191a14: @ 0x08191A14
	push {r4, r5, r6, lr}
	sub sp, #0x4c
	ldr r2, [r0]
	ldr r3, [r0, #4]
	str r2, [sp, #0x3c]
	str r3, [sp, #0x40]
	lsls r1, r1, #0x10
	ldr r2, _08191A88 @ =0x0000FFFF
	ldr r0, [sp, #0x3c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x3c]
	add r5, sp, #0x3c
	ldrh r1, [r5, #4]
	adds r1, #0xc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08191A8C @ =0xFFFF0000
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	add r6, sp, #0x44
	movs r4, #0
	str r4, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r6, #0
	ldr r2, _08191A90 @ =0x05000002
	bl CpuSet
	ldr r2, _08191A94 @ =0x0000F422
	ldr r3, _08191A98 @ =0x0000121B
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	movs r0, #0xda
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_081f22c0
	add sp, #0x4c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08191A88: .4byte 0x0000FFFF
_08191A8C: .4byte 0xFFFF0000
_08191A90: .4byte 0x05000002
_08191A94: .4byte 0x0000F422
_08191A98: .4byte 0x0000121B

	thumb_func_start FUN_08191a9c
FUN_08191a9c: @ 0x08191A9C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	str r0, [sp, #0x4c]
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _08191B00 @ =0x05000002
	bl CpuSet
	movs r0, #0
	mov sl, r0
	add r5, sp, #0x44
	ldr r1, _08191B04 @ =0x030046B8
	mov sb, r1
	ldr r2, _08191B08 @ =0x000003FF
	mov r8, r2
	ldr r7, _08191B0C @ =0x030046A4
_08191ACA:
	ldr r3, [sp, #0x4c]
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #0x44]
	str r1, [sp, #0x48]
	add r1, sp, #0x44
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08191AFA
	cmp r1, #0
	blt _08191AFA
	ldr r0, _08191B10 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191AFA
	ldr r0, _08191B14 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191B18
_08191AFA:
	movs r6, #0
	b _08191B24
	.align 2, 0
_08191B00: .4byte 0x05000002
_08191B04: .4byte 0x030046B8
_08191B08: .4byte 0x000003FF
_08191B0C: .4byte 0x030046A4
_08191B10: .4byte 0x030046A8
_08191B14: .4byte 0x030046AC
_08191B18:
	ldr r0, [r7]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_08191B24:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	mov r3, r8
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08191B70 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	ldrh r0, [r5]
	subs r0, #0x40
	movs r1, #0x7f
	ands r2, r1
	adds r0, r0, r2
	add r2, sp, #0x44
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	add r3, sp, #0x48
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08191B6A
	cmp r1, #0
	blt _08191B6A
	ldr r0, _08191B74 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191B6A
	ldr r0, _08191B78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191B7C
_08191B6A:
	movs r4, #0
	b _08191B88
	.align 2, 0
_08191B70: .4byte 0x0203B400
_08191B74: .4byte 0x030046A8
_08191B78: .4byte 0x030046AC
_08191B7C:
	ldr r0, [r7]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08191B88:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191B98
	adds r0, #4
	b _08191BA2
_08191B98:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08191BA2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0x46
	add r1, sp
	strh r0, [r1]
	mov r2, sb
	ldr r1, [r2]
	adds r1, #1
	mov r3, r8
	ands r1, r3
	lsls r0, r1, #1
	ldr r2, _08191C14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r3, [r0]
	add r0, sp, #0x48
	ldrh r2, [r0]
	subs r2, #0x40
	movs r0, #0x7f
	ands r3, r0
	adds r2, r2, r3
	add r3, sp, #0x48
	strh r2, [r3]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _08191C14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	subs r0, #4
	mov r3, sp
	strh r0, [r3, #0x3c]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	mov r3, sb
	str r1, [r3]
	lsls r1, r1, #1
	ldr r0, _08191C14 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	ands r0, r2
	subs r0, #4
	add r1, sp, #0x3c
	strh r0, [r1, #4]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191C18
	adds r0, #4
	b _08191C22
	.align 2, 0
_08191C14: .4byte 0x0203B400
_08191C18:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08191C22:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08191C7E
	adds r1, r5, #0
	add r2, sp, #0x3c
	ldr r3, _08191C44 @ =0x00002E78
	ldr r4, _08191C48 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	mov r0, sl
	cmp r0, #0
	bne _08191C4C
	movs r0, #0x80
	lsls r0, r0, #2
	b _08191C50
	.align 2, 0
_08191C44: .4byte 0x00002E78
_08191C48: .4byte 0x000038E2
_08191C4C:
	movs r0, #0x80
	lsls r0, r0, #3
_08191C50:
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _08191C9C @ =0x0000023B
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	adds r3, r4, #0
	bl FUN_081f22c0
_08191C7E:
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #1
	bgt _08191C8A
	b _08191ACA
_08191C8A:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08191C9C: .4byte 0x0000023B

	thumb_func_start FUN_08191ca0
FUN_08191ca0: @ 0x08191CA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x4c]
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _08191D1C @ =0x05000002
	bl CpuSet
	movs r2, #0
	mov r8, r2
	add r5, sp, #0x44
	ldr r7, _08191D20 @ =0x030046B8
	ldr r3, _08191D24 @ =0x000003FF
	mov sb, r3
_08191CD4:
	mov r1, sl
	lsls r0, r1, #3
	add r0, sl
	lsls r0, r0, #3
	add r0, sl
	lsls r0, r0, #2
	ldr r2, [sp, #0x4c]
	adds r0, r2, r0
	ldr r3, _08191D28 @ =0x00000674
	adds r0, r0, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x44]
	str r1, [sp, #0x48]
	add r1, sp, #0x44
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08191D16
	cmp r1, #0
	blt _08191D16
	ldr r0, _08191D2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191D16
	ldr r0, _08191D30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191D34
_08191D16:
	movs r6, #0
	b _08191D42
	.align 2, 0
_08191D1C: .4byte 0x05000002
_08191D20: .4byte 0x030046B8
_08191D24: .4byte 0x000003FF
_08191D28: .4byte 0x00000674
_08191D2C: .4byte 0x030046A8
_08191D30: .4byte 0x030046AC
_08191D34:
	ldr r0, _08191D8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_08191D42:
	ldr r0, [r7]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _08191D90 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xc8
	bl Mod
	ldrh r1, [r5]
	subs r1, #0x64
	adds r1, r1, r0
	add r0, sp, #0x44
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	add r1, sp, #0x48
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08191D88
	cmp r1, #0
	blt _08191D88
	ldr r0, _08191D94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191D88
	ldr r0, _08191D98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191D9C
_08191D88:
	movs r4, #0
	b _08191DAA
	.align 2, 0
_08191D8C: .4byte 0x030046A4
_08191D90: .4byte 0x0203B400
_08191D94: .4byte 0x030046A8
_08191D98: .4byte 0x030046AC
_08191D9C:
	ldr r0, _08191DBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08191DAA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191DC0
	adds r0, #4
	b _08191DCC
	.align 2, 0
_08191DBC: .4byte 0x030046A4
_08191DC0:
	ldr r0, _08191E40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191DCC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r2, #0x46
	add r2, sp
	strh r0, [r2]
	ldr r0, [r7]
	adds r0, #1
	mov r3, sb
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _08191E44 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xc8
	bl Mod
	add r2, sp, #0x48
	ldrh r1, [r2]
	subs r1, #0x64
	adds r1, r1, r0
	strh r1, [r2]
	ldr r1, [r7]
	adds r1, #1
	mov r3, sb
	ands r1, r3
	lsls r0, r1, #1
	ldr r2, _08191E44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	subs r0, #4
	mov r3, sp
	strh r0, [r3, #0x3c]
	adds r1, #1
	mov r0, sb
	ands r1, r0
	str r1, [r7]
	lsls r1, r1, #1
	ldr r3, _08191E44 @ =0x0203B400
	adds r1, r1, r3
	ldrh r0, [r1]
	ands r0, r2
	subs r0, #4
	add r1, sp, #0x3c
	strh r0, [r1, #4]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08191E48
	adds r0, #4
	b _08191E54
	.align 2, 0
_08191E40: .4byte 0x030046A4
_08191E44: .4byte 0x0203B400
_08191E48:
	ldr r0, _08191E78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191E54:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08191EC4
	adds r1, r5, #0
	add r2, sp, #0x3c
	ldr r3, _08191E7C @ =0x00002E78
	ldr r4, _08191E80 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	mov r0, r8
	cmp r0, #0
	bne _08191E84
	movs r0, #0x80
	lsls r0, r0, #2
	b _08191E88
	.align 2, 0
_08191E78: .4byte 0x030046A4
_08191E7C: .4byte 0x00002E78
_08191E80: .4byte 0x000038E2
_08191E84:
	movs r0, #0x80
	lsls r0, r0, #3
_08191E88:
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _08191E9C @ =0x0000023B
	str r0, [sp, #0xc]
	mov r0, r8
	cmp r0, #0
	bne _08191EA0
	movs r0, #2
	b _08191EA2
	.align 2, 0
_08191E9C: .4byte 0x0000023B
_08191EA0:
	movs r0, #1
_08191EA2:
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	adds r3, r4, #0
	bl FUN_081f22c0
_08191EC4:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #1
	bgt _08191ED0
	b _08191CD4
_08191ED0:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08191ee0
FUN_08191ee0: @ 0x08191EE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r2, _08192038 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _0819203C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r4, _08192040 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08192044 @ =0x000003FF
	mov sl, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r0, #4
	mov sb, r0
	str r0, [sp]
	movs r0, #0x14
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #2
	str r6, [sp, #8]
	movs r5, #1
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _08192048 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0xf0
	bl FUN_080ddcc8
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08192038: .4byte 0xFFFF0000
_0819203C: .4byte 0x0000FFFF
_08192040: .4byte 0x030046B8
_08192044: .4byte 0x000003FF
_08192048: .4byte 0x0203B400

	thumb_func_start FUN_0819204c
FUN_0819204c: @ 0x0819204C
	push {lr}
	adds r1, r0, #0
	ldr r2, _08192068 @ =0x00000544
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0819207C
	cmp r0, #0x3b
	bhi _08192070
	ldr r0, _0819206C @ =0x00000482
	adds r1, r1, r0
	movs r0, #2
	b _08192082
	.align 2, 0
_08192068: .4byte 0x00000544
_0819206C: .4byte 0x00000482
_08192070:
	ldr r2, _08192078 @ =0x00000482
	adds r1, r1, r2
	movs r0, #3
	b _08192082
	.align 2, 0
_08192078: .4byte 0x00000482
_0819207C:
	ldr r0, _08192088 @ =0x00000482
	adds r1, r1, r0
	movs r0, #1
_08192082:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08192088: .4byte 0x00000482

	thumb_func_start FUN_0819208c
FUN_0819208c: @ 0x0819208C
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r4, [r1]
	adds r2, #0x8a
	adds r1, r0, r2
	ldr r0, _081920BC @ =0x00000EDC
	adds r2, r4, r0
	movs r3, #5
_081920A0:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _081920A0
	ldr r2, _081920C0 @ =0x00000ED4
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081920BC: .4byte 0x00000EDC
_081920C0: .4byte 0x00000ED4

	thumb_func_start FUN_081920c4
FUN_081920c4: @ 0x081920C4
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r3, #0
	ldr r4, _081920E0 @ =0x00000EDC
	adds r2, r0, r4
_081920D4:
	ldrh r0, [r2]
	cmp r0, r1
	bne _081920E4
	movs r0, #1
	b _081920EE
	.align 2, 0
_081920E0: .4byte 0x00000EDC
_081920E4:
	adds r2, #2
	adds r3, #1
	cmp r3, #5
	ble _081920D4
	movs r0, #0
_081920EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081920f4
FUN_081920f4: @ 0x081920F4
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r4, _08192120 @ =0x00000ED4
	adds r3, r2, r4
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r4, #8
	adds r2, r2, r4
	adds r2, r2, r0
	strh r1, [r2]
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08192120: .4byte 0x00000ED4

	thumb_func_start FUN_08192124
FUN_08192124: @ 0x08192124
	push {r4, r5, r6, lr}
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r0, r3
	movs r3, #0
	strb r3, [r1]
	ldr r4, _08192178 @ =0x00000469
	adds r1, r0, r4
	strb r2, [r1]
	ldr r6, _0819217C @ =0x0000046A
	adds r1, r0, r6
	strb r3, [r1]
	ldr r2, _08192180 @ =0x00000484
	adds r1, r0, r2
	str r3, [r1]
	adds r4, #3
	adds r1, r0, r4
	movs r2, #1
	strb r2, [r1]
	ldr r5, _08192184 @ =FUN_080e48d0
	movs r4, #0x10
	adds r6, #3
	adds r1, r0, r6
	strb r2, [r1]
	ldr r2, _08192188 @ =0x0000046B
	adds r1, r0, r2
	strb r3, [r1]
	adds r6, #0xe6
	adds r1, r0, r6
	strb r4, [r1]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r0, r2
	str r5, [r1]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r0, r4
	strh r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08192178: .4byte 0x00000469
_0819217C: .4byte 0x0000046A
_08192180: .4byte 0x00000484
_08192184: .4byte FUN_080e48d0
_08192188: .4byte 0x0000046B

	thumb_func_start FUN_0819218c
FUN_0819218c: @ 0x0819218C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08192190
FUN_08192190: @ 0x08192190
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0819226C
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	ldr r2, _081921C4 @ =0x00000553
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0x26
	bne _081921C8
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	lsls r1, r0, #1
	b _081921D0
	.align 2, 0
_081921C4: .4byte 0x00000553
_081921C8:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
_081921D0:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, r1
	bhi _0819226C
	mov r5, sp
	adds r3, r4, #0
	adds r3, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #4
	ldrsh r1, [r5, r3]
	bl FUN_0823785c
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	ldrb r1, [r4, #5]
	adds r1, #0x10
	ands r1, r3
	asrs r1, r1, #6
	cmp r0, r1
	bne _0819226C
	movs r0, #2
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _08192234
	rsbs r1, r1, #0
_08192234:
	ldr r0, _08192260 @ =0x000001FF
	cmp r1, r0
	bgt _0819226C
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r1, #0x30
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x80
	ands r0, r3
	asrs r0, r0, #6
	ldr r3, _08192264 @ =0x00000F45
	adds r1, r2, r3
	strb r0, [r1]
	ldr r0, _08192268 @ =0x00000F44
	adds r2, r2, r0
	movs r0, #0xe
	strb r0, [r2]
	movs r0, #1
	b _0819226E
	.align 2, 0
_08192260: .4byte 0x000001FF
_08192264: .4byte 0x00000F45
_08192268: .4byte 0x00000F44
_0819226C:
	movs r0, #0
_0819226E:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08192278
FUN_08192278: @ 0x08192278
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08192352
	movs r2, #0x20
	ldr r3, _081922A8 @ =0x00000F2C
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081922AC
	movs r0, #1
	b _081922AE
	.align 2, 0
_081922A8: .4byte 0x00000F2C
_081922AC:
	movs r0, #0
_081922AE:
	cmp r0, #0
	bne _08192352
	ldr r1, _081922D0 @ =0x0000A027
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08192352
	movs r1, #4
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081922D4
	movs r0, #1
	b _081922D6
	.align 2, 0
_081922D0: .4byte 0x0000A027
_081922D4:
	movs r0, #0
_081922D6:
	cmp r0, #0
	beq _0819231C
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _08192310 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	ldr r2, _08192314 @ =0x00000226
	adds r1, r4, r2
	ldrh r1, [r1]
	ldr r3, _08192318 @ =0x0000022E
	adds r2, r4, r3
	ldrh r2, [r2]
	movs r5, #0x90
	lsls r5, r5, #2
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #0xa
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	b _08192352
	.align 2, 0
_08192310: .4byte 0xFFFFFEFF
_08192314: .4byte 0x00000226
_08192318: .4byte 0x0000022E
_0819231C:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	subs r1, #0x28
	ldrh r2, [r0, #6]
	orrs r1, r2
	strh r1, [r0, #6]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrh r2, [r2]
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #8
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
_08192352:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0819235c
FUN_0819235c: @ 0x0819235C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r6, #0
	movs r1, #1
	mov r8, r1
	movs r1, #0x80
	mov ip, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, _08192394 @ =0x0000077A
	adds r4, r0, r1
	movs r7, #0x92
	lsls r7, r7, #1
	movs r5, #5
_08192386:
	ldrh r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08192398
	movs r0, #1
	b _0819239A
	.align 2, 0
_08192394: .4byte 0x0000077A
_08192398:
	movs r0, #0
_0819239A:
	cmp r0, #0
	bne _081923C8
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081923B0
	subs r0, #1
	strh r0, [r1]
	b _081923C8
_081923B0:
	cmp r6, #1
	bgt _081923C8
	movs r0, #2
	strh r0, [r1]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r2, r3, r1
	ldrh r1, [r2]
	mov r0, ip
	orrs r0, r1
	strh r0, [r2]
	adds r6, #1
_081923C8:
	adds r3, r3, r7
	adds r4, r4, r7
	subs r5, #1
	cmp r5, #0
	bge _08192386
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081923e0
FUN_081923e0: @ 0x081923E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819242E
	movs r1, #0x30
	ldr r2, [sp, #0x10]
	ldr r3, _08192418 @ =0x00000F2C
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819241C
	movs r0, #1
	b _0819241E
	.align 2, 0
_08192418: .4byte 0x00000F2C
_0819241C:
	movs r0, #0
_0819241E:
	cmp r0, #0
	bne _0819242E
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08192458
_0819242E:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r5, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _08192454 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	b _0819247E
	.align 2, 0
_08192454: .4byte 0x00000474
_08192458:
	movs r2, #0x94
	lsls r2, r2, #1
	adds r3, r5, r2
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r5, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldr r3, _081924CC @ =0x00000474
	adds r2, r5, r3
	ldr r0, _081924D0 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
_0819247E:
	strh r0, [r2]
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, [sp, #0x10]
	ldr r2, _081924D4 @ =0x00000F36
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #0x14]
	cmp r1, r0
	blt _08192496
	b _08192668
_08192496:
	add r2, sp, #8
	mov sb, r2
	ldr r3, [sp, #0x10]
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r4, r3, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r7, r3, r1
	ldr r2, _081924D8 @ =0x00000674
	adds r2, r3, r2
	str r2, [sp, #0x18]
	adds r0, #0x50
	adds r6, r3, r0
	ldr r1, _081924DC @ =0x0000077A
	adds r1, r3, r1
	str r1, [sp, #0x1c]
	mov r8, r7
_081924BA:
	movs r1, #0x80
	ldr r2, [sp, #0x1c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081924E0
	movs r0, #1
	b _081924E2
	.align 2, 0
_081924CC: .4byte 0x00000474
_081924D0: .4byte 0xFFFFF7FF
_081924D4: .4byte 0x00000F36
_081924D8: .4byte 0x00000674
_081924DC: .4byte 0x0000077A
_081924E0:
	movs r0, #0
_081924E2:
	cmp r0, #0
	bne _081924F6
	ldrh r0, [r4, #6]
	movs r3, #4
	orrs r0, r3
	strh r0, [r4, #6]
	ldrh r0, [r6, #6]
	orrs r0, r3
	strh r0, [r6, #6]
	b _08192638
_081924F6:
	mov r0, r8
	adds r0, #0x98
	mov r1, r8
	adds r1, #0x1c
	movs r2, #0
	bl FUN_082364c4
	mov r1, r8
	ldr r0, [r1]
	ldr r1, _08192528 @ =0x00000201
	ands r0, r1
	cmp r0, #0
	bne _08192536
	movs r2, #0x20
	ldr r3, [sp, #0x10]
	ldr r0, _0819252C @ =0x00000F2C
	adds r1, r3, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08192530
	movs r0, #1
	b _08192532
	.align 2, 0
_08192528: .4byte 0x00000201
_0819252C: .4byte 0x00000F2C
_08192530:
	movs r0, #0
_08192532:
	cmp r0, #0
	beq _08192540
_08192536:
	ldrh r0, [r6, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r6, #6]
	b _08192638
_08192540:
	movs r2, #4
	mvns r3, r2
	ldrh r1, [r6, #6]
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r6, #6]
	ldr r0, _081925BC @ =0x03002BE0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	mov r1, sb
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #0x1e]
	subs r0, r0, r1
	mov r1, sb
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #0x20]
	subs r0, r0, r1
	mov r2, sb
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	mov ip, r2
	mov r1, sb
	movs r2, #4
	ldrsh r0, [r1, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, ip
	adds r1, r2, r0
	ldr r0, _081925C0 @ =0x0000FFFF
	cmp r1, r0
	bgt _08192638
	ldrh r0, [r4, #6]
	adds r1, r3, #0
	ands r1, r0
	strh r1, [r4, #6]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	mov r3, sl
	ldrh r0, [r3]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081925C4
	movs r0, #1
	b _081925C6
	.align 2, 0
_081925BC: .4byte 0x03002BE0
_081925C0: .4byte 0x0000FFFF
_081925C4:
	movs r0, #0
_081925C6:
	cmp r0, #0
	beq _08192604
	ldr r0, _081925F8 @ =0xFFFFFEFF
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	ldr r2, _081925FC @ =0x00000226
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08192600 @ =0x0000022E
	adds r0, r5, r3
	ldrh r2, [r0]
	adds r3, #0x12
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xa
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	b _08192638
	.align 2, 0
_081925F8: .4byte 0xFFFFFEFF
_081925FC: .4byte 0x00000226
_08192600: .4byte 0x0000022E
_08192604:
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r4, #6]
	orrs r0, r1
	strh r0, [r4, #6]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
_08192638:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r7, r7, r0
	add r8, r0
	ldr r1, [sp, #0x18]
	adds r1, r1, r0
	str r1, [sp, #0x18]
	adds r6, r6, r0
	ldr r2, [sp, #0x1c]
	adds r2, r2, r0
	str r2, [sp, #0x1c]
	ldr r3, [sp, #0x14]
	adds r3, #1
	str r3, [sp, #0x14]
	ldr r1, [sp, #0x10]
	ldr r2, _08192678 @ =0x00000F36
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #0x14]
	cmp r1, r0
	bge _08192668
	b _081924BA
_08192668:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08192678: .4byte 0x00000F36

	thumb_func_start FUN_0819267c
FUN_0819267c: @ 0x0819267C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _081926BC
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	movs r2, #8
	ldrsh r0, [r5, r2]
	movs r3, #0xc
	ldrsh r1, [r5, r3]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	adds r4, #0x1d
	adds r3, r5, r4
	ldrb r3, [r3]
	ldrh r4, [r5]
	str r4, [sp]
	bl FUN_08240dc8
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	bge _081926C0
_081926BC:
	movs r0, #0
	b _08192722
_081926C0:
	adds r0, r5, #0
	bl FUN_080e8f20
	ldr r1, _0819272C @ =0x00000D4F
	adds r0, r7, r1
	strb r6, [r0]
	movs r1, #0x17
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08192730 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _08192734 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _08192738 @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0819273C @ =FUN_080e48d0
	movs r2, #0x10
	adds r4, #3
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _08192740 @ =0x0000046B
	adds r0, r5, r1
	strb r6, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	adds r0, r5, #0
	bl FUN_0819394c
	bl FUN_080df478
	movs r0, #1
_08192722:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0819272C: .4byte 0x00000D4F
_08192730: .4byte 0x00000469
_08192734: .4byte 0x0000046A
_08192738: .4byte 0x00000484
_0819273C: .4byte FUN_080e48d0
_08192740: .4byte 0x0000046B

	thumb_func_start FUN_08192744
FUN_08192744: @ 0x08192744
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x40
	movs r1, #0x91
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, _08192770 @ =0x00000103
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08192770: .4byte 0x00000103

	thumb_func_start FUN_08192774
FUN_08192774: @ 0x08192774
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r2, #0
	str r2, [sp, #4]
	ldr r4, _081927D0 @ =0x00000F36
	adds r0, r6, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	blt _0819279C
	b _081928C6
_0819279C:
	ldr r2, _081927D4 @ =0x00000676
	adds r2, r2, r6
	mov r8, r2
	str r6, [sp, #8]
	movs r3, #0
	ldr r4, _081927D8 @ =0x00000734
	adds r5, r6, r4
	ldr r0, _081927DC @ =0x0000075B
	adds r7, r6, r0
	str r7, [sp, #0xc]
	ldr r1, _081927E0 @ =0x0000077A
	adds r1, r1, r6
	mov sl, r1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r6
	mov sb, r2
_081927BE:
	mov r4, sl
	ldrh r0, [r4]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081927E4
	movs r0, #1
	b _081927E6
	.align 2, 0
_081927D0: .4byte 0x00000F36
_081927D4: .4byte 0x00000676
_081927D8: .4byte 0x00000734
_081927DC: .4byte 0x0000075B
_081927E0: .4byte 0x0000077A
_081927E4:
	movs r0, #0
_081927E6:
	cmp r0, #0
	beq _0819281C
	ldrb r0, [r7]
	adds r4, r0, #0
	cmp r4, #0
	beq _081927F8
	subs r0, #1
	strb r0, [r7]
	b _0819281C
_081927F8:
	adds r0, r3, r6
	ldr r2, _08192850 @ =0x00000684
	adds r0, r0, r2
	ldr r1, _08192854 @ =0x000001A3
	str r3, [sp, #0x10]
	bl FUN_0822b20c
	ldr r0, [sp, #0xc]
	strb r4, [r0]
	ldr r1, [sp, #8]
	ldr r4, _08192858 @ =0x0000077A
	adds r2, r1, r4
	ldrh r1, [r2]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r2]
	ldr r3, [sp, #0x10]
_0819281C:
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08192898
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08192860
	mov r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r4, [sp]
	ldr r2, _0819285C @ =0x00000472
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _0819286C
	mov r4, sb
	adds r0, r4, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0819286A
	.align 2, 0
_08192850: .4byte 0x00000684
_08192854: .4byte 0x000001A3
_08192858: .4byte 0x0000077A
_0819285C: .4byte 0x00000472
_08192860:
	mov r1, sb
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0819286A:
	str r1, [r0]
_0819286C:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08192898
	mov r2, r8
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r2, [sp]
	ldr r4, _081928D8 @ =0x00000472
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r1, r0
	blt _08192898
	mov r1, sb
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_08192898:
	movs r2, #0x92
	lsls r2, r2, #1
	add r8, r2
	ldr r4, [sp, #8]
	adds r4, r4, r2
	str r4, [sp, #8]
	adds r3, r3, r2
	adds r5, r5, r2
	adds r7, r7, r2
	ldr r0, [sp, #0xc]
	adds r0, r0, r2
	str r0, [sp, #0xc]
	add sl, r2
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	ldr r2, _081928DC @ =0x00000F36
	adds r0, r6, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081928C6
	b _081927BE
_081928C6:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081928D8: .4byte 0x00000472
_081928DC: .4byte 0x00000F36

	thumb_func_start FUN_081928e0
FUN_081928e0: @ 0x081928E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _0819291C @ =0x00000553
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _081929B8
	movs r7, #0xa
	ldrsh r1, [r3, r7]
	subs r2, #0xe1
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _08192910
	cmp r0, #0
	bne _08192920
_08192910:
	ldr r0, [r3, #0x44]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08192936
	.align 2, 0
_0819291C: .4byte 0x00000553
_08192920:
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r0, r3, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _08192938
	ldr r0, [r3, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08192936:
	str r1, [r0]
_08192938:
	movs r4, #0
	ldr r0, _08192974 @ =0x00000F36
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r4, r0
	bge _081929B8
	movs r7, #1
	mov sl, r7
	ldr r0, _08192978 @ =0x00000472
	adds r0, r0, r3
	mov sb, r0
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r5
	mov r8, r2
	adds r2, r5, #0
	movs r6, #0
	ldr r7, _0819297C @ =0x0000077A
	adds r3, r2, r7
	movs r5, #0x92
	lsls r5, r5, #1
	mov ip, r1
_08192966:
	ldrh r0, [r3]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _08192980
	movs r0, #1
	b _08192982
	.align 2, 0
_08192974: .4byte 0x00000F36
_08192978: .4byte 0x00000472
_0819297C: .4byte 0x0000077A
_08192980:
	movs r0, #0
_08192982:
	cmp r0, #0
	bne _081929A6
	ldr r7, _081929C8 @ =0x00000676
	adds r0, r2, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r7, sb
	ldrh r1, [r7]
	cmp r0, r1
	blt _0819299A
	cmp r1, #0
	bne _081929A6
_0819299A:
	mov r0, r8
	adds r1, r0, r6
	ldr r0, [r1]
	mov r7, sl
	orrs r0, r7
	str r0, [r1]
_081929A6:
	adds r2, r2, r5
	adds r6, r6, r5
	adds r3, r3, r5
	adds r4, #1
	mov r1, ip
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r4, r0
	blt _08192966
_081929B8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081929C8: .4byte 0x00000676

	thumb_func_start FUN_081929cc
FUN_081929cc: @ 0x081929CC
	push {r4, lr}
	sub sp, #0xc
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r2, _08192A0C @ =0x00000EC8
	adds r4, r0, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _08192A04
	ldrh r0, [r1]
	str r0, [sp]
	ldr r1, _08192A10 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r4]
	bl Script_ExecById
	movs r0, #0
	strh r0, [r4]
_08192A04:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08192A0C: .4byte 0x00000EC8
_08192A10: .4byte 0xFFFF0000

	thumb_func_start FUN_08192a14
FUN_08192a14: @ 0x08192A14
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r2, _08192A6C @ =0x00000546
	adds r1, r0, r2
	ldrh r1, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt _08192A88
	movs r0, #0xd5
	lsls r0, r0, #4
	adds r1, r3, r0
	movs r0, #0x28
	strh r0, [r1]
	ldr r2, _08192A70 @ =0x00000D52
	adds r1, r3, r2
	movs r0, #0x64
	strh r0, [r1]
	ldr r2, _08192A74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08192A78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08192A7C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x50
	ldr r2, _08192A80 @ =0x00000D54
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _08192A84 @ =0x00000D56
	adds r1, r3, r0
	movs r0, #1
	b _08192AC0
	.align 2, 0
_08192A6C: .4byte 0x00000546
_08192A70: .4byte 0x00000D52
_08192A74: .4byte 0x030046B8
_08192A78: .4byte 0x000003FF
_08192A7C: .4byte 0x0203B400
_08192A80: .4byte 0x00000D54
_08192A84: .4byte 0x00000D56
_08192A88:
	movs r2, #0xd5
	lsls r2, r2, #4
	adds r1, r3, r2
	movs r0, #0x50
	strh r0, [r1]
	ldr r0, _08192AC8 @ =0x00000D52
	adds r1, r3, r0
	movs r0, #0xc8
	strh r0, [r1]
	ldr r2, _08192ACC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08192AD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08192AD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0xa0
	ldr r2, _08192AD8 @ =0x00000D54
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _08192ADC @ =0x00000D56
	adds r1, r3, r0
	movs r0, #3
_08192AC0:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08192AC8: .4byte 0x00000D52
_08192ACC: .4byte 0x030046B8
_08192AD0: .4byte 0x000003FF
_08192AD4: .4byte 0x0203B400
_08192AD8: .4byte 0x00000D54
_08192ADC: .4byte 0x00000D56

	thumb_func_start FUN_08192ae0
FUN_08192ae0: @ 0x08192AE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	mov sl, r0
	str r1, [sp, #0x38]
	mov sb, r3
	movs r1, #0
	ldr r0, [sp, #0x38]
	cmp r1, r0
	bge _08192BDC
	movs r0, #0x40
	adds r0, r0, r2
	mov r8, r0
	adds r7, r2, #0
	subs r7, #0x40
	movs r5, #0
	movs r6, #2
_08192B08:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08192B78
	mov r0, sb
	cmp r0, #0
	beq _08192B22
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	add r0, r8
	b _08192B2C
_08192B22:
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r0, r7, r0
_08192B2C:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r4, r1, #0
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	str r2, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x32
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r5, [sp, #0x20]
	ldr r0, _08192B70 @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _08192B74 @ =0x0000121B
	str r0, [sp, #0x28]
	str r5, [sp, #0x2c]
	str r5, [sp, #0x30]
	movs r0, #0xda
	str r0, [sp, #0x34]
	mov r0, sl
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl FUN_081ee53c
	b _08192BD4
	.align 2, 0
_08192B70: .4byte 0x0000F422
_08192B74: .4byte 0x0000121B
_08192B78:
	mov r0, sb
	cmp r0, #0
	beq _08192B8A
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	add r0, r8
	b _08192B94
_08192B8A:
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r0, r7, r0
_08192B94:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r4, r1, #0
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r2, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x32
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #0x1c]
	str r5, [sp, #0x20]
	ldr r0, _08192BEC @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _08192BF0 @ =0x0000121B
	str r0, [sp, #0x28]
	str r5, [sp, #0x2c]
	str r5, [sp, #0x30]
	movs r0, #0xda
	str r0, [sp, #0x34]
	mov r0, sl
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl FUN_081ee53c
_08192BD4:
	adds r1, r4, #0
	ldr r0, [sp, #0x38]
	cmp r1, r0
	blt _08192B08
_08192BDC:
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08192BEC: .4byte 0x0000F422
_08192BF0: .4byte 0x0000121B

	thumb_func_start FUN_08192bf4
FUN_08192bf4: @ 0x08192BF4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x80
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x60]
	ldr r0, _08192CE4 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _08192CE8 @ =0x00003460
	adds r2, r0, r2
	str r2, [sp, #0x68]
	movs r3, #0xd4
	lsls r3, r3, #6
	adds r3, r0, r3
	str r3, [sp, #0x64]
	mov r0, sp
	adds r0, #0x20
	str r0, [sp, #0x70]
	mov r1, sp
	adds r1, #0x40
	str r1, [sp, #0x78]
	movs r2, #0x1f
	mov sl, r2
	mov sb, r1
	mov r8, r0
	mov r6, sp
	ldr r5, [sp, #0x68]
	adds r4, r3, #0
	movs r7, #0xf
_08192C38:
	ldrh r2, [r4]
	movs r1, #0x1f
	adds r0, r1, #0
	ands r0, r2
	ldrh r2, [r5]
	ands r1, r2
	subs r0, r0, r1
	lsls r0, r0, #5
	strh r0, [r6]
	ldrh r1, [r4]
	lsrs r1, r1, #5
	mov r3, sl
	ands r1, r3
	ldrh r0, [r5]
	lsrs r0, r0, #5
	ands r0, r3
	subs r1, r1, r0
	lsls r1, r1, #5
	mov r0, r8
	strh r1, [r0]
	ldrh r1, [r4]
	lsrs r1, r1, #0xa
	ands r1, r3
	ldrh r0, [r5]
	lsrs r0, r0, #0xa
	ands r0, r3
	subs r1, r1, r0
	lsls r1, r1, #5
	mov r2, sb
	strh r1, [r2]
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl Div
	strh r0, [r6]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl Div
	mov r3, r8
	strh r0, [r3]
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl Div
	mov r3, sb
	strh r0, [r3]
	movs r0, #2
	add sb, r0
	add r8, r0
	adds r6, #2
	adds r5, #2
	adds r4, #2
	subs r7, #1
	cmp r7, #0
	bge _08192C38
	movs r7, #0
	ldr r2, _08192CEC @ =0x00000E48
	ldr r1, [sp, #0x60]
	adds r2, r1, r2
	str r2, [sp, #0x6c]
_08192CBC:
	adds r3, r7, #1
	mov sl, r3
	lsls r0, r7, #5
	str r0, [sp, #0x74]
	lsls r0, r3, #1
	add r0, sl
	mov r8, r0
	ldr r5, [sp, #0x68]
	movs r6, #0
	mov r7, sp
_08192CD0:
	movs r1, #0
	ldrsh r0, [r7, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08192CF0
	asrs r0, r0, #5
	b _08192CF6
	.align 2, 0
_08192CE4: .4byte 0x03003584
_08192CE8: .4byte 0x00003460
_08192CEC: .4byte 0x00000E48
_08192CF0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_08192CF6:
	mov sb, r0
	ldr r3, [sp, #0x70]
	adds r0, r3, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08192D0E
	asrs r0, r0, #5
	b _08192D14
_08192D0E:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_08192D14:
	mov ip, r0
	ldr r3, [sp, #0x78]
	adds r0, r3, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08192D2C
	asrs r4, r0, #5
	b _08192D32
_08192D2C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r4, r0, #0
_08192D32:
	ldr r0, [sp, #0x74]
	adds r3, r6, r0
	ldr r1, [sp, #0x6c]
	adds r3, r1, r3
	str r3, [sp, #0x7c]
	ldrh r1, [r5]
	movs r2, #0x1f
	ands r2, r1
	add r2, sb
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	movs r3, #0x1f
	ands r0, r3
	add r0, ip
	lsls r0, r0, #5
	orrs r2, r0
	lsrs r1, r1, #0x1a
	ands r1, r3
	adds r1, r1, r4
	lsls r1, r1, #0xa
	orrs r2, r1
	ldr r0, [sp, #0x7c]
	strh r2, [r0]
	adds r5, #2
	adds r6, #2
	adds r7, #2
	ldr r0, [sp, #0x68]
	adds r0, #0x1e
	cmp r5, r0
	ble _08192CD0
	mov r7, sl
	cmp r7, #1
	ble _08192CBC
	ldr r2, [sp, #0x64]
	ldr r3, [sp, #0x60]
	ldr r0, _08192DA8 @ =0x00000E88
	adds r1, r3, r0
	movs r3, #0xf
_08192D7E:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08192D7E
	ldr r1, [sp, #0x60]
	ldr r2, _08192DAC @ =0x00000EA8
	adds r0, r1, r2
	movs r1, #0x20
	bl ClearMemory
	add sp, #0x80
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08192DA8: .4byte 0x00000E88
_08192DAC: .4byte 0x00000EA8

	thumb_func_start FUN_08192db0
FUN_08192db0: @ 0x08192DB0
	push {r4, r5, r6, lr}
	adds r3, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r6, _08192DE0 @ =0x00000D58
	adds r5, r4, r6
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	subs r1, #0xcc
	ldr r6, _08192DE4 @ =0x0000077A
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08192DE8
	movs r0, #1
	b _08192DEA
	.align 2, 0
_08192DE0: .4byte 0x00000D58
_08192DE4: .4byte 0x0000077A
_08192DE8:
	movs r0, #0
_08192DEA:
	cmp r0, #0
	beq _08192E1C
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, _08192E10 @ =0x0000068A
	adds r1, r1, r2
	ldr r2, _08192E14 @ =0x000001AD
	strh r2, [r1]
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r4, r6
	adds r1, r1, r0
	ldr r2, _08192E18 @ =0x00000EA8
	b _08192ED6
	.align 2, 0
_08192E10: .4byte 0x0000068A
_08192E14: .4byte 0x000001AD
_08192E18: .4byte 0x00000EA8
_08192E1C:
	ldr r6, _08192E4C @ =0x00000F36
	adds r0, r4, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	subs r0, r1, #1
	cmp r3, r0
	bne _08192E58
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, _08192E50 @ =0x0000068A
	adds r1, r1, r2
	movs r2, #0xd6
	lsls r2, r2, #1
	strh r2, [r1]
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r4, r6
	adds r1, r1, r0
	ldr r2, _08192E54 @ =0x00000E88
	b _08192ED6
	.align 2, 0
_08192E4C: .4byte 0x00000F36
_08192E50: .4byte 0x0000068A
_08192E54: .4byte 0x00000E88
_08192E58:
	subs r0, r1, #2
	cmp r3, r0
	bne _08192E90
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r6, _08192E84 @ =0x0000068A
	adds r1, r1, r6
	ldr r2, _08192E88 @ =0x000001AB
	strh r2, [r1]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r4, r2
	adds r1, r1, r0
	ldr r6, _08192E8C @ =0x00000E68
	adds r0, r4, r6
	str r0, [r1]
	b _08192F56
	.align 2, 0
_08192E84: .4byte 0x0000068A
_08192E88: .4byte 0x000001AB
_08192E8C: .4byte 0x00000E68
_08192E90:
	subs r0, r1, #3
	cmp r3, r0
	bne _08192EE4
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r6, _08192EAC @ =0x00000F2C
	adds r0, r4, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08192EB0
	movs r0, #1
	b _08192EB2
	.align 2, 0
_08192EAC: .4byte 0x00000F2C
_08192EB0:
	movs r0, #0
_08192EB2:
	cmp r0, #0
	bne _08192EE4
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, _08192EDC @ =0x0000068A
	adds r1, r1, r2
	movs r2, #0xd5
	lsls r2, r2, #1
	strh r2, [r1]
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r4, r6
	adds r1, r1, r0
	ldr r2, _08192EE0 @ =0x00000E48
_08192ED6:
	adds r0, r4, r2
	str r0, [r1]
	b _08192F56
	.align 2, 0
_08192EDC: .4byte 0x0000068A
_08192EE0: .4byte 0x00000E48
_08192EE4:
	cmp r2, #1
	beq _08192F20
	cmp r2, #1
	bgt _08192EF2
	cmp r2, #0
	beq _08192EF8
	b _08192F56
_08192EF2:
	cmp r2, #2
	beq _08192F40
	b _08192F56
_08192EF8:
	lsls r1, r3, #3
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r6, _08192F18 @ =0x0000068A
	adds r0, r0, r6
	ldr r2, _08192F1C @ =0x000001A9
	strh r2, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r0, r4, r2
	adds r0, r0, r1
	str r5, [r0]
	b _08192F56
	.align 2, 0
_08192F18: .4byte 0x0000068A
_08192F1C: .4byte 0x000001A9
_08192F20:
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r6, _08192F3C @ =0x00000684
	adds r0, r0, r6
	movs r1, #0xd4
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _08192F56
	.align 2, 0
_08192F3C: .4byte 0x00000684
_08192F40:
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, _08192F5C @ =0x00000684
	adds r0, r0, r1
	ldr r1, _08192F60 @ =0x000001A3
	bl FUN_0822b20c
_08192F56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08192F5C: .4byte 0x00000684
_08192F60: .4byte 0x000001A3

	thumb_func_start FUN_08192f64
FUN_08192f64: @ 0x08192F64
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	subs r1, #0xcc
	ldr r3, _08192F84 @ =0x00000F2C
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08192F88
	movs r0, #1
	b _08192F8A
	.align 2, 0
_08192F84: .4byte 0x00000F2C
_08192F88:
	movs r0, #0
_08192F8A:
	cmp r0, #0
	beq _08192FB8
	movs r4, #0
	ldr r0, _08192FB4 @ =0x0000075B
	adds r5, r2, r0
_08192F94:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08192FA4
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08192db0
_08192FA4:
	movs r1, #0x92
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r4, #1
	cmp r4, #5
	ble _08192F94
	b _08192FDA
	.align 2, 0
_08192FB4: .4byte 0x0000075B
_08192FB8:
	movs r4, #0
	ldr r3, _08192FE0 @ =0x0000075B
	adds r5, r2, r3
_08192FBE:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08192FCE
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #2
	bl FUN_08192db0
_08192FCE:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	ble _08192FBE
_08192FDA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08192FE0: .4byte 0x0000075B

	thumb_func_start FUN_08192fe4
FUN_08192fe4: @ 0x08192FE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r3, [sp]
	str r0, [sp, #4]
	ldr r3, _081930F4 @ =0x00000D58
	adds r7, r0, r3
	ldr r0, _081930F8 @ =0x03003584
	lsls r3, r1, #5
	ldr r0, [r0]
	lsls r2, r2, #5
	adds r2, r0, r2
	str r2, [sp, #8]
	strh r1, [r7, #0x22]
	movs r1, #0
	str r1, [sp, #0xc]
	adds r0, r0, r3
	mov sl, r0
_0819300E:
	ldr r3, [sp, #0xc]
	lsls r2, r3, #1
	ldr r1, [sp, #8]
	adds r0, r2, r1
	ldrh r4, [r0]
	movs r3, #0x84
	adds r3, r3, r7
	mov r8, r3
	add r8, r2
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	mov sb, r4
	mov r1, sb
	movs r3, #0x1f
	ands r1, r3
	mov sb, r1
	subs r0, r0, r1
	lsls r0, r0, #5
	mov r1, r8
	strh r0, [r1]
	adds r6, r7, #0
	adds r6, #0xa4
	adds r6, r6, r2
	mov r3, sl
	ldrh r0, [r3]
	lsrs r0, r0, #5
	movs r1, #0x1f
	ands r0, r1
	asrs r3, r4, #5
	ands r3, r1
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0xc4
	adds r5, r5, r2
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r4, r4, #0xa
	ands r4, r1
	subs r0, r0, r4
	lsls r0, r0, #5
	strh r0, [r5]
	mov r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov ip, r0
	ldr r1, [sp]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	bl Div
	mov r1, r8
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r5, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r5]
	adds r0, r7, #0
	adds r0, #0x24
	ldr r2, [sp, #0x10]
	adds r0, r0, r2
	mov r1, sb
	lsls r1, r1, #5
	strh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	adds r0, r0, r2
	ldr r3, [sp, #0x14]
	lsls r3, r3, #5
	strh r3, [r0]
	adds r0, r7, #0
	adds r0, #0x64
	adds r0, r0, r2
	lsls r4, r4, #5
	strh r4, [r0]
	movs r3, #2
	add sl, r3
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0xf
	ble _0819300E
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r7, #0x20]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r3, [sp, #4]
	ldr r1, _081930FC @ =0x00000F2C
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081930F4: .4byte 0x00000D58
_081930F8: .4byte 0x03003584
_081930FC: .4byte 0x00000F2C

	thumb_func_start FUN_08193100
FUN_08193100: @ 0x08193100
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819311A
	b _0819326C
_0819311A:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r3, _08193138 @ =0x00000F2C
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819313C
	movs r0, #1
	b _0819313E
	.align 2, 0
_08193138: .4byte 0x00000F2C
_0819313C:
	movs r0, #0
_0819313E:
	cmp r0, #0
	bne _08193144
	b _0819326C
_08193144:
	ldr r0, _08193174 @ =0x00000D58
	adds r0, r0, r2
	mov ip, r0
	ldrh r0, [r0, #0x20]
	cmp r0, #0
	bne _08193180
	ldr r1, _08193178 @ =0x02008000
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08193162
	b _08193278
_08193162:
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, _0819317C @ =0x000001A9
	strh r1, [r0, #0x32]
	mov r2, r8
	ldr r0, [r2, #0x44]
	mov r3, ip
	str r3, [r0, #0x38]
	b _08193278
	.align 2, 0
_08193174: .4byte 0x00000D58
_08193178: .4byte 0x02008000
_0819317C: .4byte 0x000001A9
_08193180:
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	str r0, [sp]
	ldr r1, _081931E0 @ =0x00000D7C
	adds r1, r2, r1
	str r1, [sp, #4]
	ldr r3, _081931E4 @ =0x00000DDC
	adds r3, r2, r3
	str r3, [sp, #8]
	ldr r0, _081931E8 @ =0x00000DFC
	adds r0, r0, r2
	mov sl, r0
	ldr r1, _081931EC @ =0x00000E1C
	adds r1, r1, r2
	mov sb, r1
	mov r5, ip
	ldr r3, _081931F0 @ =0x00000DBC
	adds r4, r2, r3
	movs r7, #0
	ldr r0, _081931F4 @ =0x00000D9C
	adds r3, r2, r0
_081931AC:
	ldr r2, [sp, #4]
	adds r1, r2, r7
	ldr r2, [sp, #8]
	adds r0, r2, r7
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	mov r2, sl
	adds r0, r2, r7
	ldrh r0, [r0]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	mov r2, sb
	adds r0, r2, r7
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _081931F8
	asrs r0, r0, #5
	b _081931FE
	.align 2, 0
_081931E0: .4byte 0x00000D7C
_081931E4: .4byte 0x00000DDC
_081931E8: .4byte 0x00000DFC
_081931EC: .4byte 0x00000E1C
_081931F0: .4byte 0x00000DBC
_081931F4: .4byte 0x00000D9C
_081931F8:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081931FE:
	adds r6, r0, #0
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _0819320C
	asrs r0, r0, #5
	b _08193212
_0819320C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_08193212:
	adds r2, r0, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _08193220
	asrs r1, r0, #5
	b _08193226
_08193220:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_08193226:
	lsls r0, r2, #5
	orrs r0, r6
	lsls r1, r1, #0xa
	orrs r1, r0
	strh r1, [r5]
	adds r5, #2
	adds r4, #2
	adds r7, #2
	adds r3, #2
	mov r0, ip
	adds r0, #0x1e
	cmp r5, r0
	ble _081931AC
	mov r2, ip
	ldrh r0, [r2, #0x20]
	subs r0, #1
	strh r0, [r2, #0x20]
	ldr r1, _08193270 @ =0x02008000
	ldr r3, [sp]
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _08193264
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, _08193274 @ =0x000001A9
	strh r1, [r0, #0x32]
	mov r2, r8
	ldr r0, [r2, #0x44]
	mov r3, ip
	str r3, [r0, #0x38]
_08193264:
	mov r1, ip
	ldrh r0, [r1, #0x20]
	cmp r0, #0
	beq _08193278
_0819326C:
	movs r0, #0
	b _0819327A
	.align 2, 0
_08193270: .4byte 0x02008000
_08193274: .4byte 0x000001A9
_08193278:
	movs r0, #1
_0819327A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0819328c
FUN_0819328c: @ 0x0819328C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r1
	mov r8, r2
	mov ip, r3
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r5, #0
	ldr r1, _081932E0 @ =0xFFFFFEFF
	mov sl, r1
	ldr r1, _081932E4 @ =0x0000077A
	adds r3, r0, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r7, _081932E8 @ =0xFFFFFDFF
	movs r6, #0x92
	lsls r6, r6, #1
	adds r1, #7
	adds r4, r0, r1
_081932BE:
	cmp r5, sb
	blt _08193306
	cmp r5, r8
	bgt _08193306
	mov r0, ip
	cmp r0, #0
	bne _081932EC
	ldrh r1, [r3]
	mov r0, sl
	ands r0, r1
	strh r0, [r3]
	ldr r0, [r2]
	ands r0, r7
	str r0, [r2]
	movs r0, #2
	strb r0, [r4]
	b _0819330C
	.align 2, 0
_081932E0: .4byte 0xFFFFFEFF
_081932E4: .4byte 0x0000077A
_081932E8: .4byte 0xFFFFFDFF
_081932EC:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r0, r1
	strh r0, [r3]
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r2]
	movs r0, #3
	strb r0, [r4]
	b _0819330C
_08193306:
	ldr r0, [r2]
	ands r0, r7
	str r0, [r2]
_0819330C:
	adds r4, r4, r6
	adds r3, r3, r6
	adds r2, r2, r6
	adds r5, #1
	cmp r5, #5
	ble _081932BE
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08193328
FUN_08193328: @ 0x08193328
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x1c]
	mov r8, r1
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r4, sp, #0xc
	add r5, sp, #0x14
	ldrh r0, [r2]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r7, r0, #0
	ldr r2, _08193384 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	cmp r0, #0
	blt _08193388
	asrs r0, r0, #0xc
	b _0819338E
	.align 2, 0
_08193384: .4byte 0x085B0A08
_08193388:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819338E:
	strh r0, [r4]
	ldr r0, _081933A8 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081933AC
	asrs r0, r0, #0xc
	b _081933B2
	.align 2, 0
_081933A8: .4byte 0x085B0A08
_081933AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081933B2:
	strh r0, [r4, #4]
	movs r3, #0
	str r3, [sp, #0x20]
	mov sl, r3
	add r6, sp, #0x14
	ldr r0, _081933F8 @ =0x030046A4
	mov sb, r0
_081933C0:
	ldrh r0, [r4]
	mov r1, sp
	ldrh r1, [r1, #0x14]
	adds r0, r0, r1
	strh r0, [r6]
	add r1, sp, #0xc
	ldrh r1, [r1, #4]
	ldrh r2, [r6, #4]
	adds r1, r1, r2
	strh r1, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081933F4
	cmp r1, #0
	blt _081933F4
	ldr r0, _081933FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081933F4
	ldr r0, _08193400 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08193404
_081933F4:
	movs r5, #0
	b _08193412
	.align 2, 0
_081933F8: .4byte 0x030046A4
_081933FC: .4byte 0x030046A8
_08193400: .4byte 0x030046AC
_08193404:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08193412:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08193422
	adds r0, #4
	b _0819342E
_08193422:
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0819342E:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0819350E
	mov r2, sp
	ldrh r0, [r2, #0x14]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r6]
	add r1, sp, #0xc
	ldrh r0, [r6, #4]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	asrs r7, r7, #7
	movs r0, #1
	ands r7, r0
	cmp r7, #0
	bne _0819348C
	ldr r0, _08193470 @ =0x085B0A08
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #6
	adds r2, r0, #0
	cmp r1, #0
	blt _08193474
	asrs r0, r1, #0xc
	b _0819347A
	.align 2, 0
_08193470: .4byte 0x085B0A08
_08193474:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819347A:
	strh r0, [r4]
	adds r0, r2, #0
	adds r0, #0x80
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	cmp r0, #0
	bge _081934C0
	b _081934C4
_0819348C:
	ldr r1, _081934A0 @ =0x085B0B88
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	ldr r2, _081934A4 @ =0x085B0A08
	cmp r0, #0
	blt _081934A8
	asrs r0, r0, #0xc
	b _081934AE
	.align 2, 0
_081934A0: .4byte 0x085B0B88
_081934A4: .4byte 0x085B0A08
_081934A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081934AE:
	strh r0, [r4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081934C4
_081934C0:
	asrs r0, r0, #0xc
	b _081934CA
_081934C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081934CA:
	strh r0, [r4, #4]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sp
	ldrh r0, [r3, #0x18]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081934F2
	cmp r1, #0
	blt _081934F2
	ldr r0, _081934F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081934F2
	ldr r0, _081934FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08193500
_081934F2:
	movs r5, #0
	b _0819350E
	.align 2, 0
_081934F8: .4byte 0x030046A8
_081934FC: .4byte 0x030046AC
_08193500:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0819350E:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _08193596
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08193524
	adds r0, #4
	b _08193530
_08193524:
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08193530:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081935C0
	ldr r6, _08193574 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, r8
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08193578
	adds r0, #4
	b _08193582
	.align 2, 0
_08193574: .4byte 0x030046A4
_08193578:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08193582:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r2, r8
	strh r1, [r2, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r2, #4]
	b _08193626
_08193596:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081935A6
	adds r0, #4
	b _081935B2
_081935A6:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081935B2:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _081935C0
	movs r0, #1
	str r0, [sp, #0x20]
_081935C0:
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #0x7f
	bgt _081935CC
	b _081933C0
_081935CC:
	mov r0, sp
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_08234de8
	ldr r2, _08193638 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0819363C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08193640 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	mov r1, sp
	movs r2, #0
	strb r0, [r1, #2]
	mov r0, sp
	strb r2, [r0, #3]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	mov r2, r8
	strh r1, [r2]
	ldr r3, [sp, #0x1c]
	ldr r2, _08193644 @ =0x00000472
	adds r1, r3, r2
	ldrh r1, [r1]
	mov r3, r8
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
_08193626:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08193638: .4byte 0x030046B8
_0819363C: .4byte 0x000003FF
_08193640: .4byte 0x0203B400
_08193644: .4byte 0x00000472

	thumb_func_start FUN_08193648
FUN_08193648: @ 0x08193648
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x1c]
	mov sb, r1
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r4, sp, #0xc
	add r5, sp, #0x14
	ldrh r0, [r2]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r7, r0, #0
	ldr r2, _081936A8 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	adds r3, r4, #0
	cmp r0, #0
	blt _081936AC
	asrs r0, r0, #0xc
	b _081936B2
	.align 2, 0
_081936A8: .4byte 0x085B0A08
_081936AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081936B2:
	strh r0, [r3]
	ldr r0, _081936CC @ =0x085B0A08
	movs r1, #0xff
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081936D0
	asrs r0, r0, #0xc
	b _081936D6
	.align 2, 0
_081936CC: .4byte 0x085B0A08
_081936D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081936D6:
	strh r0, [r3, #4]
	ldr r1, [sp, #0x1c]
	ldr r2, _08193724 @ =0x00000256
	adds r0, r1, r2
	ldrh r0, [r0]
	mov r8, r0
	movs r5, #0
	add r6, sp, #0x14
	ldr r0, _08193728 @ =0x085B0B08
	mov sl, r0
_081936EA:
	ldrh r0, [r3]
	mov r1, sp
	ldrh r1, [r1, #0x14]
	adds r0, r0, r1
	strh r0, [r6]
	add r1, sp, #0xc
	ldrh r1, [r1, #4]
	ldrh r2, [r6, #4]
	adds r1, r1, r2
	strh r1, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0819371E
	cmp r1, #0
	blt _0819371E
	ldr r0, _0819372C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0819371E
	ldr r0, _08193730 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08193734
_0819371E:
	movs r4, #0
	b _08193742
	.align 2, 0
_08193724: .4byte 0x00000256
_08193728: .4byte 0x085B0B08
_0819372C: .4byte 0x030046A8
_08193730: .4byte 0x030046AC
_08193734:
	ldr r0, _08193758 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08193742:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x20]
	bl FUN_08234224
	ldr r3, [sp, #0x20]
	cmp r0, #0
	beq _0819375C
	adds r0, #4
	b _08193768
	.align 2, 0
_08193758: .4byte 0x030046A4
_0819375C:
	ldr r0, _081937A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08193768:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0819383A
	mov r1, sp
	ldrh r0, [r1, #0x14]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r6]
	add r1, sp, #0xc
	ldrh r0, [r6, #4]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	asrs r7, r7, #7
	movs r0, #1
	ands r7, r0
	cmp r7, #0
	bne _081937C4
	mov r2, sl
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #6
	ldr r1, _081937A8 @ =0x085B0A08
	cmp r0, #0
	blt _081937AC
	asrs r0, r0, #0xc
	b _081937B2
	.align 2, 0
_081937A4: .4byte 0x030046A4
_081937A8: .4byte 0x085B0A08
_081937AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081937B2:
	strh r0, [r3]
	adds r0, r1, #0
	adds r0, #0x80
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	bge _081937EC
	b _081937F0
_081937C4:
	ldr r1, _081937D4 @ =0x085B0B88
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081937D8
	asrs r0, r0, #0xc
	b _081937DE
	.align 2, 0
_081937D4: .4byte 0x085B0B88
_081937D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081937DE:
	strh r0, [r3]
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081937F0
_081937EC:
	asrs r0, r0, #0xc
	b _081937F6
_081937F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081937F6:
	strh r0, [r3, #4]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0819381E
	cmp r1, #0
	blt _0819381E
	ldr r0, _08193824 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0819381E
	ldr r0, _08193828 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0819382C
_0819381E:
	movs r4, #0
	b _0819383A
	.align 2, 0
_08193824: .4byte 0x030046A8
_08193828: .4byte 0x030046AC
_0819382C:
	ldr r0, _08193850 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819383A:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x20]
	bl FUN_08234224
	ldr r3, [sp, #0x20]
	cmp r0, #0
	beq _08193854
	adds r0, #4
	b _08193860
	.align 2, 0
_08193850: .4byte 0x030046A4
_08193854:
	ldr r0, _081938A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08193860:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _081938C6
	ldr r5, _081938A4 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	mov r0, r8
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	mov r0, r8
	bl Div
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sb
	strh r4, [r0]
	mov r0, r8
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081938A8
	adds r0, #4
	b _081938B4
	.align 2, 0
_081938A4: .4byte 0x030046A4
_081938A8:
	ldr r0, [r5]
	mov r2, r8
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081938B4:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r3, sb
	strh r1, [r3, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	b _08193928
_081938C6:
	mov r8, r4
	adds r5, #1
	cmp r5, #0x7f
	bgt _081938D0
	b _081936EA
_081938D0:
	mov r0, sp
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_08234de8
	ldr r2, _0819393C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08193940 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08193944 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	mov r1, sp
	movs r2, #0
	strb r0, [r1, #2]
	mov r0, sp
	strb r2, [r0, #3]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	mov r2, sb
	strh r1, [r2]
	ldr r3, [sp, #0x1c]
	ldr r2, _08193948 @ =0x00000472
	adds r1, r3, r2
	ldrh r1, [r1]
	mov r3, sb
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
_08193928:
	strh r0, [r3, #4]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819393C: .4byte 0x030046B8
_08193940: .4byte 0x000003FF
_08193944: .4byte 0x0203B400
_08193948: .4byte 0x00000472

	thumb_func_start FUN_0819394c
FUN_0819394c: @ 0x0819394C
	push {r4, r5, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r5, [r1]
	movs r1, #0xc0
	lsls r1, r1, #4
	ldr r2, _08193994 @ =0x00000F2C
	adds r3, r5, r2
	ldrh r2, [r3]
	movs r4, #0
	orrs r1, r2
	strh r1, [r3]
	movs r2, #0xe4
	lsls r2, r2, #4
	adds r1, r5, r2
	strb r4, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	ldr r2, _08193998 @ =0x00000546
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _081939A4
	ldr r1, _0819399C @ =0x00000E42
	adds r0, r5, r1
	ldrb r0, [r0]
	lsrs r0, r0, #1
	ldr r2, _081939A0 @ =0x00000E41
	adds r1, r5, r2
	strb r0, [r1]
	b _081939B0
	.align 2, 0
_08193994: .4byte 0x00000F2C
_08193998: .4byte 0x00000546
_0819399C: .4byte 0x00000E42
_081939A0: .4byte 0x00000E41
_081939A4:
	ldr r1, _081939B8 @ =0x00000E42
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081939BC @ =0x00000E41
	adds r0, r5, r2
	strb r1, [r0]
_081939B0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081939B8: .4byte 0x00000E42
_081939BC: .4byte 0x00000E41

	thumb_func_start FUN_081939c0
FUN_081939c0: @ 0x081939C0
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r2, #0
	ldr r0, _081939F0 @ =0x00000E44
	adds r3, r4, r0
	movs r5, #0xff
_081939D2:
	adds r1, r3, r2
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r2, #1
	cmp r2, #2
	ble _081939D2
	ldr r0, _081939F4 @ =0x00000E43
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081939F0: .4byte 0x00000E44
_081939F4: .4byte 0x00000E43

	thumb_func_start FUN_081939f8
FUN_081939f8: @ 0x081939F8
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r3, _08193A28 @ =0x00000E43
	adds r2, r0, r3
	adds r3, #1
	adds r0, r0, r3
	ldrb r3, [r2]
	adds r0, r0, r3
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08193A22
	movs r0, #0
	strb r0, [r2]
_08193A22:
	pop {r0}
	bx r0
	.align 2, 0
_08193A28: .4byte 0x00000E43

	thumb_func_start FUN_08193a2c
FUN_08193a2c: @ 0x08193A2C
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #0
	ldr r4, _08193A4C @ =0x00000E44
	adds r3, r0, r4
_08193A3C:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne _08193A50
	movs r0, #1
	b _08193A58
	.align 2, 0
_08193A4C: .4byte 0x00000E44
_08193A50:
	adds r2, #1
	cmp r2, #2
	ble _08193A3C
	movs r0, #0
_08193A58:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08193a60
FUN_08193a60: @ 0x08193A60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x20]
	mov r8, r1
	mov sl, r2
	mov r0, sp
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_08234de8
	ldr r2, _08193B44 @ =0x7FFFFFFF
	movs r0, #1
	rsbs r0, r0, #0
	mov sb, r0
	movs r5, #0
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r5, r1
	bge _08193AFC
	add r6, sp, #0xc
	add r4, sp, #0x18
	ldr r7, _08193B48 @ =0xFFFF0000
_08193A96:
	str r2, [sp, #0x24]
	bl FUN_08234f6c
	lsls r1, r5, #3
	adds r0, r0, r1
	str r0, [r6, #8]
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [r6, #8]
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x18]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r6, #8]
	ldrh r1, [r0, #2]
	ldrh r0, [r4, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r2, [sp, #0x24]
	cmp r2, r1
	ble _08193AF2
	mov sb, r5
	adds r2, r1, #0
_08193AF2:
	adds r5, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r5, r1
	blt _08193A96
_08193AFC:
	ldr r0, _08193B44 @ =0x7FFFFFFF
	cmp r2, r0
	beq _08193B34
	mov r0, sp
	movs r1, #0
	mov r2, sb
	strb r2, [r0, #2]
	strb r1, [r0, #3]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	mov r3, r8
	strh r1, [r3]
	ldr r2, [sp, #0x20]
	ldr r3, _08193B4C @ =0x00000472
	adds r1, r2, r3
	ldrh r1, [r1]
	mov r2, r8
	strh r1, [r2, #2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #4]
_08193B34:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08193B44: .4byte 0x7FFFFFFF
_08193B48: .4byte 0xFFFF0000
_08193B4C: .4byte 0x00000472

	thumb_func_start FUN_08193b50
FUN_08193b50: @ 0x08193B50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	str r1, [sp, #0x20]
	str r2, [sp, #0x24]
	mov sl, r3
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sp
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_08234de8
	ldr r2, _08193C08 @ =0x7FFFFFFF
	mov r8, r2
	ldr r3, [sp, #0x50]
	cmp r3, #0
	bne _08193B88
	movs r0, #0
	mov r8, r0
_08193B88:
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x2c]
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	cmp r6, r2
	bge _08193C34
	add r3, sp, #0xc
	mov sb, r3
	add r5, sp, #0x18
_08193B9E:
	bl FUN_08234f6c
	lsls r1, r6, #3
	adds r0, r0, r1
	mov r1, sb
	str r0, [r1, #8]
	ldr r2, [sp, #0x24]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	mov r3, sb
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	ldrh r0, [r5]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x18]
	ldr r2, _08193C0C @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r3, #8]
	ldrh r1, [r0, #2]
	ldrh r0, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r3, #0
	ldrsh r0, [r5, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r4, r1, r0
	cmp r4, #0
	beq _08193C2A
	ldr r0, [sp, #0x50]
	cmp r0, #0
	bne _08193C10
	cmp r4, sl
	bgt _08193C2A
	cmp r8, r4
	bge _08193C2A
	b _08193C18
	.align 2, 0
_08193C08: .4byte 0x7FFFFFFF
_08193C0C: .4byte 0xFFFF0000
_08193C10:
	cmp r4, sl
	blt _08193C2A
	cmp r8, r4
	ble _08193C2A
_08193C18:
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08193a2c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08193C2A
	str r6, [sp, #0x2c]
	mov r8, r4
_08193C2A:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r6, r1
	blt _08193B9E
_08193C34:
	mov r2, r8
	cmp r2, #0
	bne _08193C58
	ldr r3, [sp, #0x28]
	ldr r0, _08193C50 @ =0x00000F8C
	adds r1, r3, r0
	ldr r0, _08193C54 @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	adds r0, r7, #0
	bl FUN_08193328
	b _08193C90
	.align 2, 0
_08193C50: .4byte 0x00000F8C
_08193C54: .4byte 0x03002BE0
_08193C58:
	adds r0, r7, #0
	ldr r1, [sp, #0x2c]
	bl FUN_081939f8
	mov r0, sp
	movs r1, #0
	add r2, sp, #0x2c
	ldrb r2, [r2]
	strb r2, [r0, #2]
	strb r1, [r0, #3]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	ldr r3, [sp, #0x20]
	strh r1, [r3]
	ldr r2, _08193CA0 @ =0x00000472
	adds r1, r7, r2
	ldrh r1, [r1]
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
_08193C90:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08193CA0: .4byte 0x00000472

	thumb_func_start FUN_08193ca4
FUN_08193ca4: @ 0x08193CA4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08193CBC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08193CC0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08193CC2
	.align 2, 0
_08193CBC: .4byte 0x0000046C
_08193CC0:
	movs r0, #0
_08193CC2:
	cmp r0, #0
	beq _08193CFA
	ldr r4, _08193D9C @ =FUN_0818a904
	movs r3, #0x22
	ldr r2, _08193DA0 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08193DA4 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08193DA8 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #8
	strh r0, [r1]
_08193CFA:
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r3, r1, #0
	cmp r1, #0
	bge _08193D0C
	rsbs r3, r1, #0
_08193D0C:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r2, r0, #0
	cmp r0, #0
	bge _08193D1E
	rsbs r2, r0, #0
_08193D1E:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x28
	bl FUN_0818f938
	ldr r6, _08193DA4 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08193DB4
	adds r0, r5, #0
	bl FUN_0818e6fc
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _08193DA0 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r3, [r0]
	adds r0, r5, r6
	strb r2, [r0]
	ldr r4, _08193DA8 @ =0x00000553
	adds r0, r5, r4
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08193DAC @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08193DB0 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _08193DBE
	.align 2, 0
_08193D9C: .4byte FUN_0818a904
_08193DA0: .4byte 0x0000046D
_08193DA4: .4byte 0x0000046B
_08193DA8: .4byte 0x00000553
_08193DAC: .4byte 0x0000046A
_08193DB0: .4byte 0x00000484
_08193DB4:
	ldr r0, _08193DC4 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08193DBE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08193DC4: .4byte 0x00000484

	thumb_func_start FUN_08193dc8
FUN_08193dc8: @ 0x08193DC8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r2, _08193DE8 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08193DEC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08193DEE
	.align 2, 0
_08193DE8: .4byte 0x0000046C
_08193DEC:
	movs r0, #0
_08193DEE:
	cmp r0, #0
	beq _08193E76
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r3, #0
	strb r0, [r7, #5]
	ldr r4, _08193E44 @ =FUN_08189614
	movs r2, #0x25
	ldr r0, _08193E48 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08193E4C @ =0x0000046B
	adds r0, r7, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r3, [r0]
	movs r6, #1
	ldr r0, _08193E50 @ =0x0000077A
	adds r3, r5, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r5, r1
	movs r5, #0x92
	lsls r5, r5, #1
	movs r4, #4
_08193E38:
	ldrh r0, [r3]
	ands r0, r6
	cmp r0, #0
	beq _08193E54
	movs r0, #1
	b _08193E56
	.align 2, 0
_08193E44: .4byte FUN_08189614
_08193E48: .4byte 0x0000046D
_08193E4C: .4byte 0x0000046B
_08193E50: .4byte 0x0000077A
_08193E54:
	movs r0, #0
_08193E56:
	cmp r0, #0
	bne _08193E64
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_08193E64:
	adds r3, r3, r5
	adds r2, r2, r5
	subs r4, #1
	cmp r4, #0
	bge _08193E38
	adds r0, r7, #0
	movs r1, #3
	bl FUN_08191ca0
_08193E76:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08193E9A
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _08193EA2
_08193E9A:
	adds r0, r7, #0
	movs r1, #3
	bl FUN_08191ca0
_08193EA2:
	ldr r3, _08193F6C @ =0x0000046B
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08193F8C
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _08193F70 @ =0x00000472
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08191a14
	ldr r0, _08193F74 @ =0x000001DF
	bl PlaySound_082406e0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _08193F78 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	mov r2, sp
	ldr r1, _08193F7C @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	ldr r4, _08193F80 @ =0x00000469
	adds r0, r7, r4
	strb r5, [r0]
	ldr r2, _08193F84 @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r6, [r0]
	adds r4, #3
	adds r0, r7, r4
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08193F88 @ =FUN_080e48d0
	movs r2, #0x10
	adds r4, #1
	adds r0, r7, r4
	strb r1, [r0]
	ldr r1, _08193F6C @ =0x0000046B
	adds r0, r7, r1
	strb r5, [r0]
	adds r4, #0xe6
	adds r0, r7, r4
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r0, r7, r3
	bl FUN_080139a0
	b _08193F96
	.align 2, 0
_08193F6C: .4byte 0x0000046B
_08193F70: .4byte 0x00000472
_08193F74: .4byte 0x000001DF
_08193F78: .4byte 0xFFEFFFFF
_08193F7C: .4byte 0x000004A4
_08193F80: .4byte 0x00000469
_08193F84: .4byte 0x0000046A
_08193F88: .4byte FUN_080e48d0
_08193F8C:
	ldr r4, _08193FA0 @ =0x00000484
	adds r1, r7, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08193F96:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08193FA0: .4byte 0x00000484

	thumb_func_start FUN_08193fa4
FUN_08193fa4: @ 0x08193FA4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _081940A0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08193FB8
	movs r0, #0
	strb r0, [r1]
_08193FB8:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_0818fdd8
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0xa
	bl FUN_08191774
	ldr r1, _081940A4 @ =0x0000046B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081940C0
	adds r4, r7, #0
	adds r4, #8
	ldr r2, _081940A8 @ =0x00000472
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08191a14
	ldr r0, _081940AC @ =0x000001DF
	bl PlaySound_082406e0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _081940B0 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	mov r2, sp
	ldr r1, _081940B4 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	movs r1, #2
	movs r2, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081940B8 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081940BC @ =0x00000484
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r5, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r0, r7, r3
	bl FUN_080139a0
	b _081940CA
	.align 2, 0
_081940A0: .4byte 0x0000046C
_081940A4: .4byte 0x0000046B
_081940A8: .4byte 0x00000472
_081940AC: .4byte 0x000001DF
_081940B0: .4byte 0xFFEFFFFF
_081940B4: .4byte 0x000004A4
_081940B8: .4byte 0x0000046A
_081940BC: .4byte 0x00000484
_081940C0:
	ldr r0, _081940D4 @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081940CA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081940D4: .4byte 0x00000484

	thumb_func_start FUN_081940d8
FUN_081940d8: @ 0x081940D8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r3, _081940F8 @ =0x0000046C
	adds r1, r5, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081940FC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081940FE
	.align 2, 0
_081940F8: .4byte 0x0000046C
_081940FC:
	movs r0, #0
_081940FE:
	cmp r0, #0
	beq _0819414C
	movs r0, #0x20
	ldr r7, _081941A8 @ =0x00000474
	adds r2, r5, r7
	ldrh r1, [r2]
	movs r3, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #1
	subs r7, #7
	adds r0, r5, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r3, [r0]
	ldr r3, _081941AC @ =0x00000553
	adds r0, r5, r3
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	ldr r3, _081941B0 @ =0x00000F2C
	adds r2, r6, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0819414C:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xa
	bl FUN_08191774
	movs r4, #0
	movs r0, #0xf8
	lsls r0, r0, #8
	strh r0, [r5, #0xa]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_0818fdd8
	ldr r7, _081941B4 @ =0x00000484
	adds r2, r5, r7
	ldr r0, [r2]
	cmp r0, #0xa0
	ble _0819419C
	movs r1, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	subs r7, #0x1b
	adds r0, r5, r7
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r7, #0x1b
	adds r1, r5, r7
	movs r0, #0
	str r0, [r1]
	ldr r0, _081941B8 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0819419C:
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081941A8: .4byte 0x00000474
_081941AC: .4byte 0x00000553
_081941B0: .4byte 0x00000F2C
_081941B4: .4byte 0x00000484
_081941B8: .4byte 0x0000046C

	thumb_func_start FUN_081941bc
FUN_081941bc: @ 0x081941BC
	ldr r1, _081941C8 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081941CC @ =0x085ADD64
	str r1, [r0]
	bx lr
	.align 2, 0
_081941C8: .4byte 0x0000063C
_081941CC: .4byte 0x085ADD64

	thumb_func_start FUN_081941d0
FUN_081941d0: @ 0x081941D0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08190f34
	adds r0, r4, #0
	bl FUN_08192774
	adds r0, r4, #0
	bl FUN_08192a14
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081941ec
FUN_081941ec: @ 0x081941EC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0819235c
	adds r0, r4, #0
	bl FUN_081923e0
	adds r0, r4, #0
	bl FUN_08192278
	adds r0, r4, #0
	bl FUN_0819204c
	adds r0, r4, #0
	bl FUN_0818f7b4
	adds r0, r4, #0
	bl FUN_0818f9ac
	adds r0, r4, #0
	bl FUN_08190ae0
	adds r0, r4, #0
	bl FUN_08190974
	adds r0, r4, #0
	bl FUN_08191294
	adds r0, r4, #0
	bl FUN_081928e0
	adds r0, r4, #0
	bl FUN_08193100
	adds r0, r4, #0
	bl FUN_08192f64
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08194240
FUN_08194240: @ 0x08194240
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xf8
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r4, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08194264
FUN_08194264: @ 0x08194264
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081941d0
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _0819429C @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	adds r0, r4, #0
	bl FUN_081941ec
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0819429C: .4byte 0x0000062C

	thumb_func_start FUN_081942a0
FUN_081942a0: @ 0x081942A0
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _08194300 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08194304 @ =0x030047A4
	ldr r1, _08194308 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _081942C8
	b _081943D4
_081942C8:
	movs r1, #4
	ldr r0, _0819430C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081942D6
	b _081943D4
_081942D6:
	movs r0, #2
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08194398
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _08194310 @ =0x030046A0
	ldr r0, [r0]
	adds r2, #0xd0
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08194314
	movs r0, #1
	b _08194316
	.align 2, 0
_08194300: .4byte 0x03002BE0
_08194304: .4byte 0x030047A4
_08194308: .4byte 0x030047A0
_0819430C: .4byte 0x03002BC0
_08194310: .4byte 0x030046A0
_08194314:
	movs r0, #0
_08194316:
	cmp r0, #0
	bne _08194324
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f07d0
	b _081943D4
_08194324:
	adds r0, r4, #0
	bl FUN_0818e30c
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08194356
	ldr r1, _08194394 @ =0x00000624
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08194356
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08194356:
	adds r0, r4, #0
	bl FUN_080eafdc
	adds r0, r4, #0
	bl FUN_080e1f48
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r1, [r1]
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e35b4
	adds r0, r4, #0
	bl FUN_080e191c
	adds r0, r4, #0
	bl FUN_080eb168
	adds r0, r4, #0
	bl FUN_080f06ac
	movs r0, #1
	b _081943D6
	.align 2, 0
_08194394: .4byte 0x00000624
_08194398:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _081943CE
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _081943BC @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081943C0
	movs r0, #1
	b _081943C2
	.align 2, 0
_081943BC: .4byte 0x030046A0
_081943C0:
	movs r0, #0
_081943C2:
	cmp r0, #0
	beq _081943CE
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f0914
_081943CE:
	adds r0, r4, #0
	bl FUN_080f06ac
_081943D4:
	movs r0, #0
_081943D6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EnemySerpent_Destroy
EnemySerpent_Destroy: @ 0x081943DC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08194418 @ =0x000003E5
	bl sound_08240740
	adds r0, r4, #0
	bl FUN_0818f808
	ldr r0, _0819441C @ =0x0000044C
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08194404
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
	movs r0, #0xff
	strb r0, [r5]
_08194404:
	ldr r2, _08194420 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08194424
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _0819442C
	.align 2, 0
_08194418: .4byte 0x000003E5
_0819441C: .4byte 0x0000044C
_08194420: .4byte 0x0000025D
_08194424:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_0819442C:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08194448 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0819444C
	movs r0, #1
	b _0819444E
	.align 2, 0
_08194448: .4byte 0x00000474
_0819444C:
	movs r0, #0
_0819444E:
	cmp r0, #0
	beq _0819445A
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_0819445A:
	ldr r1, _081944B4 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08194472
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_08194472:
	ldr r0, _081944B8 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0819448A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_0819448A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081944A2
	adds r0, r4, #0
	bl FUN_08002a58
_081944A2:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081944BC
	movs r0, #1
	b _081944BE
	.align 2, 0
_081944B4: .4byte 0x0000044C
_081944B8: .4byte 0x0000044D
_081944BC:
	movs r0, #0
_081944BE:
	cmp r0, #0
	beq _081944CA
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081944CA:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemySerpent_Init
EnemySerpent_Init: @ 0x081944E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c4
	adds r7, r0, #0
	str r7, [sp, #0x30]
	ldr r1, _08194570 @ =0x00000F2C
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _08194574 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x1a
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0819119c
	ldr r3, _08194578 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08194584
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0819457C @ =0x0000D636
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08194580 @ =0x0000C102
	bl FUN_080e3804
	ldr r4, _08194574 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x8c]
	cmp r1, #0x11
	beq _08194560
	cmp r1, #0x17
	bne _08194564
_08194560:
	movs r0, #1
	strb r0, [r5, #7]
_08194564:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081945EC
	.align 2, 0
_08194570: .4byte 0x00000F2C
_08194574: .4byte 0x000001DF
_08194578: .4byte 0x0000025D
_0819457C: .4byte 0x0000D636
_08194580: .4byte 0x0000C102
_08194584:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x20
	mov r8, r0
	str r6, [sp, #0x1c]
	add r0, sp, #0x1c
	mov r1, r8
	ldr r2, _08194668 @ =0x05000002
	bl CpuSet
	ldr r0, _0819466C @ =0x0000CB05
	ldr r1, _08194670 @ =0x0000D636
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _08194674 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08194678 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x8c]
_081945EC:
	str r7, [sp, #0x34]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _0819467C @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, _08194680 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _08194668 @ =0x05000002
	bl CpuSet
	ldr r3, _08194684 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1bc]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x5c]
	mov r3, r8
	str r3, [sp, #0x60]
	str r6, [sp, #0x1b0]
	ldr r2, [sp, #0x1bc]
	adds r6, r2, #0
	cmp r0, #0
	bne _08194658
	b _081947B8
_08194658:
	bl VM_GetPC
	cmp r0, #0
	beq _08194688
	bl Script_GetValue
	adds r1, r0, #0
	b _0819468A
	.align 2, 0
_08194668: .4byte 0x05000002
_0819466C: .4byte 0x0000CB05
_08194670: .4byte 0x0000D636
_08194674: .4byte 0x000004B7
_08194678: .4byte 0x000001DF
_0819467C: .4byte 0x0000046F
_08194680: .4byte 0x00000474
_08194684: .4byte 0x000004B6
_08194688:
	movs r1, #0
_0819468A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081946B0 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x114]
	str r4, [sp, #0x118]
	cmp r0, #0
	beq _081946B4
	bl Script_GetValue
	adds r1, r0, #0
	b _081946B6
	.align 2, 0
_081946B0: .4byte 0x00000251
_081946B4:
	movs r1, #0
_081946B6:
	ldr r2, _081946EC @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081946F0 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x114]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x120]
	cmp r0, #0
	beq _081946F4
	bl Script_GetValue
	b _081946F8
	.align 2, 0
_081946EC: .4byte 0x00000252
_081946F0: .4byte 0x000004B4
_081946F4:
	ldr r4, [sp, #0x114]
	ldrb r0, [r4]
_081946F8:
	strb r0, [r6]
	ldr r5, [sp, #0x114]
	ldrb r1, [r5]
	ldr r6, [sp, #0x120]
	ldrb r2, [r6]
	add r0, sp, #0x28
	bl FUN_08234f90
	add r0, sp, #0x28
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08194730
	cmp r1, #0
	blt _08194730
	ldr r0, _08194734 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08194730
	ldr r0, _08194738 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0819473C
_08194730:
	movs r1, #0
	b _0819474A
	.align 2, 0
_08194734: .4byte 0x030046A8
_08194738: .4byte 0x030046AC
_0819473C:
	ldr r0, _08194764 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0819474A:
	ldr r2, _08194768 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0819476C
	adds r0, #4
	b _08194778
	.align 2, 0
_08194764: .4byte 0x030046A4
_08194768: .4byte 0x00000256
_0819476C:
	ldr r0, _0819478C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08194778:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08194790
	cmp r2, #2
	beq _08194794
	b _08194798
	.align 2, 0
_0819478C: .4byte 0x030046A4
_08194790:
	ldrb r0, [r4, #4]
	b _08194796
_08194794:
	ldrb r0, [r4]
_08194796:
	subs r1, r1, r0
_08194798:
	ldr r3, _081947B0 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081947B4 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x38]
	b _081947F8
	.align 2, 0
_081947B0: .4byte 0x00000472
_081947B4: .4byte 0x0000FFFF
_081947B8:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0819481C @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08194820 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08194824 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x38]
	str r5, [sp, #0x114]
	str r4, [sp, #0x118]
	str r3, [sp, #0x120]
_081947F8:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08194842
	bl VM_GetPC
	cmp r0, #0
	beq _08194828
	bl Script_GetValue
	adds r4, r0, #0
	b _0819482A
	.align 2, 0
_0819481C: .4byte 0x00000251
_08194820: .4byte 0x00000252
_08194824: .4byte 0x000004B4
_08194828:
	movs r4, #0x30
_0819482A:
	bl VM_GetPC
	cmp r0, #0
	beq _0819483C
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0819483E
_0819483C:
	movs r5, #0x40
_0819483E:
	mov r8, r4
	b _08194848
_08194842:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08194848:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08194880
	bl VM_GetPC
	cmp r0, #0
	beq _08194862
	bl Script_GetValue
	adds r6, r0, #0
	b _08194864
_08194862:
	movs r6, #0
_08194864:
	bl VM_GetPC
	cmp r0, #0
	beq _08194874
	bl Script_GetValue
	adds r1, r0, #0
	b _08194876
_08194874:
	movs r1, #0
_08194876:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0819488A
_08194880:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0819488A:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _08194B1C @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x134]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x68]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x64]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x124]
	lsls r4, r4, #0x10
	str r4, [sp, #0x88]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x94]
	lsls r6, r6, #0x10
	str r6, [sp, #0x98]
	lsls r5, r5, #0x10
	str r5, [sp, #0x90]
	ldr r4, _08194B20 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x130]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x84]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x18c]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa0]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x190]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x194]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x188]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x44]
	ldr r1, _08194B24 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x1b4]
	ldr r2, _08194B28 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x3c]
	ldr r3, _08194B2C @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _08194B30 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x54]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x58]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xdc]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xf8]
	ldr r4, _08194B34 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0xfc]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x11c]
	ldr r6, _08194B38 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x128]
	ldr r1, _08194B3C @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x138]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	ldr r3, _08194B40 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _08194B44 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x148]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _08194B48 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	ldr r1, _08194B4C @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x16c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x170]
	ldr r3, _08194B50 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xe0]
	ldr r4, _08194B54 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x15c]
	ldr r6, _08194B58 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x150]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x160]
	ldr r2, _08194B5C @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x164]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x168]
	ldr r4, _08194B60 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x178]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x17c]
	ldr r6, _08194B64 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x110]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x154]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _08194B68 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x158]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x144]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x100]
	ldr r6, _08194B6C @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x180]
	ldr r1, _08194B70 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x184]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x108]
	ldr r4, _08194B74 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0xec]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xf0]
	ldr r6, _08194B78 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	ldr r1, _08194B7C @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x104]
	ldr r2, _08194B80 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _08194B84 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x50]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x198]
	ldr r1, _08194B88 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x19c]
	ldr r2, _08194B8C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x1a0]
	ldr r3, _08194B90 @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x48]
	ldr r4, _08194B94 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x1a8]
	ldr r5, _08194B98 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x1ac]
	ldr r6, _08194B9C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x1a4]
	ldr r1, _08194BA0 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0x9c]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x78]
	movs r4, #0x92
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	movs r5, #0xea
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x80]
	ldr r6, _08194BA4 @ =0x00000572
	adds r6, r7, r6
	str r6, [sp, #0xcc]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x74]
	movs r2, #0xae
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xc8]
	ldr r3, _08194BA8 @ =0x0000055C
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	movs r4, #0xac
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xac]
	ldr r5, _08194BAC @ =0x00000564
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	ldr r6, _08194BB0 @ =0x00000565
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	ldr r1, _08194BB4 @ =0x00000566
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _08194BB8 @ =0x00000567
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	movs r3, #0xad
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xc0]
	ldr r4, _08194BBC @ =0x0000056C
	adds r4, r7, r4
	str r4, [sp, #0xc4]
	cmp r0, #0
	bne _08194AEC
	b _08194C18
_08194AEC:
	movs r5, #0
	mov sl, r5
	movs r6, #0x8d
	lsls r6, r6, #2
	adds r6, r6, r7
	mov sb, r6
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r5, r7, r1
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r7, r2
_08194B0C:
	bl VM_GetPC
	cmp r0, #0
	beq _08194BC0
	bl Script_GetValue
	b _08194BC2
	.align 2, 0
_08194B1C: .4byte 0x0000025D
_08194B20: .4byte 0x0000025A
_08194B24: .4byte 0x0000047A
_08194B28: .4byte 0x0000047C
_08194B2C: .4byte 0x0000047E
_08194B30: .4byte 0x000004A4
_08194B34: .4byte 0x000005A4
_08194B38: .4byte 0x000005C4
_08194B3C: .4byte 0x000005CC
_08194B40: .4byte 0x000005D4
_08194B44: .4byte 0x000005DC
_08194B48: .4byte 0x00000584
_08194B4C: .4byte 0x00000604
_08194B50: .4byte 0x0000021D
_08194B54: .4byte 0x0000060C
_08194B58: .4byte 0x000005E4
_08194B5C: .4byte 0x000005FC
_08194B60: .4byte 0x00000614
_08194B64: .4byte 0x000005BC
_08194B68: .4byte 0x000005EC
_08194B6C: .4byte 0x00000624
_08194B70: .4byte 0x0000058C
_08194B74: .4byte 0x00000594
_08194B78: .4byte 0x0000059C
_08194B7C: .4byte 0x000005B4
_08194B80: .4byte 0x00000543
_08194B84: .4byte 0x00000496
_08194B88: .4byte 0x00000469
_08194B8C: .4byte 0x0000046A
_08194B90: .4byte 0x00000484
_08194B94: .4byte 0x0000046C
_08194B98: .4byte 0x0000046D
_08194B9C: .4byte 0x0000046B
_08194BA0: .4byte 0x00000553
_08194BA4: .4byte 0x00000572
_08194BA8: .4byte 0x0000055C
_08194BAC: .4byte 0x00000564
_08194BB0: .4byte 0x00000565
_08194BB4: .4byte 0x00000566
_08194BB8: .4byte 0x00000567
_08194BBC: .4byte 0x0000056C
_08194BC0:
	movs r0, #0x18
_08194BC2:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08194BD4
	bl Script_GetValue
	b _08194BD6
_08194BD4:
	movs r0, #0x18
_08194BD6:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08194BE8
	bl Script_GetValue
	b _08194BEA
_08194BE8:
	movs r0, #0
_08194BEA:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08194BFC
	bl Script_GetValue
	b _08194BFE
_08194BFC:
	movs r0, #0
_08194BFE:
	strh r0, [r6]
	movs r3, #2
	add sb, r3
	movs r6, #4
	add r8, r6
	adds r5, #2
	adds r4, #2
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _08194C18
	b _08194B0C
_08194C18:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08194C64
	bl VM_GetPC
	cmp r0, #0
	beq _08194C32
	bl Script_GetValue
	adds r4, r0, #0
	b _08194C36
_08194C32:
	movs r4, #0x96
	lsls r4, r4, #1
_08194C36:
	bl VM_GetPC
	cmp r0, #0
	beq _08194C46
	bl Script_GetValue
	adds r6, r0, #0
	b _08194C4A
_08194C46:
	movs r6, #0x96
	lsls r6, r6, #1
_08194C4A:
	bl VM_GetPC
	cmp r0, #0
	beq _08194C58
	bl Script_GetValue
	b _08194C5E
_08194C58:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
_08194C5E:
	ldr r3, [sp, #0x10c]
	strh r0, [r3]
	b _08194C6C
_08194C64:
	movs r4, #0
	movs r6, #0
	ldr r5, [sp, #0x10c]
	strh r6, [r5]
_08194C6C:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08194C84
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x60]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08194C84:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x68]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x64]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08194D54
	bl VM_GetPC
	cmp r0, #0
	beq _08194CB4
	bl Script_GetValue
	b _08194CB6
_08194CB4:
	movs r0, #0
_08194CB6:
	ldr r1, [sp, #0x124]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08194CC4
	asrs r1, r0, #1
	b _08194CCA
_08194CC4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08194CCA:
	ldr r2, _08194CE0 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08194CE4
	bl Script_GetValue
	b _08194CE6
	.align 2, 0
_08194CE0: .4byte 0x00000546
_08194CE4:
	movs r0, #0
_08194CE6:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08194CFC
	bl Script_GetValue
	b _08194CFE
_08194CFC:
	movs r0, #0
_08194CFE:
	ldr r5, _08194D14 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08194D18
	bl Script_GetValue
	adds r1, r0, #0
	b _08194D1A
	.align 2, 0
_08194D14: .4byte 0x00000187
_08194D18:
	movs r1, #0
_08194D1A:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08194D30
	bl Script_GetValue
	b _08194D32
_08194D30:
	movs r0, #0
_08194D32:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08194D4A
	bl Script_GetValue
	adds r1, r0, #0
	b _08194D4C
_08194D4A:
	movs r1, #0
_08194D4C:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08194D54:
	ldr r0, [sp, #0x124]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0x88]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x94]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x98]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x90]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08194DB6
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08194D9C
	bl Script_GetValue
	b _08194D9E
_08194D9C:
	movs r0, #0
_08194D9E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08194DAE
	bl Script_GetValue
	b _08194DB0
_08194DAE:
	movs r0, #0
_08194DB0:
	ldr r2, _08194E18 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_08194DB6:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x130]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08194DDA
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08194DDA:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08194DF2
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x60]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08194DF2:
	ldr r6, [sp, #0x84]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x34]
	add r2, sp, #0x28
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x1b0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08194E1C
	movs r0, #1
	b _08194E1E
	.align 2, 0
_08194E18: .4byte 0x00000189
_08194E1C:
	movs r0, #0
_08194E1E:
	cmp r0, #0
	beq _08194E2E
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08194E58 @ =FUN_080f48ac
	ldr r1, [sp, #0x34]
	bl FUN_0807f558
_08194E2E:
	ldr r3, [sp, #0x134]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08194E3A
	ldr r1, [r7, #0x44]
_08194E3A:
	ldr r0, [sp, #0x34]
	bl FUN_0823b46c
	ldr r4, [sp, #0x8c]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08194E5C
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x18c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08194E68
	.align 2, 0
_08194E58: .4byte FUN_080f48ac
_08194E5C:
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x18c]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08194E68:
	ldr r5, [sp, #0x8c]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08194EB6
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08194EB6
	cmp r0, #0x16
	beq _08194EB6
	cmp r0, #0x14
	beq _08194EB6
	cmp r0, #9
	beq _08194EB6
	cmp r0, #0x19
	beq _08194EB6
	cmp r0, #0x1a
	beq _08194EB6
	cmp r0, #0xd
	beq _08194EB6
	cmp r0, #0x1b
	beq _08194EB6
	cmp r0, #0x1f
	beq _08194EB6
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x114]
	ldrb r2, [r6]
	ldr r0, [sp, #0x118]
	ldrb r3, [r0]
	ldr r4, [sp, #0x120]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x34]
	bl FUN_0823b490
_08194EB6:
	movs r1, #8
	ldr r5, [sp, #0x1b0]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08194EC6
	movs r0, #1
	b _08194EC8
_08194EC6:
	movs r0, #0
_08194EC8:
	cmp r0, #0
	beq _08194ED6
	ldr r6, [sp, #0xa4]
	ldr r0, [r6]
	ldr r1, [sp, #0xa0]
	str r0, [r1]
	b _08194EE8
_08194ED6:
	ldr r2, [sp, #0xa4]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xa0]
	str r0, [r3]
_08194EE8:
	ldrh r0, [r7]
	ldr r4, [sp, #0x190]
	strh r0, [r4]
	ldr r5, [sp, #0x188]
	ldr r6, [sp, #0x194]
	str r5, [r6]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _08194F12
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x34]
	strb r0, [r1, #5]
_08194F12:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08195004
	bl VM_GetPC
	cmp r0, #0
	beq _08194F2A
	bl Script_GetValue
	b _08194F2C
_08194F2A:
	movs r0, #0
_08194F2C:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _08194F3C
	bl Script_GetValue
	b _08194F3E
_08194F3C:
	movs r0, #0
_08194F3E:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _08194F4E
	bl Script_GetValue
	b _08194F50
_08194F4E:
	movs r0, #0
_08194F50:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x188]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08194F78
	cmp r1, #0
	blt _08194F78
	ldr r0, _08194F7C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08194F78
	ldr r0, _08194F80 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08194F84
_08194F78:
	movs r1, #0
	b _08194F92
	.align 2, 0
_08194F7C: .4byte 0x030046A8
_08194F80: .4byte 0x030046AC
_08194F84:
	ldr r0, _08194FAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08194F92:
	ldr r4, _08194FB0 @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x188]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08194FB4
	adds r0, #4
	b _08194FC0
	.align 2, 0
_08194FAC: .4byte 0x030046A4
_08194FB0: .4byte 0x00000256
_08194FB4:
	ldr r0, _08194FD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08194FC0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08194FD8
	cmp r3, #2
	beq _08194FDC
	b _08194FE0
	.align 2, 0
_08194FD4: .4byte 0x030046A4
_08194FD8:
	ldrb r0, [r5, #4]
	b _08194FDE
_08194FDC:
	ldrb r0, [r5]
_08194FDE:
	subs r2, r2, r0
_08194FE0:
	ldr r5, _08195020 @ =0x00000472
	adds r1, r7, r5
	strh r2, [r1]
	ldrh r0, [r7, #0xa]
	subs r0, r0, r2
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r7, r6
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r7, #0xa]
	ldr r0, [sp, #0x30]
	ldr r1, _08195024 @ =0x00000F84
	adds r2, r0, r1
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_08195004:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08195052
	bl VM_GetPC
	cmp r0, #0
	beq _08195028
	bl Script_GetValue
	adds r1, r0, #0
	b _0819502A
	.align 2, 0
_08195020: .4byte 0x00000472
_08195024: .4byte 0x00000F84
_08195028:
	movs r1, #0x2c
_0819502A:
	ldr r2, [sp, #0x30]
	ldr r3, _08195044 @ =0x00000ED2
	adds r0, r2, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08195048
	bl Script_GetValue
	adds r1, r0, #0
	b _0819504A
	.align 2, 0
_08195044: .4byte 0x00000ED2
_08195048:
	movs r1, #0x2c
_0819504A:
	ldr r4, [sp, #0x30]
	ldr r5, _081950C0 @ =0x00000ED3
	adds r0, r4, r5
	strb r1, [r0]
_08195052:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r6, [sp, #0x30]
	ldr r2, _081950C4 @ =0x00000EC8
	adds r1, r6, r2
	movs r3, #0
	movs r2, #0
	strh r0, [r1]
	movs r4, #0xed
	lsls r4, r4, #4
	adds r0, r6, r4
	strh r2, [r0]
	ldr r5, _081950C8 @ =0x00000F43
	adds r0, r6, r5
	strb r3, [r0]
	ldr r0, _081950CC @ =0x00000E42
	adds r1, r6, r0
	movs r0, #0x1e
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0819208c
	ldr r4, _081950D0 @ =0x000001A3
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x44]
	strh r0, [r1]
	ldr r2, [sp, #0x1b4]
	strh r4, [r2]
	ldr r3, [sp, #0x3c]
	strh r5, [r3]
	ldrh r0, [r1]
	adds r0, r0, r4
	ldr r4, [sp, #0x40]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x44]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0x134]
	ldrb r0, [r6]
	cmp r0, #0
	bne _081950D4
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081950E0
	.align 2, 0
_081950C0: .4byte 0x00000ED3
_081950C4: .4byte 0x00000EC8
_081950C8: .4byte 0x00000F43
_081950CC: .4byte 0x00000E42
_081950D0: .4byte 0x000001A3
_081950D4:
	ldr r2, [r7, #0x44]
	ldr r0, _08195118 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081950E0:
	ldr r1, [sp, #0x134]
	ldrb r0, [r1]
	cmp r0, #1
	bne _08195130
	ldr r2, [sp, #0x8c]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0819511C
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _08195126
	.align 2, 0
_08195118: .4byte 0x03003584
_0819511C:
	ldr r3, [sp, #0x8c]
	ldrb r0, [r3]
	bl FUN_080ecf60
	adds r4, r0, #1
_08195126:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08195130:
	adds r0, r7, #0
	bl FUN_08192bf4
	adds r0, r7, #0
	bl FUN_081901a4
	adds r0, r7, #0
	bl FUN_0818f994
	movs r5, #0xf5
	lsls r5, r5, #4
	ldr r4, [sp, #0x30]
	adds r5, r4, r5
	str r5, [sp, #0x1c0]
	ldr r6, _08195338 @ =0x00000F74
	adds r4, r4, r6
	mov r8, r4
	ldr r0, _0819533C @ =FUN_08194264
	mov sb, r0
	ldr r1, _08195340 @ =FUN_081911e0
	mov sl, r1
	ldr r2, _08195344 @ =FUN_08189608
	mov ip, r2
	movs r5, #0
	ldr r3, _08195348 @ =FUN_0818afd8
	ldr r4, _0819534C @ =FUN_0818b1c8
	ldr r2, _08195350 @ =FUN_080f62b0
	ldr r6, _08195354 @ =FUN_080f62ac
	str r6, [sp, #0x1b8]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x1c0]
	ldr r1, [sp, #0x54]
	str r0, [r1]
	mov r6, r8
	ldr r0, [sp, #0x58]
	str r6, [r0]
	mov r1, sb
	ldr r6, [sp, #0xd4]
	str r1, [r6]
	mov r0, sl
	ldr r1, [sp, #0xdc]
	str r0, [r1]
	mov r6, ip
	ldr r0, [sp, #0xe8]
	str r6, [r0]
	ldr r1, _08195358 @ =FUN_08189104
	ldr r6, [sp, #0xf8]
	str r1, [r6]
	ldr r0, _0819535C @ =FUN_081894fc
	ldr r1, [sp, #0xfc]
	str r0, [r1]
	ldr r6, _08195360 @ =FUN_0818960c
	ldr r0, [sp, #0x11c]
	str r6, [r0]
	ldr r1, [sp, #0x128]
	str r2, [r1]
	ldr r2, [sp, #0x138]
	str r3, [r2]
	ldr r3, [sp, #0x13c]
	str r4, [r3]
	ldr r0, _08195364 @ =FUN_080f44f4
	ldr r4, [sp, #0x140]
	str r0, [r4]
	ldr r0, _08195368 @ =FUN_080f410c
	ldr r6, [sp, #0x148]
	str r0, [r6]
	ldr r0, [sp, #0x12c]
	str r5, [r0]
	ldr r1, _0819536C @ =FUN_08189610
	ldr r2, [sp, #0xd8]
	str r1, [r2]
	ldr r3, [sp, #0x1b8]
	ldr r4, [sp, #0x16c]
	str r3, [r4]
	ldr r0, _08195370 @ =FUN_080f0430
	ldr r6, [sp, #0x170]
	str r0, [r6]
	movs r1, #1
	ldr r0, [sp, #0xe0]
	strb r1, [r0]
	ldr r0, _08195374 @ =0x085AD470
	ldr r2, [sp, #0x174]
	str r0, [r2]
	ldr r0, _08195378 @ =FUN_080e73c8
	ldr r3, [sp, #0x15c]
	str r0, [r3]
	ldr r4, [sp, #0x150]
	str r5, [r4]
	ldr r6, [sp, #0x160]
	str r5, [r6]
	ldr r0, [sp, #0x164]
	str r5, [r0]
	ldr r1, [sp, #0x168]
	str r5, [r1]
	ldr r2, [sp, #0x178]
	str r5, [r2]
	ldr r0, _0819537C @ =FUN_080f0320
	ldr r3, [sp, #0x17c]
	str r0, [r3]
	ldr r0, _08195380 @ =FUN_080eff14
	ldr r4, [sp, #0x110]
	str r0, [r4]
	ldr r0, _08195384 @ =FUN_080e72b0
	ldr r6, [sp, #0x154]
	str r0, [r6]
	ldr r0, _08195388 @ =FUN_0818afc0
	ldr r1, [sp, #0x14c]
	str r0, [r1]
	ldr r0, _0819538C @ =FUN_080f47c8
	ldr r2, [sp, #0x158]
	str r0, [r2]
	ldr r0, _08195390 @ =FUN_080f54e4
	ldr r3, [sp, #0x144]
	str r0, [r3]
	ldr r4, [sp, #0x100]
	str r5, [r4]
	ldr r0, _08195394 @ =FUN_080f6e64
	ldr r6, [sp, #0x180]
	str r0, [r6]
	ldr r0, _08195398 @ =FUN_080f64f0
	ldr r1, [sp, #0xe4]
	str r0, [r1]
	ldr r0, _0819539C @ =FUN_080f84d4
	ldr r2, [sp, #0x184]
	str r0, [r2]
	ldr r0, _081953A0 @ =FUN_080f624c
	ldr r3, [sp, #0x108]
	str r0, [r3]
	ldr r0, _081953A4 @ =FUN_080f56ec
	ldr r4, [sp, #0xec]
	str r0, [r4]
	ldr r0, _081953A8 @ =FUN_080f5b34
	ldr r6, [sp, #0xf0]
	str r0, [r6]
	ldr r0, _081953AC @ =FUN_080f5fac
	ldr r1, [sp, #0xf4]
	str r0, [r1]
	ldr r2, [sp, #0x104]
	str r5, [r2]
	movs r0, #0x28
	ldr r3, [sp, #0x7c]
	strb r0, [r3]
	ldr r4, _081953B0 @ =0x0000060C
	adds r1, r7, r4
	ldr r0, _081953B4 @ =0x085ADD74
	str r0, [r1]
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _081953B8 @ =FUN_0819023c
	str r0, [r1]
	ldr r1, _081953BC @ =0x000005FC
	adds r0, r7, r1
	str r5, [r0]
	ldr r2, _081953C0 @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _081953C4 @ =FUN_08192124
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081953C8 @ =FUN_0819218c
	str r0, [r1]
	subs r4, #4
	adds r1, r7, r4
	ldr r0, _081953CC @ =FUN_08192190
	str r0, [r1]
	subs r6, #0x6c
	adds r1, r7, r6
	ldr r0, _081953D0 @ =FUN_08194240
	str r0, [r1]
	ldr r0, _081953D4 @ =0x000005B4
	adds r1, r7, r0
	ldr r0, _081953D8 @ =FUN_08190824
	str r0, [r1]
	ldr r1, _081953DC @ =0x00100200
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, _081953E0 @ =0x02000008
	ldr r3, [sp, #0x60]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0xc0
	ldr r4, [sp, #0x1b0]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r6, #0xaa
	lsls r6, r6, #2
	adds r4, r7, r6
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r4, #0
	ldr r1, [sp, #0x188]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_08013ba8
	ldr r2, _081953E4 @ =0x0000044C
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _081953E8 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08013c94
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08013cb8
	adds r0, r4, #0
	bl FUN_080139a0
	ldr r3, _081953EC @ =0x0000044D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x6c]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081953FA
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08195328:
	bl VM_GetPC
	cmp r0, #0
	beq _081953F0
	bl Script_GetValue
	b _081953F2
	.align 2, 0
_08195338: .4byte 0x00000F74
_0819533C: .4byte FUN_08194264
_08195340: .4byte FUN_081911e0
_08195344: .4byte FUN_08189608
_08195348: .4byte FUN_0818afd8
_0819534C: .4byte FUN_0818b1c8
_08195350: .4byte FUN_080f62b0
_08195354: .4byte FUN_080f62ac
_08195358: .4byte FUN_08189104
_0819535C: .4byte FUN_081894fc
_08195360: .4byte FUN_0818960c
_08195364: .4byte FUN_080f44f4
_08195368: .4byte FUN_080f410c
_0819536C: .4byte FUN_08189610
_08195370: .4byte FUN_080f0430
_08195374: .4byte 0x085AD470
_08195378: .4byte FUN_080e73c8
_0819537C: .4byte FUN_080f0320
_08195380: .4byte FUN_080eff14
_08195384: .4byte FUN_080e72b0
_08195388: .4byte FUN_0818afc0
_0819538C: .4byte FUN_080f47c8
_08195390: .4byte FUN_080f54e4
_08195394: .4byte FUN_080f6e64
_08195398: .4byte FUN_080f64f0
_0819539C: .4byte FUN_080f84d4
_081953A0: .4byte FUN_080f624c
_081953A4: .4byte FUN_080f56ec
_081953A8: .4byte FUN_080f5b34
_081953AC: .4byte FUN_080f5fac
_081953B0: .4byte 0x0000060C
_081953B4: .4byte 0x085ADD74
_081953B8: .4byte FUN_0819023c
_081953BC: .4byte 0x000005FC
_081953C0: .4byte 0x000005AC
_081953C4: .4byte FUN_08192124
_081953C8: .4byte FUN_0819218c
_081953CC: .4byte FUN_08192190
_081953D0: .4byte FUN_08194240
_081953D4: .4byte 0x000005B4
_081953D8: .4byte FUN_08190824
_081953DC: .4byte 0x00100200
_081953E0: .4byte 0x02000008
_081953E4: .4byte 0x0000044C
_081953E8: .4byte 0x00001C1B
_081953EC: .4byte 0x0000044D
_081953F0:
	movs r0, #0
_081953F2:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08195328
_081953FA:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x70]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x50]
	strh r0, [r3]
	cmp r2, #0
	beq _08195432
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x5c]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08195432
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08195432:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x1b0]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08195444
	movs r0, #1
	b _08195446
_08195444:
	movs r0, #0
_08195446:
	cmp r0, #0
	beq _08195458
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x60]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08195458:
	cmp r2, #1
	beq _0819548C
	movs r0, #0
	ldr r1, [sp, #0x198]
	strb r0, [r1]
	ldr r2, [sp, #0x19c]
	strb r0, [r2]
	ldr r3, [sp, #0x1a0]
	strb r0, [r3]
	ldr r4, [sp, #0x48]
	str r0, [r4]
	movs r1, #1
	ldr r5, [sp, #0x1a8]
	strb r1, [r5]
	ldr r6, [sp, #0xfc]
	ldr r2, [r6]
	ldr r3, [sp, #0x1ac]
	strb r1, [r3]
	ldr r4, [sp, #0x1a4]
	strb r0, [r4]
	ldr r5, [sp, #0x9c]
	strb r0, [r5]
	ldr r6, [sp, #0xd0]
	str r2, [r6]
	ldr r1, [sp, #0x78]
	strh r0, [r1]
_0819548C:
	movs r1, #2
	ldr r2, [sp, #0x1b0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0819549C
	movs r0, #1
	b _0819549E
_0819549C:
	movs r0, #0
_0819549E:
	cmp r0, #0
	beq _081954B8
	ldr r0, _081954B4 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x4c]
	strh r0, [r4]
	b _081954C2
	.align 2, 0
_081954B4: .4byte 0x030046A0
_081954B8:
	ldr r0, [sp, #0x188]
	bl FUN_08241574
	ldr r5, [sp, #0x4c]
	strh r0, [r5]
_081954C2:
	movs r1, #0x40
	ldr r6, [sp, #0x1b0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081954D2
	movs r0, #1
	b _081954D4
_081954D2:
	movs r0, #0
_081954D4:
	cmp r0, #0
	beq _081954E4
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08195508 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081954E4:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _08195516
	ldr r0, _0819550C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x4c]
	ldrh r2, [r2]
	cmp r0, r2
	bne _08195510
	movs r0, #1
	b _08195512
	.align 2, 0
_08195508: .4byte 0xFFFFFEFF
_0819550C: .4byte 0x030046A0
_08195510:
	movs r0, #0
_08195512:
	cmp r0, #0
	bne _0819551E
_08195516:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_0819551E:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, [sp, #0x134]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08195606
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08195560
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08195568
_08195560:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08195568:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0819558C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08195594
_0819558C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08195594:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _081955CC @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _08195610
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081955D0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081955C4
	ldrb r0, [r4, #5]
_081955C4:
	subs r0, #1
	strh r0, [r4, #8]
	b _081955E0
	.align 2, 0
_081955CC: .4byte 0x0000FFFF
_081955D0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081955E0
	strh r1, [r4, #8]
_081955E0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08195610
	movs r0, #1
	strb r0, [r4, #7]
	b _08195610
_08195606:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08195610:
	movs r0, #0
	ldr r3, [sp, #0x80]
	str r0, [r3]
	ldr r0, _08195628 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0819562C
	movs r0, #1
	b _0819562E
	.align 2, 0
_08195628: .4byte 0x030047A4
_0819562C:
	movs r0, #0
_0819562E:
	cmp r0, #0
	bne _0819566E
	ldr r4, [sp, #0x8c]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08195656
	adds r0, r1, #0
	cmp r0, #7
	beq _08195656
	cmp r0, #6
	beq _08195656
	cmp r0, #0x15
	beq _08195656
	cmp r0, #0x14
	beq _08195656
	cmp r0, #0x17
	bne _0819566E
_08195656:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x1b0]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0819566E:
	adds r0, r7, #0
	bl FUN_0818e6fc
	movs r0, #2
	movs r2, #0
	ldr r6, [sp, #0x198]
	strb r2, [r6]
	ldr r1, [sp, #0x19c]
	strb r2, [r1]
	ldr r3, [sp, #0x1a0]
	strb r0, [r3]
	ldr r4, [sp, #0x48]
	str r2, [r4]
	movs r1, #1
	ldr r5, [sp, #0x1a8]
	strb r1, [r5]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	ldr r3, [sp, #0x1ac]
	strb r1, [r3]
	ldr r4, [sp, #0x1a4]
	strb r2, [r4]
	ldr r5, [sp, #0x9c]
	strb r1, [r5]
	ldr r6, [sp, #0xd0]
	str r0, [r6]
	ldr r0, [sp, #0x78]
	strh r2, [r0]
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_0818e2a4
	adds r0, r7, #0
	bl FUN_081941bc
	ldr r1, _0819575C @ =0x0000D636
	ldr r2, _08195760 @ =0x0000C102
	ldrb r3, [r7, #5]
	adds r0, r7, #0
	bl FUN_0818ee98
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x188]
	bl FUN_0819014c
	adds r0, r7, #0
	bl FUN_08190fb8
	adds r0, r7, #0
	bl FUN_0818e6fc
	adds r0, r7, #0
	bl FUN_081939c0
	ldr r1, [sp, #0x1b0]
	ldrh r0, [r1]
	ldr r2, [sp, #0xcc]
	strh r0, [r2]
	ldr r3, [sp, #0x74]
	ldrh r0, [r3]
	ldr r4, [sp, #0xc8]
	strh r0, [r4]
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	ldr r6, [sp, #0xa8]
	str r0, [r6]
	ldr r1, [sp, #0x60]
	ldr r0, [r1]
	ldr r2, [sp, #0xac]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xb0]
	strb r0, [r3]
	ldr r4, [sp, #0x198]
	ldrb r0, [r4]
	ldr r5, [sp, #0xb4]
	strb r0, [r5]
	ldr r6, [sp, #0x19c]
	ldrb r0, [r6]
	ldr r1, [sp, #0xb8]
	strb r0, [r1]
	ldr r2, [sp, #0x1a0]
	ldrb r0, [r2]
	ldr r3, [sp, #0xbc]
	strb r0, [r3]
	ldr r4, [sp, #0xd0]
	ldr r0, [r4]
	ldr r5, [sp, #0xc0]
	str r0, [r5]
	ldr r6, [sp, #0x9c]
	ldrb r0, [r6]
	ldr r1, [sp, #0xc4]
	strb r0, [r1]
	ldr r2, _08195764 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _08195768 @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _0819576C @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _08195770 @ =FUN_081942a0
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08195774 @ =EnemySerpent_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08195778
	movs r0, #0
	b _0819577C
	.align 2, 0
_0819575C: .4byte 0x0000D636
_08195760: .4byte 0x0000C102
_08195764: .4byte 0x0000057C
_08195768: .4byte FUN_080f09e0
_0819576C: .4byte 0x0000061C
_08195770: .4byte FUN_081942a0
_08195774: .4byte EnemySerpent_Destroy
_08195778:
	movs r0, #1
	rsbs r0, r0, #0
_0819577C:
	add sp, #0x1c4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemySerpent_Create
EnemySerpent_Create: @ 0x0819578C
	push {r4, r5, lr}
	ldr r5, _081957C0 @ =0x00000F94
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081957B8
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemySerpent_Init
	cmp r0, #0
	bge _081957B8
	adds r0, r4, #0
	bl EnemySerpent_Destroy
	adds r0, r4, #0
	bl Free
_081957B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081957C0: .4byte 0x00000F94

	thumb_func_start FUN_081957c4
FUN_081957c4: @ 0x081957C4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, [r5, #0x44]
	ldr r0, _08195820 @ =0x03002BE0
	mov r2, sp
	adds r4, r1, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r1, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _08195824 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08195828
	asrs r1, r0, #0xc
	b _0819582E
	.align 2, 0
_08195820: .4byte 0x03002BE0
_08195824: .4byte 0x085B0A08
_08195828:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819582E:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _08195850 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08195854
	asrs r1, r0, #0xc
	b _0819585A
	.align 2, 0
_08195850: .4byte 0x085B0A08
_08195854:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819585A:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r3, r5, r4
	strh r1, [r3]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	beq _08195880
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Div
	b _08195896
_08195880:
	cmp r1, #0
	beq _08195894
	mov r0, sp
	movs r4, #4
	ldrsh r0, [r0, r4]
	movs r2, #0
	ldrsh r1, [r3, r2]
	bl Div
	b _08195896
_08195894:
	movs r0, #0
_08195896:
	cmp r0, #0
	blt _0819589E
	asrs r0, r0, #1
	b _081958A4
_0819589E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081958A4:
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
