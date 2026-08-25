	push {r4, r5, lr}
	sub sp, #0x14
	adds r1, r0, #0
	ldr r0, _0823B588 @ =0x0000AE6C
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	cmp r0, #0
	bne _0823B58C
	movs r0, #1
	rsbs r0, r0, #0
	b _0823B5D2
	.align 2, 0
_0823B588: .4byte 0x0000AE6C
_0823B58C:
	bl OpenCollisionMapFile
	adds r2, r0, #0
	mov r1, sp
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	ldr r0, [sp, #4]
	adds r0, r0, r2
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	adds r0, r0, r2
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	adds r0, r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _0823B5B8
	adds r0, r0, r2
	str r0, [sp, #0x10]
_0823B5B8:
	ldr r0, [sp, #4]
	bl FUN_082327f0
	ldr r0, [sp, #8]
	bl FUN_08234624
	ldr r0, [sp, #0xc]
	bl FUN_08234ddc
	ldr r0, [sp, #0x10]
	bl FUN_08235918
	movs r0, #0
_0823B5D2:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
