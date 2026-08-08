	push {r4, lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	adds r4, r3, #0
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _080FFD20
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3, #8]
	cmp r0, #3
	bhi _080FFD04
	ldr r0, _080FFD00 @ =0x085AD4DC
	ldrh r1, [r3, #8]
	b _080FFD14
	.align 2, 0
_080FFD00: .4byte 0x085AD4DC
_080FFD04:
	subs r0, #0xa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080FFD20
	ldr r0, _080FFD1C @ =0x085AD4DC
	ldrh r1, [r4, #8]
	subs r1, #0xa
_080FFD14:
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	b _080FFD22
	.align 2, 0
_080FFD1C: .4byte 0x085AD4DC
_080FFD20:
	movs r0, #0
_080FFD22:
	pop {r4}
	pop {r1}
	bx r1
  .align 2, 0
