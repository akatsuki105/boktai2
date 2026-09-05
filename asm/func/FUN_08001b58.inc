	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x34
	ldr r1, [r4, #0x24]
	ldr r2, [r4, #0x28]
	movs r3, #0xc8
	lsls r3, r3, #3
	adds r0, r4, r3
	ldrb r3, [r0]
	movs r0, #0
	mov r8, r0
	str r0, [sp]
	movs r6, #0xd0
	str r6, [sp, #4]
	adds r0, r5, #0
	bl FUN_08001884
	ldr r1, [r4, #0x2c]
	ldr r2, _08001BC4 @ =0x04000068
	adds r0, r5, #0
	bl CpuSet
	adds r0, r4, #0
	bl FUN_080019dc
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, _08001BC8 @ =0x00000434
	adds r2, r4, r3
	ldr r3, _08001BCC @ =0x00000642
	adds r1, r4, r3
	ldrb r3, [r1]
	mov r1, r8
	str r1, [sp]
	str r6, [sp, #4]
	adds r1, r5, #0
	bl FUN_08001884
	str r5, [r4, #0x30]
	adds r4, #0x20
	movs r0, #1
	strb r0, [r4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001BC4: .4byte 0x04000068
_08001BC8: .4byte 0x00000434
_08001BCC: .4byte 0x00000642
