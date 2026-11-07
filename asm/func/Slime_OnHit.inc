	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816241C
	ldrh r0, [r5, #0xa]
	cmp r0, #1
	bne _0816241C
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08162408
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08162408
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08162424 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08162408:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _0816241C
	adds r0, r4, #0
	bl FUN_08164780
	str r0, [r6, #0x38]
_0816241C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08162424: .4byte 0xFEFFFFFF
