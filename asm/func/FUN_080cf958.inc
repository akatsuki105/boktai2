	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r1, _080CF9B8 @ =0x000003CE
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080CFA18
	ldrh r1, [r3, #0x2c]
	movs r5, #0xf0
	lsls r5, r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	ldrh r0, [r3, #0x2e]
	adds r0, #0x96
	ldr r2, _080CF9BC @ =0x000003C2
	adds r1, r3, r2
	strh r0, [r1]
	ldrh r1, [r3, #0x30]
	adds r5, #4
	adds r0, r3, r5
	strh r1, [r0]
	ldr r1, _080CF9C0 @ =0x000003BD
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _080CF9C4 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r2, #0
	cmp r0, #0
	blt _080CF9C8
	asrs r0, r0, #0xc
	b _080CF9CE
	.align 2, 0
_080CF9B8: .4byte 0x000003CE
_080CF9BC: .4byte 0x000003C2
_080CF9C0: .4byte 0x000003BD
_080CF9C4: .4byte gSineTable
_080CF9C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CF9CE:
	rsbs r1, r0, #0
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r3, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080CF9FC @ =0x000003CA
	adds r0, r3, r1
	strh r2, [r0]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	cmp r0, #0
	blt _080CFA00
	asrs r0, r0, #0xc
	b _080CFA06
	.align 2, 0
_080CF9FC: .4byte 0x000003CA
_080CFA00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CFA06:
	rsbs r1, r0, #0
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	ldr r0, _080CFA20 @ =0x000003CE
	adds r1, r3, r0
	movs r0, #1
	strh r0, [r1]
_080CFA18:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CFA20: .4byte 0x000003CE
