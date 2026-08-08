	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807C210
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
_0807C210:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _0807C28C
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807C264
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807C260 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r4, r3
	movs r0, #1
	b _0807C272
	.align 2, 0
_0807C260: .4byte 0x000002E6
_0807C264:
	lsrs r1, r1, #0x19
	ldr r2, _0807C280 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _0807C284 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_0807C272:
	strb r0, [r1]
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C288 @ =FUN_08075134
	b _0807C2F6
	.align 2, 0
_0807C280: .4byte 0x000002E6
_0807C284: .4byte 0x000002E7
_0807C288: .4byte FUN_08075134
_0807C28C:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0807C2A2
	movs r0, #4
	b _0807C2A4
_0807C2A2:
	movs r0, #0
_0807C2A4:
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080609dc
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807C2C8
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C2C4 @ =FUN_0807688c
	b _0807C2F6
	.align 2, 0
_0807C2C4: .4byte FUN_0807688c
_0807C2C8:
	cmp r0, #4
	bne _0807C2DC
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C2D8 @ =FUN_080773f0
	b _0807C2F6
	.align 2, 0
_0807C2D8: .4byte FUN_080773f0
_0807C2DC:
	ldr r3, _0807C300 @ =0x000002E6
	adds r1, r4, r3
	ldrb r0, [r1]
	lsrs r0, r0, #2
	movs r2, #0
	strb r0, [r1]
	ldr r1, _0807C304 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C308 @ =FUN_0807317c
_0807C2F6:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C300: .4byte 0x000002E6
_0807C304: .4byte 0x000002E7
_0807C308: .4byte FUN_0807317c
