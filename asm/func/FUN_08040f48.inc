	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, [sp, #0x14]
	adds r5, r4, #0
	adds r5, #0xd0
	cmp r1, #2
	bne _08040F7A
	adds r3, r4, #0
	adds r3, #0x64
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r6, #0
	bl FUN_08055e34
	adds r6, r0, #0
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r0, [r1, #0x3a]
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x5c
	bl Mover_SetMainSprite
	b _08040FA2
_08040F7A:
	adds r0, r4, #0
	adds r0, #0x64
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r3, #0
	adds r3, r6, #0
	bl FUN_08055dac
	adds r6, r0, #0
	adds r0, r4, #0
	adds r0, #0xdc
	ldrh r0, [r0, #6]
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x5c
	adds r1, r4, #0
	adds r1, #0xf8
	bl Mover_SetAuxSprite
_08040FA2:
	ldrh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08055f5c
	cmp r6, #0
	bge _08040FB6
	movs r0, #1
	rsbs r0, r0, #0
_08040FB6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
