	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r2, #0
	adds r4, #8
	movs r5, #0
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _08022718
	ldr r5, _0802276C @ =0x00000FFF
_08022718:
	movs r7, #0xc
	ldrsh r0, [r4, r7]
	cmp r0, #0
	beq _08022728
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r5, r0
_08022728:
	movs r7, #0xe
	ldrsh r0, [r4, r7]
	cmp r0, #0
	beq _08022738
	movs r1, #0xe0
	lsls r1, r1, #8
	adds r0, r1, #0
	orrs r5, r0
_08022738:
	movs r7, #8
	ldrsh r0, [r2, r7]
	movs r6, #3
	cmp r0, #0
	bne _08022744
	movs r6, #2
_08022744:
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r7, #4
	ldrsh r2, [r4, r7]
	movs r0, #6
	ldrsh r3, [r4, r0]
	movs r7, #8
	ldrsh r0, [r4, r7]
	str r0, [sp]
	str r5, [sp, #4]
	movs r5, #0x10
	ldrsh r0, [r4, r5]
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_0823ce68
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802276C: .4byte 0x00000FFF
