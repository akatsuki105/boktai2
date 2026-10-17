	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080D07D8 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D07AC
	ldr r2, _080D07DC @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D07AC
	movs r1, #1
_080D07AC:
	cmp r1, #0
	bne _080D07D4
	ldr r1, _080D07E0 @ =0x00000362
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, #0x64
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	cmp r1, #0x10
	ble _080D07E4
_080D07D4:
	movs r1, #0x10
	b _080D07EA
	.align 2, 0
_080D07D8: .4byte 0x00000446
_080D07DC: .4byte 0x00000442
_080D07E0: .4byte 0x00000362
_080D07E4:
	cmp r1, #8
	bgt _080D07EA
	movs r1, #9
_080D07EA:
	ldr r2, _080D0814 @ =0x000004C5
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _080D0800
	adds r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0800
	subs r1, #4
_080D0800:
	ldr r0, _080D0818 @ =0x00000402
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D080C
	subs r1, r1, r0
_080D080C:
	cmp r1, #1
	ble _080D081C
	adds r0, r1, #0
	b _080D081E
	.align 2, 0
_080D0814: .4byte 0x000004C5
_080D0818: .4byte 0x00000402
_080D081C:
	movs r0, #2
_080D081E:
	pop {r4}
	pop {r1}
	bx r1
