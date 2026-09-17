	push {lr}
	ldr r0, [r1, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r1, [r1, #0x18]
	ldr r0, [r2, #4]
	adds r1, r1, r0
	movs r3, #0
	ldrh r0, [r2, #2]
	cmp r3, r0
	bge _08237408
	adds r2, r0, #0
_082373FC:
	ldrh r0, [r1, #2]
	adds r3, r3, r0
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bne _082373FC
_08237408:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0
