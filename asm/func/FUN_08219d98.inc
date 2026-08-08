	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r1, _08219DC0 @ =0x000012C8
	adds r4, r0, r1
	movs r2, #0
	mov r1, sp
	strh r2, [r1]
	adds r1, #2
	strh r2, [r1]
	movs r3, #0xa
	ldr r2, _08219DC4 @ =0x0000165C
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r5, r1, #0
	cmp r0, #0
	beq _08219DC8
	cmp r0, #1
	beq _08219DCC
	b _08219E4A
	.align 2, 0
_08219DC0: .4byte 0x000012C8
_08219DC4: .4byte 0x0000165C
_08219DC8:
	mov r2, sp
	b _08219DCE
_08219DCC:
	adds r2, r5, #0
_08219DCE:
	ldr r1, _08219DE0 @ =0x00000396
	adds r0, r4, r1
	movs r6, #0
	ldrsh r1, [r0, r6]
	cmp r1, r3
	bge _08219DE4
	movs r0, #0x1f
	b _08219E1E
	.align 2, 0
_08219DE0: .4byte 0x00000396
_08219DE4:
	adds r0, r3, #0
	adds r0, #0xa
	cmp r1, r0
	bge _08219DF0
	movs r0, #0x1f
	b _08219E1E
_08219DF0:
	adds r0, r3, #0
	adds r0, #0x12
	cmp r1, r0
	blt _08219E1C
	adds r0, r3, #0
	adds r0, #0x1a
	cmp r1, r0
	bge _08219E04
	movs r0, #0x12
	b _08219E1E
_08219E04:
	adds r0, r3, #0
	adds r0, #0x22
	cmp r1, r0
	bge _08219E10
	movs r0, #0xa
	b _08219E1E
_08219E10:
	adds r0, r3, #0
	adds r0, #0x2a
	cmp r1, r0
	bge _08219E1C
	movs r0, #0x12
	b _08219E1E
_08219E1C:
	movs r0, #0x1b
_08219E1E:
	strh r0, [r2]
	ldr r0, _08219E54 @ =0x00000396
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r3, #0
	adds r1, #0x32
	cmp r0, r1
	blt _08219E38
	strh r3, [r2]
_08219E38:
	ldr r1, _08219E58 @ =0x03004250
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r1, #0
	adds r2, #0x5a
	strh r0, [r2]
	ldrh r0, [r5]
	adds r1, #0x58
	strh r0, [r1]
_08219E4A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08219E54: .4byte 0x00000396
_08219E58: .4byte 0x03004250
