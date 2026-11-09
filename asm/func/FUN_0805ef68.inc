	push {r4, lr}
	sub sp, #0x14
	adds r4, r1, #0
	cmp r0, #0
	beq _0805EF9E
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0805EF9E
	ldr r0, [sp, #0x1c]
	str r0, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x10]
	adds r0, r1, #0
	adds r1, r4, #0
	bl Entity0805f2dc_Spawn
	movs r0, #0
	b _0805EFA2
_0805EF9E:
	movs r0, #1
	rsbs r0, r0, #0
_0805EFA2:
	add sp, #0x14
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
