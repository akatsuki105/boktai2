	push {r4, r5, r6, lr}
	adds r6, r1, #0
	ldr r0, _08040F00 @ =0x03002B50
	ldr r0, [r0]
	cmp r0, #0
	beq _08040F04
	movs r5, #0xbc
	lsls r5, r5, #2
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08040F04
	adds r1, r5, #0
	bl ClearMemory
	strb r6, [r4, #1]
	adds r0, r4, #0
	b _08040F06
	.align 2, 0
_08040F00: .4byte 0x03002B50
_08040F04:
	movs r0, #0
_08040F06:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
