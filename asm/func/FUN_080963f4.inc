	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b8a4
	adds r0, r4, #0
	bl FUN_0809536c
	adds r0, r4, #0
	bl FUN_0808b910
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080954a8
	ldr r0, _08096438 @ =0x00001BCC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0809643C @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08096448
	ldr r1, _08096440 @ =0x00001BC4
	adds r0, r4, r1
	ldr r1, _08096444 @ =0x000002DF
	bl MainSprite_SetPltt
	b _08096454
	.align 2, 0
_08096438: .4byte 0x00001BCC
_0809643C: .4byte 0x00003AE8
_08096440: .4byte 0x00001BC4
_08096444: .4byte 0x000002DF
_08096448:
	ldr r1, _0809647C @ =0x00001BC4
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl MainSprite_SetPltt
_08096454:
	ldr r0, _08096480 @ =0x00001C8C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08096484 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08096490
	ldr r1, _08096488 @ =0x00001C84
	adds r0, r4, r1
	ldr r1, _0809648C @ =0x000002DF
	bl MainSprite_SetPltt
	b _0809649C
	.align 2, 0
_0809647C: .4byte 0x00001BC4
_08096480: .4byte 0x00001C8C
_08096484: .4byte 0x00003AE8
_08096488: .4byte 0x00001C84
_0809648C: .4byte 0x000002DF
_08096490:
	ldr r1, _080964A8 @ =0x00001C84
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl MainSprite_SetPltt
_0809649C:
	adds r0, r4, #0
	bl FUN_0808bac4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080964A8: .4byte 0x00001C84
