	push {r4, lr}
	adds r4, r0, #0
	bl EntityE9D3_Init_Helper_080b5984
	ldr r2, _080B59F4 @ =0x0000082C
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080b55d4
	adds r0, r4, #0
	bl FUN_080b5614
	adds r0, r4, #0
	bl EntityE9D3_Init_Helper_080b5650
	adds r0, r4, #0
	bl EntityE9D3_Init_Helper_080b593c
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B59F8
	bl Script_GetValue
	movs r2, #0x83
	lsls r2, r2, #4
	adds r1, r4, r2
	str r0, [r1]
	b _080B5A00
	.align 2, 0
_080B59F4: .4byte 0x0000082C
_080B59F8:
	movs r2, #0x83
	lsls r2, r2, #4
	adds r0, r4, r2
	str r1, [r0]
_080B5A00:
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B5A1C
	bl Script_GetValue
	ldr r2, _080B5A18 @ =0x00000834
	adds r1, r4, r2
	str r0, [r1]
	b _080B5A22
	.align 2, 0
_080B5A18: .4byte 0x00000834
_080B5A1C:
	ldr r2, _080B5A3C @ =0x00000834
	adds r0, r4, r2
	str r1, [r0]
_080B5A22:
	movs r0, #0x6f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B5A44
	bl Script_GetValue
	ldr r2, _080B5A40 @ =0x00000846
	adds r1, r4, r2
	strh r0, [r1]
	b _080B5A4A
	.align 2, 0
_080B5A3C: .4byte 0x00000834
_080B5A40: .4byte 0x00000846
_080B5A44:
	ldr r2, _080B5A5C @ =0x00000846
	adds r0, r4, r2
	strh r1, [r0]
_080B5A4A:
	ldr r1, _080B5A5C @ =0x00000846
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B5A60
	adds r0, r4, #0
	bl FUN_080b4e8c
	b _080B5A66
	.align 2, 0
_080B5A5C: .4byte 0x00000846
_080B5A60:
	adds r0, r4, #0
	bl FUN_080b4b04
_080B5A66:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
