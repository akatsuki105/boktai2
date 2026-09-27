	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081D46B0 @ =0x03000194
	ldr r0, [r0]
	ldr r1, _081D46B4 @ =0x000012B2
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D46F6
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	add r3, sp, #8
	adds r2, r5, #0
	adds r2, #0xfc
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D46B8
	movs r0, #1
	b _081D46BA
	.align 2, 0
_081D46B0: .4byte 0x03000194
_081D46B4: .4byte 0x000012B2
_081D46B8:
	movs r0, #0
_081D46BA:
	cmp r0, #0
	bne _081D46EE
	adds r0, r5, #0
	adds r0, #0x58
	mov r1, sp
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r2, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #2]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
_081D46EE:
	ldr r0, _081D4700 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_081D46F6:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D4700: .4byte 0xFFFFFDFF
