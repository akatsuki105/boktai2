	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080976A8 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08097686
	movs r0, #0x87
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08097686:
	ldrh r0, [r4]
	adds r1, r0, #1
	strh r1, [r4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _080976C8
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080976B0
	ldr r2, _080976AC @ =0x00001BE6
	adds r1, r5, r2
	b _080976D4
	.align 2, 0
_080976A8: .4byte 0x000009EE
_080976AC: .4byte 0x00001BE6
_080976B0:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x46
	subs r1, r1, r0
	ldr r2, _080976C4 @ =0x00001BE6
	adds r0, r5, r2
	strh r1, [r0]
	b _080976E6
	.align 2, 0
_080976C4: .4byte 0x00001BE6
_080976C8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080976E0
	ldr r0, _080976DC @ =0x00001BE6
	adds r1, r5, r0
_080976D4:
	movs r0, #0x46
	strh r0, [r1]
	b _080976E6
	.align 2, 0
_080976DC: .4byte 0x00001BE6
_080976E0:
	adds r0, r5, #0
	bl FUN_08096fa8
_080976E6:
	pop {r4, r5}
	pop {r0}
	bx r0
