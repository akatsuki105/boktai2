	push {lr}
	ldr r2, [r0, #0x1c]
	cmp r2, #0
	beq _08040ED2
	movs r3, #0xbb
	lsls r3, r3, #2
_08040EBC:
	adds r0, r2, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	cmp r0, r1
	bne _08040ECA
	adds r0, r2, #0
	b _08040ED4
_08040ECA:
	adds r0, r2, r3
	ldr r2, [r0]
	cmp r2, #0
	bne _08040EBC
_08040ED2:
	movs r0, #0
_08040ED4:
	pop {r1}
	bx r1
