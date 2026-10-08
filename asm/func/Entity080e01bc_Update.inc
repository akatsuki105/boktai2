	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	ldr r0, [r5, #0x38]
	cmp r0, #0
	beq _080E0102
	movs r4, #0
	ldr r7, _080E00D4 @ =0x085AD364
_080E00C2:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080E00D8
	movs r0, #1
	b _080E00DA
	.align 2, 0
_080E00D4: .4byte 0x085AD364
_080E00D8:
	movs r0, #0
_080E00DA:
	cmp r0, #0
	beq _080E00FC
	movs r0, #0xda
	lsls r0, r0, #1
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	movs r2, #0xd7
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_080E00FC:
	adds r4, #1
	cmp r4, #7
	ble _080E00C2
_080E0102:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
