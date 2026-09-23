	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	b _08049546
_08049490:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08048da4
	adds r5, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _08049560
	ldrb r0, [r5]
	cmp r0, #0
	bne _08049544
	b _08049560
_080494A8:
	ldrb r0, [r5]
	cmp r0, #0xa
	bne _080494B6
	adds r0, r6, #0
	bl FUN_0804898c
	b _08049544
_080494B6:
	cmp r0, #0x1f
	bne _08049506
	adds r0, r5, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080494DC @ =0x0000FFFF
	cmp r1, r0
	bne _080494E0
	ldrb r0, [r5]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08048a20
	b _08049502
	.align 2, 0
_080494DC: .4byte 0x0000FFFF
_080494E0:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080494FC
	ldr r0, _080494F8 @ =0x00007FFF
	ands r1, r0
	adds r0, r6, #0
	bl FUN_08048a20
	b _08049502
	.align 2, 0
_080494F8: .4byte 0x00007FFF
_080494FC:
	adds r0, r6, #0
	bl FUN_08048a20
_08049502:
	adds r5, #2
	b _08049560
_08049506:
	ldrb r0, [r5]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08048a20
_08049516:
	adds r5, #1
	b _08049560
_0804951A:
	ldrb r1, [r5]
	movs r0, #0x7f
	ands r0, r1
	adds r5, #1
	ldrb r1, [r5]
	lsls r4, r0, #8
	orrs r4, r1
	bl Video_GetZenkakuCharCount
	cmp r4, r0
	blo _0804953A
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08048998
	b _08049516
_0804953A:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08048a4c
	b _08049516
_08049544:
	adds r5, #1
_08049546:
	ldrb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _0804951A
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08049560
	cmp r0, #0x3c
	bne _080494A8
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08049490
_08049560:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
