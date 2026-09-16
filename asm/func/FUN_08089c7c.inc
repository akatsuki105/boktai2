	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _08089CC0 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _08089CD6
	adds r7, r2, #0
_08089C98:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #3
	bne _08089CC4
	movs r0, #1
	b _08089CD8
	.align 2, 0
_08089CC0: .4byte 0x03002B4C
_08089CC4:
	adds r5, #1
	ldr r1, [r7]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _08089C98
_08089CD6:
	movs r0, #0
_08089CD8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
