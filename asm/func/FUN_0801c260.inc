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
	ldr r2, _0801C2B4 @ =0x05000002
	bl CpuSet
	mov r8, r4
	movs r7, #0
	ldr r0, _0801C2B8 @ =0x00000C24
	adds r4, r6, r0
	movs r5, #3
_0801C284:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xf8
	movs r2, #0x41
	movs r3, #0x31
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C284
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C2B4: .4byte 0x05000002
_0801C2B8: .4byte 0x00000C24
