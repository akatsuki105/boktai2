	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081dfe74
FUN_081dfe74: @ 0x081DFE74
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r4, _081DFF04 @ =0x0000C091
	ldr r1, _081DFF08 @ =0x0000CD91
	adds r0, r4, #0
	bl GetFile
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r5, r7, r1
	str r0, [r5]
	ldr r1, _081DFF0C @ =0x0000A413
	adds r0, r4, #0
	bl GetFile
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r6, r7, r2
	str r0, [r6]
	movs r0, #0xa
	str r0, [sp, #0xc]
	ldr r2, [r5]
	movs r4, #0
	str r4, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #0xc
	str r0, [sp, #0xc]
	ldr r2, [r6]
	str r4, [sp]
	str r5, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081DFF10 @ =0x000092B3
	ldr r1, _081DFF14 @ =0x000026BB
	bl GetFile
	movs r2, #0xf3
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, #0x14
	str r0, [r1]
	ldr r1, _081DFF18 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DFF04: .4byte 0x0000C091
_081DFF08: .4byte 0x0000CD91
_081DFF0C: .4byte 0x0000A413
_081DFF10: .4byte 0x000092B3
_081DFF14: .4byte 0x000026BB
_081DFF18: .4byte 0x03004250

	thumb_func_start FUN_081dff1c
FUN_081dff1c: @ 0x081DFF1C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #2
	movs r1, #5
	movs r2, #0x1a
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #2
	movs r1, #0xc
	movs r2, #0x1a
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r5, #0
_081DFF4A:
	lsls r0, r5, #2
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r4, r4, r0
	ldr r0, [r4]
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r5, #1
	cmp r5, #1
	ble _081DFF4A
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dff7c
FUN_081dff7c: @ 0x081DFF7C
	push {r4, r5, lr}
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r5, r0, r1
	movs r4, #1
_081DFF86:
	ldm r5!, {r0}
	bl FUN_0804a210
	subs r4, #1
	cmp r4, #0
	bge _081DFF86
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dff98
FUN_081dff98: @ 0x081DFF98
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _081DFFB4 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_081DFFB4: .4byte 0x03003ED0

	thumb_func_start FUN_081dffb8
FUN_081dffb8: @ 0x081DFFB8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	movs r7, #0x91
	movs r0, #0
	bl FUN_081dff98
	adds r6, r0, #0
	cmp r5, #0
	ble _081DFFFC
_081DFFD0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl Div
	adds r1, r0, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r6]
	adds r6, #2
	muls r0, r5, r0
	subs r4, r4, r0
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	cmp r5, #0
	bgt _081DFFD0
_081DFFFC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e0004
FUN_081e0004: @ 0x081E0004
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldr r1, _081E0064 @ =0x0000A47C
	adds r0, r6, #0
	bl Video_GetAuxSprite
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r4, r5, r1
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	movs r2, #0
	movs r3, #0
	strh r2, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #0x11
	orrs r0, r1
	str r0, [r4]
	ldr r1, _081E0068 @ =0x00000377
	adds r0, r5, r1
	strb r3, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r4, r5, r0
	str r2, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081E006C @ =0x05000002
	bl CpuSet
	movs r0, #0x79
	strh r0, [r4]
	ldr r1, _081E0070 @ =0x0000038E
	adds r5, r5, r1
	movs r0, #0x40
	strh r0, [r5]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E0064: .4byte 0x0000A47C
_081E0068: .4byte 0x00000377
_081E006C: .4byte 0x05000002
_081E0070: .4byte 0x0000038E

	thumb_func_start FUN_081e0074
FUN_081e0074: @ 0x081E0074
	push {lr}
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r0, r1
	bl FUN_0822a4e0
	pop {r0}
	bx r0

	thumb_func_start FUN_081e0084
FUN_081e0084: @ 0x081E0084
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081E00E8 @ =0x0000CB05
	ldr r1, _081E00EC @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenMainSpriteFile
	movs r7, #0
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x18
_081E00AE:
	lsls r1, r7, #1
	movs r2, #0xd8
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	strh r4, [r0]
	ldrh r2, [r0]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r3, #0x10
	bl MainSprite_Add
	cmp r0, #0
	bne _081E00DE
	adds r6, #0x60
	adds r7, #1
	cmp r7, #7
	ble _081E00AE
_081E00DE:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E00E8: .4byte 0x0000CB05
_081E00EC: .4byte 0x0000DCC1

	thumb_func_start FUN_081e00f0
FUN_081e00f0: @ 0x081E00F0
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #0x40
	adds r0, #0x38
	movs r2, #0x80
	movs r1, #3
_081E00FC:
	strh r2, [r0]
	strh r4, [r0, #2]
	adds r0, #0x60
	subs r2, #8
	subs r1, #1
	cmp r1, #0
	bge _081E00FC
	movs r4, #0x78
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0x80
	movs r1, #3
_081E0116:
	strh r2, [r0]
	strh r4, [r0, #2]
	adds r0, #0x60
	subs r2, #8
	subs r1, #1
	cmp r1, #0
	bge _081E0116
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e012c
FUN_081e012c: @ 0x081E012C
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x20
	movs r2, #7
_081E0136:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081E0136
	pop {r0}
	bx r0

	thumb_func_start FUN_081e0148
FUN_081e0148: @ 0x081E0148
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #7
_081E0150:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E0150
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e0164
FUN_081e0164: @ 0x081E0164
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r2, #0
	lsls r7, r1, #2
	movs r2, #0
	ldr r0, _081E020C @ =0x000003E7
	cmp r5, r0
	ble _081E017E
	ldr r1, _081E0210 @ =0xFFFFFC18
_081E0176:
	adds r2, #1
	adds r5, r5, r1
	cmp r5, r0
	bgt _081E0176
_081E017E:
	lsls r4, r7, #1
	adds r0, r4, r7
	lsls r0, r0, #5
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #0x63
	ble _081E01A8
_081E01A0:
	adds r2, #1
	subs r5, #0x64
	cmp r5, #0x63
	bgt _081E01A0
_081E01A8:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0xd8
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #9
	ble _081E01CC
_081E01C4:
	adds r2, #1
	subs r5, #0xa
	cmp r5, #9
	bgt _081E01C4
_081E01CC:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x78
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #0
	ble _081E01F0
_081E01E8:
	adds r2, #1
	subs r5, #1
	cmp r5, #0
	bgt _081E01E8
_081E01F0:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x18
	adds r0, r6, r0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E020C: .4byte 0x000003E7
_081E0210: .4byte 0xFFFFFC18

	thumb_func_start FUN_081e0214
FUN_081e0214: @ 0x081E0214
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	mov r8, r1
	ldr r0, _081E0298 @ =0x000003EA
	add r0, ip
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r7, r0, #2
	ldr r4, _081E029C @ =0x030046B4
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _081E02A0 @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	ldr r6, _081E02A4 @ =0x085B0200
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r3, #7
	ands r2, r3
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r3
	movs r2, #0x64
	muls r0, r2, r0
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ands r1, r3
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r7, r7, r0
	ldr r0, _081E02A8 @ =0x0000270F
	cmp r7, r0
	ble _081E0282
	adds r7, r0, #0
_081E0282:
	mov r0, ip
	mov r1, r8
	adds r2, r7, #0
	bl FUN_081e0164
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E0298: .4byte 0x000003EA
_081E029C: .4byte 0x030046B4
_081E02A0: .4byte 0x000003FF
_081E02A4: .4byte 0x085B0200
_081E02A8: .4byte 0x0000270F

	thumb_func_start FUN_081e02ac
FUN_081e02ac: @ 0x081E02AC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081E02E0 @ =0x000003EA
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _081E02C6
	ldr r0, _081E02E4 @ =0x000002A5
	bl PlaySound_082406e0
_081E02C6:
	ldr r1, _081E02E8 @ =0x000003BA
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081E02D8
	adds r0, r4, #0
	movs r1, #0
	bl FUN_081e0214
_081E02D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E02E0: .4byte 0x000003EA
_081E02E4: .4byte 0x000002A5
_081E02E8: .4byte 0x000003BA

	thumb_func_start FUN_081e02ec
FUN_081e02ec: @ 0x081E02EC
	push {lr}
	adds r1, r0, #0
	ldr r0, _081E0320 @ =0x000003BA
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _081E031A
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081E031A
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r0, r1, #0
	movs r1, #0
	bl FUN_081e0164
	ldr r0, _081E0324 @ =0x00000167
	bl PlaySound_082406e0
_081E031A:
	pop {r0}
	bx r0
	.align 2, 0
_081E0320: .4byte 0x000003BA
_081E0324: .4byte 0x00000167

	thumb_func_start FUN_081e0328
FUN_081e0328: @ 0x081E0328
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081E033C @ =0x03002C68
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _081E0340
	movs r1, #1
	rsbs r1, r1, #0
	b _081E0344
	.align 2, 0
_081E033C: .4byte 0x03002C68
_081E0340:
	movs r0, #0x18
	ldrsh r1, [r1, r0]
_081E0344:
	ldr r0, [r4]
	cmp r0, #0
	bne _081E034E
	movs r0, #0
	b _081E035C
_081E034E:
	lsls r1, r1, #1
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
_081E035C:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r2, r3, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081E0384 @ =0x0000270F
	cmp r0, r1
	bls _081E0370
	strh r1, [r2]
_081E0370:
	ldrh r0, [r2]
	cmp r0, #0
	bne _081E0378
	strh r0, [r2]
_081E0378:
	ldr r1, [r4]
	cmp r1, #0
	bne _081E0388
	movs r1, #1
	rsbs r1, r1, #0
	b _081E038C
	.align 2, 0
_081E0384: .4byte 0x0000270F
_081E0388:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_081E038C:
	ldr r0, [r4]
	cmp r0, #0
	bne _081E0396
	movs r0, #0
	b _081E03A2
_081E0396:
	lsls r1, r1, #2
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
_081E03A2:
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r3, r1
	str r0, [r2]
	ldr r1, _081E03CC @ =0x0000270F
	cmp r0, r1
	ble _081E03B2
	str r1, [r2]
_081E03B2:
	ldr r0, [r2]
	ldr r1, _081E03D0 @ =0xFFFFD8F1
	cmp r0, r1
	bge _081E03BC
	str r1, [r2]
_081E03BC:
	ldr r2, _081E03D4 @ =0x000003BA
	adds r1, r3, r2
	movs r0, #0x5a
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E03CC: .4byte 0x0000270F
_081E03D0: .4byte 0xFFFFD8F1
_081E03D4: .4byte 0x000003BA

	thumb_func_start FUN_081e03d8
FUN_081e03d8: @ 0x081E03D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E049C @ =0x000003E9
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E0466
	adds r0, r6, #0
	bl FUN_081e012c
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r3, #0xf8
	lsls r3, r3, #2
	adds r4, r6, r3
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #6
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	bl FUN_081df908
	strb r5, [r7]
_081E0466:
	ldr r0, _081E04A0 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081E0474
	ldrb r1, [r0, #0x1c]
_081E0474:
	cmp r1, #0x16
	bne _081E0494
	ldr r1, _081E04A4 @ =FUN_081e04a8
	movs r2, #4
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r6, r3
	str r1, [r0]
	ldr r0, _081E049C @ =0x000003E9
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r2, [r0]
_081E0494:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E049C: .4byte 0x000003E9
_081E04A0: .4byte 0x03002C68
_081E04A4: .4byte FUN_081e04a8

	thumb_func_start FUN_081e04a8
FUN_081e04a8: @ 0x081E04A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E0500 @ =0x000003E9
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E04E4
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #6
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r3, _081E0504 @ =0x000003EA
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
_081E04E4:
	ldr r0, _081E0504 @ =0x000003EA
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0x3c
	bne _081E0538
	bl Save_WriteExtraToNextSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E050C
	ldr r1, _081E0508 @ =FUN_081e0660
	movs r2, #8
	b _081E0514
	.align 2, 0
_081E0500: .4byte 0x000003E9
_081E0504: .4byte 0x000003EA
_081E0508: .4byte FUN_081e0660
_081E050C:
	bl FUN_081df924
	ldr r1, _081E0530 @ =FUN_081e0544
	movs r2, #5
_081E0514:
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	ldr r0, _081E0534 @ =0x000003E9
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	b _081E053C
	.align 2, 0
_081E0530: .4byte FUN_081e0544
_081E0534: .4byte 0x000003E9
_081E0538:
	adds r0, #1
	strh r0, [r1]
_081E053C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e0544
FUN_081e0544: @ 0x081E0544
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081E057C @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081E0556
	ldrb r1, [r0, #0x1c]
_081E0556:
	cmp r1, #0x18
	bne _081E0576
	ldr r1, _081E0580 @ =FUN_081e0588
	movs r2, #6
	movs r4, #0xf4
	lsls r4, r4, #2
	adds r0, r3, r4
	str r1, [r0]
	ldr r0, _081E0584 @ =0x000003E9
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r2, [r0]
_081E0576:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E057C: .4byte 0x03002C68
_081E0580: .4byte FUN_081e0588
_081E0584: .4byte 0x000003E9

	thumb_func_start FUN_081e0588
FUN_081e0588: @ 0x081E0588
	push {r4, lr}
	adds r4, r0, #0
	bl Save_SwitchSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E05A0
	ldr r1, _081E059C @ =FUN_081e05cc
	movs r2, #7
	b _081E05A4
	.align 2, 0
_081E059C: .4byte FUN_081e05cc
_081E05A0:
	ldr r1, _081E05C4 @ =FUN_081e0660
	movs r2, #8
_081E05A4:
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081E05C8 @ =0x000003E9
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E05C4: .4byte FUN_081e0660
_081E05C8: .4byte 0x000003E9

	thumb_func_start FUN_081e05cc
FUN_081e05cc: @ 0x081E05CC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081E0630 @ =0x000003E9
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E060A
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #7
	bl FUN_0804a2f8
	ldr r0, _081E0634 @ =0x000002AE
	bl PlaySound_082406e0
	ldr r0, _081E0638 @ =0x000003EA
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
_081E060A:
	ldr r1, _081E0638 @ =0x000003EA
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x78
	bne _081E0640
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E063C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _081E064A
	.align 2, 0
_081E0630: .4byte 0x000003E9
_081E0634: .4byte 0x000002AE
_081E0638: .4byte 0x000003EA
_081E063C: .4byte 0x0000FFFF
_081E0640:
	cmp r0, #0x8c
	bls _081E064A
	bl FUN_081df940
	b _081E0654
_081E064A:
	ldr r2, _081E065C @ =0x000003EA
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E0654:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E065C: .4byte 0x000003EA

	thumb_func_start FUN_081e0660
FUN_081e0660: @ 0x081E0660
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E06B0 @ =0x000003E9
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E06A0
	bl FUN_08238bf4
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r0, [r4]
	subs r2, #8
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #5
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _081E06B4 @ =0x000003EA
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
_081E06A0:
	ldr r2, _081E06B4 @ =0x000003EA
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E06B8
	adds r0, #1
	strh r0, [r1]
	b _081E06C8
	.align 2, 0
_081E06B0: .4byte 0x000003E9
_081E06B4: .4byte 0x000003EA
_081E06B8:
	ldr r0, _081E06D0 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E06D4 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E06C8
	bl SoftReset_0823a928
_081E06C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E06D0: .4byte 0x030044E0
_081E06D4: .4byte 0x0000030F

	thumb_func_start FUN_081e06d8
FUN_081e06d8: @ 0x081E06D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _081E0794 @ =0x000003E9
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E06EA
	b _081E07EA
_081E06EA:
	adds r0, r5, #0
	bl FUN_081dff7c
	adds r0, r5, #0
	bl FUN_081e012c
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	movs r7, #0
	str r7, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r4, _081E0798 @ =0x030046A0
	ldr r0, [r4]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r2, r0, r3
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r6, r5, r0
	ldr r1, [r2]
	ldr r0, [r6]
	adds r1, r1, r0
	ldr r0, _081E079C @ =0x0000270F
	cmp r1, r0
	ble _081E0730
	adds r1, r0, #0
_081E0730:
	str r1, [r2]
	ldr r0, [r4]
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bge _081E073E
	str r7, [r1]
_081E073E:
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, [r4]
	adds r0, r0, r3
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	movs r2, #0xd
	movs r3, #2
	bl FUN_081dffb8
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #8
	str r1, [sp]
	movs r1, #1
	movs r2, #0xb
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	movs r3, #0xf5
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r6]
	cmp r0, #0
	bne _081E07A0
	ldr r0, [r4]
	movs r1, #4
	bl FUN_0804a2f8
	b _081E07B6
	.align 2, 0
_081E0794: .4byte 0x000003E9
_081E0798: .4byte 0x030046A0
_081E079C: .4byte 0x0000270F
_081E07A0:
	cmp r0, #0
	ble _081E07AE
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0804a2f8
	b _081E07B6
_081E07AE:
	ldr r0, [r4]
	movs r1, #3
	bl FUN_0804a2f8
_081E07B6:
	movs r0, #0xf8
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r1, [r4]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	cmp r2, #0
	bge _081E07CC
	rsbs r2, r2, #0
_081E07CC:
	adds r0, r1, #0
	movs r1, #0
	bl FUN_0804a3e4
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r3, _081E07FC @ =0x000003EA
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081E0800 @ =0x000003E9
	adds r0, r5, r1
	strb r2, [r0]
_081E07EA:
	ldr r2, _081E07FC @ =0x000003EA
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #9
	bhi _081E0804
	adds r0, #1
	strh r0, [r1]
	b _081E0832
	.align 2, 0
_081E07FC: .4byte 0x000003EA
_081E0800: .4byte 0x000003E9
_081E0804:
	ldr r0, _081E083C @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E0840 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E0832
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _081E0844 @ =FUN_081e03d8
	movs r2, #3
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	ldr r0, _081E0848 @ =0x000003E9
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
_081E0832:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E083C: .4byte 0x030044E0
_081E0840: .4byte 0x0000030F
_081E0844: .4byte FUN_081e03d8
_081E0848: .4byte 0x000003E9

	thumb_func_start FUN_081e084c
FUN_081e084c: @ 0x081E084C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081E08A8 @ =0x000003E9
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081E086E
	ldr r3, _081E08AC @ =0x000003BE
	adds r1, r5, r3
	movs r3, #0
	movs r2, #0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _081E08B0 @ =0x000003EA
	adds r0, r5, r1
	strh r2, [r0]
	strb r3, [r4]
_081E086E:
	ldr r3, _081E08B0 @ =0x000003EA
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0x3c
	bhi _081E087A
	b _081E09CA
_081E087A:
	movs r4, #0xef
	lsls r4, r4, #2
	adds r6, r5, r4
	ldrh r0, [r6]
	cmp r0, #0
	beq _081E0924
	ldr r1, _081E08AC @ =0x000003BE
	adds r7, r5, r1
	ldrh r4, [r7]
	subs r3, r0, r4
	cmp r3, #0
	bge _081E08BC
	adds r3, r3, r4
	ldr r2, _081E08B4 @ =0x030046A0
	ldr r1, [r2]
	ldr r4, _081E08B8 @ =0x00000912
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r6]
	subs r0, r0, r3
	b _081E08D0
	.align 2, 0
_081E08A8: .4byte 0x000003E9
_081E08AC: .4byte 0x000003BE
_081E08B0: .4byte 0x000003EA
_081E08B4: .4byte 0x030046A0
_081E08B8: .4byte 0x00000912
_081E08BC:
	ldr r2, _081E0910 @ =0x030046A0
	ldr r1, [r2]
	ldr r0, _081E0914 @ =0x00000912
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldrh r0, [r6]
	ldrh r1, [r7]
	subs r0, r0, r1
_081E08D0:
	strh r0, [r6]
	adds r3, r2, #0
	ldr r0, [r3]
	ldr r2, _081E0914 @ =0x00000912
	adds r1, r0, r2
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bge _081E08E6
	movs r0, #0
	strh r0, [r1]
_081E08E6:
	ldr r0, [r3]
	adds r2, r0, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, _081E0918 @ =0x0000270F
	cmp r0, r1
	ble _081E08F6
	strh r1, [r2]
_081E08F6:
	ldr r3, _081E091C @ =0x000003EA
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _081E0990
	ldr r0, _081E0920 @ =0x000002A5
	bl PlaySound_082406e0
	b _081E0990
	.align 2, 0
_081E0910: .4byte 0x030046A0
_081E0914: .4byte 0x00000912
_081E0918: .4byte 0x0000270F
_081E091C: .4byte 0x000003EA
_081E0920: .4byte 0x000002A5
_081E0924:
	ldr r0, _081E0958 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E095C @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E0990
	ldr r0, _081E0960 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r4, r0, r1
	cmp r0, #0
	bne _081E0940
	movs r4, #0
_081E0940:
	movs r0, #0xdd
	bl PlaySound_082406e0
	cmp r4, #0
	beq _081E0950
	ldrb r0, [r4]
	cmp r0, #1
	bne _081E0968
_081E0950:
	ldr r1, _081E0964 @ =FUN_081e03d8
	movs r2, #3
	b _081E096C
	.align 2, 0
_081E0958: .4byte 0x030044E0
_081E095C: .4byte 0x0000030F
_081E0960: .4byte 0x03002C68
_081E0964: .4byte FUN_081e03d8
_081E0968:
	ldr r1, _081E0988 @ =FUN_081e06d8
	movs r2, #2
_081E096C:
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	ldr r4, _081E098C @ =0x000003E9
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	b _081E09F8
	.align 2, 0
_081E0988: .4byte FUN_081e06d8
_081E098C: .4byte 0x000003E9
_081E0990:
	movs r2, #1
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E09A6
	movs r0, #1
	b _081E09A8
_081E09A6:
	movs r0, #0
_081E09A8:
	cmp r0, #0
	bne _081E09CA
	ldr r0, _081E0A00 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E0A04 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E09CA
	ldr r4, _081E0A08 @ =0x000003BE
	adds r1, r5, r4
	ldrh r0, [r1]
	lsls r0, r0, #3
	strh r0, [r1]
	movs r1, #1
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081E09CA:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_081e0164
	ldr r0, _081E0A0C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _081E0A10 @ =0x00000912
	adds r0, r0, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081e0164
	ldr r0, _081E0A14 @ =0x000003EA
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E09F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E0A00: .4byte 0x030044E0
_081E0A04: .4byte 0x0000030F
_081E0A08: .4byte 0x000003BE
_081E0A0C: .4byte 0x030046A0
_081E0A10: .4byte 0x00000912
_081E0A14: .4byte 0x000003EA

	thumb_func_start FUN_081e0a18
FUN_081e0a18: @ 0x081E0A18
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E0A54 @ =0x000003E9
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E0A32
	ldr r1, _081E0A58 @ =0x000003EA
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E0A32:
	ldr r3, _081E0A5C @ =0x000003BA
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	bne _081E0A64
	ldr r1, _081E0A60 @ =FUN_081e084c
	movs r2, #1
	adds r3, #0x16
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _081E0A54 @ =0x000003E9
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #0x18
	adds r0, r4, r3
	strb r2, [r0]
	b _081E0A8A
	.align 2, 0
_081E0A54: .4byte 0x000003E9
_081E0A58: .4byte 0x000003EA
_081E0A5C: .4byte 0x000003BA
_081E0A60: .4byte FUN_081e084c
_081E0A64:
	ldr r0, _081E0A90 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E0A94 @ =0x0000030B
	ands r0, r1
	cmp r0, #0
	beq _081E0A74
	movs r0, #1
	strh r0, [r2]
_081E0A74:
	adds r0, r4, #0
	bl FUN_081e02ac
	adds r0, r4, #0
	bl FUN_081e02ec
	ldr r0, _081E0A98 @ =0x000003EA
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E0A8A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E0A90: .4byte 0x030044E0
_081E0A94: .4byte 0x0000030B
_081E0A98: .4byte 0x000003EA

	thumb_func_start Entity501B_Update
Entity501B_Update: @ 0x081E0A9C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081E0AB4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081E0AC8
_081E0AB4:
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081E0AC6
	adds r0, r4, #0
	bl _call_via_r1
_081E0AC6:
	movs r0, #1
_081E0AC8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity501B_Destroy
Entity501B_Destroy: @ 0x081E0AD0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dff7c
	adds r0, r4, #0
	bl FUN_081e0148
	adds r0, r4, #0
	bl FUN_081e0074
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity501B_Init
Entity501B_Init: @ 0x081E0AEC
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081E0B0C
	bl FUN_0823d340
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081E0B26
_081E0B0C:
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081E0B2C
	bl FUN_0823d340
	movs r3, #0xf6
	lsls r3, r3, #2
	adds r1, r4, r3
	str r0, [r1]
	cmp r0, #0
	bne _081E0B2C
_081E0B26:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E0BB6
_081E0B2C:
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081dfe74
	adds r0, r4, #0
	bl FUN_081dff1c
	adds r0, r4, #0
	bl FUN_081e0084
	adds r0, r4, #0
	bl FUN_081e00f0
	ldr r0, _081E0BC0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _081E0BC4 @ =0x00000912
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081e0164
	adds r0, r4, #0
	bl FUN_081e0004
	adds r0, r4, #0
	bl FUN_081e0328
	ldr r1, _081E0BC8 @ =FUN_081e0a18
	movs r2, #0
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081E0BCC @ =0x000003E9
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E0BD0 @ =0x0000FFFF
	str r0, [sp, #4]
	str r2, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #1
_081E0BB6:
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E0BC0: .4byte 0x030046A0
_081E0BC4: .4byte 0x00000912
_081E0BC8: .4byte FUN_081e0a18
_081E0BCC: .4byte 0x000003E9
_081E0BD0: .4byte 0x0000FFFF

	thumb_func_start Entity501B_Create
Entity501B_Create: @ 0x081E0BD4
	push {r4, lr}
	movs r1, #0xfb
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E0C0C
	ldr r1, _081E0C04 @ =Entity501B_Update
	ldr r2, _081E0C08 @ =Entity501B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity501B_Init
	cmp r0, #0
	bge _081E0C0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E0C0E
	.align 2, 0
_081E0C04: .4byte Entity501B_Update
_081E0C08: .4byte Entity501B_Destroy
_081E0C0C:
	adds r0, r4, #0
_081E0C0E:
	pop {r4}
	pop {r1}
	bx r1
