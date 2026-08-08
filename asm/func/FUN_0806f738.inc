	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0806F76C
	ldr r1, _0806F77C @ =0x000003CE
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0806F76C
	adds r0, r4, #0
	bl FUN_08067068
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	movs r5, #1
_0806F76C:
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0806F77C: .4byte 0x000003CE
