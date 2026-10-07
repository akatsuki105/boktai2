	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080974C4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080974D4
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080974C8 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _080974CC @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08096af0
	adds r0, r4, #0
	bl FUN_08096a34
	ldr r1, _080974D0 @ =FUN_080971c4
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _0809750C
	.align 2, 0
_080974C4: .4byte 0x030044E0
_080974C8: .4byte 0x00001464
_080974CC: .4byte 0x00003AEB
_080974D0: .4byte FUN_080971c4
_080974D4:
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0809750C
	ldr r0, _08097520 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08097524 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	bl EntityCC28_ShowBottomLine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _08097528 @ =FUN_08097584
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809750C:
	ldr r1, _0809752C @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl MainSprite_AdvanceAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097520: .4byte 0x0000144C
_08097524: .4byte 0x0000204C
_08097528: .4byte FUN_08097584
_0809752C: .4byte 0x00001444
