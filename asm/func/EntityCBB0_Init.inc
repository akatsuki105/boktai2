	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080B2750
	bl Script_GetValue
	ldr r2, _080B274C @ =0x00000C0F
	adds r1, r4, r2
	strb r0, [r1]
	b _080B2756
	.align 2, 0
_080B274C: .4byte 0x00000C0F
_080B2750:
	ldr r2, _080B2788 @ =0x00000C0F
	adds r0, r4, r2
	strb r1, [r0]
_080B2756:
	ldr r0, _080B278C @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _080B2790 @ =0x000004F4
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _080B2794 @ =0x03002C00
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080b1d5c
	adds r0, r4, #0
	bl FUN_080b21d8
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080B2798
	bl Script_GetValue
	b _080B279A
	.align 2, 0
_080B2788: .4byte 0x00000C0F
_080B278C: .4byte 0x03002BE0
_080B2790: .4byte 0x000004F4
_080B2794: .4byte 0x03002C00
_080B2798:
	movs r0, #4
_080B279A:
	strb r0, [r4, #0x1e]
	adds r0, r4, #0
	bl FUN_080b1b74
	adds r0, r4, #0
	bl FUN_080b2094
	adds r0, r4, #0
	bl FUN_080ad388
	adds r0, r4, #0
	bl FUN_080ad544
	adds r0, r4, #0
	bl FUN_080b1de8
	adds r0, r4, #0
	bl FUN_080b2410
	ldr r0, _080B27E0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080B27E4 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0xc1
	lsls r2, r2, #4
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080B27E8 @ =0x03002C58
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B27E0: .4byte 0x030046A0
_080B27E4: .4byte 0x00000942
_080B27E8: .4byte 0x03002C58
