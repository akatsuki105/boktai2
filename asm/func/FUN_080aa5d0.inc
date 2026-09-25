	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080AA64C @ =0x0000034A
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AA5F2
	cmp r0, #0x12
	beq _080AA5F2
	cmp r0, #0x24
	beq _080AA5F2
	cmp r0, #0x36
	beq _080AA5F2
	cmp r0, #0x48
	beq _080AA5F2
	cmp r0, #0x5a
	bne _080AA5F8
_080AA5F2:
	adds r0, r4, #0
	bl FUN_080aa29c
_080AA5F8:
	adds r0, r4, #0
	bl FUN_080aa4e8
	ldr r0, _080AA64C @ =0x0000034A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x79
	bls _080AA646
	ldr r5, _080AA650 @ =0x030044BC
	ldr r6, _080AA654 @ =FUN_080aa23c
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0xe4
	movs r0, #0x88
	lsls r0, r0, #1
	adds r2, r4, r0
_080AA620:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080AA620
	movs r2, #0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	str r6, [r0]
	subs r1, #2
	adds r0, r4, r1
	strh r2, [r0]
_080AA646:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA64C: .4byte 0x0000034A
_080AA650: .4byte 0x030044BC
_080AA654: .4byte FUN_080aa23c
