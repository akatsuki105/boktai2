	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x10
	ldr r2, _08199F40 @ =0x00000111
	adds r0, r4, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08199F3A
	adds r1, r4, #0
	adds r1, #0xdc
	ldrh r0, [r1]
	cmp r0, #0
	beq _08199F10
	subs r0, #1
	strh r0, [r1]
_08199F10:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08199F22
	adds r0, r4, #0
	bl _call_via_r1
_08199F22:
	adds r0, r4, #0
	bl FUN_08195f1c
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08199F3A
	adds r0, r4, #0
	bl _call_via_r1
_08199F3A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08199F40: .4byte 0x00000111
