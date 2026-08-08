	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807B4E0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807B4DA
	movs r4, #0
_0807B4CC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08063634
	adds r4, #1
	cmp r4, #2
	ble _0807B4CC
_0807B4DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B4E0: .4byte 0x03002BE0
