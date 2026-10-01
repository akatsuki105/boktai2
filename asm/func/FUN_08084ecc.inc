	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0xac
	ldrh r1, [r0]
	ldr r0, _08084EE4 @ =0x000013FF
	cmp r1, r0
	bls _08084EE8
	adds r0, r5, #0
	bl FUN_08084870
	b _08084EF8
	.align 2, 0
_08084EE4: .4byte 0x000013FF
_08084EE8:
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08084c30
_08084EF8:
	adds r4, r5, #0
	adds r4, #0xba
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _08084F14
	ldr r0, _08084F6C @ =0x0000020F
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r4]
_08084F14:
	adds r0, r5, #0
	adds r0, #0xac
	ldrh r1, [r0]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084F70 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084F74 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084F78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0xa8
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x78
	bls _08084F66
	movs r0, #0x78
	strh r0, [r2]
_08084F66:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084F6C: .4byte 0x0000020F
_08084F70: .4byte 0x030046B8
_08084F74: .4byte 0x000003FF
_08084F78: .4byte 0x0203B400
