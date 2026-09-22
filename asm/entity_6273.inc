	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08049fc8
FUN_08049fc8: @ 0x08049FC8
	ldr r1, _08049FD0 @ =0x030000CC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08049FD0: .4byte 0x030000CC

	thumb_func_start FUN_08049fd4
FUN_08049fd4: @ 0x08049FD4
	push {lr}
	ldr r0, _08049FE4 @ =0x030000CC
	ldr r0, [r0]
	cmp r0, #0
	beq _08049FE0
	movs r0, #1
_08049FE0:
	pop {r1}
	bx r1
	.align 2, 0
_08049FE4: .4byte 0x030000CC

	thumb_func_start FUN_08049fe8
FUN_08049fe8: @ 0x08049FE8
	push {r4, lr}
	adds r4, r1, #0
	ldr r0, [r0, #0x10]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a000
FUN_0804a000: @ 0x0804A000
	push {r4, lr}
	ldr r2, [r0, #0x1c]
	cmp r2, #0
	beq _0804A020
	movs r4, #0xe0
	lsls r4, r4, #1
_0804A00C:
	adds r0, r2, r4
	ldr r3, [r0]
	ldr r0, [r2]
	cmp r0, r1
	bne _0804A01A
	adds r0, r2, #0
	b _0804A022
_0804A01A:
	adds r2, r3, #0
	cmp r2, #0
	bne _0804A00C
_0804A020:
	movs r0, #0
_0804A022:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a028
FUN_0804a028: @ 0x0804A028
	push {lr}
	adds r1, r0, #0
	ldr r0, _0804A03C @ =0x030000CC
	ldr r0, [r0]
	cmp r0, #0
	beq _0804A040
	bl FUN_0804a000
	b _0804A042
	.align 2, 0
_0804A03C: .4byte 0x030000CC
_0804A040:
	movs r0, #0
_0804A042:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a048
FUN_0804a048: @ 0x0804A048
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_0804A04E:
	ldr r1, [r4, #0x18]
	adds r1, #1
	str r1, [r4, #0x18]
	ldr r0, _0804A070 @ =0x000F423F
	cmp r1, r0
	ble _0804A05E
	movs r0, #1
	str r0, [r4, #0x18]
_0804A05E:
	ldr r1, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_0804a000
	cmp r0, #0
	bne _0804A074
	ldr r0, [r4, #0x18]
	b _0804A07E
	.align 2, 0
_0804A070: .4byte 0x000F423F
_0804A074:
	adds r5, #1
	cmp r5, #3
	ble _0804A04E
	movs r0, #1
	rsbs r0, r0, #0
_0804A07E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a084
FUN_0804a084: @ 0x0804A084
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	mov sb, r1
	mov sl, r2
	str r3, [sp, #4]
	ldr r0, _0804A0D0 @ =0x030000CC
	ldr r5, [r0]
	cmp r5, #0
	beq _0804A0CA
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r4, #0
	bl Malloc
	adds r7, r0, #0
	cmp r7, #0
	beq _0804A0CA
	adds r0, r7, #0
	adds r1, r4, #0
	bl ClearMemory
	adds r0, r5, #0
	bl FUN_0804a048
	str r0, [r7]
	cmp r0, #0
	bge _0804A0D4
	adds r0, r7, #0
	bl Free
_0804A0CA:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A152
	.align 2, 0
_0804A0D0: .4byte 0x030000CC
_0804A0D4:
	movs r6, #0
	mov r0, r8
	strb r0, [r7, #4]
	mov r1, sb
	strb r1, [r7, #5]
	mov r0, sl
	strb r0, [r7, #6]
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r7, #7]
	movs r0, #0
	mov sb, r0
	strh r6, [r7, #8]
	strh r6, [r7, #0xa]
	ldr r0, _0804A164 @ =0x0000FFFF
	strh r0, [r7, #0xc]
	str r6, [r7, #0x10]
	strh r6, [r7, #0x14]
	movs r1, #1
	mov r8, r1
	movs r0, #1
	strh r0, [r7, #0x16]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	str r6, [r0]
	adds r1, #4
	adds r0, r7, r1
	str r6, [r0]
	ldr r0, _0804A168 @ =FUN_0804a4a0
	str r0, [r7, #0x58]
	adds r4, r7, #0
	adds r4, #0x5c
	ldrb r1, [r7, #4]
	ldrb r2, [r7, #5]
	ldrb r3, [r7, #6]
	ldrb r0, [r7, #7]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_0804967c
	mov r0, sb
	strb r0, [r4, #0xf]
	mov r1, r8
	strb r1, [r4, #0xb]
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq _0804A13C
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r0, r1
	str r7, [r0]
_0804A13C:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	str r6, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r5, #0x1c]
	str r0, [r1]
	str r7, [r5, #0x1c]
	ldr r0, [r7]
_0804A152:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804A164: .4byte 0x0000FFFF
_0804A168: .4byte FUN_0804a4a0

	thumb_func_start FUN_0804a16c
FUN_0804a16c: @ 0x0804A16C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0804A18C @ =0x030000CC
	ldr r5, [r0]
	cmp r5, #0
	beq _0804A186
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0804a000
	adds r4, r0, #0
	cmp r4, #0
	bne _0804A190
_0804A186:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A1EA
	.align 2, 0
_0804A18C: .4byte 0x030000CC
_0804A190:
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl FUN_0822ea60
	ldr r0, _0804A1BC @ =FUN_0804a4a0
	str r0, [r4, #0x58]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r3, r0, #0
	cmp r2, #0
	beq _0804A1C0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r1, r4, r0
	ldr r0, [r1]
	str r0, [r2]
	b _0804A1CA
	.align 2, 0
_0804A1BC: .4byte FUN_0804a4a0
_0804A1C0:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	str r0, [r5, #0x1c]
_0804A1CA:
	adds r2, r1, #0
	ldr r1, [r2]
	cmp r1, #0
	beq _0804A1DC
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r3]
	str r0, [r1]
_0804A1DC:
	movs r0, #0
	str r0, [r3]
	str r0, [r2]
	adds r0, r4, #0
	bl Free
	adds r0, r6, #0
_0804A1EA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a1f0
FUN_0804a1f0: @ 0x0804A1F0
	push {lr}
	bl FUN_0804a028
	adds r1, r0, #0
	cmp r1, #0
	beq _0804A208
	ldr r0, _0804A204 @ =FUN_0804a4a8
	str r0, [r1, #0x58]
	movs r0, #0
	b _0804A20C
	.align 2, 0
_0804A204: .4byte FUN_0804a4a8
_0804A208:
	movs r0, #1
	rsbs r0, r0, #0
_0804A20C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a210
FUN_0804a210: @ 0x0804A210
	push {r4, lr}
	bl FUN_0804a028
	adds r4, r0, #0
	cmp r4, #0
	beq _0804A234
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl FUN_0822ea60
	ldr r0, _0804A230 @ =FUN_0804a4a0
	str r0, [r4, #0x58]
	movs r0, #0
	b _0804A238
	.align 2, 0
_0804A230: .4byte FUN_0804a4a0
_0804A234:
	movs r0, #1
	rsbs r0, r0, #0
_0804A238:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a240
FUN_0804a240: @ 0x0804A240
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	bl FUN_0804a028
	adds r5, r0, #0
	cmp r5, #0
	beq _0804A272
	adds r4, r5, #0
	adds r4, #0x5c
	str r6, [r5, #0x10]
	ldrh r1, [r5, #0xa]
	bl FUN_08049fe8
	str r0, [r4, #0x1c]
	movs r1, #0
	strh r1, [r5, #0xa]
	strh r1, [r5, #0x14]
	movs r0, #1
	strh r0, [r5, #0x16]
	strh r1, [r5, #0xc]
	adds r0, r4, #0
	bl FUN_08049640
	movs r0, #0
	b _0804A276
_0804A272:
	movs r0, #1
	rsbs r0, r0, #0
_0804A276:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a27c
FUN_0804a27c: @ 0x0804A27C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl FUN_0804a028
	adds r5, r0, #0
	cmp r5, #0
	bne _0804A298
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A2EE
_0804A298:
	adds r4, r5, #0
	adds r4, #0x5c
	str r6, [r5, #0x10]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08049fe8
	str r0, [r4, #0x1c]
	mov r0, r8
	strh r0, [r5, #0x14]
	strh r7, [r5, #0x16]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	adds r6, r4, #0
	cmp r0, #0x20
	bls _0804A2BC
	movs r0, #0x20
	strh r0, [r5, #0x16]
_0804A2BC:
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r0, [r5, #0x16]
	cmp r3, r0
	bge _0804A2DC
	ldr r2, [sp, #0x18]
	adds r1, r4, #0
_0804A2CC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	ldrh r0, [r5, #0x16]
	cmp r3, r0
	blt _0804A2CC
_0804A2DC:
	ldrh r0, [r5, #0x14]
	lsls r0, r0, #1
	adds r0, r4, r0
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	adds r0, r6, #0
	bl FUN_08049640
	movs r0, #0
_0804A2EE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a2f8
FUN_0804a2f8: @ 0x0804A2F8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r1, #0
	bl FUN_0804a028
	adds r4, r0, #0
	cmp r4, #0
	bne _0804A30E
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A350
_0804A30E:
	adds r5, r4, #0
	adds r5, #0x5c
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0804A34E
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl FUN_0822ea60
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	ldrb r3, [r4, #6]
	ldrb r0, [r4, #7]
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_08049650
	strh r6, [r4, #0xa]
	ldrh r1, [r4, #0xa]
	adds r0, r4, #0
	bl FUN_08049fe8
	str r0, [r5, #0x1c]
	ldr r0, _0804A358 @ =FUN_0804a4a8
	str r0, [r4, #0x58]
	adds r0, r5, #0
	bl FUN_08049640
	ldr r0, _0804A35C @ =0x0000FFFF
	strh r0, [r4, #0xc]
_0804A34E:
	movs r0, #0
_0804A350:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0804A358: .4byte FUN_0804a4a8
_0804A35C: .4byte 0x0000FFFF

	thumb_func_start FUN_0804a360
FUN_0804a360: @ 0x0804A360
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0804a028
	adds r3, r0, #0
	cmp r3, #0
	beq _0804A382
	adds r0, #0x5c
	movs r1, #0
	str r1, [r3, #0x10]
	movs r2, #0
	strh r1, [r3, #0xc]
	str r4, [r0, #0x1c]
	strb r2, [r0, #8]
	strb r2, [r0, #7]
	movs r0, #0
	b _0804A386
_0804A382:
	movs r0, #1
	rsbs r0, r0, #0
_0804A386:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a38c
FUN_0804a38c: @ 0x0804A38C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl FUN_0804a028
	adds r5, r0, #0
	cmp r5, #0
	bne _0804A3AA
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A3D6
_0804A3AA:
	adds r4, r5, #0
	adds r4, #0x5c
	ldrb r0, [r5, #4]
	ldrb r1, [r5, #5]
	ldrb r2, [r5, #6]
	ldrb r3, [r5, #7]
	bl FUN_0822ea60
	strb r6, [r5, #4]
	strb r7, [r5, #5]
	mov r0, r8
	strb r0, [r5, #6]
	ldr r0, [sp, #0x1c]
	strb r0, [r5, #7]
	ldrb r1, [r5, #4]
	ldrb r2, [r5, #5]
	ldrb r3, [r5, #6]
	ldrb r0, [r5, #7]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08049650
_0804A3D6:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a3e4
FUN_0804a3e4: @ 0x0804A3E4
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	bl FUN_0804a028
	cmp r0, #0
	beq _0804A400
	adds r0, #0x5c
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080496c0
	movs r0, #0
	b _0804A404
_0804A400:
	movs r0, #1
	rsbs r0, r0, #0
_0804A404:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a40c
FUN_0804a40c: @ 0x0804A40C
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	bl FUN_0804a028
	cmp r0, #0
	bne _0804A420
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A42A
_0804A420:
	adds r0, #0x5c
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080496cc
_0804A42A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a430
FUN_0804a430: @ 0x0804A430
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0804a028
	cmp r0, #0
	beq _0804A454
	adds r1, r0, #0
	adds r1, #0x5c
	ldrb r0, [r1, #2]
	str r0, [r4]
	ldrb r0, [r1, #3]
	str r0, [r4, #4]
	ldrb r0, [r1, #4]
	str r0, [r4, #8]
	ldrb r0, [r1, #5]
	str r0, [r4, #0xc]
	movs r0, #0
	b _0804A458
_0804A454:
	movs r0, #1
	rsbs r0, r0, #0
_0804A458:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a460
FUN_0804a460: @ 0x0804A460
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0804a028
	cmp r0, #0
	beq _0804A476
	adds r0, #0x5c
	adds r1, r4, #0
	bl FUN_08049708
	b _0804A47A
_0804A476:
	movs r0, #1
	rsbs r0, r0, #0
_0804A47A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a480
FUN_0804a480: @ 0x0804A480
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0804a028
	cmp r0, #0
	beq _0804A496
	adds r0, #0x5c
	adds r1, r4, #0
	bl FUN_08049784
	b _0804A49A
_0804A496:
	movs r0, #1
	rsbs r0, r0, #0
_0804A49A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a4a0
FUN_0804a4a0: @ 0x0804A4A0
	adds r1, #0x5c
	movs r0, #0
	strb r0, [r1, #0xf]
	bx lr

	thumb_func_start FUN_0804a4a8
FUN_0804a4a8: @ 0x0804A4A8
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x5c
	movs r6, #0
	b _0804A4BA
_0804A4B4:
	adds r6, #1
	cmp r6, #0
	bgt _0804A4E0
_0804A4BA:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0804A4B4
	movs r0, #0
	strb r0, [r4, #8]
	adds r0, r4, #0
	bl FUN_08049568
	cmp r0, #0
	beq _0804A4B4
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0804A4DC
	ldr r0, _0804A4D8 @ =FUN_0804a4a0
	b _0804A4DE
	.align 2, 0
_0804A4D8: .4byte FUN_0804a4a0
_0804A4DC:
	ldr r0, _0804A4E8 @ =FUN_0804a4ec
_0804A4DE:
	str r0, [r5, #0x58]
_0804A4E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804A4E8: .4byte FUN_0804a4ec

	thumb_func_start FUN_0804a4ec
FUN_0804a4ec: @ 0x0804A4EC
	bx lr
	.align 2, 0

	thumb_func_start Entity6273_Update
Entity6273_Update: @ 0x0804A4F0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r4, [r7, #0x1c]
	cmp r4, #0
	beq _0804A538
_0804A4FA:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	adds r5, r4, #0
	adds r5, #0x5c
	adds r0, r5, #0
	bl FUN_08049884
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	cmp r0, #0
	blt _0804A51E
	ldr r0, [r4]
	movs r2, #0xc
	ldrsh r1, [r4, r2]
	bl FUN_0804a2f8
_0804A51E:
	ldr r2, [r4, #0x58]
	cmp r2, #0
	beq _0804A52C
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_0804A52C:
	adds r0, r5, #0
	bl FUN_08049890
	adds r4, r6, #0
	cmp r4, #0
	bne _0804A4FA
_0804A538:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity6273_Destroy
Entity6273_Destroy: @ 0x0804A540
	push {r4, lr}
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq _0804A55C
_0804A548:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r4, [r0]
	ldr r0, [r1]
	bl FUN_0804a16c
	adds r1, r4, #0
	cmp r1, #0
	bne _0804A548
_0804A55C:
	ldr r1, _0804A568 @ =0x030000CC
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A568: .4byte 0x030000CC

	thumb_func_start Entity6273_Init
Entity6273_Init: @ 0x0804A56C
	ldr r1, _0804A57C @ =0x030000CC
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x18]
	str r1, [r0, #0x1c]
	movs r0, #0
	bx lr
	.align 2, 0
_0804A57C: .4byte 0x030000CC

	thumb_func_start Entity6273_Create
Entity6273_Create: @ 0x0804A580
	push {r4, lr}
	ldr r0, _0804A5B4 @ =0x030000CC
	ldr r4, [r0]
	cmp r4, #0
	bne _0804A5C0
	movs r0, #0xc
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804A5C0
	ldr r1, _0804A5B8 @ =Entity6273_Update
	ldr r2, _0804A5BC @ =Entity6273_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity6273_Init
	cmp r0, #0
	bge _0804A5C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804A5C2
	.align 2, 0
_0804A5B4: .4byte 0x030000CC
_0804A5B8: .4byte Entity6273_Update
_0804A5BC: .4byte Entity6273_Destroy
_0804A5C0:
	adds r0, r4, #0
_0804A5C2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a5c8
FUN_0804a5c8: @ 0x0804A5C8
	push {r4, lr}
	ldr r0, _0804A5F4 @ =0x030000CC
	ldr r0, [r0]
	cmp r0, #0
	beq _0804A5EC
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq _0804A5EC
_0804A5D8:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r4, [r0]
	ldr r0, [r1]
	bl FUN_0804a16c
	adds r1, r4, #0
	cmp r1, #0
	bne _0804A5D8
_0804A5EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A5F4: .4byte 0x030000CC
