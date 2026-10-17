	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DA8AC
	ldr r1, _081DA8D0 @ =0x0000029E
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081DA8AC:
	ldr r0, _081DA8D0 @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0xa
	bne _081DA8C2
	adds r0, r5, #0
	bl FUN_081d9da4
	adds r0, r5, #0
	bl FUN_081d9ef4
_081DA8C2:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DA8D0: .4byte 0x0000029E
