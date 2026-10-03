	push {lr}
	ldr r2, _080921D4 @ =0x00003F9C
	adds r1, r0, r2
	ldrb r2, [r1]
	ldr r1, _080921D8 @ =0x00003AEE
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	bl GetItemID
	ldr r1, _080921DC @ =0x08DAA8D8
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _080921E0
	movs r0, #0
	b _080921E2
	.align 2, 0
_080921D4: .4byte 0x00003F9C
_080921D8: .4byte 0x00003AEE
_080921DC: .4byte 0x08DAA8D8
_080921E0:
	movs r0, #1
_080921E2:
	pop {r1}
	bx r1
	.align 2, 0
