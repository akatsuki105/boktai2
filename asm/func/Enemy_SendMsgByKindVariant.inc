	push {r4, r5, r6, r7, lr}
	adds r7, r2, #0
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _080EC83C @ =0x03002C60
	ldr r4, [r0]
	cmp r4, #0
	beq _080EC836
	ldr r0, [r4]
	cmp r0, #0
	beq _080EC836
	adds r5, r1, #0
_080EC804:
	ldr r1, [r4, #4]
	ldr r2, _080EC840 @ =0x000001DF
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, r6
	bne _080EC82E
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, r5
	bne _080EC82E
	ldr r2, _080EC844 @ =0x0000057C
	adds r0, r1, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _080EC82E
	adds r0, r1, #0
	adds r1, r7, #0
	bl _call_via_r2
_080EC82E:
	ldr r4, [r4]
	ldr r0, [r4]
	cmp r0, #0
	bne _080EC804
_080EC836:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EC83C: .4byte 0x03002C60
_080EC840: .4byte 0x000001DF
_080EC844: .4byte 0x0000057C
