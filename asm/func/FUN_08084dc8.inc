	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xac
	ldrh r0, [r4]
	adds r0, #0x60
	strh r0, [r4]
	lsls r0, r0, #0x10
	ldr r1, _08084E44 @ =0x13FF0000
	cmp r0, r1
	bls _08084DF4
	movs r0, #0xba
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0xa0
	lsls r0, r0, #5
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #6
	bl FUN_08084c30
_08084DF4:
	adds r0, r5, #0
	bl FUN_08084870
	ldrh r1, [r4]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084E48 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084E4C @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084E50 @ =0x0203B400
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
	adds r0, r5, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084E44: .4byte 0x13FF0000
_08084E48: .4byte 0x030046B8
_08084E4C: .4byte 0x000003FF
_08084E50: .4byte 0x0203B400
