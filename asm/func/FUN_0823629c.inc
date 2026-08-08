	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	ldr r0, _082362B0 @ =0x030046A4
	ldr r0, [r0]
	ldr r6, [r0, #0x14]
	movs r3, #0
	b _082362E6
	.align 2, 0
_082362B0: .4byte 0x030046A4
_082362B4:
	lsls r1, r3, #2
	adds r0, r6, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r5, r6, r0
	ldr r0, [r5, #8]
	adds r7, r5, r0
	movs r4, #0
	b _082362DE
_082362C6:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	str r3, [sp]
	bl FUN_08235924
	ldr r3, [sp]
	cmp r0, #0
	beq _082362DC
	adds r0, r4, #0
	b _082362EE
_082362DC:
	adds r4, #1
_082362DE:
	ldrh r0, [r5]
	cmp r4, r0
	blt _082362C6
	adds r3, #1
_082362E6:
	ldrh r0, [r6]
	cmp r3, r0
	blt _082362B4
	movs r0, #0xff
_082362EE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
