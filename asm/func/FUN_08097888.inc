	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b8a4
	adds r0, r4, #0
	bl FUN_08096b44
	ldr r1, _080978D0 @ =0x00001D04
	adds r0, r4, r1
	movs r1, #0x10
	bl FUN_08096af0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096bb8
	ldr r0, _080978D4 @ =0x00001BCC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080978D8 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080978E4
	ldr r1, _080978DC @ =0x00001BC4
	adds r0, r4, r1
	ldr r1, _080978E0 @ =0x000002DF
	bl MainSprite_SetPltt
	b _080978F0
	.align 2, 0
_080978D0: .4byte 0x00001D04
_080978D4: .4byte 0x00001BCC
_080978D8: .4byte 0x00003AE8
_080978DC: .4byte 0x00001BC4
_080978E0: .4byte 0x000002DF
_080978E4:
	ldr r1, _08097918 @ =0x00001BC4
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl MainSprite_SetPltt
_080978F0:
	ldr r0, _0809791C @ =0x00001C8C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08097920 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809792C
	ldr r1, _08097924 @ =0x00001C84
	adds r0, r4, r1
	ldr r1, _08097928 @ =0x000002DF
	bl MainSprite_SetPltt
	b _08097938
	.align 2, 0
_08097918: .4byte 0x00001BC4
_0809791C: .4byte 0x00001C8C
_08097920: .4byte 0x00003AE8
_08097924: .4byte 0x00001C84
_08097928: .4byte 0x000002DF
_0809792C:
	ldr r1, _08097944 @ =0x00001C84
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl MainSprite_SetPltt
_08097938:
	adds r0, r4, #0
	bl FUN_0808bac4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097944: .4byte 0x00001C84
