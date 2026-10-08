	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A0884 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A08C0
	ldr r0, _080A0888 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _080A088C
	movs r1, #1
	rsbs r1, r1, #0
	b _080A0890
	.align 2, 0
_080A0884: .4byte 0x030047A4
_080A0888: .4byte 0x03002C68
_080A088C:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_080A0890:
	ldr r0, [r0]
	cmp r0, #0
	bne _080A089A
	movs r0, #0
	b _080A08A0
_080A089A:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080A08A0:
	cmp r0, #0
	beq _080A08A8
	movs r0, #0
	b _080A08B6
_080A08A8:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A090E
	adds r0, r4, #0
	bl EntityA628_ResetOrbit
	movs r0, #1
_080A08B6:
	strb r0, [r4, #0x1f]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A090E
	b _080A0920
_080A08C0:
	ldr r0, _080A08E4 @ =0x03002B80
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #1
	bne _080A08CC
	movs r2, #1
_080A08CC:
	cmp r2, #0
	beq _080A08E8
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080A0902
	movs r0, #1
	strb r0, [r5]
	b _080A0902
	.align 2, 0
_080A08E4: .4byte 0x03002B80
_080A08E8:
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _080A0902
	strb r2, [r5]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0920
	adds r0, r4, #0
	bl EntityA628_ResetOrbit
_080A0902:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0920
	ldrb r0, [r5]
	cmp r0, #0
	bne _080A0920
_080A090E:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080A091C @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080A092A
	.align 2, 0
_080A091C: .4byte 0x03003E78
_080A0920:
	ldr r0, _080A0930 @ =0x03003E78
	ldr r1, _080A0934 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080A092A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0930: .4byte 0x03003E78
_080A0934: .4byte 0xFFFFFDFF
