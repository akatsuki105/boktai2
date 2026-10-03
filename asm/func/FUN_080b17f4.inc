	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r3, _080B184C @ =0x030046A0
	cmp r0, #0
	beq _080B1828
	ldrb r0, [r4, #0x1e]
	cmp r5, r0
	bge _080B1828
	subs r1, #0x28
	adds r2, r4, r1
	adds r1, r0, #0
_080B1814:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B1820
	movs r5, #1
_080B1820:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B1814
_080B1828:
	ldr r0, [r3]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _080B183C
	adds r0, r4, #0
	bl FUN_080af0ac
_080B183C:
	cmp r5, #0
	beq _080B1854
	ldr r0, _080B1850 @ =0x000004FE
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _080B1878
	.align 2, 0
_080B184C: .4byte 0x030046A0
_080B1850: .4byte 0x000004FE
_080B1854:
	ldr r0, _080B1880 @ =0x000004FE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _080B1878
	ldr r1, _080B1884 @ =0x00000C6C
	adds r0, r4, r1
	movs r1, #6
	bl FUN_080af374
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ad1ec
_080B1878:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1880: .4byte 0x000004FE
_080B1884: .4byte 0x00000C6C
