	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #0
	adds r5, r7, #0
	adds r5, #0xc8
	adds r4, r7, #0
	adds r4, #0x20
_081F533A:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F534A
	movs r0, #1
	b _081F534C
_081F534A:
	movs r0, #0
_081F534C:
	cmp r0, #0
	beq _081F535C
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	bl Hitbox_Unregister
_081F535C:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #7
	ble _081F533A
	movs r1, #0
	ldr r0, _081F5378 @ =0x030001F8
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F5378: .4byte 0x030001F8
