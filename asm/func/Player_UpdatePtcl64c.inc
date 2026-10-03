	push {r4, r5, lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _080613DC
	ldr r5, _080613BC @ =0x00000679
	adds r1, r2, r5
	ldrb r0, [r1]
	adds r4, r0, #1
	strb r4, [r1]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080613C0
	movs r0, #0xca
	lsls r0, r0, #3
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r3]
	b _080613DC
	.align 2, 0
_080613BC: .4byte 0x00000679
_080613C0:
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r3, _080613E4 @ =0x0000064C
	adds r1, r2, r3
	ldr r1, [r1]
	ldr r5, _080613E8 @ =0x0000067A
	adds r3, r2, r5
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x1a
	ldrb r3, [r3]
	adds r2, r2, r3
	bl FUN_0822dafc
_080613DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080613E4: .4byte 0x0000064C
_080613E8: .4byte 0x0000067A
