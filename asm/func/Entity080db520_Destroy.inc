	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_080DB49E:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DB4AE
	movs r0, #1
	b _080DB4B0
_080DB4AE:
	movs r0, #0
_080DB4B0:
	cmp r0, #0
	beq _080DB4D0
	movs r0, #0xa4
	muls r0, r5, r0
	adds r0, #0x3c
	adds r4, r6, r0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _080DB4C8
	adds r0, r4, #0
	bl AuxSprite_Remove
_080DB4C8:
	adds r0, r4, #0
	adds r0, #0x4c
	bl Hitbox_Unregister
_080DB4D0:
	adds r5, #1
	cmp r5, #7
	ble _080DB49E
	ldr r1, _080DB4E4 @ =0x03000160
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080DB4E4: .4byte 0x03000160
