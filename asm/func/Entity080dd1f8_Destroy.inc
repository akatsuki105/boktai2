	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r1, _080DD180 @ =0x00000F68
	adds r7, r0, r1
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r5, r0, r1
	adds r4, r0, #0
	adds r4, #0x38
_080DD16E:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DD184
	movs r0, #1
	b _080DD186
	.align 2, 0
_080DD180: .4byte 0x00000F68
_080DD184:
	movs r0, #0
_080DD186:
	cmp r0, #0
	beq _080DD196
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	bl ParticleShadow_Remove
_080DD196:
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0xb
	ble _080DD16E
	movs r1, #0
	ldr r0, _080DD1B4 @ =0x0300016C
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1B4: .4byte 0x0300016C
