	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	ldrh r1, [r4, #0x20]
	ldrh r2, [r4, #0x22]
	bl Video_SetBLDCNTDirect
	movs r1, #0x1b
	ldrsb r1, [r4, r1]
	ldr r0, [r4, #0x24]
	muls r0, r1, r0
	ldr r1, [r4, #0x28]
	bl Div
	movs r1, #0x19
	ldrsb r1, [r4, r1]
	adds r5, r1, r0
	ldrb r0, [r4, #0x18]
	cmp r0, #1
	bne _08019994
	movs r1, #0x1c
	ldrsb r1, [r4, r1]
	ldr r0, [r4, #0x24]
	muls r0, r1, r0
	ldr r1, [r4, #0x28]
	bl Div
	movs r1, #0x1a
	ldrsb r1, [r4, r1]
	adds r1, r1, r0
	adds r0, r5, #0
	bl Video_SetBLDALPHADirect
	b _0801999A
_08019994:
	adds r0, r5, #0
	bl Video_SetBLDYDirect
_0801999A:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	blo _080199A8
	adds r0, r4, #0
	bl KillEntity
_080199A8:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
