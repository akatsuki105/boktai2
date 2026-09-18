	push {r4, r5, lr}
	sub sp, #0xc
	ldr r3, _080226A4 @ =0xFFFF0000
	ldrh r1, [r2, #0xa]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #8]
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r1, [r2, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xe
	ldrsh r1, [r2, r0]
	movs r5, #0x10
	ldrsh r4, [r2, r5]
	movs r0, #0x12
	ldrsh r3, [r2, r0]
	movs r5, #0x14
	ldrsh r0, [r2, r5]
	str r0, [sp]
	add r0, sp, #4
	adds r2, r4, #0
	bl FUN_08019814
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080226A4: .4byte 0xFFFF0000
