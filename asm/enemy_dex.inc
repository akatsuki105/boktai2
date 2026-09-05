	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0820d00c
FUN_0820d00c: @ 0x0820D00C
	push {lr}
	adds r1, r0, #0
	ldr r0, _0820D024 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r2, r0, r3
	cmp r1, #0
	blt _0820D028
	asrs r0, r1, #5
	b _0820D02E
	.align 2, 0
_0820D024: .4byte 0x030046A0
_0820D028:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0820D02E:
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0820D046
	movs r0, #0
	b _0820D048
_0820D046:
	movs r0, #1
_0820D048:
	pop {r1}
	bx r1

	thumb_func_start FUN_0820d04c
FUN_0820d04c: @ 0x0820D04C
	push {lr}
	ldr r2, _0820D078 @ =0x030046A0
	ldr r2, [r2]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r2, r2, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	lsrs r1, r0, #5
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0820D07C
	movs r0, #0
	b _0820D07E
	.align 2, 0
_0820D078: .4byte 0x030046A0
_0820D07C:
	movs r0, #1
_0820D07E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820d084
FUN_0820d084: @ 0x0820D084
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0820cbfc
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_0820cc0c
	adds r6, r0, #0
	movs r4, #0
	cmp r4, r5
	bge _0820D0B0
_0820D09C:
	adds r0, r6, r4
	bl FUN_0820d00c
	cmp r0, #0
	bne _0820D0AA
	movs r0, #0
	b _0820D0B2
_0820D0AA:
	adds r4, #1
	cmp r4, r5
	blt _0820D09C
_0820D0B0:
	movs r0, #1
_0820D0B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820d0b8
FUN_0820d0b8: @ 0x0820D0B8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0820cbfc
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_0820cc0c
	adds r7, r0, #0
	movs r6, #0
	movs r4, #0
	cmp r6, r5
	bge _0820D0E4
_0820D0D2:
	adds r0, r7, r4
	bl FUN_0820d00c
	cmp r0, #1
	bne _0820D0DE
	adds r6, #1
_0820D0DE:
	adds r4, #1
	cmp r4, r5
	blt _0820D0D2
_0820D0E4:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820d0ec
FUN_0820d0ec: @ 0x0820D0EC
	push {lr}
	ldr r0, _0820D114 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r1, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0820D11C
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r1, [r1]
	ldr r0, _0820D118 @ =0x01FFFFFF
	cmp r1, r0
	bne _0820D11C
	movs r0, #1
	b _0820D11E
	.align 2, 0
_0820D114: .4byte 0x030046A0
_0820D118: .4byte 0x01FFFFFF
_0820D11C:
	movs r0, #0
_0820D11E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820d124
FUN_0820d124: @ 0x0820D124
	push {lr}
	movs r0, #0x6b
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820D134
	bl Script_GetValue
_0820D134:
	pop {r0}
	bx r0

	thumb_func_start FUN_0820d138
FUN_0820d138: @ 0x0820D138
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0x24
	ldrb r2, [r0]
	cmp r2, #0
	bne _0820D152
	add r0, sp, #4
	movs r1, #0x13
	strh r2, [r0]
	strh r1, [r0, #2]
	strh r2, [r0, #4]
	b _0820D160
_0820D152:
	add r1, sp, #4
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	ldr r2, _0820D17C @ =0x05000002
	bl CpuSet
_0820D160:
	ldr r1, _0820D180 @ =0x0000104C
	adds r0, r4, r1
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	str r1, [r0]
	str r2, [r0, #4]
	ldr r3, _0820D184 @ =0x000010AC
	adds r0, r4, r3
	str r1, [r0]
	str r2, [r0, #4]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820D17C: .4byte 0x05000002
_0820D180: .4byte 0x0000104C
_0820D184: .4byte 0x000010AC

	thumb_func_start FUN_0820d188
FUN_0820d188: @ 0x0820D188
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0820d0ec
	cmp r0, #0
	beq _0820D1B4
	ldr r0, _0820D1AC @ =0x00000F14
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0820D1B0 @ =0x00000F74
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	b _0820D1C8
	.align 2, 0
_0820D1AC: .4byte 0x00000F14
_0820D1B0: .4byte 0x00000F74
_0820D1B4:
	ldr r0, _0820D1F8 @ =0x00000F14
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0820D1FC @ =0x00000F74
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
_0820D1C8:
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0820D210
	cmp r0, #0
	bne _0820D204
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r0, [r0]
	bl FUN_0820cc8c
	bl FUN_0820d084
	cmp r0, #0
	beq _0820D204
	ldr r1, _0820D200 @ =0x00000FD4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0820D20E
	.align 2, 0
_0820D1F8: .4byte 0x00000F14
_0820D1FC: .4byte 0x00000F74
_0820D200: .4byte 0x00000FD4
_0820D204:
	ldr r1, _0820D218 @ =0x00000FD4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0820D20E:
	str r1, [r0]
_0820D210:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820D218: .4byte 0x00000FD4

	thumb_func_start FUN_0820d21c
FUN_0820d21c: @ 0x0820D21C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x28
	movs r4, #7
_0820D226:
	ldm r5!, {r0}
	bl FUN_0804a210
	subs r4, #1
	cmp r4, #0
	bge _0820D226
	ldr r0, _0820D24C @ =0x0000110E
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	bl FUN_0822b644
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0820D24C: .4byte 0x0000110E

	thumb_func_start FUN_0820d250
FUN_0820d250: @ 0x0820D250
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x26
	ldrb r0, [r4]
	bl FUN_0820d00c
	adds r6, r0, #0
	adds r0, r5, #0
	bl FUN_0820d21c
	ldr r0, [r5, #0x28]
	ldr r2, _0820D2A0 @ =0x00001110
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x28]
	movs r1, #2
	str r1, [sp]
	movs r1, #8
	movs r2, #3
	movs r3, #0x14
	bl FUN_0804a38c
	ldrb r0, [r4]
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820D2A4
	ldr r0, [r5, #0x28]
	ldrb r1, [r4]
	bl FUN_0804a2f8
	b _0820D2AC
	.align 2, 0
_0820D2A0: .4byte 0x00001110
_0820D2A4:
	ldr r0, [r5, #0x28]
	movs r1, #0x39
	bl FUN_0804a2f8
_0820D2AC:
	ldr r0, [r5, #0x28]
	bl FUN_0804a1f0
	adds r0, r5, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #1
	beq _0820D314
	cmp r0, #1
	bgt _0820D2C6
	cmp r0, #0
	beq _0820D2D0
	b _0820D5E4
_0820D2C6:
	cmp r0, #2
	beq _0820D35C
	cmp r0, #3
	beq _0820D398
	b _0820D5E4
_0820D2D0:
	cmp r6, #0
	bne _0820D2D6
	b _0820D5E4
_0820D2D6:
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	bl FUN_0820cc8c
	adds r4, r0, #0
	ldr r0, [r5, #0x2c]
	ldr r3, _0820D310 @ =0x00001254
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x2c]
	movs r1, #4
	str r1, [sp]
	movs r1, #1
	movs r2, #0x10
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r5, #0x2c]
	adds r1, r4, #0
	bl FUN_0804a2f8
	ldr r0, [r5, #0x2c]
	bl FUN_0804a1f0
	b _0820D5E4
	.align 2, 0
_0820D310: .4byte 0x00001254
_0820D314:
	cmp r6, #0
	bne _0820D31A
	b _0820D5E4
_0820D31A:
	ldr r0, [r5, #0x30]
	ldr r2, _0820D354 @ =0x00001248
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x30]
	movs r1, #4
	str r1, [sp]
	movs r1, #1
	movs r2, #0x10
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r5, #0x30]
	adds r2, r5, #0
	adds r2, #0x26
	ldr r3, _0820D358 @ =0x00001114
	adds r1, r5, r3
	ldrb r2, [r2]
	adds r1, r1, r2
	ldrb r1, [r1]
	bl FUN_0804a2f8
	ldr r0, [r5, #0x30]
	bl FUN_0804a1f0
	b _0820D5E4
	.align 2, 0
_0820D354: .4byte 0x00001248
_0820D358: .4byte 0x00001114
_0820D35C:
	cmp r6, #0
	beq _0820D37C
	ldr r0, _0820D374 @ =0x0000110E
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _0820D378 @ =0x0000FFFE
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2]
	b _0820D5E4
	.align 2, 0
_0820D374: .4byte 0x0000110E
_0820D378: .4byte 0x0000FFFE
_0820D37C:
	ldr r1, _0820D390 @ =0x0000110E
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _0820D394 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	bl FUN_08049e5c
	b _0820D5E4
	.align 2, 0
_0820D390: .4byte 0x0000110E
_0820D394: .4byte 0x0000FFFE
_0820D398:
	cmp r6, #0
	bne _0820D39E
	b _0820D5E4
_0820D39E:
	adds r4, r5, #0
	adds r4, #0x26
	ldrb r0, [r4]
	lsls r0, r0, #2
	ldr r2, _0820D404 @ =0x00001150
	adds r0, r0, r2
	adds r6, r5, r0
	movs r3, #0x10
	mov r8, r3
	ldr r0, [r5, #0x40]
	adds r2, #0xe8
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x40]
	movs r7, #2
	str r7, [sp]
	movs r1, #1
	movs r2, #0x10
	movs r3, #6
	bl FUN_0804a38c
	ldr r0, [r5, #0x40]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r5, #0x40]
	bl FUN_0804a1f0
	ldrb r0, [r6, #1]
	mov sb, r4
	cmp r0, #0xff
	bne _0820D40C
	ldr r0, [r5, #0x38]
	ldr r3, _0820D408 @ =0x0000123C
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x38]
	str r7, [sp]
	movs r1, #6
	movs r2, #0x10
	movs r3, #0x14
	bl FUN_0804a38c
	ldr r0, [r5, #0x38]
	movs r1, #0
	b _0820D490
	.align 2, 0
_0820D404: .4byte 0x00001150
_0820D408: .4byte 0x0000123C
_0820D40C:
	mov r1, sb
	ldrb r0, [r1]
	movs r1, #0
	bl FUN_0820d04c
	cmp r0, #0
	beq _0820D4A0
	ldrb r0, [r6, #1]
	cmp r0, #0xfe
	bhi _0820D4C8
	ldrb r0, [r6]
	cmp r0, #1
	beq _0820D440
	cmp r0, #1
	bgt _0820D430
	cmp r0, #0
	beq _0820D436
	b _0820D4C8
_0820D430:
	cmp r0, #2
	beq _0820D472
	b _0820D4C8
_0820D436:
	ldr r0, [r5, #0x38]
	ldr r2, _0820D43C @ =0x00001234
	b _0820D476
	.align 2, 0
_0820D43C: .4byte 0x00001234
_0820D440:
	ldr r0, [r5, #0x38]
	movs r3, #0x92
	lsls r3, r3, #5
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x38]
	str r7, [sp]
	movs r1, #6
	movs r2, #0x10
	movs r3, #0x14
	bl FUN_0804a38c
	ldr r0, [r5, #0x38]
	ldrb r1, [r6, #1]
	bl FUN_0804a2f8
	ldr r0, [r5, #0x38]
	adds r2, r5, #0
	adds r2, #0x49
	movs r1, #0
	bl FUN_0804a40c
	b _0820D494
_0820D472:
	ldr r0, [r5, #0x38]
	ldr r2, _0820D49C @ =0x00001244
_0820D476:
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x38]
	str r7, [sp]
	movs r1, #6
	movs r2, #0x10
	movs r3, #0x14
	bl FUN_0804a38c
	ldr r0, [r5, #0x38]
	ldrb r1, [r6, #1]
_0820D490:
	bl FUN_0804a2f8
_0820D494:
	ldr r0, [r5, #0x38]
	bl FUN_0804a1f0
	b _0820D4C8
	.align 2, 0
_0820D49C: .4byte 0x00001244
_0820D4A0:
	ldr r0, [r5, #0x38]
	ldr r3, _0820D51C @ =0x00001110
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x38]
	str r7, [sp]
	movs r1, #6
	movs r2, #0x10
	movs r3, #0x14
	bl FUN_0804a38c
	ldr r0, [r5, #0x38]
	movs r1, #0x39
	bl FUN_0804a2f8
	ldr r0, [r5, #0x38]
	bl FUN_0804a1f0
_0820D4C8:
	movs r0, #2
	add r8, r0
	ldr r0, [r5, #0x44]
	ldr r2, _0820D520 @ =0x00001238
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x44]
	movs r4, #2
	str r4, [sp]
	movs r1, #1
	mov r2, r8
	movs r3, #6
	bl FUN_0804a38c
	ldr r0, [r5, #0x44]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r5, #0x44]
	bl FUN_0804a1f0
	ldrb r0, [r6, #3]
	cmp r0, #0xff
	bne _0820D528
	ldr r0, [r5, #0x3c]
	ldr r3, _0820D524 @ =0x0000123C
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x3c]
	str r4, [sp]
	movs r1, #6
	mov r2, r8
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r5, #0x3c]
	movs r1, #0
	b _0820D5AC
	.align 2, 0
_0820D51C: .4byte 0x00001110
_0820D520: .4byte 0x00001238
_0820D524: .4byte 0x0000123C
_0820D528:
	mov r1, sb
	ldrb r0, [r1]
	movs r1, #1
	bl FUN_0820d04c
	cmp r0, #0
	beq _0820D5BC
	ldrb r0, [r6, #3]
	cmp r0, #0xfe
	bhi _0820D5E4
	ldrb r0, [r6, #2]
	cmp r0, #1
	beq _0820D55C
	cmp r0, #1
	bgt _0820D54C
	cmp r0, #0
	beq _0820D552
	b _0820D5E4
_0820D54C:
	cmp r0, #2
	beq _0820D58E
	b _0820D5E4
_0820D552:
	ldr r0, [r5, #0x3c]
	ldr r2, _0820D558 @ =0x00001234
	b _0820D592
	.align 2, 0
_0820D558: .4byte 0x00001234
_0820D55C:
	ldr r0, [r5, #0x3c]
	movs r3, #0x92
	lsls r3, r3, #5
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x3c]
	str r4, [sp]
	movs r1, #6
	mov r2, r8
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r5, #0x3c]
	ldrb r1, [r6, #3]
	bl FUN_0804a2f8
	ldr r0, [r5, #0x3c]
	adds r2, r5, #0
	adds r2, #0x49
	movs r1, #0
	bl FUN_0804a40c
	b _0820D5B0
_0820D58E:
	ldr r0, [r5, #0x3c]
	ldr r2, _0820D5B8 @ =0x00001244
_0820D592:
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x3c]
	str r4, [sp]
	movs r1, #6
	mov r2, r8
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r5, #0x3c]
	ldrb r1, [r6, #3]
_0820D5AC:
	bl FUN_0804a2f8
_0820D5B0:
	ldr r0, [r5, #0x3c]
	bl FUN_0804a1f0
	b _0820D5E4
	.align 2, 0
_0820D5B8: .4byte 0x00001244
_0820D5BC:
	ldr r0, [r5, #0x3c]
	ldr r3, _0820D5F4 @ =0x00001110
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5, #0x3c]
	str r4, [sp]
	movs r1, #6
	mov r2, r8
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r5, #0x3c]
	movs r1, #0x39
	bl FUN_0804a2f8
	ldr r0, [r5, #0x3c]
	bl FUN_0804a1f0
_0820D5E4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820D5F4: .4byte 0x00001110

	thumb_func_start FUN_0820d5f8
FUN_0820d5f8: @ 0x0820D5F8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0820D628 @ =0x0000110E
	adds r4, r5, r0
	ldrh r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0820D630
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0820D67E
	bl FUN_08049e5c
	bl FUN_08049fa8
	ldrh r0, [r4]
	ldr r1, _0820D62C @ =0x0000FFFD
	ands r1, r0
	movs r0, #4
	orrs r1, r0
	strh r1, [r4]
	b _0820D67E
	.align 2, 0
_0820D628: .4byte 0x0000110E
_0820D62C: .4byte 0x0000FFFD
_0820D630:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0820D67E
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0820D650
	bl FUN_08049e5c
	bl FUN_08049f5c
	ldrh r1, [r4]
	ldr r0, _0820D684 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4]
_0820D650:
	bl FUN_08049e5c
	ldr r1, _0820D688 @ =0x0000124C
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r1, r5, #0
	adds r1, #0x26
	ldrb r1, [r1]
	adds r0, r0, r1
	bl Textbox_LookupString
	bl FUN_08049e30
	ldrh r1, [r4]
	ldr r0, _0820D68C @ =0x0000FFF7
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, _0820D684 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4]
_0820D67E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0820D684: .4byte 0x0000FFFB
_0820D688: .4byte 0x0000124C
_0820D68C: .4byte 0x0000FFF7

	thumb_func_start FUN_0820d690
FUN_0820d690: @ 0x0820D690
	push {lr}
	adds r3, r0, #0
	ldr r1, _0820D6DC @ =0x0000110C
	adds r0, r3, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x1f
	cmp r0, #9
	ble _0820D6BC
	movs r2, #0x1b
	cmp r0, #0x11
	ble _0820D6BC
	movs r2, #0x12
	cmp r0, #0x19
	ble _0820D6BC
	movs r2, #0xa
	cmp r0, #0x21
	ble _0820D6BC
	movs r2, #0x1b
	cmp r0, #0x29
	bgt _0820D6BC
	movs r2, #0x12
_0820D6BC:
	ldr r0, _0820D6DC @ =0x0000110C
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x31
	ble _0820D6D2
	movs r0, #0
	strh r0, [r1]
_0820D6D2:
	ldr r1, _0820D6E0 @ =0x00001104
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0820D6DC: .4byte 0x0000110C
_0820D6E0: .4byte 0x00001104

	thumb_func_start FUN_0820d6e4
FUN_0820d6e4: @ 0x0820D6E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	str r0, [sp, #0x18]
	ldr r0, _0820DA98 @ =0x0000CB05
	ldr r1, _0820DA9C @ =0x00005EBF
	bl GetFile
	adds r1, r0, #0
	ldr r2, [sp, #0x18]
	adds r2, #0x4c
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	ldr r4, [sp, #0x18]
	adds r4, #0x4c
	adds r0, r4, #0
	bl OpenSpriteSetFile
	add r2, sp, #0x10
	movs r0, #0
	adds r1, r2, #0
	strh r0, [r1]
	strh r0, [r2, #2]
	strh r0, [r2, #4]
	strh r0, [r2, #6]
	mov sl, r0
	str r4, [sp, #0x20]
	ldr r5, [sp, #0x18]
	adds r5, #0x6c
	str r5, [sp, #0x24]
	ldr r0, [sp, #0x18]
	adds r0, #0x48
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x18]
	adds r1, #0x8e
	str r1, [sp, #0x28]
	ldr r2, [sp, #0x18]
	adds r2, #0xcc
	str r2, [sp, #0x30]
	ldr r3, [sp, #0x18]
	ldr r4, _0820DAA0 @ =0x000005AC
	adds r3, r3, r4
	mov sb, r3
	movs r5, #0
	str r5, [sp, #0x34]
	ldr r0, [sp, #0x18]
	adds r0, #0xb4
	str r0, [sp, #0x2c]
_0820D752:
	ldr r1, [sp, #0x34]
	ldr r2, _0820DAA4 @ =0x0000084C
	adds r0, r1, r2
	ldr r3, [sp, #0x18]
	adds r4, r3, r0
	movs r5, #1
_0820D75E:
	movs r0, #0
	mov r8, r0
	str r0, [sp]
	movs r7, #2
	str r7, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r2, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0820D75E
	mov r2, r8
	str r2, [sp]
	str r7, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	mov r0, sb
	ldr r1, [sp, #0x20]
	movs r2, #0xa
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r4, #0x60
	add sb, r4
	ldr r5, [sp, #0x34]
	adds r5, #0xc0
	str r5, [sp, #0x34]
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _0820D752
	add r1, sp, #0x10
	adds r0, r1, #0
	mov r2, r8
	strh r2, [r0]
	strh r2, [r1, #2]
	strh r2, [r1, #4]
	strh r2, [r1, #6]
	ldr r7, [sp, #0x20]
	movs r3, #2
	mov sb, r3
	mov r8, r6
	ldr r4, [sp, #0x18]
	ldr r0, _0820DAA8 @ =0x00000E4C
	adds r5, r4, r0
	ldr r1, _0820DAAC @ =0x00000D8C
	adds r4, r4, r1
	add r6, sp, #0x10
	movs r2, #1
	mov sl, r2
_0820D7D6:
	movs r3, #0
	str r3, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r2, #0
	str r2, [sp]
	mov r3, sb
	str r3, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #0x60
	movs r1, #1
	rsbs r1, r1, #0
	add sl, r1
	mov r2, sl
	cmp r2, #0
	bge _0820D7D6
	movs r3, #2
	mov sl, r3
	add r1, sp, #0x10
	movs r4, #0
	adds r0, r1, #0
	strh r4, [r0]
	strh r4, [r1, #2]
	strh r4, [r1, #4]
	strh r4, [r1, #6]
	ldr r5, [sp, #0x18]
	ldr r1, _0820DAB0 @ =0x0000102C
	adds r0, r5, r1
	str r4, [sp]
	str r3, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x22
	movs r3, #0x10
	bl FUN_0822f3fc
	ldr r3, [sp, #0x18]
	ldr r1, _0820DAB4 @ =0x0000108C
	adds r0, r3, r1
	str r4, [sp]
	mov r2, sl
	str r2, [sp, #4]
	str r5, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x23
	movs r3, #0x10
	bl FUN_0822f3fc
	add r4, sp, #0x10
	movs r6, #0
	ldr r0, [sp, #0x18]
	ldr r1, _0820DAB8 @ =0x00000F0C
	adds r5, r0, r1
	movs r2, #0x20
	mov r8, r2
	movs r7, #0
	movs r3, #1
	mov sl, r3
_0820D876:
	mov r0, r8
	strh r0, [r4]
	strh r6, [r4, #2]
	strh r6, [r4, #4]
	strh r6, [r4, #6]
	str r6, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x20]
	movs r2, #0xd
	movs r3, #0x10
	bl FUN_0822f3fc
	ldr r2, [sp, #0x18]
	ldr r3, _0820DABC @ =0x00000F14
	adds r1, r2, r3
	adds r1, r1, r7
	ldr r0, [r1]
	movs r2, #1
	mov sb, r2
	orrs r0, r2
	str r0, [r1]
	adds r5, #0x60
	movs r3, #0x60
	add r8, r3
	adds r7, #0x60
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r1, sl
	cmp r1, #0
	bge _0820D876
	movs r2, #2
	mov sl, r2
	add r5, sp, #0x10
	movs r4, #0
	adds r0, r5, #0
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	ldr r3, [sp, #0x18]
	ldr r1, _0820DAC0 @ =0x00000FCC
	adds r0, r3, r1
	str r4, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	adds r3, r5, #0
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0xe
	movs r3, #0x10
	bl FUN_0822f3fc
	ldr r0, [sp, #0x18]
	ldr r2, _0820DAC4 @ =0x00000FD4
	adds r1, r0, r2
	ldr r0, [r1]
	mov r3, sb
	orrs r0, r3
	str r0, [r1]
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	ldr r1, [sp, #0x18]
	ldr r2, _0820DAC8 @ =0x0000048C
	adds r0, r1, r2
	str r4, [sp]
	mov r3, sl
	str r3, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0xf
	movs r3, #0x10
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	ldr r3, [sp, #0x18]
	ldr r1, _0820DACC @ =0x000004EC
	adds r0, r3, r1
	str r4, [sp]
	mov r2, sl
	str r2, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x10
	movs r3, #0x10
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	ldr r2, [sp, #0x18]
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r2, r3
	str r4, [sp]
	mov r1, sl
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x18
	movs r3, #0x10
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	movs r6, #0
	ldr r5, [sp, #0x18]
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r4, r5, r0
_0820D988:
	ldr r1, _0820DAD0 @ =0x085AF090
	lsls r0, r6, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r5, #0
	str r5, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r4, #0x60
	adds r6, #1
	cmp r6, #4
	ble _0820D988
	add r1, sp, #0x10
	adds r0, r1, #0
	strh r5, [r0]
	strh r5, [r1, #2]
	strh r5, [r1, #4]
	strh r5, [r1, #6]
	movs r6, #0
	ldr r2, [sp, #0x18]
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r4, r2, r3
_0820D9C8:
	ldr r0, _0820DAD4 @ =0x085AF0A4
	lsls r1, r6, #2
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r5, #0
	str r5, [sp]
	movs r0, #2
	mov r8, r0
	str r0, [sp, #4]
	movs r7, #0x3c
	str r7, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r4, #0x60
	adds r6, #1
	cmp r6, #2
	ble _0820D9C8
	add r4, sp, #0x10
	adds r0, r4, #0
	strh r5, [r0]
	strh r5, [r4, #2]
	strh r5, [r4, #4]
	strh r5, [r4, #6]
	ldr r2, [sp, #0x18]
	ldr r3, _0820DAD8 @ =0x0000054C
	adds r0, r2, r3
	str r5, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r7, [sp, #8]
	adds r2, r4, #0
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0xc
	movs r3, #0x10
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r5, [r0]
	strh r5, [r4, #2]
	strh r5, [r4, #4]
	strh r5, [r4, #6]
	str r5, [sp]
	mov r3, r8
	str r3, [sp, #4]
	str r7, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x20]
	movs r2, #0x16
	movs r3, #0x10
	bl FUN_0822f3fc
	ldr r1, [sp, #0x1c]
	ldrb r0, [r1]
	lsls r0, r0, #4
	adds r0, #8
	ldr r2, [sp, #0x28]
	strh r0, [r2]
	add r0, sp, #0x10
	strh r5, [r0]
	strh r5, [r4, #2]
	strh r5, [r4, #4]
	strh r5, [r4, #6]
	str r5, [sp]
	mov r3, r8
	str r3, [sp, #4]
	str r7, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x20]
	movs r2, #0x17
	movs r3, #0x10
	bl FUN_0822f3fc
	ldr r4, [sp, #0x2c]
	ldr r0, [r4]
	ldr r5, [sp, #0x18]
	ldr r1, _0820DADC @ =0x000010EC
	adds r4, r5, r1
	ldr r2, _0820DAE0 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	ldr r2, [sp, #0x2c]
	str r4, [r2]
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r1, r5, r3
	str r4, [r1]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0820DA98: .4byte 0x0000CB05
_0820DA9C: .4byte 0x00005EBF
_0820DAA0: .4byte 0x000005AC
_0820DAA4: .4byte 0x0000084C
_0820DAA8: .4byte 0x00000E4C
_0820DAAC: .4byte 0x00000D8C
_0820DAB0: .4byte 0x0000102C
_0820DAB4: .4byte 0x0000108C
_0820DAB8: .4byte 0x00000F0C
_0820DABC: .4byte 0x00000F14
_0820DAC0: .4byte 0x00000FCC
_0820DAC4: .4byte 0x00000FD4
_0820DAC8: .4byte 0x0000048C
_0820DACC: .4byte 0x000004EC
_0820DAD0: .4byte 0x085AF090
_0820DAD4: .4byte 0x085AF0A4
_0820DAD8: .4byte 0x0000054C
_0820DADC: .4byte 0x000010EC
_0820DAE0: .4byte 0x04000008

	thumb_func_start FUN_0820dae4
FUN_0820dae4: @ 0x0820DAE4
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r5, r0, #0
	str r1, [sp, #0x10]
	ldr r0, _0820DB80 @ =0x0000C091
	ldr r1, _0820DB84 @ =0x00004F8F
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r6, #1
	str r6, [sp, #4]
	add r0, sp, #0x10
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #2
	movs r1, #0
	bl SetBGPrioDirect
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0820DB88 @ =0x000092B3
	ldr r1, _0820DB8C @ =0x0000A41A
	bl GetFile
	adds r1, r0, #0
	adds r0, #0x14
	str r0, [r5, #0x1c]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, _0820DB90 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
	ldr r0, _0820DB94 @ =0x03003F60
	movs r1, #0x10
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x22]
	movs r0, #3
	movs r1, #3
	bl SetBGPrioDirect
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, _0820DB98 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #9
	str r0, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #3
	movs r1, #4
	movs r2, #6
	movs r3, #8
	bl FUN_0822bdb8
	movs r0, #0
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0820DB80: .4byte 0x0000C091
_0820DB84: .4byte 0x00004F8F
_0820DB88: .4byte 0x000092B3
_0820DB8C: .4byte 0x0000A41A
_0820DB90: .4byte 0x030043F0
_0820DB94: .4byte 0x03003F60
_0820DB98: .4byte 0x03003E78

	thumb_func_start FUN_0820db9c
FUN_0820db9c: @ 0x0820DB9C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r7, r0, #0
	adds r0, #0x24
	ldrb r5, [r0]
	cmp r5, #0
	beq _0820DBBA
	cmp r5, #1
	bne _0820DBB8
	b _0820DEF4
_0820DBB8:
	b _0820E06E
_0820DBBA:
	ldr r0, [r7, #0x74]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r7, #0x74]
	adds r1, r7, #0
	adds r1, #0xd4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0820DC98 @ =0x00000494
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	ldr r3, _0820DC9C @ =0x000004F4
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0820DCA0 @ =0x00000554
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0820d21c
	adds r4, r7, #0
	adds r4, #0x25
	ldrb r0, [r4]
	bl FUN_0820cbdc
	str r0, [sp, #0x14]
	ldrb r0, [r4]
	bl FUN_0820cbec
	mov sb, r0
	movs r1, #0
	mov r8, r1
	str r4, [sp, #0x34]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r3, r3, r7
	mov sl, r3
	ldr r0, _0820DCA4 @ =0x00000854
	adds r0, r7, r0
	str r0, [sp, #0x40]
	ldr r1, _0820DCA8 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x28]
	adds r2, r7, #0
	adds r2, #0x4c
	str r2, [sp, #0x3c]
	ldr r3, _0820DCAC @ =0x00000D94
	adds r3, r7, r3
	str r3, [sp, #0x30]
	ldr r0, _0820DCB0 @ =0x00000E54
	adds r0, r7, r0
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0x26
	str r1, [sp, #0x38]
	ldr r2, _0820DCB4 @ =0x00000D8C
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	ldr r3, _0820DCB8 @ =0x00000E4C
	adds r3, r7, r3
	str r3, [sp, #0x20]
	cmp r5, sb
	bge _0820DCD8
	adds r6, r7, #0
	adds r6, #0x28
	movs r4, #5
_0820DC64:
	ldr r0, [r6]
	ldr r2, _0820DCBC @ =0x00001110
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #2
	str r1, [sp]
	movs r1, #6
	adds r2, r4, #0
	movs r3, #0x14
	bl FUN_0804a38c
	ldr r5, [sp, #0x14]
	add r5, r8
	adds r0, r5, #0
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820DCC0
	ldr r0, [r6]
	adds r1, r5, #0
	bl FUN_0804a2f8
	b _0820DCC8
	.align 2, 0
_0820DC98: .4byte 0x00000494
_0820DC9C: .4byte 0x000004F4
_0820DCA0: .4byte 0x00000554
_0820DCA4: .4byte 0x00000854
_0820DCA8: .4byte 0x000005B4
_0820DCAC: .4byte 0x00000D94
_0820DCB0: .4byte 0x00000E54
_0820DCB4: .4byte 0x00000D8C
_0820DCB8: .4byte 0x00000E4C
_0820DCBC: .4byte 0x00001110
_0820DCC0:
	ldr r0, [r6]
	movs r1, #0x39
	bl FUN_0804a2f8
_0820DCC8:
	ldm r6!, {r0}
	bl FUN_0804a1f0
	adds r4, #2
	movs r3, #1
	add r8, r3
	cmp r8, sb
	blt _0820DC64
_0820DCD8:
	movs r3, #1
	ldr r1, [sp, #0x1c]
	movs r2, #4
_0820DCDE:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820DCDE
	movs r3, #1
	mov r1, sl
	movs r2, #2
_0820DCF2:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820DCF2
	movs r5, #0
	movs r3, #0
	ldr r1, [sp, #0x34]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _0820DD86
	lsls r0, r0, #2
	ldr r1, _0820DD18 @ =_0820DD1C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820DD18: .4byte _0820DD1C
_0820DD1C: @ jump table
	.4byte _0820DD40 @ case 0
	.4byte _0820DD46 @ case 1
	.4byte _0820DD4C @ case 2
	.4byte _0820DD56 @ case 3
	.4byte _0820DD5E @ case 4
	.4byte _0820DD64 @ case 5
	.4byte _0820DD6E @ case 6
	.4byte _0820DD74 @ case 7
	.4byte _0820DD7E @ case 8
_0820DD40:
	movs r1, #0
	movs r2, #0
	b _0820DD50
_0820DD46:
	movs r1, #0
	movs r2, #1
	b _0820DD50
_0820DD4C:
	movs r1, #0
	movs r2, #2
_0820DD50:
	movs r5, #0x70
	movs r3, #0x13
	b _0820DD8A
_0820DD56:
	movs r1, #1
	movs r2, #1
	rsbs r2, r2, #0
	b _0820DD8A
_0820DD5E:
	movs r1, #2
	movs r2, #0
	b _0820DD68
_0820DD64:
	movs r1, #2
	movs r2, #1
_0820DD68:
	movs r5, #0x60
	movs r3, #0x13
	b _0820DD8A
_0820DD6E:
	movs r1, #3
	movs r2, #0
	b _0820DD78
_0820DD74:
	movs r1, #3
	movs r2, #1
_0820DD78:
	movs r5, #0x80
	movs r3, #0x13
	b _0820DD8A
_0820DD7E:
	movs r1, #4
	movs r2, #1
	rsbs r2, r2, #0
	b _0820DD8A
_0820DD86:
	movs r1, #0
	movs r2, #1
_0820DD8A:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x1c]
	adds r0, r1, r0
	ldr r1, [r0]
	movs r6, #2
	rsbs r6, r6, #0
	ands r1, r6
	str r1, [r0]
	cmp r2, #0
	blt _0820DDC2
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #5
	mov r0, sl
	adds r2, r0, r1
	ldr r0, [r2]
	ands r0, r6
	str r0, [r2]
	adds r1, r7, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r5, [r0]
	ldr r0, _0820DEE4 @ =0x0000038E
	adds r1, r1, r0
	strh r3, [r1]
_0820DDC2:
	movs r1, #0
	ldr r2, [sp, #0x40]
	mov r8, r2
	movs r4, #1
_0820DDCA:
	lsls r5, r1, #1
	adds r6, r1, #1
	adds r0, r5, r1
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820DDD8:
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DDD8
	adds r1, r5, r1
	lsls r1, r1, #5
	ldr r0, [sp, #0x28]
	adds r1, r0, r1
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, r6, #0
	cmp r1, #6
	ble _0820DDCA
	ldr r1, [sp, #0x34]
	ldrb r0, [r1]
	bl FUN_0820cbec
	mov sl, r0
	ldr r2, [sp, #0x34]
	ldrb r0, [r2]
	bl FUN_0820cbdc
	adds r0, #1
	str r0, [sp, #0x18]
	movs r3, #0
	mov sb, r3
	cmp sb, sl
	bge _0820DE6A
	ldr r0, _0820DEE8 @ =0x000005CC
	adds r5, r7, r0
	ldr r4, [sp, #0x28]
	movs r1, #0x28
	mov r8, r1
	ldr r2, _0820DEEC @ =0x0000084C
	adds r6, r7, r2
_0820DE26:
	ldr r2, [sp, #0x18]
	add r2, sb
	movs r3, #0
	str r3, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	adds r0, r6, #0
	ldr r1, [sp, #0x3c]
	movs r3, #2
	bl FUN_082376a4
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r0, #0x28
	strh r0, [r5]
	mov r1, r8
	strh r1, [r5, #2]
	adds r5, #0x60
	adds r4, #0x60
	movs r2, #0x10
	add r8, r2
	adds r6, #0xc0
	movs r3, #1
	add sb, r3
	cmp sb, sl
	blt _0820DE26
_0820DE6A:
	movs r4, #1
	ldr r2, [sp, #0x24]
	ldr r1, [sp, #0x30]
	movs r3, #1
_0820DE72:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DE72
	movs r4, #0
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	bl FUN_0820cc8c
	mov r8, r0
	bl FUN_0820d0b8
	adds r2, r0, #0
	str r4, [sp]
	movs r0, #0x98
	str r0, [sp, #4]
	movs r6, #0x13
	str r6, [sp, #8]
	movs r5, #8
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x3c]
	movs r3, #2
	bl FUN_082376a4
	mov r0, r8
	bl FUN_0820cbfc
	adds r2, r0, #0
	str r4, [sp]
	movs r0, #0xb0
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x3c]
	movs r3, #2
	bl FUN_082376a4
	ldr r2, _0820DEF0 @ =0x0000125C
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_0820fea8
	adds r0, r7, #0
	bl FUN_0820d138
	b _0820E06E
	.align 2, 0
_0820DEE4: .4byte 0x0000038E
_0820DEE8: .4byte 0x000005CC
_0820DEEC: .4byte 0x0000084C
_0820DEF0: .4byte 0x0000125C
_0820DEF4:
	ldr r0, [r7, #0x74]
	orrs r0, r5
	str r0, [r7, #0x74]
	adds r1, r7, #0
	adds r1, #0xd4
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _0820E038 @ =0x00000494
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r3, _0820E03C @ =0x000004F4
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _0820E040 @ =0x00000554
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0820d21c
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r1, r1, r7
	mov sl, r1
	ldr r2, _0820E044 @ =0x00000854
	adds r2, r7, r2
	str r2, [sp, #0x40]
	ldr r3, _0820E048 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x28]
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #0x3c]
	ldr r1, _0820E04C @ =0x00000D94
	adds r1, r7, r1
	str r1, [sp, #0x30]
	ldr r2, _0820E050 @ =0x00000E54
	adds r2, r7, r2
	str r2, [sp, #0x24]
	adds r3, r7, #0
	adds r3, #0x26
	str r3, [sp, #0x38]
	ldr r0, _0820E054 @ =0x0000084C
	adds r0, r0, r7
	mov sb, r0
	movs r2, #1
	movs r3, #0xca
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r3, #4
_0820DF74:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DF74
	movs r1, #1
	mov r2, sl
	movs r3, #2
_0820DF88:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DF88
	adds r0, r7, #0
	bl FUN_0820d250
	movs r1, #0
	ldr r0, [sp, #0x40]
	mov r8, r0
	movs r6, #1
_0820DFA4:
	lsls r4, r1, #1
	adds r5, r1, #1
	adds r0, r4, r1
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820DFB2:
	ldr r0, [r2]
	orrs r0, r6
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DFB2
	adds r1, r4, r1
	lsls r1, r1, #5
	ldr r0, [sp, #0x28]
	adds r1, r0, r1
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	adds r1, r5, #0
	cmp r1, #6
	ble _0820DFA4
	ldr r1, [sp, #0x38]
	ldrb r2, [r1]
	adds r2, #1
	movs r1, #0
	str r1, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r0, sb
	ldr r1, [sp, #0x3c]
	movs r3, #2
	bl FUN_082376a4
	movs r4, #1
	ldr r2, [sp, #0x24]
	ldr r1, [sp, #0x30]
	movs r3, #1
_0820DFFE:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DFFE
	ldr r2, _0820E058 @ =0x0000125C
	adds r4, r7, r2
	ldr r0, [r4]
	ldr r3, [sp, #0x38]
	ldrb r1, [r3]
	bl FUN_0820fe98
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820E05C
	ldr r0, [r4]
	bl FUN_0820feb0
	b _0820E062
	.align 2, 0
_0820E038: .4byte 0x00000494
_0820E03C: .4byte 0x000004F4
_0820E040: .4byte 0x00000554
_0820E044: .4byte 0x00000854
_0820E048: .4byte 0x000005B4
_0820E04C: .4byte 0x00000D94
_0820E050: .4byte 0x00000E54
_0820E054: .4byte 0x0000084C
_0820E058: .4byte 0x0000125C
_0820E05C:
	ldr r0, [r4]
	bl FUN_0820fea8
_0820E062:
	adds r0, r7, #0
	bl FUN_0820d188
	adds r0, r7, #0
	bl FUN_0820d138
_0820E06E:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820e080
FUN_0820e080: @ 0x0820E080
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	adds r3, #0x24
	movs r2, #0
	strb r1, [r3]
	ldr r1, _0820E0A8 @ =0x0000114D
	adds r0, r4, r1
	strb r2, [r0]
	ldrb r1, [r3]
	adds r0, r4, #0
	bl FUN_0820dae4
	adds r0, r4, #0
	bl FUN_0820db9c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820E0A8: .4byte 0x0000114D

	thumb_func_start EnemyDexMenu_Update
EnemyDexMenu_Update: @ 0x0820E0AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp, #0x14]
	movs r4, #0
	adds r0, r7, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	bne _0820E0CC
	b _0820E548
_0820E0CC:
	cmp r0, #1
	bgt _0820E0D6
	cmp r0, #0
	beq _0820E0DE
	b _0820E730
_0820E0D6:
	cmp r0, #2
	bne _0820E0DC
	b _0820E748
_0820E0DC:
	b _0820E730
_0820E0DE:
	ldr r0, _0820E0FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0820E10E
	adds r1, r7, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	beq _0820E100
	subs r0, #1
	b _0820E102
	.align 2, 0
_0820E0FC: .4byte 0x030044E0
_0820E100:
	movs r0, #8
_0820E102:
	strb r0, [r1]
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0820E13A
_0820E10E:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0820E134
	adds r1, r7, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #7
	bhi _0820E128
	adds r0, #1
	strb r0, [r1]
	b _0820E12A
_0820E128:
	strb r4, [r1]
_0820E12A:
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #1
_0820E134:
	cmp r4, #0
	bne _0820E13A
	b _0820E420
_0820E13A:
	adds r4, r7, #0
	adds r4, #0x25
	ldrb r0, [r4]
	bl FUN_0820cbdc
	adds r5, r7, #0
	adds r5, #0x26
	movs r1, #0
	strb r0, [r5]
	adds r0, r7, #0
	adds r0, #0x48
	strb r1, [r0]
	movs r1, #1
	str r1, [sp, #0x14]
	adds r0, r7, #0
	bl FUN_0820d21c
	ldrb r0, [r4]
	bl FUN_0820cbdc
	mov sl, r0
	ldrb r0, [r4]
	bl FUN_0820cbec
	mov sb, r0
	movs r2, #0
	mov r8, r2
	str r4, [sp, #0x2c]
	str r5, [sp, #0x30]
	movs r3, #0xca
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x28]
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r0, r7, r0
	str r0, [sp, #0x40]
	ldr r1, _0820E1EC @ =0x00000854
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _0820E1F0 @ =0x000005B4
	adds r2, r7, r2
	str r2, [sp, #0x24]
	adds r3, r7, #0
	adds r3, #0x4c
	str r3, [sp, #0x34]
	ldr r0, _0820E1F4 @ =0x00000D94
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _0820E1F8 @ =0x00000E54
	adds r1, r7, r1
	str r1, [sp, #0x20]
	ldr r2, _0820E1FC @ =0x00000D8C
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r3, _0820E200 @ =0x00000E4C
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	cmp r8, sb
	bge _0820E220
	adds r4, #3
	movs r5, #5
_0820E1B6:
	ldr r0, [r4]
	ldr r2, _0820E204 @ =0x00001110
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #2
	str r1, [sp]
	movs r1, #6
	adds r2, r5, #0
	movs r3, #0x14
	bl FUN_0804a38c
	mov r6, sl
	add r6, r8
	adds r0, r6, #0
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820E208
	ldr r0, [r4]
	adds r1, r6, #0
	bl FUN_0804a2f8
	b _0820E210
	.align 2, 0
_0820E1EC: .4byte 0x00000854
_0820E1F0: .4byte 0x000005B4
_0820E1F4: .4byte 0x00000D94
_0820E1F8: .4byte 0x00000E54
_0820E1FC: .4byte 0x00000D8C
_0820E200: .4byte 0x00000E4C
_0820E204: .4byte 0x00001110
_0820E208:
	ldr r0, [r4]
	movs r1, #0x39
	bl FUN_0804a2f8
_0820E210:
	ldm r4!, {r0}
	bl FUN_0804a1f0
	adds r5, #2
	movs r3, #1
	add r8, r3
	cmp r8, sb
	blt _0820E1B6
_0820E220:
	movs r3, #1
	ldr r1, [sp, #0x28]
	movs r2, #4
_0820E226:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820E226
	movs r3, #1
	ldr r1, [sp, #0x40]
	movs r2, #2
_0820E23A:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820E23A
	movs r6, #0
	movs r3, #0
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _0820E2CE
	lsls r0, r0, #2
	ldr r1, _0820E260 @ =_0820E264
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820E260: .4byte _0820E264
_0820E264: @ jump table
	.4byte _0820E288 @ case 0
	.4byte _0820E28E @ case 1
	.4byte _0820E294 @ case 2
	.4byte _0820E29E @ case 3
	.4byte _0820E2A6 @ case 4
	.4byte _0820E2AC @ case 5
	.4byte _0820E2B6 @ case 6
	.4byte _0820E2BC @ case 7
	.4byte _0820E2C6 @ case 8
_0820E288:
	movs r1, #0
	movs r2, #0
	b _0820E298
_0820E28E:
	movs r1, #0
	movs r2, #1
	b _0820E298
_0820E294:
	movs r1, #0
	movs r2, #2
_0820E298:
	movs r6, #0x70
	movs r3, #0x13
	b _0820E2D2
_0820E29E:
	movs r1, #1
	movs r2, #1
	rsbs r2, r2, #0
	b _0820E2D2
_0820E2A6:
	movs r1, #2
	movs r2, #0
	b _0820E2B0
_0820E2AC:
	movs r1, #2
	movs r2, #1
_0820E2B0:
	movs r6, #0x60
	movs r3, #0x13
	b _0820E2D2
_0820E2B6:
	movs r1, #3
	movs r2, #0
	b _0820E2C0
_0820E2BC:
	movs r1, #3
	movs r2, #1
_0820E2C0:
	movs r6, #0x80
	movs r3, #0x13
	b _0820E2D2
_0820E2C6:
	movs r1, #4
	movs r2, #1
	rsbs r2, r2, #0
	b _0820E2D2
_0820E2CE:
	movs r1, #0
	movs r2, #1
_0820E2D2:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x28]
	adds r0, r1, r0
	ldr r1, [r0]
	movs r4, #2
	rsbs r4, r4, #0
	ands r1, r4
	str r1, [r0]
	cmp r2, #0
	blt _0820E30A
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #5
	ldr r0, [sp, #0x40]
	adds r2, r0, r1
	ldr r0, [r2]
	ands r0, r4
	str r0, [r2]
	adds r1, r7, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r6, [r0]
	ldr r0, _0820E44C @ =0x0000038E
	adds r1, r1, r0
	strh r3, [r1]
_0820E30A:
	movs r1, #0
	ldr r2, [sp, #0x44]
	mov r8, r2
	movs r5, #1
_0820E312:
	lsls r6, r1, #1
	adds r4, r1, #1
	adds r0, r6, r1
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820E320:
	ldr r0, [r2]
	orrs r0, r5
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820E320
	adds r1, r6, r1
	lsls r1, r1, #5
	ldr r0, [sp, #0x24]
	adds r1, r0, r1
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	adds r1, r4, #0
	cmp r1, #6
	ble _0820E312
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	bl FUN_0820cbec
	mov sl, r0
	ldr r2, [sp, #0x2c]
	ldrb r0, [r2]
	bl FUN_0820cbdc
	adds r0, #1
	str r0, [sp, #0x18]
	movs r3, #0
	mov sb, r3
	cmp sb, sl
	bge _0820E3B2
	ldr r0, _0820E450 @ =0x000005CC
	adds r6, r7, r0
	ldr r4, [sp, #0x24]
	movs r1, #0x28
	mov r8, r1
	ldr r2, _0820E454 @ =0x0000084C
	adds r5, r7, r2
_0820E36E:
	ldr r2, [sp, #0x18]
	add r2, sb
	movs r3, #0
	str r3, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	adds r0, r5, #0
	ldr r1, [sp, #0x34]
	movs r3, #2
	bl FUN_082376a4
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r0, #0x28
	strh r0, [r6]
	mov r1, r8
	strh r1, [r6, #2]
	adds r6, #0x60
	adds r4, #0x60
	movs r2, #0x10
	add r8, r2
	adds r5, #0xc0
	movs r3, #1
	add sb, r3
	cmp sb, sl
	blt _0820E36E
_0820E3B2:
	movs r4, #1
	ldr r2, [sp, #0x20]
	ldr r1, [sp, #0x3c]
	movs r3, #1
_0820E3BA:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820E3BA
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	bl FUN_0820cc8c
	mov r8, r0
	bl FUN_0820d0b8
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #0x98
	str r0, [sp, #4]
	movs r6, #0x13
	str r6, [sp, #8]
	movs r5, #8
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x34]
	movs r3, #2
	bl FUN_082376a4
	mov r0, r8
	bl FUN_0820cbfc
	adds r2, r0, #0
	str r4, [sp]
	movs r0, #0xb0
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x34]
	movs r3, #2
	bl FUN_082376a4
	adds r0, r7, #0
	bl FUN_0820d188
_0820E420:
	ldr r0, _0820E458 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0820E47E
	adds r6, r7, #0
	adds r6, #0x26
	ldrb r1, [r6]
	cmp r1, #0
	beq _0820E47E
	adds r4, r7, #0
	adds r4, #0x48
	ldrb r0, [r4]
	cmp r0, #0
	beq _0820E45C
	subs r0, r1, #1
	strb r0, [r6]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _0820E476
	.align 2, 0
_0820E44C: .4byte 0x0000038E
_0820E450: .4byte 0x000005CC
_0820E454: .4byte 0x0000084C
_0820E458: .4byte 0x030044E0
_0820E45C:
	adds r5, r7, #0
	adds r5, #0x25
	ldrb r0, [r5]
	bl FUN_0820cbec
	subs r0, #1
	strb r0, [r4]
	ldrb r0, [r5]
	bl FUN_0820cbdc
	ldrb r1, [r4]
	adds r1, r1, r0
	strb r1, [r6]
_0820E476:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0820E4DE
_0820E47E:
	ldr r0, _0820E4BC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0820E4D8
	adds r6, r7, #0
	adds r6, #0x26
	ldrb r0, [r6]
	cmp r0, #0x37
	bhi _0820E4D8
	adds r5, r7, #0
	adds r5, #0x48
	ldrb r4, [r5]
	movs r2, #0x25
	adds r2, r2, r7
	mov r8, r2
	ldrb r0, [r2]
	bl FUN_0820cbec
	subs r0, #1
	cmp r4, r0
	bge _0820E4C0
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0820E4CE
	.align 2, 0
_0820E4BC: .4byte 0x030044E0
_0820E4C0:
	mov r3, r8
	ldrb r0, [r3]
	bl FUN_0820cbdc
	movs r1, #0
	strb r0, [r6]
	strb r1, [r5]
_0820E4CE:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	str r0, [sp, #0x14]
_0820E4D8:
	ldr r1, [sp, #0x14]
	cmp r1, #0
	beq _0820E4EE
_0820E4DE:
	adds r0, r7, #0
	adds r0, #0x48
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #8
	adds r1, r7, #0
	adds r1, #0x8e
	strh r0, [r1]
_0820E4EE:
	ldr r4, _0820E53C @ =0x030044E0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0820E50E
	adds r0, r7, #0
	movs r1, #1
	bl FUN_0820e080
	adds r0, r7, #0
	bl FUN_0820d188
	movs r0, #0xdd
	bl PlaySound_082406e0
_0820E50E:
	ldrh r1, [r4, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0820E51A
	b _0820E730
_0820E51A:
	ldr r2, _0820E540 @ =0x00001258
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0820E52A
	movs r1, #0
	bl Script_ExecById
_0820E52A:
	ldr r0, _0820E544 @ =0x00000119
	bl PlaySound_082406e0
	adds r1, r7, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	b _0820E730
	.align 2, 0
_0820E53C: .4byte 0x030044E0
_0820E540: .4byte 0x00001258
_0820E544: .4byte 0x00000119
_0820E548:
	ldr r0, _0820E564 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0820E574
	adds r1, r7, #0
	adds r1, #0x27
	ldrb r0, [r1]
	cmp r0, #0
	beq _0820E568
	subs r0, #1
	b _0820E56A
	.align 2, 0
_0820E564: .4byte 0x030044E0
_0820E568:
	movs r0, #3
_0820E56A:
	strb r0, [r1]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0820E59E
_0820E574:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0820E598
	adds r1, r7, #0
	adds r1, #0x27
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0820E58C
	adds r0, #1
	strb r0, [r1]
	b _0820E58E
_0820E58C:
	strb r4, [r1]
_0820E58E:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r3, #1
	str r3, [sp, #0x14]
_0820E598:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _0820E5B2
_0820E59E:
	adds r0, r7, #0
	adds r0, #0x27
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r7, #0
	adds r1, #0xee
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0820d250
_0820E5B2:
	ldr r0, _0820E5D0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0820E5E2
	adds r1, r7, #0
	adds r1, #0x26
	ldrb r0, [r1]
	cmp r0, #0x37
	bhi _0820E5D4
	adds r0, #1
	b _0820E5D6
	.align 2, 0
_0820E5D0: .4byte 0x030044E0
_0820E5D4:
	movs r0, #0
_0820E5D6:
	strb r0, [r1]
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0820E614
_0820E5E2:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0820E610
	adds r0, r7, #0
	adds r0, #0x26
	ldrb r1, [r0]
	str r0, [sp, #0x30]
	cmp r1, #0
	beq _0820E600
	subs r0, r1, #1
	ldr r1, [sp, #0x30]
	strb r0, [r1]
	b _0820E606
_0820E600:
	movs r0, #0x38
	ldr r2, [sp, #0x30]
	strb r0, [r2]
_0820E606:
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #1
_0820E610:
	cmp r4, #0
	beq _0820E6D0
_0820E614:
	adds r0, r7, #0
	bl FUN_0820d250
	movs r4, #0
	adds r3, r7, #0
	adds r3, #0x26
	str r3, [sp, #0x30]
	ldr r0, _0820E6B0 @ =0x000005B4
	adds r0, r7, r0
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0x4c
	str r1, [sp, #0x34]
	ldr r2, _0820E6B4 @ =0x0000084C
	adds r2, r2, r7
	mov sb, r2
	ldr r3, _0820E6B8 @ =0x00000854
	adds r3, r3, r7
	mov r8, r3
	movs r5, #1
_0820E63C:
	lsls r1, r4, #1
	adds r6, r4, #1
	adds r0, r1, r4
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820E64A:
	ldr r0, [r2]
	orrs r0, r5
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820E64A
	adds r1, r1, r4
	lsls r1, r1, #5
	ldr r0, [sp, #0x24]
	adds r1, r0, r1
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	adds r4, r6, #0
	cmp r4, #6
	ble _0820E63C
	ldr r1, [sp, #0x30]
	ldrb r2, [r1]
	adds r2, #1
	movs r1, #0
	str r1, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r0, sb
	ldr r1, [sp, #0x34]
	movs r3, #2
	bl FUN_082376a4
	ldr r2, [sp, #0x30]
	ldrb r0, [r2]
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820E6C0
	ldr r3, _0820E6BC @ =0x0000125C
	adds r4, r7, r3
	ldr r0, [r4]
	bl FUN_0820feb0
	ldr r0, [r4]
	ldr r2, [sp, #0x30]
	ldrb r1, [r2]
	bl FUN_0820fe98
	b _0820E6CA
	.align 2, 0
_0820E6B0: .4byte 0x000005B4
_0820E6B4: .4byte 0x0000084C
_0820E6B8: .4byte 0x00000854
_0820E6BC: .4byte 0x0000125C
_0820E6C0:
	ldr r3, _0820E70C @ =0x0000125C
	adds r0, r7, r3
	ldr r0, [r0]
	bl FUN_0820fea8
_0820E6CA:
	adds r0, r7, #0
	bl FUN_0820d188
_0820E6D0:
	ldr r0, _0820E710 @ =0x0000114D
	adds r5, r7, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0820E71C
	ldr r0, _0820E714 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0820E730
	ldr r2, _0820E718 @ =0x0000110E
	adds r1, r7, r2
	ldrh r0, [r1]
	movs r4, #1
	orrs r0, r4
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0820cc30
	adds r0, r7, #0
	adds r0, #0x48
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #8
	adds r1, r7, #0
	adds r1, #0x8e
	strh r0, [r1]
	strb r4, [r5]
	b _0820E730
	.align 2, 0
_0820E70C: .4byte 0x0000125C
_0820E710: .4byte 0x0000114D
_0820E714: .4byte 0x030044E0
_0820E718: .4byte 0x0000110E
_0820E71C:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0820e080
	adds r0, r7, #0
	bl FUN_0820d188
	movs r0, #0xde
	bl PlaySound_082406e0
_0820E730:
	adds r0, r7, #0
	bl FUN_0820d188
	adds r0, r7, #0
	bl FUN_0820d690
	adds r0, r7, #0
	bl FUN_0820d5f8
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
_0820E748:
	movs r0, #0
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820e75c
FUN_0820e75c: @ 0x0820E75C
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _0820E76C
	adds r0, r1, #0
	bl FUN_0822f1c0
_0820E76C:
	pop {r0}
	bx r0

	thumb_func_start EnemyDexMenu_Destroy
EnemyDexMenu_Destroy: @ 0x0820E770
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0xcc
	adds r0, r4, #0
	bl FUN_0820e75c
	adds r0, r7, #0
	adds r0, #0x6c
	bl FUN_0820e75c
	adds r0, r4, #0
	bl FUN_0820e75c
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r7, r1
	bl FUN_0820e75c
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_0820E7A2:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E7A2
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r5, r7, r1
	movs r4, #2
_0820E7B8:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E7B8
	ldr r1, _0820E868 @ =0x0000048C
	adds r0, r7, r1
	bl FUN_0820e75c
	ldr r1, _0820E86C @ =0x000004EC
	adds r0, r7, r1
	bl FUN_0820e75c
	ldr r1, _0820E870 @ =0x0000054C
	adds r0, r7, r1
	bl FUN_0820e75c
	ldr r0, _0820E874 @ =0x000008AC
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0820E878 @ =0x0000084C
	adds r6, r7, r1
	ldr r0, _0820E87C @ =0x000005AC
	adds r5, r7, r0
	movs r4, #6
_0820E7EE:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r0, r6, #0
	bl FUN_0820e75c
	mov r0, r8
	bl FUN_0820e75c
	movs r1, #0xc0
	add r8, r1
	adds r6, #0xc0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E7EE
	ldr r0, _0820E880 @ =0x00000E4C
	adds r6, r7, r0
	ldr r1, _0820E884 @ =0x00000D8C
	adds r5, r7, r1
	movs r4, #1
_0820E818:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r0, r6, #0
	bl FUN_0820e75c
	adds r6, #0x60
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E818
	ldr r0, _0820E888 @ =0x00000F0C
	adds r5, r7, r0
	movs r4, #1
_0820E834:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E834
	ldr r1, _0820E88C @ =0x00000FCC
	adds r0, r7, r1
	bl FUN_0820e75c
	ldr r1, _0820E890 @ =0x0000102C
	adds r0, r7, r1
	bl FUN_0822f1c0
	ldr r1, _0820E894 @ =0x0000108C
	adds r0, r7, r1
	bl FUN_0822f1c0
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0820E868: .4byte 0x0000048C
_0820E86C: .4byte 0x000004EC
_0820E870: .4byte 0x0000054C
_0820E874: .4byte 0x000008AC
_0820E878: .4byte 0x0000084C
_0820E87C: .4byte 0x000005AC
_0820E880: .4byte 0x00000E4C
_0820E884: .4byte 0x00000D8C
_0820E888: .4byte 0x00000F0C
_0820E88C: .4byte 0x00000FCC
_0820E890: .4byte 0x0000102C
_0820E894: .4byte 0x0000108C

	thumb_func_start EnemyDexMenu_Init
EnemyDexMenu_Init: @ 0x0820E898
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0
	str r1, [r6, #0x20]
	adds r0, #0x24
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x22
	strb r1, [r0]
	ldr r2, _0820E8E8 @ =0x0000110C
	adds r0, r6, r2
	movs r2, #0
	strh r1, [r0]
	adds r1, r6, #0
	adds r1, #0x49
	movs r0, #0x20
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x4a
	strb r2, [r0]
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E8E0
	bl FUN_0823d340
	ldr r7, _0820E8EC @ =0x00001110
	adds r1, r6, r7
	str r0, [r1]
	cmp r0, #0
	bne _0820E8F0
_0820E8E0:
	movs r0, #1
	rsbs r0, r0, #0
	b _0820EAA8
	.align 2, 0
_0820E8E8: .4byte 0x0000110C
_0820E8EC: .4byte 0x00001110
_0820E8F0:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x28
	movs r7, #5
_0820E8F8:
	movs r0, #3
	adds r1, r7, #0
	movs r2, #0x17
	movs r3, #2
	bl FUN_0804a084
	str r0, [r4]
	ldr r2, _0820EAB0 @ =0x00001110
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	adds r1, r5, #0
	bl FUN_0804a2f8
	ldm r4!, {r0}
	bl FUN_0804a210
	adds r7, #2
	adds r5, #1
	cmp r5, #7
	ble _0820E8F8
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E94C
	bl FUN_0823d34c
	bl VM_SetPC
	movs r4, #0
	ldr r7, _0820EAB4 @ =0x00001114
	adds r5, r6, r7
_0820E93E:
	bl Script_GetValue
	adds r1, r5, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0x38
	ble _0820E93E
_0820E94C:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E996
	bl FUN_0823d34c
	adds r2, r0, #0
	ldr r0, _0820EAB8 @ =0x00001150
	adds r0, r0, r6
	mov ip, r0
	adds r5, r6, #0
	movs r4, #0x38
	ldr r1, _0820EABC @ =0x00001151
	adds r3, r6, r1
_0820E96A:
	ldrb r0, [r2]
	mov r7, ip
	strb r0, [r7]
	adds r2, #1
	ldrb r0, [r2]
	strb r0, [r3]
	adds r2, #1
	ldrb r0, [r2]
	strb r0, [r3, #1]
	adds r2, #1
	ldrb r1, [r2]
	ldr r7, _0820EAC0 @ =0x00001153
	adds r0, r5, r7
	strb r1, [r0]
	adds r2, #1
	movs r0, #4
	add ip, r0
	adds r3, #4
	adds r5, #4
	subs r4, #1
	cmp r4, #0
	bge _0820E96A
_0820E996:
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9AA
	bl FUN_0823d340
	ldr r2, _0820EAC4 @ =0x00001234
	adds r1, r6, r2
	str r0, [r1]
_0820E9AA:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9BE
	bl FUN_0823d340
	ldr r7, _0820EAC8 @ =0x0000123C
	adds r1, r6, r7
	str r0, [r1]
_0820E9BE:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9D2
	bl FUN_0823d340
	ldr r2, _0820EACC @ =0x00001238
	adds r1, r6, r2
	str r0, [r1]
_0820E9D2:
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9E8
	bl FUN_0823d340
	movs r7, #0x92
	lsls r7, r7, #5
	adds r1, r6, r7
	str r0, [r1]
_0820E9E8:
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820E9FC
	bl FUN_0823d340
	ldr r2, _0820EAD0 @ =0x00001244
	adds r1, r6, r2
	str r0, [r1]
_0820E9FC:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820EA10
	bl FUN_0823d340
	ldr r7, _0820EAD4 @ =0x00001248
	adds r1, r6, r7
	str r0, [r1]
_0820EA10:
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820EA24
	bl FUN_0823d340
	ldr r2, _0820EAD8 @ =0x0000124C
	adds r1, r6, r2
	str r0, [r1]
_0820EA24:
	movs r0, #0x75
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820EA38
	bl FUN_0823d340
	ldr r7, _0820EADC @ =0x00001250
	adds r1, r6, r7
	str r0, [r1]
_0820EA38:
	movs r0, #0x54
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0820EA4C
	bl FUN_0823d340
	ldr r2, _0820EAE0 @ =0x00001254
	adds r1, r6, r2
	str r0, [r1]
_0820EA4C:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r7, _0820EAE4 @ =0x00001258
	adds r1, r6, r7
	str r0, [r1]
	ldr r0, _0820EAE8 @ =0x0000110E
	adds r1, r6, r0
	movs r4, #0
	movs r0, #5
	strh r0, [r1]
	bl FUN_08049e5c
	movs r0, #0
	movs r1, #0
	bl EntityC946_Create
	ldr r2, _0820EAEC @ =0x0000125C
	adds r1, r6, r2
	str r0, [r1]
	bl FUN_0820fea8
	adds r0, r6, #0
	bl FUN_0820d6e4
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0820e080
	movs r0, #4
	str r0, [sp]
	ldr r0, _0820EAF0 @ =0x0000FFFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0
_0820EAA8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0820EAB0: .4byte 0x00001110
_0820EAB4: .4byte 0x00001114
_0820EAB8: .4byte 0x00001150
_0820EABC: .4byte 0x00001151
_0820EAC0: .4byte 0x00001153
_0820EAC4: .4byte 0x00001234
_0820EAC8: .4byte 0x0000123C
_0820EACC: .4byte 0x00001238
_0820EAD0: .4byte 0x00001244
_0820EAD4: .4byte 0x00001248
_0820EAD8: .4byte 0x0000124C
_0820EADC: .4byte 0x00001250
_0820EAE0: .4byte 0x00001254
_0820EAE4: .4byte 0x00001258
_0820EAE8: .4byte 0x0000110E
_0820EAEC: .4byte 0x0000125C
_0820EAF0: .4byte 0x0000FFFF

	thumb_func_start EnemyDexMenu_Create
EnemyDexMenu_Create: @ 0x0820EAF4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x93
	lsls r1, r1, #5
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0820EB30
	ldr r1, _0820EB28 @ =EnemyDexMenu_Update
	ldr r2, _0820EB2C @ =EnemyDexMenu_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EnemyDexMenu_Init
	cmp r0, #0
	bge _0820EB30
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0820EB32
	.align 2, 0
_0820EB28: .4byte EnemyDexMenu_Update
_0820EB2C: .4byte EnemyDexMenu_Destroy
_0820EB30:
	adds r0, r4, #0
_0820EB32:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820eb38
FUN_0820eb38: @ 0x0820EB38
	push {r4, r5, r6, r7, lr}
	movs r4, #0
	movs r6, #1
	ldr r1, _0820EB7C @ =0x000005B4
	adds r1, r1, r0
	mov ip, r1
	ldr r1, _0820EB80 @ =0x00000854
	adds r7, r0, r1
_0820EB48:
	lsls r1, r4, #1
	adds r5, r4, #1
	adds r0, r1, r4
	lsls r0, r0, #6
	adds r2, r0, r7
	movs r3, #1
_0820EB54:
	ldr r0, [r2]
	orrs r0, r6
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820EB54
	adds r1, r1, r4
	lsls r1, r1, #5
	add r1, ip
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	adds r4, r5, #0
	cmp r4, #6
	ble _0820EB48
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820EB7C: .4byte 0x000005B4
_0820EB80: .4byte 0x00000854

	thumb_func_start FUN_0820eb84
FUN_0820eb84: @ 0x0820EB84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r1, #0
	ldr r0, _0820EC5C @ =0x00000854
	adds r0, r0, r7
	mov sb, r0
	ldr r3, _0820EC60 @ =0x000005B4
	adds r3, r3, r7
	mov r8, r3
	adds r0, r7, #0
	adds r0, #0x25
	str r0, [sp, #0x18]
	movs r6, #1
_0820EBA8:
	lsls r4, r1, #1
	adds r5, r1, #1
	adds r0, r4, r1
	lsls r0, r0, #6
	mov r3, sb
	adds r2, r0, r3
	movs r3, #1
_0820EBB6:
	ldr r0, [r2]
	orrs r0, r6
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820EBB6
	adds r1, r4, r1
	lsls r1, r1, #5
	add r1, r8
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	adds r1, r5, #0
	cmp r1, #6
	ble _0820EBA8
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
	bl FUN_0820cbec
	mov sl, r0
	ldr r3, [sp, #0x18]
	ldrb r0, [r3]
	bl FUN_0820cbdc
	adds r0, #1
	str r0, [sp, #0x14]
	movs r0, #0
	mov r8, r0
	cmp r8, sl
	bge _0820EC4A
	ldr r1, _0820EC64 @ =0x000005CC
	adds r4, r7, r1
	mov sb, r0
	movs r6, #0x28
	ldr r3, _0820EC68 @ =0x0000084C
	adds r5, r7, r3
_0820EC00:
	ldr r2, [sp, #0x14]
	add r2, r8
	movs r0, #0
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r1, #0
	str r1, [sp, #0x10]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x4c
	movs r3, #2
	bl FUN_082376a4
	ldr r3, _0820EC60 @ =0x000005B4
	adds r2, r7, r3
	add r2, sb
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0x28
	strh r0, [r4]
	strh r6, [r4, #2]
	adds r4, #0x60
	movs r0, #0x60
	add sb, r0
	adds r6, #0x10
	adds r5, #0xc0
	movs r1, #1
	add r8, r1
	cmp r8, sl
	blt _0820EC00
_0820EC4A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820EC5C: .4byte 0x00000854
_0820EC60: .4byte 0x000005B4
_0820EC64: .4byte 0x000005CC
_0820EC68: .4byte 0x0000084C

	thumb_func_start FUN_0820ec6c
FUN_0820ec6c: @ 0x0820EC6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	movs r4, #0
	ldr r0, _0820ECF8 @ =0x00000854
	adds r0, r0, r6
	mov r8, r0
	ldr r1, _0820ECFC @ =0x000005B4
	adds r1, r1, r6
	mov ip, r1
	movs r3, #0x4c
	adds r3, r3, r6
	mov sl, r3
	movs r0, #0x26
	adds r0, r0, r6
	mov sb, r0
	movs r7, #1
_0820EC96:
	lsls r1, r4, #1
	adds r5, r4, #1
	adds r0, r1, r4
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820ECA4:
	ldr r0, [r2]
	orrs r0, r7
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820ECA4
	adds r1, r1, r4
	lsls r1, r1, #5
	add r1, ip
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	adds r4, r5, #0
	cmp r4, #6
	ble _0820EC96
	movs r3, #0
	ldr r1, _0820ED00 @ =0x0000084C
	adds r0, r6, r1
	mov r1, sb
	ldrb r2, [r1]
	adds r2, #1
	str r3, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r3, [sp, #0x10]
	mov r1, sl
	movs r3, #2
	bl FUN_082376a4
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820ECF8: .4byte 0x00000854
_0820ECFC: .4byte 0x000005B4
_0820ED00: .4byte 0x0000084C

	thumb_func_start FUN_0820ed04
FUN_0820ed04: @ 0x0820ED04
	push {r4, lr}
	movs r4, #1
	ldr r1, _0820ED30 @ =0x00000E54
	adds r2, r0, r1
	ldr r3, _0820ED34 @ =0x00000D94
	adds r1, r0, r3
	movs r3, #1
_0820ED12:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820ED12
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820ED30: .4byte 0x00000E54
_0820ED34: .4byte 0x00000D94
_0820ED38:
	.byte 0x01, 0x1C, 0x48, 0x31, 0x09, 0x78, 0x09, 0x01
	.byte 0x08, 0x31, 0x8E, 0x30, 0x01, 0x80, 0x70, 0x47

	thumb_func_start FUN_0820ed48
FUN_0820ed48: @ 0x0820ED48
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	movs r4, #1
	ldr r0, _0820EDDC @ =0x00000E54
	adds r2, r7, r0
	subs r0, #0xc0
	adds r1, r7, r0
	movs r3, #1
_0820ED60:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820ED60
	movs r4, #0
	adds r0, r7, #0
	adds r0, #0x26
	ldrb r0, [r0]
	bl FUN_0820cc8c
	mov r8, r0
	bl FUN_0820d0b8
	adds r2, r0, #0
	ldr r1, _0820EDE0 @ =0x00000D8C
	adds r0, r7, r1
	movs r1, #0x4c
	adds r1, r1, r7
	mov sb, r1
	str r4, [sp]
	movs r1, #0x98
	str r1, [sp, #4]
	movs r6, #0x13
	str r6, [sp, #8]
	movs r5, #8
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	mov r1, sb
	movs r3, #2
	bl FUN_082376a4
	mov r0, r8
	bl FUN_0820cbfc
	adds r2, r0, #0
	ldr r1, _0820EDE4 @ =0x00000E4C
	adds r0, r7, r1
	str r4, [sp]
	movs r1, #0xb0
	str r1, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	mov r1, sb
	movs r3, #2
	bl FUN_082376a4
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820EDDC: .4byte 0x00000E54
_0820EDE0: .4byte 0x00000D8C
_0820EDE4: .4byte 0x00000E4C

	thumb_func_start FUN_0820ede8
FUN_0820ede8: @ 0x0820EDE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0820d21c
	adds r4, r7, #0
	adds r4, #0x25
	ldrb r0, [r4]
	bl FUN_0820cbdc
	mov sl, r0
	ldrb r0, [r4]
	bl FUN_0820cbec
	mov r8, r0
	movs r6, #0
	cmp r6, r8
	bge _0820EE6C
	adds r5, r7, #0
	adds r5, #0x28
	movs r0, #5
	mov sb, r0
_0820EE1C:
	ldr r0, [r5]
	ldr r2, _0820EE50 @ =0x00001110
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r5]
	movs r1, #2
	str r1, [sp]
	movs r1, #6
	mov r2, sb
	movs r3, #0x14
	bl FUN_0804a38c
	mov r0, sl
	adds r4, r0, r6
	adds r0, r4, #0
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820EE54
	ldr r0, [r5]
	adds r1, r4, #0
	bl FUN_0804a2f8
	b _0820EE5C
	.align 2, 0
_0820EE50: .4byte 0x00001110
_0820EE54:
	ldr r0, [r5]
	movs r1, #0x39
	bl FUN_0804a2f8
_0820EE5C:
	ldm r5!, {r0}
	bl FUN_0804a1f0
	movs r2, #2
	add sb, r2
	adds r6, #1
	cmp r6, r8
	blt _0820EE1C
_0820EE6C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820ee7c
FUN_0820ee7c: @ 0x0820EE7C
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #4
_0820EE8A:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820EE8A
	movs r4, #1
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r2, #2
_0820EEA2:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820EEA2
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820eeb8
FUN_0820eeb8: @ 0x0820EEB8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r3, #1
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #4
_0820EEC6:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820EEC6
	movs r1, #0x25
	adds r1, r1, r5
	mov ip, r1
	movs r3, #1
	movs r2, #0xdd
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #2
_0820EEE4:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820EEE4
	movs r4, #0
	movs r3, #0
	mov r6, ip
	ldrb r0, [r6]
	cmp r0, #8
	bhi _0820EF76
	lsls r0, r0, #2
	ldr r1, _0820EF08 @ =_0820EF0C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820EF08: .4byte _0820EF0C
_0820EF0C: @ jump table
	.4byte _0820EF30 @ case 0
	.4byte _0820EF36 @ case 1
	.4byte _0820EF3C @ case 2
	.4byte _0820EF46 @ case 3
	.4byte _0820EF4E @ case 4
	.4byte _0820EF54 @ case 5
	.4byte _0820EF5E @ case 6
	.4byte _0820EF64 @ case 7
	.4byte _0820EF6E @ case 8
_0820EF30:
	movs r1, #0
	movs r2, #0
	b _0820EF40
_0820EF36:
	movs r1, #0
	movs r2, #1
	b _0820EF40
_0820EF3C:
	movs r1, #0
	movs r2, #2
_0820EF40:
	movs r4, #0x70
	movs r3, #0x13
	b _0820EF7A
_0820EF46:
	movs r1, #1
	movs r2, #1
	rsbs r2, r2, #0
	b _0820EF7A
_0820EF4E:
	movs r1, #2
	movs r2, #0
	b _0820EF58
_0820EF54:
	movs r1, #2
	movs r2, #1
_0820EF58:
	movs r4, #0x60
	movs r3, #0x13
	b _0820EF7A
_0820EF5E:
	movs r1, #3
	movs r2, #0
	b _0820EF68
_0820EF64:
	movs r1, #3
	movs r2, #1
_0820EF68:
	movs r4, #0x80
	movs r3, #0x13
	b _0820EF7A
_0820EF6E:
	movs r1, #4
	movs r2, #1
	rsbs r2, r2, #0
	b _0820EF7A
_0820EF76:
	movs r1, #0
	movs r2, #1
_0820EF7A:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r6, #0xca
	lsls r6, r6, #1
	adds r1, r5, r6
	adds r1, r1, r0
	ldr r0, [r1]
	movs r6, #2
	rsbs r6, r6, #0
	ands r0, r6
	str r0, [r1]
	cmp r2, #0
	blt _0820EFBA
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #5
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r2, r5, r0
	adds r2, r2, r1
	ldr r0, [r2]
	ands r0, r6
	str r0, [r2]
	adds r1, r5, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r4, [r0]
	ldr r6, _0820EFC0 @ =0x0000038E
	adds r1, r1, r6
	strh r3, [r1]
_0820EFBA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0820EFC0: .4byte 0x0000038E

	thumb_func_start FUN_0820efc4
FUN_0820efc4: @ 0x0820EFC4
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #4
	bls _0820EFE6
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #4
	bls _0820EFE2
	movs r0, #8
	subs r0, r0, r3
	strb r0, [r1]
	b _0820F008
_0820EFE2:
	strb r3, [r1]
	b _0820F00E
_0820EFE6:
	cmp r0, #0
	beq _0820F014
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r4, #0xff
	lsls r4, r4, #0x18
	adds r0, r0, r4
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0820F000
	movs r0, #1
	b _0820F002
_0820F000:
	movs r0, #0
_0820F002:
	strb r0, [r1]
	cmp r3, #1
	bls _0820F00E
_0820F008:
	movs r0, #1
	strb r0, [r2]
	b _0820F018
_0820F00E:
	movs r0, #0
	strb r0, [r2]
	b _0820F018
_0820F014:
	strb r3, [r1]
	strb r3, [r2]
_0820F018:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820f020
FUN_0820f020: @ 0x0820F020
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _0820F126
	adds r4, r6, #0
	adds r4, #0x28
	adds r0, r4, #0
	bl FUN_08055d20
	adds r7, r4, #0
	cmp r0, #0
	beq _0820F0E8
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0xc
	bhi _0820F0E8
	lsls r0, r0, #2
	ldr r1, _0820F054 @ =_0820F058
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820F054: .4byte _0820F058
_0820F058: @ jump table
	.4byte _0820F08C @ case 0
	.4byte _0820F098 @ case 1
	.4byte _0820F0A4 @ case 2
	.4byte _0820F0B0 @ case 3
	.4byte _0820F0BC @ case 4
	.4byte _0820F0C8 @ case 5
	.4byte _0820F0D4 @ case 6
	.4byte _0820F0E8 @ case 7
	.4byte _0820F0E8 @ case 8
	.4byte _0820F0E8 @ case 9
	.4byte _0820F0E8 @ case 10
	.4byte _0820F0E8 @ case 11
	.4byte _0820F0E0 @ case 12
_0820F08C:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	b _0820F0E8
_0820F098:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	b _0820F0E8
_0820F0A4:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #3
	strh r0, [r1]
	b _0820F0E8
_0820F0B0:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #4
	strh r0, [r1]
	b _0820F0E8
_0820F0BC:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #5
	strh r0, [r1]
	b _0820F0E8
_0820F0C8:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #6
	strh r0, [r1]
	b _0820F0E8
_0820F0D4:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #0xc
	strh r0, [r1]
	b _0820F0E8
_0820F0E0:
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
_0820F0E8:
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	subs r1, #0xa
	adds r4, r6, r1
	adds r1, #1
	adds r5, r6, r1
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0820efc4
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldrb r2, [r4]
	ldrb r3, [r5]
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	bl FUN_08055b5c
	adds r0, r7, #0
	bl FUN_08055c04
_0820F126:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820f130
FUN_0820f130: @ 0x0820F130
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, [r7, #0x18]
	mov sl, r0
	cmp r0, #0
	bne _0820F1C8
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r0, #1
	mov sb, r0
	mov r0, sb
	strh r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	subs r1, #0xa
	adds r5, r7, r1
	adds r1, #1
	adds r6, r7, r1
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0820efc4
	adds r4, r7, #0
	adds r4, #0x28
	mov r0, r8
	ldrh r1, [r0]
	ldrb r2, [r5]
	ldrb r3, [r6]
	mov r0, sb
	str r0, [sp]
	mov r0, sl
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08055b5c
	adds r0, r4, #0
	bl FUN_08055c04
	adds r0, r4, #0
	bl FUN_08055d20
	cmp r0, #0
	beq _0820F1CE
	ldr r2, _0820F1BC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0820F1C0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0820F1C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x20
	bl Mod
	adds r0, #0x3c
	b _0820F1CC
	.align 2, 0
_0820F1BC: .4byte 0x030046B8
_0820F1C0: .4byte 0x000003FF
_0820F1C4: .4byte 0x0203B400
_0820F1C8:
	mov r0, sl
	subs r0, #1
_0820F1CC:
	str r0, [r7, #0x18]
_0820F1CE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820f1e0
FUN_0820f1e0: @ 0x0820F1E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r0, #0
	str r0, [r7, #0x18]
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	adds r6, r7, #0
	adds r6, #0x28
	movs r2, #0
	mov sl, r2
	add r3, sp, #0xc
	mov sb, r3
	ldr r5, _0820F2B4 @ =0x085AF0B0
	str r5, [sp, #0x18]
_0820F20C:
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r5, sl
	lsls r5, r5, #1
	str r5, [sp, #0x14]
	ldr r0, [sp, #0x18]
	movs r4, #0
	ldrsb r4, [r0, r4]
	adds r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r5, [sp, #0x18]
	movs r3, #1
	ldrsb r3, [r5, r3]
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r2, r2, r4
	adds r1, r1, r3
	mov r3, sb
	strh r2, [r3]
	strh r1, [r3, #2]
	strh r0, [r3, #4]
	mov r5, r8
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	str r3, [sp]
	adds r0, r6, #0
	movs r3, #0x10
	bl FUN_08055dac
	cmp r0, #0
	blt _0820F2FA
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08055f1c
	ldrb r1, [r5, #0xb]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0820F274
	ldrh r1, [r5, #8]
	adds r0, r6, #0
	bl FUN_08055fbc
_0820F274:
	adds r0, r6, #0
	movs r1, #2
	bl FUN_08055f5c
	mov r1, r8
	ldrb r0, [r1, #0xa]
	ldr r2, _0820F2B8 @ =0x00000366
	adds r4, r7, r2
	ldr r3, _0820F2BC @ =0x00000367
	adds r5, r7, r3
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0820efc4
	mov r0, sl
	cmp r0, #0
	bne _0820F2C4
	ldr r0, _0820F2C0 @ =0x085AF0BA
	ldrh r1, [r0]
	ldrb r2, [r4]
	ldrb r3, [r5]
	movs r0, #2
	str r0, [sp]
	mov r5, sl
	str r5, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_08055b5c
	b _0820F2E2
	.align 2, 0
_0820F2B4: .4byte 0x085AF0B0
_0820F2B8: .4byte 0x00000366
_0820F2BC: .4byte 0x00000367
_0820F2C0: .4byte 0x085AF0BA
_0820F2C4:
	ldr r0, _0820F30C @ =0x085AF0BA
	ldr r1, [sp, #0x14]
	adds r0, r1, r0
	ldrh r1, [r0]
	movs r0, #2
	str r0, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08055b5c
_0820F2E2:
	adds r0, r6, #0
	bl FUN_08055c04
	adds r6, #0x94
	ldr r3, [sp, #0x18]
	adds r3, #2
	str r3, [sp, #0x18]
	movs r5, #1
	add sl, r5
	mov r0, sl
	cmp r0, #4
	ble _0820F20C
_0820F2FA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820F30C: .4byte 0x085AF0BA

	thumb_func_start FUN_0820f310
FUN_0820f310: @ 0x0820F310
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	ldr r0, [r0, #0x18]
	adds r0, #0x20
	mov r1, ip
	str r0, [r1, #0x18]
	movs r3, #0x28
	add r3, ip
	mov sb, r3
	movs r7, #0
	movs r6, #0xd5
	lsls r6, r6, #2
	add r6, ip
	str r6, [sp]
	ldr r0, _0820F384 @ =0x00000356
	add r0, ip
	str r0, [sp, #4]
	ldr r1, _0820F388 @ =0x085AF0B0
	mov r8, r1
	movs r3, #0xd6
	lsls r3, r3, #2
	add r3, ip
	mov sl, r3
_0820F348:
	ldr r6, [sp]
	movs r0, #0
	ldrsh r2, [r6, r0]
	mov r1, r8
	movs r4, #0
	ldrsb r4, [r1, r4]
	ldr r3, [sp, #4]
	movs r6, #0
	ldrsh r1, [r3, r6]
	mov r0, r8
	movs r3, #1
	ldrsb r3, [r0, r3]
	mov r6, sl
	movs r0, #0
	ldrsh r5, [r6, r0]
	mov r6, sb
	adds r6, #0x8c
	ldr r0, [r6]
	adds r2, r2, r4
	adds r1, r1, r3
	strh r2, [r0]
	strh r1, [r0, #2]
	strh r5, [r0, #4]
	mov r1, ip
	ldr r0, [r1, #0x18]
	cmp r0, #0
	blt _0820F38C
	asrs r1, r0, #5
	b _0820F392
	.align 2, 0
_0820F384: .4byte 0x00000356
_0820F388: .4byte 0x085AF0B0
_0820F38C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_0820F392:
	lsls r0, r7, #5
	adds r0, r1, r0
	movs r2, #8
	subs r2, r2, r7
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _0820F3B4 @ =0x085B0A08
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0820F3B8
	asrs r2, r0, #0xd
	b _0820F3BE
	.align 2, 0
_0820F3B4: .4byte 0x085B0A08
_0820F3B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xd
	rsbs r2, r0, #0
_0820F3BE:
	ldr r1, [r6]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r3, #0x94
	add sb, r3
	movs r6, #2
	add r8, r6
	adds r7, #1
	cmp r7, #4
	ble _0820F348
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820f3e4
FUN_0820f3e4: @ 0x0820F3E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r7, [r0]
	adds r5, r6, #0
	adds r5, #0x28
	movs r2, #0
	mov sl, r2
	add r3, sp, #4
	mov r8, r3
	ldr r4, _0820F4A8 @ =0x085AF0C4
	mov sb, r4
_0820F40E:
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r4, sb
	ldrb r4, [r4]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	mov ip, r4
	adds r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r4, sb
	movs r3, #1
	ldrsb r3, [r4, r3]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	add r2, ip
	adds r1, r1, r3
	mov r3, r8
	strh r2, [r3]
	strh r1, [r3, #2]
	strh r0, [r3, #4]
	ldrh r1, [r7]
	ldrh r2, [r7, #2]
	str r3, [sp]
	adds r0, r5, #0
	movs r3, #0x10
	bl FUN_08055dac
	cmp r0, #0
	blt _0820F498
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08055f1c
	ldrb r1, [r7, #0xb]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0820F472
	ldrh r1, [r7, #8]
	adds r0, r5, #0
	bl FUN_08055fbc
_0820F472:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08055f5c
	ldrb r0, [r7, #0xa]
	ldr r4, _0820F4AC @ =0x00000366
	adds r1, r6, r4
	ldr r3, _0820F4B0 @ =0x00000367
	adds r2, r6, r3
	bl FUN_0820efc4
	adds r5, #0x94
	movs r4, #2
	add sb, r4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #4
	ble _0820F40E
_0820F498:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820F4A8: .4byte 0x085AF0C4
_0820F4AC: .4byte 0x00000366
_0820F4B0: .4byte 0x00000367

	thumb_func_start FUN_0820f4b4
FUN_0820f4b4: @ 0x0820F4B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, [r6, #0x18]
	adds r0, #0x20
	str r0, [r6, #0x18]
	adds r7, r6, #0
	adds r7, #0x28
	movs r0, #0
	mov r8, r0
	movs r1, #0
	str r1, [sp, #0xc]
	ldr r2, _0820F508 @ =0x085AF0CE
	mov sl, r2
	movs r3, #0xb4
	adds r3, r3, r6
	mov sb, r3
_0820F4DE:
	mov r4, r8
	cmp r4, #0
	bne _0820F514
	ldr r5, _0820F508 @ =0x085AF0CE
	ldrh r1, [r5]
	ldr r2, _0820F50C @ =0x00000366
	adds r0, r6, r2
	ldrb r2, [r0]
	ldr r3, _0820F510 @ =0x00000367
	adds r0, r6, r3
	ldrb r3, [r0]
	movs r4, #1
	str r4, [sp]
	mov r5, r8
	str r5, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	bl FUN_08055b5c
	b _0820F56A
	.align 2, 0
_0820F508: .4byte 0x085AF0CE
_0820F50C: .4byte 0x00000366
_0820F510: .4byte 0x00000367
_0820F514:
	mov r1, r8
	cmp r1, #1
	bgt _0820F530
	mov r2, sl
	ldrh r1, [r2]
	movs r3, #1
	str r3, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r4, #5
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r2, #0
	b _0820F548
_0820F530:
	mov r5, r8
	cmp r5, #2
	bgt _0820F550
	mov r0, sl
	ldrh r1, [r0]
	movs r2, #1
	str r2, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r3, #5
	str r3, [sp, #8]
	adds r0, r7, #0
_0820F548:
	movs r3, #0
	bl FUN_08055b5c
	b _0820F56A
_0820F550:
	mov r4, sl
	ldrh r1, [r4]
	movs r5, #1
	str r5, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08055b5c
_0820F56A:
	adds r0, r7, #0
	bl FUN_08055c04
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r4, [sp, #0xc]
	ldr r5, _0820F5BC @ =0x085AF0C4
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov ip, r0
	adds r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r5, _0820F5C0 @ =0x085AF0C5
	adds r0, r4, r5
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r5, #0
	ldrsh r4, [r0, r5]
	mov r5, sb
	ldr r0, [r5]
	add r2, ip
	adds r1, r1, r3
	strh r2, [r0]
	strh r1, [r0, #2]
	strh r4, [r0, #4]
	ldr r0, [r6, #0x18]
	mov r4, sb
	cmp r0, #0
	blt _0820F5C4
	asrs r1, r0, #5
	b _0820F5CA
	.align 2, 0
_0820F5BC: .4byte 0x085AF0C4
_0820F5C0: .4byte 0x085AF0C5
_0820F5C4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_0820F5CA:
	mov r2, r8
	lsls r0, r2, #5
	adds r0, r1, r0
	movs r2, #8
	mov r3, r8
	subs r2, r2, r3
	ldr r3, _0820F5F0 @ =0x085B0A08
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	blt _0820F5F4
	asrs r2, r0, #0xd
	b _0820F5FA
	.align 2, 0
_0820F5F0: .4byte 0x085B0A08
_0820F5F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xd
	rsbs r2, r0, #0
_0820F5FA:
	ldr r1, [r4]
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	movs r0, #0x94
	add sb, r0
	adds r7, #0x94
	ldr r1, [sp, #0xc]
	adds r1, #2
	str r1, [sp, #0xc]
	movs r2, #2
	add sl, r2
	movs r3, #1
	add r8, r3
	mov r4, r8
	cmp r4, #4
	bgt _0820F61E
	b _0820F4DE
_0820F61E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820f630
FUN_0820f630: @ 0x0820F630
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r7, [r0]
	adds r5, r6, #0
	adds r5, #0x28
	movs r2, #0
	mov sl, r2
	add r3, sp, #4
	mov r8, r3
	ldr r4, _0820F6F4 @ =0x085AF0D8
	mov sb, r4
_0820F65A:
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r4, sb
	ldrb r4, [r4]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	mov ip, r4
	adds r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r4, sb
	movs r3, #1
	ldrsb r3, [r4, r3]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	add r2, ip
	adds r1, r1, r3
	mov r3, r8
	strh r2, [r3]
	strh r1, [r3, #2]
	strh r0, [r3, #4]
	ldrh r1, [r7]
	ldrh r2, [r7, #2]
	str r3, [sp]
	adds r0, r5, #0
	movs r3, #0x10
	bl FUN_08055dac
	cmp r0, #0
	blt _0820F6E4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08055f1c
	ldrb r1, [r7, #0xb]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0820F6BE
	ldrh r1, [r7, #8]
	adds r0, r5, #0
	bl FUN_08055fbc
_0820F6BE:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08055f5c
	ldrb r0, [r7, #0xa]
	ldr r4, _0820F6F8 @ =0x00000366
	adds r1, r6, r4
	ldr r3, _0820F6FC @ =0x00000367
	adds r2, r6, r3
	bl FUN_0820efc4
	adds r5, #0x94
	movs r4, #2
	add sb, r4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #4
	ble _0820F65A
_0820F6E4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820F6F4: .4byte 0x085AF0D8
_0820F6F8: .4byte 0x00000366
_0820F6FC: .4byte 0x00000367

	thumb_func_start FUN_0820f700
FUN_0820f700: @ 0x0820F700
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, [r6, #0x18]
	adds r0, #0x20
	str r0, [r6, #0x18]
	adds r7, r6, #0
	adds r7, #0x28
	movs r0, #0
	mov sb, r0
	ldr r1, _0820F754 @ =0x085AF0D8
	mov sl, r1
	movs r2, #0
	str r2, [sp, #0xc]
	movs r3, #0xb4
	adds r3, r3, r6
	mov r8, r3
_0820F72A:
	mov r4, sb
	cmp r4, #0
	bne _0820F764
	ldr r0, _0820F758 @ =0x085AF0E2
	ldrh r1, [r0]
	ldr r5, _0820F75C @ =0x00000366
	adds r0, r6, r5
	ldrb r2, [r0]
	ldr r3, _0820F760 @ =0x00000367
	adds r0, r6, r3
	ldrb r3, [r0]
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	bl FUN_08055b5c
	b _0820F782
	.align 2, 0
_0820F754: .4byte 0x085AF0D8
_0820F758: .4byte 0x085AF0E2
_0820F75C: .4byte 0x00000366
_0820F760: .4byte 0x00000367
_0820F764:
	ldr r0, _0820F7CC @ =0x085AF0E2
	ldr r4, [sp, #0xc]
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08055b5c
_0820F782:
	adds r0, r7, #0
	bl FUN_08055c04
	movs r5, #0xd5
	lsls r5, r5, #2
	adds r0, r6, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r3, sl
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	mov ip, r3
	ldr r4, _0820F7D0 @ =0x00000356
	adds r0, r6, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	mov r0, sl
	movs r3, #1
	ldrsb r3, [r0, r3]
	adds r4, #2
	adds r0, r6, r4
	movs r5, #0
	ldrsh r4, [r0, r5]
	mov r5, r8
	ldr r0, [r5]
	add r2, ip
	adds r1, r1, r3
	strh r2, [r0]
	strh r1, [r0, #2]
	strh r4, [r0, #4]
	ldr r0, [r6, #0x18]
	mov r4, r8
	cmp r0, #0
	blt _0820F7D4
	asrs r1, r0, #5
	b _0820F7DA
	.align 2, 0
_0820F7CC: .4byte 0x085AF0E2
_0820F7D0: .4byte 0x00000356
_0820F7D4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_0820F7DA:
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r1, r0
	movs r2, #8
	mov r3, sb
	subs r2, r2, r3
	ldr r3, _0820F800 @ =0x085B0A08
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	blt _0820F804
	asrs r2, r0, #0xd
	b _0820F80A
	.align 2, 0
_0820F800: .4byte 0x085B0A08
_0820F804:
	rsbs r0, r0, #0
	asrs r0, r0, #0xd
	rsbs r2, r0, #0
_0820F80A:
	ldr r1, [r4]
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	movs r0, #0x94
	add r8, r0
	adds r7, #0x94
	movs r1, #2
	add sl, r1
	ldr r2, [sp, #0xc]
	adds r2, #2
	str r2, [sp, #0xc]
	movs r3, #1
	add sb, r3
	mov r4, sb
	cmp r4, #4
	bgt _0820F82E
	b _0820F72A
_0820F82E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0


