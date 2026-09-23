	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_08060646:
	movs r0, #0x58
	muls r0, r5, r0
	adds r1, r6, r0
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	beq _080606E8
	adds r2, r1, #0
	adds r2, #0x18
	adds r3, r2, #0
	adds r3, #0x2c
	ldrh r0, [r2, #2]
	ldrh r1, [r2, #4]
	cmp r0, r1
	blo _080606A8
	movs r0, #8
	ldrsh r1, [r2, r0]
	ldrh r0, [r2, #6]
	muls r1, r0, r1
	adds r4, r0, #0
	cmp r1, #0
	blt _08060674
	asrs r0, r1, #8
	b _0806067A
_08060674:
	rsbs r0, r1, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0806067A:
	strh r0, [r2, #8]
	movs r1, #0xa
	ldrsh r0, [r2, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0806068A
	asrs r0, r0, #8
	b _08060690
_0806068A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08060690:
	strh r0, [r2, #0xa]
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080606A0
	asrs r0, r0, #8
	b _080606A6
_080606A0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080606A6:
	strh r0, [r2, #0xc]
_080606A8:
	ldrh r0, [r2, #8]
	ldrh r1, [r3, #0x1c]
	adds r0, r0, r1
	movs r4, #0
	strh r0, [r3, #0x1c]
	ldrh r0, [r2, #0xa]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080606CC
	ldrh r0, [r2, #0xc]
	ldrh r1, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
_080606CC:
	ldrh r0, [r2, #2]
	lsrs r0, r0, #2
	strh r0, [r3, #0x10]
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x18
	bls _080606E8
	strb r4, [r2]
	adds r0, r3, #0
	bl AuxSprite_Remove
_080606E8:
	adds r5, #1
	cmp r5, #0xf
	ble _08060646
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
