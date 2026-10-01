	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	mov r8, r0
	movs r5, #0x9c
	lsls r5, r5, #1
	add r5, r8
	movs r6, #0
	add r0, sp, #0x24
	mov sb, r0
	adds r7, r5, #0
	movs r4, #0xb2
	lsls r4, r4, #1
	add r4, r8
_0801C538:
	movs r0, #3
	ands r0, r6
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x13
	movs r2, #0x90
	lsls r2, r2, #0x10
	adds r1, r1, r2
	asrs r2, r6, #2
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0x13
	movs r2, #0x80
	lsls r2, r2, #0xe
	adds r0, r0, r2
	lsrs r1, r1, #0x10
	orrs r1, r0
	str r1, [sp, #0x24]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08242b14
	mov r0, r8
	adds r1, r7, #0
	mov r2, sp
	mov r3, sb
	bl FUN_0801c488
	movs r0, #1
	lsls r0, r6
	mov r2, r8
	ldr r1, [r2, #0x50]
	ands r0, r1
	cmp r0, #0
	beq _0801C594
	ldr r0, _0801C590 @ =0x000002DF
	strh r0, [r4, #0x32]
	movs r0, #0
	bl FUN_0801b670
	adds r1, r0, #0
	str r1, [r4, #0x40]
	b _0801C5AA
	.align 2, 0
_0801C590: .4byte 0x000002DF
_0801C594:
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
	bl FUN_0801b670
	adds r1, r0, #0
	str r1, [r4, #0x40]
	ldrb r1, [r5]
	cmp r1, #0
	beq _0801C5B4
_0801C5AA:
	ldr r1, [r4]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4]
_0801C5B4:
	adds r7, #0x84
	adds r6, #1
	adds r4, #0x84
	adds r5, #0x84
	cmp r6, #0xf
	ble _0801C538
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
