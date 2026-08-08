	push {r4, r5, lr}
	movs r1, #4
	ldr r0, _080EC56C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080EC570 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080EC574
	movs r0, #1
	b _080EC576
	.align 2, 0
_080EC56C: .4byte 0x030046A0
_080EC570: .4byte 0x00000934
_080EC574:
	movs r0, #0
_080EC576:
	cmp r0, #0
	beq _080EC5A8
	ldr r5, _080EC5B0 @ =0x030046A0
	movs r3, #0
	movs r4, #0xc2
	lsls r4, r4, #2
	movs r2, #0x13
_080EC584:
	adds r0, r3, r4
	ldr r1, [r5]
	adds r1, r1, r0
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq _080EC5A0
	ldrh r0, [r1, #4]
	subs r0, #1
	strh r0, [r1, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _080EC5A0
	strh r0, [r1, #2]
_080EC5A0:
	adds r3, #6
	subs r2, #1
	cmp r2, #0
	bge _080EC584
_080EC5A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080EC5B0: .4byte 0x030046A0
