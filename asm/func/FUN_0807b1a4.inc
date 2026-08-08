	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807B1C8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r0, #0
	cmp r4, #0
	beq _0807B1C2
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	bne _0807B1CC
_0807B1C2:
	movs r0, #0
	b _0807B1DC
	.align 2, 0
_0807B1C8: .4byte 0x03002BE0
_0807B1CC:
	bl fetch_082316e4
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r1, [r1]
	ands r1, r0
	adds r0, r1, #0
_0807B1DC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
