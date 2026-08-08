	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BEF2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BEF2:
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
	bls _0807BF28
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807BF20 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0807BF24 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807BF36
	.align 2, 0
_0807BF20: .4byte 0x000002E6
_0807BF24: .4byte 0x000002E7
_0807BF28:
	lsrs r1, r1, #0x19
	ldr r2, _0807BF6C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0807BF70 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807BF36:
	strb r0, [r1]
	ldr r1, _0807BF74 @ =0x000004A4
	adds r0, r4, r1
	strh r5, [r0]
	movs r2, #0x96
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08060b84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _0807BF7C
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BF78 @ =FUN_08075980
	b _0807BF98
	.align 2, 0
_0807BF6C: .4byte 0x000002E6
_0807BF70: .4byte 0x000002E7
_0807BF74: .4byte 0x000004A4
_0807BF78: .4byte FUN_08075980
_0807BF7C:
	cmp r0, #3
	bne _0807BF90
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BF8C @ =FUN_08076f2c
	b _0807BF98
	.align 2, 0
_0807BF8C: .4byte FUN_08076f2c
_0807BF90:
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BFA0 @ =FUN_080739e0
_0807BF98:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BFA0: .4byte FUN_080739e0
