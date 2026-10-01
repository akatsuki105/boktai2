	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801C510 @ =0x05000002
	bl CpuSet
	movs r5, #0x12
	mov r8, r4
	movs r7, #0
	ldr r0, _0801C514 @ =0x00000AA4
	adds r4, r6, r0
_0801C4E0:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, r8
	str r2, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	movs r3, #0x11
	bl MainSprite_Add
	subs r4, #0x84
	subs r5, #1
	cmp r5, #0
	bge _0801C4E0
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C510: .4byte 0x05000002
_0801C514: .4byte 0x00000AA4
