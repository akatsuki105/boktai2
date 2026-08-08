	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807B3B4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r5, r4, #0
	cmp r4, #0
	beq _0807B3AE
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807B3AE
	bl fetch_082316e4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08060ec8
	ldr r1, _0807B3B8 @ =0x00003FFE
	adds r0, r4, #0
	bl FUN_08060ed8
	cmp r0, #0
	beq _0807B398
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r0, r4, #0
	bl FUN_08064c48
	ldr r2, _0807B3BC @ =0x00000282
	adds r1, r4, r2
	strb r0, [r1]
_0807B398:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807B3AE
	bl fetch_082316e4
	movs r2, #0x9c
	lsls r2, r2, #4
	adds r1, r5, r2
	str r0, [r1]
_0807B3AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B3B4: .4byte 0x03002BE0
_0807B3B8: .4byte 0x00003FFE
_0807B3BC: .4byte 0x00000282
