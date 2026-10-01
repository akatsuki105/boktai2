	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0xac
	ldrh r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bls _08084D62
	strh r1, [r2]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08084c30
	b _08084D6E
_08084D62:
	cmp r0, #0
	bne _08084D6E
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08084c30
_08084D6E:
	adds r0, r4, #0
	adds r0, #0xac
	ldrh r1, [r0]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r5, r4, #0
	adds r5, #0xaa
	strh r1, [r5]
	ldr r3, _08084DBC @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084DC0 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084DC4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
	ldrh r2, [r5]
	adds r1, r4, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084DBC: .4byte 0x030046B8
_08084DC0: .4byte 0x000003FF
_08084DC4: .4byte 0x0203B400
