	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _081369AC @ =0x00000B3A
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _081369CA
	movs r5, #1
	adds r6, r2, #0
	ldr r7, _081369B0 @ =0x00000755
	adds r2, r1, r7
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r4, #0x90
	lsls r4, r4, #1
_081369A0:
	ldrb r0, [r2]
	ands r0, r5
	cmp r0, #0
	beq _081369B4
	movs r0, #1
	b _081369B6
	.align 2, 0
_081369AC: .4byte 0x00000B3A
_081369B0: .4byte 0x00000755
_081369B4:
	movs r0, #0
_081369B6:
	cmp r0, #0
	beq _081369BC
	str r5, [r1]
_081369BC:
	adds r2, r2, r4
	adds r1, r1, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _081369A0
_081369CA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
