	push {r4, r5, r6, lr}
	adds r6, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080EC7B0 @ =0x03002C60
	ldr r4, [r0]
	cmp r4, #0
	beq _080EC7DA
	b _080EC7D4
	.align 2, 0
_080EC7B0: .4byte 0x03002C60
_080EC7B4:
	ldr r1, [r4, #4]
	ldr r2, _080EC7E0 @ =0x000001DF
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, r5
	bne _080EC7D2
	ldr r2, _080EC7E4 @ =0x0000057C
	adds r0, r1, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _080EC7D2
	adds r0, r1, #0
	adds r1, r6, #0
	bl _call_via_r2
_080EC7D2:
	ldr r4, [r4]
_080EC7D4:
	ldr r0, [r4]
	cmp r0, #0
	bne _080EC7B4
_080EC7DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EC7E0: .4byte 0x000001DF
_080EC7E4: .4byte 0x0000057C
