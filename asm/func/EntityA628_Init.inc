	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x1c]
	strb r2, [r4, #0x1e]
	strb r3, [r4, #0x1f]
	bl EntityA628_SetupBG
	adds r0, r4, #0
	bl EntityA628_ResetOrbit
	ldr r2, _080A0ECC @ =0x085B0A08
	ldrh r0, [r4, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0ED0
	asrs r1, r0, #0xc
	b _080A0ED6
	.align 2, 0
_080A0ECC: .4byte 0x085B0A08
_080A0ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0ED6:
	ldr r3, _080A0F24 @ =0x03002BE0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	subs r0, r0, r1
	strh r0, [r4, #0x28]
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r2, [r0]
	ldr r1, _080A0F28 @ =0x0000097A
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #0x2a]
	ldr r2, _080A0F2C @ =0x085B0A08
	ldrh r1, [r4, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	muls r0, r1, r0
	ldrb r2, [r4, #0x1e]
	cmp r0, #0
	blt _080A0F30
	asrs r1, r0, #0xc
	b _080A0F36
	.align 2, 0
_080A0F24: .4byte 0x03002BE0
_080A0F28: .4byte 0x0000097A
_080A0F2C: .4byte 0x085B0A08
_080A0F30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0F36:
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	subs r0, r0, r1
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl EntityA628_Update
	ldr r0, _080A0F54 @ =0x03002C3C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A0F54: .4byte 0x03002C3C
