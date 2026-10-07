	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081DEC14 @ =0x030044D0
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEBF6
	ldr r2, _081DEC18 @ =FUN_081debc0
	movs r0, #0
	movs r1, #0
	adds r3, r4, #0
	bl FUN_080a6180
_081DEBF6:
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DEC0C
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
_081DEC0C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DEC14: .4byte 0x030044D0
_081DEC18: .4byte FUN_081debc0
