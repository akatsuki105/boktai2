	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _0807A72C @ =0x030046A0
	ldr r2, [r1]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r2, r4
	movs r5, #0
	ldrsh r4, [r0, r5]
	adds r5, r1, #0
	cmp r4, #5
	bne _0807A734
	ldr r0, _0807A730 @ =0x03002B74
	ldrh r0, [r0]
	b _0807A790
	.align 2, 0
_0807A72C: .4byte 0x030046A0
_0807A730: .4byte 0x03002B74
_0807A734:
	movs r6, #0x1e
	ldrsh r1, [r2, r6]
	movs r6, #0x26
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	cmp r3, #0
	bne _0807A750
	adds r0, r2, #0
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r1, r0
	asrs r0, r0, #1
	b _0807A790
_0807A750:
	ldrb r0, [r3, #3]
	cmp r0, #2
	beq _0807A76C
	cmp r0, #2
	bgt _0807A760
	cmp r0, #1
	beq _0807A766
	b _0807A77A
_0807A760:
	cmp r0, #0x1a
	beq _0807A776
	b _0807A77A
_0807A766:
	cmp r4, #0
	beq _0807A776
	b _0807A770
_0807A76C:
	cmp r4, #0
	bne _0807A776
_0807A770:
	ldrb r0, [r3, #4]
	subs r1, r1, r0
	b _0807A77A
_0807A776:
	ldrb r0, [r3, #4]
	adds r1, r1, r0
_0807A77A:
	cmp r1, #0x63
	ble _0807A780
	movs r1, #0x63
_0807A780:
	ldr r0, [r5]
	adds r0, #0x40
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r0, r1, r0
	asrs r0, r0, #1
	ldrb r3, [r3, #1]
	adds r0, r0, r3
_0807A790:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
