	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080CFE74 @ =0x00000395
	adds r0, r4, r1
	movs r2, #0
	movs r6, #1
	strb r6, [r0]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r5, #0
	movs r0, #0x32
	strh r0, [r1]
	movs r1, #0x3c
	adds r3, #4
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _080CFE78 @ =0x000003D2
	adds r0, r4, r1
	strb r5, [r0]
	ldr r3, _080CFE7C @ =0x000003F6
	adds r0, r4, r3
	strh r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #1
	adds r1, #1
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r1, #4
	bls _080CFE88
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080CFE80 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _080CFE84 @ =0x000002E7
	adds r0, r4, r3
	strb r6, [r0]
	b _080CFE96
	.align 2, 0
_080CFE74: .4byte 0x00000395
_080CFE78: .4byte 0x000003D2
_080CFE7C: .4byte 0x000003F6
_080CFE80: .4byte 0x000002E6
_080CFE84: .4byte 0x000002E7
_080CFE88:
	lsrs r0, r0, #0x19
	ldr r2, _080CFEB0 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _080CFEB4 @ =0x000002E7
	adds r0, r4, r3
	strb r5, [r0]
_080CFE96:
	ldr r0, _080CFEB8 @ =0x000003D6
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _080CFEBC @ =0x00000191
	strh r0, [r1]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x32
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080CFEB0: .4byte 0x000002E6
_080CFEB4: .4byte 0x000002E7
_080CFEB8: .4byte 0x000003D6
_080CFEBC: .4byte 0x00000191
