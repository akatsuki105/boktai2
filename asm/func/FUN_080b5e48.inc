	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080B5E84
	ldr r1, _080B5E68 @ =0x00001429
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080B5E70
	ldr r1, _080B5E6C @ =0x0000130C
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080B5F0E
	.align 2, 0
_080B5E68: .4byte 0x00001429
_080B5E6C: .4byte 0x0000130C
_080B5E70:
	ldr r1, _080B5E80 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080B5F0E
	.align 2, 0
_080B5E80: .4byte 0x0000130C
_080B5E84:
	ldr r0, _080B5EAC @ =0x0000142E
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _080B5EB0 @ =0x00001458
	adds r5, r4, r1
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	bge _080B5EB8
	ldr r1, _080B5EB4 @ =0x0000142B
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	b _080B5EDA
	.align 2, 0
_080B5EAC: .4byte 0x0000142E
_080B5EB0: .4byte 0x00001458
_080B5EB4: .4byte 0x0000142B
_080B5EB8:
	ldr r1, _080B5ECC @ =0x0000142B
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r6, [r6]
	cmp r0, r6
	bne _080B5EE4
	cmp r0, #0xf
	bhi _080B5ED0
	subs r1, #0x18
	b _080B5ED2
	.align 2, 0
_080B5ECC: .4byte 0x0000142B
_080B5ED0:
	ldr r1, _080B5EE0 @ =0x00001412
_080B5ED2:
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_080B5EDA:
	mvns r0, r0
	lsrs r0, r0, #0x1f
	b _080B5EE6
	.align 2, 0
_080B5EE0: .4byte 0x00001412
_080B5EE4:
	movs r0, #1
_080B5EE6:
	cmp r0, #1
	bne _080B5F00
	ldr r1, _080B5EFC @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080B5F0E
	.align 2, 0
_080B5EFC: .4byte 0x0000130C
_080B5F00:
	ldr r1, _080B5F14 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080B5F0E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B5F14: .4byte 0x0000130C
