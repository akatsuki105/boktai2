	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x18
	bl MainSprite_AdvanceAnim
	ldr r0, _080B5584 @ =0x00000844
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x96
	bne _080B555A
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B5588 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080B555A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb5
	bls _080B557A
	ldr r1, _080B558C @ =0x00000834
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0
	bl VM_ExecByID
	adds r0, r5, #0
	bl KillEntity
_080B557A:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B5584: .4byte 0x00000844
_080B5588: .4byte 0x0000FFFF
_080B558C: .4byte 0x00000834
