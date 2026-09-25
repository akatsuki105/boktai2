	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r3, #0
	adds r6, #0x3c
	movs r4, #0
	movs r5, #0
	movs r2, #0
_080DADFA:
	movs r1, #1
	lsls r1, r2
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DAE0A
	movs r0, #1
	b _080DAE0C
_080DAE0A:
	movs r0, #0
_080DAE0C:
	cmp r0, #0
	beq _080DAE2E
	movs r0, #0xa4
	muls r0, r2, r0
	adds r0, r0, r6
	adds r0, #0x40
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080DAE24
	movs r4, #1
_080DAE24:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080DAE2E
	movs r5, #1
_080DAE2E:
	adds r2, #1
	cmp r2, #7
	ble _080DADFA
	cmp r4, #0
	bne _080DAE44
	ldr r0, _080DAE58 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080DAE5C @ =0x000003FF
	adds r0, r0, r1
	movs r1, #0xff
	strb r1, [r0]
_080DAE44:
	cmp r5, #0
	bne _080DAE50
	movs r0, #1
	rsbs r0, r0, #0
	bl FUN_0808689c
_080DAE50:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DAE58: .4byte 0x03002BE0
_080DAE5C: .4byte 0x000003FF
