	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r2, #0
	ldrh r0, [r5, #8]
	bl FUN_0823b2d0
	adds r4, r0, #0
	cmp r4, #0
	beq _080226F4
	ldrh r0, [r4, #8]
	ldr r3, _080226FC @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _08022700 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #4]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	movs r4, #0xc
	ldrsh r2, [r5, r4]
	movs r0, #0xe
	ldrsh r3, [r5, r0]
	movs r4, #0x10
	ldrsh r0, [r5, r4]
	str r0, [sp]
	add r0, sp, #4
	bl FUN_08019814
_080226F4:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080226FC: .4byte 0xFFFF0000
_08022700: .4byte 0x0000FFFF
