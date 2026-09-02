	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807EE6A
	b _0807F092
_0807EE6A:
	ldr r2, _0807EEC8 @ =0x00000381
	adds r0, r5, r2
	ldrb r1, [r0]
	cmp r1, #2
	bne _0807EEEC
	subs r2, #0x29
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _0807EECC @ =FUN_080798a4
	str r0, [r1]
	ldr r0, _0807EED0 @ =0x00000359
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	str r2, [r5, #0x50]
	adds r0, r5, #0
	adds r0, #0xe8
	str r0, [r5, #0x4c]
	ldr r2, _0807EED4 @ =0x000004CC
	adds r1, r5, r2
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08062c3c
	ldr r0, _0807EED8 @ =0x0000094C
	adds r1, r5, r0
	ldr r0, _0807EEDC @ =0x0000FFFF
	strh r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0807EEE0 @ =0x0000094A
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r1, #6]
	ldr r0, _0807EEE4 @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _0807EEE8 @ =0x0000026D
	b _0807EF46
	.align 2, 0
_0807EEC8: .4byte 0x00000381
_0807EECC: .4byte FUN_080798a4
_0807EED0: .4byte 0x00000359
_0807EED4: .4byte 0x000004CC
_0807EED8: .4byte 0x0000094C
_0807EEDC: .4byte 0x0000FFFF
_0807EEE0: .4byte 0x0000094A
_0807EEE4: .4byte 0x0000095E
_0807EEE8: .4byte 0x0000026D
_0807EEEC:
	cmp r1, #3
	bne _0807EF70
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _0807EF54 @ =FUN_08079b64
	str r0, [r1]
	ldr r0, _0807EF58 @ =0x00000359
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	str r2, [r5, #0x50]
	adds r0, r5, #0
	adds r0, #0xe8
	str r0, [r5, #0x4c]
	ldr r2, _0807EF5C @ =0x000004CC
	adds r1, r5, r2
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08062c3c
	ldr r0, _0807EF60 @ =0x0000094C
	adds r1, r5, r0
	ldr r0, _0807EF64 @ =0x0000FFFF
	strh r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0807EF68 @ =0x0000094A
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r1, #6]
	ldr r0, _0807EF6C @ =0x0000095E
	adds r1, r5, r0
	movs r0, #0x91
	lsls r0, r0, #1
_0807EF46:
	strh r0, [r1]
	adds r2, #0x16
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
	b _0807F066
	.align 2, 0
_0807EF54: .4byte FUN_08079b64
_0807EF58: .4byte 0x00000359
_0807EF5C: .4byte 0x000004CC
_0807EF60: .4byte 0x0000094C
_0807EF64: .4byte 0x0000FFFF
_0807EF68: .4byte 0x0000094A
_0807EF6C: .4byte 0x0000095E
_0807EF70:
	cmp r1, #4
	bne _0807EFFC
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r4, #0
	strb r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _0807EFE8 @ =FUN_08079e4c
	str r0, [r1]
	adds r2, #1
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	str r4, [r5, #0x50]
	adds r0, r5, #0
	adds r0, #0xe8
	str r0, [r5, #0x4c]
	ldr r0, _0807EFEC @ =0x000004CC
	adds r1, r5, r0
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08062c3c
	ldr r0, _0807EFF0 @ =0x0000094C
	adds r1, r5, r0
	ldr r0, _0807EFF4 @ =0x0000FFFF
	strh r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _0807EFF8 @ =0x0000094A
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r2, #6]
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	subs r2, #0xa2
	adds r0, r5, r2
	strb r1, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	b _0807F066
	.align 2, 0
_0807EFE8: .4byte FUN_08079e4c
_0807EFEC: .4byte 0x000004CC
_0807EFF0: .4byte 0x0000094C
_0807EFF4: .4byte 0x0000FFFF
_0807EFF8: .4byte 0x0000094A
_0807EFFC:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #4
	beq _0807F01C
	ldr r2, _0807F098 @ =0x0000095E
	adds r1, r5, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
_0807F01C:
	movs r2, #0
	movs r0, #1
	strb r0, [r3]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _0807F09C @ =FUN_08078d5c
	str r0, [r1]
	ldr r1, _0807F0A0 @ =0x00000359
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	adds r0, #0x88
	str r0, [r5, #0x50]
	str r2, [r5, #0x4c]
	ldr r2, _0807F0A4 @ =0x000004CC
	adds r1, r5, r2
	adds r0, #0x20
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08062c3c
	ldr r0, _0807F0A8 @ =0x0000094C
	adds r1, r5, r0
	ldr r0, _0807F0AC @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r5, #0
	bl Player_CheckMagicEnchant
	adds r0, #1
	ldr r2, _0807F0B0 @ =0x00000951
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, #1
	subs r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_0807F066:
	ldr r1, _0807F0B4 @ =0x0000094A
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0xc2
	movs r4, #0
	strh r0, [r1]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r0, r5, #0
	bl FUN_08064c48
	ldr r2, _0807F0B8 @ =0x00000282
	adds r1, r5, r2
	strb r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_0807F092:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807F098: .4byte 0x0000095E
_0807F09C: .4byte FUN_08078d5c
_0807F0A0: .4byte 0x00000359
_0807F0A4: .4byte 0x000004CC
_0807F0A8: .4byte 0x0000094C
_0807F0AC: .4byte 0x0000FFFF
_0807F0B0: .4byte 0x00000951
_0807F0B4: .4byte 0x0000094A
_0807F0B8: .4byte 0x00000282
