	push {r4, r5, r6, lr}
	sub sp, #4
	adds r2, r0, #0
	adds r4, r1, #0
	movs r5, #0
	strb r5, [r4, #1]
	movs r0, #1
	strb r0, [r4, #2]
	str r5, [r4, #0x14]
	adds r6, r4, #0
	adds r6, #0x20
	adds r2, #0x18
	adds r0, r6, #0
	adds r1, r2, #0
	movs r2, #1
	bl AuxSprite_Setup
	movs r0, #3
	strb r0, [r6, #7]
	adds r4, #0x3c
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0805EB28 @ =0x05000002
	bl CpuSet
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805EB28: .4byte 0x05000002
