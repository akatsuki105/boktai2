	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CFCD8
	cmp r1, #0
	blt _080CFCD8
	ldr r0, _080CFCDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CFCD8
	ldr r0, _080CFCE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CFCE4
_080CFCD8:
	movs r4, #0
	b _080CFCF2
	.align 2, 0
_080CFCDC: .4byte 0x030046A8
_080CFCE0: .4byte 0x030046AC
_080CFCE4:
	ldr r0, _080CFD04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CFCF2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080CFD08
	adds r0, #4
	b _080CFD14
	.align 2, 0
_080CFD04: .4byte 0x030046A4
_080CFD08:
	ldr r0, _080CFDA0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CFD14:
	ldrh r0, [r0, #2]
	bl FUN_080cfc04
	cmp r0, #0
	beq _080CFDE4
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080CFDE4
	ldr r2, _080CFDA4 @ =0x00000395
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CFDE4
	adds r0, r7, #0
	adds r0, #0x2c
	bl Elevator_FindAtPos
	cmp r0, #0
	bne _080CFDE4
	movs r5, #0xe0
	lsls r5, r5, #1
	adds r6, r7, r5
	ldrh r0, [r6]
	ldr r5, _080CFDA0 @ =0x030046A4
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl Mod
	adds r4, r0, #0
	ldrh r0, [r6]
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl Div
	lsls r4, r4, #8
	adds r1, r4, #0
	adds r1, #0x80
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r3, r7, r2
	strh r1, [r3]
	lsls r0, r0, #8
	adds r2, r0, #0
	adds r2, #0x80
	movs r5, #0xe8
	lsls r5, r5, #2
	adds r1, r7, r5
	strh r2, [r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r1, r7, r2
	str r3, [r1]
	adds r2, r4, #1
	adds r4, #0xff
	adds r3, r0, #1
	adds r0, #0xff
	movs r5, #0x2c
	ldrsh r1, [r7, r5]
	cmp r1, r2
	bge _080CFDA8
	strh r2, [r7, #0x2c]
	b _080CFDAE
	.align 2, 0
_080CFDA0: .4byte 0x030046A4
_080CFDA4: .4byte 0x00000395
_080CFDA8:
	cmp r1, r4
	ble _080CFDAE
	strh r4, [r7, #0x2c]
_080CFDAE:
	movs r2, #0x30
	ldrsh r1, [r7, r2]
	cmp r1, r3
	bge _080CFDBA
	strh r3, [r7, #0x30]
	b _080CFDC0
_080CFDBA:
	cmp r1, r0
	ble _080CFDC0
	strh r0, [r7, #0x30]
_080CFDC0:
	movs r5, #0x82
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, r7, #0
	adds r2, #0xa8
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_080CFDE4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
