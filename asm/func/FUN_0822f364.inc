	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	ldr r0, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	ldr r4, [sp, #0x20]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	bl Sprite_LoadSprite
	cmp r0, #0
	blt _0822F3BC
	ldr r0, _0822F3B8 @ =0x030044B8
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r5, #2]
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	str r0, [r5, #8]
	strh r1, [r5, #0xc]
	movs r0, #0x40
	strh r0, [r5, #0x10]
	strh r4, [r5, #0xe]
	strb r7, [r5, #0x1a]
	strb r6, [r5, #0x1b]
	ldr r0, [sp, #0x24]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x20]
	str r1, [r5, #0x24]
	movs r0, #0
	b _0822F3C0
	.align 2, 0
_0822F3B8: .4byte 0x030044B8
_0822F3BC:
	movs r0, #1
	rsbs r0, r0, #0
_0822F3C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
