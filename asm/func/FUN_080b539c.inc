	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl MainSprite_AdvanceAnim
	ldr r0, _080B53E4 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _080B5422
	ldr r1, _080B53E8 @ =0x0000082E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _080B5404
	movs r0, #5
	bl MessageWindow_ShowLine
	movs r1, #0x83
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B53EC
	movs r1, #0
	bl VM_ExecByID
	b _080B53F4
	.align 2, 0
_080B53E4: .4byte 0x00000844
_080B53E8: .4byte 0x0000082E
_080B53EC:
	movs r0, #0
	movs r1, #3
	bl MessageWindow_SetVarValue
_080B53F4:
	ldr r1, _080B5400 @ =FUN_080b5434
	adds r0, r4, #0
	bl FUN_080b4aec
	b _080B5422
	.align 2, 0
_080B5400: .4byte FUN_080b5434
_080B5404:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B542C @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B5430 @ =FUN_080b54ec
	adds r0, r4, #0
	bl FUN_080b4aec
_080B5422:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B542C: .4byte 0x0000FFFF
_080B5430: .4byte FUN_080b54ec
