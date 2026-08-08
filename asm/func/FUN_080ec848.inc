	push {r4, r5, r6, lr}
	adds r6, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	ldr r0, _080EC860 @ =0x03002C60
	ldr r2, [r0]
	cmp r2, #0
	beq _080EC89C
	b _080EC896
	.align 2, 0
_080EC860: .4byte 0x03002C60
_080EC864:
	ldr r1, [r2, #4]
	ldr r3, _080EC88C @ =0x000001DF
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r5
	bne _080EC894
	ldrh r0, [r1]
	cmp r0, r4
	bne _080EC894
	ldr r3, _080EC890 @ =0x0000057C
	adds r0, r1, r3
	ldr r3, [r0]
	cmp r3, #0
	beq _080EC894
	adds r0, r1, #0
	adds r1, r6, #0
	bl _call_via_r3
	b _080EC89C
	.align 2, 0
_080EC88C: .4byte 0x000001DF
_080EC890: .4byte 0x0000057C
_080EC894:
	ldr r2, [r2]
_080EC896:
	ldr r0, [r2]
	cmp r0, #0
	bne _080EC864
_080EC89C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
