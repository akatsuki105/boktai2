	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080B1A70 @ =0x000004FE
	adds r5, r6, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x21
	bne _080B1A16
	ldr r0, _080B1A74 @ =0x03002C00
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _080B1A78 @ =0x03002BE0
	ldr r4, [r1]
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	adds r2, #0x4c
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0x30
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0807b910
_080B1A16:
	ldrh r0, [r5]
	cmp r0, #0x40
	bne _080B1A22
	ldr r0, _080B1A7C @ =0x000001C5
	bl PlaySound_082406e0
_080B1A22:
	ldrh r0, [r5]
	cmp r0, #0xf0
	bne _080B1A34
	ldr r0, _080B1A78 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	movs r0, #0x10
	bl FUN_0823bb7c
_080B1A34:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _080B1A56
	ldr r1, _080B1A80 @ =0x00001346
	adds r0, r6, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
	ldr r0, _080B1A78 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	movs r2, #0
	bl FUN_0807bcb0
_080B1A56:
	ldrh r1, [r5]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _080B1A68
	adds r0, r6, #0
	movs r1, #7
	bl FUN_080ad204
_080B1A68:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1A70: .4byte 0x000004FE
_080B1A74: .4byte 0x03002C00
_080B1A78: .4byte 0x03002BE0
_080B1A7C: .4byte 0x000001C5
_080B1A80: .4byte 0x00001346
