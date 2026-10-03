	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	movs r6, #0
	ldrb r0, [r4, #0x1e]
	cmp r7, r0
	bge _080B1506
_080B14C6:
	lsls r0, r6, #2
	ldr r2, _080B1560 @ =0x00000BE8
	adds r1, r4, r2
	adds r5, r1, r0
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B14FE
	adds r7, #1
	adds r0, r1, #0
	adds r0, #0xec
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B14FE
	movs r0, #0x93
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	ldr r1, _080B1564 @ =FUN_080adb5c
	bl EntityCBB0_SetState
	ldr r0, [r5]
	adds r0, #0xec
	movs r1, #0
	strb r1, [r0]
_080B14FE:
	adds r6, #1
	ldrb r0, [r4, #0x1e]
	cmp r6, r0
	blt _080B14C6
_080B1506:
	ldr r2, _080B1568 @ =0x00001332
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _080B1522
	ldrb r0, [r4, #0x1e]
	cmp r7, r0
	blt _080B1522
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ad204
_080B1522:
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080B1536
	ldr r1, _080B156C @ =FUN_080adce4
	adds r0, r4, #0
	bl EntityCBB0_SetState
_080B1536:
	adds r0, r4, #0
	bl FUN_080b10f8
	cmp r0, #0
	beq _080B155A
	ldr r0, _080B1570 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xa1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ad1ec
_080B155A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1560: .4byte 0x00000BE8
_080B1564: .4byte FUN_080adb5c
_080B1568: .4byte 0x00001332
_080B156C: .4byte FUN_080adce4
_080B1570: .4byte 0x03002BE0
