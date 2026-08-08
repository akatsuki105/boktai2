	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0
	cmp r5, #0x1e
	bgt _080E6344
	movs r0, #2
	cmp r5, #0xa
	ble _080E6344
	movs r0, #1
_080E6344:
	ldr r1, _080E6374 @ =0x085AD3C4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	cmp r0, #0
	bne _080E63CC
	movs r2, #1
	ldr r1, _080E6378 @ =0x0000025D
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _080E637C
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	bne _080E6388
	b _080E638C
	.align 2, 0
_080E6374: .4byte 0x085AD3C4
_080E6378: .4byte 0x0000025D
_080E637C:
	ldr r1, [r4, #0x44]
	ldr r0, [r1, #0x28]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _080E638C
_080E6388:
	movs r0, #1
	b _080E638E
_080E638C:
	movs r0, #0
_080E638E:
	cmp r0, #0
	beq _080E63B2
	ldrb r0, [r6]
	cmp r0, #0
	bne _080E63A4
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080E63CC
_080E63A4:
	adds r2, #0x20
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #8]
	ands r0, r1
	str r0, [r2, #8]
	b _080E63CC
_080E63B2:
	movs r3, #1
	ldrb r0, [r6]
	cmp r0, #0
	bne _080E63C2
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	b _080E63CC
_080E63C2:
	adds r1, r2, #0
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r3
	str r0, [r1, #8]
_080E63CC:
	cmp r5, #0x3c
	ble _080E63FE
	ldr r2, _080E63E8 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E63EC
	ldr r2, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080E63FA
	.align 2, 0
_080E63E8: .4byte 0x0000025D
_080E63EC:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080E63FA:
	movs r0, #1
	b _080E6400
_080E63FE:
	movs r0, #0
_080E6400:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
