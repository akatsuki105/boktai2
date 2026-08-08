	push {r4, r5, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807B920
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807B920:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #2
	bne _0807B988
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807B960
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807B958 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0807B95C @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807B96E
	.align 2, 0
_0807B958: .4byte 0x000002E6
_0807B95C: .4byte 0x000002E7
_0807B960:
	lsrs r1, r1, #0x19
	ldr r2, _0807B97C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0807B980 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807B96E:
	strb r0, [r1]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807B984 @ =FUN_08074d90
	b _0807B9C0
	.align 2, 0
_0807B97C: .4byte 0x000002E6
_0807B980: .4byte 0x000002E7
_0807B984: .4byte FUN_08074d90
_0807B988:
	adds r0, r4, #0
	bl FUN_080609dc
	ldrb r0, [r5]
	cmp r0, #3
	bne _0807B9A4
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807B9A0 @ =FUN_08075df8
	b _0807B9C0
	.align 2, 0
_0807B9A0: .4byte FUN_08075df8
_0807B9A4:
	cmp r0, #4
	bne _0807B9B8
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807B9B4 @ =FUN_080772ec
	b _0807B9C0
	.align 2, 0
_0807B9B4: .4byte FUN_080772ec
_0807B9B8:
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807B9D8 @ =FUN_08072724
_0807B9C0:
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B9D8: .4byte FUN_08072724
