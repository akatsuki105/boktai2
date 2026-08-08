	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807B6B4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r5, r4, #0
	cmp r4, #0
	beq _0807B6AC
	adds r0, r4, #0
	bl FUN_0807e854
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _0807B69C
	bl fetch_082316e4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
_0807B69C:
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	movs r1, #0x1f
	movs r2, #0
	bl FUN_08060b84
_0807B6AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B6B4: .4byte 0x03002BE0
