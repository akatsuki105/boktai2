	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	bl FUN_0823b3ec
	adds r3, r0, #0
	cmp r3, #0
	beq _081D1DDC
	movs r0, #0
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x82
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D1D04
	mov r5, sb
	strb r5, [r1]
_081D1D04:
	ldr r4, [r3, #0x18]
	cmp r4, #0
	beq _081D1DBA
	mov r7, sp
	movs r0, #0x1c
	adds r0, r0, r6
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #0x11
	mov r8, r1
_081D1D18:
	ldrh r1, [r4, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081D1DB4
	ldr r0, _081D1DAC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081D1D4A
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _081D1D4A
	ldr r0, _081D1DB0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _081D1DB4
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D1DB4
_081D1D4A:
	adds r3, r4, #0
	adds r3, #8
	ldrh r2, [r4, #8]
	ldrh r0, [r6, #0x1c]
	subs r2, r2, r0
	strh r2, [r7]
	ldrh r1, [r3, #2]
	mov r5, ip
	ldrh r0, [r5, #2]
	subs r5, r1, r0
	strh r5, [r7, #2]
	ldrh r1, [r3, #4]
	mov r3, ip
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r7, #4]
	lsls r2, r2, #0x10
	mov r0, r8
	lsrs r3, r0, #0x10
	cmp r2, r8
	bhi _081D1DB4
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x20
	bgt _081D1DB4
	cmp r0, #0
	blt _081D1DB4
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	bgt _081D1DB4
	cmp r0, #0
	blt _081D1DB4
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_081d1bf8
	adds r2, r6, #0
	adds r2, #0x84
	ldrh r1, [r2]
	adds r0, r6, #0
	adds r0, #0x86
	ldrh r0, [r0]
	subs r0, #1
	cmp r1, r0
	bge _081D1DDC
	adds r0, r1, #1
	b _081D1DDA
	.align 2, 0
_081D1DAC: .4byte 0x030047A4
_081D1DB0: .4byte 0x03002BE0
_081D1DB4:
	ldr r4, [r4, #0x40]
	cmp r4, #0
	bne _081D1D18
_081D1DBA:
	mov r1, sb
	cmp r1, #0
	bne _081D1DDC
	adds r2, r6, #0
	adds r2, #0x84
	adds r1, r6, #0
	adds r1, #0x86
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	blo _081D1DD8
	adds r0, r6, #0
	bl FUN_081d1c64
	b _081D1DDC
_081D1DD8:
	adds r0, #1
_081D1DDA:
	strh r0, [r2]
_081D1DDC:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
