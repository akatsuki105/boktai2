	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080BB11C @ =0x000012F0
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080BB0FC
	ldr r0, _080BB120 @ =0x00000276
	bl PlaySound_082406e0
_080BB0FC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080BB140
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BB128
	ldr r2, _080BB124 @ =0x00000C3A
	adds r1, r5, r2
	b _080BB148
	.align 2, 0
_080BB11C: .4byte 0x000012F0
_080BB120: .4byte 0x00000276
_080BB124: .4byte 0x00000C3A
_080BB128:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _080BB13C @ =0x00000C3A
	adds r0, r5, r2
	strh r1, [r0]
	b _080BB15A
	.align 2, 0
_080BB13C: .4byte 0x00000C3A
_080BB140:
	cmp r1, #0xf
	bhi _080BB154
	ldr r0, _080BB150 @ =0x00000C3A
	adds r1, r5, r0
_080BB148:
	movs r0, #0x20
	strh r0, [r1]
	b _080BB15A
	.align 2, 0
_080BB150: .4byte 0x00000C3A
_080BB154:
	adds r0, r5, #0
	bl FUN_080baa64
_080BB15A:
	pop {r4, r5}
	pop {r0}
	bx r0
